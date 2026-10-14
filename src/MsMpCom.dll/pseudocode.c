/* AUTOMATED ANGR PSEUDOCODE, NOT ORIGINAL SOURCE; NOT A BUILD TARGET.
 * Types, signatures, locals, calling conventions and control flow are inferred, unverified.
 * Input SHA256: 9e8396674ed1969a87e8108f9beceb8df84e5a5b1d52a40d694c3af88c9887a0; addresses use preferred image base.
 * Per-function omissions and errors: analysis/report/modules/MsMpCom.dll/function-coverage.json
 */

/* VA 0x7ff28f23b0c, RVA 0x3b0c, CFG name DllUnregisterServer; exports: ['DllRegisterServer', 'DllUnregisterServer'] */
unsigned int DllUnregisterServer(void)
{
    return 2147942450;
}


/* VA 0x7ff28f2399c, RVA 0x399c, CFG name DllCanUnloadNow; exports: ['DllCanUnloadNow'] */
typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_0 {
    char padding_0[24];
    struct struct_1 *field_18;
} struct_0;

extern struct_0 *g_7ff28f2d5a0;

long long DllCanUnloadNow(void)
{
    return g_7ff28f2d5a0->field_18(&g_7ff28f2d5a0);
}


/* VA 0x7ff28f239c8, RVA 0x39c8, CFG name DllGetClassObject; exports: ['DllGetClassObject'] */
typedef struct struct_2 {
    struct struct_3 *field_0;
    char padding_8[8];
    struct struct_4 *field_10;
    unsigned long long field_18;
    struct struct_5 *field_20;
} struct_2;

typedef struct struct_1 {
    struct struct_0 *field_0;
} struct_1;

typedef struct struct_3 {
    unsigned int field_0;
    unsigned int field_4;
    unsigned int field_8;
    unsigned int field_c;
} struct_3;

typedef struct struct_4 {
    unsigned long long field_0;
} struct_4;

typedef struct struct_5 {
    struct struct_1 *field_0;
} struct_5;

typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

typedef struct LIST_ENTRY {
    void* Flink;
    void* Blink;
} LIST_ENTRY;

typedef struct CRITICAL_SECTION_DEBUG {
    unsigned short Type;
    unsigned short CreatorBackTraceIndex;
    char padding_4[4];
    void* CriticalSection;
    LIST_ENTRY ProcessLocksList;
    unsigned int EntryCount;
    unsigned int ContentionCount;
    unsigned int Flags;
    unsigned short CreatorBackTraceIndexHigh;
    unsigned short Identifier;
} CRITICAL_SECTION_DEBUG;

typedef struct struct_6 {
    struct struct_2 *field_0;
} struct_6;

typedef struct CRITICAL_SECTION {
    struct CRITICAL_SECTION_DEBUG *DebugInfo;
    int LockCount;
    int RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    UIntPtr SpinCount;
} CRITICAL_SECTION;

extern char g_7ff28f215c0;
extern unsigned int g_7ff28f2ce70;
extern struct_6 *g_7ff28f2ce80;
extern char g_7ff28f2ce88;
extern CRITICAL_SECTION g_7ff28f2ce90;
extern char g_7ff28f2d60c;

unsigned int DllGetClassObject(unsigned long a0, unsigned long a1, unsigned long long *ptr)
{
    struct_2 **cur;  // rcx
    unsigned int v3;  // ebx
    struct_2 *p;  // rsi
    unsigned int v5[4];  // rdx
    char flag;  // [bp+0x20]

    if (!g_7ff28f2d60c)
    {
        g_7ff28f2d60c = 1;
        flag = 0;
        if ((int)sub_7ff28f273d4(&flag, L"dllhost.exe") >= 0 && flag)
            sub_7ff28f26d5c();
    }
    if (!g_7ff28f2ce70)
    {
        return 2147549183;
    }
    else if (!ptr)
    {
        return 2147500035;
    }
    else
    {
        *(ptr) = 0;
        cur = g_7ff28f2ce80;
        v3 = 0;
        while (true)
        {
            if (cur < *((long long *)&g_7ff28f2ce88))
            {
                p = *(cur);
                if (!p || !p->field_10 || (v5 = (unsigned int [4])p->field_0, *((int *)a0) != v5[0] || *((int *)(a0 + 4)) != v5[1] || *((int *)(a0 + 8)) != v5[2] || *((int *)(a0 + 12)) != v5[3]))
                {
                    cur += 1;
                }
                else
                {
                    if (!p->field_20)
                    {
                        EnterCriticalSection(&g_7ff28f2ce90.DebugInfo);
                        if (!p->field_20)
                            v3 = p->field_10(p->field_18, &g_7ff28f215c0, &p->field_20);
                        LeaveCriticalSection(&g_7ff28f2ce90.DebugInfo);
                    }
                    if (p->field_20)
                        v3 = p->field_20->field_0->field_0(p->field_20, a1, ptr);
                    if (*(ptr))
                    {
                        return v3;
                    }
                    else if (v3)
                    {
                        return v3;
                    }
                    goto LABEL_7ff28f23aea;
                }
            }
            else
            {
LABEL_7ff28f23aea:
                break;
            }
        }
        return 2147746065;
    }
}


/* VA 0x7ff28f28fe0, RVA 0x8fe0, CFG name _start; exports: [] */
void _start(long long a0, unsigned int flag, long long a2)
{
    if (flag == 1)
        _security_init_cookie();
    sub_7ff28f28dec(a0, flag, a2);
    return;
}


/* VA 0x7ff28f2177a, RVA 0x177a, CFG name sub_7ff28f2177a; exports: [] */
void sub_7ff28f2177a(void)
{
    return;
}


/* VA 0x7ff28f29456, RVA 0x9456, CFG name sub_7ff28f29456; exports: [] */
int sub_7ff28f29456(void)
{
}


/* VA 0x7ff28f23cfc, RVA 0x3cfc, CFG name sub_7ff28f23cfc; exports: [] */
unsigned int sub_7ff28f23cfc(void)
{
    return 0;
}


/* VA 0x7ff28f25dbc, RVA 0x5dbc, CFG name sub_7ff28f25dbc; exports: [] */
void sub_7ff28f25dbc(void)
{
    return;
}


/* VA 0x7ff28f23bb0, RVA 0x3bb0, CFG name sub_7ff28f23bb0; exports: [] */
typedef struct struct_0 {
    char padding_0[12];
    unsigned int field_c;
} struct_0;

int sub_7ff28f23bb0(struct_0 *a0)
{
    return a0->field_c;
}


/* VA 0x7ff28f26caf, RVA 0x6caf, CFG name sub_7ff28f26caf; exports: [] */
int sub_7ff28f26caf(void)
{
}


/* VA 0x7ff28f2180e, RVA 0x180e, CFG name sub_7ff28f2180e; exports: [] */
void sub_7ff28f2180e(void)
{
    unsigned long v1;  // cc_op
    unsigned long v2;  // cc_dep1
    unsigned long v3;  // cc_dep2
    unsigned long v4;  // cc_ndep
    unsigned long v5;  // 4118

    [D] PutI(904:F64x8)[t5,0] = t6()
    [D] PutI(968:I8x8)[t5,0] = 0x01()
    v5 = _ccall(10, v1, v2, v3, v4);
    if ((char)v5)
        goto LABEL_0x7ff28f21813;
    else
        goto LABEL_0x7ff28f2186a;
}


/* VA 0x7ff28f28fbc, RVA 0x8fbc, CFG name sub_7ff28f28fbc; exports: [] */
void sub_7ff28f28fbc(void)
{
    unsigned int flag;  // [bp+0x20]

    flag = 0;
}


/* VA 0x7ff28f291f2, RVA 0x91f2, CFG name sub_7ff28f291f2; exports: [] */
void sub_7ff28f291f2(void)
{
    free();
    return;
}


/* VA 0x7ff28f291fe, RVA 0x91fe, CFG name memcpy_s; exports: [] */
// attributes: PLT stub
int memcpy_s(void)
{
    ::msvcrt.dll::memcpy_s();
    return;
}


/* VA 0x7ff28f2927a, RVA 0x927a, CFG name _purecall; exports: [] */
// attributes: PLT stub
int _purecall(void)
{
    ::msvcrt.dll::_purecall();
    return;
}


/* VA 0x7ff28f29286, RVA 0x9286, CFG name memmove; exports: [] */
// attributes: PLT stub
int memmove(void)
{
    ::msvcrt.dll::memmove();
    return;
}


/* VA 0x7ff28f29292, RVA 0x9292, CFG name ?what@exception@@UEBAPEBDXZ; exports: [] */
// attributes: PLT stub
char * exception::what(void* this)
{
    return ::msvcrt.dll::exception::what();
}


/* VA 0x7ff28f2929e, RVA 0x929e, CFG name ??1exception@@UEAA@XZ; exports: [] */
// attributes: PLT stub
int exception::~exception(void* this)
{
    return;
}


/* VA 0x7ff28f292aa, RVA 0x92aa, CFG name ??0exception@@QEAA@AEBQEBDH@Z; exports: [] */
// attributes: PLT stub
int exception::exception(void* this, char *&arg_0, int arg_1)
{
    ::msvcrt.dll::exception::exception();
    return;
}


/* VA 0x7ff28f292b6, RVA 0x92b6, CFG name ??0exception@@QEAA@AEBV0@@Z; exports: [] */
// attributes: PLT stub
int exception::exception(void* this, class exception &arg_0)
{
    ::msvcrt.dll::exception::exception();
    return;
}


/* VA 0x7ff28f292c2, RVA 0x92c2, CFG name memset; exports: [] */
// attributes: PLT stub
int memset(void)
{
    ::msvcrt.dll::memset();
    return;
}


/* VA 0x7ff28f292ce, RVA 0x92ce, CFG name __C_specific_handler; exports: [] */
// attributes: PLT stub
int __C_specific_handler(void)
{
    ::msvcrt.dll::__C_specific_handler();
    return;
}


/* VA 0x7ff28f29376, RVA 0x9376, CFG name _XcptFilter; exports: [] */
// attributes: PLT stub
int _XcptFilter(void)
{
    ::msvcrt.dll::_XcptFilter();
    return;
}


/* VA 0x7ff28f29464, RVA 0x9464, CFG name _initterm; exports: [] */
// attributes: PLT stub
int _initterm(void)
{
    ::msvcrt.dll::_initterm();
    return;
}


/* VA 0x7ff28f29470, RVA 0x9470, CFG name _amsg_exit; exports: [] */
// attributes: PLT stub
int _amsg_exit(void)
{
    ::msvcrt.dll::_amsg_exit();
    return;
}


/* VA 0x7ff28f29660, RVA 0x9660, CFG name _unlock; exports: [] */
// attributes: PLT stub
int _unlock(void)
{
    ::msvcrt.dll::_unlock();
    return;
}


/* VA 0x7ff28f2966c, RVA 0x966c, CFG name __dllonexit; exports: [] */
// attributes: PLT stub
int __dllonexit(void)
{
    ::msvcrt.dll::__dllonexit();
    return;
}


/* VA 0x7ff28f29678, RVA 0x9678, CFG name _lock; exports: [] */
// attributes: PLT stub
int _lock(void)
{
    ::msvcrt.dll::_lock();
    return;
}


/* VA 0x7ff28f29684, RVA 0x9684, CFG name RtlVirtualUnwind; exports: [] */
typedef struct IMAGE_RUNTIME_FUNCTION_ENTRY {
    unsigned int BeginAddress;
    unsigned int EndAddress;
    union <anon> Anonymous;
} IMAGE_RUNTIME_FUNCTION_ENTRY;

typedef struct CONTEXT {
    enum CONTEXT_FLAGS ContextFlags;
    unsigned int Dr0;
    unsigned int Dr1;
    unsigned int Dr2;
    unsigned int Dr3;
    unsigned int Dr6;
    unsigned int Dr7;
    FLOATING_SAVE_AREA FloatSave;
    unsigned int SegGs;
    unsigned int SegFs;
    unsigned int SegEs;
    unsigned int SegDs;
    unsigned int Edi;
    unsigned int Esi;
    unsigned int Ebx;
    unsigned int Edx;
    unsigned int Ecx;
    unsigned int Eax;
    unsigned int Ebp;
    unsigned int Eip;
    unsigned int SegCs;
    unsigned int EFlags;
    unsigned int Esp;
    unsigned int SegSs;
    Byte ExtendedRegisters[512];
} CONTEXT;

typedef struct FLOATING_SAVE_AREA {
    unsigned int ControlWord;
    unsigned int StatusWord;
    unsigned int TagWord;
    unsigned int ErrorOffset;
    unsigned int ErrorSelector;
    unsigned int DataOffset;
    unsigned int DataSelector;
    Byte RegisterArea[80];
    unsigned int Spare0;
} FLOATING_SAVE_AREA;

// attributes: PLT stub
enum EXCEPTION_DISPOSITION (*)(struct EXCEPTION_RECORD *, void*, struct CONTEXT *, void*) RtlVirtualUnwind(enum RTL_VIRTUAL_UNWIND_HANDLER_TYPE HandlerType, unsigned long long ImageBase, unsigned long long ControlPc, struct IMAGE_RUNTIME_FUNCTION_ENTRY *FunctionEntry, struct CONTEXT *ContextRecord, void* *HandlerData, unsigned long long *EstablisherFrame, struct KNONVOLATILE_CONTEXT_POINTERS *ContextPointers)
{
    CONTEXT *v1;  // [bp+0x20]

    return ::kernel32.dll::RtlVirtualUnwind(HandlerType, ImageBase, ControlPc, FunctionEntry, v1, ContextRecord, HandlerData, EstablisherFrame);
}


/* VA 0x7ff28f29690, RVA 0x9690, CFG name RtlLookupFunctionEntry; exports: [] */
typedef struct IMAGE_RUNTIME_FUNCTION_ENTRY {
    unsigned int BeginAddress;
    unsigned int EndAddress;
    char Anonymous;
} IMAGE_RUNTIME_FUNCTION_ENTRY;

typedef struct UNWIND_HISTORY_TABLE {
    unsigned int Count;
    Byte LocalHint;
    Byte GlobalHint;
    Byte Search;
    Byte Once;
    UIntPtr LowAddress;
    UIntPtr HighAddress;
    struct UNWIND_HISTORY_TABLE_ENTRY Entry[12];
} UNWIND_HISTORY_TABLE;

// attributes: PLT stub
struct IMAGE_RUNTIME_FUNCTION_ENTRY * RtlLookupFunctionEntry(unsigned long long ControlPc, unsigned long long *ImageBase, struct UNWIND_HISTORY_TABLE *HistoryTable)
{
    return ::kernel32.dll::RtlLookupFunctionEntry(ControlPc, ImageBase, HistoryTable);
}


/* VA 0x7ff28f2969c, RVA 0x969c, CFG name MpConfigInitialize; exports: [] */
// attributes: PLT stub
int MpConfigInitialize(void)
{
    ::rpcrt4.dll::MpConfigInitialize();
    return;
}


/* VA 0x7ff28f296a8, RVA 0x96a8, CFG name MpConfigUninitialize; exports: [] */
// attributes: PLT stub
int MpConfigUninitialize(void)
{
    ::rpcrt4.dll::MpConfigUninitialize();
    return;
}


/* VA 0x7ff28f296b4, RVA 0x96b4, CFG name MpFreeMemory; exports: [] */
// attributes: PLT stub
int MpFreeMemory(void)
{
    ::rpcrt4.dll::MpFreeMemory();
    return;
}


/* VA 0x7ff28f296c0, RVA 0x96c0, CFG name MpHandleClose; exports: [] */
// attributes: PLT stub
int MpHandleClose(void)
{
    ::rpcrt4.dll::MpHandleClose();
    return;
}


/* VA 0x7ff28f296cc, RVA 0x96cc, CFG name MpManagerOpen; exports: [] */
// attributes: PLT stub
int MpManagerOpen(void)
{
    ::rpcrt4.dll::MpManagerOpen();
    return;
}


/* VA 0x7ff28f296d8, RVA 0x96d8, CFG name MpQuarantineRequest; exports: [] */
// attributes: PLT stub
int MpQuarantineRequest(void)
{
    ::rpcrt4.dll::MpQuarantineRequest();
    return;
}


/* VA 0x7ff28f296e4, RVA 0x96e4, CFG name MpThreatOpen; exports: [] */
// attributes: PLT stub
int MpThreatOpen(void)
{
    ::rpcrt4.dll::MpThreatOpen();
    return;
}


/* VA 0x7ff28f296f0, RVA 0x96f0, CFG name MpThreatEnumerate; exports: [] */
// attributes: PLT stub
int MpThreatEnumerate(void)
{
    ::rpcrt4.dll::MpThreatEnumerate();
    return;
}


/* VA 0x7ff28f296fc, RVA 0x96fc, CFG name MpThreatHistoryRequest; exports: [] */
// attributes: PLT stub
int MpThreatHistoryRequest(void)
{
    ::rpcrt4.dll::MpThreatHistoryRequest();
    return;
}


/* VA 0x7ff28f29708, RVA 0x9708, CFG name MpScanControl; exports: [] */
// attributes: PLT stub
int MpScanControl(void)
{
    ::rpcrt4.dll::MpScanControl();
    return;
}


/* VA 0x7ff28f29714, RVA 0x9714, CFG name MpElevationHandleOpen; exports: [] */
// attributes: PLT stub
int MpElevationHandleOpen(void)
{
    ::rpcrt4.dll::MpElevationHandleOpen();
    return;
}


/* VA 0x7ff28f29720, RVA 0x9720, CFG name MpElevationHandleActivate; exports: [] */
// attributes: PLT stub
int MpElevationHandleActivate(void)
{
    ::rpcrt4.dll::MpElevationHandleActivate();
    return;
}


/* VA 0x7ff28f2972c, RVA 0x972c, CFG name MpUpdateControl; exports: [] */
// attributes: PLT stub
int MpUpdateControl(void)
{
    ::rpcrt4.dll::MpUpdateControl();
    return;
}


/* VA 0x7ff28f29738, RVA 0x9738, CFG name MpUtilsExportFunctions; exports: [] */
// attributes: PLT stub
int MpUtilsExportFunctions(void)
{
    ::rpcrt4.dll::MpUtilsExportFunctions();
    return;
}


/* VA 0x7ff28f29744, RVA 0x9744, CFG name __RTDynamicCast; exports: [] */
// attributes: PLT stub
int __RTDynamicCast(void)
{
    ::msvcrt.dll::__RTDynamicCast();
    return;
}


/* VA 0x7ff28f29750, RVA 0x9750, CFG name _CxxThrowException; exports: [] */
// attributes: PLT stub
int _CxxThrowException(void)
{
    ::msvcrt.dll::_CxxThrowException();
    return;
}


/* VA 0x7ff28f2975c, RVA 0x975c, CFG name __CxxFrameHandler3; exports: [] */
// attributes: PLT stub
int __CxxFrameHandler3(void)
{
    ::msvcrt.dll::__CxxFrameHandler3();
    return;
}


/* VA 0x7ff28f29768, RVA 0x9768, CFG name MpClientUtilExportFunctions; exports: [] */
// attributes: PLT stub
int MpClientUtilExportFunctions(void)
{
    ::rpcrt4.dll::MpClientUtilExportFunctions();
    return;
}


/* VA 0x7ff28f29774, RVA 0x9774, CFG name MpConfigOpen; exports: [] */
// attributes: PLT stub
int MpConfigOpen(void)
{
    ::rpcrt4.dll::MpConfigOpen();
    return;
}


/* VA 0x7ff28f29780, RVA 0x9780, CFG name MpConfigGetValueAlloc; exports: [] */
// attributes: PLT stub
int MpConfigGetValueAlloc(void)
{
    ::rpcrt4.dll::MpConfigGetValueAlloc();
    return;
}


/* VA 0x7ff28f2978c, RVA 0x978c, CFG name MpConfigClose; exports: [] */
// attributes: PLT stub
int MpConfigClose(void)
{
    ::rpcrt4.dll::MpConfigClose();
    return;
}


/* VA 0x7ff28f29798, RVA 0x9798, CFG name MpAllocMemory; exports: [] */
// attributes: PLT stub
int MpAllocMemory(void)
{
    ::rpcrt4.dll::MpAllocMemory();
    return;
}


/* VA 0x7ff28f297a4, RVA 0x97a4, CFG name MpConfigSetValue; exports: [] */
// attributes: PLT stub
int MpConfigSetValue(void)
{
    ::rpcrt4.dll::MpConfigSetValue();
    return;
}


/* VA 0x7ff28f297b0, RVA 0x97b0, CFG name MpConfigDelValue; exports: [] */
// attributes: PLT stub
int MpConfigDelValue(void)
{
    ::rpcrt4.dll::MpConfigDelValue();
    return;
}


/* VA 0x7ff28f297bc, RVA 0x97bc, CFG name MpConfigGetValue; exports: [] */
// attributes: PLT stub
int MpConfigGetValue(void)
{
    ::rpcrt4.dll::MpConfigGetValue();
    return;
}


/* VA 0x7ff28f297c8, RVA 0x97c8, CFG name memcpy; exports: [] */
// attributes: PLT stub
int memcpy(void)
{
    ::msvcrt.dll::memcpy();
    return;
}


/* VA 0x7ff28f2986a, RVA 0x986a, CFG name memcmp; exports: [] */
// attributes: PLT stub
int memcmp(void)
{
    ::msvcrt.dll::memcmp();
    return;
}


/* VA 0x7ff28f2aaeb, RVA 0xaaeb, CFG name sub_7ff28f2aaeb; exports: [] */
typedef struct struct_0 {
    char padding_0[90];
    unsigned long long field_5a;
} struct_0;

void sub_7ff28f2aaeb(void)
{
    struct_0 *v1;  // rdi

    goto *((long long *)&(&v1->padding_0)[1]);
}


/* VA 0x7ff28f2addf, RVA 0xaddf, CFG name sub_7ff28f2addf; exports: [] */
typedef struct struct_0 {
    char padding_0[16777295];
    unsigned long long field_100004f;
} struct_0;

void sub_7ff28f2addf(void)
{
    struct_0 *v1;  // rax

    goto *((long long *)&(&v1->padding_0)[1]);
}


/* VA 0x7ff28f26c50, RVA 0x6c50, CFG name sub_7ff28f26c50; exports: [] */
void sub_7ff28f26c50(void)
{
    free();
    return;
}


/* VA 0x7ff28f21731, RVA 0x1731, CFG name sub_7ff28f21731; exports: [] */
void sub_7ff28f21731(void)
{
    unsigned long v1;  // cc_op
    unsigned long v2;  // cc_dep1
    unsigned long v3;  // cc_dep2
    unsigned long v4;  // cc_ndep
    unsigned long v5;  // 4104

    v5 = _ccall(0, v1, v2, v3, v4);
    if ((char)v5)
        [D] Unsupported jumpkind Ijk_SigTRAP at address 8792485009238()
}


/* VA 0x7ff28f28481, RVA 0x8481, CFG name sub_7ff28f28481; exports: [] */
long long sub_7ff28f28481(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, int a8)
{
    if (a8 < 0)
        goto LABEL_0x7ff28f2848b;
    else
        goto LABEL_0x7ff28f28489;
}


/* VA 0x7ff28f23bf6, RVA 0x3bf6, CFG name sub_7ff28f23bf6; exports: [] */
int sub_7ff28f23bf6(void)
{
    unsigned int v1;  // [bp+0x20]

    v1 = 2147942414;
}


/* VA 0x7ff28f2a32c, RVA 0xa32c, CFG name sub_7ff28f2a32c; exports: [] */
int sub_7ff28f2a32c(char *ptr, char a1)
{
    unsigned long v1;  // cc_op
    unsigned long v2;  // cc_dep1
    unsigned long v3;  // cc_dep2
    unsigned long v4;  // cc_ndep
    unsigned long v5;  // 4116
    unsigned int *p;  // rax
    unsigned int v7;  // ebx

    v5 = _ccall(v1, v2, v3, v4);
    *(p) = *(p) - v7 - ((unsigned int)v5 & 1);
    *(ptr) = *(ptr) + a1;
}


/* VA 0x7ff28f23488, RVA 0x3488, CFG name sub_7ff28f23488; exports: [] */
void sub_7ff28f23488(BSTR *a0)
{
    SysFreeString(*(a0));
    return;
}


/* VA 0x7ff28f24d0c, RVA 0x4d0c, CFG name sub_7ff28f24d0c; exports: [] */
long long sub_7ff28f24d0c(void* a0)
{
    goto *((long long *)*((long long *)(long long)a0[56]));
}


/* VA 0x7ff28f2840c, RVA 0x840c, CFG name sub_7ff28f2840c; exports: [] */
long long sub_7ff28f2840c(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, int a8)
{
    if (a8 < 0)
        goto LABEL_0x7ff28f28418;
    else
        goto LABEL_0x7ff28f28416;
}


/* VA 0x7ff28f29026, RVA 0x9026, CFG name sub_7ff28f29026; exports: [] */
void sub_7ff28f29026(unsigned long a0)
{
    sub_7ff28f29030();
    return;
}


/* VA 0x7ff28f29876, RVA 0x9876, CFG name sub_7ff28f29876; exports: [] */
void sub_7ff28f29876(void)
{
    return;
}


/* VA 0x7ff28f2a70f, RVA 0xa70f, CFG name sub_7ff28f2a70f; exports: [] */
void sub_7ff28f2a70f(void)
{
    [D] Unsupported jumpkind Ijk_Privileged at address 8792485046031()
}


/* VA 0x7ff28f23bbc, RVA 0x3bbc, CFG name sub_7ff28f23bbc; exports: [] */
typedef struct struct_0 {
    char padding_0[12];
    unsigned int field_c;
} struct_0;

int sub_7ff28f23bbc(struct_0 *a0)
{
    InterlockedExchangeAdd(&a0->field_c, 4294967295);
    return a0->field_c - 1;
}


/* VA 0x7ff28f24ce4, RVA 0x4ce4, CFG name sub_7ff28f24ce4; exports: [] */
long long sub_7ff28f24ce4(void* a0)
{
    goto *((long long *)(*((long long *)(long long)a0[56]) + 8));
}


/* VA 0x7ff28f24cf8, RVA 0x4cf8, CFG name sub_7ff28f24cf8; exports: [] */
long long sub_7ff28f24cf8(void* a0)
{
    goto *((long long *)(*((long long *)(long long)a0[56]) + 16));
}


/* VA 0x7ff28f2a280, RVA 0xa280, CFG name sub_7ff28f2a280; exports: [] */
extern long long g_7ff28f2ce70;

void sub_7ff28f2a280(void)
{
    sub_7ff28f2896c(&g_7ff28f2ce70);
    return;
}


/* VA 0x7ff28f2a294, RVA 0xa294, CFG name sub_7ff28f2a294; exports: [] */
extern long long g_7ff28f2cec0;

void sub_7ff28f2a294(void)
{
    sub_7ff28f28a94(&g_7ff28f2cec0);
    return;
}


/* VA 0x7ff28f23bd0, RVA 0x3bd0, CFG name sub_7ff28f23bd0; exports: [] */
typedef struct struct_0 {
    char padding_0[12];
    unsigned int field_c;
} struct_0;

int sub_7ff28f23bd0(struct_0 *a0)
{
    InterlockedExchangeAdd(&a0->field_c, 1);
    return a0->field_c + 1;
}


/* VA 0x7ff28f247ec, RVA 0x47ec, CFG name sub_7ff28f247ec; exports: [] */
typedef struct struct_0 {
    char padding_0[8];
    unsigned int field_8;
} struct_0;

int sub_7ff28f247ec(struct_0 *a0)
{
    InterlockedExchangeAdd(&a0->field_8, 1);
    return a0->field_8 + 1;
}


/* VA 0x7ff28f24b84, RVA 0x4b84, CFG name sub_7ff28f24b84; exports: [] */
int sub_7ff28f24b84(void* a0)
{
    InterlockedExchangeAdd(a0 - 56, 1);
    return (int)a0[56] + 1;
}


/* VA 0x7ff28f26b0c, RVA 0x6b0c, CFG name sub_7ff28f26b0c; exports: [] */
extern char g_7ff28f21b88;

void sub_7ff28f26b0c(unsigned long ptr)
{
    *((char **)ptr) = &g_7ff28f21b88;
    return;
}


/* VA 0x7ff28f21dd1, RVA 0x1dd1, CFG name sub_7ff28f21dd1; exports: [] */
void sub_7ff28f21dd1(void)
{
    [D] Unsupported jumpkind Ijk_SigTRAP at address 8792485010897()
}


/* VA 0x7ff28f25818, RVA 0x5818, CFG name sub_7ff28f25818; exports: [] */
typedef struct struct_0 {
    unsigned long long field_0;
    unsigned int field_8;
    unsigned int field_c;
} struct_0;

struct_0 * sub_7ff28f25818(struct_0 *ptr)
{
    ptr->field_0 = 0;
    ptr->field_8 = 0;
    ptr->field_c = 4294967295;
    return ptr;
}


/* VA 0x7ff28f253ed, RVA 0x53ed, CFG name sub_7ff28f253ed; exports: [] */
void sub_7ff28f253ed(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned int a12, unsigned long a13)
{
}


/* VA 0x7ff28f254f4, RVA 0x54f4, CFG name sub_7ff28f254f4; exports: [] */
void sub_7ff28f254f4(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned int a12, unsigned long a13)
{
}


/* VA 0x7ff28f25749, RVA 0x5749, CFG name sub_7ff28f25749; exports: [] */
void sub_7ff28f25749(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12)
{
}


/* VA 0x7ff28f24860, RVA 0x4860, CFG name sub_7ff28f24860; exports: [] */
void sub_7ff28f24860(unsigned long a0, unsigned long a1, unsigned long a2)
{
    sub_7ff28f25dc8();
    return;
}


/* VA 0x7ff28f28ef8, RVA 0x8ef8, CFG name sub_7ff28f28ef8; exports: [] */
void sub_7ff28f28ef8(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
}


/* VA 0x7ff28f28f1a, RVA 0x8f1a, CFG name sub_7ff28f28f1a; exports: [] */
void sub_7ff28f28f1a(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
}


/* VA 0x7ff28f28f45, RVA 0x8f45, CFG name sub_7ff28f28f45; exports: [] */
void sub_7ff28f28f45(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
}


/* VA 0x7ff28f24570, RVA 0x4570, CFG name sub_7ff28f24570; exports: [] */
unsigned int sub_7ff28f24570(unsigned long a0, unsigned int *ptr)
{
    if (ptr)
    {
        *(ptr) = 1;
        return 0;
    }
    return 2147500035;
}


/* VA 0x7ff28f24931, RVA 0x4931, CFG name sub_7ff28f24931; exports: [] */
void sub_7ff28f24931(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned int a14)
{
}


/* VA 0x7ff28f28e61, RVA 0x8e61, CFG name sub_7ff28f28e61; exports: [] */
void sub_7ff28f28e61(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
    unsigned int flag;  // [bp+0x20]

    flag = 0;
}


/* VA 0x7ff28f28e94, RVA 0x8e94, CFG name sub_7ff28f28e94; exports: [] */
void sub_7ff28f28e94(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
    unsigned int flag;  // [bp+0x20]

    flag = 0;
}


/* VA 0x7ff28f28ecb, RVA 0x8ecb, CFG name sub_7ff28f28ecb; exports: [] */
void sub_7ff28f28ecb(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
    unsigned int flag;  // [bp+0x20]

    flag = 0;
}


/* VA 0x7ff28f28f7b, RVA 0x8f7b, CFG name sub_7ff28f28f7b; exports: [] */
void sub_7ff28f28f7b(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
    unsigned int flag;  // [bp+0x20]

    flag = 0;
}


/* VA 0x7ff28f24bc8, RVA 0x4bc8, CFG name sub_7ff28f24bc8; exports: [] */
extern long long g_7ff28f21640;

void sub_7ff28f24bc8(long long a0, long long a1, long long a2)
{
    sub_7ff28f25dc8(a0 - 64, &g_7ff28f21640, a1, a2);
    return;
}


/* VA 0x7ff28f25240, RVA 0x5240, CFG name sub_7ff28f25240; exports: [] */
extern long long g_7ff28f21690;

void sub_7ff28f25240(long long a0, long long a1, long long a2)
{
    sub_7ff28f25dc8(a0 - 64, &g_7ff28f21690, a1, a2);
    return;
}


/* VA 0x7ff28f2525c, RVA 0x525c, CFG name sub_7ff28f2525c; exports: [] */
extern long long g_7ff28f216e0;

void sub_7ff28f2525c(long long a0, long long a1, long long a2)
{
    sub_7ff28f25dc8(a0 - 64, &g_7ff28f216e0, a1, a2);
    return;
}


/* VA 0x7ff28f23be4, RVA 0x3be4, CFG name sub_7ff28f23be4; exports: [] */
typedef struct CRITICAL_SECTION {
    struct CRITICAL_SECTION_DEBUG *DebugInfo;
    int LockCount;
    int RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    UIntPtr SpinCount;
} CRITICAL_SECTION;

typedef struct CRITICAL_SECTION_DEBUG {
    unsigned short Type;
    unsigned short CreatorBackTraceIndex;
    char padding_4[4];
    void* CriticalSection;
    LIST_ENTRY ProcessLocksList;
    unsigned int EntryCount;
    unsigned int ContentionCount;
    unsigned int Flags;
    unsigned short CreatorBackTraceIndexHigh;
    unsigned short Identifier;
} CRITICAL_SECTION_DEBUG;

typedef struct LIST_ENTRY {
    void* Flink;
    void* Blink;
} LIST_ENTRY;

unsigned int sub_7ff28f23be4(CRITICAL_SECTION *a0)
{
    unsigned int flag;  // [bp-0x18]

    InitializeCriticalSection(a0);
    flag = 0;
    return 0;
}


/* VA 0x7ff28f256dc, RVA 0x56dc, CFG name sub_7ff28f256dc; exports: [] */
typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_0 {
    char padding_0[16];
    struct struct_1 *field_10;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

unsigned long long sub_7ff28f256dc(struct_2 **ptr)
{
    struct_0 **v1;  // rcx
    unsigned long long v2;  // rax

    v1 = *(ptr);
    if (v1)
        v2 = *(v1)->field_10(v1);
    return v2;
}


/* VA 0x7ff28f291d4, RVA 0x91d4, CFG name sub_7ff28f291d4; exports: [] */
long long sub_7ff28f291d4(void)
{
    return -(-(0 < sub_7ff28f29148())) - 1;
}


/* VA 0x7ff28f2175b, RVA 0x175b, CFG name sub_7ff28f2175b; exports: [] */
void sub_7ff28f2175b(unsigned long long a0, unsigned long long a1)
{
    unsigned long long v4;  // rcx
    unsigned long long ptr;  // rcx
    unsigned long v6;  // cc_op
    unsigned long v7;  // cc_dep1
    unsigned long v8;  // cc_dep2
    unsigned long v9;  // cc_ndep
    unsigned long v10;  // 4114
    unsigned long idx;  // rbx
    unsigned int v12;  // esi
    unsigned long v13;  // 4101
    unsigned long long v0;  // [bp-0x18]
    unsigned long long v1;  // [bp-0x10]
    unsigned long long v2;  // [bp-0x8]

    v4 = a0 - 1;
    if (a0 - 1)
        goto LABEL_0x7ff28f2179e;
    v2 = v4;
    v1 = a1;
    ptr = v4 - 1;
    v10 = _ccall(4, v6, v7, v8, v9);
    if (v4 - 1 & (char)v10)
        goto LABEL_0x7ff28f2175e;
    v0 = a1;
    *((unsigned int *)(ptr + idx * 4)) = *((int *)(ptr + idx * 4)) & v12;
    [D] syscall()(ptr);
    v13 = _ccall(8, v6, v7, v8, v9);
}


/* VA 0x7ff28f23b18, RVA 0x3b18, CFG name sub_7ff28f23b18; exports: [] */
typedef struct struct_0 {
    char padding_0[24];
    unsigned long long field_18;
} struct_0;

long long sub_7ff28f23b18(unsigned long a0, struct_0 **a1)
{
    goto *(a1)->field_18;
}


/* VA 0x7ff28f258f8, RVA 0x58f8, CFG name sub_7ff28f258f8; exports: [] */
void sub_7ff28f258f8(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17)
{
}


/* VA 0x7ff28f29d2c, RVA 0x9d2c, CFG name sub_7ff28f29d2c; exports: [] */
void sub_7ff28f29d2c(unsigned long a0, unsigned long a1)
{
    sub_7ff28f26c50();
    return;
}


/* VA 0x7ff28f29e31, RVA 0x9e31, CFG name sub_7ff28f29e31; exports: [] */
void sub_7ff28f29e31(unsigned long a0, long long a1)
{
    sub_7ff28f23c2c(a1 + 104);
    return;
}


/* VA 0x7ff28f29e51, RVA 0x9e51, CFG name sub_7ff28f29e51; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    struct struct_1 *field_10;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

unsigned long long sub_7ff28f29e51(unsigned long a0, struct_0 ***a1)
{
    return sub_7ff28f256dc(a1 + 9);
}


/* VA 0x7ff28f29e71, RVA 0x9e71, CFG name sub_7ff28f29e71; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    struct struct_1 *field_10;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

unsigned long long sub_7ff28f29e71(unsigned long a0, struct_0 ***a1)
{
    return sub_7ff28f256dc(a1 + 6);
}


/* VA 0x7ff28f29e91, RVA 0x9e91, CFG name sub_7ff28f29e91; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    struct struct_1 *field_10;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

unsigned long long sub_7ff28f29e91(unsigned long a0, struct_0 ***a1)
{
    return sub_7ff28f256dc(a1 + 7);
}


/* VA 0x7ff28f29f35, RVA 0x9f35, CFG name sub_7ff28f29f35; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    struct struct_1 *field_10;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

unsigned long long sub_7ff28f29f35(unsigned long a0, struct_0 ***a1)
{
    return sub_7ff28f256dc(a1 + 14);
}


/* VA 0x7ff28f29f98, RVA 0x9f98, CFG name sub_7ff28f29f98; exports: [] */
void sub_7ff28f29f98(unsigned long a0, long long a1)
{
    sub_7ff28f2521c(a1 + 112);
    return;
}


/* VA 0x7ff28f29fb8, RVA 0x9fb8, CFG name sub_7ff28f29fb8; exports: [] */
void sub_7ff28f29fb8(unsigned long a0, long long a1)
{
    sub_7ff28f2521c(a1 + 104);
    return;
}


/* VA 0x7ff28f29fd8, RVA 0x9fd8, CFG name sub_7ff28f29fd8; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    struct struct_1 *field_10;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

unsigned long long sub_7ff28f29fd8(unsigned long a0, struct_0 ***a1)
{
    return sub_7ff28f256dc(a1 + 12);
}


/* VA 0x7ff28f29ff6, RVA 0x9ff6, CFG name sub_7ff28f29ff6; exports: [] */
void sub_7ff28f29ff6(unsigned long a0, unsigned long a1)
{
    sub_7ff28f26c50();
    return;
}


/* VA 0x7ff28f2ada1, RVA 0xada1, CFG name sub_7ff28f2ada1; exports: [] */
void sub_7ff28f2ada1(unsigned long long a0, void* ptr)
{
    unsigned long v1;  // cc_op
    unsigned long v2;  // cc_dep1
    unsigned long v11;  // 4173
    unsigned long v12;  // 4175
    unsigned long v13;  // 4177
    unsigned long v14;  // 4180
    char *addr;  // rax
    unsigned long ptr4;  // rdi
    char v17;  // bl
    unsigned long v3;  // cc_dep2
    unsigned long v4;  // cc_ndep
    unsigned long v5;  // 4106
    char *ptr3;  // rax
    char *p;  // rax
    unsigned long v8;  // 4167
    unsigned long v9;  // 4169
    unsigned long v10;  // 4171

    v5 = _ccall(5, v1, v2, v3, v4);
    p = ptr3;
    if (!(a0 - 1 & (char)v5))
    {
        v8 = _ccall(v1, v2, v3, v4);
        v9 = _ccall((unsigned long long)(char)*((char *)ptr), 1, v8, 1);
        v10 = _ccall((unsigned long long)(char)*((char *)ptr), 1, v8, 18446744073709551615);
        *((char *)ptr) = v9;
        v11 = _ccall(0, v10, 0, 0);
        v12 = _ccall((unsigned long long)*(ptr3), 112, v11, 1);
        v13 = _ccall((unsigned long long)*(ptr3), 112, v11, 18446744073709551615);
        *(ptr3) = v12;
        v14 = _ccall(0, v13, 0, 0);
        *((unsigned int *)ptr) = *((int *)ptr) + (unsigned int)ptr + ((unsigned int)v14 & 1);
        addr = (unsigned int)ptr3 + 0x5620900;
        if (((unsigned int)~(ptr3 & 4294967295 ^ 0x5620900) & ((unsigned int)ptr3 ^ (unsigned int)ptr3 + 0x5620900)) >= 0)
            goto LABEL_0x7ff28f2adb1;
        *(addr) = *(addr) ^ *((char *)&addr);
        p = addr;
    }
    *((char *)(ptr4 + ptr * 4)) = *((char *)(ptr4 + ptr * 4)) + v17;
    *(p) = *(p) + v17;
}


/* VA 0x7ff28f2179f, RVA 0x179f, CFG name sub_7ff28f2179f; exports: [] */
typedef struct struct_0 {
    char padding_0[93];
    unsigned int field_5d;
} struct_0;

void sub_7ff28f2179f(char a0)
{
    unsigned long v1;  // cc_op
    unsigned long v2;  // cc_dep1
    unsigned long v3;  // cc_dep2
    unsigned long v4;  // cc_ndep
    unsigned long v5;  // 4101
    struct_0 *ptr;  // rdi
    unsigned long p;  // rdi

    [D] Unsupported jumpkind Ijk_NoDecode at address 8792485009311()
    return;
    v5 = _ccall(14, v1, v2, v3, v4);
    if ((char)v5)
        *((int *)(p + vvar_2{r56|8b} * 8)) = *((int *)(p + vvar_2{r56|8b} * 8)) | vvar_2{r56|8b};
    *((int *)&(&ptr->padding_0)[1]) = *((int *)&(&ptr->padding_0)[1]) >> (a0 & 31) | *((int *)&(&ptr->padding_0)[1]) << 32 - (a0 & 31);
}


/* VA 0x7ff28f29bd4, RVA 0x9bd4, CFG name sub_7ff28f29bd4; exports: [] */
extern unsigned int g_7ff28f2c110;

void sub_7ff28f29bd4(unsigned long a0, unsigned long a1)
{
    g_7ff28f2c110 = 4294967295;
    return;
}


/* VA 0x7ff28f29c69, RVA 0x9c69, CFG name sub_7ff28f29c69; exports: [] */
void sub_7ff28f29c69(unsigned long a0, unsigned long a1)
{
    _unlock(8);
    return;
}


/* VA 0x7ff28f2a31d, RVA 0xa31d, CFG name sub_7ff28f2a31d; exports: [] */
void sub_7ff28f2a31d(void* ptr3, char *a1)
{
    char v1;  // al
    char *p;  // rax
    char *ptr;  // rsi
    unsigned long v4;  // cc_ndep
    unsigned long v5;  // 4101
    char *addr;  // rax

    p = v1 ^ 10;
    *(ptr) = *(ptr) + *((char *)&a1);
    if (ptr3 - 1 & (*((char *)&a1) ^ *(a1)))
    {
        v5 = _ccall(0, 17, (unsigned long long)(*((char *)(void*)&a1) ^ *(a1)), 0, v4);
        if (!((char)v5))
            goto LABEL_0x7ff28f2a337;
        *((char *)&ptr3[115]) = (char)ptr3[115] + *((char *)((void*)&p + 1));
        *(p) = *(p) + *((char *)&p);
        addr = (char *)_INSERT(_INSERT(p, 1, *((char *)&p) / 152), 0, *((char *)&p) % 152);
        *(addr) = *(addr) + *((char *)&addr);
    }
    *(ptr) = *(ptr) >> 1 | *(ptr) * 128;
    *(p + 0x2 * ptr) = *(p + 0x2 * ptr) >> 3 | *(p + 0x2 * ptr) * 32;
}


/* VA 0x7ff28f24550, RVA 0x4550, CFG name sub_7ff28f24550; exports: [] */
void sub_7ff28f24550(unsigned long long a0)
{
    if (a0)
    {
        sub_7ff28f249b8();
        return;
    }
    sub_7ff28f24878();
    return;
}


/* VA 0x7ff28f230e7, RVA 0x30e7, CFG name sub_7ff28f230e7; exports: [] */
char * sub_7ff28f230e7(void)
{
    void* p;  // rax
    char *ptr;  // [bp+0x0]

    *((unsigned int *)p) = *((int *)p) + 1;
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *(ptr) = *(ptr) ^ *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)((void*)&ptr + 1));
    return ptr;
}


/* VA 0x7ff28f2521c, RVA 0x521c, CFG name sub_7ff28f2521c; exports: [] */
typedef struct struct_2 {
    char padding_0[64];
    struct struct_0 *field_40;
} struct_2;

typedef struct struct_0 {
    char padding_0[16];
    struct struct_1 *field_10;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

unsigned long long sub_7ff28f2521c(struct_2 **a0)
{
    unsigned long long v1;  // rax

    if (*(a0))
        v1 = *(a0)->field_40->field_10(&*(a0)->field_40);
    return v1;
}


/* VA 0x7ff28f29d6c, RVA 0x9d6c, CFG name sub_7ff28f29d6c; exports: [] */
void sub_7ff28f29d6c(unsigned long a0, BSTR *a1)
{
    sub_7ff28f23488(a1 + 17);
    return;
}


/* VA 0x7ff28f29ef5, RVA 0x9ef5, CFG name sub_7ff28f29ef5; exports: [] */
typedef struct struct_2 {
    char padding_0[64];
    struct struct_0 *field_40;
} struct_2;

typedef struct struct_0 {
    char padding_0[16];
    struct struct_1 *field_10;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

unsigned long long sub_7ff28f29ef5(unsigned long a0, struct_2 **a1)
{
    return sub_7ff28f2521c(a1 + 16);
}


/* VA 0x7ff28f29f15, RVA 0x9f15, CFG name sub_7ff28f29f15; exports: [] */
typedef struct struct_2 {
    char padding_0[64];
    struct struct_0 *field_40;
} struct_2;

typedef struct struct_0 {
    char padding_0[16];
    struct struct_1 *field_10;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

unsigned long long sub_7ff28f29f15(unsigned long a0, struct_2 **a1)
{
    return sub_7ff28f2521c(a1 + 17);
}


/* VA 0x7ff28f2aa6b, RVA 0xaa6b, CFG name sub_7ff28f2aa6b; exports: [] */
void sub_7ff28f2aa6b(char *p, void* a1, unsigned long a2, unsigned long a3, char a4)
{
    void* addr;  // rax
    unsigned long v2;  // fs
    void* ptr;  // rax
    char v4;  // 4112
    unsigned long v5;  // 4101
    unsigned int v6;  // 4098
    char *ptr3;  // rdi

    *((char *)addr) = *((char *)addr) + *((char *)&a1);
    ptr = (unsigned int)addr | *((int *)((char *)addr + v2));
    *((char *)(a1 + p)) = *((char *)(a1 + p)) + *((char *)((void*)&a1 + 1));
    v4 = *((char *)ptr);
    *((char *)ptr) = v4 + *((char *)&a1);
    if ((char)__CFADD__(v4, *((char *)&a1)))
        *(ptr3) = *(ptr3) + *((char *)&p);
    v5 = _ccall(0, 1, (unsigned long long)v4, (unsigned long long)*((char *)(void*)&a1), 0);
    if (!((char)v5))
        [D] Unsupported jumpkind Ijk_NoDecode at address 8792485046905()
    v6 = *((int *)ptr);
    *((unsigned int *)ptr) = *((int *)ptr) + (unsigned int)ptr;
    *(p) = *(p) + (char)ptr + (char)*((int *)a1) + ((char)(v6 + (unsigned int)ptr <= v6 ? 1 : 0) & 1);
}


/* VA 0x7ff28f29d09, RVA 0x9d09, CFG name sub_7ff28f29d09; exports: [] */
long long sub_7ff28f29d09(unsigned long a0, unsigned long long a1)
{
    unsigned long long v1;  // [bp+0x10]

    v1 = a1;
    return sub_7ff28f26caf;
}


/* VA 0x7ff28f29d4c, RVA 0x9d4c, CFG name sub_7ff28f29d4c; exports: [] */
long long sub_7ff28f29d4c(unsigned long a0, unsigned long long a1)
{
    unsigned long long v1;  // [bp+0x10]

    v1 = a1;
    return sub_7ff28f258f8;
}


/* VA 0x7ff28f29dbc, RVA 0x9dbc, CFG name sub_7ff28f29dbc; exports: [] */
long long sub_7ff28f29dbc(unsigned long a0, unsigned long long a1)
{
    unsigned long long v1;  // [bp+0x10]

    v1 = a1;
    return sub_7ff28f25749;
}


/* VA 0x7ff28f29ddf, RVA 0x9ddf, CFG name sub_7ff28f29ddf; exports: [] */
long long sub_7ff28f29ddf(unsigned long a0, unsigned long long a1)
{
    unsigned long long v1;  // [bp+0x10]

    v1 = a1;
    return sub_7ff28f244a9;
}


/* VA 0x7ff28f29eaf, RVA 0x9eaf, CFG name sub_7ff28f29eaf; exports: [] */
long long sub_7ff28f29eaf(unsigned long a0, unsigned long long a1)
{
    unsigned long long v1;  // [bp+0x10]

    v1 = a1;
    return sub_7ff28f254f4;
}


/* VA 0x7ff28f29ed2, RVA 0x9ed2, CFG name sub_7ff28f29ed2; exports: [] */
long long sub_7ff28f29ed2(unsigned long a0, unsigned long long a1)
{
    unsigned long long v1;  // [bp+0x10]

    v1 = a1;
    return sub_7ff28f253ed;
}


/* VA 0x7ff28f29f53, RVA 0x9f53, CFG name sub_7ff28f29f53; exports: [] */
typedef struct struct_0 {
    char padding_0[64];
    unsigned long long field_40;
} struct_0;

void sub_7ff28f29f53(unsigned long a0, struct_0 *a1)
{
    sub_7ff28f24d8c(a1->field_40 + 24);
    return;
}


/* VA 0x7ff28f29f75, RVA 0x9f75, CFG name sub_7ff28f29f75; exports: [] */
long long sub_7ff28f29f75(unsigned long a0, unsigned long long a1)
{
    unsigned long long v1;  // [bp+0x10]

    v1 = a1;
    return sub_7ff28f24931;
}


/* VA 0x7ff28f2a016, RVA 0xa016, CFG name sub_7ff28f2a016; exports: [] */
typedef struct struct_0 {
    char padding_0[48];
    unsigned long long field_30;
} struct_0;

void sub_7ff28f2a016(unsigned long a0, struct_0 *a1)
{
    sub_7ff28f24d8c(a1->field_30 + 24);
    return;
}


/* VA 0x7ff28f2a036, RVA 0xa036, CFG name sub_7ff28f2a036; exports: [] */
long long sub_7ff28f2a036(unsigned long a0, unsigned long long a1)
{
    unsigned long long v1;  // [bp+0x10]

    v1 = a1;
    return sub_7ff28f24a88;
}


/* VA 0x7ff28f29348, RVA 0x9348, CFG name sub_7ff28f29348; exports: [] */
typedef struct struct_0 {
    char padding_0[56];
    long long field_38;
} struct_0;

unsigned int sub_7ff28f29348(unsigned long a0, long long a1, unsigned long a2, struct_0 *a3)
{
    sub_7ff28f292dc(a1, a3, a3->field_38);
    return 1;
}


/* VA 0x7ff28f235c8, RVA 0x35c8, CFG name sub_7ff28f235c8; exports: [] */
long long sub_7ff28f235c8(unsigned long a0, unsigned long a1, unsigned long a2, unsigned short a3)
{
    char *v0;  // [bp-0x18]
    unsigned short v2;  // [bp+0x20]
    char v3;  // [bp+0x28]

    v2 = a3;
    v0 = &v3;
    return sub_7ff28f23498();
}


/* VA 0x7ff28f23d08, RVA 0x3d08, CFG name sub_7ff28f23d08; exports: [] */
void sub_7ff28f23d08(unsigned long a0, unsigned short a1)
{
    unsigned long long flag;  // [bp-0x18]

    flag = 0;
    sub_7ff28f236b0();
    return;
}


/* VA 0x7ff28f24a88, RVA 0x4a88, CFG name sub_7ff28f24a88; exports: [] */
void sub_7ff28f24a88(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned int a18)
{
}


/* VA 0x7ff28f29030, RVA 0x9030, CFG name sub_7ff28f29030; exports: [] */
extern char g_7ff28f2c100;

void sub_7ff28f29030(unsigned long a0)
{
    if (a0 != *((long long *)&g_7ff28f2c100))
    {
        sub_7ff28f29538();
        return;
    }
    else if (!(unsigned short)(__ROL__(a0, 16)))
    {
        return;
    }
    else
    {
        sub_7ff28f29538();
        return;
    }
}


/* VA 0x7ff28f2a198, RVA 0xa198, CFG name sub_7ff28f2a198; exports: [] */
extern long long g_7ff28f2cec0;

long long sub_7ff28f2a198(void)
{
    sub_7ff28f28ad0(&g_7ff28f2cec0);
    return sub_7ff28f291d4();
}


/* VA 0x7ff28f244a9, RVA 0x44a9, CFG name sub_7ff28f244a9; exports: [] */
void sub_7ff28f244a9(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned int a16)
{
}


/* VA 0x7ff28f255b8, RVA 0x55b8, CFG name sub_7ff28f255b8; exports: [] */
typedef struct struct_2 {
    unsigned long long field_0;
} struct_2;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_0 {
    char padding_0[8];
    struct struct_1 *field_8;
    struct struct_2 *field_10;
} struct_0;

typedef struct struct_3 {
    struct struct_0 *field_0;
} struct_3;

extern struct_3 *g_7ff28f2d5f0;

unsigned int sub_7ff28f255b8(unsigned long a0, unsigned int a1)
{
    if (!a1)
    {
        g_7ff28f2d5f0->field_0->field_10(g_7ff28f2d5f0);
        return 0;
    }
    g_7ff28f2d5f0->field_0->field_8(g_7ff28f2d5f0);
    return 0;
}


/* VA 0x7ff28f26b9c, RVA 0x6b9c, CFG name sub_7ff28f26b9c; exports: [] */
extern char g_7ff28f21b88;

void* sub_7ff28f26b9c(void* ptr, unsigned long a1)
{
    exception::exception(ptr, a1);
    *((char **)ptr) = &g_7ff28f21b88;
    return ptr;
}


/* VA 0x7ff28f278a0, RVA 0x78a0, CFG name sub_7ff28f278a0; exports: [] */
long long sub_7ff28f278a0(unsigned long a0, unsigned long long a1, unsigned long long a2, unsigned long long a3)
{
    unsigned long long v1;  // [bp+0x10]
    unsigned long long v2;  // [bp+0x18]
    unsigned long long v3;  // [bp+0x20]

    v1 = a1;
    v2 = a2;
    v3 = a3;
    return sub_7ff28f276a8();
}


/* VA 0x7ff28f29cbb, RVA 0x9cbb, CFG name sub_7ff28f29cbb; exports: [] */
typedef struct struct_0 {
    unsigned int field_0;
} struct_0;

long long sub_7ff28f29cbb(struct_0 **a0, unsigned long a1)
{
    return *(a0)->field_0 == 3221225477;
}


/* VA 0x7ff28f29ce2, RVA 0x9ce2, CFG name sub_7ff28f29ce2; exports: [] */
typedef struct struct_0 {
    unsigned int field_0;
} struct_0;

long long sub_7ff28f29ce2(struct_0 **a0, unsigned long a1)
{
    return *(a0)->field_0 == 3221225495;
}


/* VA 0x7ff28f23c2c, RVA 0x3c2c, CFG name sub_7ff28f23c2c; exports: [] */
typedef struct struct_0 {
    struct CRITICAL_SECTION *field_0;
    char field_8;
} struct_0;

typedef struct CRITICAL_SECTION {
    struct CRITICAL_SECTION_DEBUG *DebugInfo;
    int LockCount;
    int RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    UIntPtr SpinCount;
} CRITICAL_SECTION;

typedef struct CRITICAL_SECTION_DEBUG {
    unsigned short Type;
    unsigned short CreatorBackTraceIndex;
    char padding_4[4];
    void* CriticalSection;
    LIST_ENTRY ProcessLocksList;
    unsigned int EntryCount;
    unsigned int ContentionCount;
    unsigned int Flags;
    unsigned short CreatorBackTraceIndexHigh;
    unsigned short Identifier;
} CRITICAL_SECTION_DEBUG;

typedef struct LIST_ENTRY {
    void* Flink;
    void* Blink;
} LIST_ENTRY;

void sub_7ff28f23c2c(struct_0 *ptr)
{
    if (ptr->field_8)
    {
        LeaveCriticalSection(ptr->field_0);
        ptr->field_8 = 0;
    }
    return;
}


/* VA 0x7ff28f22121, RVA 0x2121, CFG name sub_7ff28f22121; exports: [] */
void sub_7ff28f22121(char *p, char a1)
{
    void* ptr;  // rax

    *((unsigned int *)ptr) = *((int *)ptr) & (unsigned int)ptr;
    *((char *)ptr) = *((char *)ptr) + a1;
    *((unsigned int *)ptr) = *((int *)ptr) & (unsigned int)ptr;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *(p) = *(p) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + a1;
    return;
}


/* VA 0x7ff28f2434c, RVA 0x434c, CFG name sub_7ff28f2434c; exports: [] */
extern long long g_7ff28f2cc18;

int sub_7ff28f2434c(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned int a4, unsigned long long a5)
{
    unsigned int v0;  // [bp-0x18]
    unsigned long long v1;  // [bp-0x10]

    v1 = a5;
    v0 = a4;
    return sub_7ff28f255e0(&g_7ff28f2cc18);
}


/* VA 0x7ff28f245f4, RVA 0x45f4, CFG name sub_7ff28f245f4; exports: [] */
extern long long g_7ff28f2cc50;

int sub_7ff28f245f4(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned int a4, unsigned long long a5)
{
    unsigned int v0;  // [bp-0x18]
    unsigned long long v1;  // [bp-0x10]

    v1 = a5;
    v0 = a4;
    return sub_7ff28f255e0(&g_7ff28f2cc50);
}


/* VA 0x7ff28f24724, RVA 0x4724, CFG name sub_7ff28f24724; exports: [] */
extern long long g_7ff28f2cc88;

int sub_7ff28f24724(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned int a4, unsigned long long a5)
{
    unsigned int v0;  // [bp-0x18]
    unsigned long long v1;  // [bp-0x10]

    v1 = a5;
    v0 = a4;
    return sub_7ff28f255e0(&g_7ff28f2cc88);
}


/* VA 0x7ff28f271b8, RVA 0x71b8, CFG name sub_7ff28f271b8; exports: [] */
extern char g_7ff28f21bd8;

void* sub_7ff28f271b8(void* ptr, char a1)
{
    *((char **)ptr) = &g_7ff28f21bd8;
    if ((a1 & 1))
        free(ptr);
    return ptr;
}


/* VA 0x7ff28f29d8d, RVA 0x9d8d, CFG name sub_7ff28f29d8d; exports: [] */
typedef struct struct_0 {
    char padding_0[40];
    long long field_28;
    char padding_30[24];
    unsigned int field_48;
} struct_0;

long long sub_7ff28f29d8d(unsigned long a0, struct_0 *ptr)
{
    struct_0 *v1;  // [bp+0x10]

    v1 = ptr;
    ptr->field_48 = sub_7ff28f27914(ptr->field_28);
    return sub_7ff28f28481;
}


/* VA 0x7ff28f29e02, RVA 0x9e02, CFG name sub_7ff28f29e02; exports: [] */
typedef struct struct_0 {
    char padding_0[40];
    long long field_28;
    char padding_30[24];
    unsigned int field_48;
} struct_0;

long long sub_7ff28f29e02(unsigned long a0, struct_0 *ptr)
{
    struct_0 *v1;  // [bp+0x10]

    v1 = ptr;
    ptr->field_48 = sub_7ff28f27914(ptr->field_28);
    return sub_7ff28f2840c;
}


/* VA 0x7ff28f2a351, RVA 0xa351, CFG name sub_7ff28f2a351; exports: [] */
void sub_7ff28f2a351(void* ptr, void* addr, unsigned long a2, unsigned long a3, char a4)
{
    unsigned long idx;  // rbx
    char *p;  // rax
    char v0;  // [bp+0x0]

    *((char *)&addr[114]) = (char)addr[114] + *((char *)((void*)&idx + 1));
    *(p) = *(p) + *((char *)&p);
    *((char *)ptr + 4 * idx) = *((char *)ptr + 4 * idx) + *((char *)((void*)&addr + 1));
    *((char *)(&v0 & 4294967295)) = *((char *)(&v0 & 4294967295)) + (char)(&v0 & 4294967295);
    *((char *)&ptr[889192306]) = (char)ptr[889192306] + *((char *)((void*)&addr + 1));
    *(-0x71350000 + (char *)ptr + 4 * idx) = *(-0x71350000 + (char *)ptr + 4 * idx) + *((char *)&addr);
    *((char *)(p & 4294967295)) = *((char *)(p & 4294967295)) + (char)(p & 4294967295);
}


/* VA 0x7ff28f27678, RVA 0x7678, CFG name sub_7ff28f27678; exports: [] */
unsigned long long sub_7ff28f27678(void)
{
    unsigned int v1;  // eax

    v1 = (unsigned long long)GetLastError();
    if (v1 > 0)
        v1 = v1 & 65535 | 0x80070000;
    if (v1 < 0)
        return v1;
    return 2147500037;
}


/* VA 0x7ff28f24b98, RVA 0x4b98, CFG name sub_7ff28f24b98; exports: [] */
int sub_7ff28f24b98(void* ptr)
{
    unsigned int v1;  // ebx

    InterlockedExchangeAdd(ptr - 56, 4294967295);
    v1 = (int)ptr[56];
    if (!v1 + 4294967295 && ptr != 64)
        (*((long long *)(long long)ptr[64]))(ptr - 64, v1, (long long)ptr[64]);
    return v1 - 1;
}


/* VA 0x7ff28f24c50, RVA 0x4c50, CFG name sub_7ff28f24c50; exports: [] */
typedef struct struct_2 {
    struct struct_0 *field_0;
    unsigned int field_8;
} struct_2;

typedef struct struct_0 {
    char padding_0[24];
    struct struct_1 *field_18;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

int sub_7ff28f24c50(struct_2 *ptr)
{
    unsigned int v1;  // ebx
    struct_0 *v2;  // r8
    unsigned long v3;  // rdx

    InterlockedExchangeAdd(&ptr->field_8, 4294967295);
    v1 = ptr->field_8;
    if (!v1 + 4294967295 && ptr)
    {
        v2 = ptr->field_0;
        v3 = v1;
        ptr->field_0->field_18();
    }
    return v1 - 1;
}


/* VA 0x7ff28f29c39, RVA 0x9c39, CFG name sub_7ff28f29c39; exports: [] */
typedef struct struct_0 {
    char padding_0[32];
    unsigned int field_20;
    char padding_24[60];
    long long field_60;
    long long field_68;
    unsigned int field_70;
    char padding_74[4];
    long long field_78;
} struct_0;

void sub_7ff28f29c39(unsigned long a0, struct_0 *a1)
{
    if (!a1->field_20)
        sub_7ff28f29058(a1->field_60, a1->field_68, a1->field_70, a1->field_78);
    return;
}


/* VA 0x7ff28f21747, RVA 0x1747, CFG name sub_7ff28f21747; exports: [] */
int sub_7ff28f21747(void* addr, char a1)
{
    unsigned long v2;  // cc_op
    unsigned long v3;  // cc_dep1
    char *ptr;  // rax
    unsigned long v4;  // cc_dep2
    unsigned long v5;  // cc_ndep
    unsigned long v6;  // 4113
    unsigned long v7;  // id
    unsigned long v8;  // ac
    unsigned int v9;  // edi
    char *p;  // rax
    char v11;  // dh
    unsigned long long v0;  // [bp-0x8]

    v6 = _ccall(v2, v3, v4, v5);
    v0 = v6 | v7 * 0x200000 & 0x200000 | v8 * 0x40000 & 0x40000;
    p = v9;
    if (!addr - 1)
        return *((unsigned int *)&p);
    *(p) = *(p) + *((char *)&p);
    *(p) = *(p) + *((char *)&p);
    ptr = _INSERT(p, 0, *((char *)&p) + v11) + 134162674 + ((unsigned int)(*((char *)&p) + v11 <= *((char *)&p) ? 1 : 0) & 1);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *((char *)&addr[1]) = (char)addr[1] + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)((void*)&ptr + 1));
}


/* VA 0x7ff28f217cf, RVA 0x17cf, CFG name sub_7ff28f217cf; exports: [] */
typedef struct struct_0 {
    char padding_0[1517502904];
    char field_5a7341b8;
} struct_0;

extern char g_1a71bcef;

long long sub_7ff28f217cf(struct_0 *a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4)
{
    char *ptr;  // rdi
    char *v2;  // rsi
    unsigned long v11;  // 4101
    struct_0 *p;  // rcx
    unsigned long v4;  // rax
    unsigned long v5;  // cc_dep1
    unsigned long v6;  // cc_dep2
    unsigned long idx;  // rdx
    unsigned int v8;  // eax
    unsigned long v9;  // cc_ndep
    unsigned long v10;  // 4104

    *(ptr) = *(v2);
    p = &a0->padding_0[1];
    if (!(&a0->padding_0[1] & (((char)v4 ^ 215) & *((char *)((void*)&a0 + 1)))))
    {
        v5 = *((char *)((void*)&v4 + 1));
        v6 = p[1].padding_0[0];
        idx = _INSERT(a1, 1, 213);
        if (*((char *)((void*)&v4 + 1)) <= p[1].padding_0[0])
            goto LABEL_0x7ff28f217a1;
        v8 = _INSERT(((char)v4 ^ 215) & *((char *)((void*)&a0 + 1)) CONCAT 0, 0, __inbyte(161));
        v10 = _ccall(8, 5, v5, v6, v9);
        if (!((char)v10))
        {
            if (&p->padding_0[1] & (!v8 && 0))
                goto LABEL_0x7ff28f2182c;
            (&g_1a71bcef)[4 * idx] = (&g_1a71bcef)[4 * idx] ^ ((char)v8 | 66);
        }
        v11 = _ccall(8, 5, v5, v6, v9);
        if ((char)v11)
            goto LABEL_0x7ff28f2178e;
        else
            goto LABEL_0x7ff28f2172b;
    }
}


/* VA 0x7ff28f29c88, RVA 0x9c88, CFG name sub_7ff28f29c88; exports: [] */
typedef struct struct_0 {
    char padding_0[32];
    unsigned int field_20;
    unsigned int field_24;
    char padding_28[40];
    long long field_50;
    long long field_58;
    char padding_60[16];
    long long field_70;
} struct_0;

void sub_7ff28f29c88(unsigned long a0, struct_0 *a1)
{
    if (!a1->field_20)
        sub_7ff28f29058(a1->field_50, a1->field_58, a1->field_24, a1->field_70);
    return;
}


/* VA 0x7ff28f29390, RVA 0x9390, CFG name sub_7ff28f29390; exports: [] */
unsigned int sub_7ff28f29390(void* ptr)
{
    void* p;  // rcx
    unsigned int v2;  // eax

    if (*((short *)ptr) != 23117)
        return 0;
    p = (int)ptr[60] + ptr;
    v2 = 0;
    if (*((int *)p) == 17744)
        v2 = (short)p[24] == 523;
    return v2;
}


/* VA 0x7ff28f24d1c, RVA 0x4d1c, CFG name sub_7ff28f24d1c; exports: [] */
void* sub_7ff28f24d1c(void* a0, char a1)
{
    sub_7ff28f24b1c();
    if ((a1 & 1))
        free(a0);
    return a0;
}


/* VA 0x7ff28f24d54, RVA 0x4d54, CFG name sub_7ff28f24d54; exports: [] */
void* sub_7ff28f24d54(void* a0, char a1)
{
    sub_7ff28f24be4();
    if ((a1 & 1))
        free(a0);
    return a0;
}


/* VA 0x7ff28f279d4, RVA 0x79d4, CFG name sub_7ff28f279d4; exports: [] */
extern long long g_7ff28f2d550;

long long sub_7ff28f279d4(unsigned long long *ptr, long long a1)
{
    unsigned long long v1;  // rax

    v1 = sub_7ff28f26c60(a1, &g_7ff28f2d550);
    *(ptr) = v1;
    return ~(-(0 < v1)) & 2147942414;
}


/* VA 0x7ff28f29110, RVA 0x9110, CFG name sub_7ff28f29110; exports: [] */
long long sub_7ff28f29110(unsigned long a0, char a1)
{
    if ((a1 & 1))
        sub_7ff28f26c50();
    return a0;
}


/* VA 0x7ff28f22f69, RVA 0x2f69, CFG name sub_7ff28f22f69; exports: [] */
void sub_7ff28f22f69(unsigned long a0, char a1)
{
    void* ptr;  // rax
    char v2;  // bl
    char v3;  // dh

    *((unsigned int *)ptr) = *((int *)ptr) ^ (unsigned int)ptr;
    *((char *)&ptr[49]) = (char)ptr[49] + v2;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) ^ v3;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) | v3;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    return;
}


/* VA 0x7ff28f260ec, RVA 0x60ec, CFG name sub_7ff28f260ec; exports: [] */
typedef struct struct_2 {
    char padding_0[16];
    struct struct_3 *field_10;
} struct_2;

typedef struct struct_3 {
    struct struct_0 *field_0;
} struct_3;

typedef struct struct_0 {
    char padding_0[24];
    struct struct_1 *field_18;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

unsigned long long sub_7ff28f260ec(struct_2 *a0, unsigned long long a1, unsigned long long a2)
{
    unsigned int v1;  // eax

    if (a1 && a2)
    {
        v1 = a0->field_10->field_0->field_18(a0->field_10);
        if (v1 >= 0)
            v1 = 0;
        return v1;
    }
    return 2147500035;
}


/* VA 0x7ff28f2aa89, RVA 0xaa89, CFG name sub_7ff28f2aa89; exports: [] */
extern unsigned int g_7;
extern char g_7ff2952af28;
extern char g_7ff2b84aac2;

void sub_7ff28f2aa89(unsigned int *addr, unsigned int a1)
{
    char v2;  // al
    char *ptr3;  // rax
    char *ptr4;  // rbx
    unsigned long idx;  // rax
    char *ptr5;  // rsi
    char *p;  // rax
    char *ptr;  // rdi
    char v5;  // 4101
    unsigned long v6;  // cc_ndep
    unsigned long v7;  // 4101
    char v8;  // al
    unsigned long v9;  // cc_ndep
    unsigned long v10;  // 4109
    unsigned long v11;  // rbx
    char *v0;  // [bp-0x8]

    ptr3 = v2 ^ 10;
    v5 = *(ptr);
    *(ptr) = v5 + *((char *)&addr);
    if (!((char)__CFADD__(v5, *((char *)&addr))))
    {
        v7 = _ccall(0, 1, (unsigned long long)v5, (unsigned long long)*((char *)(void*)&addr), v6);
        if ((char)v7)
            goto LABEL_0x7ff28f2aa92;
        else
            goto LABEL_0x7ff28f2aa91;
    }
    else
    {
        v8 = *((char *)&ptr3) | *(ptr3);
        v10 = _ccall(0, 17, (unsigned long long)(*((char *)(void*)&ptr3) | *(ptr3)), 0, v9);
        if (!((char)v10))
        {
            *(addr) = *(addr) ^ (unsigned int)addr;
            *(ptr) = *(ptr) + (char)v11;
            ptr4 = v0;
            *(ptr4) = *(ptr4) + *((char *)&ptr4);
            idx = v8 ^ 90;
            *(ptr5) = *(ptr5) + *((char *)&addr);
            *((unsigned int *)(idx * 2 + 7)) = *((int *)(idx * 2 + 7)) + a1;
            g_7ff2952af28 = g_7ff2952af28;
            p = (char *)_INSERT(idx, 0, (char)idx % 151);
        }
        *(p) = *(p) + *((char *)&p);
        g_7ff2b84aac2 = g_7ff2b84aac2 - *((char *)&ptr4);
        *(p) = *(p) + *((char *)&p);
    }
}


/* VA 0x7ff28f215c8, RVA 0x15c8, CFG name sub_7ff28f215c8; exports: [] */
void sub_7ff28f215c8(char a0, unsigned long a1, unsigned int a2)
{
    void* p;  // rax
    void* ptr;  // rax
    unsigned long long v4;  // rax
    unsigned long v5;  // cc_op
    unsigned long v6;  // cc_dep1
    unsigned long v7;  // cc_dep2
    unsigned long v8;  // cc_ndep
    unsigned long v9;  // 4101
    unsigned long long v0;  // [bp-0x8]

    *((char *)p) = *((char *)p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((unsigned int *)p) = *((int *)p) + a2;
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    ptr = (void*)_INSERT(p, 0, *((char *)&p) * 2);
    *((char *)ptr) = *((char *)ptr) + *((char *)&p) * 2;
    *((char *)ptr) = *((char *)ptr) + *((char *)&p) * 2;
    *((char *)ptr) = *((char *)ptr) + *((char *)&p) * 2;
    *((unsigned int *)ptr) = *((int *)ptr) + a2;
    *((char *)ptr) = *((char *)ptr) + *((char *)&p) * 2;
    *((char *)ptr) = *((char *)ptr) + *((char *)&p) * 2;
    *((char *)ptr) = *((char *)ptr) + *((char *)&p) * 2;
    *((char *)ptr) = *((char *)ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&p) * 2;
    *((char *)ptr) = *((char *)ptr) + *((char *)&p) * 2;
    v4 = [D] syscall()();
    v9 = _ccall(8, v5, v6, v7, v8);
    if (!((char)v9))
        v0 = v4;
}


/* VA 0x7ff28f23d2c, RVA 0x3d2c, CFG name sub_7ff28f23d2c; exports: [] */
long long sub_7ff28f23d2c(unsigned long a0, unsigned short a1, unsigned long a2, unsigned int a3)
{
    char *v0;  // [bp-0x28]
    unsigned long long v1;  // [bp-0x20]
    unsigned long long flag;  // [bp-0x18]
    unsigned int v4;  // [bp+0x20]

    v4 = a3;
    flag = 0;
    v1 = 4;
    v0 = &v4;
    return sub_7ff28f236b0();
}


/* VA 0x7ff28f25f94, RVA 0x5f94, CFG name sub_7ff28f25f94; exports: [] */
unsigned int sub_7ff28f25f94(unsigned long a0, unsigned long long a1, unsigned long long a2, unsigned long long a3, void* a4)
{
    if (a1 && a2 && a3 && a4)
    {
        VariantInit(a4);
        return 2147500033;
    }
    return 2147500035;
}


/* VA 0x7ff28f28a94, RVA 0x8a94, CFG name sub_7ff28f28a94; exports: [] */
typedef struct CRITICAL_SECTION {
    struct CRITICAL_SECTION_DEBUG *DebugInfo;
    int LockCount;
    int RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    UIntPtr SpinCount;
} CRITICAL_SECTION;

typedef struct CRITICAL_SECTION_DEBUG {
    unsigned short Type;
    unsigned short CreatorBackTraceIndex;
    char padding_4[4];
    void* CriticalSection;
    LIST_ENTRY ProcessLocksList;
    unsigned int EntryCount;
    unsigned int ContentionCount;
    unsigned int Flags;
    unsigned short CreatorBackTraceIndexHigh;
    unsigned short Identifier;
} CRITICAL_SECTION_DEBUG;

typedef struct LIST_ENTRY {
    void* Flink;
    void* Blink;
} LIST_ENTRY;

void sub_7ff28f28a94(CRITICAL_SECTION *ptr)
{
    DeleteCriticalSection(ptr + 1);
    if (ptr[2].DebugInfo)
    {
        sub_7ff28f291f2();
        ptr[2].DebugInfo = 0;
    }
    ptr[2].LockCount = 0;
    ptr[2].RecursionCount = 0;
    return;
}


/* VA 0x7ff28f28bd8, RVA 0x8bd8, CFG name sub_7ff28f28bd8; exports: [] */
extern unsigned long long g_7ff28f2d638;
extern unsigned long long g_7ff28f2d640;

unsigned int sub_7ff28f28bd8(void)
{
    unsigned long long *ptr;  // rax

    ptr = malloc(0x100);
    g_7ff28f2d640 = ptr;
    g_7ff28f2d638 = ptr;
    if (ptr)
    {
        *(ptr) = 0;
        return 0;
    }
    return 1;
}


/* VA 0x7ff28f2ad4f, RVA 0xad4f, CFG name sub_7ff28f2ad4f; exports: [] */
extern char g_7ff2a52b9ea;

void sub_7ff28f2ad4f(unsigned long a0, void* ptr3, unsigned long a2, unsigned long a3, unsigned long a4)
{
    char *ptr;  // rax
    void* p;  // rax
    char *addr;  // rdx
    char v7;  // 4125
    unsigned long v8;  // cc_ndep
    unsigned long v9;  // 4101
    char *ptr4;  // rbx
    unsigned int *ptr5;  // rax
    char *ptr6;  // rax
    char *v0;  // [bp-0x10]
    unsigned long v1;  // [bp-0x8]
    unsigned long v3;  // [bp+0xfffa7]

    v1 = v3;
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *((unsigned int *)ptr3) = *((int *)ptr3) + (unsigned int)a0;
    p = (void*)_INSERT(ptr, 0, *((char *)&ptr));
    addr = (char *)_INSERT(ptr3, 1, *((char *)((void*)&ptr3 + 1)) | *((char *)ptr3 + a0));
    v7 = *(addr);
    *(addr) = v7 + (char)a0;
    if (!((char)__CFADD__(v7, a0)))
    {
        v9 = _ccall(0, 1, (unsigned long long)v7, (unsigned long long)(char)a0, v8);
        if (!((char)v9))
            [D] Unsupported jumpkind Ijk_NoDecode at address 8792485047653()
        *((char *)p) = *((char *)p) | *((char *)&p);
    }
    v0 = &v1;
    *((unsigned int *)p) = *((int *)p) | (unsigned int)p;
    *(ptr4) = *(ptr4) + *((char *)&addr);
    g_7ff2a52b9ea = g_7ff2a52b9ea >> 4 | g_7ff2a52b9ea * 16;
    *((char *)p) = *((char *)p) | *((char *)&p);
    ptr5 = (unsigned int *)_INSERT(p, 0, *((char *)&p) + 100);
    *(ptr5) = *(ptr5) | (unsigned int)ptr5;
    ptr6 = (char *)_INSERT(ptr5, 0, *((char *)&p) + 184);
    *(ptr6) = *(ptr6) | *((char *)&p) + 184;
}


/* VA 0x7ff28f24d8c, RVA 0x4d8c, CFG name sub_7ff28f24d8c; exports: [] */
typedef struct CRITICAL_SECTION {
    struct CRITICAL_SECTION_DEBUG *DebugInfo;
    int LockCount;
    int RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    UIntPtr SpinCount;
} CRITICAL_SECTION;

typedef struct CRITICAL_SECTION_DEBUG {
    unsigned short Type;
    unsigned short CreatorBackTraceIndex;
    char padding_4[4];
    void* CriticalSection;
    LIST_ENTRY ProcessLocksList;
    unsigned int EntryCount;
    unsigned int ContentionCount;
    unsigned int Flags;
    unsigned short CreatorBackTraceIndexHigh;
    unsigned short Identifier;
} CRITICAL_SECTION_DEBUG;

typedef struct LIST_ENTRY {
    void* Flink;
    void* Blink;
} LIST_ENTRY;

extern char g_7ff28f21af0;

unsigned long long sub_7ff28f24d8c(CRITICAL_SECTION *ptr)
{
    unsigned long v1;  // rax
    CRITICAL_SECTION *p;  // rcx

    if (ptr[1].SpinCount)
        MpConfigUninitialize();
    v1 = &g_7ff28f21af0;
    p = &ptr->OwningThread;
    ptr->DebugInfo = &g_7ff28f21af0;
    if ((char)p[1].DebugInfo)
    {
        *((char *)&p[1].DebugInfo) = 0;
        v1 = (unsigned long long)DeleteCriticalSection(p);
    }
    return v1;
}


/* VA 0x7ff28f26b5c, RVA 0x6b5c, CFG name sub_7ff28f26b5c; exports: [] */
extern char g_7ff28f21b88;

void* sub_7ff28f26b5c(void* ptr, char a1)
{
    *((char **)ptr) = &g_7ff28f21b88;
    if ((a1 & 1))
        free(ptr);
    return ptr;
}


/* VA 0x7ff28f27aac, RVA 0x7aac, CFG name sub_7ff28f27aac; exports: [] */
typedef struct struct_0 {
    char padding_0[72];
    struct struct_1 *field_48;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

void sub_7ff28f27aac(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4)
{
    struct_0 *v1;  // rax

    v1 = MpUtilsExportFunctions();
    v1->field_48(2, 16, a2, a3, a4);
    return;
}


/* VA 0x7ff28f2aef3, RVA 0xaef3, CFG name sub_7ff28f2aef3; exports: [] */
char sub_7ff28f2aef3(char *ptr, unsigned int *p, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5)
{
    void* addr;  // rsi
    char v3;  // 4133
    unsigned long v12;  // cc_dep1
    unsigned long long v13;  // cc_dep2
    unsigned long v14;  // rax
    unsigned int *ptr3;  // rax
    char *ptr4;  // rax
    unsigned long v6;  // rax
    char *ptr5;  // rdx
    char *ptr6;  // rax
    unsigned long v9;  // cc_ndep
    unsigned long v10;  // 4161
    unsigned long long v11;  // cc_op
    unsigned long v0;  // [bp-0x8]

    v0 = *((long long *)addr);
    v3 = *(0x401000000000000);
    ptr3 = (unsigned int *)_INSERT(0, 0, *(0x401000000000000));
    *(ptr3) = *(ptr3) + (unsigned int)ptr3;
    ptr4 = (char *)_INSERT(ptr3, 0, v3 + 98);
    *(ptr4) = *(ptr4) + v3 + 98;
    *(p) = *(p) + (unsigned int)ptr;
    v6 = _INSERT(ptr4, 0, v3 + 98);
    ptr5 = (char *)_INSERT(p, 1, *((char *)((void*)&p + 1)) | *((char *)addr + v6));
    *(ptr5) = *(ptr5) + *((char *)&ptr);
    ptr6 = (char *)_INSERT(v6, 0, v3 + 98 ^ *((char *)addr));
    v10 = _ccall(0, 17, (unsigned long long)(v3 + 98 ^ *((char *)addr)), 0, v9);
    if (!((char)v10))
        [D] Unsupported jumpkind Ijk_NoDecode at address 8792485048081()
    v11 = 17;
    v12 = *((char *)&ptr6) | *(ptr6);
    v13 = 0;
    v14 = _INSERT(ptr6, 0, *((char *)&ptr6) | *(ptr6));
}


/* VA 0x7ff28f2941c, RVA 0x941c, CFG name sub_7ff28f2941c; exports: [] */
typedef struct struct_0 {
    char padding_0[36];
    unsigned int field_24;
} struct_0;

extern char g_7ff28f20000;

int sub_7ff28f2941c(long long a0)
{
    struct_0 *ptr;  // rax

    ptr = sub_7ff28f29390(&g_7ff28f20000);
    if ((unsigned int)ptr)
    {
        ptr = sub_7ff28f293d0(&g_7ff28f20000, a0 - &g_7ff28f20000, a0 - &g_7ff28f20000);
        if (ptr)
            ptr = ~(ptr->field_24 >> 31) & 1;
    }
    return *((unsigned int *)&ptr);
}


/* VA 0x7ff28f29bf3, RVA 0x9bf3, CFG name sub_7ff28f29bf3; exports: [] */
typedef struct struct_0 {
    char padding_0[32];
    unsigned int field_20;
    char padding_24[4];
    struct struct_1 *field_28;
    struct struct_2 *field_30;
    struct struct_1 *field_38;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_2 {
    unsigned int field_0;
} struct_2;

int sub_7ff28f29bf3(unsigned long long *a0, struct_0 *ptr)
{
    ptr->field_38 = a0;
    ptr->field_28 = a0;
    ptr->field_30 = ptr->field_28->field_0;
    if (ptr->field_30->field_0 == 3765269347)
        return (unsigned long long)terminate();
    ptr->field_20 = 0;
    return ptr->field_20;
}


/* VA 0x7ff28f236b0, RVA 0x36b0, CFG name sub_7ff28f236b0; exports: [] */
unsigned int sub_7ff28f236b0(long long a0, unsigned int a1, long long a2, unsigned short a3)
{
    char v1;  // [bp+0x28]

    sub_7ff28f235ec();
    sub_7ff28f23498(a0, a1, a2, a3, &v1);
    return 0;
}


/* VA 0x7ff28f26cc8, RVA 0x6cc8, CFG name sub_7ff28f26cc8; exports: [] */
unsigned int sub_7ff28f26cc8(long long a0, unsigned short a1, long long a2, unsigned int a3)
{
    char *v0;  // [bp-0x38]
    unsigned long long v1;  // [bp-0x30]
    char *v2;  // [bp-0x28]
    unsigned long long v3;  // [bp-0x20]
    unsigned long long flag;  // [bp-0x18]
    unsigned int v6;  // [bp+0x20]
    char v7;  // [bp+0x28]

    v6 = a3;
    flag = 0;
    v3 = 4;
    v2 = &v7;
    v1 = 4;
    v0 = &v6;
    return sub_7ff28f236b0(a0, 43, a2, a1);
}


/* VA 0x7ff28f2a2a8, RVA 0xa2a8, CFG name sub_7ff28f2a2a8; exports: [] */
extern long long g_7ff28f2cec8;
extern long long g_7ff28f2cf20;
extern unsigned long long g_7ff28f2cf58;
extern unsigned int g_7ff28f2cf60;
extern unsigned int g_7ff28f2cf64;

void sub_7ff28f2a2a8(void)
{
    sub_7ff28f289d8(&g_7ff28f2cf20, g_7ff28f2cec8);
    if (g_7ff28f2cf58)
    {
        sub_7ff28f291f2();
        g_7ff28f2cf58 = 0;
    }
    g_7ff28f2cf60 = 0;
    g_7ff28f2cf64 = 0;
    return;
}


/* VA 0x7ff28f26d10, RVA 0x6d10, CFG name sub_7ff28f26d10; exports: [] */
extern long long g_7ff28f217e8;

unsigned int sub_7ff28f26d10(long long a0, unsigned long a1, unsigned long a2, unsigned long long a3)
{
    unsigned long long v0;  // [bp-0x38]
    unsigned long long v1;  // [bp-0x30]
    char *v2;  // [bp-0x28]
    unsigned long long v3;  // [bp-0x20]
    unsigned long long flag;  // [bp-0x18]
    char v6;  // [bp+0x28]

    flag = 0;
    v3 = 4;
    v2 = &v6;
    v1 = 16;
    v0 = a3;
    return sub_7ff28f236b0(a0, 43, &g_7ff28f217e8, 16);
}


/* VA 0x7ff28f2a234, RVA 0xa234, CFG name sub_7ff28f2a234; exports: [] */
typedef struct struct_0 {
    char padding_0[64];
    struct struct_1 *field_40;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

extern struct_2 *g_7ff28f2ce80;
extern char g_7ff28f2ce88;
extern long long g_7ff28f2d5a0;

long long sub_7ff28f2a234(void)
{
    struct_0 **i;  // rbx
    struct_0 **v2;  // rax

    i = g_7ff28f2ce80;
    for (v2 = *((long long *)&g_7ff28f2ce88); i < v2; i += 1)
    {
        if (*(i))
        {
            *(i)->field_40(0);
            v2 = *((long long *)&g_7ff28f2ce88);
        }
    }
    return sub_7ff28f23c54(&g_7ff28f2d5a0);
}


/* VA 0x7ff28f267a4, RVA 0x67a4, CFG name sub_7ff28f267a4; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    long long field_10;
} struct_0;

unsigned int sub_7ff28f267a4(struct_0 *ptr)
{
    long long v1;  // rbx
    unsigned int v2;  // eax

    if (!ptr->field_10)
        return 2147500035;
    v1 = ptr->field_10;
    ptr->field_10 = 0;
    v2 = MpElevationHandleActivate(v1);
    if (!v1)
        return v2;
    MpHandleClose(v1);
    return v2;
}


/* VA 0x7ff28f278c8, RVA 0x78c8, CFG name sub_7ff28f278c8; exports: [] */
typedef struct struct_0 {
    char padding_0[284];
    unsigned short field_11c;
    char padding_11e[6];
    unsigned int field_124;
} struct_0;

long long sub_7ff28f278c8(void)
{
    struct_0 *v1;  // rax

    v1 = (*((long long *)(MpUtilsExportFunctions() + 88)))();
    return 0 <= (v1->field_124 <= 327682 ? (v1->field_124 < 327682 ? 4294967295 : 0 < v1->field_11c) : 1);
}


/* VA 0x7ff28f293d0, RVA 0x93d0, CFG name sub_7ff28f293d0; exports: [] */
typedef struct struct_0 {
    char padding_0[6];
    unsigned short field_6;
    char padding_8[12];
    unsigned short field_14;
    char padding_16[38];
    unsigned int field_3c;
} struct_0;

unsigned int [10] sub_7ff28f293d0(struct_0 *p, unsigned long a1)
{
    unsigned int v1;  // r9d
    struct_0 *ptr;  // r8
    unsigned int v3;  // r11d
    unsigned int cur[10];  // rcx
    unsigned long v5;  // rdx

    v1 = 0;
    ptr = &p->padding_0[p->field_3c];
    v3 = ptr->field_6;
    cur = &ptr->padding_0[ptr->field_14 + 24];
    if (!v3)
        return NULL;
    while (true)
    {
        v5 = cur[3];
        if (a1 >= v5 && a1 < cur[2] + v5)
            return cur;
        v1 += 1;
        cur += 1;
        if (v1 >= v3)
            return NULL;
    }
}


/* VA 0x7ff28f2a72d, RVA 0xa72d, CFG name sub_7ff28f2a72d; exports: [] */
void sub_7ff28f2a72d(char a0, char *ptr3, unsigned long a2, unsigned long a3, unsigned long a4, char a5)
{
    char v2;  // al
    char *ptr4;  // rax
    char v12;  // 4122
    unsigned long v13;  // 4101
    char *ptr5;  // rdi
    char *ptr6;  // rbx
    void* ptr;  // rcx
    unsigned long v7;  // cc_ndep
    unsigned long v8;  // 4116
    char v9;  // 4097
    char *p;  // rax
    char *addr;  // rdx
    char v0;  // [bp+0x0]

    ptr4 = v2 ^ 6;
    *(ptr5) = *(ptr5) + a0;
    ptr = a0 ^ *(ptr6);
    v8 = _ccall(0, 17, (unsigned long long)(a0 ^ *(ptr6)), 0, v7);
    if (!((char)v8))
        [D] Unsupported jumpkind Ijk_NoDecode at address 8792485046069()
    v9 = *(ptr4);
    *(ptr3) = *(ptr3) | *((char *)((void*)&ptr3 + 1));
    *((unsigned int *)ptr) = *((int *)ptr) - (unsigned int)ptr6 - ((unsigned int)(*((char *)&ptr4) + v9 + 48 <= *((char *)&ptr4) + v9 ? 1 : 0) & 1);
    p = (char *)_INSERT(ptr4, 0, *((char *)&ptr4) + v9 + 48);
    addr = (char *)_INSERT(ptr3, 1, *((char *)((void*)&ptr3 + 1)) | *((char *)(&v0 + ptr)));
    v12 = *(addr);
    *(addr) = v12 + *((char *)&ptr);
    if (!((char)__CFADD__(v12, *((char *)&ptr))))
    {
        v13 = _ccall(0, 1, (unsigned long long)v12, (unsigned long long)*((char *)(void*)&ptr), (*((char *)(void*)&ptr4) + v9 + 48 <= *((char *)(void*)&ptr4) + v9 ? 1 : 0) & 1);
        if ((char)v13)
            [D] Unsupported jumpkind Ijk_SigTRAP at address 8792485046161()
        p = ptr6 & 4294967295;
        *(p) = *(p) + *((char *)&p);
    }
    *(p) = *(p) + *((char *)&p);
    *((char *)ptr) = *((char *)ptr) + *((char *)&p);
}


/* VA 0x7ff28f26188, RVA 0x6188, CFG name sub_7ff28f26188; exports: [] */
typedef struct CRITICAL_SECTION {
    struct CRITICAL_SECTION_DEBUG *DebugInfo;
    int LockCount;
    int RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    UIntPtr SpinCount;
} CRITICAL_SECTION;

typedef struct CRITICAL_SECTION_DEBUG {
    unsigned short Type;
    unsigned short CreatorBackTraceIndex;
    char padding_4[4];
    void* CriticalSection;
    LIST_ENTRY ProcessLocksList;
    unsigned int EntryCount;
    unsigned int ContentionCount;
    unsigned int Flags;
    unsigned short CreatorBackTraceIndexHigh;
    unsigned short Identifier;
} CRITICAL_SECTION_DEBUG;

typedef struct LIST_ENTRY {
    void* Flink;
    void* Blink;
} LIST_ENTRY;

extern char g_7ff28f21af0;

unsigned long long sub_7ff28f26188(CRITICAL_SECTION *ptr)
{
    unsigned long v1;  // rax
    CRITICAL_SECTION *p;  // rcx

    if (ptr[2].DebugInfo)
        MpHandleClose(ptr[2].DebugInfo);
    if (ptr[1].SpinCount)
        MpHandleClose(ptr[1].SpinCount);
    v1 = &g_7ff28f21af0;
    p = &ptr->OwningThread;
    ptr->DebugInfo = &g_7ff28f21af0;
    if ((char)p[1].DebugInfo)
    {
        *((char *)&p[1].DebugInfo) = 0;
        v1 = (unsigned long long)DeleteCriticalSection(p);
    }
    return v1;
}


/* VA 0x7ff28f25d6c, RVA 0x5d6c, CFG name sub_7ff28f25d6c; exports: [] */
typedef struct struct_0 {
    char padding_0[56];
    char field_38;
} struct_0;

extern char g_7ff28f21af0;

struct_0 * sub_7ff28f25d6c(struct_0 *ptr, char a1)
{
    struct_0 *p;  // rcx

    *((char **)&ptr->padding_0[0]) = &g_7ff28f21af0;
    p = &ptr->padding_0[16];
    if (p->padding_0[40])
    {
        p->padding_0[40] = 0;
        DeleteCriticalSection(p);
    }
    if ((a1 & 1))
        free(ptr);
    return ptr;
}


/* VA 0x7ff28f29058, RVA 0x9058, CFG name sub_7ff28f29058; exports: [] */
void sub_7ff28f29058(unsigned long long a0, unsigned long a1, int a2, unsigned long long *a3)
{
    int v2;  // edi
    unsigned long long ptr;  // [bp+0x8]
    int v1;  // [bp+0x18]

    v1 = a2;
    ptr = a0;
    while (true)
    {
        v2 = a2 - 1;
        v1 = v2;
        if (a2 - 1 < 0)
            break;
        a0 -= a1;
        ptr = a0;
        a3(a0);
        a2 = v2;
    }
    return;
}


/* VA 0x7ff28f29880, RVA 0x9880, CFG name sub_7ff28f29880; exports: [] */
void sub_7ff28f29880(void)
{
    char *flag;  // r11
    char *v2;  // rax
    char *v3;  // r10
    char *v4;  // r10
    unsigned long ptr;  // gs
    char *cur;  // r11
    unsigned long v0;  // [bp+0x8]

    flag = NULL;
    v3 = &v0 - v2;
    if (&v0 < v2)
        v4 = flag;
    else
        v4 = v3;
    cur = *((long long *)(16 + ptr));
    if (v4 >= *((long long *)(16 + ptr)))
        return;
    do
    {
        cur += 0x1000;
        *(cur) = 0;
    } while (_INSERT(v4, 0, *((unsigned short *)&v4) & 0xf000) != cur);
    return;
}


/* VA 0x7ff28f2a3d7, RVA 0xa3d7, CFG name sub_7ff28f2a3d7; exports: [] */
typedef struct struct_0 {
    char field_0;
    char padding_1[15];
    unsigned int field_10;
} struct_0;

int sub_7ff28f2a3d7(char *ptr5, char *ptr7, unsigned long a2, unsigned long a3, char a4)
{
    char *addr;  // rdi
    char v3;  // al
    char v12;  // 4120
    unsigned long v13;  // 4167
    unsigned int v14;  // ebp
    void* ptr3;  // rax
    char v16;  // 4108
    unsigned int v17;  // ebx
    struct_0 *ptr6;  // rax
    unsigned long v19;  // 4189
    unsigned long v20;  // 4192
    unsigned long v21;  // 4195
    void* ptr4;  // rax
    unsigned long v22;  // 4206
    void* ptr;  // rax
    char v5;  // 4105
    unsigned long v6;  // cc_ndep
    unsigned long v7;  // 4126
    unsigned long v8;  // 4129
    unsigned long v9;  // 4132
    unsigned long v10;  // 4141
    void* p;  // rax
    char v0;  // [bp+0x0]

    *(addr) = *(addr) + *((char *)&ptr7);
    ptr4 = v3 ^ 13;
    v5 = *(addr);
    *(addr) = v5 + *((char *)&ptr7);
    if (!((char)__CFADD__(v5, *((char *)&ptr7))))
    {
        v7 = _ccall(1, (unsigned long long)v5, (unsigned long long)*((char *)(void*)&ptr7), v6);
        v8 = _ccall((unsigned long long)*(ptr5), 112, v7, 1);
        v9 = _ccall((unsigned long long)*(ptr5), 112, v7, 18446744073709551615);
        *(ptr5) = v8;
        v10 = _ccall(0, v9, 0, 0);
        *((char *)&ptr4[50]) = (char)ptr4[50] + *((char *)((void*)&ptr4 + 1)) + ((char)v10 & 1);
        p = ptr7 & 4294967295;
        ptr7 = ptr4 & 255;
        *((char *)p) = *((char *)p) + *((char *)&p);
        *((unsigned int *)p) = *((int *)p) + (unsigned int)p;
        v12 = *((char *)p);
        *((char *)p) = *((char *)p) + *((char *)&p);
        v13 = _ccall(10, 1, (unsigned long long)v12, (unsigned long long)*((char *)(void*)&p), v10 & 1);
        if (!((char)v13))
            goto LABEL_0x7ff28f2a37e;
        *((char *)p) = *((char *)p) + *((char *)&p);
        ptr4 = vvar_22{r56|4b};
        v14 = (unsigned int)p;
    }
    *((char *)ptr4) = *((char *)ptr4) + *((char *)&ptr4);
    *((char *)ptr4) = *((char *)ptr4) + *((char *)&ptr4);
    ptr3 = v14;
    v16 = *((char *)ptr3);
    *((char *)ptr3) = *((char *)ptr3) + *((char *)&ptr3);
    *((unsigned int *)ptr3) = *((int *)ptr3) + v17 + ((unsigned int)(v16 + *((char *)&ptr3) <= v16 ? 1 : 0) & 1);
    ptr6 = (unsigned int)ptr3 + 0x14621800;
    v19 = _ccall(3, ptr3 & 4294967295, 0x14621800, (v16 + *((char *)(void*)&ptr3) <= v16 ? 1 : 0) & 1);
    v20 = _ccall((unsigned long long)*(ptr7), 112, v19, 1);
    v21 = _ccall((unsigned long long)*(ptr7), 112, v19, 18446744073709551615);
    *(ptr7) = v20;
    v22 = _ccall(0, v21, 0, 0);
    ptr6->field_10 = ptr6->field_10 + (unsigned int)&v0 + ((unsigned int)v22 & 1);
    ptr6->field_0 = ptr6->field_0 ^ *((char *)&ptr6);
    ptr = _INSERT(ptr7, 1, *((char *)((void*)&ptr7 + 1)) + *((char *)&ptr5)) & 4294967295;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((unsigned int *)ptr) = *((int *)ptr) + (unsigned int)ptr;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    if ([D] unsupported_<class 'pyvex.expr.GetI'>())
        *((short *)&ptr[0x6f000000]) = ([D] unsupported_<class 'pyvex.expr.GetI'>() + 0x8000 < 0x10000 ? (short)[D] unsupported_<class 'pyvex.expr.GetI'>() : 0x8000);
    else
        *((unsigned short *)&ptr[0x6f000000]) = ((unsigned int)nan + 0x8000 < 0x10000 ? (unsigned short)nan : 0x8000);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *(ptr5) = *(ptr5) + (char)(ptr6 & 4294967295);
}


/* VA 0x7ff28f23d68, RVA 0x3d68, CFG name sub_7ff28f23d68; exports: [] */
typedef struct struct_0 {
    char padding_0[72];
    unsigned long long field_48;
    char padding_50[16];
    char field_60;
} struct_0;

unsigned int sub_7ff28f23d68(struct_0 *ptr)
{
    unsigned int v1;  // eax
    unsigned int v2;  // eax

    if (ptr->field_48)
    {
        MpConfigUninitialize();
        ptr->field_48 = 0;
    }
    v1 = MpConfigInitialize();
    if (v1 < 0)
        return v1;
    ptr->field_48 = 305419896;
    v2 = (*((long long *)(MpUtilsExportFunctions() + 80)))(16, &ptr->padding_50);
    if (v2 < 0)
        return v2;
    ptr->field_60 = 0;
    return 0;
}


/* VA 0x7ff28f27dac, RVA 0x7dac, CFG name sub_7ff28f27dac; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    long long field_10;
    void* field_18;
} struct_0;

extern char g_7ff28f21bd8;

struct_0 * sub_7ff28f27dac(struct_0 *ptr, char a1)
{
    if (ptr->field_18)
        free(ptr->field_18);
    if (ptr->field_10)
        MpConfigClose(ptr->field_10);
    *((char **)&ptr->padding_0[0]) = &g_7ff28f21bd8;
    if ((a1 & 1))
        free(ptr);
    return ptr;
}


/* VA 0x7ff28f298d4, RVA 0x98d4, CFG name sub_7ff28f298d4; exports: [] */
typedef struct struct_1 {
    char padding_0[48];
    unsigned int field_30;
    char padding_34[28];
    unsigned int field_50;
    char padding_54[84];
    unsigned int field_a8;
    char padding_ac[76];
    struct struct_2 *field_f8;
    struct struct_2 *field_100;
} struct_1;

typedef struct struct_3 {
    unsigned int field_0;
} struct_3;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_0 {
    unsigned int field_0;
} struct_0;

int sub_7ff28f298d4(struct_3 **a0, struct_1 *ptr)
{
    unsigned int v1;  // edx

    ptr->field_100 = a0;
    v1 = *(a0)->field_0;
    ptr->field_a8 = v1;
    ptr->field_f8 = a0;
    ptr->field_50 = v1;
    if (ptr->field_50 == 3765269347)
        ptr->field_30 = _XcptFilter(ptr->field_50, ptr->field_f8);
    else
        ptr->field_30 = 0;
    return ptr->field_30;
}


/* VA 0x7ff28f29934, RVA 0x9934, CFG name sub_7ff28f29934; exports: [] */
typedef struct struct_1 {
    char padding_0[56];
    unsigned int field_38;
    char padding_3c[52];
    unsigned int field_70;
    char padding_74[36];
    unsigned int field_98;
    char padding_9c[52];
    struct struct_2 *field_d0;
    char padding_d8[56];
    struct struct_2 *field_110;
} struct_1;

typedef struct struct_3 {
    unsigned int field_0;
} struct_3;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_0 {
    unsigned int field_0;
} struct_0;

int sub_7ff28f29934(struct_3 **a0, struct_1 *ptr)
{
    unsigned int v1;  // edx

    ptr->field_110 = a0;
    v1 = *(a0)->field_0;
    ptr->field_98 = v1;
    ptr->field_d0 = a0;
    ptr->field_70 = v1;
    if (ptr->field_70 == 3765269347)
        ptr->field_38 = _XcptFilter(ptr->field_70, ptr->field_d0);
    else
        ptr->field_38 = 0;
    return ptr->field_38;
}


/* VA 0x7ff28f29994, RVA 0x9994, CFG name sub_7ff28f29994; exports: [] */
typedef struct struct_1 {
    char padding_0[72];
    unsigned int field_48;
    char padding_4c[20];
    unsigned int field_60;
    char padding_64[104];
    unsigned int field_cc;
    char padding_d0[32];
    struct struct_2 *field_f0;
    char padding_f8[56];
    struct struct_2 *field_130;
} struct_1;

typedef struct struct_3 {
    unsigned int field_0;
} struct_3;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_0 {
    unsigned int field_0;
} struct_0;

int sub_7ff28f29994(struct_3 **a0, struct_1 *ptr)
{
    unsigned int v1;  // edx

    ptr->field_130 = a0;
    v1 = *(a0)->field_0;
    ptr->field_cc = v1;
    ptr->field_f0 = a0;
    ptr->field_60 = v1;
    if (ptr->field_60 == 3765269347)
        ptr->field_48 = _XcptFilter(ptr->field_60, ptr->field_f0);
    else
        ptr->field_48 = 0;
    return ptr->field_48;
}


/* VA 0x7ff28f29a54, RVA 0x9a54, CFG name sub_7ff28f29a54; exports: [] */
typedef struct struct_1 {
    char padding_0[40];
    unsigned int field_28;
    char padding_2c[8];
    unsigned int field_34;
    char padding_38[88];
    struct struct_2 *field_90;
    char padding_98[64];
    unsigned int field_d8;
    char padding_dc[44];
    struct struct_2 *field_108;
} struct_1;

typedef struct struct_3 {
    unsigned int field_0;
} struct_3;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_0 {
    unsigned int field_0;
} struct_0;

int sub_7ff28f29a54(struct_3 **a0, struct_1 *ptr)
{
    unsigned int v1;  // edx

    ptr->field_108 = a0;
    v1 = *(a0)->field_0;
    ptr->field_d8 = v1;
    ptr->field_90 = a0;
    ptr->field_28 = v1;
    if (ptr->field_28 == 3765269347)
        ptr->field_34 = _XcptFilter(ptr->field_28, ptr->field_90);
    else
        ptr->field_34 = 0;
    return ptr->field_34;
}


/* VA 0x7ff28f29ab4, RVA 0x9ab4, CFG name sub_7ff28f29ab4; exports: [] */
typedef struct struct_1 {
    char padding_0[64];
    unsigned int field_40;
    char padding_44[8];
    unsigned int field_4c;
    char padding_50[80];
    struct struct_2 *field_a0;
    char padding_a8[16];
    unsigned int field_b8;
    char padding_bc[92];
    struct struct_2 *field_118;
} struct_1;

typedef struct struct_3 {
    unsigned int field_0;
} struct_3;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_0 {
    unsigned int field_0;
} struct_0;

int sub_7ff28f29ab4(struct_3 **a0, struct_1 *ptr)
{
    unsigned int v1;  // edx

    ptr->field_118 = a0;
    v1 = *(a0)->field_0;
    ptr->field_b8 = v1;
    ptr->field_a0 = a0;
    ptr->field_40 = v1;
    if (ptr->field_40 == 3765269347)
        ptr->field_4c = _XcptFilter(ptr->field_40, ptr->field_a0);
    else
        ptr->field_4c = 0;
    return ptr->field_4c;
}


/* VA 0x7ff28f29b14, RVA 0x9b14, CFG name sub_7ff28f29b14; exports: [] */
typedef struct struct_1 {
    char padding_0[88];
    unsigned int field_58;
    char padding_5c[12];
    unsigned int field_68;
    char padding_6c[68];
    struct struct_2 *field_b0;
    char padding_b8[48];
    unsigned int field_e8;
    char padding_ec[60];
    struct struct_2 *field_128;
} struct_1;

typedef struct struct_3 {
    unsigned int field_0;
} struct_3;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_0 {
    unsigned int field_0;
} struct_0;

int sub_7ff28f29b14(struct_3 **a0, struct_1 *ptr)
{
    unsigned int v1;  // edx

    ptr->field_128 = a0;
    v1 = *(a0)->field_0;
    ptr->field_e8 = v1;
    ptr->field_b0 = a0;
    ptr->field_58 = v1;
    if (ptr->field_58 == 3765269347)
        ptr->field_68 = _XcptFilter(ptr->field_58, ptr->field_b0);
    else
        ptr->field_68 = 0;
    return ptr->field_68;
}


/* VA 0x7ff28f2ae01, RVA 0xae01, CFG name sub_7ff28f2ae01; exports: [] */
typedef struct struct_0 {
    char padding_0[21];
    unsigned int field_15;
} struct_0;

typedef struct struct_1 {
    char padding_0[4194304];
    char field_400000;
} struct_1;

extern char g_7ff3452badb;

void sub_7ff28f2ae01(char a0, struct_0 *ptr4, unsigned long a2, unsigned long a3, char a4)
{
    void* ptr;  // rax
    char v3;  // 4108
    void* ptr3;  // rax
    void* p;  // rax
    struct_1 *ptr5;  // rsi
    char v15;  // ch
    unsigned long v16;  // rsi
    unsigned long v4;  // cc_ndep
    unsigned long v5;  // 4125
    char v6;  // 4106
    char v7;  // cc_dep1
    unsigned long v8;  // 4119
    char addr[31];  // rax
    unsigned long ptr6;  // rdi
    char v11;  // bl
    void* v0;  // [bp-0x8]

    v0 = ptr;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((unsigned int *)ptr) = *((int *)ptr) + (unsigned int)ptr;
    v3 = *((char *)ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    v5 = _ccall(6, 1, (unsigned long long)v3, (unsigned long long)*((char *)(void*)&ptr), v4);
    if ((char)v5)
    {
        *((char *)ptr) = *((char *)ptr) | *((char *)&ptr);
        *((unsigned int *)&(&ptr4->padding_0)[1]) = *((int *)&(&ptr4->padding_0)[1]) - (unsigned int)v16 - 0;
    }
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    v6 = *((char *)ptr);
    *((char *)ptr) = v6 + *((char *)&ptr);
    v7 = v6;
    v8 = _ccall(12, 1, (unsigned long long)v6, (unsigned long long)*((char *)(void*)&ptr), v4);
    if ((char)v8)
    {
        addr = (unsigned int)ptr + (unsigned int)ptr4 + ((unsigned int)(v7 + *((char *)&ptr) <= v7 ? 1 : 0) & 1);
        g_7ff3452badb = g_7ff3452badb + a0;
        *((char *)(ptr6 + ptr4 * 4)) = *((char *)(ptr6 + ptr4 * 4)) ^ v11;
        addr[30] = addr[30] + *((char *)&addr);
        addr[0] = addr[0] + *((char *)&addr);
        addr[0] = addr[0] + *((char *)&addr);
        addr[0] = addr[0] + *((char *)&addr);
        ptr3 = (void*)_INSERT(addr, 0, *((char *)&addr) + addr[0]);
        *((char *)ptr3) = *((char *)ptr3) + *((char *)&addr) + addr[0];
        p = (unsigned int)ptr3 + *((int *)ptr3);
        *((char *)p) = *((char *)p) + *((char *)&p);
        *((unsigned int *)p) = *((int *)p) + (unsigned int)p;
        *((char *)p) = *((char *)p) + *((char *)&p);
        ptr5->field_400000 = v15;
        *((char *)p) = *((char *)p) + *((char *)&p);
        *((char *)p) = *((char *)p) + *((char *)&p);
        *((char *)p) = *((char *)p) + *((char *)&p);
        *((char *)p) = *((char *)p) + *((char *)&p);
        *((char *)p) = *((char *)p) + *((char *)&p);
    }
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
}


/* VA 0x7ff28f2303f, RVA 0x303f, CFG name sub_7ff28f2303f; exports: [] */
void sub_7ff28f2303f(unsigned long a0, char a1)
{
    void* addr;  // rax
    unsigned long v3;  // cc_op
    char v12;  // 4126
    unsigned long v13;  // 4149
    char v14;  // dh
    char v15;  // 4156
    unsigned long v16;  // 4206
    unsigned long v4;  // cc_dep1
    unsigned long v5;  // cc_dep2
    unsigned long v6;  // cc_ndep
    unsigned long long v7;  // 4141
    unsigned long long v8;  // cc_ndep
    char *p;  // rax
    char v10;  // 4121
    char *ptr;  // rax
    char *v0;  // [bp+0x0]

    *((unsigned int *)addr) = *((int *)addr) + 1;
    v7 = _ccall(v3, v4, v5, v6);
    v8 = v7;
    *((char *)addr) = *((char *)addr) + *((char *)&addr);
    *((char *)addr) = *((char *)addr) + *((char *)&addr);
    *((char *)addr) = *((char *)addr) + *((char *)&addr);
    p = v0;
    *(p) = *(p) ^ *((char *)&p);
    *(p) = *(p) + *((char *)&p);
    *(p) = *(p) + *((char *)&p);
    *(p) = *(p) + *((char *)&p);
    *(p) = *(p) + *((char *)&p);
    do
    {
        *(p) = *(p) + *((char *)&p);
        *(p) = *(p) + *((char *)&p);
        *(p) = *(p) + *((char *)&p);
        *(p) = *(p) + *((char *)&p);
        *(p) = *(p) + *((char *)&p);
        *(p) = *(p) + *((char *)&p);
        v10 = *(p);
        ptr = (char *)_INSERT(p, 0, *((char *)&p) + v10);
        v12 = *(ptr);
        *(ptr) = *(ptr) + *((char *)&p) + v10;
        v13 = _ccall(0, 1, (unsigned long long)v12, (unsigned long long)(*((char *)(void*)&p) + v10), v8);
        if ((char)v13)
            goto LABEL_0x7ff28f23096;
        *(ptr) = *(ptr) + *((char *)&ptr);
        *(ptr) = *(ptr) + *((char *)&ptr);
        *(ptr) = *(ptr) + *((char *)&ptr);
        *(ptr) = *(ptr) + *((char *)&ptr);
        *(ptr) = *(ptr) + *((char *)&ptr);
        [D] PutI(904:F64x8)[t72,0] = t73()
        [D] PutI(968:I8x8)[t72,0] = 0x01()
        *(ptr) = *(ptr) + *((char *)&ptr);
        *(ptr) = v14;
        *(ptr) = *(ptr) + *((char *)&ptr);
        *(ptr) = *(ptr) + *((char *)&ptr);
        *(ptr) = *(ptr) + *((char *)&ptr);
        *(ptr) = *(ptr) + *((char *)&ptr);
        *(ptr) = *(ptr) + *((char *)&ptr);
        *(ptr) = *(ptr) + *((char *)&ptr);
        *(ptr) = *(ptr) + *((char *)&ptr);
        *(ptr) = *(ptr) + *((char *)&ptr);
        v15 = *(ptr);
        *(ptr) = *(ptr) + *((char *)&ptr);
        v16 = _ccall(8, 1, (unsigned long long)v15, (unsigned long long)*((char *)(void*)&ptr), v8);
        p = ptr;
    } while ((char)v16);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
}


/* VA 0x7ff28f251c0, RVA 0x51c0, CFG name sub_7ff28f251c0; exports: [] */
unsigned long long sub_7ff28f251c0(long long a0, long long a1)
{
    unsigned long long v3;  // rax
    unsigned long choice;  // [bp+0x18]
    unsigned long flag;  // [bp+0x20]

    flag = 0;
    choice = 0;
    v3 = sub_7ff28f26fa4(a1, &flag, &choice);
    if ((unsigned int)v3 < 0)
    {
        return v3;
    }
    else if (choice != 16)
    {
        return 2147942487;
    }
    else
    {
        memmove(a0, flag);
        return 0;
    }
}


/* VA 0x7ff28f24dcc, RVA 0x4dcc, CFG name sub_7ff28f24dcc; exports: [] */
typedef struct struct_0 {
    char padding_0[56];
    char field_38;
    char padding_39[15];
    unsigned long long field_48;
} struct_0;

extern char g_7ff28f21af0;

struct_0 * sub_7ff28f24dcc(struct_0 *ptr, char a1)
{
    struct_0 *p;  // rcx

    if (ptr->field_48)
        MpConfigUninitialize();
    p = &ptr->padding_0[16];
    *((char **)&ptr->padding_0[0]) = &g_7ff28f21af0;
    if (p->padding_0[40])
    {
        p->padding_0[40] = 0;
        DeleteCriticalSection(p);
    }
    if ((a1 & 1))
        free(ptr);
    return ptr;
}


/* VA 0x7ff28f26560, RVA 0x6560, CFG name sub_7ff28f26560; exports: [] */
typedef struct struct_1 {
    char padding_0[8];
    long long field_8;
} struct_1;

typedef struct struct_0 {
    char padding_0[16];
    long long field_10;
    char padding_18[4];
    char field_1c;
} struct_0;

extern long long g_7ff28f217f8;
extern struct_0 *g_7ff28f2c1d8;

long long sub_7ff28f26560(struct_1 *a0)
{
    if (g_7ff28f2c1d8 != &g_7ff28f2c1d8 && (g_7ff28f2c1d8->field_1c & 8))
        sub_7ff28f26124(g_7ff28f2c1d8->field_10, 16, &g_7ff28f217f8, "Enter to", a0 + 4);
    return MpScanControl(a0->field_8, 0);
}


/* VA 0x7ff28f24800, RVA 0x4800, CFG name sub_7ff28f24800; exports: [] */
typedef struct struct_0 {
    char padding_0[8];
    unsigned int field_8;
    char padding_c[44];
    char field_38;
} struct_0;

extern char g_7ff28f21ac0;

unsigned int sub_7ff28f24800(struct_0 *ptr)
{
    unsigned int v1;  // edi
    struct_0 *p;  // rcx

    InterlockedExchangeAdd(&ptr->field_8, 4294967295);
    v1 = ptr->field_8 - 1;
    if (ptr->field_8 + 4294967295)
    {
        return v1;
    }
    else if (ptr)
    {
        ptr->field_8 = 3221225473;
        *((char **)&ptr->padding_0[0]) = &g_7ff28f21ac0;
        p = &ptr->padding_c[4];
        if (p->padding_c[28] != (char)v1)
        {
            p->padding_c[28] = v1;
            DeleteCriticalSection(p);
        }
        free(ptr);
        return v1;
    }
    else
    {
        return v1;
    }
}


/* VA 0x7ff28f26500, RVA 0x6500, CFG name sub_7ff28f26500; exports: [] */
typedef struct struct_1 {
    char padding_0[8];
    long long field_8;
} struct_1;

typedef struct struct_0 {
    char padding_0[16];
    long long field_10;
    char padding_18[4];
    char field_1c;
} struct_0;

extern long long g_7ff28f217f8;
extern struct_0 *g_7ff28f2c1d8;

long long sub_7ff28f26500(struct_1 *a0)
{
    if (g_7ff28f2c1d8 != &g_7ff28f2c1d8 && (g_7ff28f2c1d8->field_1c & 8))
        sub_7ff28f26124(g_7ff28f2c1d8->field_10, 15, &g_7ff28f217f8, "Enter to", a0 + 4);
    return MpThreatHistoryRequest(a0->field_8, 1);
}


/* VA 0x7ff28f265c0, RVA 0x65c0, CFG name sub_7ff28f265c0; exports: [] */
typedef struct struct_1 {
    char padding_0[8];
    long long field_8;
} struct_1;

typedef struct struct_0 {
    char padding_0[16];
    long long field_10;
    char padding_18[4];
    char field_1c;
} struct_0;

extern long long g_7ff28f217f8;
extern struct_0 *g_7ff28f2c1d8;

long long sub_7ff28f265c0(struct_1 *a0)
{
    if (g_7ff28f2c1d8 != &g_7ff28f2c1d8 && (g_7ff28f2c1d8->field_1c & 8))
        sub_7ff28f26124(g_7ff28f2c1d8->field_10, 17, &g_7ff28f217f8, "Enter to", a0 + 4);
    return MpScanControl(a0->field_8, 1);
}


/* VA 0x7ff28f26620, RVA 0x6620, CFG name sub_7ff28f26620; exports: [] */
typedef struct struct_1 {
    char padding_0[8];
    long long field_8;
} struct_1;

typedef struct struct_0 {
    char padding_0[16];
    long long field_10;
    char padding_18[4];
    char field_1c;
} struct_0;

extern long long g_7ff28f217f8;
extern struct_0 *g_7ff28f2c1d8;

long long sub_7ff28f26620(struct_1 *a0)
{
    if (g_7ff28f2c1d8 != &g_7ff28f2c1d8 && (g_7ff28f2c1d8->field_1c & 8))
        sub_7ff28f26124(g_7ff28f2c1d8->field_10, 18, &g_7ff28f217f8, "Enter to", a0 + 4);
    return MpScanControl(a0->field_8, 2);
}


/* VA 0x7ff28f26124, RVA 0x6124, CFG name sub_7ff28f26124; exports: [] */
extern long long g_7ff28f217f8;

unsigned int sub_7ff28f26124(long long a0, unsigned short a1)
{
    unsigned long long v0;  // [bp-0x38]
    unsigned long long v1;  // [bp-0x30]
    char *v2;  // [bp-0x28]
    unsigned long long v3;  // [bp-0x20]
    unsigned long long flag;  // [bp-0x18]
    char v6;  // [bp+0x28]

    flag = 0;
    v3 = 8;
    do
    {
        if (false)
            break;
    } while (true);
    v2 = &v6;
    v1 = ~(18446744073709551615);
    v0 = "Enter to";
    return sub_7ff28f236b0(a0, 43, &g_7ff28f217f8, a1);
}


/* VA 0x7ff28f25278, RVA 0x5278, CFG name sub_7ff28f25278; exports: [] */
typedef struct struct_0 {
    char padding_0[8];
    unsigned int field_8;
} struct_0;

typedef struct struct_2 {
    unsigned long long field_0;
} struct_2;

typedef struct struct_1 {
    char padding_0[16];
    struct struct_2 *field_10;
} struct_1;

typedef struct struct_3 {
    struct struct_1 *field_0;
} struct_3;

extern char g_7ff28f218f8;
extern char g_7ff28f21908;
extern struct_3 *g_7ff28f2d5f0;

struct_0 * sub_7ff28f25278(struct_0 *ptr, char a1)
{
    ptr->field_8 = 3221225473;
    *((char **)&ptr->padding_0[0]) = &g_7ff28f218f8;
    *((char **)&ptr[5].padding_0[4]) = &g_7ff28f21908;
    g_7ff28f2d5f0->field_0->field_10(g_7ff28f2d5f0);
    sub_7ff28f26188(ptr);
    if ((a1 & 1))
        free(ptr);
    return ptr;
}


/* VA 0x7ff28f252dc, RVA 0x52dc, CFG name sub_7ff28f252dc; exports: [] */
typedef struct struct_0 {
    char padding_0[8];
    unsigned int field_8;
} struct_0;

typedef struct struct_2 {
    unsigned long long field_0;
} struct_2;

typedef struct struct_1 {
    char padding_0[16];
    struct struct_2 *field_10;
} struct_1;

typedef struct struct_3 {
    struct struct_1 *field_0;
} struct_3;

extern char g_7ff28f219a0;
extern char g_7ff28f219b8;
extern struct_3 *g_7ff28f2d5f0;

struct_0 * sub_7ff28f252dc(struct_0 *ptr, char a1)
{
    ptr->field_8 = 3221225473;
    *((char **)&ptr->padding_0[0]) = &g_7ff28f219a0;
    *((char **)&ptr[5].padding_0[4]) = &g_7ff28f219b8;
    g_7ff28f2d5f0->field_0->field_10(g_7ff28f2d5f0);
    sub_7ff28f25ef0(ptr);
    if ((a1 & 1))
        free(ptr);
    return ptr;
}


/* VA 0x7ff28f26c60, RVA 0x6c60, CFG name sub_7ff28f26c60; exports: [] */
extern unsigned long long g_7ff28f2d590;
extern char g_7ff28f2d598;

unsigned long long sub_7ff28f26c60(unsigned long a0)
{
    unsigned long long ptr;  // rax
    unsigned long long *v3;  // rax
    unsigned long long *v4;  // rax
    unsigned long long v0;  // [bp-0x18]

    v0 = 18446744073709551614;
    while (true)
    {
        ptr = malloc(a0);
        if (ptr)
            return ptr;
        if (!g_7ff28f2d598)
            break;
        v3 = (*((long long *)(MpUtilsExportFunctions() + 168)))();
        v4 = v3(g_7ff28f2d590);
        if (!v4)
            break;
        v4();
    }
    return 0;
}


/* VA 0x7ff28f299f4, RVA 0x99f4, CFG name sub_7ff28f299f4; exports: [] */
typedef struct struct_1 {
    char padding_0[36];
    unsigned int field_24;
    char padding_28[88];
    unsigned int field_80;
    char padding_84[8];
    unsigned int field_8c;
    char padding_90[80];
    struct struct_2 *field_e0;
    char padding_e8[56];
    struct struct_2 *field_120;
} struct_1;

typedef struct struct_3 {
    unsigned int field_0;
} struct_3;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_0 {
    unsigned int field_0;
} struct_0;

int sub_7ff28f299f4(struct_3 **a0, struct_1 *ptr)
{
    unsigned int v1;  // edx

    ptr->field_120 = a0;
    v1 = *(a0)->field_0;
    ptr->field_8c = v1;
    ptr->field_e0 = a0;
    ptr->field_80 = v1;
    if (ptr->field_80 == 3765269347)
        ptr->field_24 = _XcptFilter(ptr->field_80, ptr->field_e0);
    else
        ptr->field_24 = 0;
    return ptr->field_24;
}


/* VA 0x7ff28f29b74, RVA 0x9b74, CFG name sub_7ff28f29b74; exports: [] */
typedef struct struct_1 {
    char padding_0[120];
    unsigned int field_78;
    char padding_7c[12];
    unsigned int field_88;
    char padding_8c[52];
    struct struct_2 *field_c0;
    unsigned int field_c8;
    char padding_cc[108];
    struct struct_2 *field_138;
} struct_1;

typedef struct struct_3 {
    unsigned int field_0;
} struct_3;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_0 {
    unsigned int field_0;
} struct_0;

int sub_7ff28f29b74(struct_3 **a0, struct_1 *ptr)
{
    unsigned int v1;  // edx

    ptr->field_138 = a0;
    v1 = *(a0)->field_0;
    ptr->field_c8 = v1;
    ptr->field_c0 = a0;
    ptr->field_78 = v1;
    if (ptr->field_78 == 3765269347)
        ptr->field_88 = _XcptFilter(ptr->field_78, ptr->field_c0);
    else
        ptr->field_88 = 0;
    return ptr->field_88;
}


/* VA 0x7ff28f24c80, RVA 0x4c80, CFG name sub_7ff28f24c80; exports: [] */
typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_0 {
    char padding_0[8];
    struct struct_1 *field_8;
} struct_0;

typedef struct struct_3 {
    char padding_0[8];
    struct struct_4 *field_8;
} struct_3;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_4 {
    unsigned long long field_0;
} struct_4;

extern long long g_7ff28f21640;

unsigned int sub_7ff28f24c80(struct_3 **a0, unsigned int *a1, struct_2 **ptr)
{
    unsigned int v1;  // ebx

    v1 = 0;
    if (!ptr)
        return 2147500035;
    *(ptr) = NULL;
    if (!*(a1) && !a1[1] && a1[2] == 192 && a1[3] == 0x46000000)
    {
        *(ptr) = a0;
        *(a0)->field_8();
    }
    else
    {
        v1 = sub_7ff28f25dc8(a0 + 3, &g_7ff28f21640, a1, ptr);
    }
    return v1;
}


/* VA 0x7ff28f25554, RVA 0x5554, CFG name sub_7ff28f25554; exports: [] */
typedef struct struct_0 {
    char padding_0[64];
    struct struct_1 *field_40;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

unsigned int sub_7ff28f25554(struct_0 *a0, unsigned long long a1, unsigned int *a2, unsigned long long *ptr)
{
    if (!ptr)
        return 2147500035;
    *(ptr) = 0;
    if (!a1 || !*(a2) && !a2[1] && a2[2] == 192 && a2[3] == 0x46000000)
        return a0->field_40(a1, a2, ptr);
    return 2147746064;
    return a0->field_40(a1, a2, ptr);
}


/* VA 0x7ff28f290ac, RVA 0x90ac, CFG name sub_7ff28f290ac; exports: [] */
char * sub_7ff28f290ac(unsigned long a0, unsigned long long a1, unsigned int a2, unsigned long long *a3)
{
    char *v6;  // rax
    unsigned long v7;  // rdi
    unsigned long long v8;  // rbx
    unsigned long v9;  // rdi
    unsigned int flag;  // [bp-0x38]
    char v1;  // [bp+0x0]
    unsigned long long ptr;  // [bp+0x8]
    unsigned long long v3;  // [bp+0x10]
    unsigned int v4;  // [bp+0x18]
    unsigned long long *v5;  // [bp+0x20]

    v6 = &v1;
    v5 = a3;
    v4 = a2;
    v3 = a1;
    v7 = a2;
    flag = 0;
    v8 = a1 * v7 + a0;
    ptr = v8;
    while (true)
    {
        v9 = (unsigned int)v7 - 1;
        v4 = v9;
        if ((unsigned int)((v7 & 4294967295) - 1) < 0)
            break;
        v8 -= a1;
        ptr = v8;
        v6 = a3(v8);
        v7 = v9;
    }
    return v6;
}


/* VA 0x7ff28f26fa4, RVA 0x6fa4, CFG name sub_7ff28f26fa4; exports: [] */
typedef struct struct_0 {
    unsigned short field_0;
    char padding_2[6];
    struct SAFEARRAY *field_8;
} struct_0;

typedef struct SAFEARRAY {
    unsigned short cDims;
    enum ADVANCED_FEATURE_FLAGS fFeatures;
    unsigned int cbElements;
    unsigned int cLocks;
    char padding_c[4];
    void* pvData;
    struct SAFEARRAYBOUND *rgsabound;
} SAFEARRAY;

typedef struct SAFEARRAYBOUND {
    unsigned int cElements;
    int lLbound;
} SAFEARRAYBOUND;

unsigned int sub_7ff28f26fa4(struct_0 *addr, unsigned long long *ptr, unsigned long long *p)
{
    SAFEARRAY *index;  // rbx

    *(ptr) = 0;
    *(p) = 0;
    if (addr->field_0 == 8209)
    {
        index = addr->field_8;
        if (SafeArrayGetDim(index) == 1)
        {
            *(ptr) = index->pvData;
            *(p) = (int)index->rgsabound;
            return 0;
        }
    }
    return 2147942487;
}


/* VA 0x7ff28f257b0, RVA 0x57b0, CFG name sub_7ff28f257b0; exports: [] */
typedef struct struct_2 {
    char padding_0[24];
    struct struct_3 *field_18;
    char padding_20[8];
    void* field_28;
} struct_2;

typedef struct struct_0 {
    char padding_0[16];
    struct struct_1 *field_10;
} struct_0;

typedef struct struct_3 {
    struct struct_0 *field_0;
} struct_3;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

long long sub_7ff28f257b0(struct_2 *ptr)
{
    unsigned long long v2;  // rbx
    unsigned long long v3;  // rdi
    struct_0 **v4;  // rcx
    unsigned long v5;  // rax
    void* v6;  // rcx
    unsigned long v7;  // rbx
    unsigned long v8;  // rax
    unsigned long long v0;  // [bp-0x8]
    unsigned long long v1;  // [bp+0x8]

    if (!ptr)
        return v8;
    v1 = v2;
    v0 = v3;
    v4 = ptr->field_18;
    if (v4)
        v5 = *(v4)->field_10(v4);
    v6 = ptr->field_28;
    ptr->field_18 = NULL;
    if (v6)
    {
        v7 = v6 - 8;
        sub_7ff28f290ac(v6, 16, *((int *)v7), sub_7ff28f23488);
        v5 = (unsigned long long)free(v7);
    }
    ptr->field_28 = NULL;
    return v5;
}


/* VA 0x7ff28f242e4, RVA 0x42e4, CFG name sub_7ff28f242e4; exports: [] */
typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_3 {
    char padding_0[8];
    struct struct_4 *field_8;
} struct_3;

typedef struct struct_0 {
    char padding_0[8];
    struct struct_1 *field_8;
} struct_0;

typedef struct struct_4 {
    unsigned long long field_0;
} struct_4;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_5 {
    struct struct_3 *field_0;
} struct_5;

extern long long g_7ff28f2cc18;
extern struct_5 *g_7ff28f2cc30;

unsigned int sub_7ff28f242e4(unsigned long a0, unsigned int a1, unsigned int a2, struct_2 **ptr)
{
    struct_3 **v1;  // rcx
    unsigned int v2;  // eax

    if (a1)
    {
        return 2147614731;
    }
    else if (!ptr)
    {
        return 2147500035;
    }
    else
    {
        v1 = g_7ff28f2cc30;
        v2 = 0;
        if (!g_7ff28f2cc30)
        {
            v2 = sub_7ff28f25a4c(&g_7ff28f2cc18, a2);
            v1 = g_7ff28f2cc30;
        }
        *(ptr) = v1;
        if (!g_7ff28f2cc30)
            return v2;
        g_7ff28f2cc30->field_0->field_8(g_7ff28f2cc30);
        return 0;
    }
}


/* VA 0x7ff28f2458c, RVA 0x458c, CFG name sub_7ff28f2458c; exports: [] */
typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_3 {
    char padding_0[8];
    struct struct_4 *field_8;
} struct_3;

typedef struct struct_0 {
    char padding_0[8];
    struct struct_1 *field_8;
} struct_0;

typedef struct struct_4 {
    unsigned long long field_0;
} struct_4;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_5 {
    struct struct_3 *field_0;
} struct_5;

extern long long g_7ff28f2cc50;
extern struct_5 *g_7ff28f2cc68;

unsigned int sub_7ff28f2458c(unsigned long a0, unsigned int a1, unsigned int a2, struct_2 **ptr)
{
    struct_3 **v1;  // rcx
    unsigned int v2;  // eax

    if (a1)
    {
        return 2147614731;
    }
    else if (!ptr)
    {
        return 2147500035;
    }
    else
    {
        v1 = g_7ff28f2cc68;
        v2 = 0;
        if (!g_7ff28f2cc68)
        {
            v2 = sub_7ff28f25a4c(&g_7ff28f2cc50, a2);
            v1 = g_7ff28f2cc68;
        }
        *(ptr) = v1;
        if (!g_7ff28f2cc68)
            return v2;
        g_7ff28f2cc68->field_0->field_8(g_7ff28f2cc68);
        return 0;
    }
}


/* VA 0x7ff28f246bc, RVA 0x46bc, CFG name sub_7ff28f246bc; exports: [] */
typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_3 {
    char padding_0[8];
    struct struct_4 *field_8;
} struct_3;

typedef struct struct_0 {
    char padding_0[8];
    struct struct_1 *field_8;
} struct_0;

typedef struct struct_4 {
    unsigned long long field_0;
} struct_4;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_5 {
    struct struct_3 *field_0;
} struct_5;

extern long long g_7ff28f2cc88;
extern struct_5 *g_7ff28f2cca0;

unsigned int sub_7ff28f246bc(unsigned long a0, unsigned int a1, unsigned int a2, struct_2 **ptr)
{
    struct_3 **v1;  // rcx
    unsigned int v2;  // eax

    if (a1)
    {
        return 2147614731;
    }
    else if (!ptr)
    {
        return 2147500035;
    }
    else
    {
        v1 = g_7ff28f2cca0;
        v2 = 0;
        if (!g_7ff28f2cca0)
        {
            v2 = sub_7ff28f25a4c(&g_7ff28f2cc88, a2);
            v1 = g_7ff28f2cca0;
        }
        *(ptr) = v1;
        if (!g_7ff28f2cca0)
            return v2;
        g_7ff28f2cca0->field_0->field_8(g_7ff28f2cca0);
        return 0;
    }
}


/* VA 0x7ff28f28428, RVA 0x8428, CFG name sub_7ff28f28428; exports: [] */
typedef struct struct_0 {
    char padding_0[8];
    unsigned int field_8;
    char padding_c[4];
    char field_10;
    char padding_11[47];
    unsigned long long field_40;
} struct_0;

typedef struct struct_1 {
    char padding_0[8];
    unsigned int field_8;
    char padding_c[4];
    char field_10;
    char padding_11[47];
    unsigned long long field_40;
} struct_1;

extern char g_7ff28f21c18;

unsigned int sub_7ff28f28428(struct_1 **p)
{
    struct_0 *ptr;  // rax
    unsigned long long v0;  // [bp-0x18]

    v0 = 18446744073709551614;
    ptr = sub_7ff28f26c60(72);
    if (ptr)
    {
        ptr->field_8 = 0;
        *((char **)&ptr->padding_0[0]) = &g_7ff28f21c18;
        ptr->field_10 = 0;
        ptr->field_40 = 0;
    }
    else
    {
        ptr = NULL;
    }
    if (!ptr)
        return 2147942414;
    InterlockedIncrement(&ptr->field_8);
    *(p) = ptr;
    return 0;
}


/* VA 0x7ff28f24b1c, RVA 0x4b1c, CFG name sub_7ff28f24b1c; exports: [] */
typedef struct CRITICAL_SECTION {
    struct CRITICAL_SECTION_DEBUG *DebugInfo;
    int LockCount;
    int RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    UIntPtr SpinCount;
} CRITICAL_SECTION;

typedef struct CRITICAL_SECTION_DEBUG {
    unsigned short Type;
    unsigned short CreatorBackTraceIndex;
    char padding_4[4];
    void* CriticalSection;
    LIST_ENTRY ProcessLocksList;
    unsigned int EntryCount;
    unsigned int ContentionCount;
    unsigned int Flags;
    unsigned short CreatorBackTraceIndexHigh;
    unsigned short Identifier;
} CRITICAL_SECTION_DEBUG;

typedef struct LIST_ENTRY {
    void* Flink;
    void* Blink;
} LIST_ENTRY;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_0 {
    char padding_0[16];
    struct struct_1 *field_10;
} struct_0;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

extern char g_7ff28f21850;
extern char g_7ff28f21868;
extern char g_7ff28f21af0;
extern struct_2 *g_7ff28f2d5f0;

unsigned long long sub_7ff28f24b1c(CRITICAL_SECTION *ptr)
{
    unsigned long v1;  // rax
    CRITICAL_SECTION *p;  // rcx

    ptr->LockCount = 3221225473;
    ptr->DebugInfo = &g_7ff28f21850;
    ptr[1].LockSemaphore = &g_7ff28f21868;
    g_7ff28f2d5f0->field_0->field_10(g_7ff28f2d5f0);
    if (ptr[1].SpinCount)
        MpConfigUninitialize();
    v1 = &g_7ff28f21af0;
    p = &ptr->OwningThread;
    ptr->DebugInfo = &g_7ff28f21af0;
    if ((char)p[1].DebugInfo)
    {
        *((char *)&p[1].DebugInfo) = 0;
        v1 = (unsigned long long)DeleteCriticalSection(p);
    }
    return v1;
}


/* VA 0x7ff28f292dc, RVA 0x92dc, CFG name sub_7ff28f292dc; exports: [] */
typedef struct struct_1 {
    char padding_0[8];
    unsigned long long field_8;
    struct struct_0 *field_10;
} struct_1;

typedef struct struct_2 {
    char padding_0[3];
    char field_3;
} struct_2;

typedef struct struct_0 {
    char padding_0[8];
    unsigned int field_8;
} struct_0;

void sub_7ff28f292dc(unsigned long long a0, struct_1 *p, void* ptr)
{
    unsigned long long v1;  // r9
    struct_2 *addr;  // rcx

    v1 = a0;
    if ((*((char *)ptr) & 4))
        a0 = (int)ptr[4] + a0 & -((int)ptr[8]);
    addr = p->field_10->field_8 + p->field_8;
    if ((addr->field_3 & 15))
        v1 += addr->field_3 & 0xfffffff0;
    sub_7ff28f29030(v1 ^ *((long long *)((*((int *)ptr) & 0xfffffff8) + a0)));
    return;
}


/* VA 0x7ff28f2a379, RVA 0xa379, CFG name sub_7ff28f2a379; exports: [] */
typedef struct struct_0 {
    unsigned int field_0;
    unsigned int field_4;
} struct_0;

char sub_7ff28f2a379(void* ptr5, char a1, unsigned long long *ptr6, unsigned long a3, unsigned long a4)
{
    char v7;  // al
    char v8;  // dh
    char v17;  // 4107
    unsigned long v18;  // 4130
    struct_0 *ptr7;  // rdi
    unsigned int *v20;  // rsi
    struct_0 *ptr8;  // rdi
    char *ptr3;  // rax
    void* p;  // rax
    char *ptr4;  // rdx
    char *ptr9;  // rbx
    char *addr;  // rax
    char v13;  // 4156
    unsigned long v14;  // 4205
    char v15;  // 4098
    void* ptr;  // rax
    unsigned long v0;  // [bp+0x0]
    unsigned long v1;  // [bp+0x8]
    unsigned long v2;  // [bp+0x10]
    unsigned long v3;  // [bp+0x18]
    unsigned long v4;  // [bp+0x20]
    char v5;  // [bp+0xfff96]
    char v6;  // [bp+0xfff97]

    p = (void*)_INSERT(v7, 1, v7 + v8);
    ptr4 = (unsigned int)p >> 31;
    *((char *)p) = *((char *)p) + *((char *)&p);
    *(ptr9) = *(ptr9) + *((char *)&ptr5);
    *((unsigned long *)p) = v0;
    *(ptr4) = *(ptr4) + *((char *)&ptr9);
    *((unsigned long *)p) = v1;
    *(ptr4 + 0x4 * ptr9) = *(ptr4 + 0x4 * ptr9) + *((char *)&ptr4);
    *(ptr4) = *(ptr4) + *((char *)&ptr9);
    *((unsigned long *)p) = v2;
    *((char *)ptr5) = *((char *)ptr5) + *((char *)((void*)&ptr9 + 1));
    *((unsigned long *)p) = v3;
    v6 += *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    addr = (char *)_INSERT(p, 1, 154);
    *(addr) = *(addr) + *((char *)&p);
    *(ptr6) = v4;
    *((char *)&ptr5[113]) = (char)ptr5[113] - 102;
    v13 = *(addr);
    *(addr) = *(addr) + *((char *)&p);
    v14 = _ccall(10, 1, (unsigned long long)v13, (unsigned long long)*((char *)(void*)&p), 0);
    if (!((char)v14))
        goto LABEL_0x7ff28f2a339;
    v15 = *(addr);
    *(addr) = *(addr) + *((char *)&addr);
    ptr = (void*)_INSERT(addr, 0, *((char *)&addr) - 101 + ((char)(v15 + *((char *)&addr) <= v15 ? 1 : 0) & 1));
    v17 = *((char *)ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&addr) - 101 + ((char)(v15 + *((char *)&addr) <= v15 ? 1 : 0) & 1);
    v18 = _ccall(10, 1, (unsigned long long)v17, (unsigned long long)(*((char *)(void*)&addr) - 101 + ((char)(v15 + *((char *)(void*)&addr) <= v15 ? 1 : 0) & 1)), (v15 + *((char *)(void*)&addr) <= v15 ? 1 : 0) & 1);
    if ((char)v18)
    {
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        ptr7->field_0 = *(v20);
        ptr8 = &ptr7->field_4;
        *((unsigned long *)ptr) = a4;
        *(-0x648c0000 + (char *)ptr8 + 0x4 * ptr5) = *(-0x648c0000 + (char *)ptr8 + 0x4 * ptr5) + *((char *)((void*)&ptr9 + 1));
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((long long *)ptr) = *((long long *)0x1200008f);
        ptr3 = (char *)_INSERT(ptr, 1, *((char *)((void*)&ptr + 1)) + *((char *)&ptr4) + *((char *)&ptr));
        *(ptr3) = *(ptr3) + *((char *)&ptr);
        *(ptr3) = *(ptr3) + *((char *)&ptr);
        *(ptr3) = *(ptr3) + *((char *)&ptr);
        ptr8->field_0 = ptr8->field_0 | _INSERT(ptr4, 0, *((char *)&ptr4) + *((char *)&ptr));
    }
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    v5 += *((char *)&ptr);
}


/* VA 0x7ff28f2896c, RVA 0x896c, CFG name sub_7ff28f2896c; exports: [] */
typedef struct CRITICAL_SECTION {
    struct CRITICAL_SECTION_DEBUG *DebugInfo;
    int LockCount;
    int RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    UIntPtr SpinCount;
} CRITICAL_SECTION;

typedef struct struct_8 {
    char padding_0[32];
    struct struct_9 *field_20;
} struct_8;

typedef struct struct_4 {
    char padding_0[32];
    struct struct_5 *field_20;
} struct_4;

typedef struct struct_0 {
    char padding_0[16];
    struct struct_1 *field_10;
} struct_0;

typedef struct struct_2 {
    char padding_0[16];
    struct struct_3 *field_10;
} struct_2;

typedef struct CRITICAL_SECTION_DEBUG {
    unsigned short Type;
    unsigned short CreatorBackTraceIndex;
    char padding_4[4];
    void* CriticalSection;
    LIST_ENTRY ProcessLocksList;
    unsigned int EntryCount;
    unsigned int ContentionCount;
    unsigned int Flags;
    unsigned short CreatorBackTraceIndexHigh;
    unsigned short Identifier;
} CRITICAL_SECTION_DEBUG;

typedef struct struct_9 {
    struct struct_6 *field_0;
} struct_9;

typedef struct struct_5 {
    struct struct_2 *field_0;
} struct_5;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_3 {
    unsigned long long field_0;
} struct_3;

typedef struct LIST_ENTRY {
    void* Flink;
    void* Blink;
} LIST_ENTRY;

typedef struct struct_6 {
    char padding_0[16];
    struct struct_7 *field_10;
} struct_6;

typedef struct struct_7 {
    unsigned long long field_0;
} struct_7;

void sub_7ff28f2896c(CRITICAL_SECTION *ptr)
{
    struct_8 **cur;  // rdi
    struct_4 *p;  // rsi
    struct_0 **v3;  // rcx

    if (!(int)ptr->DebugInfo)
        return;
    cur = ptr->OwningThread;
    if (cur < ptr->LockSemaphore)
    {
        do
        {
            p = *(cur);
            if (p)
            {
                v3 = p->field_20;
                if (v3)
                    *(v3)->field_10(v3);
                p->field_20 = NULL;
            }
        } while ((cur += 8, cur < ptr->LockSemaphore));
    }
    DeleteCriticalSection(&ptr->SpinCount);
    *((unsigned int *)&ptr->DebugInfo) = 0;
    return;
}


/* VA 0x7ff28f24be4, RVA 0x4be4, CFG name sub_7ff28f24be4; exports: [] */
typedef struct CRITICAL_SECTION {
    struct CRITICAL_SECTION_DEBUG *DebugInfo;
    int LockCount;
    int RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    UIntPtr SpinCount;
} CRITICAL_SECTION;

typedef struct CRITICAL_SECTION_DEBUG {
    unsigned short Type;
    unsigned short CreatorBackTraceIndex;
    char padding_4[4];
    void* CriticalSection;
    LIST_ENTRY ProcessLocksList;
    unsigned int EntryCount;
    unsigned int ContentionCount;
    unsigned int Flags;
    unsigned short CreatorBackTraceIndexHigh;
    unsigned short Identifier;
} CRITICAL_SECTION_DEBUG;

typedef struct LIST_ENTRY {
    void* Flink;
    void* Blink;
} LIST_ENTRY;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_0 {
    char padding_0[16];
    struct struct_1 *field_10;
} struct_0;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

extern char g_7ff28f218d0;
extern char g_7ff28f21af0;
extern struct_2 *g_7ff28f2d5f0;

unsigned long long sub_7ff28f24be4(CRITICAL_SECTION *ptr)
{
    unsigned long v2;  // rax
    CRITICAL_SECTION *p;  // rcx
    unsigned long long v0;  // [bp-0x18]
    CRITICAL_SECTION *v1;  // [bp+0x8]

    v1 = ptr;
    v0 = 18446744073709551614;
    ptr->DebugInfo = &g_7ff28f218d0;
    ptr->LockCount = 3221225473;
    g_7ff28f2d5f0->field_0->field_10(g_7ff28f2d5f0);
    if (ptr[2].OwningThread)
        MpConfigUninitialize();
    v2 = &g_7ff28f21af0;
    ptr->LockSemaphore = &g_7ff28f21af0;
    p = ptr + 1;
    if ((char)p[1].DebugInfo)
    {
        *((char *)&p[1].DebugInfo) = 0;
        v2 = (unsigned long long)DeleteCriticalSection(p);
    }
    return v2;
}


/* VA 0x7ff28f2920c, RVA 0x920c, CFG name sub_7ff28f2920c; exports: [] */
char * sub_7ff28f2920c(unsigned long long a0, unsigned long long a1, int a2, unsigned long long *a3)
{
    char *v5;  // rax
    int v6;  // ebx
    unsigned int flag;  // [bp-0x28]
    int i;  // [bp-0x24], Other Possible Types: unsigned int
    char v2;  // [bp+0x0]
    unsigned long long ptr;  // [bp+0x8]
    unsigned long long v4;  // [bp+0x10]

    v5 = &v2;
    v4 = a1;
    ptr = a0;
    v6 = 0;
    flag = 0;
    for (i = 0; v6 < a2; i = v6 + 1)
    {
        v5 = a3(a0);
        ptr = a0 + a1;
    }
    return v5;
}


/* VA 0x7ff28f237a8, RVA 0x37a8, CFG name sub_7ff28f237a8; exports: [] */
typedef struct struct_0 {
    char padding_0[64];
    struct struct_1 *field_40;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

extern struct_2 *g_7ff28f2ce80;
extern char g_7ff28f2ce88;

long long sub_7ff28f237a8(unsigned long a0, char a1)
{
    struct_0 **i;  // rdi
    struct_0 **v2;  // rcx

    i = g_7ff28f2ce80;
    for (v2 = *((long long *)&g_7ff28f2ce88); i < v2; i += 1)
    {
        if (*(i))
        {
            *(i)->field_40(0);
            v2 = *((long long *)&g_7ff28f2ce88);
        }
    }
    sub_7ff28f23c54(a0);
    if ((a1 & 1))
        free(a0);
    return a0;
}


/* VA 0x7ff28f283a8, RVA 0x83a8, CFG name sub_7ff28f283a8; exports: [] */
typedef struct struct_0 {
    char padding_0[8];
    unsigned int field_8;
    char padding_c[4];
    unsigned long long field_10;
    unsigned long long field_18;
} struct_0;

typedef struct struct_1 {
    char padding_0[8];
    unsigned int field_8;
    char padding_c[4];
    unsigned long long field_10;
    unsigned long long field_18;
} struct_1;

extern char g_7ff28f21c08;

unsigned int sub_7ff28f283a8(struct_1 **p)
{
    struct_0 *ptr;  // rax
    unsigned long long v0;  // [bp-0x18]
    unsigned long long flag;  // [bp+0x10]
    unsigned long long choice;  // [bp+0x18]

    v0 = 18446744073709551614;
    ptr = sub_7ff28f26c60(32);
    if (ptr)
    {
        ptr->field_8 = 0;
        *((char **)&ptr->padding_0[0]) = &g_7ff28f21c08;
        flag = 0;
        ptr->field_10 = 0;
        choice = 0;
        ptr->field_18 = 0;
    }
    else
    {
        ptr = NULL;
    }
    if (!ptr)
        return 2147942414;
    InterlockedIncrement(&ptr->field_8);
    *(p) = ptr;
    return 0;
}


/* VA 0x7ff28f2a1c0, RVA 0xa1c0, CFG name sub_7ff28f2a1c0; exports: [] */
extern unsigned int g_7ff28f2cf20;
extern char g_7ff28f2cf28;
extern unsigned long long g_7ff28f2cf50;
extern unsigned long long g_7ff28f2cf58;
extern unsigned int g_7ff28f2cf60;
extern unsigned int g_7ff28f2cf64;
extern char g_7ff28f2d5ea;

long long sub_7ff28f2a1c0(void)
{
    memset(&g_7ff28f2cf28, 0, 40);
    g_7ff28f2cf58 = 0;
    g_7ff28f2cf60 = 0;
    g_7ff28f2cf64 = 0;
    g_7ff28f2cf50 = 0;
    g_7ff28f2cf20 = 72;
    if (sub_7ff28f23be4(&g_7ff28f2cf28) < 0)
    {
        g_7ff28f2cf20 = 0;
        g_7ff28f2d5ea = 1;
    }
    return sub_7ff28f291d4();
}


/* VA 0x7ff28f267f0, RVA 0x67f0, CFG name sub_7ff28f267f0; exports: [] */
typedef struct struct_1 {
    char padding_0[8];
    long long field_8;
} struct_1;

typedef struct struct_0 {
    char padding_0[16];
    long long field_10;
    char padding_18[4];
    char field_1c;
} struct_0;

extern struct_0 *g_7ff28f2c1d8;

long long sub_7ff28f267f0(struct_1 *a0, unsigned int a1)
{
    struct_1 *v0;  // [bp-0x18]

    if (g_7ff28f2c1d8 != &g_7ff28f2c1d8 && (g_7ff28f2c1d8->field_1c & 8))
    {
        v0 = a0 + 4;
        sub_7ff28f26124(g_7ff28f2c1d8->field_10, 20);
    }
    return (!a1 ? MpUpdateControl(a0->field_8, 0) : 2147942487);
}


/* VA 0x7ff28f23b38, RVA 0x3b38, CFG name sub_7ff28f23b38; exports: [] */
typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_5 {
    char padding_0[64];
    struct struct_6 *field_40;
} struct_5;

typedef struct struct_3 {
    char padding_0[8];
    struct struct_4 *field_8;
} struct_3;

typedef struct struct_0 {
    char padding_0[8];
    struct struct_1 *field_8;
} struct_0;

typedef struct struct_6 {
    struct struct_3 *field_0;
} struct_6;

typedef struct struct_4 {
    unsigned long long field_0;
} struct_4;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct Guid {
    unsigned int Data1;
    unsigned short Data2;
    unsigned short Data3;
    char Data4[8];
} Guid;

extern Guid g_7ff28f21500;
extern Guid g_7ff28f215d0;

int sub_7ff28f23b38(struct_5 *a0, struct_2 **ptr)
{
    struct_5 *v1;  // rbx
    int v2;  // edi

    if (!ptr)
        return -2147467261;
    v1 = &a0->field_40;
    v2 = 0;
    if (*((long long *)&v1->padding_0[0]) || (v2 = (int)(long long)CoCreateInstance(&g_7ff28f21500.Data1, 0, CLSCTX_INPROC_SERVER, &g_7ff28f215d0.Data1, v1), v2 >= 0))
    {
        *(ptr) = *((long long *)&v1->padding_0[0]);
        (*((long long *)(*((long long *)*((long long *)&v1->padding_0[0])) + 8)))(*((long long *)&v1->padding_0[0]), *((long long *)*((long long *)&v1->padding_0[0])));
    }
    return v2;
}


/* VA 0x7ff28f2202f, RVA 0x202f, CFG name sub_7ff28f2202f; exports: [] */
extern char g_40000c2;

void sub_7ff28f2202f(char *a0)
{
    void* ptr;  // rax
    unsigned long v2;  // cc_op
    char v11;  // 4122
    unsigned long v13;  // 4148
    unsigned long v3;  // cc_dep1
    unsigned long v4;  // cc_dep2
    unsigned long v5;  // cc_ndep
    unsigned long long v6;  // 4107
    unsigned long long v7;  // cc_ndep
    char *p;  // rcx
    char v9;  // 4178
    unsigned long v10;  // 4230

    *((unsigned int *)ptr) = *((int *)ptr) + 1;
    v6 = _ccall(v2, v3, v4, v5);
    v7 = v6;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    while (true)
    {
        p = a0;
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) & *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *(p) = *(p) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)&ptr[32]) = (char)ptr[32] + *((char *)((void*)&ptr + 1));
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        v9 = *((char *)ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        v10 = _ccall(0, 1, (unsigned long long)v9, (unsigned long long)*((char *)(void*)&ptr), v7);
        if ((char)v10)
        {
            *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
            *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
            *((char *)&ptr[32]) = (char)ptr[32] + *((char *)&p);
            *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
            *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
            *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
            *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
            *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
            *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
            *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
            g_40000c2 = g_40000c2 + 194;
            g_40000c2 = g_40000c2 + 194;
            g_40000c2 = g_40000c2 + 194;
        }
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        v11 = *((char *)ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        v13 = _ccall(5, 1, (unsigned long long)v11, (unsigned long long)*((char *)(void*)&ptr), v7);
        a0 = p + 1;
        if (!(p + 1 & (char)v13))
        {
            *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
            *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
            *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
            *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
            *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        }
    }
}


/* VA 0x7ff28f22d37, RVA 0x2d37, CFG name sub_7ff28f22d37; exports: [] */
extern char g_1800002d;

void sub_7ff28f22d37(unsigned long long a0, unsigned long a1, unsigned long a2, unsigned long a3, char a4)
{
    void* ptr;  // rax
    unsigned long v3;  // cc_op
    char v12;  // 4149
    unsigned long v13;  // 4191
    unsigned long v4;  // cc_dep1
    unsigned long v5;  // cc_dep2
    unsigned long v6;  // cc_ndep
    unsigned long v7;  // 4115
    char v8;  // 4109
    unsigned long v9;  // 4135
    char *ptr3;  // rax
    char *addr;  // rax
    void* p;  // [bp+0x0]

    *((unsigned int *)ptr) = *((int *)ptr) + 1;
    v7 = _ccall(v3, v4, v5, v6);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    v8 = *((char *)ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    v9 = _ccall(5, 1, (unsigned long long)v8, (unsigned long long)*((char *)(void*)&ptr), v7);
    if (!(a0 - 1 & (char)v9))
    {
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        ptr3 = (unsigned int)ptr + *((int *)ptr);
        *(ptr3) = *(ptr3) + *((char *)&ptr3);
        *(ptr3) = *(ptr3) + *((char *)&ptr3);
    }
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)(ptr * 2)) = *((char *)(ptr * 2)) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    addr = ptr & 4294967295;
    *(addr) = *(addr) + *((char *)&addr);
    *(addr) = *(addr) + *((char *)&addr);
    v12 = *(addr);
    *(addr) = *(addr) + *((char *)&addr);
    v13 = _ccall(0, 1, (unsigned long long)v12, (unsigned long long)*((char *)(void*)&addr), v7);
    if ((char)v13)
    {
        *(addr) = *(addr) + *((char *)&addr);
        *(addr) = *(addr) + *((char *)&addr);
    }
    *(addr) = *(addr) + *((char *)&addr);
    g_1800002d = g_1800002d + 45;
    *((unsigned int *)p) = *((int *)p) ^ (unsigned int)p;
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
}


/* VA 0x7ff28f28240, RVA 0x8240, CFG name sub_7ff28f28240; exports: [] */
typedef struct struct_3 {
    char padding_0[16];
    char field_10;
    char padding_11[47];
    struct struct_1 *field_40;
} struct_3;

typedef struct struct_1 {
    struct struct_2 *field_0;
    unsigned int field_8;
} struct_1;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

extern char g_7ff28f21bd8;
extern char g_7ff28f21c18;

struct_3 * sub_7ff28f28240(struct_3 *ptr, char a1)
{
    struct_1 *v1;  // rcx
    unsigned long long flag;  // rdx

    *((char **)&ptr->padding_0[0]) = &g_7ff28f21c18;
    v1 = ptr->field_40;
    if (v1)
    {
        InterlockedExchangeAdd(&v1->field_8, 4294967295);
        if (v1->field_8 - 1 <= 0 && v1)
        {
            flag = 1;
            v1->field_0->field_0();
        }
    }
    if (ptr->field_10)
        DeleteCriticalSection(&ptr->padding_11[7]);
    *((char **)&ptr->padding_0[0]) = &g_7ff28f21bd8;
    if ((a1 & 1))
        free(ptr);
    return ptr;
}


/* VA 0x7ff28f271e8, RVA 0x71e8, CFG name sub_7ff28f271e8; exports: [] */
unsigned int sub_7ff28f271e8(long long a0, unsigned short a1, long long a2, unsigned short *a3)
{
    unsigned long long v4;  // rcx
    unsigned short *v5;  // rdi
    unsigned short *v6;  // rax
    unsigned short *v7;  // r9
    unsigned short *v0;  // [bp-0x28]
    unsigned long long v1;  // [bp-0x20]
    unsigned long long flag;  // [bp-0x18]

    if (!a3)
    {
        v4 = 10;
    }
    else if (!*(a3))
    {
        v4 = 14;
    }
    else
    {
        v5 = a3;
        do
        {
            if (false)
                break;
        } while (*(v5));
        v4 = ~(18446744073709551615) * 2;
    }
    if (a3)
    {
        v6 = L"<NULL>";
        if (!*(a3))
            v7 = v6;
        else
            v7 = a3;
    }
    else
    {
        v7 = L"NULL";
    }
    flag = 0;
    v1 = v4;
    v0 = v7;
    return sub_7ff28f236b0(a0, 43, a2, a1);
}


/* VA 0x7ff28f2a118, RVA 0xa118, CFG name sub_7ff28f2a118; exports: [] */
extern char g_7ff28f20000;
extern char g_7ff28f2b010;
extern char g_7ff28f2b018;
extern unsigned int g_7ff28f2ce70;
extern unsigned long long g_7ff28f2ce78;
extern unsigned long long g_7ff28f2ce80;
extern unsigned long long g_7ff28f2ce88;
extern char g_7ff28f2ce90;
extern char g_7ff28f2d5ea;

long long sub_7ff28f2a118(void)
{
    memset(&g_7ff28f2ce90, 0, 40);
    g_7ff28f2ce70 = 0;
    g_7ff28f2ce78 = &g_7ff28f20000;
    g_7ff28f2ce80 = &g_7ff28f2b010;
    g_7ff28f2ce88 = &g_7ff28f2b018;
    if (sub_7ff28f23be4(&g_7ff28f2ce90) < 0)
        g_7ff28f2d5ea = 1;
    else
        g_7ff28f2ce70 = 72;
    return sub_7ff28f291d4();
}


/* VA 0x7ff28f26bc4, RVA 0x6bc4, CFG name sub_7ff28f26bc4; exports: [] */
extern char g_7ff28f21b88;
extern long long g_7ff28f2afe8;
extern char g_7ff28f2c1b8;
extern unsigned long long g_7ff28f2d590;
extern char g_7ff28f2d598;

unsigned long long sub_7ff28f26bc4(unsigned long a0)
{
    unsigned long v2;  // rcx
    unsigned long long ptr;  // rax
    unsigned long long *v4;  // rax
    unsigned long long *v5;  // rax
    char v0;  // [bp-0x28], Other Possible Types: unsigned long

    v2 = a0;
    while (true)
    {
        ptr = malloc(v2);
        if (ptr)
            return ptr;
        if (!g_7ff28f2d598)
            break;
        v4 = (*((long long *)(MpUtilsExportFunctions() + 168)))();
        v5 = v4(g_7ff28f2d590);
        if (!v5)
            break;
        v5();
        v2 = a0;
    }
    exception::exception(&v0, &g_7ff28f2c1b8, 1);
    v0 = &g_7ff28f21b88;
    _CxxThrowException(&v0, &g_7ff28f2afe8);
    [D] Unsupported jumpkind Ijk_SigTRAP at address 8792485030983()
}


/* VA 0x7ff28f29148, RVA 0x9148, CFG name sub_7ff28f29148; exports: [] */
extern unsigned long long g_7ff28f2d638;
extern unsigned long long g_7ff28f2d640;

long long sub_7ff28f29148(long long a0)
{
    long long v3;  // rbx
    unsigned long long v1;  // [bp+0x10]
    unsigned long v2;  // [bp+0x18]

    v1 = g_7ff28f2d640;
    if (g_7ff28f2d640 != 18446744073709551615)
    {
        _lock(8);
        v1 = g_7ff28f2d640;
        v2 = g_7ff28f2d638;
        v3 = __dllonexit(a0, &v1, &v2);
        g_7ff28f2d640 = v1;
        g_7ff28f2d638 = v2;
        _unlock(8, v2);
        return v3;
    }
    return (unsigned long long)_onexit();
}


/* VA 0x7ff28f24024, RVA 0x4024, CFG name sub_7ff28f24024; exports: [] */
typedef struct struct_0 {
    char padding_0[32];
    char field_20;
} struct_0;

typedef struct struct_1 {
    char padding_0[16];
    unsigned int field_10;
    char padding_14[8];
    char field_1c;
} struct_1;

extern struct_1 *g_7ff28f2c1d8;

unsigned int sub_7ff28f24024(struct_0 *a0, unsigned short *ptr)
{
    unsigned int v2;  // eax
    unsigned int flag;  // [bp+0x10]

    if (!ptr)
        return 2147500035;
    *(ptr) = 0;
    if (!a0->field_20)
    {
        if (g_7ff28f2c1d8 == &g_7ff28f2c1d8 || !(g_7ff28f2c1d8->field_1c & 1))
            return 2147942405;
        sub_7ff28f23d08(*((long long *)&g_7ff28f2c1d8->field_10), 12);
        return 2147942405;
    }
    else
    {
        flag = 0;
        v2 = (*((long long *)(MpUtilsExportFunctions() + 96)))(0, &flag);
        if (v2 < 0)
            return v2;
        *(ptr) = -(0 < flag);
        return 0;
    }
}


/* VA 0x7ff28f22377, RVA 0x2377, CFG name sub_7ff28f22377; exports: [] */
extern char g_7ff4d1a23c6;

int sub_7ff28f22377(char *ptr4, char a1, unsigned long a2, unsigned long a3, char a4)
{
    void* ptr3;  // rax
    char p[36];  // rax
    char v4;  // dh
    char *addr;  // rax
    char v6;  // 4221
    char *ptr;  // rax
    unsigned long v0;  // [bp+0x0]

    *((unsigned int *)ptr3) = *((int *)ptr3) + 1;
    *((char *)ptr3) = *((char *)ptr3) + *((char *)&ptr3);
    *((char *)ptr3) = *((char *)ptr3) + *((char *)&ptr3);
    *((char *)ptr3) = *((char *)ptr3) + *((char *)&ptr3);
    p = (unsigned int)ptr3 & *((int *)ptr3);
    p[0] = p[0] + *((char *)&p);
    p[0] = p[0] + *((char *)&p);
    p[0] = p[0] + *((char *)&p);
    p[0] = p[0] + *((char *)&p);
    p[0] = p[0] + *((char *)&p);
    p[0] = p[0] + *((char *)&p);
    p[0] = p[0] + *((char *)&p);
    p[0] = p[0] + *((char *)&p);
    *(ptr4) = *(ptr4) + *((char *)&p);
    p[0] = p[0] + *((char *)&p);
    *(ptr4) = *(ptr4) + *((char *)&ptr4);
    p[0] = p[0] + *((char *)&p);
    p[35] = p[35] + v4;
    p[0] = p[0] + *((char *)&p);
    p[0] = p[0] + *((char *)&p);
    p[0] = p[0] + *((char *)&p);
    p[0] = p[0] + *((char *)&p);
    p[0] = p[0] + *((char *)&p);
    p[0] = p[0] + *((char *)&p);
    p[0] = p[0] + *((char *)&p);
    p[35] = p[35] + *((char *)((void*)&ptr4 + 1));
    p[0] = p[0] + *((char *)&p);
    addr = *((unsigned short *)&p);
    *(addr) = *(addr) + *((char *)&addr);
    *(addr) = *(addr) ^ v4;
    *(addr) = *(addr) + *((char *)&addr);
    *(addr) = *(addr) | v4;
    v6 = *(addr);
    *(addr) = *(addr) + *((char *)&addr);
    g_7ff4d1a23c6 = g_7ff4d1a23c6 - *((char *)((void*)&addr + 1)) - ((char)(v6 + *((char *)&addr) <= v6 ? 1 : 0) & 1);
    *(addr) = *(addr) + *((char *)&addr);
    *((char *)(addr * 2)) = *((char *)(addr * 2)) + *((char *)((void*)&addr + 1));
    *(addr) = *(addr) + *((char *)&addr);
    ptr = (unsigned int)addr - 0x2cd80000;
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    return v0;
}


/* VA 0x7ff28f297d4, RVA 0x97d4, CFG name sub_7ff28f297d4; exports: [] */
typedef struct struct_1 {
    char padding_0[56];
    struct struct_0 *field_38;
} struct_1;

typedef struct struct_2 {
    char padding_0[4];
    unsigned int field_4;
} struct_2;

typedef struct struct_0 {
    char padding_0[4];
    unsigned int field_4;
} struct_0;

unsigned int sub_7ff28f297d4(struct_2 *a0, unsigned long a1, long long a2, struct_1 *a3)
{
    sub_7ff28f292dc(a1, a3, &a3->field_38->field_4);
    if (!(!((char)a0->field_4 & 102) ? a3->field_38->field_4 & 1 : a3->field_38->field_4 & 2))
        return 1;
    return __CxxFrameHandler3(a0, a1, a2, a3);
}


/* VA 0x7ff28f2437c, RVA 0x437c, CFG name sub_7ff28f2437c; exports: [] */
typedef struct struct_0 {
    char padding_0[88];
    struct struct_1 *field_58;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

extern long long g_7ff28f2cc18;
extern struct_2 *g_7ff28f2cc30;
extern unsigned long long g_7ff28f2cc40;

unsigned long long sub_7ff28f2437c(unsigned long a0, unsigned long a1, unsigned long a2, unsigned int a3, unsigned short a4, unsigned long long a5, unsigned long long a6, unsigned long long a7, unsigned long long a8)
{
    struct_0 **v5;  // rcx
    unsigned long long v6;  // rax
    unsigned long long v0;  // [bp-0x28]
    unsigned long long v1;  // [bp-0x20]
    unsigned long long v2;  // [bp-0x18]
    unsigned long long v3;  // [bp-0x10]

    v5 = g_7ff28f2cc30;
    v6 = 0;
    if (!g_7ff28f2cc30 || !g_7ff28f2cc40)
    {
        v6 = sub_7ff28f25a4c(&g_7ff28f2cc18, a3);
        v5 = g_7ff28f2cc30;
    }
    if (v5)
    {
        v3 = a8;
        v2 = a7;
        v1 = a6;
        v0 = a5;
        v6 = *(v5)->field_58();
    }
    return v6;
}


/* VA 0x7ff28f24624, RVA 0x4624, CFG name sub_7ff28f24624; exports: [] */
typedef struct struct_0 {
    char padding_0[88];
    struct struct_1 *field_58;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

extern long long g_7ff28f2cc50;
extern struct_2 *g_7ff28f2cc68;
extern unsigned long long g_7ff28f2cc78;

unsigned long long sub_7ff28f24624(unsigned long a0, unsigned long a1, unsigned long a2, unsigned int a3, unsigned short a4, unsigned long long a5, unsigned long long a6, unsigned long long a7, unsigned long long a8)
{
    struct_0 **v5;  // rcx
    unsigned long long v6;  // rax
    unsigned long long v0;  // [bp-0x28]
    unsigned long long v1;  // [bp-0x20]
    unsigned long long v2;  // [bp-0x18]
    unsigned long long v3;  // [bp-0x10]

    v5 = g_7ff28f2cc68;
    v6 = 0;
    if (!g_7ff28f2cc68 || !g_7ff28f2cc78)
    {
        v6 = sub_7ff28f25a4c(&g_7ff28f2cc50, a3);
        v5 = g_7ff28f2cc68;
    }
    if (v5)
    {
        v3 = a8;
        v2 = a7;
        v1 = a6;
        v0 = a5;
        v6 = *(v5)->field_58();
    }
    return v6;
}


/* VA 0x7ff28f24754, RVA 0x4754, CFG name sub_7ff28f24754; exports: [] */
typedef struct struct_0 {
    char padding_0[88];
    struct struct_1 *field_58;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

extern long long g_7ff28f2cc88;
extern struct_2 *g_7ff28f2cca0;
extern unsigned long long g_7ff28f2ccb0;

unsigned long long sub_7ff28f24754(unsigned long a0, unsigned long a1, unsigned long a2, unsigned int a3, unsigned short a4, unsigned long long a5, unsigned long long a6, unsigned long long a7, unsigned long long a8)
{
    struct_0 **v5;  // rcx
    unsigned long long v6;  // rax
    unsigned long long v0;  // [bp-0x28]
    unsigned long long v1;  // [bp-0x20]
    unsigned long long v2;  // [bp-0x18]
    unsigned long long v3;  // [bp-0x10]

    v5 = g_7ff28f2cca0;
    v6 = 0;
    if (!g_7ff28f2cca0 || !g_7ff28f2ccb0)
    {
        v6 = sub_7ff28f25a4c(&g_7ff28f2cc88, a3);
        v5 = g_7ff28f2cca0;
    }
    if (v5)
    {
        v3 = a8;
        v2 = a7;
        v1 = a6;
        v0 = a5;
        v6 = *(v5)->field_58();
    }
    return v6;
}


/* VA 0x7ff28f27120, RVA 0x7120, CFG name sub_7ff28f27120; exports: [] */
typedef struct struct_0 {
    struct struct_0 *field_0;
    char padding_8[16];
    unsigned long long field_18;
} struct_0;

extern char g_7ff28f2d599;
extern struct_0 g_7ff28f2d610;
extern unsigned long long g_7ff28f2d618;
extern unsigned int g_7ff28f2d620;

int sub_7ff28f27120(void)
{
    struct_0 *i;  // rdi
    unsigned long long *v2;  // rax
    unsigned long long *v3;  // rax
    unsigned int v4;  // eax
    unsigned int v5;  // eax

    if (!g_7ff28f2d599)
        return v5;
    if (!((char)g_7ff28f2d620 & 1))
    {
        g_7ff28f2d618 = &g_7ff28f2d610.field_0;
        i = &g_7ff28f2d610.field_0;
        g_7ff28f2d620 = g_7ff28f2d620 | 1;
        g_7ff28f2d610.field_0 = &g_7ff28f2d610.field_0;
    }
    for (; i != &g_7ff28f2d610.field_0; i = g_7ff28f2d610.field_0)
    {
        g_7ff28f2d610.field_0 = i->field_0;
        *((struct struct_0 ***)&g_7ff28f2d610.field_0->padding_8[0]) = &g_7ff28f2d610.field_0;
        v2 = (*((long long *)(MpUtilsExportFunctions() + 168)))();
        v3 = v2(i->field_18);
        v3(i);
    }
    g_7ff28f2d599 = 0;
    return v4;
}


/* VA 0x7ff28f261d8, RVA 0x61d8, CFG name sub_7ff28f261d8; exports: [] */
typedef struct struct_1 {
    char padding_0[8];
    long long field_8;
} struct_1;

typedef struct struct_0 {
    char padding_0[16];
    long long field_10;
    char padding_18[4];
    char field_1c;
} struct_0;

extern unsigned long long g_7ff28f2c100;
extern struct_0 *g_7ff28f2c1d8;

void sub_7ff28f261d8(struct_1 *a0, uint128_t *ptr)
{
    char v0;  // [bp-0x58]
    struct_1 *v1;  // [bp-0x38]
    int v2;  // [bp-0x28]
    unsigned long long v3;  // [bp-0x18]

    v3 = g_7ff28f2c100 ^ &v0;
    if (g_7ff28f2c1d8 != &g_7ff28f2c1d8 && (g_7ff28f2c1d8->field_1c & 8))
    {
        v1 = a0 + 4;
        sub_7ff28f26124(g_7ff28f2c1d8->field_10, 11);
    }
    v2 = (int)*(ptr);
    MpQuarantineRequest(a0->field_8, &v2, 1, 0);
    sub_7ff28f29030(v3 ^ &v0);
    return;
}


/* VA 0x7ff28f26464, RVA 0x6464, CFG name sub_7ff28f26464; exports: [] */
typedef struct struct_1 {
    char padding_0[8];
    long long field_8;
} struct_1;

typedef struct struct_0 {
    char padding_0[16];
    long long field_10;
    char padding_18[4];
    char field_1c;
} struct_0;

extern unsigned long long g_7ff28f2c100;
extern struct_0 *g_7ff28f2c1d8;

void sub_7ff28f26464(struct_1 *a0, uint128_t *ptr)
{
    char v0;  // [bp-0x58]
    struct_1 *v1;  // [bp-0x38]
    int v2;  // [bp-0x28]
    unsigned long long v3;  // [bp-0x18]

    v3 = g_7ff28f2c100 ^ &v0;
    if (g_7ff28f2c1d8 != &g_7ff28f2c1d8 && (g_7ff28f2c1d8->field_1c & 8))
    {
        v1 = a0 + 4;
        sub_7ff28f26124(g_7ff28f2c1d8->field_10, 14);
    }
    v2 = (int)*(ptr);
    MpQuarantineRequest(a0->field_8, &v2, 2, 0);
    sub_7ff28f29030(v3 ^ &v0);
    return;
}


/* VA 0x7ff28f27a0c, RVA 0x7a0c, CFG name sub_7ff28f27a0c; exports: [] */
int sub_7ff28f27a0c(unsigned long p, unsigned short *a1)
{
    unsigned short *v2;  // rdi
    unsigned long long v3;  // rcx
    unsigned long long n;  // rbx
    int v5;  // edi
    unsigned long long ptr;  // [bp+0x18]

    ptr = 0;
    v2 = a1;
    do
    {
        if (false)
            break;
    } while (*(v2));
    v3 = ~(18446744073709551615);
    n = v3 * 2;
    if (n >> 1 != v3)
    {
        v5 = -2147024809;
    }
    else
    {
        v5 = sub_7ff28f279d4(&ptr, n);
        if (v5 >= 0)
        {
            memmove(ptr, a1, n);
            *((unsigned long long *)p) = ptr;
            return 0;
        }
        else if (ptr)
        {
            free(ptr);
        }
    }
    return v5;
}


/* VA 0x7ff28f22149, RVA 0x2149, CFG name sub_7ff28f22149; exports: [] */
typedef struct struct_0 {
    char field_0;
    char padding_1[44];
    char field_2d;
    char padding_2e[805306368];
    char field_3000002e;
} struct_0;

extern char g_7ff55f221a2;

char sub_7ff28f22149(char *ptr4, char a1, unsigned long a2, unsigned long a3, char a4)
{
    void* p;  // rax
    char *ptr5;  // rbx
    void* ptr3;  // rax
    struct_0 *addr;  // rax
    unsigned int *ptr6;  // rax
    char *ptr;  // rax
    void* v0;  // [bp-0x8]

    *((unsigned int *)p) = *((int *)p) & (unsigned int)p;
    *((char *)p) = *((char *)p) + *((char *)((void*)&ptr5 + 1));
    *((unsigned int *)p) = *((int *)p) & (unsigned int)p;
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *(ptr4) = *(ptr4) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *(ptr5) = *(ptr5) + *((char *)&ptr4);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)&p[33]) = (char)p[33] + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    ptr3 = (void*)_INSERT(p, 0, *((char *)&p) + *((char *)((void*)&p + 1)));
    *((unsigned int *)ptr3) = *((int *)ptr3) & (unsigned int)ptr3;
    *((char *)&ptr3[43]) = (char)ptr3[43] + *((char *)&p) + *((char *)((void*)&p + 1));
    *((char *)ptr3) = *((char *)ptr3) + *((char *)&p) + *((char *)((void*)&p + 1));
    v0 = ptr3;
    addr = (struct_0 *)_INSERT(ptr3, 0, *((char *)&p) + *((char *)((void*)&p + 1)) - 0);
    addr->field_3000002e = addr->field_3000002e + *((char *)&ptr5);
    addr->field_0 = addr->field_0 ^ *((char *)&p) + *((char *)((void*)&p + 1)) - 0;
    addr->field_0 = addr->field_0 + *((char *)&ptr4);
    addr->field_0 = addr->field_0 ^ *((char *)&p) + *((char *)((void*)&p + 1)) - 0;
    addr->field_2d = addr->field_2d + a1;
    addr->field_0 = addr->field_0 + *((char *)&p) + *((char *)((void*)&p + 1)) - 0;
    g_7ff55f221a2 = g_7ff55f221a2 - *((char *)((void*)&ptr4 + 1));
    addr->field_0 = addr->field_0 + *((char *)&p) + *((char *)((void*)&p + 1)) - 0;
    if ([D] unsupported_<class 'pyvex.expr.GetI'>())
    {
        [D] PutI(904:F64x8)[t5,0] = t6()
        [D] PutI(968:I8x8)[t5,0] = 0x01()
    }
    else
    {
        [D] PutI(904:F64x8)[t5,0] = t6()
        [D] PutI(968:I8x8)[t5,0] = 0x01()
    }
    ptr6 = (unsigned int *)_INSERT(addr, 0, *((char *)&addr) + *((char *)&ptr5));
    ptr = (unsigned int)ptr6 - *(ptr6);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + a1;
    return *((char *)&ptr);
}


/* VA 0x7ff28f256fc, RVA 0x56fc, CFG name sub_7ff28f256fc; exports: [] */
typedef struct CRITICAL_SECTION {
    struct CRITICAL_SECTION_DEBUG *DebugInfo;
    int LockCount;
    int RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    UIntPtr SpinCount;
} CRITICAL_SECTION;

typedef struct struct_0 {
    char padding_0[8];
    unsigned long long field_8;
    struct struct_0 *field_10;
} struct_0;

typedef struct CRITICAL_SECTION_DEBUG {
    unsigned short Type;
    unsigned short CreatorBackTraceIndex;
    char padding_4[4];
    void* CriticalSection;
    LIST_ENTRY ProcessLocksList;
    unsigned int EntryCount;
    unsigned int ContentionCount;
    unsigned int Flags;
    unsigned short CreatorBackTraceIndexHigh;
    unsigned short Identifier;
} CRITICAL_SECTION_DEBUG;

typedef struct LIST_ENTRY {
    void* Flink;
    void* Blink;
} LIST_ENTRY;

unsigned int sub_7ff28f256fc(CRITICAL_SECTION *p, unsigned long a1, unsigned long long a2)
{
    unsigned int v4;  // edi
    unsigned long long v0;  // [bp-0x28]
    CRITICAL_SECTION *v1;  // [bp+0x8]
    unsigned long long v2;  // [bp+0x18]
    struct_0 *ptr;  // [bp+0x20], Other Possible Types: unsigned long long

    v2 = a2;
    v1 = p;
    v0 = 18446744073709551614;
    v4 = 0;
    if (!p)
        return 2147942487;
    ptr = 0;
    ptr = sub_7ff28f26bc4(24);
    if (!ptr)
    {
        v4 = 2147942414;
    }
    else
    {
        *((void* *)&ptr->padding_0[0]) = sub_7ff28f257b0;
        ptr->field_8 = a2;
        EnterCriticalSection(&p->OwningThread);
        ptr->field_10 = *((long long *)&p->LockCount);
        *((struct_0 **)&p->LockCount) = ptr;
        LeaveCriticalSection(&p->OwningThread);
    }
    return v4;
}


/* VA 0x7ff28f25ef0, RVA 0x5ef0, CFG name sub_7ff28f25ef0; exports: [] */
typedef struct CRITICAL_SECTION {
    struct CRITICAL_SECTION_DEBUG *DebugInfo;
    int LockCount;
    int RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    UIntPtr SpinCount;
} CRITICAL_SECTION;

typedef struct struct_1 {
    struct struct_2 *field_0;
    unsigned int field_8;
} struct_1;

typedef struct CRITICAL_SECTION_DEBUG {
    unsigned short Type;
    unsigned short CreatorBackTraceIndex;
    char padding_4[4];
    void* CriticalSection;
    LIST_ENTRY ProcessLocksList;
    unsigned int EntryCount;
    unsigned int ContentionCount;
    unsigned int Flags;
    unsigned short CreatorBackTraceIndexHigh;
    unsigned short Identifier;
} CRITICAL_SECTION_DEBUG;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct LIST_ENTRY {
    void* Flink;
    void* Blink;
} LIST_ENTRY;

typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

extern char g_7ff28f21af0;

unsigned long long sub_7ff28f25ef0(CRITICAL_SECTION *ptr)
{
    struct_1 *v1;  // rcx
    unsigned long long flag;  // rdx
    struct_1 *v3;  // rcx
    unsigned long long choice;  // rdx
    unsigned long v5;  // rax
    CRITICAL_SECTION *p;  // rcx

    v1 = ptr[2].DebugInfo;
    if (v1)
    {
        InterlockedExchangeAdd(&v1->field_8, 4294967295);
        if (v1->field_8 - 1 <= 0 && v1)
        {
            flag = 1;
            v1->field_0->field_0();
        }
        ptr[2].DebugInfo = NULL;
    }
    if (ptr[1].SpinCount)
    {
        MpConfigUninitialize();
        ptr[1].SpinCount = 0;
    }
    v3 = ptr[2].DebugInfo;
    if (v3)
    {
        InterlockedExchangeAdd(&v3->field_8, 4294967295);
        if (v3->field_8 - 1 <= 0 && v3)
        {
            choice = 1;
            v3->field_0->field_0();
        }
    }
    if (ptr[1].SpinCount)
        MpConfigUninitialize();
    v5 = &g_7ff28f21af0;
    p = &ptr->OwningThread;
    ptr->DebugInfo = &g_7ff28f21af0;
    if ((char)p[1].DebugInfo)
    {
        *((char *)&p[1].DebugInfo) = 0;
        v5 = (unsigned long long)DeleteCriticalSection(p);
    }
    return v5;
}


/* VA 0x7ff28f27268, RVA 0x7268, CFG name sub_7ff28f27268; exports: [] */
extern long long g_7ff28f217c8;

unsigned int sub_7ff28f27268(long long a0, unsigned long a1, unsigned long a2, unsigned short *a3)
{
    unsigned long long v7;  // rcx
    unsigned short *v8;  // rdi
    unsigned short *v9;  // rax
    unsigned short *v10;  // r9
    unsigned short *v0;  // [bp-0x38]
    unsigned long long v1;  // [bp-0x30]
    char *v2;  // [bp-0x28]
    unsigned long long v3;  // [bp-0x20]
    unsigned long long flag;  // [bp-0x18]
    char v6;  // [bp+0x28]

    if (!a3)
    {
        v7 = 10;
    }
    else if (!*(a3))
    {
        v7 = 14;
    }
    else
    {
        v8 = a3;
        do
        {
            if (false)
                break;
        } while (*(v8));
        v7 = ~(18446744073709551615) * 2;
    }
    if (a3)
    {
        v9 = L"<NULL>";
        if (!*(a3))
            v10 = v9;
        else
            v10 = a3;
    }
    else
    {
        v10 = L"NULL";
    }
    flag = 0;
    v3 = 4;
    v2 = &v6;
    v1 = v7;
    v0 = v10;
    return sub_7ff28f236b0(a0, 43, &g_7ff28f217c8, 53);
}


/* VA 0x7ff28f23c54, RVA 0x3c54, CFG name sub_7ff28f23c54; exports: [] */
typedef struct CRITICAL_SECTION {
    struct CRITICAL_SECTION_DEBUG *DebugInfo;
    int LockCount;
    int RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    UIntPtr SpinCount;
} CRITICAL_SECTION;

typedef struct struct_2 {
    struct struct_3 *field_0;
    unsigned long long field_8;
    struct struct_2 *field_10;
} struct_2;

typedef struct struct_0 {
    char padding_0[16];
    struct struct_1 *field_10;
} struct_0;

typedef struct CRITICAL_SECTION_DEBUG {
    unsigned short Type;
    unsigned short CreatorBackTraceIndex;
    char padding_4[4];
    void* CriticalSection;
    LIST_ENTRY ProcessLocksList;
    unsigned int EntryCount;
    unsigned int ContentionCount;
    unsigned int Flags;
    unsigned short CreatorBackTraceIndexHigh;
    unsigned short Identifier;
} CRITICAL_SECTION_DEBUG;

typedef struct struct_3 {
    unsigned long long field_0;
} struct_3;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct LIST_ENTRY {
    void* Flink;
    void* Blink;
} LIST_ENTRY;

void sub_7ff28f23c54(CRITICAL_SECTION *p)
{
    CRITICAL_SECTION *ptr;  // rsi
    struct_2 *v2;  // rbp
    struct_2 *addr;  // rbp
    struct_2 *v4;  // rbx
    struct_0 **v5;  // rcx

    ptr = &p->LockCount;
    if (!(int)ptr->DebugInfo)
        return;
    if (p->OwningThread)
    {
        if (!ptr)
        {
            RaiseException(3221225477, 1, 0, NULL);
            [D] Unsupported jumpkind Ijk_SigTRAP at address 8792485018772()
        }
        v2 = *((long long *)&ptr->LockCount);
        if (*((long long *)&ptr->LockCount))
        {
            do
            {
                addr = v2;
                addr->field_0(addr->field_8);
                v4 = addr->field_10;
                free(addr);
                v2 = v4;
            } while (addr->field_10);
        }
        *((struct_2 **)&ptr->LockCount) = NULL;
        p->OwningThread = NULL;
    }
    v5 = p[1].LockSemaphore;
    if (v5)
        *(v5)->field_10(v5);
    DeleteCriticalSection(&p->LockSemaphore);
    *((unsigned int *)&ptr->DebugInfo) = 0;
    return;
}


/* VA 0x7ff28f275c8, RVA 0x75c8, CFG name sub_7ff28f275c8; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    long long field_10;
    char padding_18[4];
    char field_1c;
} struct_0;

extern long long g_7ff28f217c8;
extern struct_0 *g_7ff28f2c1d8;

unsigned int sub_7ff28f275c8(unsigned short *a0)
{
    unsigned int v2;  // eax
    unsigned int v3;  // ebx
    unsigned int v0;  // [bp-0x18]

    v2 = GetFileAttributesW(a0);
    if (v2 == 4294967295)
    {
        v3 = sub_7ff28f27678();
        if (v3 == 2147942402 || g_7ff28f2c1d8 == &g_7ff28f2c1d8 || !(g_7ff28f2c1d8->field_1c & 1))
            return v3;
        v0 = v3;
        sub_7ff28f27268(g_7ff28f2c1d8->field_10, 53, &g_7ff28f217c8, a0);
        return v3;
    }
    else if (((char)v2 & 16))
    {
        if (g_7ff28f2c1d8 == &g_7ff28f2c1d8 || !(g_7ff28f2c1d8->field_1c & 1))
            return 2147942583;
        sub_7ff28f271e8(g_7ff28f2c1d8->field_10, 54, &g_7ff28f217c8, a0);
        return 2147942583;
    }
    else
    {
        return 0;
    }
}


/* VA 0x7ff28f236f8, RVA 0x36f8, CFG name sub_7ff28f236f8; exports: [] */
typedef struct struct_0 {
    struct struct_0 *field_0;
    unsigned int field_8;
    unsigned int field_c;
    struct struct_0 *field_10;
    char padding_18[1];
    Byte field_19;
    char field_1a;
    char padding_1b[1];
    unsigned int field_1c;
} struct_0;

unsigned int sub_7ff28f236f8(unsigned int a0, struct_0 *a1, unsigned int *ptr, void* a3)
{
    struct_0 *cur;  // rbx
    struct_0 *v2;  // rdi
    unsigned int v3;  // edx
    Byte v4;  // sil

    *(ptr) = 0;
    cur = a1;
    if (a0 != 4)
    {
        if (a0 != 5)
            return 87;
        v2 = NULL;
        v3 = 0;
        v4 = 0;
    }
    else
    {
        v2 = GetTraceLoggerHandle(a3);
        v4 = GetTraceEnableLevel(v2);
        v3 = GetTraceEnableFlags(v2);
    }
    if ((cur->field_1a & 1) && cur->field_10)
    {
        cur->field_10->field_0 = v2;
        cur->field_10->field_c = v4;
        cur->field_10->field_8 = v3;
    }
    else
    {
        if ((cur->field_1a & 2) && cur->field_10)
            cur = cur->field_10;
LABEL_7ff28f23784:
        cur->field_10 = v2;
        cur->field_19 = v4;
        cur->field_1c = v3;
        goto LABEL_7ff28f23784;
    }
    return 0;
}


/* VA 0x7ff28f27fbc, RVA 0x7fbc, CFG name sub_7ff28f27fbc; exports: [] */
typedef struct struct_1 {
    struct struct_2 *field_0;
    unsigned int field_8;
    char padding_c[4];
    long long field_10;
} struct_1;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

unsigned int sub_7ff28f27fbc(unsigned long a0, unsigned long a1, long long a2)
{
    unsigned int v2;  // eax
    struct_1 *v3;  // rcx
    struct_1 *v4;  // rbx
    unsigned int v5;  // eax
    struct_1 *flag;  // [bp+0x20]

    flag = NULL;
    v2 = sub_7ff28f28074();
    if (v2 < 0)
    {
        v3 = flag;
        if (!v3)
            return v2;
        InterlockedExchangeAdd(&v3->field_8, 4294967295);
        if (v3->field_8 - 1 <= 0)
            flag->field_0->field_0(flag, 1);
        return v2;
    }
    else
    {
        v4 = flag;
        v5 = MpConfigDelValue(v4->field_10, a2);
        if (v5 < 0)
        {
            InterlockedExchangeAdd(&v4->field_8, 4294967295);
            if (v4->field_8 - 1 > 0)
                return v5;
            flag->field_0->field_0(flag, 1, flag->field_0);
            return v5;
        }
        else
        {
            InterlockedExchangeAdd(&v4->field_8, 4294967295);
            if (v4->field_8 - 1 > 0)
                return 0;
            flag->field_0->field_0(flag, 1);
            return 0;
        }
    }
}


/* VA 0x7ff28f2947c, RVA 0x947c, CFG name _security_init_cookie; exports: [] */
extern unsigned long long g_7ff28f2c100;
extern unsigned long long g_7ff28f2c108;

unsigned long long _security_init_cookie(void)
{
    unsigned int v2;  // eax
    unsigned int v3;  // eax
    unsigned int v4;  // eax
    unsigned long long v5;  // r11
    unsigned int flag[2];  // [bp+0x8], Other Possible Types: unsigned long long
    long long v1;  // [bp+0x10]

    flag = 0;
    if (g_7ff28f2c100 != 47936899621426)
    {
        g_7ff28f2c108 = ~(g_7ff28f2c100);
        return g_7ff28f2c108;
    }
    GetSystemTimeAsFileTime(&flag);
    v2 = GetCurrentProcessId();
    v3 = GetCurrentThreadId();
    v4 = GetTickCount();
    QueryPerformanceCounter(&v1);
    v5 = (unsigned long long)((v1 ^ flag ^ v2 ^ v3 ^ v4) & 281474976710655);
    if (v5 == 47936899621426)
        v5 = 47936899621427;
    g_7ff28f2c100 = v5;
    g_7ff28f2c108 = ~(v5);
    return 47936899621427;
}


/* VA 0x7ff28f2a05c, RVA 0xa05c, CFG name sub_7ff28f2a05c; exports: [] */
typedef struct struct_0 {
    char padding_0[64];
    struct struct_1 *field_40;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

extern char g_7ff28f21578;
extern struct_2 *g_7ff28f2ce80;
extern char g_7ff28f2ce88;
extern unsigned long long g_7ff28f2d5a0;
extern unsigned int g_7ff28f2d5a8;
extern unsigned int g_7ff28f2d5ac;
extern unsigned long long g_7ff28f2d5b0;
extern char g_7ff28f2d5b8;
extern unsigned long long g_7ff28f2d5e0;
extern char g_7ff28f2d5ea;
extern unsigned long long g_7ff28f2d5f0;

long long sub_7ff28f2a05c(void)
{
    struct_0 **i;  // rbx
    struct_0 **v2;  // rax
    unsigned long v3;  // rcx

    memset(&g_7ff28f2d5b8, 0, 40);
    g_7ff28f2d5a8 = 0;
    g_7ff28f2d5b0 = 0;
    g_7ff28f2d5ac = 0;
    g_7ff28f2d5e0 = 0;
    g_7ff28f2d5f0 = &g_7ff28f2d5a0;
    if (sub_7ff28f23be4(&g_7ff28f2d5b8) < 0)
        g_7ff28f2d5ea = 1;
    else
        g_7ff28f2d5a8 = 56;
    i = g_7ff28f2ce80;
    for (v2 = *((long long *)&g_7ff28f2ce88); i < v2; i += 1)
    {
        if (*(i))
        {
            *(i)->field_40(v3);
            v2 = *((long long *)&g_7ff28f2ce88);
        }
    }
    g_7ff28f2d5a0 = &g_7ff28f21578;
    return sub_7ff28f291d4();
}


/* VA 0x7ff28f289d8, RVA 0x89d8, CFG name sub_7ff28f289d8; exports: [] */
typedef struct CRITICAL_SECTION {
    struct CRITICAL_SECTION_DEBUG *DebugInfo;
    int LockCount;
    int RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    UIntPtr SpinCount;
} CRITICAL_SECTION;

typedef struct CRITICAL_SECTION_DEBUG {
    unsigned short Type;
    unsigned short CreatorBackTraceIndex;
    char padding_4[4];
    void* CriticalSection;
    LIST_ENTRY ProcessLocksList;
    unsigned int EntryCount;
    unsigned int ContentionCount;
    unsigned int Flags;
    unsigned short CreatorBackTraceIndexHigh;
    unsigned short Identifier;
} CRITICAL_SECTION_DEBUG;

typedef struct LIST_ENTRY {
    void* Flink;
    void* Blink;
} LIST_ENTRY;

unsigned int sub_7ff28f289d8(CRITICAL_SECTION *ptr, HINSTANCE a1)
{
    unsigned int v1;  // edi
    long long v2;  // rsi

    if (!ptr)
        return 2147942487;
    if (!(int)ptr->DebugInfo)
        return 0;
    if ((int)ptr->DebugInfo != 72)
        return 2147942487;
    v1 = 0;
    if ((int)ptr[1].LockSemaphore > 0)
    {
        v2 = 0;
        do
        {
            if (v2 < 0 || v1 >= (int)ptr[1].LockSemaphore)
            {
                RaiseException(3221225612, 1, 0, NULL);
                [D] Unsupported jumpkind Ijk_SigTRAP at address 8792485038731()
            }
        } while ((UnregisterClassA((unsigned long long)(unsigned short)*((short *)((char *)ptr[1].OwningThread + v2)), a1), v1 += 1, v2 = (long long)(v2 + 2), v1 < (int)ptr[1].LockSemaphore));
    }
    if (ptr[1].OwningThread)
    {
        sub_7ff28f291f2();
        ptr[1].OwningThread = 0;
    }
    *((unsigned int *)&ptr[1].LockSemaphore) = 0;
    *((unsigned int *)((char *)&ptr[1].LockSemaphore + 4)) = 0;
    DeleteCriticalSection(&ptr->LockCount);
    *((unsigned int *)&ptr->DebugInfo) = 0;
    return 0;
}


/* VA 0x7ff28f27914, RVA 0x7914, CFG name sub_7ff28f27914; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    struct struct_1 *field_10;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

extern long long g_7ff28f2ccc0;
extern long long g_7ff28f2cce0;
extern long long g_7ff28f2cd38;
extern long long g_7ff28f2cd68;

unsigned long long sub_7ff28f27914(long long a0)
{
    struct_0 **v2;  // rax
    long long v0;  // [bp-0x18]

    v2 = __RTDynamicCast();
    if (v2)
        return *(v2)->field_10(v2, *(v2));
    *((unsigned int *)&v0) = 0;
    if (__RTDynamicCast(a0, 0, &g_7ff28f2ccc0, &g_7ff28f2cce0, v0))
        return 2147942414;
    *((unsigned int *)&v0) = 0;
    if (!__RTDynamicCast(a0, 0, &g_7ff28f2ccc0, &g_7ff28f2cd68, v0))
    {
        *((unsigned int *)&v0) = 0;
        return (-(0 < __RTDynamicCast(a0, 0, &g_7ff28f2ccc0, &g_7ff28f2cd38, v0)) & 442450) - 2147467259;
    }
    return 2147943813;
}


/* VA 0x7ff28f235ec, RVA 0x35ec, CFG name sub_7ff28f235ec; exports: [] */
extern unsigned long long g_7ff28f2c1c8;
extern unsigned long long g_7ff28f2c1d0;
extern unsigned int g_7ff28f2d608;

HMODULE sub_7ff28f235ec(void)
{
    HMODULE v1;  // rbx
    void* v2;  // rax

    v1 = LoadLibraryW(L"advapi32");
    if (!v1)
    {
        g_7ff28f2d608 = 0;
        g_7ff28f2c1c8 = sub_7ff28f235c8;
        g_7ff28f2c1d0 = sub_7ff28f23498;
        return v1;
    }
    g_7ff28f2c1c8 = GetProcAddress(v1, "TraceMessage");
    if (!g_7ff28f2c1c8)
    {
        g_7ff28f2d608 = 0;
        g_7ff28f2c1c8 = sub_7ff28f235c8;
        g_7ff28f2c1d0 = sub_7ff28f23498;
    }
    else
    {
        g_7ff28f2d608 = 1;
        v2 = GetProcAddress(v1, "TraceMessageVa");
        if (!v2)
            v2 = sub_7ff28f23498;
        g_7ff28f2c1d0 = v2;
    }
    return FreeLibrary(v1);
}


/* VA 0x7ff28f2730c, RVA 0x730c, CFG name sub_7ff28f2730c; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    unsigned int field_10;
    char padding_14[8];
    char field_1c;
} struct_0;

extern unsigned int g_7ff28f217c8;
extern struct_0 *g_7ff28f2c1d8;

unsigned long long sub_7ff28f2730c(void* ptr, LPArray a1)
{
    unsigned long v1;  // rbx
    unsigned int v2;  // eax
    unsigned long v3;  // r11
    unsigned int v4;  // ebx

    v1 = *((int *)ptr);
    if (v1 != *((long long *)ptr))
    {
        return 2147942487;
    }
    else if (!(unsigned int)v1)
    {
        return 2147942522;
    }
    else
    {
        v2 = GetModuleFileNameW(NULL, a1, v1);
        v3 = v2;
        if (!v2)
        {
            v4 = sub_7ff28f27678();
            if (g_7ff28f2c1d8 == &g_7ff28f2c1d8 || !(g_7ff28f2c1d8->field_1c & 1))
                return v4;
            sub_7ff28f23d2c(*((long long *)&g_7ff28f2c1d8->field_10), 32, &g_7ff28f217c8, v4);
            return v4;
        }
        else
        {
            if ((unsigned int)v3 >= (unsigned int)v1 || *((short *)&a1[2 * v3]))
                return ((unsigned int)v3 != (unsigned int)v1 ? 2147549183 : 2147942522);
            *((unsigned long long *)ptr) = (unsigned int)v3 + 1;
            return 0;
            return ((unsigned int)v3 != (unsigned int)v1 ? 2147549183 : 2147942522);
        }
    }
}


/* VA 0x7ff28f250f4, RVA 0x50f4, CFG name sub_7ff28f250f4; exports: [] */
typedef struct SAFEARRAYBOUND {
    unsigned int cElements;
    int lLbound;
} SAFEARRAYBOUND;

typedef struct SAFEARRAY {
    unsigned short cDims;
    enum ADVANCED_FEATURE_FLAGS fFeatures;
    unsigned int cbElements;
    unsigned int cLocks;
    char padding_c[4];
    void* pvData;
    struct SAFEARRAYBOUND *rgsabound;
} SAFEARRAY;

typedef struct struct_0 {
    char padding_0[16];
    unsigned int field_10;
    char padding_14[8];
    char field_1c;
} struct_0;

extern struct_0 *g_7ff28f2c1d8;

unsigned int sub_7ff28f250f4(void* ptr, long long a1)
{
    SAFEARRAY *v2;  // rax
    SAFEARRAYBOUND v1;  // [bp+0x18]

    if (!a1)
        return 2147942487;
    VariantInit(ptr);
    v1.cElements = 16;
    v1.lLbound = 0;
    v2 = SafeArrayCreate(VT_UI1, 1, &v1);
    if (v2)
    {
        memmove(v2->pvData, a1, 16);
        *((SAFEARRAY **)&ptr[8]) = v2;
        *((unsigned short *)ptr) = 8209;
        return 0;
    }
    if (g_7ff28f2c1d8 == &g_7ff28f2c1d8 || !(g_7ff28f2c1d8->field_1c & 1))
        return 2147942414;
    sub_7ff28f23d08(*((long long *)&g_7ff28f2c1d8->field_10), 14);
    return 2147942414;
}


/* VA 0x7ff28f27ee4, RVA 0x7ee4, CFG name sub_7ff28f27ee4; exports: [] */
typedef struct struct_1 {
    struct struct_2 *field_0;
    unsigned int field_8;
    char padding_c[4];
    long long field_10;
} struct_1;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

unsigned int sub_7ff28f27ee4(unsigned long a0, unsigned long a1, long long a2, unsigned int a3, unsigned int a4, long long a5)
{
    unsigned int v2;  // eax
    struct_1 *v3;  // rcx
    struct_1 *v4;  // rbx
    unsigned int v5;  // eax
    struct_1 *flag;  // [bp-0x18]

    flag = NULL;
    v2 = sub_7ff28f28074();
    if (v2 < 0)
    {
        v3 = flag;
        if (!v3)
            return v2;
        InterlockedExchangeAdd(&v3->field_8, 4294967295);
        if (v3->field_8 - 1 <= 0)
            flag->field_0->field_0(flag, 1);
        return v2;
    }
    else
    {
        v4 = flag;
        v5 = MpConfigSetValue(v4->field_10, a2, a3, a4, a5);
        if (v5 < 0)
        {
            InterlockedExchangeAdd(&v4->field_8, 4294967295);
            if (v4->field_8 - 1 > 0)
                return v5;
            flag->field_0->field_0(flag, 1, flag->field_0);
            return v5;
        }
        else
        {
            InterlockedExchangeAdd(&v4->field_8, 4294967295);
            if (v4->field_8 - 1 > 0)
                return 0;
            flag->field_0->field_0(flag, 1);
            return 0;
        }
    }
}


/* VA 0x7ff28f27e08, RVA 0x7e08, CFG name sub_7ff28f27e08; exports: [] */
typedef struct struct_1 {
    struct struct_2 *field_0;
    unsigned int field_8;
    char padding_c[4];
    long long field_10;
} struct_1;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

unsigned int sub_7ff28f27e08(unsigned long a0, unsigned long a1, long long a2, long long a3, long long a4, long long a5)
{
    unsigned int v2;  // eax
    struct_1 *v3;  // rcx
    struct_1 *v4;  // rbx
    unsigned int v5;  // eax
    struct_1 *flag;  // [bp-0x18]

    flag = NULL;
    v2 = sub_7ff28f28074();
    if (v2 < 0)
    {
        v3 = flag;
        if (!v3)
            return v2;
        InterlockedExchangeAdd(&v3->field_8, 4294967295);
        if (v3->field_8 - 1 <= 0)
            flag->field_0->field_0(flag, 1);
        return v2;
    }
    else
    {
        v4 = flag;
        v5 = MpConfigGetValue(v4->field_10, a2, a3, a4, a5, 0);
        if (v5 < 0)
        {
            InterlockedExchangeAdd(&v4->field_8, 4294967295);
            if (v4->field_8 - 1 > 0)
                return v5;
            flag->field_0->field_0(flag, 1, flag->field_0);
            return v5;
        }
        else
        {
            InterlockedExchangeAdd(&v4->field_8, 4294967295);
            if (v4->field_8 - 1 > 0)
                return 0;
            flag->field_0->field_0(flag, 1);
            return 0;
        }
    }
}


/* VA 0x7ff28f285f4, RVA 0x85f4, CFG name sub_7ff28f285f4; exports: [] */
typedef struct ACL {
    Byte AclRevision;
    Byte Sbz1;
    unsigned short AclSize;
    unsigned short AceCount;
    unsigned short Sbz2;
} ACL;

typedef struct struct_0 {
    char padding_0[16];
    unsigned int field_10;
    char padding_14[8];
    char field_1c;
} struct_0;

extern unsigned int g_7ff28f21778;
extern struct_0 *g_7ff28f2c1d8;

unsigned int sub_7ff28f285f4(unsigned long long *ptr, PSECURITY_DESCRIPTOR a1)
{
    unsigned int v4;  // ebx
    struct_0 *v5;  // rcx
    int flag2[4];  // [bp+0x8]
    int flag[2];  // [bp+0x18]
    unsigned long long choice;  // [bp+0x20]
    ACL *v3;  // [bp+0x20]

    *(ptr) = 0;
    choice = 0;
    flag2 = (int (32 bits)[4])0;
    flag = (int (32 bits)[2])0;
    if (!GetSecurityDescriptorDacl(a1, &flag2, &v3, &flag))
    {
        v4 = sub_7ff28f27678();
        v5 = g_7ff28f2c1d8;
        if (g_7ff28f2c1d8 != &g_7ff28f2c1d8 && (g_7ff28f2c1d8->field_1c & 1))
        {
            sub_7ff28f23d2c(*((long long *)&g_7ff28f2c1d8->field_10), 15, &g_7ff28f21778, v4);
            v5 = g_7ff28f2c1d8;
        }
        if (v4 < 0)
            return v4;
    }
    else
    {
        v5 = g_7ff28f2c1d8;
    }
    if (!flag2)
    {
        if (v5 == &g_7ff28f2c1d8 || !(v5->field_1c & 1))
            return 2147942402;
        sub_7ff28f23d08(*((long long *)&v5->field_10), 16);
        return 2147942402;
    }
    else if (!v3)
    {
        return 2147549183;
    }
    else
    {
        *(ptr) = v3;
        return 0;
    }
}


/* VA 0x7ff28f27af0, RVA 0x7af0, CFG name sub_7ff28f27af0; exports: [] */
typedef struct Guid {
    unsigned int Data1;
    unsigned short Data2;
    unsigned short Data3;
    char Data4[8];
} Guid;

unsigned int sub_7ff28f27af0(Guid *a0)
{
    unsigned int v5;  // eax
    unsigned long v6;  // rcx
    unsigned long v7;  // rcx
    unsigned int v8;  // eax
    unsigned int v9;  // ecx
    unsigned int v10;  // edx
    unsigned long flag2;  // [bp-0x18]
    unsigned int flag;  // [bp+0x10]
    unsigned int v3;  // [bp+0x18]
    unsigned long choice;  // [bp+0x20]

    choice = 0;
    v5 = MpConfigOpen(".", &choice);
    v6 = choice;
    v7 = v6;
    if (v5 >= 0)
    {
        flag2 = 0;
        flag = 0;
        v3 = 2;
        v5 = MpConfigGetValueAlloc(v6, L"ReportingGUID", &v3, &flag, &flag2, 0, 0);
        if (v5 >= 0)
        {
            v8 = (unsigned long long)UuidFromStringW(NULL, a0);
            v9 = v8 | 0x80010000;
            v10 = -(0 < v8);
            v5 = ((v10 & v9) < 0 ? v10 & v9 : 0);
            if (v5 >= 0)
            {
                if (!choice)
                    return 0;
                MpConfigClose(choice);
                return 0;
            }
        }
        v7 = choice;
    }
    if (v7)
        MpConfigClose();
    return v5;
}


/* VA 0x7ff28f282bc, RVA 0x82bc, CFG name sub_7ff28f282bc; exports: [] */
typedef struct struct_1 {
    char padding_0[8];
    unsigned int field_8;
    char padding_c[4];
    char field_10;
    char padding_11[47];
    unsigned long long field_40;
} struct_1;

extern char g_10;

int sub_7ff28f282bc(struct_1 **ptr)
{
    struct_1 *v2;  // rbx
    int v3;  // esi
    int v5;  // eax
    struct_1 *p;  // [bp+0x10]

    v2 = NULL;
    p = NULL;
    v3 = sub_7ff28f28428(&p);
    if (v3 >= 0)
    {
        v5 = (!InitializeCriticalSectionAndSpinCount(&p->padding_11[7], 0) ? (unsigned int)sub_7ff28f27678() : 0);
        if (v5 >= 0)
        {
            p->field_10 = 1;
            v5 = 0;
        }
        v3 = (v5 < 0 ? v5 : 0);
        if (v3 < 0)
        {
            if (p)
                InterlockedExchangeAdd(&p->field_8, 4294967295);
        }
        else
        {
            v2 = p;
            v3 = 0;
        }
    }
    else if (p)
    {
        InterlockedExchangeAdd(&p->field_8, 4294967295);
    }
    if (v3 >= 0)
    {
        *(ptr) = v2;
        return 0;
    }
    if (!v2)
        return v3;
    InterlockedExchangeAdd(&v2->field_8, 4294967295);
    if (v2->field_8 - 1 <= 0)
        (*((long long *)&v2->padding_0))(v2, 1, v2->padding_0);
    return v3;
}


/* VA 0x7ff28f26864, RVA 0x6864, CFG name sub_7ff28f26864; exports: [] */
typedef struct struct_0 {
    unsigned short field_0;
    char padding_2[6];
    struct SAFEARRAY *field_8;
} struct_0;

typedef struct SAFEARRAY {
    unsigned short cDims;
    enum ADVANCED_FEATURE_FLAGS fFeatures;
    unsigned int cbElements;
    unsigned int cLocks;
    char padding_c[4];
    void* pvData;
    struct SAFEARRAYBOUND *rgsabound;
} SAFEARRAY;

typedef struct SAFEARRAYBOUND {
    unsigned int cElements;
    int lLbound;
} SAFEARRAYBOUND;

extern unsigned int g_7ff28f217f8;
extern void* g_7ff28f2c1d8;

unsigned int sub_7ff28f26864(unsigned long a0, long long a1, struct_0 *a2)
{
    unsigned int v3;  // eax
    unsigned int v4;  // eax
    unsigned long v0;  // [bp-0x18]
    unsigned long long flag;  // [bp+0x8]
    unsigned long long choice;  // [bp+0x10]

    if (g_7ff28f2c1d8 != &g_7ff28f2c1d8 && ((char)g_7ff28f2c1d8[28] & 8))
    {
        v0 = a0 - 64;
        sub_7ff28f26124((long long)g_7ff28f2c1d8[16], 21);
    }
    if (!a1)
        return 2147942487;
    flag = 0;
    choice = 0;
    v3 = sub_7ff28f26fa4(a2, &flag, &choice);
    if (v3 < 0)
    {
        return v3;
    }
    else if (!IsValidSid(flag))
    {
        v4 = sub_7ff28f27678();
        if (g_7ff28f2c1d8 == &g_7ff28f2c1d8 || !((char)g_7ff28f2c1d8[28] & 1))
            return v4;
        sub_7ff28f23d2c((long long)g_7ff28f2c1d8[16], 22, &g_7ff28f217f8, v4);
        return v4;
    }
    else
    {
        return sub_7ff28f26950(a1, flag);
    }
}


/* VA 0x7ff28f22a5f, RVA 0x2a5f, CFG name sub_7ff28f22a5f; exports: [] */
extern char g_7ff55ca2b06;

void sub_7ff28f22a5f(char *ptr4, char a1, unsigned long a2, unsigned long a3, char a4, char a5)
{
    void* ptr;  // rax
    unsigned long v4;  // cc_op
    unsigned long v13;  // 4194
    char ptr3[45];  // rax
    char *addr;  // rax
    char v16;  // dh
    unsigned long v5;  // cc_dep1
    unsigned long v6;  // cc_dep2
    unsigned long v7;  // cc_ndep
    unsigned long v8;  // 4176
    char v9;  // 4168
    unsigned long v10;  // 4228
    void* p;  // rax
    char v12;  // 4150
    char *v0;  // [bp-0x6c]
    unsigned long v1;  // [bp-0x3a]

    *((unsigned int *)ptr) = *((int *)ptr) + 1;
    v8 = _ccall(v4, v5, v6, v7);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((unsigned int *)ptr) = *((int *)ptr) - (unsigned int)ptr;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *(ptr4) = *(ptr4) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    v9 = *((char *)ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    v10 = _ccall(8, 1, (unsigned long long)v9, (unsigned long long)*((char *)(void*)&ptr), v8);
    if (!((char)v10))
    {
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((unsigned int *)ptr) = *((int *)ptr) + (unsigned int)ptr;
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        v1 = &vvar_32{r56|8b};
    }
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((unsigned int *)ptr) = *((int *)ptr) + (unsigned int)ptr;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    p = (unsigned int)ptr | *((int *)ptr);
    v12 = *((char *)p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    v13 = _ccall(5, 1, (unsigned long long)v12, (unsigned long long)*((char *)(void*)&p), v8);
    if (!(ptr4 + 1 & (char)v13))
    {
        *((char *)p) = *((char *)p) + *((char *)&p);
        *((char *)p) = *((char *)p) + *((char *)&p);
        *((char *)p) = *((char *)p) + *((char *)&p);
        *((char *)p) = *((char *)p) + *((char *)&p);
        *((char *)p) = *((char *)p) + *((char *)&p);
        *((char *)p) = *((char *)p) + *((char *)&p);
        ptr3 = (unsigned int)p - *((int *)p);
        ptr3[44] = ptr3[44] + a1;
        ptr3[0] = ptr3[0] + *((char *)&ptr3);
        addr = *((unsigned short *)&ptr3);
        *(addr) = *(addr) + *((char *)&addr);
        *(addr) = *(addr) ^ v16;
        *(addr) = *(addr) + *((char *)&addr);
        *(addr) = *(addr) | v16;
        *(addr) = *(addr) + *((char *)&addr);
        v0 = addr;
        p = (unsigned int)v0 - 0x2d280000;
        *((char *)p) = *((char *)p) + *((char *)&p);
    }
    g_7ff55ca2b06 = g_7ff55ca2b06 + *((char *)((void*)&ptr4 + 1 + 1));
    *((char *)p) = *((char *)p) + *((char *)&p);
    [D] PutI(904:F64x8)[t144,0] = t145()
    [D] PutI(968:I8x8)[t144,0] = 0x01()
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((unsigned int *)p) = *((int *)p) | (unsigned int)p;
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
}


/* VA 0x7ff28f241ec, RVA 0x41ec, CFG name sub_7ff28f241ec; exports: [] */
typedef struct struct_2 {
    char padding_0[16];
    unsigned long long field_10;
    char padding_18[8];
    char field_20;
} struct_2;

typedef struct struct_0 {
    char padding_0[16];
    struct struct_1 *field_10;
    char padding_18[4];
    char field_1c;
} struct_0;

typedef struct struct_3 {
    char padding_0[80];
    struct struct_4 *field_50;
} struct_3;

typedef struct struct_1 {
    struct struct_0 *field_0;
} struct_1;

typedef struct struct_4 {
    unsigned long long field_0;
} struct_4;

extern unsigned long long g_7ff28f2c100;
extern struct_0 *g_7ff28f2c1d8;

void sub_7ff28f241ec(struct_2 *ptr, unsigned short *a1)
{
    unsigned long long v4;  // rdx
    unsigned int v5;  // eax
    unsigned long v6;  // 4131
    struct_0 *v7;  // rcx
    struct_3 *v8;  // rax
    char v0;  // [bp-0x48]
    char v1;  // [bp-0x28], Other Possible Types: unsigned long long
    unsigned long long v2;  // [bp-0x18]

    v2 = g_7ff28f2c100 ^ &v0;
    if (*(a1) != 8209)
    {
        if (g_7ff28f2c1d8 != &g_7ff28f2c1d8 && (g_7ff28f2c1d8->field_1c & 1))
            sub_7ff28f23d08(g_7ff28f2c1d8->field_10, 13);
        sub_7ff28f29030(v2 ^ &v0);
        return;
    }
    else if ((unsigned int)sub_7ff28f251c0(&v1, a1) >= 0)
    {
        v4 = ptr->field_10;
        if (ptr->field_10 == v1 && !((v4 = (unsigned long long)ptr->padding_18, ptr->padding_18 != v1)))
        {
            v5 = 0;
        }
        else
        {
            v6 = _ccall(15, 0, (unsigned long long)(char)(v4 < v1), (unsigned long long)(char)(v4 < v1));
            v5 = -(v4 < v1) + 1 - ((unsigned int)v6 & 1);
        }
        if (!v5)
        {
            ptr->field_20 = 1;
            sub_7ff28f29030(v2 ^ &v0);
            return;
        }
        v7 = g_7ff28f2c1d8;
        if (g_7ff28f2c1d8 != &g_7ff28f2c1d8 && (g_7ff28f2c1d8->field_1c & 1))
        {
            v7 = g_7ff28f2c1d8->field_10;
            sub_7ff28f23d08(g_7ff28f2c1d8->field_10, 14);
        }
        v8 = MpUtilsExportFunctions(v7);
        v8->field_50(16, &ptr->field_10);
        sub_7ff28f29030(v2 ^ &v0);
        return;
    }
    else
    {
        sub_7ff28f29030(v2 ^ &v0);
        return;
    }
}


/* VA 0x7ff28f2544c, RVA 0x544c, CFG name sub_7ff28f2544c; exports: [] */
typedef struct struct_1 {
    struct struct_2 *field_0;
    unsigned int field_8;
    char padding_c[44];
    char field_38;
    char padding_39[15];
    unsigned long long field_48;
    unsigned long long field_50;
} struct_1;

typedef struct struct_4 {
    struct struct_5 *field_0;
    unsigned int field_8;
    char padding_c[44];
    char field_38;
    char padding_39[15];
    unsigned long long field_48;
    unsigned long long field_50;
} struct_4;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_5 {
    struct struct_3 *field_0;
} struct_5;

typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

typedef struct struct_3 {
    unsigned long long field_0;
} struct_3;

typedef struct struct_7 {
    unsigned long long field_0;
} struct_7;

typedef struct struct_6 {
    char padding_0[8];
    struct struct_7 *field_8;
} struct_6;

typedef struct struct_8 {
    struct struct_6 *field_0;
} struct_8;

extern char g_7ff28f219a0;
extern char g_7ff28f219b8;
extern struct_8 *g_7ff28f2d5f0;

unsigned int sub_7ff28f2544c(struct_1 **p)
{
    unsigned int v4;  // r12d
    struct_4 *ptr;  // rsi
    unsigned int v6;  // eax
    unsigned long long v0;  // [bp-0x38]
    struct_1 **v1;  // [bp+0x8]
    unsigned int v2;  // [bp+0x10]
    struct_4 *v3;  // [bp+0x18], Other Possible Types: unsigned long long

    v1 = p;
    v0 = 18446744073709551614;
    if (!p)
        return 2147500035;
    *(p) = NULL;
    v4 = 2147942414;
    v2 = 2147942414;
    v3 = 0;
    ptr = sub_7ff28f26bc4(88);
    if (ptr)
    {
        ptr->field_8 = 0;
        memset((struct struct_4 *)&ptr->padding_c[4], 0, 40);
        ptr->field_38 = 0;
        v3 = 0;
        ptr->field_48 = 0;
        ptr->field_50 = 0;
        ptr->field_0 = &g_7ff28f219a0;
        *((char **)&ptr->padding_39[7]) = &g_7ff28f219b8;
        g_7ff28f2d5f0->field_0->field_8(g_7ff28f2d5f0);
        v3 = ptr;
    }
    else
    {
        ptr = NULL;
        v3 = 0;
    }
    if (ptr)
    {
        v6 = sub_7ff28f23be4(&ptr->padding_c[4]);
        if (v6 >= 0)
            ptr->field_38 = 1;
        v4 = (0 <= v6 ? 0 : v6);
        if (v4)
        {
            ptr->field_0->field_0(ptr, 1, ptr->field_0);
            ptr = NULL;
        }
    }
    *(p) = ptr;
    return v4;
}


/* VA 0x7ff28f232ff, RVA 0x32ff, CFG name sub_7ff28f232ff; exports: [] */
void sub_7ff28f232ff(char a0, char *ptr8, unsigned long a2, unsigned long a3, char a4)
{
    void* p;  // rax
    unsigned long v4;  // cc_op
    unsigned long v13;  // 4358
    char *ptr9;  // rax
    char v15;  // 4109
    char *addr;  // rax
    char *ptr6;  // rax
    char *ptr10;  // rdx
    char v19;  // 4324
    char *ptr3;  // rax
    unsigned int *ptr11;  // rax
    char *ptr5;  // rax
    unsigned long v5;  // cc_dep1
    unsigned int *ptr12;  // rax
    char v24;  // al
    char *ptr13;  // rax
    char v26;  // 4244
    char *ptr4;  // rax
    unsigned long v6;  // cc_dep2
    unsigned long v7;  // cc_ndep
    unsigned long v8;  // 4259
    void* ptr7;  // rax
    char *ptr14;  // rbx
    void* ptr;  // rax
    char v12;  // 4253
    char *v0;  // [bp-0x117], Other Possible Types: void*
    unsigned long v1;  // [bp-0x42]

    *((unsigned int *)p) = *((int *)p) + 1;
    v8 = _ccall(v4, v5, v6, v7);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((unsigned int *)p) = *((int *)p) + (unsigned int)p;
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    v1 = &vvar_8{r56|8b};
    ptr7 = (unsigned int)p ^ *((int *)p);
    *((char *)ptr7) = *((char *)ptr7) + *((char *)&ptr14);
    ptr = (unsigned int)ptr7 ^ *((int *)ptr7);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *(ptr14) = *(ptr14) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)&ptr[51]) = (char)ptr[51] + *((char *)&ptr14);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    v12 = *((char *)ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    v13 = _ccall(8, 1, (unsigned long long)v12, (unsigned long long)*((char *)(void*)&ptr), v8);
    if ((char)v13)
    {
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)&ptr[51]) = (char)ptr[51] + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((unsigned int *)ptr) = *((int *)ptr) + (unsigned int)ptr;
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        ptr10 = (char *)_INSERT(ptr8, 1, *((char *)((void*)&ptr8 + 1)) + a0);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        v0 = &v1;
        v19 = *(0x33);
        ptr3 = (char *)_INSERT(ptr, 0, v19);
        *(ptr3) = *(ptr3) + v19;
        *(ptr3) = *(ptr3) + v19;
        *(ptr3) = *(ptr3) + v19;
        *(ptr3) = *(ptr3) + v19;
        *(ptr3) = *(ptr3) + v19;
        *(ptr3) = *(ptr3) + v19;
        *(ptr3) = *(ptr3) + v19;
        *(ptr3) = *(ptr3) + v19;
        *(ptr3) = *(ptr3) + v19;
        *(ptr10) = *(ptr10) + v19;
        *(ptr3) = *(ptr3) + v19;
        ptr11 = (unsigned int *)_INSERT(ptr3, 0, v19 + *((char *)((void*)&ptr3 + 1)));
        ptr5 = (unsigned int)ptr11 ^ *(ptr11);
        *(ptr5) = *(ptr5) + *((char *)&ptr5);
        *(ptr5) = *(ptr5) + *((char *)&ptr5);
        *(ptr5) = *(ptr5) + *((char *)&ptr5);
        *(ptr5) = *(ptr5) + *((char *)&ptr5);
        ptr12 = (unsigned int *)_INSERT(ptr5, 0, *((char *)&ptr5) + *((char *)((void*)&ptr14 + 1)));
        v24 = (char)ptr12 ^ (char)*(ptr12);
        ptr13 = (char *)_INSERT(v24, 0, v24 + *((char *)((void*)&ptr8 + 1)) + a0);
        v26 = *(ptr13);
        ptr4 = (char *)_INSERT(ptr13, 0, v24 + *((char *)((void*)&ptr8 + 1)) + a0 ^ v26);
        *(ptr4) = *(ptr4) + (v24 + *((char *)((void*)&ptr8 + 1)) + a0 ^ v26);
        *(ptr4) = *(ptr4) + (v24 + *((char *)((void*)&ptr8 + 1)) + a0 ^ v26);
        *(ptr4) = *(ptr4) + (v24 + *((char *)((void*)&ptr8 + 1)) + a0 ^ v26);
        *(ptr4) = *(ptr4) + (v24 + *((char *)((void*)&ptr8 + 1)) + a0 ^ v26);
        *(ptr4) = *(ptr4) + (v24 + *((char *)((void*)&ptr8 + 1)) + a0 ^ v26);
        *(ptr4) = *(ptr4) + (v24 + *((char *)((void*)&ptr8 + 1)) + a0 ^ v26);
        *(ptr4) = *(ptr4) + (v24 + *((char *)((void*)&ptr8 + 1)) + a0 ^ v26);
        *(ptr4) = *(ptr4) + (v24 + *((char *)((void*)&ptr8 + 1)) + a0 ^ v26);
        *(ptr4) = *(ptr4) + (v24 + *((char *)((void*)&ptr8 + 1)) + a0 ^ v26);
    }
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    v0 = ptr;
    ptr9 = (char *)_INSERT(ptr, 0, *((char *)&ptr) + *((char *)((void*)&ptr8 + 1)));
    v15 = *(ptr9);
    addr = (char *)_INSERT(ptr9, 0, *((char *)&ptr) + *((char *)((void*)&ptr8 + 1)) ^ v15);
    *(addr) = *(addr) + (*((char *)&ptr) + *((char *)((void*)&ptr8 + 1)) ^ v15);
    *(addr) = *(addr) + (*((char *)&ptr) + *((char *)((void*)&ptr8 + 1)) ^ v15);
    *(addr) = *(addr) + (*((char *)&ptr) + *((char *)((void*)&ptr8 + 1)) ^ v15);
    *(addr) = *(addr) + (*((char *)&ptr) + *((char *)((void*)&ptr8 + 1)) ^ v15);
    *(addr) = *(addr) + (*((char *)&ptr) + *((char *)((void*)&ptr8 + 1)) ^ v15);
    *(addr) = *(addr) + (*((char *)&ptr) + *((char *)((void*)&ptr8 + 1)) ^ v15);
    *(addr) = *(addr) + (*((char *)&ptr) + *((char *)((void*)&ptr8 + 1)) ^ v15);
    *(addr) = *(addr) + (*((char *)&ptr) + *((char *)((void*)&ptr8 + 1)) ^ v15);
    *(addr) = *(addr) + (*((char *)&ptr) + *((char *)((void*)&ptr8 + 1)) ^ v15);
    *(addr) = *(addr) + (*((char *)&ptr) + *((char *)((void*)&ptr8 + 1)) ^ v15);
    ptr6 = [D] syscall()();
    *(ptr8) = *(ptr8) + *((char *)&ptr6);
    *(ptr6) = *(ptr6) + *((char *)&ptr6);
    *(ptr6) = *(ptr6) + *((char *)&ptr6);
    *(ptr6) = *(ptr6) + *((char *)&ptr6);
}


/* VA 0x7ff28f255e0, RVA 0x55e0, CFG name sub_7ff28f255e0; exports: [] */
typedef struct struct_2 {
    char padding_0[24];
    struct struct_3 *field_18;
    char padding_20[8];
    unsigned long long field_28;
    unsigned int field_30;
} struct_2;

typedef struct struct_0 {
    char padding_0[80];
    struct struct_1 *field_50;
} struct_0;

typedef struct struct_3 {
    struct struct_0 *field_0;
} struct_3;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

unsigned long long sub_7ff28f255e0(struct_2 *ptr, unsigned long a1, void* a2, unsigned int flag, unsigned long a4, unsigned int *p)
{
    unsigned long long v1;  // rax
    unsigned int v2;  // eax
    unsigned int v3;  // edi
    unsigned long v4;  // rbp
    unsigned long long v5;  // r14
    unsigned long long v6;  // rsi
    unsigned long long v7;  // r12
    unsigned long v8;  // rbp
    unsigned int v9;  // eax
    unsigned long v10;  // rbp
    unsigned int v0;  // [bp+0x8]

    v1 = 0;
    if (!ptr->field_18 || !ptr->field_28)
        v1 = sub_7ff28f25a4c();
    if (!ptr->field_18)
        return v1;
    if (!ptr->field_28 || flag != 1)
        return ptr->field_18->field_0->field_50(ptr->field_18, a2, flag, p);
    v2 = lstrlenW(*((long long *)a2));
    v3 = ptr->field_30 - 1;
    v0 = v2;
    v4 = v3;
    if (v4 >= 0)
    {
        v5 = ptr->field_28;
        v6 = v4 * 16;
        v7 = v6 + v5 + 8;
        do
        {
            v8 = v4;
            v9 = v2;
            if (v9 == *((int *)v7))
            {
                if (memcmp(*((long long *)(v6 + v5)), *((long long *)a2), *((int *)(v6 + v5 + 8)) * 2))
                {
                    v9 = v0;
                }
                else
                {
                    *(p) = *((int *)(v5 + v3 * 16 + 12));
                    return 0;
                }
            }
            v2 = v9;
            v3 -= 1;
            v6 -= 16;
            v7 -= 16;
            v10 = v8 - 1;
            v4 = v10;
        } while (!((char)(v8 - 1 >> 63)));
    }
    return ptr->field_18->field_0->field_50(ptr->field_18, a2, flag, p);
}


/* VA 0x7ff28f25340, RVA 0x5340, CFG name sub_7ff28f25340; exports: [] */
typedef struct struct_1 {
    struct struct_2 *field_0;
    unsigned int field_8;
    char padding_c[44];
    char field_38;
    char padding_39[15];
    unsigned long long field_48;
    unsigned long long field_50;
} struct_1;

typedef struct struct_4 {
    struct struct_5 *field_0;
    unsigned int field_8;
    char padding_c[44];
    char field_38;
    char padding_39[15];
    unsigned long long field_48;
    unsigned long long field_50;
} struct_4;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_5 {
    struct struct_3 *field_0;
} struct_5;

typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

typedef struct struct_3 {
    unsigned long long field_0;
} struct_3;

typedef struct struct_7 {
    unsigned long long field_0;
} struct_7;

typedef struct struct_6 {
    char padding_0[8];
    struct struct_7 *field_8;
} struct_6;

typedef struct struct_8 {
    struct struct_6 *field_0;
} struct_8;

extern char g_7ff28f218f8;
extern char g_7ff28f21908;
extern struct_8 *g_7ff28f2d5f0;

unsigned int sub_7ff28f25340(struct_1 **p)
{
    unsigned int v5;  // r12d
    struct_4 *ptr;  // rsi
    unsigned int v7;  // eax
    unsigned long long v0;  // [bp-0x38]
    struct_1 **v1;  // [bp+0x8]
    unsigned int v2;  // [bp+0x10]
    struct_4 *v3;  // [bp+0x18], Other Possible Types: unsigned long long
    unsigned long long flag;  // [bp+0x20]

    v1 = p;
    v0 = 18446744073709551614;
    if (!p)
        return 2147500035;
    *(p) = NULL;
    v5 = 2147942414;
    v2 = 2147942414;
    v3 = 0;
    ptr = sub_7ff28f26bc4(88);
    if (ptr)
    {
        ptr->field_8 = 0;
        memset((struct struct_4 *)&ptr->padding_c[4], 0, 40);
        ptr->field_38 = 0;
        v3 = 0;
        ptr->field_48 = 0;
        flag = 0;
        ptr->field_50 = 0;
        ptr->field_0 = &g_7ff28f218f8;
        *((char **)&ptr->padding_39[7]) = &g_7ff28f21908;
        g_7ff28f2d5f0->field_0->field_8(g_7ff28f2d5f0);
        v3 = ptr;
    }
    else
    {
        ptr = NULL;
        v3 = 0;
    }
    if (ptr)
    {
        v7 = sub_7ff28f23be4(&ptr->padding_c[4]);
        if (v7 >= 0)
            ptr->field_38 = 1;
        v5 = (0 <= v7 ? 0 : v7);
        if (v5)
        {
            ptr->field_0->field_0(ptr, 1, ptr->field_0);
            ptr = NULL;
        }
    }
    *(p) = ptr;
    return v5;
}


/* VA 0x7ff28f28ad0, RVA 0x8ad0, CFG name sub_7ff28f28ad0; exports: [] */
typedef struct struct_0 {
    unsigned int field_0;
    char padding_4[4];
    unsigned long long field_8;
    unsigned long long field_10;
    char field_18;
    char padding_19[3];
    unsigned int field_1c;
    char padding_20[48];
    unsigned long long field_50;
    unsigned int field_58;
    unsigned int field_5c;
} struct_0;

typedef struct OSVERSIONINFOA {
    unsigned int dwOSVersionInfoSize;
    unsigned int dwMajorVersion;
    unsigned int dwMinorVersion;
    unsigned int dwBuildNumber;
    unsigned int dwPlatformId;
    CHAR szCSDVersion[128];
} OSVERSIONINFOA;

extern char g_7ff28f20000;
extern char g_7ff28f21430;
extern unsigned long long g_7ff28f2c100;
extern char g_7ff28f2d5ea;

void sub_7ff28f28ad0(struct_0 *ptr)
{
    char v0;  // [bp-0xd8]
    OSVERSIONINFOA v1;  // [bp-0xb8]
    unsigned long long v2;  // [bp-0x18]

    v2 = g_7ff28f2c100 ^ &v0;
    memset((struct struct_0 *)&ptr->padding_20[8], 0, 40);
    ptr->field_50 = 0;
    ptr->field_58 = 0;
    ptr->field_5c = 0;
    ptr->field_10 = &g_7ff28f20000;
    ptr->field_8 = &g_7ff28f20000;
    ptr->field_0 = 96;
    ptr->field_18 = 0;
    memset(&v1, 0, 148);
    v1 = (OSVERSIONINFOA)_INSERT(v1 CONCAT 0, 0, 148);
    GetVersionExA(&v1);
    if (v1.dwPlatformId == 2)
    {
        if (v1.dwMajorVersion >= 5)
            goto LABEL_7ff28f28b79;
    }
    else
    {
        if (v1.dwPlatformId == 1 && (v1.dwMajorVersion > 4 || v1.dwMajorVersion == 4 && v1.dwMinorVersion > 0))
        {
LABEL_7ff28f28b79:
            ptr->field_18 = 1;
        }
    }
    ptr->field_1c = 0x800;
    *((char **)&ptr->padding_20[0]) = &g_7ff28f21430;
    g_7ff28f2d5ea = (sub_7ff28f23be4(&ptr->padding_20[8]) < 0 ? 1 : g_7ff28f2d5ea);
    sub_7ff28f29030(v2 ^ &v0);
    return;
}


/* VA 0x7ff28f2700c, RVA 0x700c, CFG name sub_7ff28f2700c; exports: [] */
typedef struct struct_0 {
    struct struct_0 *field_0;
    struct struct_0 *field_8;
    unsigned long long field_10;
    unsigned long long field_18;
} struct_0;

extern char g_7ff28f2d599;
extern struct_0 g_7ff28f2d610;
extern unsigned long long g_7ff28f2d618;
extern unsigned int g_7ff28f2d620;

int sub_7ff28f2700c(void)
{
    int v1;  // esi
    struct_0 *cur;  // rdi
    unsigned long long *v3;  // rax
    unsigned long long *v4;  // rax
    unsigned long long *v5;  // rax

    v1 = 0;
    if (g_7ff28f2d599)
        return -2147024809;
    if (!((char)g_7ff28f2d620 & 1))
    {
        g_7ff28f2d618 = &g_7ff28f2d610.field_0;
        cur = &g_7ff28f2d610.field_0;
        g_7ff28f2d620 = g_7ff28f2d620 | 1;
        g_7ff28f2d610.field_0 = &g_7ff28f2d610.field_0;
    }
    else
    {
        cur = g_7ff28f2d610.field_0;
    }
    if (cur == &g_7ff28f2d610.field_0)
        return 1;
    g_7ff28f2d599 = 1;
    while (true)
    {
        if (cur != &g_7ff28f2d610.field_0 && cur)
        {
            v3 = (*((long long *)(MpUtilsExportFunctions() + 168)))();
            v1 = v3(cur->field_10)(cur);
            if (v1 < 0)
                goto LABEL_7ff28f270b5;
            cur = cur->field_0;
        }
        else
        {
            if (v1 >= 0)
                return 0;
            while (true)
            {
LABEL_7ff28f270b5:
                cur = cur->field_8;
                if (cur == &g_7ff28f2d610.field_0 || !cur)
                    break;
                v4 = (*((long long *)(MpUtilsExportFunctions() + 168)))();
                v5 = v4(cur->field_18);
                v5(cur);
            }
            for (; g_7ff28f2d610.field_0 != &g_7ff28f2d610.field_0; g_7ff28f2d610.field_0->field_8 = &g_7ff28f2d610.field_0)
            {
                g_7ff28f2d610.field_0 = g_7ff28f2d610.field_0->field_0;
            }
        }
    }
    g_7ff28f2d599 = 0;
    return v1;
}


/* VA 0x7ff28f24414, RVA 0x4414, CFG name sub_7ff28f24414; exports: [] */
typedef struct struct_1 {
    struct struct_2 *field_0;
    unsigned int field_8;
    char padding_c[44];
    char field_38;
    char padding_39[7];
    unsigned long long field_40;
} struct_1;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

extern char g_7ff28f21820;
extern char g_7ff28f21ac0;

unsigned int sub_7ff28f24414(unsigned long long a0, unsigned long long a1, unsigned long long *p)
{
    unsigned int v6;  // r12d
    struct_1 *ptr;  // rsi
    unsigned int v8;  // eax
    struct_1 *v0;  // [bp-0x48], Other Possible Types: unsigned long long
    unsigned long long v1;  // [bp-0x40]
    unsigned long long v2;  // [bp+0x8]
    unsigned long long v3;  // [bp+0x10]
    unsigned long long *v4;  // [bp+0x18]
    unsigned int v5;  // [bp+0x20]

    v4 = p;
    v3 = a1;
    v2 = a0;
    v1 = 18446744073709551614;
    if (!p)
        return 2147500035;
    *(p) = 0;
    v6 = 2147942414;
    v5 = 2147942414;
    v0 = 0;
    ptr = sub_7ff28f26bc4(72);
    if (ptr)
    {
        ptr->field_8 = 0;
        memset((struct struct_1 *)&ptr->padding_c[4], 0, 40);
        ptr->field_38 = 0;
        ptr->field_0 = &g_7ff28f21820;
    }
    else
    {
        ptr = NULL;
    }
    v0 = ptr;
    if (ptr)
    {
        ptr->field_40 = a0;
        v8 = sub_7ff28f23be4(&ptr->padding_c[4]);
        if (v8 >= 0)
            ptr->field_38 = 1;
        v6 = (0 <= v8 ? 0 : v8);
        if (v6 || (v6 = (unsigned int)(unsigned long long)ptr->field_0->field_0(ptr, a1, p), v6))
        {
            ptr->field_8 = 3221225473;
            ptr->field_0 = &g_7ff28f21ac0;
            if (ptr->field_38)
            {
                ptr->field_38 = 0;
                DeleteCriticalSection(&ptr->padding_c[4]);
            }
            free(ptr);
        }
    }
    return v6;
}


/* VA 0x7ff28f25fd0, RVA 0x5fd0, CFG name sub_7ff28f25fd0; exports: [] */
typedef struct struct_2 {
    unsigned short field_0;
    char padding_2[6];
    struct struct_0 *field_8;
} struct_2;

typedef struct struct_0 {
    char padding_0[16];
    struct struct_1 *field_10;
    unsigned int field_18;
} struct_0;

typedef struct struct_5 {
    char padding_0[16];
    struct struct_6 *field_10;
} struct_5;

typedef struct struct_1 {
    unsigned short field_0;
} struct_1;

typedef struct struct_6 {
    struct struct_3 *field_0;
} struct_6;

typedef struct struct_3 {
    char padding_0[16];
    struct struct_4 *field_10;
} struct_3;

typedef struct struct_4 {
    unsigned long long field_0;
} struct_4;

unsigned long long sub_7ff28f25fd0(struct_5 *a0, unsigned long long a1, unsigned long long a2, unsigned int flag, struct_2 *ptr)
{
    unsigned int v2;  // ecx
    unsigned int v3;  // ecx
    unsigned int v12;  // eax
    unsigned int v4;  // ecx
    unsigned int choice;  // ecx
    unsigned int v6;  // r8d
    struct_0 *p;  // rax
    unsigned long long v8;  // rdx
    unsigned short *v9;  // r9
    unsigned int v10;  // r8d
    unsigned short *v11;  // rdi
    unsigned long v0;  // [bp-0x18]

    if (!a1 || !a2)
        return 2147500035;
    v2 = ptr->field_0;
    v3 = v2 - 8;
    if (v2 != 8)
    {
        v4 = v3 - 11;
        if (v3 != 11)
        {
            choice = v4 - 8190;
            if (v4 != 8190)
            {
                if (choice == 1 && (v6 = choice + 2, flag == v6 && ptr->field_8))
                {
                    p = ptr->field_8;
                    v8 = ptr->field_8->field_18 * 2;
                    goto LABEL_7ff28f26036;
                }
            }
            else
            {
                if ((flag == 4 || flag == 3) && ptr->field_8)
                {
                    p = ptr->field_8;
                    v6 = -(0 < flag - 4) + 4;
                    v8 = ptr->field_8->field_18;
LABEL_7ff28f26036:
                    v9 = &p->field_10->field_0;
LABEL_7ff28f260ab:
                    if ((v8 & 4294967295) == v8)
                    {
                        *((unsigned int *)&v0) = v8;
                        v12 = a0->field_10->field_0->field_10(a0->field_10, a1, a2, v6, v0, v9);
                        if (v12 >= 0)
                            v12 = 0;
                        return v12;
                    }
                }
            }
        }
        else if (flag == 1)
        {
            v8 = flag + 3;
            v9 = &ptr->field_8;
            v6 = flag;
            goto LABEL_7ff28f260ab;
        }
    }
    else
    {
        v10 = 2;
        if (flag == 2 && (v9 = (unsigned short *)ptr->field_8, v9))
        {
            v11 = v9;
            do
            {
                if (false)
                    break;
            } while (*(v11));
            v8 = ~(18446744073709551615) * 2;
            v6 = v10;
            goto LABEL_7ff28f260ab;
        }
    }
    return 2147942487;
    return 2147500035;
}


/* VA 0x7ff28f23dc0, RVA 0x3dc0, CFG name sub_7ff28f23dc0; exports: [] */
typedef struct struct_2 {
    struct struct_0 *field_0;
    char padding_8[24];
    char field_20;
} struct_2;

typedef struct struct_0 {
    char padding_0[8];
    struct struct_1 *field_8;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_3 {
    char padding_0[16];
    unsigned int field_10;
    char padding_14[8];
    char field_1c;
} struct_3;

extern char g_7ff28f20000;
extern struct_3 *g_7ff28f2c1d8;

unsigned int sub_7ff28f23dc0(struct_2 *a0, unsigned long long *ptr, unsigned long long *p)
{
    unsigned long long v1;  // r8
    unsigned long long v2;  // r9
    unsigned long long v11;  // rcx
    unsigned long long v12;  // cc_dep2
    unsigned int v13;  // eax
    unsigned long v14;  // 4131
    unsigned long long v3;  // cc_dep2
    unsigned long long v4;  // r8
    unsigned int v5;  // eax
    unsigned long v6;  // 4131
    unsigned long long v7;  // r8
    unsigned long long v8;  // cc_dep2
    unsigned int v9;  // eax
    unsigned long v10;  // 4131

    if (!p)
        return 2147500035;
    *(p) = 0;
    if (!a0->field_20)
    {
        if (g_7ff28f2c1d8 == &g_7ff28f2c1d8 || !(g_7ff28f2c1d8->field_1c & 1))
            return 2147942405;
        sub_7ff28f23d08(*((long long *)&g_7ff28f2c1d8->field_10), 10);
        return 2147942405;
    }
    else
    {
        v1 = *(ptr);
        v2 = &g_7ff28f20000;
        v3 = 4628857133061948090;
        v4 = v1;
        if (v4 == 4628857133061948090 && !((v4 = ptr[1], v1 = v4, v3 = 11256589712218164893, v4 != 11256589712218164893)))
        {
            v5 = 0;
        }
        else
        {
            v6 = _ccall(15, 0, (unsigned long long)(char)(v1 < v3), (unsigned long long)(char)(v1 < v3));
            v5 = -(v1 < v3) + 1 - ((unsigned int)v6 & 1);
        }
        if (!v5)
        {
            a0->field_0->field_8();
            *(p) = -(NULL < &a0[1].padding_8[23]) & a0;
            return 0;
        }
        v7 = *(ptr);
        v8 = 5048128645958681936;
        if (*(ptr) == 5048128645958681936 && !((v7 = ptr[1], v8 = 3756374797384307131, ptr[1] != 3756374797384307131)))
        {
            v9 = 0;
        }
        else
        {
            v10 = _ccall(15, 0, (unsigned long long)(char)(v7 < v8), (unsigned long long)(char)(v7 < v8));
            v9 = -(v7 < v8) + 1 - ((unsigned int)v10 & 1);
        }
        if (!v9)
            return sub_7ff28f24e28(p);
        v11 = *(ptr);
        v12 = 4830525776824554393;
        if (*(ptr) == 4830525776824554393 && !((v11 = ptr[1], v12 = 961725249536025776, ptr[1] != 961725249536025776)))
        {
            v13 = 0;
        }
        else
        {
            v14 = _ccall(15, 0, (unsigned long long)(char)(v11 < v12), (unsigned long long)(char)(v11 < v12));
            v13 = -(v11 < v12) + 1 - ((unsigned int)v14 & 1);
        }
        return (!v13 ? (int)sub_7ff28f24f80(p) : 2147500034);
    }
}


/* VA 0x7ff28f26680, RVA 0x6680, CFG name sub_7ff28f26680; exports: [] */
typedef struct struct_1 {
    char padding_0[8];
    long long field_8;
    unsigned long long field_10;
} struct_1;

typedef struct struct_0 {
    char padding_0[16];
    long long field_10;
    char padding_18[4];
    char field_1c;
} struct_0;

extern unsigned long long g_7ff28f2c100;
extern struct_0 *g_7ff28f2c1d8;

void sub_7ff28f26680(struct_1 *ptr, void* a1)
{
    char v0;  // [bp-0x58]
    struct_1 *v1;  // [bp-0x38]
    unsigned long long flag;  // [bp-0x28]
    unsigned long long v3;  // [bp-0x28]
    char v4;  // [bp-0x20]
    unsigned long long v5;  // [bp-0x10]

    v5 = g_7ff28f2c100 ^ &v0;
    if (g_7ff28f2c1d8 != &g_7ff28f2c1d8 && (g_7ff28f2c1d8->field_1c & 8))
    {
        v1 = &ptr[2].field_10;
        sub_7ff28f26124(g_7ff28f2c1d8->field_10, 19);
    }
    if (!a1)
    {
        sub_7ff28f29030(v5 ^ &v0);
        return;
    }
    VariantInit(a1);
    if (ptr->field_10)
    {
        sub_7ff28f29030(v5 ^ &v0);
        return;
    }
    flag = 0;
    if (MpElevationHandleOpen(ptr->field_8, &v4, &flag) < 0)
    {
        if (flag)
            MpHandleClose(flag);
        sub_7ff28f29030(v5 ^ &v0);
        return;
    }
    else if (sub_7ff28f250f4(a1, &v4) < 0)
    {
        if (flag)
            MpHandleClose(flag);
        sub_7ff28f29030(v5 ^ &v0);
        return;
    }
    else
    {
        v3 = ptr->field_10;
        ptr->field_10 = flag;
        if (v3)
            MpHandleClose(v3);
        sub_7ff28f29030(v5 ^ &v0);
        return;
    }
}


/* VA 0x7ff28f29538, RVA 0x9538, CFG name sub_7ff28f29538; exports: [] */
typedef struct UNWIND_HISTORY_TABLE {
    unsigned int Count;
    Byte LocalHint;
    Byte GlobalHint;
    Byte Search;
    Byte Once;
    UIntPtr LowAddress;
    UIntPtr HighAddress;
    struct UNWIND_HISTORY_TABLE_ENTRY Entry[12];
} UNWIND_HISTORY_TABLE;

typedef struct IMAGE_RUNTIME_FUNCTION_ENTRY {
    unsigned int BeginAddress;
    unsigned int EndAddress;
    char Anonymous;
} IMAGE_RUNTIME_FUNCTION_ENTRY;

typedef struct FLOATING_SAVE_AREA {
    unsigned int ControlWord;
    unsigned int StatusWord;
    unsigned int TagWord;
    unsigned int ErrorOffset;
    unsigned int ErrorSelector;
    unsigned int DataOffset;
    unsigned int DataSelector;
    Byte RegisterArea[80];
    unsigned int Spare0;
} FLOATING_SAVE_AREA;

typedef struct CONTEXT {
    enum CONTEXT_FLAGS ContextFlags;
    unsigned int Dr0;
    unsigned int Dr1;
    unsigned int Dr2;
    unsigned int Dr3;
    unsigned int Dr6;
    unsigned int Dr7;
    FLOATING_SAVE_AREA FloatSave;
    unsigned int SegGs;
    unsigned int SegFs;
    unsigned int SegEs;
    unsigned int SegDs;
    unsigned int Edi;
    unsigned int Esi;
    unsigned int Ebx;
    unsigned int Edx;
    unsigned int Ecx;
    unsigned int Eax;
    unsigned int Ebp;
    unsigned int Eip;
    unsigned int SegCs;
    unsigned int EFlags;
    unsigned int Esp;
    unsigned int SegSs;
    Byte ExtendedRegisters[512];
} CONTEXT;

typedef struct EXCEPTION_RECORD {
    int ExceptionCode;
    unsigned int ExceptionFlags;
    void* ExceptionRecord;
    void* ExceptionAddress;
    unsigned int NumberParameters;
    char padding_1c[4];
    UIntPtr ExceptionInformation[15];
} EXCEPTION_RECORD;

typedef struct EXCEPTION_POINTERS {
    struct EXCEPTION_RECORD *ExceptionRecord;
    struct CONTEXT *ContextRecord;
} EXCEPTION_POINTERS;

extern EXCEPTION_POINTERS g_7ff28f214c8;
extern unsigned long long g_7ff28f2c100;
extern unsigned long long g_7ff28f2c108;
extern unsigned int g_7ff28f2cfe0;
extern unsigned int g_7ff28f2cfe4;
extern unsigned long long g_7ff28f2cff0;
extern char g_7ff28f2d080;
extern unsigned long long g_7ff28f2d100;
extern unsigned long long g_7ff28f2d118;
extern unsigned long long g_7ff28f2d178;

int sub_7ff28f29538(unsigned long a0)
{
    void* v0;  // [bp-0x48]
    unsigned long long v1;  // [bp-0x40]
    IMAGE_RUNTIME_FUNCTION_ENTRY *v2;  // [bp-0x38]
    unsigned long v3;  // [bp-0x30]
    unsigned long long v4;  // [bp-0x28]
    unsigned long v5;  // [bp-0x20]
    unsigned long v6;  // [bp-0x18]
    unsigned long v7;  // [bp+0x0]
    unsigned long v8;  // [bp+0x8]

    v8 = a0;
    RtlCaptureContext(&g_7ff28f2d080);
    v3 = g_7ff28f2d178;
    v2 = RtlLookupFunctionEntry(v3, &v4, NULL);
    if (v2)
    {
        RtlVirtualUnwind(UNW_FLAG_NHANDLER, v4, v3, v2, &g_7ff28f2d080, &v0, &v1, NULL);
    }
    else
    {
        g_7ff28f2d178 = v7;
        g_7ff28f2d118 = &v8;
    }
    g_7ff28f2cff0 = g_7ff28f2d178;
    g_7ff28f2d100 = v8;
    g_7ff28f2cfe0 = 3221226505;
    g_7ff28f2cfe4 = 1;
    v5 = g_7ff28f2c100;
    v6 = g_7ff28f2c108;
    SetUnhandledExceptionFilter(NULL);
    UnhandledExceptionFilter(&g_7ff28f214c8.ExceptionRecord);
    return TerminateProcess(GetCurrentProcess(), 3221226505);
}


/* VA 0x7ff28f25dc8, RVA 0x5dc8, CFG name sub_7ff28f25dc8; exports: [] */
typedef struct struct_0 {
    struct struct_1 *field_0;
    unsigned long long field_8;
    struct struct_2 *field_10;
} struct_0;

typedef struct struct_5 {
    struct struct_3 *field_0;
} struct_5;

typedef struct struct_3 {
    char padding_0[8];
    struct struct_4 *field_8;
} struct_3;

typedef struct struct_6 {
    char padding_0[8];
    struct struct_7 *field_8;
} struct_6;

typedef struct struct_1 {
    unsigned int field_0;
    unsigned int field_4;
    unsigned int field_8;
    unsigned int field_c;
} struct_1;

typedef struct struct_2 {
    unsigned long long field_0;
} struct_2;

typedef struct struct_4 {
    unsigned long long field_0;
} struct_4;

typedef struct struct_7 {
    unsigned long long field_0;
} struct_7;

unsigned int sub_7ff28f25dc8(unsigned long long a0, struct_0 *p, unsigned long a2, struct_5 **ptr)
{
    struct_0 *cur;  // rbx
    struct_6 **v2;  // rbx
    unsigned int v3[4];  // rcx
    unsigned int v4;  // r12d
    unsigned int v5;  // eax

    cur = p;
    if (!a0 || !p)
        return 2147942487;
    if (!ptr)
        return 2147500035;
    *(ptr) = NULL;
    if (!*((int *)a2) && !*((int *)(a2 + 4)) && *((int *)(a2 + 8)) == 192 && *((int *)(a2 + 12)) == 0x46000000)
    {
        v2 = a0 + p->field_8;
        *(v2)->field_8(v2);
        *(ptr) = v2;
        return 0;
    }
    if (!p->field_10)
        return 2147500034;
    do
    {
        v3 = cur->field_0;
        v4 = !v3;
        if (v4 || v3[0] == *((int *)a2) && v3[1] == *((int *)(a2 + 4)) && v3[2] == *((int *)(a2 + 8)) && v3[3] == *((int *)(a2 + 12)))
        {
            if (cur->field_10 != 0x1)
            {
                v5 = cur->field_10(a0, a2, ptr, cur->field_8);
                if (!v5 || !v4 && v5 < 0)
                    return v5;
            }
            else
            {
                v2 = a0 + cur->field_8;
                *(v2)->field_8(v2);
                *(ptr) = v2;
                return 0;
            }
        }
    } while ((cur += 24, cur->field_10));
    return 2147500034;
    return 2147942487;
}


/* VA 0x7ff28f24878, RVA 0x4878, CFG name sub_7ff28f24878; exports: [] */
typedef struct struct_5 {
    struct struct_6 *field_0;
    unsigned int field_8;
    char padding_c[44];
    char field_38;
    char padding_39[7];
    struct struct_7 *field_40;
    unsigned long long field_48;
    char padding_50[16];
    char field_60;
} struct_5;

typedef struct struct_6 {
    struct struct_3 *field_0;
} struct_6;

typedef struct struct_7 {
    struct struct_4 *field_0;
} struct_7;

typedef struct struct_3 {
    unsigned long long field_0;
} struct_3;

typedef struct struct_4 {
    unsigned long long field_0;
} struct_4;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_0 {
    char padding_0[8];
    struct struct_1 *field_8;
} struct_0;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

extern char g_7ff28f21850;
extern char g_7ff28f21868;
extern struct_2 *g_7ff28f2d5f0;

unsigned int sub_7ff28f24878(unsigned long a0, unsigned long long a1, unsigned long long *p)
{
    unsigned int v6;  // esi
    struct_5 *ptr;  // r12
    unsigned int v8;  // eax
    struct_5 *v0;  // [bp-0x38], Other Possible Types: unsigned long long
    unsigned long long v1;  // [bp-0x30]
    unsigned long long v3;  // [bp+0x10]
    unsigned long long *v4;  // [bp+0x18]
    unsigned int v5;  // [bp+0x20]

    v4 = p;
    v3 = a1;
    v1 = 18446744073709551614;
    if (!p)
        return 2147500035;
    *(p) = 0;
    v6 = 2147942414;
    v5 = 2147942414;
    v0 = 0;
    ptr = sub_7ff28f26bc4(104);
    if (ptr)
    {
        ptr->field_8 = 0;
        memset((struct struct_5 *)&ptr->padding_c[4], 0, 40);
        ptr->field_38 = 0;
        v0 = 0;
        ptr->field_48 = 0;
        ptr->field_60 = 0;
        ptr->field_0 = &g_7ff28f21850;
        ptr->field_40 = &g_7ff28f21868;
        g_7ff28f2d5f0->field_0->field_8(g_7ff28f2d5f0);
        v0 = ptr;
    }
    else
    {
        ptr = NULL;
        v0 = 0;
    }
    if (ptr)
    {
        v6 = sub_7ff28f23be4(&ptr->padding_c[4]);
        if (v6 >= 0)
            ptr->field_38 = 1;
        if (v6 >= 0)
        {
            v8 = sub_7ff28f23d68(ptr);
            v6 = (0 <= v8 ? 0 : v8);
        }
        if (v6 || (v6 = (unsigned int)(unsigned long long)ptr->field_40->field_0(ptr + 64, a1, p), v6))
            ptr->field_0->field_0(ptr, 1, ptr->field_0);
    }
    return v6;
}


/* VA 0x7ff28f23498, RVA 0x3498, CFG name sub_7ff28f23498; exports: [] */
typedef struct EVENT_TRACE_HEADER {
    unsigned short Size;
    char Anonymous1;
    char padding_3[1];
    char Anonymous2;
    char padding_5[3];
    unsigned int ThreadId;
    unsigned int ProcessId;
    long long TimeStamp;
    char Anonymous3;
    char padding_19[15];
    char Anonymous4;
} EVENT_TRACE_HEADER;

unsigned int sub_7ff28f23498(unsigned long long a0, unsigned long a1, unsigned long a2, unsigned short a3, void* a4)
{
    HLOCAL v7;  // rdi
    UIntPtr v8;  // rbx
    unsigned long long v9;  // rdx
    void* iter;  // rsi
    void* ptr;  // rax
    void* cur;  // r8
    void* idx;  // rax
    void* p;  // rax
    unsigned long v15;  // rcx
    unsigned long long i;  // rbp
    int v0;  // [bp-0xc8]
    char *v1;  // [bp-0x98]
    int v2;  // [bp-0x90]
    HLOCAL v3;  // [bp-0x88]
    unsigned int v4;  // [bp-0x80]
    unsigned short v6;  // [bp+0x20]

    v6 = a3;
    v7 = NULL;
    v8 = NULL;
    v9 = 0;
    *((unsigned long *)&(&v0)[24]) = a2;
    v1 = &v6;
    ptr = a4 - 8;
    *((unsigned int *)&(&v0)[44]) = 0x1a0000;
    *((char *)&(&v0)[4]) = 255;
    *((unsigned int *)&v2) = 2;
    cur = &v2;
    while (true)
    {
        idx = ptr;
        if (!(long long)idx[8])
            break;
        p = idx + 16;
        v15 = *((long long *)p);
        v8 = (char *)v8 + v15;
        if (v8 < v15)
            return 0;
        v9 += 1;
        cur += 16;
        ptr = p;
        if (v9 <= 7)
        {
            *((long long *)&cur[8]) = (long long)idx[8];
            *((unsigned int *)cur) = v15;
            ptr = p;
        }
    }
    if (v8 > 0x2000)
        return 0;
    if (v9 > 7)
    {
        v7 = LocalAlloc(GMEM_FIXED, v8);
        if (!v7)
            return 0;
        v3 = v7;
        v4 = (unsigned int)v8;
        for (i = 0; (long long)iter[8]; i += *((long long *)iter))
        {
            iter += 16;
            memcpy(v7 + i);
        }
        *((unsigned short *)&v0) = 80;
    }
    else
    {
        *((unsigned short *)&v0) = ((unsigned short)v9 + 4) * 16;
    }
    TraceEvent(a0, &v0);
    if (!v7)
        return 0;
    LocalFree(v7);
    return 0;
}


/* VA 0x7ff28f240b4, RVA 0x40b4, CFG name sub_7ff28f240b4; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    uint128_t field_10;
} struct_0;

extern unsigned long long g_7ff28f2c100;

void sub_7ff28f240b4(struct_0 *ptr, unsigned long a1)
{
    unsigned int v6;  // eax
    char v0;  // [bp-0x78]
    int v1;  // [bp-0x58]
    char v2;  // [bp-0x40]
    int v3;  // [bp-0x30], Other Possible Types: char
    unsigned long long v4;  // [bp-0x20]

    v4 = g_7ff28f2c100 ^ &v0;
    if (!a1)
    {
        sub_7ff28f29030(v4 ^ &v0);
        return;
    }
    VariantInit(a1);
    if ((*((long long *)(MpUtilsExportFunctions(a1) + 80)))(16, &v2) < 0)
    {
        sub_7ff28f29030(v4 ^ &v0);
        return;
    }
    else if ((int)sub_7ff28f27bdc(&v3, &v2) >= 0)
    {
        VariantInit(&v1);
        if (sub_7ff28f250f4(&v1, &v2) >= 0 && VariantClear(a1) >= 0)
        {
            v6 = memcpy_s(a1, 24, &v1, 24);
            if (v6)
            {
                if (v6 == 12)
                {
                    8792485018636();
                }
                else if (!(v6 != 22 && v6 != 34))
                {
                    8792485018636();
                }
                else if (v6 != 80)
                {
                    8792485018636();
                }
            }
            *((unsigned short *)&v1) = 0;
            *((void*)&ptr->field_10) = v3;
            VariantClear(&v1);
            sub_7ff28f29030(v4 ^ &v0);
            return;
        }
        VariantClear(&v1);
        sub_7ff28f29030(v4 ^ &v0);
        return;
    }
    else
    {
        sub_7ff28f29030(v4 ^ &v0);
        return;
    }
}


/* VA 0x7ff28f23ee0, RVA 0x3ee0, CFG name sub_7ff28f23ee0; exports: [] */
typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_0 {
    char padding_0[16];
    struct struct_1 *field_10;
} struct_0;

typedef struct Guid {
    unsigned int Data1;
    unsigned short Data2;
    unsigned short Data3;
    char Data4[8];
} Guid;

typedef struct struct_4 {
    struct struct_5 *field_0;
    char padding_8[8];
    struct struct_6 *field_10;
} struct_4;

typedef struct struct_7 {
    char padding_0[56];
    struct struct_8 *field_38;
} struct_7;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_5 {
    unsigned long long field_0;
} struct_5;

typedef struct struct_6 {
    unsigned long long field_0;
} struct_6;

typedef struct struct_8 {
    unsigned long long field_0;
} struct_8;

typedef struct struct_3 {
    char padding_0[16];
    unsigned int field_10;
    char padding_14[8];
    char field_1c;
} struct_3;

extern char g_7ff28f21620;
extern unsigned int g_7ff28f21808;
extern unsigned long long g_7ff28f2c100;
extern struct_3 *g_7ff28f2c1d8;

void sub_7ff28f23ee0(struct_7 **a0, PWSTR a1, struct_2 **ptr)
{
    unsigned int v10;  // eax
    struct_4 **p;  // rcx
    unsigned long v12;  // rdx
    struct_4 **v13;  // rcx
    struct_4 **v14;  // rcx
    char v0;  // [bp-0x68]
    struct_4 **flag6;  // [bp-0x48]
    unsigned long long flag4;  // [bp-0x40]
    struct_0 **flag5;  // [bp-0x40]
    Guid flag;  // [bp-0x38]
    unsigned int choice;  // [bp-0x34]
    unsigned int flag2;  // [bp-0x30]
    unsigned int flag3;  // [bp-0x2c]
    unsigned long long v8;  // [bp-0x28]

    v8 = g_7ff28f2c100 ^ &v0;
    if (a1 && ptr)
    {
        *(ptr) = NULL;
        flag = (Guid)0;
        choice = 0;
        flag2 = 0;
        flag3 = 0;
        v10 = IIDFromString(a1, &flag);
        if (v10 >= 0)
        {
            flag6 = NULL;
            p = flag6;
            if (*(a0)->field_38(a0, &flag, &flag6) < 0)
            {
                if (p)
                {
                    v12 = *(p);
                    *(p)->field_10();
                }
            }
            else
            {
                flag5 = NULL;
                if (*(p)->field_0(p, &g_7ff28f21620, &flag5) < 0)
                {
                    if (flag5)
                        *(flag5)->field_10(flag5, *(flag5));
                    v13 = flag6;
                    if (v13)
                        *(v13)->field_10(v13);
                }
                else
                {
                    v14 = flag6;
                    flag4 = 0;
                    *(ptr) = flag5;
                    if (v14)
                        *(v14)->field_10(v14);
                    sub_7ff28f29030(v8 ^ &v0);
                    return;
                }
            }
        }
        else if (g_7ff28f2c1d8 != &g_7ff28f2c1d8 && (g_7ff28f2c1d8->field_1c & 1))
        {
            sub_7ff28f23d2c(*((long long *)&g_7ff28f2c1d8->field_10), 11, &g_7ff28f21808, v10);
        }
        sub_7ff28f29030(v8 ^ &v0);
        return;
    }
    sub_7ff28f29030(v8 ^ &v0);
    return;
}


/* VA 0x7ff28f249b8, RVA 0x49b8, CFG name sub_7ff28f249b8; exports: [] */
typedef struct struct_3 {
    struct struct_0 *field_0;
    unsigned int field_8;
    char padding_c[20];
    unsigned long long field_20;
    char padding_28[40];
    char field_50;
    char padding_51[15];
    unsigned long long field_60;
    char padding_68[16];
    char field_78;
} struct_3;

typedef struct struct_0 {
    struct struct_1 *field_0;
    char padding_8[16];
    struct struct_2 *field_18;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_2 {
    unsigned long long field_0;
} struct_2;

typedef struct struct_5 {
    unsigned long long field_0;
} struct_5;

typedef struct struct_4 {
    char padding_0[8];
    struct struct_5 *field_8;
} struct_4;

typedef struct struct_6 {
    struct struct_4 *field_0;
} struct_6;

extern char g_7ff28f218d0;
extern char g_7ff28f21a10;
extern char g_7ff28f21a28;
extern struct_6 *g_7ff28f2d5f0;

int sub_7ff28f249b8(unsigned long a0, unsigned long long a1, unsigned long long *p)
{
    int v8;  // esi
    struct_3 *ptr;  // r12
    int v10;  // eax
    int v11;  // eax
    struct_3 *v0;  // [bp-0x58], Other Possible Types: unsigned long long
    unsigned long long v1;  // [bp-0x50]
    struct_3 *v2;  // [bp-0x48]
    unsigned long long flag;  // [bp-0x40]
    unsigned long long v5;  // [bp+0x10]
    unsigned long long *v6;  // [bp+0x18]
    unsigned int v7;  // [bp+0x20]

    v6 = p;
    v5 = a1;
    v1 = 18446744073709551614;
    if (!p)
        return -2147467261;
    *(p) = 0;
    v8 = -2147024882;
    v7 = 2147942414;
    v0 = 0;
    ptr = sub_7ff28f26bc4(128);
    v2 = ptr;
    if (ptr)
    {
        ptr->field_8 = 0;
        ptr->field_0 = &g_7ff28f218d0;
        memset((struct struct_3 *)&ptr->padding_28, 0, 40);
        ptr->field_50 = 0;
        flag = 0;
        ptr->field_60 = 0;
        ptr->field_78 = 0;
        *((char **)&ptr->padding_c[12]) = &g_7ff28f21a10;
        *((char **)&ptr->padding_51[7]) = &g_7ff28f21a28;
        ptr->field_20 = a0;
        g_7ff28f2d5f0->field_0->field_8(g_7ff28f2d5f0);
    }
    else
    {
        ptr = NULL;
    }
    v0 = ptr;
    if (ptr)
    {
        v10 = sub_7ff28f23be4(&ptr->padding_28);
        if (v10 >= 0)
            ptr->field_50 = 1;
        v8 = (0 <= v10 ? 0 : v10);
        if (v8 >= 0)
        {
            v11 = sub_7ff28f23d68(&ptr->padding_c[12]);
            v8 = (0 <= v11 ? 0 : v11);
        }
        if (v8 || (v8 = (int)(unsigned int)(unsigned long long)ptr->field_0->field_0(ptr, a1, p), v8))
            ptr->field_0->field_18(ptr, 1, ptr->field_0);
    }
    return v8;
}


/* VA 0x7ff28f24e28, RVA 0x4e28, CFG name sub_7ff28f24e28; exports: [] */
typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_0 {
    char padding_0[16];
    struct struct_1 *field_10;
} struct_0;

typedef struct struct_8 {
    char padding_0[64];
    struct struct_4 *field_40;
    long long field_48;
} struct_8;

typedef struct struct_1 {
    struct struct_2 *field_0;
    unsigned int field_8;
    char padding_c[44];
    char field_38;
    char padding_39[15];
    unsigned long long field_48;
    unsigned long long field_50;
} struct_1;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_4 {
    struct struct_5 *field_0;
    struct struct_6 *field_8;
    struct struct_7 *field_10;
} struct_4;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_5 {
    unsigned long long field_0;
} struct_5;

typedef struct struct_6 {
    unsigned long long field_0;
} struct_6;

typedef struct struct_7 {
    unsigned long long field_0;
} struct_7;

typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

typedef struct struct_3 {
    char padding_0[16];
    long long field_10;
    char padding_18[4];
    char field_1c;
} struct_3;

extern char g_7ff28f215c0;
extern struct_3 *g_7ff28f2c1d8;

int sub_7ff28f24e28(struct_2 **ptr)
{
    struct_8 *v6;  // rdi
    struct_8 *p;  // rbx
    unsigned int v8;  // eax
    unsigned int v9;  // ebx
    struct_8 *v0;  // [bp-0x48]
    unsigned long long v1;  // [bp-0x38]
    struct_0 **choice;  // [bp+0x8], Other Possible Types: unsigned long long
    struct_1 *v3;  // [bp+0x10]
    struct_8 *v4;  // [bp+0x18], Other Possible Types: unsigned long long
    unsigned long long flag;  // [bp+0x20]

    v1 = 18446744073709551614;
    *(ptr) = NULL;
    v6 = NULL;
    v4 = 0;
    p = NULL;
    flag = 0;
    v8 = sub_7ff28f25340(&v3);
    if (v8 >= 0)
    {
        p = v3;
        p->field_40->field_8(&p->field_40);
        v8 = 0;
    }
    if (v8 >= 0)
    {
        if (g_7ff28f2c1d8 != &g_7ff28f2c1d8 && (g_7ff28f2c1d8->field_1c & 8))
        {
            v0 = p;
            sub_7ff28f26124(g_7ff28f2c1d8->field_10, 10);
        }
        if (p->field_48)
        {
            MpHandleClose(p->field_48);
            p->field_48 = 0;
        }
        v8 = MpManagerOpen(0, (struct struct_8 *)&p->field_48);
        if (v8 < 0)
        {
            if (p)
                p->field_40->field_10(&p->field_40);
        }
        else
        {
            v6 = p;
            v4 = p;
            v8 = 0;
        }
    }
    else if (p)
    {
        p->field_40->field_10(&p->field_40);
    }
    if (v8 < 0)
    {
        if (!v6)
            return v8;
        v6->field_40->field_10(&v6->field_40, v6->field_40);
        return v8;
    }
    else
    {
        choice = NULL;
        v9 = v6->field_40->field_0(&v6->field_40, &g_7ff28f215c0, &choice);
        if (v9 >= 0)
        {
            choice = 0;
            *(ptr) = choice;
            v9 = 0;
        }
        else if (choice)
        {
            *(choice)->field_10(choice, *(choice));
        }
        v6->field_40->field_10(&v6->field_40);
        return v9;
    }
}


/* VA 0x7ff28f28498, RVA 0x8498, CFG name sub_7ff28f28498; exports: [] */
typedef struct struct_0 {
    char padding_0[2];
    unsigned short field_2;
} struct_0;

typedef struct struct_2 {
    char padding_0[2];
    unsigned short field_2;
} struct_2;

typedef struct struct_1 {
    char padding_0[2];
    unsigned short field_2;
} struct_1;

extern long long g_7ff28f21778;
extern void* g_7ff28f2c1d8;

unsigned int sub_7ff28f28498(struct_0 **ptr, struct_2 *a1, PSID a2)
{
    unsigned int v1;  // ebp
    struct_1 *v2;  // rax
    struct_1 *p;  // rbx
    struct_1 *v4;  // rcx
    unsigned int v5;  // edi
    struct_1 *v0;  // [bp+0x8]

    *(ptr) = NULL;
    v1 = GetLengthSid(a2) + (!a1 ? 8 : a1->field_2) + 12;
    v2 = MpAllocMemory(v1);
    p = v2;
    v0 = v2;
    if (!v2)
        return 2147942414;
    v4 = v2;
    if (a1)
    {
        memmove(v4, a1, a1->field_2);
        p->field_2 = v1;
    }
    else if (!InitializeAcl(v4, v1, ACL_REVISION))
    {
        v5 = sub_7ff28f27678();
        if (g_7ff28f2c1d8 != &g_7ff28f2c1d8 && ((char)g_7ff28f2c1d8[28] & 1))
            sub_7ff28f23d2c((long long)g_7ff28f2c1d8[16], 12, &g_7ff28f21778, v5);
        if (v5 < 0)
        {
            MpFreeMemory(p);
            return v5;
        }
    }
    if (!(int)AddAccessAllowedAceEx(p, ACL_REVISION, NO_INHERITANCE, 0x80000000, a2))
    {
        v5 = sub_7ff28f27678();
        if (g_7ff28f2c1d8 != &g_7ff28f2c1d8 && ((char)g_7ff28f2c1d8[28] & 1))
            sub_7ff28f26cc8((long long)g_7ff28f2c1d8[16], 13, &g_7ff28f21778, 1);
        if (v5 < 0)
        {
            MpFreeMemory(p);
            return v5;
        }
    }
    *(ptr) = p;
    return 0;
}


/* VA 0x7ff28f28dec, RVA 0x8dec, CFG name sub_7ff28f28dec; exports: [] */
typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

extern unsigned int g_7ff28f2c110;
extern char g_7ff28f2cfd8;
extern unsigned int g_7ff28f2cfdc;
extern struct_0 *g_7ff28f2d648;

unsigned int sub_7ff28f28dec(long long a0, unsigned int flag, long long a2)
{
    unsigned int v3;  // ebx
    unsigned int v0;  // [bp-0x138]
    long long v1;  // [bp+0x8]
    unsigned int v2;  // [bp+0x10]

    v2 = flag;
    v1 = a0;
    v3 = 1;
    v0 = 1;
    g_7ff28f2c110 = flag;
    if (!flag && *((int *)&g_7ff28f2cfd8) == flag)
    {
        v3 = 0;
        v0 = 0;
    }
    else
    {
        if (flag == 1 || flag == 2)
        {
            if (g_7ff28f2d648)
            {
                g_7ff28f2cfdc = 1;
                v3 = g_7ff28f2d648();
                v0 = v3;
            }
            if (v3)
            {
                v3 = sub_7ff28f28c14(a0, flag, a2);
                v0 = v3;
            }
            if (!v3)
            {
                g_7ff28f2c110 = 4294967295;
                return v3;
            }
        }
        v3 = sub_7ff28f2381c(a0, flag, a2);
        v0 = v3;
        if (flag == 1 && !v3)
        {
            sub_7ff28f2381c(a0, 0, 0);
            sub_7ff28f28c14(a0, 0, 0);
            if (g_7ff28f2d648)
                g_7ff28f2d648(a0, 0, 0);
        }
        if (!flag || flag == 3)
        {
            v3 = sub_7ff28f28c14(a0, flag, a2);
            v0 = v3;
            if (g_7ff28f2d648 && g_7ff28f2cfdc)
            {
                v3 = g_7ff28f2d648(a0, flag, a2);
                v0 = v3;
            }
        }
    }
    g_7ff28f2c110 = 4294967295;
    return v3;
}


/* VA 0x7ff28f24f80, RVA 0x4f80, CFG name sub_7ff28f24f80; exports: [] */
typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_0 {
    char padding_0[16];
    struct struct_1 *field_10;
} struct_0;

typedef struct struct_10 {
    char padding_0[64];
    struct struct_3 *field_40;
    unsigned long long field_48;
    struct struct_8 *field_50;
} struct_10;

typedef struct struct_1 {
    struct struct_2 *field_0;
    unsigned int field_8;
    char padding_c[44];
    char field_38;
    char padding_39[15];
    unsigned long long field_48;
    unsigned long long field_50;
} struct_1;

typedef struct struct_11 {
    char padding_0[8];
    unsigned int field_8;
} struct_11;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_3 {
    struct struct_4 *field_0;
    struct struct_5 *field_8;
    struct struct_6 *field_10;
} struct_3;

typedef struct struct_8 {
    struct struct_9 *field_0;
    unsigned int field_8;
} struct_8;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_4 {
    unsigned long long field_0;
} struct_4;

typedef struct struct_5 {
    unsigned long long field_0;
} struct_5;

typedef struct struct_6 {
    unsigned long long field_0;
} struct_6;

typedef struct struct_9 {
    struct struct_7 *field_0;
} struct_9;

typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

typedef struct struct_7 {
    unsigned long long field_0;
} struct_7;

extern char g_7ff28f215c0;

unsigned int sub_7ff28f24f80(struct_2 **ptr)
{
    struct_10 *v5;  // rdi
    struct_10 *addr;  // rbx
    unsigned int v7;  // eax
    struct_10 *p;  // rsi
    struct_11 *v9;  // rcx
    unsigned long long flag;  // rdx
    unsigned int v11;  // eax
    unsigned int v12;  // ebx
    unsigned long long v0;  // [bp-0x38]
    struct_0 **choice;  // [bp+0x8], Other Possible Types: unsigned long long
    struct_10 *v2;  // [bp+0x10]
    struct_10 *v3;  // [bp+0x18]
    struct_1 *v4;  // [bp+0x20]

    v0 = 18446744073709551614;
    *(ptr) = NULL;
    v5 = NULL;
    v3 = NULL;
    addr = NULL;
    v2 = NULL;
    v7 = sub_7ff28f2544c(&v4);
    if (v7 >= 0)
    {
        addr = v4;
        addr->field_40->field_8(&addr->field_40);
        v2 = addr;
        v7 = 0;
    }
    if (v7 >= 0)
    {
        if (addr->field_48)
        {
            MpConfigUninitialize();
            addr->field_48 = 0;
        }
        v7 = MpConfigInitialize();
        if (v7 >= 0)
        {
            addr->field_48 = 305419896;
            v7 = 0;
        }
        if (v7 >= 0)
        {
            p = &addr->field_50;
            v9 = *((long long *)&p->padding_0[0]);
            if (v9)
            {
                InterlockedExchangeAdd(&v9->field_8, 4294967295);
                if (v9->field_8 - 1 <= 0 && v9)
                {
                    flag = 1;
                    (*((long long *)&v9->padding_0))();
                }
                *((struct_11 **)&p->padding_0[0]) = NULL;
                v5 = v3;
                addr = v2;
            }
            v11 = sub_7ff28f282bc(p);
            v7 = (v11 < 0 ? v11 : 0);
        }
        if (v7 < 0)
        {
            if (addr)
                addr->field_40->field_10(&addr->field_40);
        }
        else
        {
            v5 = addr;
            v3 = addr;
            v7 = 0;
        }
    }
    else if (addr)
    {
        addr->field_40->field_10(&addr->field_40);
    }
    if (v7 < 0)
    {
        if (!v5)
            return v7;
        v5->field_40->field_10(&v5->field_40, v5->field_40);
        return v7;
    }
    else
    {
        choice = NULL;
        v12 = v5->field_40->field_0(&v5->field_40, &g_7ff28f215c0, &choice);
        if (v12 >= 0)
        {
            choice = 0;
            *(ptr) = choice;
            v12 = 0;
        }
        else if (choice)
        {
            *(choice)->field_10(choice, *(choice));
        }
        v5->field_40->field_10(&v5->field_40);
        return v12;
    }
}


/* VA 0x7ff28f2381c, RVA 0x381c, CFG name sub_7ff28f2381c; exports: [] */
typedef struct struct_0 {
    struct struct_0 *field_0;
} struct_0;

typedef struct Guid {
    unsigned int Data1;
    unsigned short Data2;
    unsigned short Data3;
    char Data4[8];
} Guid;

typedef struct TRACE_GUID_REGISTRATION {
    struct Guid *Guid;
    HANDLE RegHandle;
} TRACE_GUID_REGISTRATION;

typedef struct struct_1 {
    struct struct_2 *field_0;
    unsigned long long field_8;
} struct_1;

typedef struct struct_2 {
    struct struct_1 *field_0;
} struct_2;

extern char g_7ff28f21548;
extern struct_1 *g_7ff28f2c1d8;
extern struct_0 *g_7ff28f2d568;
extern unsigned long long g_7ff28f2d578;
extern char g_7ff28f2d580;
extern char g_7ff28f2d581;
extern unsigned short g_7ff28f2d582;
extern unsigned int g_7ff28f2d584;
extern Guid *g_7ff28f2d588;
extern char g_7ff28f2d5ea;
extern char g_7ff28f2d624;

unsigned int sub_7ff28f2381c(HMODULE a0, unsigned int flag)
{
    struct_0 **p;  // rdi
    Guid **v4;  // rsi
    unsigned int choice;  // eax
    struct_1 *ptr;  // rdi
    int v0;  // [bp-0x18], Other Possible Types: TRACE_GUID_REGISTRATION

    if (flag)
    {
        if (flag != 1)
            goto LABEL_7ff28f2396b;
        if (!DisableThreadLibraryCalls(a0))
            sub_7ff28f27678();
        sub_7ff28f235ec();
        p = &g_7ff28f2d568;
        g_7ff28f2d578 = 0;
        g_7ff28f2d568 = 0;
        g_7ff28f2d588 = &g_7ff28f21548;
        g_7ff28f2d580 = 1;
        g_7ff28f2d581 = 0;
        g_7ff28f2c1d8 = &g_7ff28f2d568;
        g_7ff28f2d582 = 0;
        g_7ff28f2d584 = 0;
        v4 = &g_7ff28f2d588;
        do
        {
            *((Guid **)&v0) = *(v4);
            v0.RegHandle = 0;
            RegisterTraceGuidsW(sub_7ff28f236f8, p, *(v4), 1, &v0, NULL, NULL, p + 1);
            p = *(p);
            v4 += 1;
        } while (p);
        if (!g_7ff28f2d624)
        {
            choice = sub_7ff28f2700c();
            if (choice < 0)
                return 0;
            if (choice == 1 || !(int)sub_7ff28f291d4())
            {
                g_7ff28f2d624 = 1;
            }
            else
            {
                sub_7ff28f27120();
                if (false)
                    return 0;
            }
        }
LABEL_7ff28f23970:
        if (g_7ff28f2d5ea)
            return 0;
    }
    else if (g_7ff28f2c1d8 != &g_7ff28f2c1d8)
    {
        for (ptr = g_7ff28f2c1d8; ptr; ptr = ptr->field_0)
        {
            if (ptr->field_8)
            {
                UnregisterTraceGuids(ptr->field_8);
                ptr->field_8 = 0;
            }
        }
        g_7ff28f2c1d8 = &g_7ff28f2c1d8;
LABEL_7ff28f2396b:
        if (flag == 1)
            goto LABEL_7ff28f23970;
    }
    return 1;
}


/* VA 0x7ff28f26950, RVA 0x6950, CFG name sub_7ff28f26950; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    unsigned int field_10;
    char padding_14[8];
    char field_1c;
} struct_0;

extern unsigned int g_7ff28f217f8;
extern struct_0 *g_7ff28f2c1d8;

unsigned int sub_7ff28f26950(unsigned long a0, long long a1)
{
    unsigned int v5;  // eax
    unsigned long v6;  // rcx
    unsigned long v7;  // rcx
    unsigned long ptr;  // rbx
    unsigned int v9;  // eax
    unsigned long choice;  // [bp-0x18]
    unsigned long flag2;  // [bp-0x10]
    unsigned int flag;  // [bp+0x18], Other Possible Types: unsigned long
    unsigned int v4;  // [bp+0x20]

    if (!wcschr(a0, 92) && !wcschr(a0, 47))
    {
        choice = 0;
        flag2 = 0;
        v5 = MpConfigOpen(L"Real-Time Protection", &flag2);
        v6 = flag2;
        v7 = v6;
        if (v5 >= 0)
        {
            flag = 0;
            v4 = 2;
            v5 = MpConfigGetValueAlloc(v6, L"LocalCopyDirectory", &v4, &flag, &choice, 0);
            v7 = flag2;
        }
        if (v7)
            MpConfigClose();
        if (v5 >= 0)
        {
            flag = 0;
            v5 = sub_7ff28f278a0(&flag, L"%s\\%s", choice, a0);
            if (v5 >= 0)
            {
                ptr = flag;
                v9 = sub_7ff28f275c8(ptr);
                if (v9 >= 0)
                {
                    v9 = sub_7ff28f286d0(ptr, a1, 0x80000000, 1);
                    if (v9 >= 0)
                    {
                        if (ptr)
                            free(ptr);
                        if (!choice)
                            return 0;
                        MpFreeMemory(choice);
                        return 0;
                    }
                }
                if (ptr)
                    free(ptr);
                if (!choice)
                    return v9;
                MpFreeMemory(choice);
                return v9;
            }
            else if (flag)
            {
                free(flag);
            }
        }
        if (choice)
            MpFreeMemory(choice);
    }
    else
    {
        v5 = 2147942487;
        if (g_7ff28f2c1d8 != &g_7ff28f2c1d8 && (g_7ff28f2c1d8->field_1c & 1))
            sub_7ff28f23d2c(*((long long *)&g_7ff28f2c1d8->field_10), 23, &g_7ff28f217f8, 2147942487);
    }
    return v5;
}


/* VA 0x7ff28f28074, RVA 0x8074, CFG name sub_7ff28f28074; exports: [] */
typedef struct struct_1 {
    struct struct_2 *field_0;
    unsigned int field_8;
    char padding_c[4];
    unsigned long long field_10;
    unsigned long long field_18;
} struct_1;

typedef struct CRITICAL_SECTION {
    struct CRITICAL_SECTION_DEBUG *DebugInfo;
    int LockCount;
    int RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    UIntPtr SpinCount;
} CRITICAL_SECTION;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct CRITICAL_SECTION_DEBUG {
    unsigned short Type;
    unsigned short CreatorBackTraceIndex;
    char padding_4[4];
    void* CriticalSection;
    LIST_ENTRY ProcessLocksList;
    unsigned int EntryCount;
    unsigned int ContentionCount;
    unsigned int Flags;
    unsigned short CreatorBackTraceIndexHigh;
    unsigned short Identifier;
} CRITICAL_SECTION_DEBUG;

typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

typedef struct LIST_ENTRY {
    void* Flink;
    void* Blink;
} LIST_ENTRY;

extern unsigned long long g_10;
extern unsigned long long g_18;

unsigned int sub_7ff28f28074(CRITICAL_SECTION *p, unsigned long a1, struct_1 **ptr)
{
    struct_1 *v1;  // rbx
    struct_1 *v2;  // rsi
    unsigned int v3;  // edi
    struct_1 *v4;  // rax
    struct_1 *addr;  // rbx
    unsigned int v6;  // eax
    struct_1 *v7;  // rbx
    struct_1 *flag;  // [bp+0x8]

    *(ptr) = NULL;
    EnterCriticalSection(&p->LockSemaphore);
    v1 = p[1].LockSemaphore;
    if (v1)
        InterlockedIncrement(&v1->field_8);
    LeaveCriticalSection(&p->LockSemaphore);
    if (v1)
    {
        if (!(int)_wcsicmp(a1, v1->field_18))
        {
            *(ptr) = v1;
            return 0;
        }
        InterlockedExchangeAdd(&v1->field_8, 4294967295);
        if (v1->field_8 + 4294967295 <= 0)
            v1->field_0->field_0(v1, 1);
    }
    v2 = NULL;
    flag = NULL;
    v3 = sub_7ff28f283a8(&flag);
    if (v3 < 0)
    {
        v4 = flag;
        if (v4 && !((InterlockedExchangeAdd(v4 + 8, 4294967295), v4 > NULL)))
            goto LABEL_7ff28f2812c;
    }
    else
    {
        addr = flag;
        if (addr->field_18)
        {
            free(addr->field_18);
            addr->field_18 = 0;
        }
        v3 = sub_7ff28f27a0c(&addr->field_18, a1);
        if (v3 >= 0)
        {
            if (addr->field_10)
            {
                MpConfigClose(addr->field_10);
                addr->field_10 = 0;
            }
            v6 = MpConfigOpen(a1, (struct struct_1 *)&addr->field_10);
            v3 = (v6 < 0 ? v6 : 0);
        }
        if (v3 >= 0)
        {
            v2 = addr;
            v3 = 0;
        }
        else if (addr && !((InterlockedExchangeAdd(addr + 8, 4294967295), addr > NULL)))
        {
LABEL_7ff28f2812c:
            flag->field_0->field_0(flag, 1);
        }
    }
    if (v3 < 0)
    {
        if (!v2)
            return v3;
        InterlockedExchangeAdd(&v2->field_8, 4294967295);
        if (v2->field_8 + 4294967295 <= 0)
            v2->field_0->field_0(v2, 1, v2->field_0);
        return v3;
    }
    else
    {
        if (v2)
            InterlockedIncrement(&v2->field_8);
        *(ptr) = v2;
        EnterCriticalSection(&p->LockSemaphore);
        v7 = p[1].LockSemaphore;
        p[1].LockSemaphore = v2;
        LeaveCriticalSection(&p->LockSemaphore);
        if (!v7)
            return 0;
        InterlockedExchangeAdd(&v7->field_8, 4294967295);
        if (v7->field_8 + 4294967295 <= 0)
            v7->field_0->field_0(v7, 1);
        return 0;
    }
}


/* VA 0x7ff28f27bdc, RVA 0x7bdc, CFG name sub_7ff28f27bdc; exports: [] */
typedef struct Guid {
    unsigned int Data1;
    unsigned short Data2;
    unsigned short Data3;
    char Data4[8];
} Guid;

extern unsigned long long g_7ff28f2c100;

void sub_7ff28f27bdc(uint128_t *ptr, unsigned long a1)
{
    unsigned long long i;  // rbx
    unsigned int v21;  // eax
    unsigned long v22;  // rcx
    unsigned long v23;  // rcx
    unsigned long long idx;  // rbx
    char v0;  // [bp-0xa8]
    unsigned int v1;  // [bp-0x78], Other Possible Types: unsigned long
    unsigned short v2;  // [bp-0x74]
    unsigned short v3;  // [bp-0x72]
    char v4;  // [bp-0x70]
    char v5;  // [bp-0x6f]
    char v6;  // [bp-0x6e]
    char v7;  // [bp-0x6d]
    char v8;  // [bp-0x6c]
    char v9;  // [bp-0x6b]
    char v10;  // [bp-0x6a]
    char v11;  // [bp-0x69]
    unsigned int flag;  // [bp-0x68]
    unsigned int v13;  // [bp-0x64]
    Guid v14;  // [bp-0x60], Other Possible Types: char
    char v15;  // [bp-0x50]
    int v16;  // [bp-0x38], Other Possible Types: char
    char v17;  // [bp-0x28]
    unsigned long long v18;  // [bp-0x18]

    v18 = g_7ff28f2c100 ^ &v0;
    v1 = 2713435244;
    v4 = 191;
    v2 = 39466;
    v5 = 180;
    v6 = 140;
    v7 = 212;
    v8 = 120;
    v3 = 18106;
    v9 = 134;
    v10 = 159;
    v11 = 153;
    memcpy(&v17, &v1, 16);
    i = 0;
    v13 = GetTickCount();
    flag = 0;
    v1 = 0;
    memset(&v15, 0, 20);
    v21 = (*((long long *)(MpClientUtilExportFunctions(&v15, 0, 20) + 24)))(&v17, 4, &v13, &flag, &v1);
    v22 = v1;
    v23 = v22;
    if (v21 >= 0)
    {
        if (v22 && flag >= 20)
        {
            memmove(&v15, v22, 20);
            v23 = v1;
        }
        else
        {
            v21 = 2147549183;
            v23 = v22;
        }
    }
    if (v23)
        MpFreeMemory();
    if (v21 < 0)
    {
        if (v21 != 2147550901 && v21 != 2147550906 && (v21 <= 2147550909 || v21 > 2147550911))
        {
            sub_7ff28f29030(v18 ^ &v0);
            return;
        }
        if (sub_7ff28f27af0(&v14) < 0)
        {
            sub_7ff28f29030(v18 ^ &v0);
            return;
        }
    }
    else
    {
        memcpy(&v14, &v15, 16);
    }
    do
    {
        idx = i + 1;
        *((long long *)&(&flag)[2 * idx]) = *((long long *)&(&flag)[2 * idx]) ^ *((long long *)(&v14 + a1 - &v14 + 8 * i));
        i = idx;
    } while (i < 2);
    v1 = 16;
    sub_7ff28f27aac(2, 16, &v14, &v1, &v16);
    *((void*)ptr) = v16;
    sub_7ff28f29030(v18 ^ &v0);
    return;
}


/* VA 0x7ff28f28c14, RVA 0x8c14, CFG name sub_7ff28f28c14; exports: [] */
typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

extern long long g_7ff28f213b0;
extern long long g_7ff28f213d8;
extern struct_0 *g_7ff28f213e0;
extern struct_0 *g_7ff28f213f0;
extern int g_7ff28f2cfd8;
extern unsigned int g_7ff28f2d628;
extern char g_7ff28f2d630;
extern void* g_7ff28f2d638;
extern void* g_7ff28f2d640;
extern struct_1 *g_7ff28f2d650;

unsigned int sub_7ff28f28c14(unsigned long a0, unsigned int flag, unsigned long a2)
{
    void* i;  // rsi
    unsigned int v2;  // ebp
    unsigned long v3;  // gs
    unsigned long long v4;  // 4101
    struct_0 **cur;  // rsi
    unsigned int v6;  // eax
    unsigned long v7;  // rcx

    if (!flag)
    {
        if (g_7ff28f2cfd8 > 0)
        {
            g_7ff28f2cfd8 = g_7ff28f2cfd8 - 1;
            while (InterlockedCompareExchange64(&g_7ff28f2d630, 1, 0))
            {
                Sleep(1000);
            }
            if (g_7ff28f2d628 != 2)
            {
                _amsg_exit(31);
                return 1;
            }
            if (g_7ff28f2d640)
            {
                for (i = g_7ff28f2d638 - 8; i >= g_7ff28f2d640; i -= 8)
                {
                    if (*((long long *)i))
                        (*((long long *)i))();
                }
                free(g_7ff28f2d640);
                g_7ff28f2d638 = 0;
                g_7ff28f2d640 = 0;
            }
            g_7ff28f2d628 = 0;
            InterlockedExchange64(&g_7ff28f2d630, 0);
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if (flag == 1)
        {
            v2 = 0;
            while (true)
            {
                v4 = InterlockedCompareExchange64(&g_7ff28f2d630, *((long long *)(*((long long *)(48 + v3)) + 8)), 0);
                if (!v4)
                    break;
                if ((0 == v4 ? 0 : v4) != *((long long *)(*((long long *)(48 + v3)) + 8)))
                {
                    Sleep(1000);
                }
                else
                {
                    v2 = 1;
                    break;
                }
            }
            if (g_7ff28f2d628)
            {
                _amsg_exit(31);
            }
            else
            {
                cur = &g_7ff28f213e0;
                g_7ff28f2d628 = 1;
                v6 = 0;
                do
                {
                    if (v6)
                        return 0;
                    v7 = *(cur);
                    if (v7)
                        v6 = v7(v7);
                    cur += 1;
                } while (cur < &g_7ff28f213f0);
                if (v6)
                    return 0;
                _initterm(&g_7ff28f213b0, &g_7ff28f213d8);
                g_7ff28f2d628 = 2;
            }
            if (!v2)
                InterlockedExchange64(&g_7ff28f2d630, 0);
            if (g_7ff28f2d650 && sub_7ff28f2941c(&g_7ff28f2d650))
                g_7ff28f2d650(a0, 2, a2);
            g_7ff28f2cfd8 = g_7ff28f2cfd8 + 1;
            return 1;
        }
        else
        {
            return 1;
        }
    }
}


/* VA 0x7ff28f26274, RVA 0x6274, CFG name sub_7ff28f26274; exports: [] */
typedef struct struct_0 {
    char padding_0[8];
    long long field_8;
} struct_0;

typedef struct struct_1 {
    char padding_0[8];
    long long field_8;
    char padding_10[48];
    unsigned int field_40;
    char padding_44[4];
    long long field_48;
    char padding_50[16];
    uint128_t field_60;
} struct_1;

extern unsigned int g_7ff28f217f8;
extern unsigned long long g_7ff28f2c100;
extern void* g_7ff28f2c1d8;

void sub_7ff28f26274(struct_0 *a0)
{
    unsigned long v7;  // rcx
    unsigned long v8;  // rcx
    char v9;  // r12b
    unsigned int choice;  // eax
    struct_1 *ptr;  // rbx
    unsigned long long v12;  // rbp
    unsigned long long v13;  // rsi
    unsigned long long v14[2];  // rdi
    unsigned int v15;  // eax
    char v0;  // [bp-0x88]
    struct_0 *v1;  // [bp-0x68]
    unsigned long flag;  // [bp-0x58]
    struct_1 *v3;  // [bp-0x50], Other Possible Types: unsigned long long
    int v4;  // [bp-0x48]
    unsigned long long v5;  // [bp-0x38]

    v5 = g_7ff28f2c100 ^ &v0;
    if (g_7ff28f2c1d8 != &g_7ff28f2c1d8 && ((char)g_7ff28f2c1d8[28] & 8))
    {
        v1 = a0 + 4;
        sub_7ff28f26124((long long)g_7ff28f2c1d8[16], 12);
    }
    flag = 0;
    v7 = flag;
    v8 = v7;
    if (MpThreatOpen(a0->field_8, 3, 0, &flag) >= 0)
    {
        v3 = NULL;
        v9 = 0;
        choice = MpThreatEnumerate(v7, &v3);
        if (choice >= 0)
        {
            do
            {
                if (choice == 1)
                {
                    if (v9)
                        break;
                    else
                        break;
                }
                ptr = v3;
                v4 = (int)ptr->field_60;
                if (ptr->field_8)
                    MpFreeMemory(ptr->field_8);
                if (ptr->field_48)
                {
                    v12 = 0;
                    if (ptr->field_40 > 0)
                    {
                        v13 = 0;
                        do
                        {
                            v14 = *((long long *)(v13 + ptr->field_48));
                            if (v14)
                            {
                                if (v14[0])
                                    MpFreeMemory(v14[0]);
                                if (v14[1])
                                    MpFreeMemory(v14[1]);
                                MpFreeMemory(v14);
                            }
                        } while ((v12 += 1, v13 += 8, (unsigned int)v12 < ptr->field_40));
                    }
                    MpFreeMemory(ptr->field_48);
                }
                MpFreeMemory(ptr);
                v3 = 0;
                v15 = MpQuarantineRequest(a0->field_8, &v4, 1, 0);
                if (v15 < 0)
                {
                    if (g_7ff28f2c1d8 != &g_7ff28f2c1d8 && (1 & (char)g_7ff28f2c1d8[28]))
                        sub_7ff28f23d2c((long long)g_7ff28f2c1d8[16], 13, &g_7ff28f217f8, v15);
                    v9 = 1;
                }
                v3 = NULL;
                choice = MpThreatEnumerate(flag, &v3);
            } while (choice >= 0);
        }
LABEL_7ff28f26427:
        v8 = flag;
        goto LABEL_7ff28f26427;
    }
    if (v8)
        MpHandleClose();
    sub_7ff28f29030(v5 ^ &v0);
    return;
}


/* VA 0x7ff28f273d4, RVA 0x73d4, CFG name sub_7ff28f273d4; exports: [] */
extern unsigned long long g_7ff28f2c100;

void sub_7ff28f273d4(char *addr)
{
    unsigned long p;  // rdi
    unsigned int v8;  // eax
    unsigned int v9;  // esi
    void* ptr;  // rbx
    unsigned long long v11;  // rsi
    unsigned long long v12;  // rdx
    unsigned long v13;  // rax
    unsigned long v14;  // rax
    unsigned long v16;  // rax
    char v0;  // [bp-0x278]
    unsigned long long v1;  // [bp-0x258]
    unsigned long flag;  // [bp-0x250]
    void* v3;  // [bp-0x248]
    char v4;  // [bp-0x238]
    unsigned long long v5;  // [bp-0x28]

    v5 = g_7ff28f2c100 ^ &v0;
    v1 = 260;
    p = 0;
    flag = 0;
    v8 = sub_7ff28f2730c(&v1, &v4);
    if (v8 >= 0)
    {
        v9 = sub_7ff28f27a0c(&flag, &v4);
LABEL_7ff28f2743c:
        p = flag;
        goto LABEL_7ff28f27562;
    }
    else
    {
        if (v8 == 2147942522)
            v8 = 0;
        if (v8 < 0)
            goto LABEL_7ff28f27567;
        ptr = NULL;
        v3 = NULL;
        v11 = v1 * 3 >> 1;
        if (v1 < v11)
        {
            do
            {
                v1 = v11;
                if (ptr)
                {
                    free(ptr);
                    ptr = NULL;
                    v3 = NULL;
                }
                v12 = v11 * 2;
                if (v12 >> 1 == v11)
                {
                    v9 = sub_7ff28f279d4(&v3, v12);
                    ptr = v3;
                    if (v9 < 0)
                        goto LABEL_7ff28f27554;
                    v9 = sub_7ff28f2730c(&v1, ptr);
                    if (v9 >= 0)
                    {
                        v9 = sub_7ff28f27a0c(&flag, ptr);
                        if (ptr)
                        {
                            free(ptr);
                            goto LABEL_7ff28f2743c;
                        }
                    }
                    if (v9 != 2147942522)
                        goto LABEL_7ff28f27554;
                }
                else
                {
                    v9 = 2147942487;
LABEL_7ff28f27554:
                    if (ptr)
                    {
                        free(ptr);
                        goto LABEL_7ff28f27562;
                    }
                }
            } while ((v11 = v1 * 3 >> 1, v1 < v11));
            if (ptr)
            {
                free(ptr);
                goto LABEL_7ff28f274fa;
            }
LABEL_7ff28f27562:
            if (v9 >= 0)
            {
                v13 = wcsrchr(p, 92);
                if (!v13)
                    v14 = p;
                else
                    v14 = v13 + 2;
                v16 = v14;
                *(addr) = !(int)_wcsicmp(L"dllhost.exe", v16);
                if (p)
                    free(p);
                sub_7ff28f29030(v5 ^ &v0);
                return;
            }
LABEL_7ff28f27567:
            if (p)
                free(p);
        }
        else
        {
LABEL_7ff28f274fa:
        }
        sub_7ff28f29030(v5 ^ &v0);
        return;
    }
}


/* VA 0x7ff28f276a8, RVA 0x76a8, CFG name sub_7ff28f276a8; exports: [] */
extern unsigned long long g_7ff28f2c100;

void sub_7ff28f276a8(void* p, long long a1, long long a2)
{
    unsigned long long v5;  // rbp
    unsigned long ptr;  // rdi
    unsigned long v14;  // rax
    unsigned long v15;  // cc_ndep
    unsigned long v16;  // 4114
    int v17;  // esi
    unsigned long long idx;  // r12
    unsigned int v19;  // eax
    unsigned long long v20;  // rax
    unsigned int v7;  // eax
    unsigned long v8;  // rax
    unsigned long long v9;  // rbx
    unsigned long long v10;  // rax
    unsigned long v11;  // 4118
    int v12;  // ebx
    int v13;  // ebx
    char v0;  // [bp-0x288]
    char i;  // [bp-0x258]
    unsigned short flag;  // [bp-0x52]
    unsigned long long v3;  // [bp-0x48]

    v3 = g_7ff28f2c100 ^ &v0;
    *((unsigned long *)p) = 0;
    v5 = 260;
    ptr = 0;
    v7 = _vsnwprintf(&i, 259, a1, a2, a2, 0);
    if (v7 >= 0 && !((v8 = (unsigned long)(long long)(int)v7, v8 > 259)))
    {
        if (v8 == 259)
            flag = 0;
        do
        {
            if (false)
                break;
        } while (i);
        v9 = ~(18446744073709551615);
        free(NULL);
        v10 = 2 * v9;
        v11 = _ccall(0, 48, 2, v9, v15);
        if ((char)v11)
            v10 = 18446744073709551615;
        ptr = sub_7ff28f26c60(v10);
        if (!ptr)
        {
            v12 = -2147024882;
        }
        else
        {
            memmove(ptr, &i, v9 * 2);
            v12 = 0;
        }
LABEL_7ff28f27836:
        if (v12 < 0)
            goto LABEL_7ff28f27856;
        if (ptr)
        {
            v13 = 0;
            if (v13 >= 0)
            {
                *((unsigned long *)p) = ptr;
                sub_7ff28f29030(v3 ^ &v0);
                return;
            }
LABEL_7ff28f27856:
            if (ptr)
                free(ptr);
        }
        sub_7ff28f29030(v3 ^ &v0);
        return;
    }
    else
    {
        flag = 0;
        v13 = -2147024774;
        while (true)
        {
            v5 = v5 * 3 >> 1;
            if (v5 > 2147483647)
                break;
            free(ptr);
            v14 = 2 * v5;
            v16 = _ccall(0, 48, 2, v5, v15);
            if ((char)v16)
                v14 = 18446744073709551615;
            ptr = sub_7ff28f26c60(v14);
            if (!ptr)
            {
                v13 = -2147024882;
                break;
            }
            v17 = 0;
            if (!v5 || v5 > 2147483647)
                v17 = -2147024809;
            if (v17 >= 0)
            {
                v17 = 0;
                idx = v5 - 1;
                v19 = _vsnwprintf(ptr, idx, a1, a2, a2, 0);
                if (!(v19 >= 0 && !((v20 = (unsigned long long)(long long)(int)v19, v20 > idx))))
                {
                    v17 = -2147024774;
                }
                else if (!(v20 == idx))
                {
                    goto LABEL_7ff28f27822;
                }
                *((unsigned short *)(ptr + idx * 2)) = 0;
LABEL_7ff28f27822:
            }
            if (v17 != -2147024774)
            {
                v12 = (v17 < 0 ? v17 : 0);
                goto LABEL_7ff28f27836;
            }
        }
    }
}


/* VA 0x7ff28f25830, RVA 0x5830, CFG name sub_7ff28f25830; exports: [] */
typedef struct struct_0 {
    char padding_0[24];
    struct struct_1 *field_18;
    char padding_20[8];
    struct struct_2 *field_28;
    char padding_30[48];
    struct struct_3 *field_60;
    char padding_68[48];
    struct struct_4 *field_98;
    struct struct_5 *field_a0;
} struct_0;

typedef struct struct_6 {
    char padding_0[40];
    void* field_28;
    int field_30;
} struct_6;

typedef struct struct_7 {
    char padding_0[48];
    unsigned short field_30;
} struct_7;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_2 {
    unsigned long long field_0;
} struct_2;

typedef struct struct_3 {
    unsigned long long field_0;
} struct_3;

typedef struct struct_4 {
    unsigned long long field_0;
} struct_4;

typedef struct struct_5 {
    unsigned long long field_0;
} struct_5;

unsigned int sub_7ff28f25830(struct_6 *ptr, struct_0 **a1)
{
    void* v6;  // rsi
    unsigned long v7;  // rcx
    unsigned int v8;  // r13d
    unsigned long v9;  // rax
    unsigned long v10;  // cc_ndep
    unsigned long v11;  // 4121
    unsigned long v12;  // rax
    unsigned int v13;  // r14d
    void* cur;  // r13
    unsigned long long v0;  // [bp-0x48]
    void* p;  // [bp-0x40]
    struct_6 *v2;  // [bp+0x8]
    struct_0 **v3;  // [bp+0x10], Other Possible Types: unsigned long
    void* v4;  // [bp+0x18]
    char addr;  // [bp+0x20]

    v3 = a1;
    v2 = ptr;
    v0 = 18446744073709551614;
    if (*(a1)->field_18(a1, &addr) < 0)
        return 0;
    v6 = NULL;
    v4 = NULL;
    v7 = *((short *)(addr + 48));
    ptr->field_30 = v7;
    ptr->field_28 = NULL;
    if ((unsigned int)v7)
    {
        v8 = v7;
        v9 = 16 * v7;
        v11 = _ccall(0, 48, 16, v7, v10);
        if ((char)v11)
            v9 = 18446744073709551615;
        v12 = v9 + 8;
        if ((char)__CFADD__(v9, 8))
            v12 = 18446744073709551615;
        p = sub_7ff28f26bc4(v12);
        if (p)
        {
            *((unsigned int *)p) = v8;
            v6 = p + 8;
            sub_7ff28f2920c(v6, 16, v8, sub_7ff28f25818);
        }
        else
        {
            v6 = NULL;
        }
        v4 = v6;
        if (!v6)
        {
            *(a1)->field_98(a1, addr);
            return 2147942414;
        }
    }
    v13 = 0;
    if (ptr->field_30 > 0)
    {
        cur = v6;
        do
        {
            *((unsigned int *)&cur[8]) = 0;
            *((unsigned int *)&cur[12]) = 0;
            if (*(a1)->field_28(a1, v13, &v4) >= 0)
            {
                v3 = 0;
                if (*(a1)->field_60(a1, *((int *)v4), &v3, 0, 0, 0) >= 0)
                {
                    v3 = 0;
                    if (*((long long *)cur) != v3)
                    {
                        SysFreeString(*((long long *)cur));
                        *((unsigned long *)cur) = v3;
                    }
                    *((unsigned int *)&cur[8]) = SysStringLen(*((long long *)cur));
                    *((int *)&cur[12]) = *((int *)v4);
                }
                else
                {
                    v3 = v3;
                }
                *(a1)->field_a0(a1);
                SysFreeString(v3);
            }
        } while ((v13 += 1, cur += 16, v13 < ptr->field_30));
    }
    ptr->field_28 = v6;
    *(a1)->field_98(a1, addr);
    return 0;
}


/* VA 0x7ff28f26d5c, RVA 0x6d5c, CFG name sub_7ff28f26d5c; exports: [] */
typedef struct Guid {
    unsigned int Data1;
    unsigned short Data2;
    unsigned short Data3;
    char Data4[8];
} Guid;

typedef struct struct_0 {
    char padding_0[16];
    struct struct_1 *field_10;
    struct struct_2 *field_18;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_2 {
    unsigned long long field_0;
} struct_2;

extern long long g_7ff28f217e8;
extern Guid g_7ff28f21ba0;
extern unsigned long long g_7ff28f2c100;
extern void* g_7ff28f2c1d8;
extern char g_7ff28f2d60d;

void sub_7ff28f26d5c(void)
{
    unsigned long long v6;  // rsi
    unsigned int v7;  // eax
    unsigned int v8;  // edi
    void* v9;  // rcx
    struct_0 **v10;  // rcx
    unsigned int v11;  // eax
    struct_0 **v12;  // rcx
    struct_0 **v13;  // rcx
    char v0;  // [bp-0x58]
    unsigned long long flag;  // [bp-0x28]
    struct_0 **v2;  // [bp-0x28]
    Guid v3;  // [bp-0x20], Other Possible Types: int
    unsigned long long v4;  // [bp-0x10]

    v4 = g_7ff28f2c100 ^ &v0;
    v6 = 0;
    if (g_7ff28f2d60d || !((g_7ff28f2d60d = 1, (int)sub_7ff28f278c8())))
    {
LABEL_7ff28f26f78:
        sub_7ff28f29030(v4 ^ &v0);
        return;
    }
    v7 = CoInitializeEx(NULL, 0);
    if (v7 >= 0)
    {
        v6 = 305419896;
        v7 = 0;
    }
    else if (v7 != 2147549446 && g_7ff28f2c1d8 != &g_7ff28f2c1d8 && ((char)g_7ff28f2c1d8[28] & 1))
    {
        sub_7ff28f26cc8((long long)g_7ff28f2c1d8[16], 15, &g_7ff28f217e8, 0);
    }
    if (v7 == 2147549446)
        v7 = 0;
    if (v7 >= 0)
    {
        *((unsigned int *)&v3) = 843;
        *((unsigned short *)&(&v3)[4]) = 0;
        *((unsigned short *)&(&v3)[6]) = 0;
        *((char *)&(&v3)[8]) = 192;
        *((char *)&(&v3)[9]) = 0;
        *((char *)&(&v3)[10]) = 0;
        *((char *)&(&v3)[11]) = 0;
        *((char *)&(&v3)[12]) = 0;
        *((char *)&(&v3)[13]) = 0;
        *((char *)&(&v3)[14]) = 0;
        v3.Data4[7] = 70;
        flag = 0;
        v8 = CoCreateInstance(&v3, 0, CLSCTX_INPROC_SERVER, &g_7ff28f21ba0.Data1, &v2);
        if (v8 < 0)
        {
            v9 = g_7ff28f2c1d8;
            if (g_7ff28f2c1d8 == &g_7ff28f2c1d8 || !((char)g_7ff28f2c1d8[28] & 1))
                goto LABEL_7ff28f26ec1;
            sub_7ff28f26d10((long long)g_7ff28f2c1d8[16], 16, &g_7ff28f217e8, &v3);
        }
        else
        {
            v8 = 0;
        }
        v9 = g_7ff28f2c1d8;
LABEL_7ff28f26ec1:
        if (v8 < 0)
        {
            if (v9 != &g_7ff28f2c1d8 && ((char)v9[28] & 1))
                sub_7ff28f23d2c((long long)v9[16], 10, &g_7ff28f217e8, v8);
            v10 = v2;
            if (v10)
                *(v10)->field_10(v10, *(v10));
        }
        else
        {
            v11 = *(v2)->field_18(v2, 1, 1);
            if (v11 < 0)
            {
                if (g_7ff28f2c1d8 != &g_7ff28f2c1d8 && ((char)g_7ff28f2c1d8[28] & 1))
                    sub_7ff28f23d2c((long long)g_7ff28f2c1d8[16], 11, &g_7ff28f217e8, v11);
                v12 = v2;
                if (v12)
                    *(v12)->field_10(v12);
            }
            else
            {
                v13 = v2;
                if (v13)
                    *(v13)->field_10(v13);
                if (v6)
                    CoUninitialize();
                goto LABEL_7ff28f26f78;
            }
        }
    }
    if (v6)
        CoUninitialize();
    sub_7ff28f29030(v4 ^ &v0);
    return;
}


/* VA 0x7ff28f286d0, RVA 0x86d0, CFG name sub_7ff28f286d0; exports: [] */
typedef struct struct_0 {
    char padding_0[2];
    unsigned short field_2;
} struct_0;


unsigned int sub_7ff28f286d0(PWSTR a0, PSID a1)
{
    unsigned int v10;  // r12d

    return v10;
}


/* VA 0x7ff28f25a4c, RVA 0x5a4c, CFG name sub_7ff28f25a4c; exports: [] */
typedef struct struct_4 {
    unsigned long long field_0;
    struct struct_5 *field_8;
    unsigned short field_10;
    unsigned short field_12;
    char padding_14[4];
    struct struct_6 *field_18;
    char padding_20[8];
    unsigned long long field_28;
} struct_4;

typedef struct struct_0 {
    struct struct_1 *field_0;
    struct struct_2 *field_8;
    struct struct_3 *field_10;
} struct_0;

typedef struct struct_11 {
    char padding_0[16];
    struct struct_12 *field_10;
    char padding_18[24];
    struct struct_13 *field_30;
} struct_11;

typedef struct struct_7 {
    struct struct_8 *field_0;
    struct struct_9 *field_8;
    struct struct_10 *field_10;
} struct_7;

typedef struct struct_24 {
    struct struct_25 *field_0;
    char padding_8[8];
    struct struct_26 *field_10;
} struct_24;

typedef struct struct_14 {
    char padding_0[16];
    struct struct_15 *field_10;
} struct_14;

typedef struct struct_18 {
    struct struct_16 *field_0;
} struct_18;

typedef struct struct_19 {
    char padding_0[16];
    struct struct_20 *field_10;
} struct_19;

typedef struct struct_23 {
    struct struct_21 *field_0;
} struct_23;

typedef struct struct_27 {
    char padding_0[16];
    struct struct_28 *field_10;
} struct_27;

typedef struct struct_5 {
    unsigned int field_0;
    unsigned int field_4;
    unsigned int field_8;
    unsigned int field_c;
} struct_5;

typedef struct struct_6 {
    struct struct_0 *field_0;
} struct_6;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_2 {
    unsigned long long field_0;
} struct_2;

typedef struct struct_3 {
    unsigned long long field_0;
} struct_3;

typedef struct struct_12 {
    unsigned long long field_0;
} struct_12;

typedef struct struct_13 {
    unsigned long long field_0;
} struct_13;

typedef struct struct_8 {
    unsigned long long field_0;
} struct_8;

typedef struct struct_9 {
    unsigned long long field_0;
} struct_9;

typedef struct struct_10 {
    unsigned long long field_0;
} struct_10;

typedef struct struct_25 {
    unsigned long long field_0;
} struct_25;

typedef struct struct_26 {
    unsigned long long field_0;
} struct_26;

typedef struct struct_15 {
    unsigned long long field_0;
} struct_15;

typedef struct struct_16 {
    char padding_0[16];
    struct struct_17 *field_10;
} struct_16;

typedef struct struct_20 {
    unsigned long long field_0;
} struct_20;

typedef struct struct_21 {
    char padding_0[16];
    struct struct_22 *field_10;
} struct_21;

typedef struct struct_28 {
    unsigned long long field_0;
} struct_28;

typedef struct struct_17 {
    unsigned long long field_0;
} struct_17;

typedef struct struct_22 {
    unsigned long long field_0;
} struct_22;

extern struct_19 g_7ff28f215c0;
extern char g_7ff28f21af8;
extern char g_7ff28f21b08;
extern unsigned long long g_7ff28f2c100;
extern HMODULE g_7ff28f2cec8;
extern unsigned long long g_7ff28f2d5f0;
extern char g_7ff28f2d5f8;
extern char g_7ff28f2d5fc;
extern char g_7ff28f2d600;
extern char g_7ff28f2d604;

void sub_7ff28f25a4c(struct_4 *ptr, unsigned int a1)
{
    unsigned int v13[4];  // rcx
    unsigned int v14;  // eax
    struct_18 **v23;  // r8
    struct_19 *v24;  // rdx
    struct_23 **v25;  // r8
    struct_19 *v26;  // rdx
    struct_14 **p;  // rax
    char v28;  // bpl
    struct_24 **v29;  // rdi
    struct_24 **v30;  // rdi
    struct_7 **v31;  // rbp
    unsigned int v15;  // esi
    struct_7 **v33;  // rcx
    struct_24 **v35;  // rcx
    struct_7 **v36;  // rcx
    unsigned long v16;  // r9
    struct_7 **v17;  // rcx
    struct_7 **v18;  // rcx
    struct_7 **v19;  // rcx
    struct_24 **v20;  // rdi
    struct_7 **v21;  // rcx
    struct_7 **v22;  // rcx
    char v0;  // [bp-0x2b8]
    struct_27 **v1;  // [bp-0x288], Other Possible Types: struct_7 **
    struct_24 **flag3;  // [bp-0x280]
    struct_11 **v3;  // [bp-0x278]
    struct_7 **flag4;  // [bp-0x270]
    struct_14 **v5;  // [bp-0x268]
    struct_14 **flag2;  // [bp-0x260]
    unsigned long long v7;  // [bp-0x258]
    unsigned long v8;  // [bp-0x250]
    char flag;  // [bp-0x248]
    char v10;  // [bp-0x238]
    unsigned long long v11;  // [bp-0x28]

    v7 = 18446744073709551614;
    v11 = g_7ff28f2c100 ^ &v0;
    if (ptr->field_18 && ptr->field_28)
    {
        sub_7ff28f29030(v11 ^ &v0);
        return;
    }
    v8 = g_7ff28f2d5f0 + 24;
    EnterCriticalSection(v8);
    flag = 1;
    if (!ptr->field_18)
    {
        v3 = NULL;
        v13 = ptr->field_8;
        if (*((int *)&g_7ff28f2d5f8) == v13[0] && *((int *)&g_7ff28f2d5fc) == v13[1] && *((int *)&g_7ff28f2d600) == v13[2] && *((int *)&g_7ff28f2d604) == v13[3] && ptr->field_10 == 65535 && ptr->field_12 == 65535)
        {
            v14 = GetModuleFileNameW(g_7ff28f2cec8, &v10, 260);
            if (!v14 || v14 == 260)
                goto LABEL_7ff28f25d16;
            v15 = LoadTypeLib(&v10, &v3);
        }
        else
        {
            v16 = a1;
            v15 = LoadRegTypeLib(v13, ptr->field_10, ptr->field_12, v16, &v3);
        }
        if (v15 >= 0)
        {
            flag4 = NULL;
            if (*(v3)->field_30(v3, ptr->field_0, &flag4) >= 0)
            {
                v17 = flag4;
                v1 = v17;
                v18 = v17;
                if (v18)
                {
                    *(v17)->field_8(v17);
                    v18 = flag4;
                }
                v19 = v18;
                flag3 = NULL;
                if (*(v19)->field_0(v19, &g_7ff28f21af8, &flag3) >= 0)
                {
                    v20 = flag3;
                    v21 = v1;
                    if (!v21)
                    {
                        v22 = v21;
                        if (!v20)
                            goto LABEL_7ff28f25ca7;
LABEL_7ff28f25c5c:
                        v28 = 0;
                        v29 = v20;
                        v22 = v21;
                    }
                    else
                    {
                        if (!v20)
                            goto LABEL_7ff28f25c5c;
                        v5 = NULL;
                        flag2 = NULL;
                        v23 = &v5;
                        v24 = &g_7ff28f215c0.padding_0[0];
                        *(v21)->field_0();
                        v25 = &flag2;
                        v26 = &g_7ff28f215c0.padding_0[0];
                        *(v20)->field_0(v20, &g_7ff28f215c0.padding_0[0], &flag2);
                        p = flag2;
                        v28 = v5 == p;
                        if (p)
                        {
                            v26 = *(p);
                            v26->field_10(p, v26);
                        }
                        if (v5)
                            *(v5)->field_10();
                        v29 = flag3;
                        v22 = v1;
                    }
                    v30 = v29;
                    if (!v28)
                    {
                        v31 = v22;
                        v1 = NULL;
                        v33 = NULL;
                        if (v30)
                        {
                            *(v30)->field_0(v30, &g_7ff28f21b08, &v1);
                            v33 = v1;
                        }
                        v22 = v33;
                        if (v31)
                        {
                            *(v31)->field_10(v31);
                            v22 = v1;
                        }
                    }
                }
                else
                {
                    v22 = v1;
                }
LABEL_7ff28f25ca7:
                v1 = NULL;
                ptr->field_18 = v22;
                sub_7ff28f256fc(g_7ff28f2d5f0 + 8 & -(0 < g_7ff28f2d5f0), sub_7ff28f257b0, ptr);
                v35 = flag3;
                if (v35)
                    *(v35)->field_10(v35);
                if (v1)
                    *(v1)->field_10(v1);
            }
            *(v3)->field_10(v3);
            v36 = flag4;
            if (v36)
                *(v36)->field_10(v36);
        }
    }
LABEL_7ff28f25d16:
    if (ptr->field_18 && !ptr->field_28)
        sub_7ff28f25830(ptr, ptr->field_18);
    LeaveCriticalSection(v8);
    sub_7ff28f29030(v11 ^ &v0);
    return;
}


