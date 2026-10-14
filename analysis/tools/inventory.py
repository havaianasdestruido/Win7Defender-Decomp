#!/usr/bin/env python3
"""Read-only PE inventory using pefile; reports and per-module interfaces. See README.md."""
from pathlib import Path
import collections, datetime, gzip, hashlib, json, re, struct, subprocess
import pefile
ROOT = Path(__file__).resolve().parents[2]
REPORT = ROOT / 'analysis/report'
def dump(path, data):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(data, indent=2, ensure_ascii=False) + '\n')
def text(b): return b.decode('utf-8', 'replace') if isinstance(b, bytes) else str(b)
def module_id(p): return '__'.join(p.relative_to(ROOT/'bin').parts)
def sha(b): return hashlib.sha256(b).hexdigest()
def resources(pe):
    result=[]; decoded=[]
    def walk(node, ids):
        for e in node.entries:
            key = str(e.name) if e.name is not None else e.id
            path = ids+[key]
            if hasattr(e, 'directory'): walk(e.directory, path); continue
            d=e.data.struct; blob=pe.get_data(d.OffsetToData,d.Size)
            row={'path':path,'type':pefile.RESOURCE_TYPE.get(path[0],str(path[0])), 'rva':d.OffsetToData,
                 'file_offset':pe.get_offset_from_rva(d.OffsetToData),'size':d.Size,'codepage':d.CodePage,'sha256':sha(blob)}
            result.append(row)
            if path[0]==6:
                pos=0
                for i in range(16):
                    if pos+2>len(blob): break
                    n=struct.unpack_from('<H',blob,pos)[0]; pos+=2
                    if pos+2*n>len(blob): raise ValueError('truncated RT_STRING')
                    if n: decoded.append({'resource':path,'id':(int(path[1])-1)*16+i,'rva':d.OffsetToData+pos,'kind':'string','text':blob[pos:pos+2*n].decode('utf-16le','replace')})
                    pos+=2*n
            elif path[0]==11 and len(blob)>=4:
                n=struct.unpack_from('<I',blob)[0]
                for j in range(n):
                    low,high,pos=struct.unpack_from('<III',blob,4+12*j)
                    for mid in range(low,high+1):
                        length,flags=struct.unpack_from('<HH',blob,pos)
                        if length<4 or pos+length>len(blob): raise ValueError('invalid message entry')
                        decoded.append({'resource':path,'id':mid,'rva':d.OffsetToData+pos,'kind':'message','flags':flags,'text':blob[pos+4:pos+length].decode('utf-16le' if flags&1 else 'cp1252','replace').rstrip('\0')})
                        pos+=length
            elif path[0]==24:
                decoded.append({'resource':path,'rva':d.OffsetToData,'kind':'manifest','text':blob.decode('utf-8-sig','replace').rstrip('\0')})
    if hasattr(pe,'DIRECTORY_ENTRY_RESOURCE'): walk(pe.DIRECTORY_ENTRY_RESOURCE,[])
    return result,decoded

def inspect(p):
    b=p.read_bytes(); row={'path':str(p.relative_to(ROOT)),'module':module_id(p),'size':len(b),'sha256':sha(b)}
    if b[:2]!=b'MZ':
        row.update(format='text',architecture=None,status='inventoried; non-executable input')
        return row
    pe=pefile.PE(data=b,fast_load=False)
    o=pe.OPTIONAL_HEADER; base=o.ImageBase
    row.update(format='PE32+' if o.Magic==0x20b else 'PE32', architecture=pefile.MACHINE_TYPE.get(pe.FILE_HEADER.Machine),bitness=64 if o.Magic==0x20b else 32,endianness='little',image_base=base,entry_rva=o.AddressOfEntryPoint,
               coff_timestamp=pe.FILE_HEADER.TimeDateStamp,coff_timestamp_utc=datetime.datetime.fromtimestamp(pe.FILE_HEADER.TimeDateStamp,datetime.timezone.utc).isoformat(),coff_characteristics=pe.FILE_HEADER.Characteristics,
               linker_version=f'{o.MajorLinkerVersion}.{o.MinorLinkerVersion}',os_version=f'{o.MajorOperatingSystemVersion}.{o.MinorOperatingSystemVersion}',subsystem=o.Subsystem,
               dll_characteristics=o.DllCharacteristics,file_alignment=o.FileAlignment,section_alignment=o.SectionAlignment,size_of_image=o.SizeOfImage,
               checksum_stored=o.CheckSum,checksum_computed=pe.generate_checksum(),coff_symbols=pe.FILE_HEADER.NumberOfSymbols,
               managed_cli_directory=bool(o.DATA_DIRECTORY[14].VirtualAddress),status='structural analysis complete; semantic coverage tracked separately')
    row['sections']=[{'name':text(s.Name.rstrip(b'\0')),'rva':s.VirtualAddress,'virtual_size':s.Misc_VirtualSize,'file_offset':s.PointerToRawData,'raw_size':s.SizeOfRawData,'characteristics':s.Characteristics,'entropy':round(s.get_entropy(),4)} for s in pe.sections]
    row['directories']=[{'name':d.name,'address':d.VirtualAddress,'size':d.Size,'coordinate':'file offset' if i==4 else 'RVA'} for i,d in enumerate(o.DATA_DIRECTORY)]
    row['imports']=[]
    for kind,attr in [('normal','DIRECTORY_ENTRY_IMPORT'),('delay','DIRECTORY_ENTRY_DELAY_IMPORT')]:
        for d in getattr(pe,attr,[]):
            for i in d.imports:
                row['imports'].append({'dll':text(d.dll),'name':text(i.name) if i.name else None,'ordinal':i.ordinal,'hint':i.hint,'iat_va':i.address,'kind':kind})
    row['exports']=[{'name':text(s.name) if s.name else None,'ordinal':s.ordinal,'rva':s.address,'va':base+s.address,'forwarder':text(s.forwarder) if s.forwarder else None} for s in getattr(getattr(pe,'DIRECTORY_ENTRY_EXPORT',None),'symbols',[])]
    row['runtime_functions']=[{'begin_rva':e.struct.BeginAddress,'end_rva':e.struct.EndAddress,'unwind_rva':e.struct.UnwindData} for e in getattr(pe,'DIRECTORY_ENTRY_EXCEPTION',[])]
    row['relocations']=[{'rva':e.rva,'type':e.type} for block in getattr(pe,'DIRECTORY_ENTRY_BASERELOC',[]) for e in block.entries]
    row['debug']=[]
    for d in getattr(pe,'DIRECTORY_ENTRY_DEBUG',[]):
        blob=b[d.struct.PointerToRawData:d.struct.PointerToRawData+d.struct.SizeOfData]
        out={'type':d.struct.Type,'file_offset':d.struct.PointerToRawData,'size':d.struct.SizeOfData}
        if blob[:4]==b'RSDS' and len(blob)>=24:
            import uuid
            out.update(signature='RSDS',guid=str(uuid.UUID(bytes_le=blob[4:20])),age=struct.unpack_from('<I',blob,20)[0],pdb_path=text(blob[24:].split(b'\0')[0]))
        row['debug'].append(out)
    row['rich_header']=pe.parse_rich_header()
    if row['rich_header']:
        row['rich_header']={k:(v.hex() if isinstance(v,(bytes,bytearray)) else v) for k,v in row['rich_header'].items()}
    row['load_config']={}
    if hasattr(pe,'DIRECTORY_ENTRY_LOAD_CONFIG'):
        s=pe.DIRECTORY_ENTRY_LOAD_CONFIG.struct
        row['load_config']={name:getattr(s,name) for name in s.__keys__ if isinstance(name,str)}
        # pefile keys are grouped lists on some releases.
        row['load_config']={name:getattr(s,name) for names in s.__keys__ for name in (names if isinstance(names,list) else [names])}
    row['tls']=None
    if hasattr(pe,'DIRECTORY_ENTRY_TLS'):
        t=pe.DIRECTORY_ENTRY_TLS.struct
        callbacks=[]; va=t.AddressOfCallBacks
        if va:
            for i in range(256):
                value=struct.unpack('<Q',pe.get_data(va-base+i*8,8))[0]
                if not value: break
                callbacks.append(value)
        row['tls']={'start_va':t.StartAddressOfRawData,'end_va':t.EndAddressOfRawData,'index_va':t.AddressOfIndex,'callbacks':callbacks}
    row['version']={}
    for group in getattr(pe,'FileInfo',[]):
        for s in group:
            for table in getattr(s,'StringTable',[]): row['version'].update({text(k):text(v) for k,v in table.entries.items()})
    row['resources'],decoded=resources(pe)
    row['resource_counts']=dict(collections.Counter(str(r['path'][0]) for r in row['resources']))
    overlay=pe.get_overlay_data_start_offset()
    row['overlay']=None if overlay is None else {'offset':overlay,'size':len(b)-overlay,'sha256':sha(b[overlay:])}
    sec=o.DATA_DIRECTORY[4]; row['certificates']=[]
    if sec.VirtualAddress:
        pos=sec.VirtualAddress
        while pos+8<=min(len(b),sec.VirtualAddress+sec.Size):
            length,revision,typ=struct.unpack_from('<IHH',b,pos)
            if length<8 or pos+length>len(b): break
            row['certificates'].append({'file_offset':pos,'size':length,'revision':revision,'type':typ,'sha256':sha(b[pos:pos+length])});pos+=(length+7)&~7
    row['embedded_candidates']=[]
    for magic in [b'MZ',b'PK\x03\x04',b'MSCF',b'7z\xbc\xaf\x27\x1c']:
        for m in re.finditer(re.escape(magic),b):
            off=m.start()
            if off==0: continue
            valid=False
            if magic==b'MZ' and off+64<=len(b):
                ptr=struct.unpack_from('<I',b,off+60)[0]+off
                valid=ptr+4<=len(b) and b[ptr:ptr+4]==b'PE\0\0'
            row['embedded_candidates'].append({'file_offset':off,'magic':magic.hex(),'validated_nested_pe':valid})
    row['warnings']=pe.get_warnings()
    out=REPORT/'modules'/row['module']; out.mkdir(parents=True,exist_ok=True)
    strings=[]
    for enc,pattern in [('ascii',rb'[\x20-\x7e]{5,}'),('utf-16le',rb'(?:[\x20-\x7e]\x00){5,}')]:
        for m in re.finditer(pattern,b): strings.append({'file_offset':m.start(),'encoding':enc,'text':m.group().decode(enc)})
    dump(out/'strings.json',sorted(strings,key=lambda s:s['file_offset']))
    with gzip.open(out/'objdump.txt.gz','wt') as f:
        cp=subprocess.run(['objdump','-x','-d','-w','-M','intel',str(p)],capture_output=True,text=True)
        f.write(cp.stdout); f.write(cp.stderr)
    row['objdump_exit_code']=cp.returncode
    dump(out/'metadata.json',row)
    src=ROOT/'src'/row['module']; src.mkdir(parents=True,exist_ok=True)
    dump(src/'resources.json',{'input_sha256':row['sha256'],'inventory':row['resources'],'decoded':decoded})
    dump(src/'interfaces.json',{'input_sha256':row['sha256'],'image_base':base,'imports':row['imports'],'exports':row['exports'],'calling_convention':'Microsoft x64 ABI; individual signatures not encoded by PE import/export tables','types':'Unknown unless supported by separately reviewed disassembly; do not infer from undecorated names.'})
    src.joinpath('README.md').write_text(f"# {row['module']}\n\nInput: `{row['path']}`; SHA-256 `{row['sha256']}`.\n\nNative AMD64 PE32+; preferred image base `{base:#x}`, entry RVA `{o.AddressOfEntryPoint:#x}`. Addresses in automatic pseudocode refer to preferred-image virtual addresses, not runtime ASLR addresses.\n\n- `interfaces.json`: exact imports, exports and IAT locations; these tables do not encode C prototypes.\n- `resources.json`: resource tree with original RVA/file-offset/hash provenance and decoded RT_STRING, RT_MESSAGETABLE and RT_MANIFEST where present. Icons, dialogs, version, MUI and custom resources are inventoried, not all semantically decoded.\n- Structural evidence and strings: `analysis/report/modules/{row['module']}/`.\n- Automated function recovery/decompilation, when code exists: see per-function coverage there. Pseudocode is not original source and inferred types are unverified.\n\n## Compatibility constraints\n\nWindows x64, little-endian, Microsoft x64 calling convention (RCX/RDX/R8/R9 integer arguments, shadow space, RAX return as appropriate); signatures vary. PE directory references are RVAs except the certificate table. Required imported DLLs are listed without assuming host implementations. No runtime equivalence or complete clean-room reimplementation is claimed. No DLL build target is supplied for opaque, unreconstructed interfaces.\n")
    pe.close(); return row

def main():
    REPORT.mkdir(parents=True,exist_ok=True)
    rows=[inspect(p) for p in sorted((ROOT/'bin').rglob('*')) if p.is_file()]
    dump(REPORT/'inventory.json',rows)
    lines=['# Input inventory','', 'All inputs opened read-only. Timestamps are untrusted COFF header values, not provenance proofs. SHA-256 identities are checked separately after analysis.','', '| File | Bytes | Format / architecture | SHA-256 | Status |','|---|---:|---|---|---|']
    for r in rows: lines.append(f"| `{r['path']}` | {r['size']} | {r['format']} / {r.get('architecture') or 'n/a'} | `{r['sha256']}` | {r['status']} |")
    groups=collections.defaultdict(list)
    for r in rows: groups[r['sha256']].append(r['path'])
    lines+=['','## Duplicate identities',json.dumps([v for v in groups.values() if len(v)>1]),'', '## Detailed evidence','`inventory.json` and `modules/<filename>/metadata.json` retain sections, entropy, header flags, compiler indicators (not compiler proof), debug/PDB identities, exceptions, TLS, load config, relocation entries, resource inventory, certificate records, overlay hashes and embedded-magic candidates. An MZ byte hit alone is not a nested executable. No general-purpose unpacking or nested archive extraction is claimed.','']
    (REPORT/'inventory.md').write_text('\n'.join(lines))
    print(f'Inventoried {len(rows)} files, {sum(r["format"].startswith("PE") for r in rows)} PE images')
if __name__=='__main__': main()
