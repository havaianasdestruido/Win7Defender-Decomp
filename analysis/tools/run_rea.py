#!/usr/bin/env python3
"""Run verified REA 6.5.0 CLI operations on every PE; never execute input code."""
from pathlib import Path
import json, subprocess, hashlib
ROOT=Path(__file__).resolve().parents[2]
cli=ROOT/'analysis/tools/node_modules/.bin/rea'
rows=json.loads((ROOT/'analysis/report/inventory.json').read_text()); results=[]
for r in rows:
    if not r['format'].startswith('PE'): continue
    d=ROOT/'analysis/report/modules'/r['module']; rec={'module':r['module'],'operations':[]}
    for command in ['inspect-artifact','inspect-managed-artifact']:
        args=[str(cli),command,str(ROOT/r['path']),'--json']
        cp=subprocess.run(args,capture_output=True,text=True,timeout=90)
        (d/f'rea-{command}.json').write_text(cp.stdout)
        (d/f'rea-{command}.stderr.txt').write_text(cp.stderr)
        evidence=json.loads(cp.stdout)
        identity=evidence.get('subject',{}).get('digest',{}).get('sha256')
        status={'command':args,'exit_code':cp.returncode,'hash_matches_inventory':identity==r['sha256'],'evidence_id':evidence.get('evidence_id')}
        if command=='inspect-managed-artifact':
            nr=evidence.get('normalized_result',{})
            status['classification']=nr.get('classification')
            status['machine_matches_pefile']=nr.get('pe',{}).get('machine_hex')=='0x8664'
            status['section_count_matches_pefile']=nr.get('pe',{}).get('section_count')==len(r['sections'])
        rec['operations'].append(status)
    assert hashlib.sha256((ROOT/r['path']).read_bytes()).hexdigest()==r['sha256']
    results.append(rec)
    print(r['module'], 'REA completed',flush=True)
(ROOT/'analysis/report/rea-crosscheck.json').write_text(json.dumps(results,indent=2)+'\n')
