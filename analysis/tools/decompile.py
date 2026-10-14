#!/usr/bin/env python3
"""Bounded angr CFG recovery and pseudocode generation with explicit coverage ledger.
Usage: python decompile.py --module MpOAV.dll [--budget 180] [--function-seconds 3]
See README.md. No input is executed; auto_load_libs=False.
"""
from pathlib import Path
import argparse, collections, json, logging, os, signal, time, traceback
from inventory import ROOT, REPORT, dump
# angr can spill databases next to its input by default. Never allow that in bin/.
cache_dir=ROOT/'analysis/tools/runtime/angr'
cache_dir.mkdir(parents=True,exist_ok=True)
os.environ['RTDB_BASE']=str(cache_dir)
logging.disable(logging.CRITICAL)
import angr
class Deadline(BaseException): pass
def expire(signum,frame): raise Deadline()
signal.signal(signal.SIGALRM,expire)
def run(module,budget,seconds,seeded=False,cfg_seconds=240):
    row=json.loads((REPORT/'modules'/module/'metadata.json').read_text())
    dest=REPORT/'modules'/module; src=ROOT/'src'/module
    seed={row['image_base']+f['begin_rva'] for f in row['runtime_functions']}
    seed.update(e['va'] for e in row['exports'] if not e['forwarder'])
    if row['entry_rva']: seed.add(row['image_base']+row['entry_rva'])
    settings={'angr_version':angr.__version__,'auto_load_libs':False,'normalize':True,'data_references':True,'cross_references':True,'function_prologues':True,'seed_count':len(seed),'per_function_seconds':seconds,'decompilation_budget_seconds':budget,'cfg_timeout_seconds':cfg_seconds,'seeded_only_scan':seeded}
    if not any(s['characteristics']&0x20000000 and s['virtual_size'] for s in row['sections']):
        dump(dest/'function-coverage.json',{'settings':settings,'status':'resource-only; no executable section','functions':[],'summary':{}});return
    print(module,'loading',flush=True)
    settings['cache_limits']={'functions':None,'cfg_nodes':None,'cfg_edges':None}
    p=angr.Project(str(ROOT/row['path']),auto_load_libs=False,cache_limits=settings['cache_limits'])
    start=time.monotonic()
    signal.setitimer(signal.ITIMER_REAL,cfg_seconds)
    try:
        cfg=p.analyses.CFGFast(normalize=True,data_references=True,cross_references=True,function_starts=sorted(seed),function_prologues=not seeded,force_smart_scan=not seeded)
    except (Deadline,Exception) as exc:
        dump(dest/'function-coverage.json',{'settings':settings,'status':'CFG failure','error':type(exc).__name__+': '+str(exc),'functions':[{'va':a,'status':'CFG failed; decompilation not attempted'} for a in sorted(seed)]});return 1
    finally: signal.setitimer(signal.ITIMER_REAL,0)
    settings['cfg_elapsed_seconds']=round(time.monotonic()-start,2)
    print(module,'CFG',len(cfg.kb.functions),'functions',settings['cfg_elapsed_seconds'],'seconds',flush=True)
    exports=collections.defaultdict(list)
    for e in row['exports']: exports[e['va']].append(e['name'] or f"ordinal_{e['ordinal']}")
    funcs={a:f for a,f in cfg.kb.functions.items() if p.loader.main_object.contains_addr(a) and not f.is_simprocedure}
    records=[]
    for a in sorted(seed|set(funcs)):
        f=funcs.get(a)
        records.append({'va':a,'rva':a-row['image_base'],'name':f.name if f else None,'exports':exports[a],'unwind_or_entry_or_export_seed':a in seed,'size':f.size if f else None,'blocks':[{'va':n.addr,'size':n.size} for n in sorted(f.graph.nodes,key=lambda n:n.addr) if hasattr(n,'size')] if f else [],'status':'pending' if f else 'seed not recovered by CFG; inspect disassembly and exception-range boundaries','pseudocode_lines':0,'manually_verified':False})
    calls=[]
    for a,f in funcs.items():
        for site in sorted(f.get_call_sites()):
            target=f.get_call_target(site)
            calls.append({'caller_va':a,'call_block_va':site,'target_va':target,'target_name':cfg.kb.functions[target].name if target in cfg.kb.functions else None,'return_va':f.get_call_return(site)})
    dump(dest/'calls.json',calls)
    xrefs=[]
    for target, refs in sorted(cfg.kb.xrefs.xrefs_by_dst.items()):
        for ref in refs:
            xrefs.append({'source_instruction_va':ref.ins_addr,'source_block_va':ref.block_addr,'target_va':ref.dst,'type':str(ref.type)})
    dump(dest/'xrefs.json',xrefs)
    indirect=[]
    for addr,jump in sorted(cfg.indirect_jumps.items()):
        indirect.append({'instruction_va':addr,'resolved_targets':sorted(jump.resolved_targets),'jumpkind':jump.jumpkind})
    dump(dest/'indirect-jumps.json',indirect)
    ordered=sorted(records,key=lambda r:(not bool(r['exports']),r['va']!=p.entry,r['size'] if r['size'] is not None else 10**10,r['va']))
    start=time.monotonic()
    # One logical module file avoids tens of thousands of tiny generated artifacts.
    with (src/'pseudocode.c').open('w') as out:
        out.write('/* AUTOMATED ANGR PSEUDOCODE, NOT ORIGINAL SOURCE; NOT A BUILD TARGET.\n'
                  ' * Types, signatures, locals, calling conventions and control flow are inferred, unverified.\n'
                  f' * Input SHA256: {row["sha256"]}; addresses use preferred image base.\n'
                  ' * Per-function omissions and errors: analysis/report/modules/'+module+'/function-coverage.json\n */\n\n')
        lineno=7
        for r in ordered:
            if r['status']!='pending':continue
            if time.monotonic()-start>budget:
                r['status']='deferred: module decompilation time budget exhausted; rerun with larger --budget';continue
            f=funcs[r['va']]; begin=time.monotonic()
            signal.setitimer(signal.ITIMER_REAL,seconds)
            try:
                dec=p.analyses.Decompiler(f,cfg=cfg.model)
                if dec.codegen is None:
                    r['status']='no codegen returned; inspect CFG and angr log';continue
                code=dec.codegen.text
                header=f'/* VA {r["va"]:#x}, RVA {r["rva"]:#x}, CFG name {r["name"]}; exports: {r["exports"]} */\n'
                fragment=header+code+'\n\n'
                out.write(fragment);out.flush()
                r['pseudocode_line']=lineno;r['pseudocode_lines']=fragment.count('\n');lineno+=r['pseudocode_lines']
                r['status']='automated pseudocode; unverified'
                r['inferred_prototype']=str(f.prototype) if f.prototype else None
                r['inferred_calling_convention']=str(f.calling_convention) if f.calling_convention else None
            except Deadline:
                r['status']='timeout: per-function decompilation deadline; rerun with larger --function-seconds'
            except Exception as exc:
                r['status']='decompiler exception';r['error']=type(exc).__name__+': '+str(exc)
            finally:
                signal.setitimer(signal.ITIMER_REAL,0)
                r['decompilation_seconds']=round(time.monotonic()-begin,3)
                # Drop codegen caches to bound batch memory; CFG remains retained.
                p.kb.decompilations.discard((f.addr,'pseudocode'))
    summary=dict(collections.Counter(r['status'] for r in records))
    settings['decompilation_elapsed_seconds']=round(time.monotonic()-start,2)
    dump(dest/'function-coverage.json',{'settings':settings,'status':'bounded pass complete','summary':summary,'functions':records})
    print(module,summary,flush=True)
if __name__=='__main__':
    ap=argparse.ArgumentParser();ap.add_argument('--module',required=True);ap.add_argument('--budget',type=float,default=180);ap.add_argument('--function-seconds',type=float,default=3)
    ap.add_argument('--seeded',action='store_true',help='Disable prologue and linear smart scan; retain unwind/export/entry roots and reachable functions')
    ap.add_argument('--cfg-seconds',type=float,default=240)
    a=ap.parse_args();raise SystemExit(run(a.module,a.budget,a.function_seconds,a.seeded,a.cfg_seconds))
