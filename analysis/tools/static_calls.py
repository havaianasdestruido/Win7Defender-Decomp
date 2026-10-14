#!/usr/bin/env python3
"""Independent Capstone cross-reference pass over original .pdata code ranges.
Records exact CALL/JMP instruction sites and simple, locally proven literal API
arguments. It does not resolve arbitrary indirect calls or evaluate execution paths.
"""
import gzip,json
from capstone import Cs,CS_ARCH_X86,CS_MODE_64,CS_GRP_JUMP,CS_GRP_CALL,CS_GRP_RET
from capstone.x86 import X86_OP_IMM,X86_OP_MEM,X86_OP_REG,X86_REG_RIP
import pefile
from inventory import ROOT,REPORT,dump

def main():
    for row in json.loads((REPORT/'inventory.json').read_text()):
        if not row['format'].startswith('PE'):continue
        pe=pefile.PE(str(ROOT/row['path']));base=row['image_base'];cs=Cs(CS_ARCH_X86,CS_MODE_64);cs.detail=True
        imports={i['iat_va']:i for i in row['imports']};calls=[];ranges=[];lookups=[]
        def read_string(va,wide):
            try:
                off=pe.get_offset_from_rva(va-base);raw=pe.__data__[off:off+2048]
                if wide:
                    end=next(i for i in range(0,len(raw)-1,2) if raw[i:i+2]==b'\0\0');txt=raw[:end].decode('utf-16le')
                else:txt=raw.split(b'\0',1)[0].decode('ascii')
                return txt if txt and len(txt)<512 else None
            except (ValueError,UnicodeError,StopIteration,pefile.PEFormatError):return None
        for f in row['runtime_functions']:
            rva=f['begin_rva'];end=f['end_rva'];blob=pe.get_data(rva,end-rva);insns=list(cs.disasm(blob,base+rva))
            decoded=sum(i.size for i in insns)
            ranges.append({'begin_rva':rva,'end_rva':end,'decoded_bytes':decoded,'range_bytes':end-rva,'complete_linear_decode':decoded==end-rva})
            for index,ins in enumerate(insns):
                if ins.mnemonic not in ('call','jmp'):continue
                op=ins.operands[0];target=None;iat=None;imp=None
                if op.type==X86_OP_IMM:target=op.imm
                elif op.type==X86_OP_MEM and op.mem.base==X86_REG_RIP:
                    iat=ins.address+ins.size+op.mem.disp;imp=imports.get(iat)
                record={'caller_begin_va':base+rva,'instruction_va':ins.address,'file_offset':pe.get_offset_from_rva(ins.address-base),'mnemonic':ins.mnemonic,'operand':ins.op_str,'bytes':ins.bytes.hex(),'direct_target_va':target,'rip_memory_slot_va':iat,'import':imp,'confidence':'decoded within .pdata range; reachability not established'}
                calls.append(record)
                if not imp or imp['name'] not in ['GetProcAddress','LoadLibraryA','LoadLibraryW','LoadLibraryExA','LoadLibraryExW','GetModuleHandleA','GetModuleHandleW']:continue
                reg='rdx' if imp['name']=='GetProcAddress' else 'rcx';aliases={reg,'e'+reg[1:]}
                literal=None;definition=None
                for prev in reversed(insns[max(0,index-12):index]):
                    if any(prev.group(g) for g in [CS_GRP_CALL,CS_GRP_JUMP,CS_GRP_RET]):break
                    _,writes=prev.regs_access()
                    if not aliases.intersection(prev.reg_name(w) for w in writes):continue
                    if prev.mnemonic=='lea' and len(prev.operands)==2 and prev.operands[0].type==X86_OP_REG and prev.reg_name(prev.operands[0].reg)==reg:
                        operand=prev.operands[1]
                        if operand.type==X86_OP_MEM and operand.mem.base==X86_REG_RIP:
                            va=prev.address+prev.size+operand.mem.disp
                            literal=read_string(va,imp['name'].endswith('W'));definition={'instruction_va':prev.address,'literal_va':va,'bytes':prev.bytes.hex()}
                    break
                lookups.append({'function_start_va':base+rva,'call_instruction_va':ins.address,'api':imp['name'],'literal_argument':literal,'definition':definition,'scope':'same linear instruction window, no intervening branch/call/register overwrite; external entry into that window not excluded'})
        dest=REPORT/'modules'/row['module']
        with gzip.open(dest/'static-calls.json.gz','wt') as output:json.dump(calls,output,indent=2)
        dump(dest/'disassembly-coverage.json',ranges);dump(dest/'dynamic-lookup-sites.json',lookups)
        print(row['module'],len(calls),'call/jump sites;',sum(bool(x['literal_argument']) for x in lookups),'literal API arguments')
if __name__=='__main__':main()
