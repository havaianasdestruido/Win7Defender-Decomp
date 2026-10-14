#!/usr/bin/env python3
"""Validate provenance/coverage, normalize pseudocode line anchors and save receipts.
Read-only to bin/; only function-coverage line-number fields are normalized in place.
"""
import collections,gzip,hashlib,json,re,subprocess
from inventory import ROOT,REPORT,dump

def main():
    rows=json.loads((REPORT/'inventory.json').read_text());checks=[];failures=[]
    def check(name,ok,detail=None):
        record={'check':name,'pass':bool(ok),'detail':detail};checks.append(record)
        if not ok:failures.append(record)
    local={r['module'].lower():r for r in rows}
    actual_inputs={str(p.relative_to(ROOT)) for p in (ROOT/'bin').rglob('*') if p.is_file()}
    check('exact original input file set',actual_inputs=={r['path'] for r in rows})
    for r in rows:
        data=(ROOT/r['path']).read_bytes();check(r['path']+' hash unchanged',hashlib.sha256(data).hexdigest()==r['sha256'])
        cp=subprocess.run(['git','show','HEAD:'+r['path']],cwd=ROOT,capture_output=True)
        check(r['path']+' equals original Git object',cp.returncode==0 and cp.stdout==data)
        if not r['format'].startswith('PE'):continue
        m=r['module'];dest=REPORT/'modules'/m
        check(m+' PE checksum',r['checksum_stored']==r['checksum_computed'])
        check(m+' objdump successful',r['objdump_exit_code']==0)
        listing=gzip.open(dest/'objdump.txt.gz','rt').read()
        check(m+' objdump architecture agrees','file format pei-x86-64' in listing)
        for command in ['inspect-artifact','inspect-managed-artifact']:
            e=json.loads((dest/f'rea-{command}.json').read_text())
            check(m+' REA '+command+' SHA256',e['subject']['digest']['sha256']==r['sha256'])
            if command=='inspect-managed-artifact':
                n=e['normalized_result'];check(m+' REA native AMD64',n['pe']['machine']==0x8664 and n['pe']['section_count']==len(r['sections']) and n['classification']['status']=='not-managed')
        with gzip.open(dest/'static-calls.json.gz','rt') as f:static_calls=json.load(f)
        check(m+' Capstone instruction bytes match input',all(data[c['file_offset']:c['file_offset']+len(bytes.fromhex(c['bytes']))]==bytes.fromhex(c['bytes']) for c in static_calls),{'sites':len(static_calls)})
        if r['runtime_functions']:
            graph=json.loads((dest/'calls.json').read_text())
            check(m+' nonempty call-site evidence',len(graph)>0,{'angr_call_records':len(graph)})
        for res in r['resources']:
            o=res['file_offset'];n=res['size'];check(m+' resource '+str(res['path']),0<=o<=o+n<=len(data) and hashlib.sha256(data[o:o+n]).hexdigest()==res['sha256'])
        for f in r['runtime_functions']:
            check(m+f' unwind range {f["begin_rva"]:#x}',f['begin_rva']<f['end_rva']<=r['size_of_image'] and any(s['rva']<=f['begin_rva']<s['rva']+s['virtual_size'] and s['characteristics']&0x20000000 for s in r['sections']))
        for imp in r['imports']:
            lib=local.get(imp['dll'].lower())
            if lib and lib['format'].startswith('PE'):
                ok=any((e['name']==imp['name']) if imp['name'] else (e['ordinal']==imp['ordinal']) for e in lib['exports'])
                check(m+' internal import '+imp['dll']+'!'+str(imp['name'] or imp['ordinal']),ok)
        details=json.loads((ROOT/'src'/m/'resource-details.json').read_text())
        for d in details:
            for chunk in d.get('chunks',[]):check(m+' PNG chunk CRC '+str(d['resource'])+f"/{chunk['offset']}",chunk['crc_valid'])
        fc=dest/'function-coverage.json'
        check(m+' function coverage exists',fc.exists())
        if not fc.exists():continue
        coverage=json.loads(fc.read_text());code=ROOT/'src'/m/'pseudocode.c'
        anchors={}
        if code.exists():
            for i,line in enumerate(code.read_text().splitlines(),1):
                match=re.match(r'/\* VA (0x[0-9a-f]+),',line)
                if match:anchors[int(match[1],16)]=i
        fs=coverage['functions'];emit=[f for f in fs if f['status']=='automated pseudocode; unverified']
        check(m+' emitted pseudocode ledger matches',set(anchors)=={f['va'] for f in emit})
        for f in emit:f['pseudocode_line']=anchors[f['va']]
        review_index=json.loads((REPORT/'manual-review-index.json').read_text())
        reviews={int(x['rva'],0):x for x in review_index['functions'] if x['module']==m}
        for f in fs:
            if f.get('rva') in reviews:
                f['manual_review']=reviews[f['rva']]
                f['manual_review_note']='Narrow original-instruction review; manually_verified remains false for uncertified automatic pseudocode/types.'
        dump(fc,coverage)
        seeds={r['image_base']+f['begin_rva'] for f in r['runtime_functions']}|{e['va'] for e in r['exports'] if not e['forwarder']}
        if r['entry_rva']:seeds.add(r['image_base']+r['entry_rva'])
        check(m+' all identified seed functions accounted',seeds<={f['va'] for f in fs})
    receipt={'result':'pass' if not failures else 'fail','check_count':len(checks),'failed':failures,'checks':checks,'normalization':'pseudocode_line re-derived from actual VA comment anchors; no pseudocode changed'}
    dump(REPORT/'artifact-validation.json',receipt)
    print(receipt['result'],len(checks),'checks;',len(failures),'failures')
    for failure in failures[:30]:print(failure)
    raise SystemExit(bool(failures))
if __name__=='__main__':main()
