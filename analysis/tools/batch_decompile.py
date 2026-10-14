#!/usr/bin/env python3
"""Run isolated module workers, two at a time; logs/progress survive partial failures."""
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor
import argparse,json,subprocess,sys
ROOT=Path(__file__).resolve().parents[2]
def main():
    ap=argparse.ArgumentParser();ap.add_argument('--budget',type=int,default=240);ap.add_argument('--workers',type=int,default=2)
    ap.add_argument('--module',action='append',help='Restrict to named module; repeatable')
    a=ap.parse_args();rows=json.loads((ROOT/'analysis/report/inventory.json').read_text())
    rows=[r for r in rows if r['format'].startswith('PE') and (not a.module or r['module'] in a.module)]
    rows.sort(key=lambda r:len(r['runtime_functions']))
    def run(r):
        d=ROOT/'analysis/report/modules'/r['module']; print('START',r['module'],flush=True)
        with (d/'angr.log').open('w') as f:
            args=[sys.executable,str(ROOT/'analysis/tools/decompile.py'),'--module',r['module'],'--budget',str(a.budget)]
            try:
                cp=subprocess.run(args,stdout=f,stderr=subprocess.STDOUT,timeout=600+a.budget)
                receipt={'command':args,'exit_code':cp.returncode}
            except subprocess.TimeoutExpired:receipt={'command':args,'timeout':True}
        (d/'angr-run.json').write_text(json.dumps(receipt,indent=2)+'\n')
        print('END',r['module'],receipt,flush=True)
    with ThreadPoolExecutor(max_workers=a.workers) as pool:list(pool.map(run,rows))
if __name__=='__main__':main()
