#!/usr/bin/env python3
"""Compare portable resolver with actual original AMD64 instructions in Unicorn.
No Windows process/service is launched; LoadStringW is an explicit controlled stub.
Usage: python validate_behavior.py --library analysis/report/work/mpasdesc/libmpasdesc_model.so
"""
from pathlib import Path
import argparse,ctypes,hashlib,json,struct,time
import pefile,unicorn
from unicorn import Uc,UC_ARCH_X86,UC_MODE_64,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_RAX,UC_X86_REG_RCX,UC_X86_REG_RDX,UC_X86_REG_R8,UC_X86_REG_R9,UC_X86_REG_RSP
from inventory import ROOT,REPORT,dump
STACK=0x10000000;OUT=STACK+0x100;HOOK=0x20000000;STOP=HOOK+0x100
class Image:
    def __init__(self,filename):
        self.pe=pefile.PE(str(ROOT/'bin'/filename));self.base=self.pe.OPTIONAL_HEADER.ImageBase
        self.uc=Uc(UC_ARCH_X86,UC_MODE_64)
        self.uc.mem_map(self.base,(self.pe.OPTIONAL_HEADER.SizeOfImage+0xfff)&~0xfff)
        self.uc.mem_write(self.base,self.pe.get_memory_mapped_image())
        self.uc.mem_map(STACK,0x10000);self.uc.mem_map(HOOK,0x1000)
        self.uc.mem_write(HOOK,b'\xc3');self.uc.mem_write(STOP,b'\x90')
    def call(self,rva,args=()):
        sp=STACK+0xff08;self.uc.reg_write(UC_X86_REG_RSP,sp);self.uc.mem_write(sp,struct.pack('<Q',STOP))
        for reg,value in zip([UC_X86_REG_RCX,UC_X86_REG_RDX,UC_X86_REG_R8,UC_X86_REG_R9],args): self.uc.reg_write(reg,value&0xffffffffffffffff)
        self.uc.emu_start(self.base+rva,STOP,timeout=100000,count=1000)
        # Reaching STOP distinguishes successful return from count/timeout exhaustion.
        from unicorn.x86_const import UC_X86_REG_RIP
        assert self.uc.reg_read(UC_X86_REG_RIP)==STOP,'function did not return'
        return self.uc.reg_read(UC_X86_REG_RAX)
def main():
    ap=argparse.ArgumentParser();ap.add_argument('--library',required=True);a=ap.parse_args()
    lib=ctypes.CDLL(str(Path(a.library).resolve()));CB=ctypes.CFUNCTYPE(ctypes.c_int,ctypes.c_void_p,ctypes.c_uint32)
    resolve=lib.mp_description_resolve;resolve.argtypes=[ctypes.c_int32,ctypes.c_uint32,ctypes.POINTER(ctypes.c_uint32),CB,ctypes.c_void_p];resolve.restype=ctypes.c_uint32
    img=Image('MpAsDesc.dll');uc=img.uc;base=img.base
    table=[struct.unpack('<III',img.pe.get_data(0x11f0+12*i,12)) for i in range(7)]
    class Range(ctypes.Structure):_fields_=[('first',ctypes.c_uint32),('limit',ctypes.c_uint32),('fallback',ctypes.c_uint32)]
    compiled=(Range*7).in_dll(lib,'mp_description_ranges')
    assert table==[(r.first,r.limit,r.fallback) for r in compiled]
    uc.mem_write(base+0x3138,struct.pack('<Q',base+0x3138)) # disable optional WPP logging
    uc.mem_write(base+0x36e8,struct.pack('<Q',0xabcdef00))
    uc.mem_write(base+0x10d8,struct.pack('<Q',HOOK))
    strings=json.loads((ROOT/'src/pt-BR__MpAsDesc.dll.mui/resources.json').read_text())['decoded']
    existing={r['id'] for r in strings if r['kind']=='string' and r['text']}
    mode=0;native_calls=[];model_calls=[];cases=[];digest=hashlib.sha256();start=time.monotonic()
    def available(id):return mode==1 or (mode==2 and id in existing)
    def hook(uc,address,size,data):
        if address!=HOOK:return
        assert uc.reg_read(UC_X86_REG_RCX)==0xabcdef00
        assert uc.reg_read(UC_X86_REG_R9)==2
        id=uc.reg_read(UC_X86_REG_RDX)&0xffffffff;native_calls.append(id)
        result=int(available(id))
        if result:uc.mem_write(uc.reg_read(UC_X86_REG_R8),b'X\0\0\0')
        uc.reg_write(UC_X86_REG_RAX,result)
    uc.hook_add(UC_HOOK_CODE,hook)
    @CB
    def probe(context,id):model_calls.append(id);return int(available(id))
    total=0
    for mode in range(3):
        for category in [-2147483648,-1,0,1,2,3,4,5,6,7,8,2147483647]:
            values=list(range(1002))+[0x7fffffff,0x80000000,0xffffffff] if 1<=category<=7 else [0,999,1000,0xffffffff]
            for value in values:
                native_calls.clear();model_calls.clear();uc.mem_write(OUT,struct.pack('<I',0xdeadbeef));out=ctypes.c_uint32(0xdeadbeef)
                native=img.call(0x1768,[category,value,OUT])&0xffffffff
                modeled=resolve(category,value,ctypes.byref(out),probe,None)
                result=struct.unpack('<I',uc.mem_read(OUT,4))[0]
                assert (native,result,native_calls)==(modeled,out.value,model_calls),(mode,category,value,native,result,modeled,out.value)
                digest.update(struct.pack('<IiIIII',mode,category,value,native,result,len(native_calls)));total+=1
                if value in [0,999,1000,0xffffffff]:cases.append({'resource_mode':mode,'category':category,'value':value,'return':native,'output':result,'probe_ids':native_calls.copy()})
        for category in [-1,0,1,7,8]:
            native_calls.clear();model_calls.clear()
            assert img.call(0x1768,[category,0,0])&0xffffffff==resolve(category,0,None,probe,None)==0x80070057
            assert not native_calls and not model_calls;total+=1
    simple=[]
    for file,rva,global_rva in [('MpAsDesc.dll',0x1758,0x36e8),('MsMpRes.dll',0x1640,0x36e8)]:
        test=Image(file)
        for value in [0,0x123456789abcdef0]:
            test.uc.mem_write(test.base+global_rva,struct.pack('<Q',value));assert test.call(rva)==value
        simple.append({'file':file,'rva':rva,'cases':2,'result':'pass: returns controlled 64-bit global'})
    for file,rva in [('MpOAV.dll',0x3ff4),('MsMpCom.dll',0x3b0c)]:
        test=Image(file);assert test.call(rva)&0xffffffff==0x80070032
        simple.append({'file':file,'rva':rva,'cases':1,'result':'pass: aliased registration exports return 0x80070032'})
    dump(REPORT/'behavior-validation.json',{'result':'pass','unicorn_version':unicorn.__version__,'resolver_cases':total,'table_matches_original':True,'resource_modes':['all absent','all present','nonempty pt-BR RT_STRING IDs (modeled, not Windows MUI loader)'],'outcomes_sha256':digest.hexdigest(),'seconds':round(time.monotonic()-start,3),'boundary_examples':cases,'simple_exports':simple,'limitations':['WPP tracing explicitly disabled by self-sentinel state','LoadStringW stubbed, not a Windows API implementation','DLL initialization, exception handling, service/UI and actual MUI fallback not executed','Writable valid output or null tested; access violations not modeled','No original software process launched; only selected bounded subroutines emulated']})
    print('PASS',total,'resolver cases; 6 simple export cases; original table equals model')
if __name__=='__main__':main()
