#!/usr/bin/env python3
"""Regenerate consolidated findings, API/dependency and coverage reports from saved evidence."""
import collections,json,re
from inventory import ROOT,REPORT,dump

def load(p,default=None):return json.loads(p.read_text()) if p.exists() else default

def render_type(d):
    if d['name']=='PTR': return 'PTR('+render_type(d['target'])+')'
    if d['name']=='USERDEFINED':return d.get('type_name') or f"external_hreftype_{d['hreftype']}"
    return d['name']

def main():
    rows=load(REPORT/'inventory.json');pes=[r for r in rows if r['format'].startswith('PE')]
    names={r['module'].lower():r for r in pes};edges=[];coverage=[]
    api=['# Consolidated API map','','PE names/ordinals/IAT addresses are verified table contents. The PE tables do not encode parameter/return types. Windows x64 ABI is the platform default, not evidence for a particular prototype. Full exact tables: `src/<module>/interfaces.json`. Automated inferred signatures: per-function coverage JSON and pseudocode. Manually supported declarations are explicitly identified below.','']
    dep=['# Dependencies','','Static imports are observed loader dependencies, not proof that every imported function executes. DLL-name strings are candidates, not observed runtime loads. No imports were resolved against arbitrary Linux substitutes.','']
    findings=['# Module analysis','','Scope: all inputs structurally inventoried; bounded automated native analysis; selected disassembly review and isolated instruction emulation. **Not complete semantic reconstruction.** Addresses are preferred-image VAs unless marked RVA or file offset. Names in version resources describe intended roles, not verified runtime behavior.','']
    progress=['# Coverage and progress — 2026-10-14','','## Coverage semantics','','Every input has an inventory entry. Every PE has a module directory, resource/API inventory and REA results. Candidate functions are the union of angr discoveries, export/entry starts and `.pdata` starts. `.pdata` records can describe funclets, not distinct source functions; leaf functions can lack unwind records. CFG scanning can mistake data/padding for code. Therefore neither count is a ground-truth total. No percentage here means semantic completeness.','', '| Module | Unwind records | Candidate starts | Pseudocode emitted | Timeout | Deferred | Other gaps |','|---|---:|---:|---:|---:|---:|---:|']
    roles={
        'MSASCui.exe':'User-interface version description; imports user32, GDI/GDI+, common controls, accessibility and MpClient. Event flow, dialog semantics, COM/RPC callbacks and UI state transitions are not fully reviewed.',
        'MpAsDesc.dll':'Resource-description helper. Both exports manually reviewed; a buildable resolver model and emulation tests cover non-tracing behavior. See src/MpAsDesc.dll/reviewed-behavior.md.',
        'MpClient.dll':'Central exported client façade (52 exports). MpConfig*, MpScan*, MpThreat*, cleaning and handle APIs are named in exports. RPC import and ncalrpc string evidence supports local RPC participation, but no complete NDR/IDL contract has been recovered.',
        'MpCmdRun.exe':'Command-line utility by version metadata and embedded help strings; imports MpClient and Cabinet. Argument parser and command dispatch have automatic pseudocode but command behavior is not validated on Windows.',
        'MpCommu.dll':'Communication/download subsystem: four MpCommunication exports, WinHTTP imports, SOAP/WS-Security literal templates and update URL strings. No network requests were made. Authentication/session/error semantics not fully reconstructed.',
        'MpEvMsg.dll':'Resource-only event module, no executable section/entry/imports. WEVT_TEMPLATE contains CRIM/WEVT signatures; custom event schema retained as offset/hash/prefix and partial header facts. Requires a dedicated event-template parser for full reconstruction.',
        'MpOAV.dll':'IOfficeAntiVirus module by version metadata and embedded registry script. Four COM exports, with register/unregister aliases returning 0x80070032. Class-object factory error paths manually inspected. Actual scan interface/vtable still needs recovery.',
        'MpRTP.dll':'Real-time monitor/plugin by version metadata and eight MpPlugin exports. State transitions, engine callback structures, concurrency and teardown semantics remain inferred in automatic code.',
        'MpSvc.dll':'Service module exporting ServiceMain, ServiceCrtMain, SvchostPushServiceGlobals. RPC server imports, ncalrpc literal and plugin-name literals are present. mpengine.dll and mpfilter.sys string references point outside supplied inputs; complete scanning behavior cannot be recreated from this corpus alone.',
        'MsMpCom.dll':'COM utility with three dispatch-interface definitions recovered from embedded MSFT typelib (19 declared methods), six coclasses, one enum. Four COM exports; registration aliases return 0x80070032. Method metadata does not prove implementation behavior.',
        'MsMpLics.dll':'Resource-only license module: four RT_STRING blocks plus version. No executable code to decompile.',
        'MsMpRes.dll':'Resource library: 54 PNGs, AVI, bitmap, icons and MUI metadata. The sole export returns a saved module-handle global; 64-bit return instruction emulated. Runtime localization is not validated.',
        'pt-BR__MpAsDesc.dll.mui':'Resource-only Portuguese description satellite: RT_STRING, message table, version and MUI metadata. Localized IDs can be compared with the resolver table; actual Windows MUI lookup is not emulated.',
        'pt-BR__MpEvMsg.dll.mui':'Resource-only Portuguese event-message satellite. Decoded message IDs/text/flags retain original resource/RVA provenance.',
        'pt-BR__MsMpRes.dll.mui':'Resource-only Portuguese UI satellite. Strings decoded; two menu resources, ten dialogs and one accelerator are inventoried but their detailed control/menu layouts are not decoded.'}
    for r in pes:
        m=r['module'];d=REPORT/'modules'/m;f=load(d/'function-coverage.json',{'status':'not finished','functions':[]});fs=f['functions']
        stat=collections.Counter(x['status'] for x in fs);emit=sum(x['status']=='automated pseudocode; unverified' for x in fs);timeouts=sum('timeout:' in x['status'] for x in fs);deferred=sum('deferred:' in x['status'] for x in fs);other=len(fs)-emit-timeouts-deferred
        progress.append(f'| {m} | {len(r["runtime_functions"])} | {len(fs)} | {emit} | {timeouts} | {deferred} | {other} |')
        emitted_vas={x['va'] for x in fs if x['status']=='automated pseudocode; unverified'}
        unwind_emitted=sum(r['image_base']+x['begin_rva'] in emitted_vas for x in r['runtime_functions'])
        exports_emitted=sum(x['va'] in emitted_vas for x in r['exports'])
        coverage.append({'module':m,'unwind_records':len(r['runtime_functions']),'unwind_starts_emitted':unwind_emitted,'export_names_emitted':exports_emitted,'candidate_starts':len(fs),'emitted':emit,'timeouts':timeouts,'deferred':deferred,'other_gaps':other,'status':f['status']})
        libs=collections.Counter(i['dll'] for i in r['imports']);exports=r['exports']
        api+=['## '+m,'',f"Image base `{r['image_base']:#x}`; entry RVA `{r['entry_rva']:#x}`. {len(r['imports'])} imported symbol entries; {len(exports)} exports.",'']
        if exports:
            api+=['| Export | Ordinal | RVA | Forwarder |','|---|---:|---:|---|']
            for e in exports:api.append(f"| {e['name'] or '(unnamed)'} | {e['ordinal']} | `{e['rva']:#x}` | {e['forwarder'] or '—'} |")
        api+=['','Imports: '+(', '.join(f'`{lib}` ({n})' for lib,n in sorted(libs.items())) or 'none')+'.','']
        lookup=load(d/'dynamic-lookup-sites.json',[])
        if lookup:
            api+=['### Literal dynamic-lookup arguments','', 'Independent Capstone pass over `.pdata` ranges. The listed string definition reaches the API argument within a local linear window without an intervening branch/call/register overwrite. Runtime reachability, incoming branches and the identity of GetProcAddress’s module handle remain unproven. Full instruction/definition evidence: dynamic-lookup-sites.json.','', '| Call VA | Imported API | Literal argument |','|---|---|---|']
            for x in lookup:
                if x['literal_argument']:api.append(f"| `{x['call_instruction_va']:#x}` | {x['api']} | `{x['literal_argument']}` |")
            api.append('')
        dep+=['## '+m,'']
        for lib,n in sorted(libs.items()):
            local=lib.lower() in names;edges.append({'from':m,'to':lib,'kind':'PE import','symbols':n,'supplied':local})
            dep.append(f'- `{lib}`: {n} entries; '+('supplied in bin/' if local else 'external runtime dependency')+'.')
        ss=load(d/'strings.json',[])
        candidates=[s for s in ss if re.search(r'(?i)(?:\.dll|\.sys|\.exe)$',s['text']) and len(s['text'])<200 and s['text'].lower() not in {lib.lower() for lib in libs}]
        dump(d/'dynamic-component-candidates.json',candidates)
        if candidates:
            dep+=['','Other filename **string candidates**, not confirmed dynamic resolutions:']
            for s in candidates:dep.append(f"- File offset `{s['file_offset']:#x}`: `{s['text']}`")
        dep.append('')
        selected=[s for s in ss if re.search(r'(?i)https?://|ncalrpc|\\Microsoft\\|MpPlugin|ScanType|SignatureUpdate|RemoveDefinitions',s['text'])][:16]
        findings+=['## '+m,'',roles[m],'',f"Version resource: **{r['version'].get('FileVersion','absent')}**. COFF timestamp `{r['coff_timestamp_utc']}` (not authenticated). Linker field `{r['linker_version']}`; native x64 with CLI directory absent.",'',f"Entry RVA `{r['entry_rva']:#x}`; {len(r['runtime_functions'])} unwind table entries; {len(r['relocations'])} relocation entries (including padding types); resource leaf counts `{r['resource_counts']}`.",'']
        for s in selected:findings.append(f"- String evidence, file offset `{s['file_offset']:#x}`: `{s['text'].replace('`','')[:350]}`")
        findings+=['',f"Function status: {f['status']}; {emit}/{len(fs)} candidates emitted pseudocode. See `modules/{m}/function-coverage.json`, `calls.json`, `xrefs.json`, `indirect-jumps.json` and `objdump.txt.gz`. For resource-only images, call graphs and pseudocode are inapplicable.",'']
    dep+=['## Corpus boundaries and unresolved load relationships','','`msmpeng.exe`, `mpengine.dll`, `mpfilter.sys`, signature databases and matching PDB files are not in bin/. References to them do not establish exact versions, protocols or successful loads. The independent Capstone pass traces literal GetProcAddress arguments for all eight MpPlugin names in MpSvc, several MpCommunication names in MpClient and MpClient entry points in MpOAV. These match supplied exports, but module-handle provenance and runtime success remain unverified; do not label them as observed runtime edges. Satellite basenames/locales establish packaging relationships, not tested loader selection. Version resources mix 6.1.7601.23403 native components with 6.1.7600.16385 event/localized resources; compatibility across this mix is untested.','']
    progress+=['','## Exact remaining work','','- Each timeout/deferred/error/seed-not-recovered row contains the exact VA and reason. Use the row and disassembly to re-run the module with larger budgets or a Ghidra session; validate boundaries before trusting pseudocode. Successful emission is **not manual verification**.','- All unresolved indirect jumps are listed in each module’s indirect-jumps.json. Resolved targets are static candidates; runtime callbacks and plugin/COM virtual dispatch require object/state recovery.','- Original PDB references (10 code images) are recorded by GUID/age/path; no matching PDB was supplied or loaded. Recover them only from an authorized matching source, then rerun type/symbol analysis.','- Native REA provider blocked by missing Ghidra/JDK and release-host restrictions. Supply Ghidra 12.1.x + host JDK 21+, run rea doctor, then REA analyze/decompile on the original read-only inputs.','- Reconstruct MpClient/MpSvc RPC NDR procedure/type tables, plugin engine callback layouts, COM implementation vtables, complete UI/command state machines, and undocumented file formats before attempting full DLL replacements.','- Decode dialogs, menus, accelerators, MUI and WEVT semantic tables fully; cross-check TYPELIB against Windows LoadTypeLib or Wine. The present bounded MSFT decoder covers this supplied artifact, not arbitrary hostile typelibs.','- Full Windows integration requires an isolated VM with matching services, registry, external engine/driver/signature data. Neither Wine nor a Windows VM is available; no service/UI execution or live network behavior has been tested.','- Only the MpAsDesc non-tracing resolver has a meaningful buildable behavior model. No stubs falsely stand in for unrecovered modules.','']
    (REPORT/'api-map.md').write_text('\n'.join(api));(REPORT/'dependencies.md').write_text('\n'.join(dep));(REPORT/'module-analysis.md').write_text('\n'.join(findings));(REPORT/'progress.md').write_text('\n'.join(progress));dump(REPORT/'coverage-summary.json',coverage);dump(REPORT/'dependency-map.json',edges)
    dot=['digraph imports {']+[f'  "{e["from"]}" -> "{e["to"]}" [label="{e["symbols"]}"];' for e in edges]+['}'];(REPORT/'dependencies.dot').write_text('\n'.join(dot)+'\n')
    # Human-readable type metadata; not guessed callable stubs.
    t=next(r['typelib'] for r in load(ROOT/'src/MsMpCom.dll/resource-details.json') if 'typelib' in r)
    lines=['# Recovered COM type-library declarations','','Source: `TYPELIB/1/1033`, file offset `0xd130`, RVA `0xf530`, size 5848. All member offsets below are relative to that resource. Format interpretation: Wine MSFT typelib records; raw values and provenance are in resource-details.json. Metadata declarations are verified bytes interpreted via that format, **not proof of implementation behavior**. No Windows LoadTypeLib cross-check has been performed.','',f"Library `{t['library_name']}`, LIBID `{t['library_guid']}`.",'','`PTR(T)` is typelib pointer indirection (not a C spelling). IUnknown/IDispatch VARTYPEs are already interface-pointer types. `external_hreftype_N` remains unresolved rather than guessed to be a GUID. Callconv=4 is CC_STDCALL metadata; the native x64 ABI still uses Windows x64 calling rules. Parameter flags: 1=in, 2=out, 8=retval; 10=out|retval.','']
    constants=['/* Recovered from MSFT enum metadata; all underlying values fit signed 32 bits. */','#ifndef MSMP_CONFIG_TYPES_H','#define MSMP_CONFIG_TYPES_H','#include <stdint.h>','typedef int32_t mp_com_config_type;','enum {']
    for ty in t['types']:
        lines+=['## '+ty['name'],'',f"Kind `{ty['typekind']}`; GUID `{ty['guid']}`; size {ty['size']}; vtable bytes {ty['vtable_bytes']}; record offset `{ty['resource_offset']:#x}`.",'']
        for f in ty['functions']:
            args=', '.join(f"{render_type(p['type'])} {p['name']} [flags={p['flags']}]" for p in f['parameters'])
            lines.append(f"- `{render_type(f['type'])} {f['name']}({args})`; DISPID {f['memid']}, vtable byte offset {f['vtable_offset']}, callconv {f['callconv']}, record `{f['resource_offset']:#x}`.")
        for v in ty['variables']:
            lines.append(f"- `{v['name']} = {v.get('value','unresolved')}`; record `{v['resource_offset']:#x}`.")
            if 'value' in v:constants.append(f"    {v['name']} = {v['value']},")
        lines.append('')
    constants+=['};','#endif','']
    (ROOT/'src/MsMpCom.dll/type-library.md').write_text('\n'.join(lines));(ROOT/'src/MsMpCom.dll/config-types.h').write_text('\n'.join(constants))
    print('Reports updated; pseudocode candidates',sum(r['emitted'] for r in coverage))
if __name__=='__main__':main()
