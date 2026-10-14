#!/usr/bin/env python3
"""Supplement pefile resource inventory with bounded PNG/RIFF/MSFT header decoding.
MSFT field interpretation follows Wine typelib.h (reference pinned in README).
This is not a general TYPELIB, WEVT, MUI or multimedia decoder.
"""
import struct,uuid,zlib,json
from inventory import ROOT,REPORT,dump
import pefile
SEGMENTS=['typeinfo','importinfo','importfiles','references','guidhash','guids','namehash','names','strings','typedesc','arrays','customdata','customguids','reserved14','reserved15']
def typelib(b):
    h=struct.unpack_from('<21i',b)
    assert b[:4]==b'MSFT'
    fields=['magic','version_signature','guid_offset','lcid','lcid2','flags','version','library_flags','type_count','helpstring','helpstringcontext','helpcontext','name_count','name_chars','name_offset','helpfile','customdata','reserved44','reserved48','dispatchpos','import_count']
    result={'header':dict(zip(fields,h)),'segments':[],'names':[],'guids':[],'types':[]}
    directory=84+h[8]*4+(4 if h[5]&0x100 else 0)
    for i,name in enumerate(SEGMENTS):
        offset,length,r1,r2=struct.unpack_from('<4i',b,directory+16*i)
        assert length>=0 and (length==0 or 0<=offset<=offset+length<=len(b))
        result['segments'].append({'name':name,'offset':offset,'length':length,'reserved':[r1,r2]})
    ns=result['segments'][7];pos=ns['offset'];end=pos+ns['length']
    while pos<end:
        ref,link,flags=struct.unpack_from('<3i',b,pos);n=flags&255
        result['names'].append({'relative_offset':pos-ns['offset'],'resource_offset':pos,'hreftype':ref,'name':b[pos+12:pos+12+n].decode('cp1252'),'flags':flags})
        pos+=(12+n+3)&~3
    gs=result['segments'][5]
    for pos in range(gs['offset'],gs['offset']+gs['length'],24):
        result['guids'].append({'relative_offset':pos-gs['offset'],'resource_offset':pos,'guid':str(uuid.UUID(bytes_le=b[pos:pos+16])),'hreftype':struct.unpack_from('<i',b,pos+16)[0]})
    names={n['relative_offset']:n['name'] for n in result['names']};guids={g['relative_offset']:g['guid'] for g in result['guids']}
    result['library_name']=names.get(h[14]);result['library_guid']=guids.get(h[2])
    kinds=['enum','record','module','interface','dispatch','coclass','alias','union']
    for i in range(h[8]):
        offset=struct.unpack_from('<i',b,84+i*4)[0];pos=result['segments'][0]['offset']+offset
        vals=struct.unpack_from('<25i',b,pos)
        result['types'].append({'resource_offset':pos,'typekind':kinds[vals[0]&15] if (vals[0]&15)<8 else vals[0]&15,'name':names.get(vals[13]),'guid':guids.get(vals[11]),'function_count':vals[6]&65535,'variable_count':(vals[6]>>16)&65535,'size':vals[20],'implemented_types':vals[19]&65535,'vtable_bytes':(vals[19]>>16)&65535,'member_data_offset':vals[1],'raw_words':list(vals)})
    vt_names={0:'EMPTY',1:'NULL',2:'I2',3:'I4',4:'R4',5:'R8',8:'BSTR',9:'IDispatch',11:'VARIANT_BOOL',12:'VARIANT',13:'IUnknown',16:'I1',17:'UI1',18:'UI2',19:'UI4',20:'I8',21:'UI8',22:'INT',23:'UINT',24:'VOID',25:'HRESULT',26:'PTR',27:'SAFEARRAY',28:'CARRAY',29:'USERDEFINED',30:'LPSTR',31:'LPWSTR'}
    type_names={i*100:t['name'] for i,t in enumerate(result['types'])}
    def dtype(value,depth=0):
        assert depth<16
        if value<0:return {'vartype':value&0xfff,'name':vt_names.get(value&0xfff,str(value&0xfff))}
        seg=result['segments'][9];assert 0<=value and value+8<=seg['length']
        a,b1,c,d=struct.unpack_from('<4H',b,seg['offset']+value);vt=a&0xfff
        out={'vartype':vt,'name':vt_names.get(vt,str(vt)),'typedesc_offset':value,'raw_words':[a,b1,c,d]}
        if vt in (26,27):out['target']=dtype((c|0x80000000)-0x100000000 if d&0x8000 else c,depth+1)
        elif vt==29:out.update(hreftype=c|(d<<16),type_name=type_names.get(c|(d<<16)))
        return out
    for t in result['types']:
        count=t['function_count']+t['variable_count'];t['functions']=[];t['variables']=[]
        if not count:continue
        off=t['member_data_offset'];length=struct.unpack_from('<I',b,off)[0]
        assert off+4+length+12*count<=len(b)
        for i in range(count):
            memid,nameoff,recoff=(struct.unpack_from('<i',b,off+4+length+4*(count*j+i))[0] for j in range(3))
            pos=off+4+recoff;raw=struct.unpack_from('<I',b,pos)[0];size=raw&65535
            assert pos+size<=off+4+length
            datatype,flags=struct.unpack_from('<ii',b,pos+4)
            item={'name':names.get(nameoff),'memid':memid,'resource_offset':pos,'record_size':size,'type':dtype(datatype),'flags':flags}
            if i<t['function_count']:
                vtable,descsize,fkccic,nargs,noptional=struct.unpack_from('<HHIHH',b,pos+12)
                item.update(vtable_offset=vtable&~1,callconv=(fkccic>>8)&15,invkind=(fkccic>>3)&15,funckind=fkccic&7,optional_arguments=noptional,parameters=[])
                for j in range(nargs):
                    dt,nm,fl=struct.unpack_from('<iii',b,pos+size-12*nargs+12*j)
                    item['parameters'].append({'name':names.get(nm),'type':dtype(dt),'flags':fl})
                t['functions'].append(item)
            else:
                kind=struct.unpack_from('<H',b,pos+12)[0];value=struct.unpack_from('<i',b,pos+16)[0]
                item.update(varkind=kind,value_raw=value)
                if kind==2 and value<0:item.update(value_vartype=(value&0x7c000000)>>26,value=value&0x3ffffff)
                t['variables'].append(item)
    result['limitations']=['Selected MSFT method/parameter/enum metadata decoded using Wine format interpretation; not cross-checked with Windows LoadTypeLib. Import references, complex arrays and inherited interface layouts not fully resolved.','All offsets are relative to TYPELIB resource, not original PE file. Add resource file_offset.']
    return result

def main():
    rows=json.loads((REPORT/'inventory.json').read_text())
    for row in rows:
        if row['format']=='text':continue
        pe=pefile.PE(str(ROOT/row['path']));details=[];src=ROOT/'src'/row['module']
        for r in row['resources']:
            b=pe.get_data(r['rva'],r['size']);typ=r['path'][0]
            d={'resource':r['path'],'rva':r['rva'],'file_offset':r['file_offset'],'size':r['size'],'sha256':r['sha256'],'prefix_hex':b[:32].hex()}
            if typ=='REGISTRY':
                d['encoding']='cp1252';d['text']=b.decode('cp1252')
            elif typ=='TYPELIB' and b[:4]==b'MSFT':d['typelib']=typelib(b)
            elif typ=='PNG' and b[:8]==b'\x89PNG\r\n\x1a\n':
                pos=8;chunks=[]
                while pos+12<=len(b):
                    n=struct.unpack_from('>I',b,pos)[0];tag=b[pos+4:pos+8];assert pos+12+n<=len(b)
                    stored=struct.unpack_from('>I',b,pos+8+n)[0]
                    chunks.append({'offset':pos,'type':tag.decode('ascii'),'length':n,'crc_valid':stored==zlib.crc32(b[pos+4:pos+8+n])})
                    if tag==b'IHDR':
                        w,h,depth,color,compression,filter_,interlace=struct.unpack_from('>IIBBBBB',b,pos+8)
                        d['image']={'width':w,'height':h,'bit_depth':depth,'color_type':color,'compression':compression,'filter':filter_,'interlace':interlace}
                    pos+=12+n
                    if tag==b'IEND':break
                d['chunks']=chunks;d['trailing_bytes']=len(b)-pos
            elif typ=='AVI' and b[:4]==b'RIFF':
                d['riff']={'declared_total_bytes':struct.unpack_from('<I',b,4)[0]+8,'form':b[8:12].decode('ascii'),'resource_bytes':len(b),'top_level_chunks':[]}
                pos=12
                while pos+8<=min(len(b),d['riff']['declared_total_bytes']):
                    n=struct.unpack_from('<I',b,pos+4)[0];d['riff']['top_level_chunks'].append({'offset':pos,'tag':b[pos:pos+4].decode('ascii','replace'),'size':n});pos+=8+n+(n&1)
            elif typ=='MUI':d['observed_u32_prefix']=list(struct.unpack_from('<7I',b));d['interpretation']='magic/length/version candidate; remaining fields opaque'
            elif typ=='WEVT_TEMPLATE':
                d['observed_crim_header']={'magic':b[:4].decode('ascii'),'u32_at_4':struct.unpack_from('<I',b,4)[0],'u16_at_8':struct.unpack_from('<H',b,8)[0],'u16_at_10':struct.unpack_from('<H',b,10)[0],'u32_at_12':struct.unpack_from('<I',b,12)[0],'guid_at_16':str(uuid.UUID(bytes_le=b[16:32])),'u32_at_32':struct.unpack_from('<I',b,32)[0]}
                d['interpretation']='CRIM + WEVT signatures observed; provider GUID candidate at +16, payload schema not fully decoded'
            else:continue
            details.append(d)
        dump(src/'resource-details.json',details)
        print(row['module'],len(details),'supplemental resources')
if __name__=='__main__':main()
