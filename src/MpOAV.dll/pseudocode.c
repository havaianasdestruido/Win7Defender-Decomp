/* AUTOMATED ANGR PSEUDOCODE, NOT ORIGINAL SOURCE; NOT A BUILD TARGET.
 * Types, signatures, locals, calling conventions and control flow are inferred, unverified.
 * Input SHA256: b2913b2234cc75b1e57517a0ad0ca229c258a670f44c579e5260913ac5fb0269; addresses use preferred image base.
 * Per-function omissions and errors: analysis/report/modules/MpOAV.dll/function-coverage.json
 */

/* VA 0x7ff29103ff4, RVA 0x3ff4, CFG name DllUnregisterServer; exports: ['DllRegisterServer', 'DllUnregisterServer'] */
unsigned int DllUnregisterServer(void)
{
    return 2147942450;
}


/* VA 0x7ff29103ea8, RVA 0x3ea8, CFG name DllCanUnloadNow; exports: ['DllCanUnloadNow'] */
typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_0 {
    char padding_0[24];
    struct struct_1 *field_18;
} struct_0;

extern struct_0 *g_7ff2910d210;

long long DllCanUnloadNow(void)
{
    return g_7ff2910d210->field_18(&g_7ff2910d210);
}


/* VA 0x7ff29103ed4, RVA 0x3ed4, CFG name DllGetClassObject; exports: ['DllGetClassObject'] */
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

extern char g_7ff291017c0;
extern unsigned int g_7ff2910ca30;
extern struct_6 *g_7ff2910ca40;
extern char g_7ff2910ca48;
extern CRITICAL_SECTION g_7ff2910ca50;

unsigned int DllGetClassObject(unsigned long a0, unsigned long a1, unsigned long long ptr)
{
    struct_2 **cur;  // rcx
    unsigned int v2;  // ebx
    struct_2 *p;  // rsi
    unsigned int v4[4];  // rdx

    if (!g_7ff2910ca30)
    {
        return 2147549183;
    }
    else if (!ptr)
    {
        return 2147500035;
    }
    else
    {
        *((unsigned long long *)ptr) = 0;
        cur = g_7ff2910ca40;
        v2 = 0;
        while (true)
        {
            if (cur < *((long long *)&g_7ff2910ca48))
            {
                p = *(cur);
                if (!p || !p->field_10 || (v4 = (unsigned int [4])p->field_0, *((int *)a0) != v4[0] || *((int *)(a0 + 4)) != v4[1] || *((int *)(a0 + 8)) != v4[2] || *((int *)(a0 + 12)) != v4[3]))
                {
                    cur += 1;
                }
                else
                {
                    if (!p->field_20)
                    {
                        EnterCriticalSection(&g_7ff2910ca50.DebugInfo);
                        if (!p->field_20)
                            v2 = p->field_10(p->field_18, &g_7ff291017c0, &p->field_20);
                        LeaveCriticalSection(&g_7ff2910ca50.DebugInfo);
                    }
                    if (p->field_20)
                        v2 = p->field_20->field_0->field_0(p->field_20, a1, ptr);
                    if (*((long long *)ptr))
                    {
                        return v2;
                    }
                    else if (v2)
                    {
                        return v2;
                    }
                    goto LABEL_7ff29103fcc;
                }
            }
            else
            {
LABEL_7ff29103fcc:
                break;
            }
        }
        return 2147746065;
    }
}


/* VA 0x7ff29108b94, RVA 0x8b94, CFG name _start; exports: [] */
void _start(long long a0, unsigned int flag, long long a2)
{
    if (flag == 1)
        _security_init_cookie();
    sub_7ff291089a0(a0, flag, a2);
    return;
}


/* VA 0x7ff29101395, RVA 0x1395, CFG name sub_7ff29101395; exports: [] */
void sub_7ff29101395(void)
{
    [D] Unsupported jumpkind Ijk_Privileged at address 8792486974357()
}


/* VA 0x7ff29101995, RVA 0x1995, CFG name sub_7ff29101995; exports: [] */
void sub_7ff29101995(void)
{
    [D] Unsupported jumpkind Ijk_SigTRAP at address 8792486975893()
}


/* VA 0x7ff29102127, RVA 0x2127, CFG name sub_7ff29102127; exports: [] */
void sub_7ff29102127(void)
{
    [D] Unsupported jumpkind Ijk_Privileged at address 8792486977831()
}


/* VA 0x7ff2910a4f8, RVA 0xa4f8, CFG name sub_7ff2910a4f8; exports: [] */
void sub_7ff2910a4f8(void)
{
    [D] Unsupported jumpkind Ijk_Privileged at address 8792487011576()
}


/* VA 0x7ff291015a3, RVA 0x15a3, CFG name sub_7ff291015a3; exports: [] */
void sub_7ff291015a3(void)
{
    unsigned long v1;  // cc_op
    unsigned long v2;  // cc_dep1
    unsigned long v3;  // cc_dep2
    unsigned long v4;  // cc_ndep
    unsigned long v5;  // 4101

    v5 = _ccall(2, v1, v2, v3, v4);
    if ((char)v5)
        goto LABEL_0x7ff2910154f;
    else
        goto LABEL_0x7ff291015a5;
}


/* VA 0x7ff29101d57, RVA 0x1d57, CFG name sub_7ff29101d57; exports: [] */
void sub_7ff29101d57(unsigned int a0)
{
    __fastfail(a0); /* do not return */
}


/* VA 0x7ff291021a0, RVA 0x21a0, CFG name sub_7ff291021a0; exports: [] */
void sub_7ff291021a0(void)
{
    [D] Unsupported jumpkind Ijk_Privileged at address 8792486977952()
}


/* VA 0x7ff291021d2, RVA 0x21d2, CFG name sub_7ff291021d2; exports: [] */
void sub_7ff291021d2(void)
{
    char *ptr;  // rdi
    char *v2;  // rsi

    *(ptr) = *(v2);
    return;
}


/* VA 0x7ff291021d4, RVA 0x21d4, CFG name sub_7ff291021d4; exports: [] */
void sub_7ff291021d4(void)
{
    char *ptr;  // rsi

    *(ptr) = *(ptr) * 2;
}


/* VA 0x7ff29108ec6, RVA 0x8ec6, CFG name sub_7ff29108ec6; exports: [] */
int sub_7ff29108ec6(void)
{
}


/* VA 0x7ff29109ea7, RVA 0x9ea7, CFG name sub_7ff29109ea7; exports: [] */
void sub_7ff29109ea7(unsigned long long *a0)
{
    goto *(a0);
}


/* VA 0x7ff2910a407, RVA 0xa407, CFG name sub_7ff2910a407; exports: [] */
void sub_7ff2910a407(unsigned long a0, unsigned long long *a1)
{
    goto *(a1);
}


/* VA 0x7ff2910a48b, RVA 0xa48b, CFG name sub_7ff2910a48b; exports: [] */
void sub_7ff2910a48b(unsigned long a0, unsigned long long *a1)
{
    goto *(a1);
}


/* VA 0x7ff2910a54b, RVA 0xa54b, CFG name sub_7ff2910a54b; exports: [] */
void sub_7ff2910a54b(void)
{
    unsigned long v1;  // rdi

    goto v1;
}


/* VA 0x7ff29101476, RVA 0x1476, CFG name sub_7ff29101476; exports: [] */
void sub_7ff29101476(void)
{
    return;
}


/* VA 0x7ff29101587, RVA 0x1587, CFG name sub_7ff29101587; exports: [] */
void sub_7ff29101587(void)
{
    return;
}


/* VA 0x7ff29101607, RVA 0x1607, CFG name sub_7ff29101607; exports: [] */
void sub_7ff29101607(void)
{
    unsigned long v1;  // cc_op
    unsigned long v2;  // cc_dep1
    unsigned long v3;  // cc_dep2
    unsigned long v4;  // cc_ndep
    unsigned long v5;  // 4101

    v5 = _ccall(0, v1, v2, v3, v4);
    if (!((char)v5))
        goto LABEL_0x7ff291015d8;
    [D] Unsupported jumpkind Ijk_Privileged at address 8792486974985()
}


/* VA 0x7ff2910167a, RVA 0x167a, CFG name sub_7ff2910167a; exports: [] */
void sub_7ff2910167a(void)
{
    return;
}


/* VA 0x7ff29102064, RVA 0x2064, CFG name sub_7ff29102064; exports: [] */
void sub_7ff29102064(void)
{
    [D] Unsupported jumpkind Ijk_SigTRAP at address 8792486977636()
}


/* VA 0x7ff29102a69, RVA 0x2a69, CFG name sub_7ff29102a69; exports: [] */
void sub_7ff29102a69(void)
{
    return;
}


/* VA 0x7ff2910419c, RVA 0x419c, CFG name sub_7ff2910419c; exports: [] */
unsigned int sub_7ff2910419c(void)
{
    return 0;
}


/* VA 0x7ff29104a2c, RVA 0x4a2c, CFG name sub_7ff29104a2c; exports: [] */
void sub_7ff29104a2c(void)
{
    return;
}


/* VA 0x7ff2910a2cf, RVA 0xa2cf, CFG name sub_7ff2910a2cf; exports: [] */
typedef struct struct_0 {
    char padding_0[85];
    unsigned long long field_55;
} struct_0;

void sub_7ff2910a2cf(void)
{
    struct_0 *v1;  // rax

    goto *((long long *)&(&v1->padding_0)[1]);
}


/* VA 0x7ff291019d8, RVA 0x19d8, CFG name sub_7ff291019d8; exports: [] */
void sub_7ff291019d8(unsigned long a0)
{
    [D] Unsupported jumpkind Ijk_SigTRAP at address 8792486975960()
}


/* VA 0x7ff29101d9e, RVA 0x1d9e, CFG name sub_7ff29101d9e; exports: [] */
void sub_7ff29101d9e(void)
{
    [D] Unsupported jumpkind Ijk_SigTRAP at address 8792486976926()
}


/* VA 0x7ff29102053, RVA 0x2053, CFG name sub_7ff29102053; exports: [] */
void sub_7ff29102053(unsigned long a0, unsigned short a1)
{
    [D] syscall()();
}


/* VA 0x7ff29104098, RVA 0x4098, CFG name sub_7ff29104098; exports: [] */
typedef struct struct_0 {
    char padding_0[12];
    unsigned int field_c;
} struct_0;

int sub_7ff29104098(struct_0 *a0)
{
    return a0->field_c;
}


/* VA 0x7ff29106640, RVA 0x6640, CFG name sub_7ff29106640; exports: [] */
int sub_7ff29106640(void)
{
}


/* VA 0x7ff291069bf, RVA 0x69bf, CFG name sub_7ff291069bf; exports: [] */
void sub_7ff291069bf(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned int a8)
{
}


/* VA 0x7ff2910a5ee, RVA 0xa5ee, CFG name sub_7ff2910a5ee; exports: [] */
char sub_7ff2910a5ee(void)
{
}


/* VA 0x7ff29101524, RVA 0x1524, CFG name sub_7ff29101524; exports: [] */
char sub_7ff29101524(void)
{
    unsigned long v1;  // cc_op
    unsigned long v2;  // cc_dep1
    unsigned long v3;  // cc_dep2
    unsigned long v4;  // cc_ndep
    unsigned long v5;  // 4110
    char v6;  // al

    v5 = _ccall(v1, v2, v3, v4);
    return v6 - 57 - ((char)v5 & 1);
}


/* VA 0x7ff2910168a, RVA 0x168a, CFG name sub_7ff2910168a; exports: [] */
char sub_7ff2910168a(void)
{
}


/* VA 0x7ff29102107, RVA 0x2107, CFG name sub_7ff29102107; exports: [] */
void sub_7ff29102107(void)
{
}


/* VA 0x7ff2910211d, RVA 0x211d, CFG name sub_7ff2910211d; exports: [] */
void sub_7ff2910211d(void)
{
    [D] Unsupported jumpkind Ijk_NoDecode at address 8792486977821()
}


/* VA 0x7ff291084f4, RVA 0x84f4, CFG name sub_7ff291084f4; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    unsigned long long field_10;
} struct_0;

long long sub_7ff291084f4(struct_0 *a0)
{
    return a0->field_10;
}


/* VA 0x7ff29102078, RVA 0x2078, CFG name sub_7ff29102078; exports: [] */
void sub_7ff29102078(void)
{
}


/* VA 0x7ff29108b70, RVA 0x8b70, CFG name sub_7ff29108b70; exports: [] */
void sub_7ff29108b70(void)
{
    unsigned int flag;  // [bp+0x20]

    flag = 0;
}


/* VA 0x7ff29108cfa, RVA 0x8cfa, CFG name _purecall; exports: [] */
// attributes: PLT stub
int _purecall(void)
{
    ::msvcrt.dll::_purecall();
    return;
}


/* VA 0x7ff29108d06, RVA 0x8d06, CFG name ?what@exception@@UEBAPEBDXZ; exports: [] */
// attributes: PLT stub
char * exception::what(void* this)
{
    return ::msvcrt.dll::exception::what();
}


/* VA 0x7ff29108d12, RVA 0x8d12, CFG name ??1exception@@UEAA@XZ; exports: [] */
// attributes: PLT stub
int exception::~exception(void* this)
{
    return;
}


/* VA 0x7ff29108d1e, RVA 0x8d1e, CFG name ??0exception@@QEAA@AEBQEBDH@Z; exports: [] */
// attributes: PLT stub
int exception::exception(void* this, char *&arg_0, int arg_1)
{
    ::msvcrt.dll::exception::exception();
    return;
}


/* VA 0x7ff29108d2a, RVA 0x8d2a, CFG name ??0exception@@QEAA@AEBV0@@Z; exports: [] */
// attributes: PLT stub
int exception::exception(void* this, class exception &arg_0)
{
    ::msvcrt.dll::exception::exception();
    return;
}


/* VA 0x7ff29108d36, RVA 0x8d36, CFG name memset; exports: [] */
// attributes: PLT stub
int memset(void)
{
    ::msvcrt.dll::memset();
    return;
}


/* VA 0x7ff29108d42, RVA 0x8d42, CFG name __C_specific_handler; exports: [] */
// attributes: PLT stub
int __C_specific_handler(void)
{
    ::msvcrt.dll::__C_specific_handler();
    return;
}


/* VA 0x7ff29108de8, RVA 0x8de8, CFG name _XcptFilter; exports: [] */
// attributes: PLT stub
int _XcptFilter(void)
{
    ::msvcrt.dll::_XcptFilter();
    return;
}


/* VA 0x7ff29108ed4, RVA 0x8ed4, CFG name _initterm; exports: [] */
// attributes: PLT stub
int _initterm(void)
{
    ::msvcrt.dll::_initterm();
    return;
}


/* VA 0x7ff29108ee0, RVA 0x8ee0, CFG name _amsg_exit; exports: [] */
// attributes: PLT stub
int _amsg_exit(void)
{
    ::msvcrt.dll::_amsg_exit();
    return;
}


/* VA 0x7ff291090d0, RVA 0x90d0, CFG name _unlock; exports: [] */
// attributes: PLT stub
int _unlock(void)
{
    ::msvcrt.dll::_unlock();
    return;
}


/* VA 0x7ff291090dc, RVA 0x90dc, CFG name __dllonexit; exports: [] */
// attributes: PLT stub
int __dllonexit(void)
{
    ::msvcrt.dll::__dllonexit();
    return;
}


/* VA 0x7ff291090e8, RVA 0x90e8, CFG name _lock; exports: [] */
// attributes: PLT stub
int _lock(void)
{
    ::msvcrt.dll::_lock();
    return;
}


/* VA 0x7ff291090f4, RVA 0x90f4, CFG name RtlVirtualUnwind; exports: [] */
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


/* VA 0x7ff29109100, RVA 0x9100, CFG name RtlLookupFunctionEntry; exports: [] */
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


/* VA 0x7ff2910910c, RVA 0x910c, CFG name memmove; exports: [] */
// attributes: PLT stub
int memmove(void)
{
    ::msvcrt.dll::memmove();
    return;
}


/* VA 0x7ff29109118, RVA 0x9118, CFG name __RTDynamicCast; exports: [] */
// attributes: PLT stub
int __RTDynamicCast(void)
{
    ::msvcrt.dll::__RTDynamicCast();
    return;
}


/* VA 0x7ff29109124, RVA 0x9124, CFG name memcpy; exports: [] */
// attributes: PLT stub
int memcpy(void)
{
    ::msvcrt.dll::memcpy();
    return;
}


/* VA 0x7ff29109130, RVA 0x9130, CFG name _CxxThrowException; exports: [] */
// attributes: PLT stub
int _CxxThrowException(void)
{
    ::msvcrt.dll::_CxxThrowException();
    return;
}


/* VA 0x7ff2910913c, RVA 0x913c, CFG name __CxxFrameHandler3; exports: [] */
// attributes: PLT stub
int __CxxFrameHandler3(void)
{
    ::msvcrt.dll::__CxxFrameHandler3();
    return;
}


/* VA 0x7ff29109f93, RVA 0x9f93, CFG name sub_7ff29109f93; exports: [] */
typedef struct struct_0 {
    char padding_0[129];
    unsigned long long field_81;
} struct_0;

void sub_7ff29109f93(void)
{
    struct_0 *v1;  // rsi

    goto *((long long *)&(&v1->padding_0)[1]);
}


/* VA 0x7ff291019ae, RVA 0x19ae, CFG name sub_7ff291019ae; exports: [] */
typedef struct struct_0 {
    char padding_0[162941995];
    char field_9b64c2b;
} struct_0;

void sub_7ff291019ae(char a0)
{
    unsigned long v1;  // cc_op
    unsigned long v2;  // cc_dep1
    unsigned long v3;  // cc_dep2
    unsigned long v4;  // cc_ndep
    unsigned long v5;  // 4108
    struct_0 *ptr;  // rdi
    unsigned long v7;  // 4112

    v5 = _ccall(v1, v2, v3, v4);
    v7 = _ccall((unsigned long long)ptr->field_9b64c2b, (unsigned long long)a0, v5, 1);
    ptr->field_9b64c2b = v7;
}


/* VA 0x7ff291065d8, RVA 0x65d8, CFG name sub_7ff291065d8; exports: [] */
void sub_7ff291065d8(void)
{
    free();
    return;
}


/* VA 0x7ff29101d42, RVA 0x1d42, CFG name sub_7ff29101d42; exports: [] */
void sub_7ff29101d42(void)
{
    return;
}


/* VA 0x7ff291041a8, RVA 0x41a8, CFG name sub_7ff291041a8; exports: [] */
extern char g_7ff29101840;

long long sub_7ff291041a8(void)
{
    return &g_7ff29101840;
}


/* VA 0x7ff29105afb, RVA 0x5afb, CFG name sub_7ff29105afb; exports: [] */
long long sub_7ff29105afb(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, int a8)
{
    if (a8 < 0)
        goto LABEL_0x7ff29105b05;
    else
        goto LABEL_0x7ff29105b03;
}


/* VA 0x7ff29106404, RVA 0x6404, CFG name sub_7ff29106404; exports: [] */
long long sub_7ff29106404(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, int a8)
{
    if (a8 < 0)
        goto LABEL_0x7ff2910640e;
    else
        goto LABEL_0x7ff2910640c;
}


/* VA 0x7ff291081ee, RVA 0x81ee, CFG name sub_7ff291081ee; exports: [] */
long long sub_7ff291081ee(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, int a10)
{
    if (a10 < 0)
        goto LABEL_0x7ff291081f8;
    else
        goto LABEL_0x7ff291081f6;
}


/* VA 0x7ff29108701, RVA 0x8701, CFG name sub_7ff29108701; exports: [] */
long long sub_7ff29108701(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, int a8)
{
    if (a8 < 0)
        goto LABEL_0x7ff2910870b;
    else
        goto LABEL_0x7ff29108709;
}


/* VA 0x7ff291040de, RVA 0x40de, CFG name sub_7ff291040de; exports: [] */
int sub_7ff291040de(void)
{
    unsigned int v1;  // [bp+0x20]

    v1 = 2147942414;
}


/* VA 0x7ff29109c10, RVA 0x9c10, CFG name sub_7ff29109c10; exports: [] */
int sub_7ff29109c10(char *ptr, char a1)
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


/* VA 0x7ff2910160a, RVA 0x160a, CFG name sub_7ff2910160a; exports: [] */
void sub_7ff2910160a(void)
{
    char v0;  // [bp-0x163a2453]

    v0 *= 0;
    return;
}


/* VA 0x7ff29102059, RVA 0x2059, CFG name sub_7ff29102059; exports: [] */
long long sub_7ff29102059(void)
{
    unsigned int v2;  // edi
    unsigned int v0;  // [bp-0x62a67290]

    if ((v2 | v0) <= 0)
        goto LABEL_0x7ff29102019;
    else
        goto LABEL_0x7ff29102063;
}


/* VA 0x7ff2910484c, RVA 0x484c, CFG name sub_7ff2910484c; exports: [] */
typedef struct struct_1 {
    char padding_0[8];
    struct struct_2 *field_8;
} struct_1;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

long long sub_7ff2910484c(struct_1 *a0)
{
    goto a0->field_8->field_0->field_0;
}


/* VA 0x7ff29105567, RVA 0x5567, CFG name sub_7ff29105567; exports: [] */
long long sub_7ff29105567(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, int a8)
{
    if (a8 < 0)
        goto LABEL_0x7ff29105573;
    else
        goto LABEL_0x7ff29105571;
}


/* VA 0x7ff29108be6, RVA 0x8be6, CFG name sub_7ff29108be6; exports: [] */
void sub_7ff29108be6(unsigned long a0)
{
    sub_7ff29108bf0();
    return;
}


/* VA 0x7ff291091e6, RVA 0x91e6, CFG name sub_7ff291091e6; exports: [] */
void sub_7ff291091e6(void)
{
    return;
}


/* VA 0x7ff2910a247, RVA 0xa247, CFG name sub_7ff2910a247; exports: [] */
void sub_7ff2910a247(void)
{
    [D] Unsupported jumpkind Ijk_Privileged at address 8792487010887()
}


/* VA 0x7ff29101518, RVA 0x1518, CFG name sub_7ff29101518; exports: [] */
void sub_7ff29101518(unsigned long long a0)
{
    char v1;  // al

    if (a0 - 1 & !(v1 & 72))
        goto LABEL_0x7ff291014d2;
}


/* VA 0x7ff291040a4, RVA 0x40a4, CFG name sub_7ff291040a4; exports: [] */
typedef struct struct_0 {
    char padding_0[12];
    unsigned int field_c;
} struct_0;

int sub_7ff291040a4(struct_0 *a0)
{
    InterlockedExchangeAdd(&a0->field_c, 4294967295);
    return a0->field_c - 1;
}


/* VA 0x7ff29104824, RVA 0x4824, CFG name sub_7ff29104824; exports: [] */
typedef struct struct_1 {
    char padding_0[8];
    struct struct_2 *field_8;
} struct_1;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_0 {
    char padding_0[8];
    unsigned long long field_8;
} struct_0;

long long sub_7ff29104824(struct_1 *a0)
{
    goto a0->field_8->field_0->field_8;
}


/* VA 0x7ff29104838, RVA 0x4838, CFG name sub_7ff29104838; exports: [] */
typedef struct struct_1 {
    char padding_0[8];
    struct struct_2 *field_8;
} struct_1;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_0 {
    char padding_0[16];
    unsigned long long field_10;
} struct_0;

long long sub_7ff29104838(struct_1 *a0)
{
    goto a0->field_8->field_0->field_10;
}


/* VA 0x7ff2910562c, RVA 0x562c, CFG name sub_7ff2910562c; exports: [] */
extern char g_7ff29102280;

long long sub_7ff2910562c(unsigned long long *ptr)
{
    *(ptr) = &g_7ff29102280;
    return &g_7ff29102280;
}


/* VA 0x7ff291015b7, RVA 0x15b7, CFG name sub_7ff291015b7; exports: [] */
char sub_7ff291015b7(void)
{
    unsigned int *ptr;  // rbx
    unsigned int v2;  // 4098
    unsigned long v3;  // cc_op
    unsigned long v4;  // cc_dep1
    unsigned long v5;  // cc_dep2
    unsigned long v6;  // cc_ndep
    unsigned long v7;  // 4117
    unsigned long v8;  // 4129
    char v9;  // al

    v2 = *(ptr);
    v7 = _ccall(v3, v4, v5, v6);
    *(ptr) = *(ptr) + (unsigned int)ptr + ((unsigned int)v7 & 1);
    v8 = _ccall(11, (unsigned long long)v2, (unsigned long long)((unsigned int)ptr ^ (unsigned int)v7 & 1), v7 & 1);
    if ((_INSERT(v9 CONCAT 0, 0, v9 - 19 - ((char)v8 & 1)) ^ 2216390923) < 0)
        goto LABEL_0x7ff291015c3;
    else
        goto LABEL_0x7ff291015c7;
}


/* VA 0x7ff29109a30, RVA 0x9a30, CFG name sub_7ff29109a30; exports: [] */
void sub_7ff29109a30(void)
{
    sub_7ff29108cdc(sub_7ff29109bc4);
    return;
}


/* VA 0x7ff29109bec, RVA 0x9bec, CFG name sub_7ff29109bec; exports: [] */
extern long long g_7ff2910ca30;

void sub_7ff29109bec(void)
{
    sub_7ff29108720(&g_7ff2910ca30);
    return;
}


/* VA 0x7ff29101fcb, RVA 0x1fcb, CFG name sub_7ff29101fcb; exports: [] */
int sub_7ff29101fcb(unsigned long a0)
{
    unsigned long v1;  // cc_op
    unsigned long v2;  // cc_dep1
    unsigned long v3;  // cc_dep2
    unsigned long v4;  // cc_ndep
    unsigned long v5;  // 4101

    v5 = _ccall(4, v1, v2, v3, v4);
    if ((char)v5)
        goto LABEL_0x7ff29101f71;
}


/* VA 0x7ff2910296e, RVA 0x296e, CFG name sub_7ff2910296e; exports: [] */
unsigned int sub_7ff2910296e(void)
{
    unsigned int v1;  // eax

    return v1 & 2571250829;
}


/* VA 0x7ff291040b8, RVA 0x40b8, CFG name sub_7ff291040b8; exports: [] */
typedef struct struct_0 {
    char padding_0[12];
    unsigned int field_c;
} struct_0;

int sub_7ff291040b8(struct_0 *a0)
{
    InterlockedExchangeAdd(&a0->field_c, 1);
    return a0->field_c + 1;
}


/* VA 0x7ff2910477c, RVA 0x477c, CFG name sub_7ff2910477c; exports: [] */
typedef struct struct_0 {
    char padding_0[8];
    unsigned int field_8;
} struct_0;

int sub_7ff2910477c(struct_0 *a0)
{
    InterlockedExchangeAdd(&a0->field_8, 1);
    return a0->field_8 + 1;
}


/* VA 0x7ff29101c76, RVA 0x1c76, CFG name sub_7ff29101c76; exports: [] */
int sub_7ff29101c76(void)
{
    char v2;  // 4096
    unsigned long v3;  // cc_ndep
    unsigned long v4;  // 4132
    unsigned int v5;  // eax
    char v0;  // [bp-0x1316616d]

    v2 = v0;
    v0 = v2 * 2;
    v4 = _ccall(29, (unsigned long long)v2 * 2, (unsigned long long)v2, v3);
    return v5 + 1336156498 - ((unsigned int)v4 & 1);
}


/* VA 0x7ff29102b7f, RVA 0x2b7f, CFG name sub_7ff29102b7f; exports: [] */
long long sub_7ff29102b7f(void)
{
    void* ptr;  // rax
    void* p;  // rax

    *((unsigned int *)ptr) = *((int *)ptr) + 1;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    p = ptr - *((long long *)ptr);
    *((char *)p) = *((char *)p) + *((char *)&p);
}


/* VA 0x7ff29109c1d, RVA 0x9c1d, CFG name sub_7ff29109c1d; exports: [] */
void sub_7ff29109c1d(unsigned long a0, void* p)
{
    void* ptr;  // rax

    *((char *)ptr) = *((char *)ptr) ^ *((char *)&ptr);
    *((char *)&p[115]) = (char)p[115] + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((unsigned int *)ptr) = *((int *)ptr) | (unsigned int)ptr;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((unsigned int *)ptr) = (unsigned int)ptr;
}


/* VA 0x7ff2910a610, RVA 0xa610, CFG name sub_7ff2910a610; exports: [] */
typedef struct struct_0 {
    char padding_0[127];
    char field_7f;
} struct_0;

void sub_7ff2910a610(char a0, struct_0 *p)
{
    unsigned long v1;  // cc_op
    unsigned long v2;  // cc_dep1
    unsigned long v3;  // cc_dep2
    unsigned long v4;  // cc_ndep
    unsigned long v5;  // 4104
    void* ptr;  // rax
    char v7;  // ch

    v5 = _ccall(14, v1, v2, v3, v4);
    if (!((char)v5))
        goto LABEL_7ff2910a613;
LABEL_7ff2910a613:
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    p->field_7f = p->field_7f + v7;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((unsigned int *)ptr) = *((int *)ptr) + (unsigned int)ptr;
}


/* VA 0x7ff29101529, RVA 0x1529, CFG name sub_7ff29101529; exports: [] */
char sub_7ff29101529(void* p)
{
    char v1;  // al
    char *ptr;  // rdi
    unsigned long v3;  // cc_op
    unsigned long v4;  // cc_dep1
    unsigned long v5;  // cc_dep2
    unsigned long v6;  // cc_ndep
    unsigned long v7;  // 4101

    v1 = (char)p[29];
    *(ptr) = (char)p[29];
    if ([D] unsupported_<class 'pyvex.expr.GetI'>())
    {
        [D] PutI(904:F64x8)[t3,0] = t4()
        [D] PutI(968:I8x8)[t3,0] = 0x01()
    }
    else
    {
        [D] PutI(904:F64x8)[t3,0] = t4()
        [D] PutI(968:I8x8)[t3,0] = 0x01()
    }
    if (!p)
        goto LABEL_0x7ff29101596;
    v7 = _ccall(6, v3, v4, v5, v6);
    if (!((char)v7))
        goto LABEL_0x7ff29101584;
    return v1;
}


/* VA 0x7ff29106490, RVA 0x6490, CFG name sub_7ff29106490; exports: [] */
extern char g_7ff29102520;

void sub_7ff29106490(unsigned long ptr)
{
    *((char **)ptr) = &g_7ff29102520;
    return;
}


/* VA 0x7ff291016cc, RVA 0x16cc, CFG name sub_7ff291016cc; exports: [] */
char sub_7ff291016cc(void)
{
    unsigned long v1;  // cc_op
    unsigned long v2;  // cc_dep1
    unsigned long v3;  // cc_dep2
    unsigned long v4;  // cc_ndep
    unsigned long v5;  // 4110
    char *ptr;  // rdi

    v5 = _ccall(v1, v2, v3, v4);
    *(ptr) = 251 - ((char)v5 & 1);
    if ([D] unsupported_<class 'pyvex.expr.GetI'>())
    {
        [D] PutI(904:F64x8)[t3,0] = t4()
        [D] PutI(968:I8x8)[t3,0] = 0x01()
    }
    else
    {
        [D] PutI(904:F64x8)[t3,0] = t4()
        [D] PutI(968:I8x8)[t3,0] = 0x01()
    }
    return 251 - ((char)v5 & 1);
}


/* VA 0x7ff291016e6, RVA 0x16e6, CFG name sub_7ff291016e6; exports: [] */
void sub_7ff291016e6(void)
{
    unsigned int *p;  // rdi
    unsigned int *v2;  // rsi
    unsigned long v3;  // cc_op
    unsigned long v4;  // cc_dep1
    unsigned long v5;  // cc_dep2
    unsigned long v6;  // cc_ndep
    unsigned long v7;  // 4109
    unsigned long v8;  // 4101
    unsigned long v9;  // 4101
    char *ptr;  // rax

    *(p) = *(v2);
    v7 = _ccall(8, v3, v4, v5, v6);
    if ((char)v7)
    {
        v9 = _ccall(8, v3, v4, v5, v6);
        if ((char)v9)
            goto LABEL_0x7ff29101770;
        *(ptr) = 0;
        *(ptr) = *(ptr) + *((char *)&ptr);
        *(ptr) = *(ptr) + *((char *)&ptr);
        *(ptr) = *(ptr) + *((char *)&ptr);
    }
    v8 = _ccall(8, v3, v4, v5, v6);
    if ((char)v8)
        goto LABEL_0x7ff291016b3;
    else
        goto LABEL_0x7ff291016eb;
}


/* VA 0x7ff29101cdc, RVA 0x1cdc, CFG name sub_7ff29101cdc; exports: [] */
void sub_7ff29101cdc(void)
{
    unsigned long v1;  // cc_op
    unsigned long v2;  // cc_dep1
    unsigned long v3;  // cc_dep2
    unsigned long v4;  // cc_ndep
    unsigned long v5;  // 4101
    char v6;  // al
    unsigned long v7;  // 4101

    v5 = _ccall(6, v1, v2, v3, v4);
    if ((char)v5)
    {
        __outbyte(90, v6);
        v7 = _ccall(0, v1, v2, v3, v4);
        if (!((char)v7))
            goto LABEL_0x7ff29101ce6;
    }
}


/* VA 0x7ff291084a4, RVA 0x84a4, CFG name sub_7ff291084a4; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    HANDLE field_10;
} struct_0;

UIntPtr sub_7ff291084a4(struct_0 *a0, void* a1)
{
    return HeapSize(a0->field_10, HEAP_NONE, a1);
}


/* VA 0x7ff29109cbd, RVA 0x9cbd, CFG name sub_7ff29109cbd; exports: [] */
char sub_7ff29109cbd(unsigned long a0, void* p)
{
    char v1;  // 4097
    char v2;  // al
    void* ptr;  // rax
    char v4;  // 4114
    unsigned long v5;  // cc_ndep
    unsigned long v6;  // 4133

    v1 = *((char *)p);
    ptr = v2 ^ v1;
    *((char *)&p[115]) = (char)p[115] ^ v2 ^ v1;
    *((char *)ptr) = *((char *)ptr) + (v2 ^ v1);
    *((unsigned int *)ptr) = *((int *)ptr) + (unsigned int)ptr;
    v4 = *((char *)ptr);
    *((char *)ptr) = *((char *)ptr) + (v2 ^ v1);
    v6 = _ccall(14, 1, (unsigned long long)v4, (unsigned long long)(v2 ^ v1), v5);
    if ((char)v6)
        goto LABEL_0x7ff29109c56;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    return *((char *)&ptr);
}


/* VA 0x7ff2910206e, RVA 0x206e, CFG name sub_7ff2910206e; exports: [] */
void sub_7ff2910206e(void* ptr, char a1)
{
    unsigned long v1;  // cc_op
    unsigned long v2;  // cc_dep1
    unsigned long v3;  // cc_dep2
    unsigned long v4;  // cc_ndep
    unsigned long v5;  // 4101
    unsigned long v6;  // 4101

    v5 = _ccall(0, v1, v2, v3, v4);
    if ((char)v5)
    {
        v6 = _ccall(8, v1, v2, v3, v4);
        if (!((char)v6))
            *((char *)&ptr[1312128599]) = a1;
    }
}


/* VA 0x7ff2910154e, RVA 0x154e, CFG name sub_7ff2910154e; exports: [] */
typedef struct struct_0 {
    char padding_0[2067842852];
    char field_7b40c724;
} struct_0;

void sub_7ff2910154e(unsigned long a0, char a1)
{
    unsigned int p[2];  // rdi
    unsigned int *v2;  // rsi
    struct_0 *addr;  // rbx
    unsigned int v12;  // eax
    unsigned int ptr[2];  // rdi
    unsigned long v4;  // cc_op
    unsigned long v5;  // cc_dep1
    unsigned long v6;  // cc_dep2
    unsigned long v7;  // cc_ndep
    unsigned long v8;  // 4101
    unsigned int v9;  // eax
    unsigned long v10;  // 4110

    p[0] = *(v2);
    ptr = &p[1];
    v8 = _ccall(8, v4, v5, v6, v7);
    if ((char)v8)
    {
        v10 = _ccall(6, 19, (unsigned long long)((unsigned int)v2 + 4 & vvar_5{r56|4b}), 0, v7);
        if (!((char)v10))
            goto LABEL_0x7ff291015a2;
        addr->field_7b40c724 = addr->field_7b40c724 - a1;
        ptr[0] = v12;
        return;
    }
    ptr[0] = v9;
}


/* VA 0x7ff291044bc, RVA 0x44bc, CFG name sub_7ff291044bc; exports: [] */
void sub_7ff291044bc(unsigned long a0, unsigned long a1, unsigned long a2)
{
    sub_7ff29104a38();
    return;
}


/* VA 0x7ff29104764, RVA 0x4764, CFG name sub_7ff29104764; exports: [] */
void sub_7ff29104764(unsigned long a0, unsigned long a1, unsigned long a2)
{
    sub_7ff29104a38();
    return;
}


/* VA 0x7ff2910a733, RVA 0xa733, CFG name sub_7ff2910a733; exports: [] */
typedef struct struct_0 {
    char padding_0[82];
    struct struct_1 *field_52;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

int sub_7ff2910a733(unsigned long a0, unsigned long a1)
{
    struct_0 *v1;  // rbx
    char *ptr;  // rax
    void* p;  // rax

    ptr = (*((long long *)&(&v1->padding_0)[1]))();
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    p = *((unsigned short *)&ptr);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((unsigned int *)p) = *((int *)p) + (unsigned int)p;
    *((char *)p) = *((char *)p) + *((char *)&p);
    return *((unsigned int *)&p);
}


/* VA 0x7ff291015d1, RVA 0x15d1, CFG name sub_7ff291015d1; exports: [] */
long long sub_7ff291015d1(void)
{
    unsigned int v1;  // eax

    return (v1 | 1740938256) - 1044559427;
}


/* VA 0x7ff29102135, RVA 0x2135, CFG name sub_7ff29102135; exports: [] */
void sub_7ff29102135(unsigned long a0, char a1)
{
    unsigned long v3;  // cc_op
    unsigned long v4;  // cc_dep1
    unsigned long v5;  // cc_dep2
    unsigned long v6;  // cc_ndep
    unsigned long v7;  // 4105
    unsigned long v8;  // 4101
    unsigned long v9;  // 4101
    char *v0;  // [bp-0x10]
    unsigned long v1;  // [bp-0x8]

    v1 = 22;
    v7 = _ccall(10, v3, v4, v5, v6);
    if ((char)v7)
    {
        if ([D] unsupported_<class 'pyvex.expr.GetI'>())
        {
            [D] PutI(968:I8x8)[t12,0] = 0x00()
            v8 = _ccall(4, v3, v4, v5, v6);
            if (!((char)v8))
                goto LABEL_0x7ff2910217c;
            v0 = &v1;
        }
        [D] PutI(968:I8x8)[t12,0] = 0x00()
        v9 = _ccall(4, v3, v4, v5, v6);
        if (!((char)v9))
            goto LABEL_0x7ff2910217c;
        v0 = &v1;
    }
}


/* VA 0x7ff29108aac, RVA 0x8aac, CFG name sub_7ff29108aac; exports: [] */
void sub_7ff29108aac(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
}


/* VA 0x7ff29108ace, RVA 0x8ace, CFG name sub_7ff29108ace; exports: [] */
void sub_7ff29108ace(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
}


/* VA 0x7ff29108af9, RVA 0x8af9, CFG name sub_7ff29108af9; exports: [] */
void sub_7ff29108af9(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
}


/* VA 0x7ff29101a4e, RVA 0x1a4e, CFG name sub_7ff29101a4e; exports: [] */
typedef struct struct_0 {
    char padding_0[565507253];
    char field_21b4f4b5;
} struct_0;

int sub_7ff29101a4e(void)
{
    struct_0 *ptr;  // rdi

    ptr->field_21b4f4b5 = ptr->field_21b4f4b5 >> 1;
}


/* VA 0x7ff29101da2, RVA 0x1da2, CFG name sub_7ff29101da2; exports: [] */
void sub_7ff29101da2(unsigned long a0, unsigned long a1)
{
    unsigned long v1;  // rax

    *((char *)(v1 * 5)) = *((char *)(v1 * 5)) >> 5 | *((char *)(v1 * 5)) * 8;
    [D] syscall()();
    return;
}


/* VA 0x7ff2910394f, RVA 0x394f, CFG name sub_7ff2910394f; exports: [] */
void sub_7ff2910394f(char *p)
{
    void* ptr;  // rax
    char v2;  // 4109
    char v3;  // bh

    *((unsigned int *)ptr) = *((int *)ptr) + 1;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    v2 = *((char *)ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *(p) = *(p) + v3 + ((char)(v2 + *((char *)&ptr) <= v2 ? 1 : 0) & 1);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
}


/* VA 0x7ff29108a15, RVA 0x8a15, CFG name sub_7ff29108a15; exports: [] */
void sub_7ff29108a15(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
    unsigned int flag;  // [bp+0x20]

    flag = 0;
}


/* VA 0x7ff29108a48, RVA 0x8a48, CFG name sub_7ff29108a48; exports: [] */
void sub_7ff29108a48(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
    unsigned int flag;  // [bp+0x20]

    flag = 0;
}


/* VA 0x7ff29108a7f, RVA 0x8a7f, CFG name sub_7ff29108a7f; exports: [] */
void sub_7ff29108a7f(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
    unsigned int flag;  // [bp+0x20]

    flag = 0;
}


/* VA 0x7ff29108b2f, RVA 0x8b2f, CFG name sub_7ff29108b2f; exports: [] */
void sub_7ff29108b2f(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
    unsigned int flag;  // [bp+0x20]

    flag = 0;
}


/* VA 0x7ff29101d00, RVA 0x1d00, CFG name sub_7ff29101d00; exports: [] */
void sub_7ff29101d00(unsigned long idx)
{
    unsigned long v1;  // cc_op
    unsigned long v2;  // cc_dep1
    unsigned long v3;  // cc_dep2
    unsigned long v4;  // cc_ndep
    unsigned long v5;  // 4101
    unsigned long ptr;  // rsi

    v5 = _ccall(8, v1, v2, v3, v4);
    if ((char)v5)
        goto LABEL_0x7ff29101ce4;
    *((unsigned int *)(ptr + idx * 2)) = *((int *)(ptr + idx * 2)) - 62;
    *((int *)((ptr & 4294967295) + 4)) = ~(*((int *)((ptr & 4294967295) + 4)));
}


/* VA 0x7ff29104572, RVA 0x4572, CFG name sub_7ff29104572; exports: [] */
void sub_7ff29104572(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned int a14)
{
}


/* VA 0x7ff291054e8, RVA 0x54e8, CFG name sub_7ff291054e8; exports: [] */
void sub_7ff291054e8(long long *a0)
{
    if (*(a0))
        sub_7ff29104b60(*(a0));
    return;
}


/* VA 0x7ff29107c88, RVA 0x7c88, CFG name sub_7ff29107c88; exports: [] */
extern unsigned long long g_7ff2910d1e0;

unsigned long long sub_7ff29107c88(unsigned long long a0)
{
    unsigned long long v1;  // rax
    char v2;  // cl

    v1 = g_7ff2910d1e0 ^ a0;
    v2 = (char)g_7ff2910d1e0 & 63;
    return ((v2 & 63) ? v1 << (v2 & 63) | v1 >> 64 - (v2 & 63) : v1 << (v2 & 63) | v1 >> 64 - (v2 & 63));
}


/* VA 0x7ff29101bee, RVA 0x1bee, CFG name sub_7ff29101bee; exports: [] */
void sub_7ff29101bee(void* ptr)
{
    if ([D] unsupported_<class 'pyvex.expr.GetI'>())
    {
        *((unsigned long long *)&ptr[1091569159]) = [D] unsupported_<class 'pyvex.expr.GetI'>();
        [D] PutI(968:I8x8)[t7,0] = 0x00()
    }
    else
    {
        *((unsigned long long *)&ptr[1091569159]) = nan;
        [D] PutI(968:I8x8)[t7,0] = 0x00()
    }
    8794614985384();
}


/* VA 0x7ff291040cc, RVA 0x40cc, CFG name sub_7ff291040cc; exports: [] */
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

unsigned int sub_7ff291040cc(CRITICAL_SECTION *a0)
{
    unsigned int flag;  // [bp-0x18]

    InitializeCriticalSection(a0);
    flag = 0;
    return 0;
}


/* VA 0x7ff29104c24, RVA 0x4c24, CFG name sub_7ff29104c24; exports: [] */
void sub_7ff29104c24(void* *a0)
{
    if (*(a0))
        free(*(a0));
    return;
}


/* VA 0x7ff29108cdc, RVA 0x8cdc, CFG name sub_7ff29108cdc; exports: [] */
long long sub_7ff29108cdc(void)
{
    return -(-(0 < sub_7ff29108c50())) - 1;
}


/* VA 0x7ff29101996, RVA 0x1996, CFG name sub_7ff29101996; exports: [] */
void sub_7ff29101996(char a0)
{
    unsigned long long v0;  // [bp-0x8]

    v0 = 112;
    if ([D] unsupported_<class 'pyvex.expr.GetI'>())
    {
        [D] PutI(904:F64x8)[t3,0] = t4()
        [D] PutI(968:I8x8)[t3,0] = 0x01()
    }
    else
    {
        [D] PutI(904:F64x8)[t3,0] = t4()
        [D] PutI(968:I8x8)[t3,0] = 0x01()
    }
}


/* VA 0x7ff29101b05, RVA 0x1b05, CFG name sub_7ff29101b05; exports: [] */
void sub_7ff29101b05(unsigned long long a0, unsigned long a1)
{
    unsigned long v2;  // cc_op
    unsigned long v3;  // cc_dep1
    unsigned long v4;  // cc_dep2
    unsigned long v5;  // cc_ndep
    unsigned long v6;  // 4105
    unsigned long long v0;  // [bp-0x8]

    v0 = a0;
    v6 = _ccall(4, v2, v3, v4, v5);
    if (!((char)v6))
        goto LABEL_7ff29101b0a;
LABEL_7ff29101b0a:
    [D] Unsupported jumpkind Ijk_Privileged at address 8792486976266()
}


/* VA 0x7ff29104000, RVA 0x4000, CFG name sub_7ff29104000; exports: [] */
typedef struct struct_0 {
    char padding_0[24];
    unsigned long long field_18;
} struct_0;

long long sub_7ff29104000(unsigned long a0, struct_0 **a1)
{
    goto *(a1)->field_18;
}


/* VA 0x7ff291095ff, RVA 0x95ff, CFG name sub_7ff291095ff; exports: [] */
void sub_7ff291095ff(unsigned long a0, long long a1)
{
    sub_7ff29106380(a1 + 64);
    return;
}


/* VA 0x7ff2910961d, RVA 0x961d, CFG name sub_7ff2910961d; exports: [] */
void sub_7ff2910961d(unsigned long a0, long long a1)
{
    sub_7ff2910805c(a1 + 48);
    return;
}


/* VA 0x7ff2910966c, RVA 0x966c, CFG name sub_7ff2910966c; exports: [] */
void sub_7ff2910966c(unsigned long a0, long long a1)
{
    sub_7ff2910805c(a1 + 40);
    return;
}


/* VA 0x7ff2910968a, RVA 0x968a, CFG name sub_7ff2910968a; exports: [] */
typedef struct struct_0 {
    char padding_0[64];
    unsigned long long *field_40;
} struct_0;

long long sub_7ff2910968a(unsigned long a0, struct_0 *a1)
{
    return sub_7ff2910562c(a1->field_40);
}


/* VA 0x7ff2910979c, RVA 0x979c, CFG name sub_7ff2910979c; exports: [] */
void sub_7ff2910979c(unsigned long a0, unsigned long a1)
{
    sub_7ff291065d8();
    return;
}


/* VA 0x7ff29109896, RVA 0x9896, CFG name sub_7ff29109896; exports: [] */
void sub_7ff29109896(unsigned long a0, long long a1)
{
    sub_7ff2910805c(a1 + 112);
    return;
}


/* VA 0x7ff291098b6, RVA 0x98b6, CFG name sub_7ff291098b6; exports: [] */
void sub_7ff291098b6(unsigned long a0, long long a1)
{
    sub_7ff2910805c(a1 + 96);
    return;
}


/* VA 0x7ff291098d4, RVA 0x98d4, CFG name sub_7ff291098d4; exports: [] */
void sub_7ff291098d4(unsigned long a0, long long a1)
{
    sub_7ff29106380(a1 + 56);
    return;
}


/* VA 0x7ff291098f2, RVA 0x98f2, CFG name sub_7ff291098f2; exports: [] */
void sub_7ff291098f2(unsigned long a0, void* *a1)
{
    sub_7ff29104c24(a1 + 8);
    return;
}


/* VA 0x7ff29109912, RVA 0x9912, CFG name sub_7ff29109912; exports: [] */
void sub_7ff29109912(unsigned long a0, long long a1)
{
    sub_7ff291054c4(a1 + 48);
    return;
}


/* VA 0x7ff29109932, RVA 0x9932, CFG name sub_7ff29109932; exports: [] */
void sub_7ff29109932(unsigned long a0, long long a1)
{
    sub_7ff291054c4(a1 + 56);
    return;
}


/* VA 0x7ff29109952, RVA 0x9952, CFG name sub_7ff29109952; exports: [] */
void sub_7ff29109952(unsigned long a0, long long *a1)
{
    sub_7ff291054e8(a1 + 9);
    return;
}


/* VA 0x7ff29109544, RVA 0x9544, CFG name sub_7ff29109544; exports: [] */
extern unsigned int g_7ff2910c120;

void sub_7ff29109544(unsigned long a0, unsigned long a1)
{
    g_7ff2910c120 = 4294967295;
    return;
}


/* VA 0x7ff29109563, RVA 0x9563, CFG name sub_7ff29109563; exports: [] */
void sub_7ff29109563(unsigned long a0, unsigned long a1)
{
    _unlock(8);
    return;
}


/* VA 0x7ff2910443c, RVA 0x443c, CFG name sub_7ff2910443c; exports: [] */
void sub_7ff2910443c(unsigned long long a0)
{
    if (a0)
    {
        sub_7ff291045f8();
        return;
    }
    sub_7ff291044d4();
    return;
}


/* VA 0x7ff29101984, RVA 0x1984, CFG name sub_7ff29101984; exports: [] */
int sub_7ff29101984(long long a0, char a1)
{
    unsigned int cur;  // eax
    unsigned long long v8;  // cc_dep1
    unsigned long long v9;  // cc_dep2
    unsigned long v10;  // 4114
    char v11;  // 4098
    unsigned long v12;  // 4113
    unsigned long v13;  // 4127
    char *ptr;  // rdi
    unsigned long long v3;  // cc_ndep
    unsigned long long v4;  // fs
    char v5;  // dh
    char v6;  // 4100
    unsigned long long v7;  // cc_op
    unsigned long long v0;  // [bp-0x8]

    while (true)
    {
        v6 = *(ptr);
        *(ptr) = v6 ^ (char)cur;
        v7 = 17;
        v8 = v6 ^ (char)cur;
        v9 = 0;
        v10 = _ccall(6, 17, (unsigned long long)(v6 ^ (char)cur), 0, v3);
        if ((char)v10)
            goto LABEL_0x7ff29101989;
        if ((char)v8 < 0)
            goto LABEL_0x7ff29101968;
        if ((char)v8 > 0)
        {
            v7 = 7;
            v8 = cur;
            v9 = 496101304;
            cur -= 496101304;
        }
        v11 = ptr[1340018147 + v4];
        v12 = _ccall(v7, v8, v9, v3);
        ptr[1340018147 + v4] = ptr[1340018147 + v4] + v5 + ((char)v12 & 1);
        v3 = v12 & 1;
        v0 = 72;
        v13 = _ccall(0, 9, (unsigned long long)v11, (unsigned long long)(v5 ^ (char)v12 & 1), v12 & 1);
        if (!((char)v13))
            break;
    }
    return sub_7ff29101984(a0, a1);
}


/* VA 0x7ff291054c4, RVA 0x54c4, CFG name sub_7ff291054c4; exports: [] */
typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_0 {
    char padding_0[24];
    struct struct_1 *field_18;
} struct_0;

extern struct_0 *g_7ff2910d1f8;

unsigned long long sub_7ff291054c4(unsigned long long *a0)
{
    unsigned long long v1;  // rax

    if (*(a0))
        v1 = g_7ff2910d1f8->field_18(*(a0));
    return v1;
}


/* VA 0x7ff29106380, RVA 0x6380, CFG name sub_7ff29106380; exports: [] */
typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_0 {
    char padding_0[88];
    struct struct_1 *field_58;
} struct_0;

extern struct_0 *g_7ff2910d1f8;

unsigned long long sub_7ff29106380(unsigned long long *a0)
{
    unsigned long long v1;  // rax

    if (*(a0))
        v1 = g_7ff2910d1f8->field_58(*(a0));
    return v1;
}


/* VA 0x7ff2910805c, RVA 0x805c, CFG name sub_7ff2910805c; exports: [] */
typedef struct struct_2 {
    struct struct_1 *field_0;
} struct_2;

typedef struct struct_1 {
    struct struct_0 *field_0;
} struct_1;

typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

unsigned long long sub_7ff2910805c(struct_2 **ptr)
{
    struct_1 **v1;  // rcx
    unsigned long long v2;  // rax

    v1 = *(ptr);
    if (v1)
        v2 = *(v1)->field_0(v1, 1);
    return v2;
}


/* VA 0x7ff29101c9b, RVA 0x1c9b, CFG name sub_7ff29101c9b; exports: [] */
extern char g_7febecf6726;

int sub_7ff29101c9b(unsigned long a0, unsigned long a1)
{
    unsigned long v2;  // cc_op
    unsigned long v3;  // cc_dep1
    unsigned long v4;  // cc_dep2
    unsigned long v5;  // cc_ndep
    unsigned long v6;  // 4101
    unsigned long long v7;  // rdi
    char v8;  // 4100
    char v9;  // al
    unsigned long v10;  // 4129
    unsigned long long v0;  // [bp-0x8]

    v6 = _ccall(2, v2, v3, v4, v5);
    if (!((char)v6))
    {
        v0 = v7;
        v8 = g_7febecf6726;
        g_7febecf6726 = g_7febecf6726 + v9;
        v10 = _ccall(10, 9, (unsigned long long)v9, (unsigned long long)(122 ^ (char)(v8 + v9 <= v8 ? 1 : 0) & 1), (v8 + v9 <= v8 ? 1 : 0) & 1);
        if (!((char)v10))
            goto LABEL_0x7ff29101ce5;
        [D] Unsupported jumpkind Ijk_NoDecode at address 8792486976685()
    }
}


/* VA 0x7ff291096aa, RVA 0x96aa, CFG name sub_7ff291096aa; exports: [] */
typedef struct struct_0 {
    char padding_0[64];
    unsigned long long field_40;
} struct_0;

void sub_7ff291096aa(unsigned long a0, struct_0 *a1)
{
    sub_7ff29105640(a1->field_40 + 16);
    return;
}


/* VA 0x7ff291096ca, RVA 0x96ca, CFG name sub_7ff291096ca; exports: [] */
typedef struct struct_0 {
    char padding_0[64];
    unsigned long long field_40;
} struct_0;

void sub_7ff291096ca(unsigned long a0, struct_0 *a1)
{
    sub_7ff29105640(a1->field_40 + 24);
    return;
}


/* VA 0x7ff291096ec, RVA 0x96ec, CFG name sub_7ff291096ec; exports: [] */
long long sub_7ff291096ec(unsigned long a0, unsigned long long a1)
{
    unsigned long long v1;  // [bp+0x10]

    v1 = a1;
    return sub_7ff29106640;
}


/* VA 0x7ff291097bc, RVA 0x97bc, CFG name sub_7ff291097bc; exports: [] */
typedef struct struct_0 {
    char padding_0[48];
    unsigned long long field_30;
} struct_0;

void sub_7ff291097bc(unsigned long a0, struct_0 *a1)
{
    sub_7ff29104934(a1->field_30 + 24);
    return;
}


/* VA 0x7ff291097dc, RVA 0x97dc, CFG name sub_7ff291097dc; exports: [] */
long long sub_7ff291097dc(unsigned long a0, unsigned long long a1)
{
    unsigned long long v1;  // [bp+0x10]

    v1 = a1;
    return sub_7ff291046aa;
}


/* VA 0x7ff291097ff, RVA 0x97ff, CFG name sub_7ff291097ff; exports: [] */
long long sub_7ff291097ff(unsigned long a0, unsigned long long a1)
{
    unsigned long long v1;  // [bp+0x10]

    v1 = a1;
    return sub_7ff29104572;
}


/* VA 0x7ff29109822, RVA 0x9822, CFG name sub_7ff29109822; exports: [] */
long long sub_7ff29109822(unsigned long a0, unsigned long long a1)
{
    unsigned long long v1;  // [bp+0x10]

    v1 = a1;
    return sub_7ff29104395;
}


/* VA 0x7ff29109874, RVA 0x9874, CFG name sub_7ff29109874; exports: [] */
typedef struct struct_0 {
    char padding_0[64];
    unsigned long long field_40;
} struct_0;

void sub_7ff29109874(unsigned long a0, struct_0 *a1)
{
    sub_7ff29104934(a1->field_40 + 24);
    return;
}


/* VA 0x7ff29104934, RVA 0x4934, CFG name sub_7ff29104934; exports: [] */
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

void sub_7ff29104934(CRITICAL_SECTION *a0)
{
    CRITICAL_SECTION *ptr;  // rcx

    ptr = &a0->OwningThread;
    if ((char)ptr[1].DebugInfo)
    {
        *((char *)&ptr[1].DebugInfo) = 0;
        DeleteCriticalSection(ptr);
    }
    return;
}


/* VA 0x7ff29108480, RVA 0x8480, CFG name sub_7ff29108480; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    HANDLE field_10;
} struct_0;

int sub_7ff29108480(struct_0 *a0, void* a1)
{
    int v1;  // eax

    if (a1)
        v1 = HeapFree(a0->field_10, HEAP_NONE, a1);
    return v1;
}


/* VA 0x7ff29108dc4, RVA 0x8dc4, CFG name sub_7ff29108dc4; exports: [] */
typedef struct struct_0 {
    char padding_0[56];
    long long field_38;
} struct_0;

unsigned int sub_7ff29108dc4(unsigned long a0, long long a1, unsigned long a2, struct_0 *a3)
{
    sub_7ff29108d58(a1, a3, a3->field_38);
    return 1;
}


/* VA 0x7ff29103aa8, RVA 0x3aa8, CFG name sub_7ff29103aa8; exports: [] */
long long sub_7ff29103aa8(unsigned long a0, unsigned long a1, unsigned long a2, unsigned short a3)
{
    char *v0;  // [bp-0x18]
    unsigned short v2;  // [bp+0x20]
    char v3;  // [bp+0x28]

    v2 = a3;
    v0 = &v3;
    return sub_7ff29103978();
}


/* VA 0x7ff29106a0c, RVA 0x6a0c, CFG name sub_7ff29106a0c; exports: [] */
void sub_7ff29106a0c(unsigned long a0, unsigned short a1)
{
    unsigned long long flag;  // [bp-0x18]

    flag = 0;
    sub_7ff29103b90();
    return;
}


/* VA 0x7ff29107ca4, RVA 0x7ca4, CFG name sub_7ff29107ca4; exports: [] */
extern unsigned long long g_7ff2910d1e0;

long long sub_7ff29107ca4(unsigned long long a0)
{
    char v1;  // cl

    v1 = 64 - ((unsigned int)g_7ff2910d1e0 & 63);
    return ((v1 & 63) ? a0 << (v1 & 63) | a0 >> 64 - (v1 & 63) : a0 << (v1 & 63) | a0 >> 64 - (v1 & 63)) ^ g_7ff2910d1e0;
}


/* VA 0x7ff29101fa0, RVA 0x1fa0, CFG name sub_7ff29101fa0; exports: [] */
void sub_7ff29101fa0(unsigned long a0, void* ptr, unsigned long a2, unsigned long a3, char a4)
{
    char v3;  // 4102
    char v4;  // al
    unsigned long v5;  // 4133
    unsigned long v6;  // 4112
    unsigned long long v7;  // 4133
    void* addr;  // rsi
    char v9;  // al
    void* p;  // rsi
    unsigned long v11;  // 4113
    char v0;  // [bp-0x8ad6ba6]
    void* v1;  // [bp-0x8]

    *((unsigned int *)ptr) = *((int *)ptr) ^ (unsigned int)ptr;
    v3 = *((char *)ptr);
    *((char *)ptr) = v3 + v4;
    v5 = _ccall(2, 9, (unsigned long long)v3, (unsigned long long)(v4 ^ 0), 0);
    if (!((char)v5))
    {
        __outbyte(*((unsigned short *)&ptr), v4);
        v7 = _ccall(9, (unsigned long long)v3, (unsigned long long)(v4 ^ 0), 0);
        v9 = *((char *)addr);
        p = addr + 1;
        if (((v7 ^ 1) & 1))
            goto LABEL_0x7ff2910200a;
        v11 = _ccall(0, v7 ^ 1, 0, 0);
        *((unsigned int *)p) = *((int *)p) + (unsigned int)ptr + ((unsigned int)v11 & 1);
        *((char *)p) = *((char *)p) ^ v9;
    }
    v1 = ptr;
    v6 = _ccall(2, 17, (unsigned long long)(*((char *)((void*)&ptr + 1)) & v0), 0, 0);
    if ((char)v6)
        goto LABEL_0x7ff29101f85;
    else
        goto LABEL_0x7ff29101faf;
}


/* VA 0x7ff291046aa, RVA 0x46aa, CFG name sub_7ff291046aa; exports: [] */
void sub_7ff291046aa(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned int a18)
{
}


/* VA 0x7ff29109bc4, RVA 0x9bc4, CFG name sub_7ff29109bc4; exports: [] */
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

typedef struct CRITICAL_SECTION {
    struct CRITICAL_SECTION_DEBUG *DebugInfo;
    int LockCount;
    int RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    UIntPtr SpinCount;
} CRITICAL_SECTION;

extern char g_7ff2910d258;
extern CRITICAL_SECTION g_7ff2910d260;

void sub_7ff29109bc4(void)
{
    if (g_7ff2910d258)
        DeleteCriticalSection(&g_7ff2910d260.DebugInfo);
    return;
}


/* VA 0x7ff29102014, RVA 0x2014, CFG name sub_7ff29102014; exports: [] */
char sub_7ff29102014(void* ptr, char a1, unsigned long a2, unsigned long a3, unsigned long a4)
{
    char v2;  // sil
    unsigned long long v0;  // [bp-0x8]

    *((int *)&ptr[103]) = vvar_7{r56|4b};
    v0 = 113;
    [D] PutI(904:F64x8)[t50,0] = t51()
    [D] PutI(968:I8x8)[t50,0] = 0x01()
    return v2;
}


/* VA 0x7ff29108bf0, RVA 0x8bf0, CFG name sub_7ff29108bf0; exports: [] */
extern char g_7ff2910c110;

void sub_7ff29108bf0(unsigned long a0)
{
    if (a0 != *((long long *)&g_7ff2910c110))
    {
        sub_7ff29108fa8();
        return;
    }
    else if (!(unsigned short)(__ROL__(a0, 16)))
    {
        return;
    }
    else
    {
        sub_7ff29108fa8();
        return;
    }
}


/* VA 0x7ff29104395, RVA 0x4395, CFG name sub_7ff29104395; exports: [] */
void sub_7ff29104395(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned int a16)
{
}


/* VA 0x7ff29104a04, RVA 0x4a04, CFG name sub_7ff29104a04; exports: [] */
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

extern struct_3 *g_7ff2910d300;

unsigned int sub_7ff29104a04(unsigned long a0, unsigned int a1)
{
    if (!a1)
    {
        g_7ff2910d300->field_0->field_10(g_7ff2910d300);
        return 0;
    }
    g_7ff2910d300->field_0->field_8(g_7ff2910d300);
    return 0;
}


/* VA 0x7ff29106520, RVA 0x6520, CFG name sub_7ff29106520; exports: [] */
extern char g_7ff29102520;

void* sub_7ff29106520(void* ptr, unsigned long a1)
{
    exception::exception(ptr, a1);
    *((char **)ptr) = &g_7ff29102520;
    return ptr;
}


/* VA 0x7ff2910730c, RVA 0x730c, CFG name sub_7ff2910730c; exports: [] */
long long sub_7ff2910730c(unsigned long a0, unsigned long long a1, unsigned long long a2, unsigned long long a3)
{
    unsigned long long v1;  // [bp+0x10]
    unsigned long long v2;  // [bp+0x18]
    unsigned long long v3;  // [bp+0x20]

    v1 = a1;
    v2 = a2;
    v3 = a3;
    return sub_7ff29107114();
}


/* VA 0x7ff29109582, RVA 0x9582, CFG name sub_7ff29109582; exports: [] */
typedef struct struct_0 {
    unsigned int field_0;
} struct_0;

long long sub_7ff29109582(struct_0 **a0, unsigned long a1)
{
    return *(a0)->field_0 == 3221225477;
}


/* VA 0x7ff291095a9, RVA 0x95a9, CFG name sub_7ff291095a9; exports: [] */
typedef struct struct_0 {
    unsigned int field_0;
} struct_0;

long long sub_7ff291095a9(struct_0 **a0, unsigned long a1)
{
    return *(a0)->field_0 == 3221225495;
}


/* VA 0x7ff291014f0, RVA 0x14f0, CFG name sub_7ff291014f0; exports: [] */
void sub_7ff291014f0(char a0, char a1, unsigned long a2, unsigned long long a3, char a4)
{
    char *v3;  // rax
    unsigned long v4;  // cc_ndep
    unsigned long v5;  // 4107
    unsigned int *ptr;  // rdi
    unsigned long v7;  // rsi
    char v8;  // ch
    unsigned long long v0;  // [bp-0x10]
    unsigned long long v1;  // [bp-0x8]

    v5 = _ccall(0, 5, (unsigned long long)*((char *)((void*)&v3 + 1)), (unsigned long long)*(v3), v4);
    if (!((char)v5))
        goto LABEL_0x7ff2910154b;
    v1 = 1788899378;
    *(ptr) = 430227734;
    v0 = a3;
    *(34 + (char *)ptr + v7) = *(34 + (char *)ptr + v7) | v8;
}


/* VA 0x7ff29101e0e, RVA 0x1e0e, CFG name sub_7ff29101e0e; exports: [] */
void sub_7ff29101e0e(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3)
{
    [D] Unsupported jumpkind Ijk_Privileged at address 8792486977038()
}


/* VA 0x7ff29102115, RVA 0x2115, CFG name sub_7ff29102115; exports: [] */
void sub_7ff29102115(char a0, unsigned long a1)
{
    unsigned long v2;  // cc_op
    unsigned long v3;  // cc_dep1
    unsigned long v4;  // cc_dep2
    unsigned long v5;  // cc_ndep
    unsigned long v6;  // 4101
    unsigned int *ptr;  // rax
    unsigned long v8;  // 4108
    unsigned long v9;  // rdi
    unsigned long v10;  // rbx
    unsigned long long v0;  // [bp-0x8]

    v6 = _ccall(8, v2, v3, v4, v5);
    if ((char)v6)
    {
        [D] PutI(968:I8x8)[0x00000000,0] = 0x01()
        [D] PutI(968:I8x8)[0x00000000,1] = 0x01()
        [D] PutI(968:I8x8)[0x00000000,2] = 0x01()
        [D] PutI(968:I8x8)[0x00000000,3] = 0x01()
        [D] PutI(968:I8x8)[0x00000000,4] = 0x01()
        [D] PutI(968:I8x8)[0x00000000,5] = 0x01()
        [D] PutI(968:I8x8)[0x00000000,6] = 0x01()
        [D] PutI(968:I8x8)[0x00000000,7] = 0x01()
        ptr = [D] syscall()();
        v8 = _ccall(12, v2, v3, v4, v5);
        if (!((char)v8))
            goto LABEL_0x7ff29102153;
        *(ptr) = *(ptr) - 28;
        *((unsigned int *)(v9 + v10)) = *((int *)(v9 + v10)) >> 15 | *((int *)(v9 + v10)) * 0x20000;
    }
    v0 = 148969664;
}


/* VA 0x7ff29101499, RVA 0x1499, CFG name sub_7ff29101499; exports: [] */
typedef struct struct_0 {
    char padding_0[103044453];
    char field_6245565;
} struct_0;

int sub_7ff29101499(unsigned int a0)
{
    unsigned long v2;  // cc_ndep
    unsigned long v3;  // 4133
    struct_0 *ptr;  // rcx
    char v5;  // al
    unsigned long v6;  // 4161
    unsigned long v7;  // 4109
    unsigned long v0;  // [bp+0x0]

    v3 = _ccall(0, v0 & 2261, 0, v2);
    ptr = a0 + *((int *)0x7ff8cee67da) + ((unsigned int)v3 & 1);
    v6 = _ccall(6, 17, (unsigned long long)(v5 & 178), 0, v3 & 1);
    if (!((char)v6))
    {
        v7 = _ccall(17, (unsigned long long)(v5 & 178), 0, v3 & 1);
        ptr->field_6245565 = ptr->field_6245565 + *((char *)((void*)&ptr + 1)) + ((char)v7 & 1);
    }
}


/* VA 0x7ff29102bd0, RVA 0x2bd0, CFG name sub_7ff29102bd0; exports: [] */
void sub_7ff29102bd0(char *p, char a1)
{
    char *ptr;  // rax
    char v2;  // dh
    char *addr;  // rbx

    *(ptr) = *(ptr) ^ v2;
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(addr) = *(addr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(p) = *(p) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    *(ptr) = *(ptr) + *((char *)((void*)&ptr + 1));
    return;
}


/* VA 0x7ff29102c77, RVA 0x2c77, CFG name sub_7ff29102c77; exports: [] */
char sub_7ff29102c77(char *p, unsigned long a1, unsigned long a2, unsigned long a3, char a4)
{
    void* ptr;  // rax
    char v2;  // 4109

    *((unsigned int *)ptr) = *((int *)ptr) + 1;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    v2 = *((char *)ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)(ptr * 2)) = *((char *)(ptr * 2)) + *((char *)((void*)&p + 1)) + ((char)(v2 + *((char *)&ptr) <= v2 ? 1 : 0) & 1);
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
    return *((char *)&ptr) * 2;
}


/* VA 0x7ff29105674, RVA 0x5674, CFG name sub_7ff29105674; exports: [] */
extern char g_7ff29102280;

void* sub_7ff29105674(void* ptr, char a1)
{
    *((char **)ptr) = &g_7ff29102280;
    if ((a1 & 1))
        free(ptr);
    return ptr;
}


/* VA 0x7ff29107b48, RVA 0x7b48, CFG name sub_7ff29107b48; exports: [] */
extern char g_7ff29102548;

void* sub_7ff29107b48(void* ptr, char a1)
{
    *((char **)ptr) = &g_7ff29102548;
    if ((a1 & 1))
        free(ptr);
    return ptr;
}


/* VA 0x7ff29109d29, RVA 0x9d29, CFG name sub_7ff29109d29; exports: [] */
typedef struct struct_0 {
    char padding_0[67174400];
    unsigned int field_4010000;
} struct_0;

void sub_7ff29109d29(unsigned int a0, struct_0 *ptr6)
{
    unsigned long v1;  // cc_op
    unsigned long v2;  // cc_dep1
    char *addr;  // rax
    unsigned int *ptr3;  // rsi
    unsigned long v3;  // cc_dep2
    unsigned long v4;  // cc_ndep
    unsigned long v5;  // 4101
    unsigned long v6;  // 4101
    unsigned int *ptr;  // rax
    void* p;  // rax
    unsigned int *ptr4;  // rbx
    unsigned int *ptr5;  // rax

    v5 = _ccall(2, v1, v2, v3, v4);
    if ((char)v5 || (v6 = (unsigned long)_ccall(0, v1, v2, v3, v4), !((char)v6)))
        [D] Unsupported jumpkind Ijk_NoDecode at address 8792487009581()
    *(ptr) = *(ptr) + (unsigned int)ptr;
    *(ptr) = *(ptr) + (unsigned int)ptr;
    p = (void*)_INSERT(ptr, 0, *((char *)&ptr) + 98);
    *((char *)p) = *((char *)p) + *((char *)&ptr) + 98;
    *(ptr4) = *(ptr4) + a0;
    *((unsigned int *)p) = *((int *)p) + (unsigned int)p;
    ptr5 = (unsigned int)p | ptr6->field_4010000;
    *(ptr5) = *(ptr5) + (unsigned int)ptr5;
    addr = (char *)_INSERT(ptr5, 0, *((char *)&ptr5) - 126);
    *(addr) = *(addr) + *((char *)&ptr5) - 126;
    *(ptr3) = *(ptr3) + (unsigned int)addr;
}


/* VA 0x7ff2910a0c3, RVA 0xa0c3, CFG name sub_7ff2910a0c3; exports: [] */
typedef struct struct_0 {
    char padding_0[1];
    char field_1;
} struct_0;

void sub_7ff2910a0c3(void* ptr, void* ptr3, unsigned long a2, unsigned long a3, char a4)
{
    unsigned long v2;  // rsi
    char v3;  // 4098
    unsigned long v12;  // 4157
    void* p;  // rcx
    unsigned long v14;  // 4106
    unsigned long v15;  // 4106
    unsigned long v16;  // 4120
    unsigned long v17;  // 4123
    unsigned long v18;  // 4126
    unsigned long v19;  // 4132
    unsigned long v20;  // 4135
    unsigned int *ptr4;  // rdi
    struct_0 *addr;  // rax
    char v5;  // 4102
    unsigned long v6;  // 4143
    unsigned long long v7;  // cc_ndep
    char v8;  // 4114
    char v9;  // bl
    unsigned long v10;  // cc_dep1
    unsigned long v11;  // cc_dep2
    void* v0;  // [bp-0x10]

    v3 = *((char *)ptr3 + v2);
    *((char *)ptr3 + v2) = *((char *)ptr3 + v2) + *((char *)&ptr3);
    v5 = addr->field_1;
    addr->field_1 = addr->field_1 + *((char *)((void*)&ptr3 + 1)) + ((char)(v3 + *((char *)&ptr3) <= v3 ? 1 : 0) & 1);
    v6 = _ccall(9, (unsigned long long)v5, (unsigned long long)(*((char *)((void*)&ptr3 + 1)) ^ (char)(v3 + *((char *)(void*)&ptr3) <= v3 ? 1 : 0) & 1), (v3 + *((char *)(void*)&ptr3) <= v3 ? 1 : 0) & 1);
    *((unsigned int *)ptr3) = *((int *)ptr3) - (unsigned int)ptr - ((unsigned int)v6 & 1);
    v7 = v6 & 1;
    v8 = *((char *)ptr);
    *((char *)ptr) = v8 + v9;
    v10 = v8;
    v11 = v9;
    v12 = _ccall(4, 1, (unsigned long long)v8, (unsigned long long)v9, v6 & 1);
    if (!((char)v12))
    {
        *((char *)ptr) = *((char *)ptr) + v9;
        *((unsigned int *)(ptr3 + ptr)) = *((int *)(ptr3 + ptr)) - (unsigned int)v2 - 0;
        v7 = 0;
        *((char *)ptr) = *((char *)ptr) + v9;
        v10 = *((char *)ptr);
        v11 = v9;
        v0 = ptr3;
        p = ptr - 1;
        v14 = _ccall(5, 1, v10, v11, 0);
        if (ptr - 1 & (char)v14)
            goto LABEL_7ff2910a0f0;
    }
    else
    {
        p = ptr - 1;
        v15 = _ccall(5, 1, v10, v11, v7);
        if (ptr - 1 & (char)v15)
        {
LABEL_7ff2910a0f0:
            *(ptr4) = *(ptr4) - (unsigned int)p - ((unsigned int)((char)v10 + (char)v11 <= (char)v10 ? 1 : 0) & 1);
        }
    }
    v16 = _ccall(1, v10, v11, v7);
    v17 = _ccall((unsigned long long)(char)*((char *)p), 1, v16, 1);
    v18 = _ccall((unsigned long long)(char)*((char *)p), 1, v16, 18446744073709551615);
    *((char *)p) = v17;
    v19 = _ccall(0, v18, 0, 0);
    v20 = _ccall((unsigned long long)(char)*((char *)p), 10, v19, 1);
    *((char *)p) = v20;
}


/* VA 0x7ff291095d0, RVA 0x95d0, CFG name sub_7ff291095d0; exports: [] */
typedef struct struct_0 {
    char padding_0[40];
    long long field_28;
    char padding_30[24];
    unsigned int field_48;
} struct_0;

long long sub_7ff291095d0(unsigned long a0, struct_0 *ptr)
{
    struct_0 *v1;  // [bp+0x10]

    v1 = ptr;
    ptr->field_48 = sub_7ff29107334(ptr->field_28);
    return sub_7ff291069bf;
}


/* VA 0x7ff2910963d, RVA 0x963d, CFG name sub_7ff2910963d; exports: [] */
typedef struct struct_0 {
    char padding_0[40];
    long long field_28;
    char padding_30[40];
    unsigned int field_58;
} struct_0;

long long sub_7ff2910963d(unsigned long a0, struct_0 *ptr)
{
    struct_0 *v1;  // [bp+0x10]

    v1 = ptr;
    ptr->field_58 = sub_7ff29107334(ptr->field_28);
    return sub_7ff291081ee;
}


/* VA 0x7ff2910970f, RVA 0x970f, CFG name sub_7ff2910970f; exports: [] */
typedef struct struct_0 {
    char padding_0[40];
    long long field_28;
    char padding_30[24];
    unsigned int field_48;
} struct_0;

long long sub_7ff2910970f(unsigned long a0, struct_0 *ptr)
{
    struct_0 *v1;  // [bp+0x10]

    v1 = ptr;
    ptr->field_48 = sub_7ff29107334(ptr->field_28);
    return sub_7ff29106404;
}


/* VA 0x7ff2910973e, RVA 0x973e, CFG name sub_7ff2910973e; exports: [] */
typedef struct struct_0 {
    char padding_0[40];
    long long field_28;
    char padding_30[24];
    unsigned int field_48;
} struct_0;

long long sub_7ff2910973e(unsigned long a0, struct_0 *ptr)
{
    struct_0 *v1;  // [bp+0x10]

    v1 = ptr;
    ptr->field_48 = sub_7ff29107334(ptr->field_28);
    return sub_7ff29105afb;
}


/* VA 0x7ff2910976d, RVA 0x976d, CFG name sub_7ff2910976d; exports: [] */
typedef struct struct_0 {
    char padding_0[40];
    long long field_28;
    char padding_30[24];
    unsigned int field_48;
} struct_0;

long long sub_7ff2910976d(unsigned long a0, struct_0 *ptr)
{
    struct_0 *v1;  // [bp+0x10]

    v1 = ptr;
    ptr->field_48 = sub_7ff29107334(ptr->field_28);
    return sub_7ff29105567;
}


/* VA 0x7ff29109845, RVA 0x9845, CFG name sub_7ff29109845; exports: [] */
typedef struct struct_0 {
    char padding_0[40];
    long long field_28;
    char padding_30[24];
    unsigned int field_48;
} struct_0;

long long sub_7ff29109845(unsigned long a0, struct_0 *ptr)
{
    struct_0 *v1;  // [bp+0x10]

    v1 = ptr;
    ptr->field_48 = sub_7ff29107334(ptr->field_28);
    return sub_7ff29108701;
}


/* VA 0x7ff2910a0f5, RVA 0xa0f5, CFG name sub_7ff2910a0f5; exports: [] */
void sub_7ff2910a0f5(unsigned long a0, unsigned long long a1, unsigned long a2, unsigned long a3, char a4)
{
    void* ptr;  // rax
    char *addr;  // rdi
    char v4;  // 4147
    void* p;  // rax
    unsigned long long v0;  // [bp-0x8]

    v0 = a1;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *(addr) = *(addr) ^ *((char *)((void*)&ptr + 1));
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((unsigned int *)ptr) = *((int *)ptr) + (unsigned int)ptr;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((unsigned int *)ptr) = *((int *)ptr) + (unsigned int)ptr;
    v4 = *((char *)ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    p = (void*)_INSERT(ptr, 0, *((char *)&ptr) - 95 + ((char)(v4 + *((char *)&ptr) <= v4 ? 1 : 0) & 1));
    *((char *)p) = *((char *)p) + *((char *)&ptr) - 95 + ((char)(v4 + *((char *)&ptr) <= v4 ? 1 : 0) & 1);
    *((unsigned int *)p) = *((int *)p) | (unsigned int)p;
    *((char *)p) = *((char *)p) + *((char *)&ptr) - 95 + ((char)(v4 + *((char *)&ptr) <= v4 ? 1 : 0) & 1);
    8792487010788();
}


/* VA 0x7ff29101403, RVA 0x1403, CFG name sub_7ff29101403; exports: [] */
void sub_7ff29101403(void* p, unsigned long a1, char a2)
{
    unsigned long long v2;  // 4114
    unsigned int *ptr;  // rdi
    unsigned int v4;  // 4130
    unsigned long v5;  // 4135
    unsigned long v6;  // 4138
    unsigned long v7;  // 4149
    unsigned long long v0;  // [bp+0x0]

    *((int *)&p[101]) = (int)p[101] >> 4;
    if (!p)
        goto LABEL_0x7ff2910142f;
    v2 = v0;
    v4 = *(ptr);
    v5 = _ccall(0, v2 & 2261, 0, 0);
    *(ptr) = v4 >> 5 | v4 * 0x8000000;
    v6 = _ccall(43, (unsigned long long)(__ROR__(v4, 5)), 0, v5);
    v0 = v6 | ((char)(v2 >> 10) ? 18446744073709551615 : 1) & 0x400 | ((char)(v2 >> 21) ? 1 : 0) * 0x200000 & 0x200000 | ((char)(v2 >> 18) ? 1 : 0) * 0x40000 & 0x40000;
    v7 = _ccall(6, 43, (unsigned long long)(__ROR__(v4, 5)), 0, v5);
}


/* VA 0x7ff29108208, RVA 0x8208, CFG name sub_7ff29108208; exports: [] */
unsigned long long sub_7ff29108208(void)
{
    unsigned int v1;  // eax

    v1 = (unsigned long long)GetLastError();
    if (v1 > 0)
        v1 = v1 & 65535 | 0x80070000;
    if (v1 < 0)
        return v1;
    return 2147500037;
}


/* VA 0x7ff29108668, RVA 0x8668, CFG name sub_7ff29108668; exports: [] */
typedef struct struct_2 {
    struct struct_0 *field_0;
    unsigned int field_8;
} struct_2;

typedef struct struct_0 {
    char padding_0[16];
    struct struct_1 *field_10;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

int sub_7ff29108668(struct_2 *ptr)
{
    int v1;  // eax
    unsigned long long flag;  // rdx

    InterlockedExchangeAdd(&ptr->field_8, 4294967295);
    v1 = ptr->field_8 - 1;
    if (v1 > 0)
        return v1;
    if (!ptr)
        return 0;
    flag = 1;
    ptr->field_0->field_10();
    return 0;
}


/* VA 0x7ff2910145d, RVA 0x145d, CFG name sub_7ff2910145d; exports: [] */
long long sub_7ff2910145d(unsigned long a0)
{
    unsigned long v1;  // cc_op
    unsigned long v2;  // cc_dep1
    unsigned long v3;  // cc_dep2
    unsigned long v4;  // cc_ndep
    unsigned long v5;  // 4101
    unsigned int v6;  // esi

    v5 = _ccall(14, v1, v2, v3, v4);
    if (!((char)v5))
    {
        if (v6 < *((int *)8793233893696))
            [D] Unsupported jumpkind Ijk_Privileged at address 8792486974546()
        *((char *)(*((long long *)0x4bbc423001a2bfe8) - 117)) = *((char *)(*((long long *)0x4bbc423001a2bfe8) - 117)) * 2;
        return *((long long *)0x4bbc423001a2bfe8);
    }
}


/* VA 0x7ff29104734, RVA 0x4734, CFG name sub_7ff29104734; exports: [] */
typedef struct struct_2 {
    struct struct_0 *field_0;
    unsigned int field_8;
} struct_2;

typedef struct struct_0 {
    char padding_0[32];
    struct struct_1 *field_20;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

int sub_7ff29104734(struct_2 *ptr)
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
        ptr->field_0->field_20();
    }
    return v1 - 1;
}


/* VA 0x7ff29104790, RVA 0x4790, CFG name sub_7ff29104790; exports: [] */
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

int sub_7ff29104790(struct_2 *ptr)
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


/* VA 0x7ff29101a29, RVA 0x1a29, CFG name sub_7ff29101a29; exports: [] */
extern unsigned int g_e3d27187;

char sub_7ff29101a29(unsigned long long a0, unsigned long a1)
{
    unsigned long v1;  // cc_op
    unsigned long v2;  // cc_dep1
    char *ptr;  // rdi
    unsigned long v3;  // cc_dep2
    unsigned long v4;  // cc_ndep
    unsigned long v5;  // 4114
    unsigned long v6;  // cc_op
    unsigned long v7;  // cc_dep1
    unsigned long v8;  // cc_dep2
    unsigned long v9;  // cc_ndep
    unsigned long v10;  // 4102

    if (a0)
    {
        [D] PutI(904:F64x8)[t1,0] = t2()
        [D] PutI(968:I8x8)[t1,0] = 0x01()
        v5 = _ccall(4, v1, v2, v3, v4);
        if (!((char)v5))
            goto LABEL_0x7ff29101a92;
        if ([D] unsupported_<class 'pyvex.expr.GetI'>())
        {
            [D] PutI(904:F64x8)[t3,0] = t6()
            [D] PutI(968:I8x8)[t3,0] = 0x01()
        }
        else
        {
            [D] PutI(904:F64x8)[t3,0] = t6()
            [D] PutI(968:I8x8)[t3,0] = 0x01()
        }
        g_e3d27187 = g_e3d27187 >> 1;
    }
    else
    {
        v10 = _ccall(8, v6, v7, v8, v9);
        if ((char)v10)
            [D] Unsupported jumpkind Ijk_SigTRAP at address 8792486976217()
        *(ptr) = *(ptr);
    }
}


/* VA 0x7ff29105640, RVA 0x5640, CFG name sub_7ff29105640; exports: [] */
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

long long sub_7ff29105640(struct_1 **ptr)
{
    struct_1 *p;  // rcx
    unsigned long v2;  // rax
    unsigned long long flag;  // rdx

    p = *(ptr);
    if (p)
    {
        InterlockedExchangeAdd(&p->field_8, 4294967295);
        v2 = p->field_8 - 1;
        if ((unsigned int)v2 <= 0 && p)
        {
            flag = 1;
            v2 = p->field_0->field_0();
        }
    }
    return v2;
}


/* VA 0x7ff291021e7, RVA 0x21e7, CFG name sub_7ff291021e7; exports: [] */
typedef struct struct_0 {
    char padding_0[1517502904];
    char field_5a7341b8;
} struct_0;

void sub_7ff291021e7(struct_0 *a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4)
{
    char *p;  // rdi
    char *v2;  // rsi
    char v3;  // al
    char *ptr;  // rax
    struct_0 *v5;  // rcx
    unsigned long v6;  // cc_ndep
    unsigned long v7;  // 4104

    *(p) = *(v2);
    ptr = (char *)_INSERT(v3, 0, (v3 ^ 215) & *((char *)((void*)&a0 + 1)));
    v5 = &a0->padding_0[1];
    if (&a0->padding_0[1] & ((v3 ^ 215) & *((char *)((void*)&a0 + 1))))
    {
        *(ptr) = *(ptr) + *((char *)&ptr);
        *(ptr) = *(ptr) + *((char *)&ptr);
    }
    else if (*((char *)((void*)&ptr + 1)) <= v5[1].padding_0[0])
    {
        [D] Unsupported jumpkind Ijk_SigTRAP at address 8792486977977()
    }
    else
    {
        v7 = _ccall(8, 5, (unsigned long long)*((char *)((void*)&ptr + 1)), (unsigned long long)v5[1].padding_0[0], v6);
        if (!((char)v7))
            if (&v5->padding_0[1])
                goto LABEL_0x7ff29102271;
    }
}


/* VA 0x7ff291084bc, RVA 0x84bc, CFG name sub_7ff291084bc; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    HANDLE field_10;
} struct_0;

unsigned long long sub_7ff291084bc(struct_0 *a0, void* a1)
{
    return (!a1 ? 2147942487 : ~(-(0 < HeapValidate(a0->field_10, HEAP_NONE, a1))) & 2147549183);
}


/* VA 0x7ff29108e00, RVA 0x8e00, CFG name sub_7ff29108e00; exports: [] */
unsigned int sub_7ff29108e00(void* ptr)
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


/* VA 0x7ff29108238, RVA 0x8238, CFG name sub_7ff29108238; exports: [] */
extern long long g_7ff2910cae8;

long long sub_7ff29108238(unsigned long long *ptr, long long a1)
{
    unsigned long long v1;  // rax

    v1 = sub_7ff291065e8(a1, &g_7ff2910cae8);
    *(ptr) = v1;
    return ~(-(0 < v1)) & 2147942414;
}


/* VA 0x7ff29108c18, RVA 0x8c18, CFG name sub_7ff29108c18; exports: [] */
long long sub_7ff29108c18(unsigned long a0, char a1)
{
    if ((a1 & 1))
        sub_7ff291065d8();
    return a0;
}


/* VA 0x7ff291073f4, RVA 0x73f4, CFG name sub_7ff291073f4; exports: [] */
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

unsigned long long sub_7ff291073f4(CRITICAL_SECTION *ptr)
{
    unsigned long long v2;  // rax

    v2 = (!InitializeCriticalSectionAndSpinCount(&ptr->LockCount, 0) ? sub_7ff29108208() : 0);
    if ((unsigned int)v2 >= 0)
    {
        *((char *)&ptr->DebugInfo) = 1;
        v2 = 0;
    }
    return v2;
}


/* VA 0x7ff29107cc8, RVA 0x7cc8, CFG name sub_7ff29107cc8; exports: [] */
extern void* g_7ff2910d0a8;

int sub_7ff29107cc8(void)
{
    HANDLE v1;  // rax
    int v2;  // eax

    if (g_7ff2910d0a8)
    {
        v1 = GetProcessHeap();
        v2 = HeapFree(v1, HEAP_NONE, g_7ff2910d0a8);
    }
    g_7ff2910d0a8 = 0;
    return v2;
}


/* VA 0x7ff291020f6, RVA 0x20f6, CFG name sub_7ff291020f6; exports: [] */
typedef struct struct_0 {
    char padding_0[93];
    unsigned int field_5d;
} struct_0;

void sub_7ff291020f6(char a0, unsigned long a1, unsigned long a2, unsigned long a3, char a4)
{
    unsigned int v3;  // eax
    struct_0 *addr;  // rdi
    unsigned int v13;  // eax
    unsigned long v14;  // 4106
    unsigned int *ptr;  // rax
    char v16;  // ch
    unsigned long v5;  // cc_op
    unsigned long v6;  // cc_dep1
    unsigned long v7;  // cc_dep2
    unsigned long v8;  // cc_ndep
    unsigned long v9;  // 4105
    unsigned long v10;  // 4101
    unsigned long v11;  // 4101
    unsigned int *p;  // rsi
    struct_0 *v0;  // [bp-0x8]
    char v2;  // [bp+0xfff96]

    v3 = _INSERT(0, 0, 22);
    v0 = addr;
    v9 = _ccall(6, v5, v6, v7, v8);
    if ((char)v9)
    {
        v10 = _ccall(14, v5, v6, v7, v8);
        if ((char)v10)
            *((int *)&(&addr->padding_0)[1]) = *((int *)&(&addr->padding_0)[1]) >> (a0 & 31) | *((int *)&(&addr->padding_0)[1]) << 32 - (a0 & 31);
        v11 = _ccall(4, v5, v6, v7, v8);
        if ((char)v11)
        {
            v13 = v3 & 2939476921;
            if (!(v3 & 2939476921))
                goto LABEL_0x7ff291021d1;
            v14 = _ccall(10, 6, (unsigned long long)(unsigned short)v13, 5859, v8);
            if ((char)v14)
                goto LABEL_0x7ff291021e6;
            ptr = v13 + 1909570444;
            *(ptr) = *(ptr) - _INSERT(a0 CONCAT 0, 1, v16 ^ v2) - ((unsigned int)(v13 + 1909570444 <= v13 ? 1 : 0) & 1);
        }
        *(p) = *(p) >> 1 | *(p) * 0x80000000;
    }
}


/* VA 0x7ff29106078, RVA 0x6078, CFG name sub_7ff29106078; exports: [] */
char sub_7ff29106078(unsigned long a0, unsigned long a1, char *ptr)
{
    unsigned int v2;  // eax
    unsigned int v1;  // [bp+0x20]

    v2 = sub_7ff291061e8();
    if (v2 >= 0)
        *(ptr) = v1;
    return v2;
}


/* VA 0x7ff291067a8, RVA 0x67a8, CFG name sub_7ff291067a8; exports: [] */
long long sub_7ff291067a8(unsigned long a0, unsigned short a1, unsigned long a2, unsigned int a3)
{
    char *v0;  // [bp-0x28]
    unsigned long long v1;  // [bp-0x20]
    unsigned long long flag;  // [bp-0x18]
    unsigned int v4;  // [bp+0x20]

    v4 = a3;
    flag = 0;
    v1 = 4;
    v0 = &v4;
    return sub_7ff29103b90();
}


/* VA 0x7ff2910742c, RVA 0x742c, CFG name sub_7ff2910742c; exports: [] */
long long sub_7ff2910742c(unsigned long a0, unsigned short a1, unsigned long a2, unsigned long a3)
{
    char *v0;  // [bp-0x28]
    unsigned long long v1;  // [bp-0x20]
    unsigned long long flag;  // [bp-0x18]
    unsigned long v4;  // [bp+0x20]

    v4 = a3;
    flag = 0;
    v1 = 8;
    v0 = &v4;
    return sub_7ff29103b90();
}


/* VA 0x7ff2910878c, RVA 0x878c, CFG name sub_7ff2910878c; exports: [] */
extern unsigned long long g_7ff2910d338;
extern unsigned long long g_7ff2910d340;

unsigned int sub_7ff2910878c(void)
{
    unsigned long long *ptr;  // rax

    ptr = malloc(0x100);
    g_7ff2910d340 = ptr;
    g_7ff2910d338 = ptr;
    if (ptr)
    {
        *(ptr) = 0;
        return 0;
    }
    return 1;
}


/* VA 0x7ff29107e94, RVA 0x7e94, CFG name sub_7ff29107e94; exports: [] */
extern char g_7ff291025c8;

void* sub_7ff29107e94(void* ptr, char a1)
{
    *((char **)ptr) = &g_7ff291025c8;
    if ((a1 & 1))
        HeapFree(GetProcessHeap(), HEAP_NONE, ptr);
    return ptr;
}


/* VA 0x7ff29107bbc, RVA 0x7bbc, CFG name sub_7ff29107bbc; exports: [] */
unsigned int sub_7ff29107bbc(void* a0)
{
    void* ptr;  // rbx

    ptr = a0 - 48;
    if (!(char)ptr[80])
        return 0;
    *((char *)&ptr[80]) = 0;
    if (!*((char *)ptr))
        return memset(ptr, 0, 48);
    DeleteCriticalSection(ptr + 8);
    return memset(ptr, 0, 48);
}


/* VA 0x7ff29107e54, RVA 0x7e54, CFG name sub_7ff29107e54; exports: [] */
typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

extern struct_0 *g_7ff2910d0a8;
extern char g_7ff2910d30c;

long long sub_7ff29107e54(void)
{
    if (!g_7ff2910d30c)
    {
        sub_7ff29107d04();
        g_7ff2910d30c = 1;
    }
    return (!g_7ff2910d0a8 ? sub_7ff29107c88 : g_7ff2910d0a8->field_0 ^ g_7ff2910d0a8);
}


/* VA 0x7ff291064e0, RVA 0x64e0, CFG name sub_7ff291064e0; exports: [] */
extern char g_7ff29102520;

void* sub_7ff291064e0(void* ptr, char a1)
{
    *((char **)ptr) = &g_7ff29102520;
    if ((a1 & 1))
        free(ptr);
    return ptr;
}


/* VA 0x7ff291020be, RVA 0x20be, CFG name sub_7ff291020be; exports: [] */
extern unsigned int g_7fefce75db8;

void sub_7ff291020be(char a0)
{
    unsigned int *v3;  // rsi
    unsigned long v4;  // cc_op
    unsigned int *v11;  // rdi
    unsigned int v12;  // eax
    char v13;  // al
    unsigned long v14;  // 4164
    unsigned long v5;  // cc_dep1
    unsigned long v6;  // cc_dep2
    unsigned long v7;  // cc_ndep
    unsigned long v8;  // 4105
    void* ptr;  // rdi
    unsigned int *p;  // rdi
    unsigned int v0;  // [bp-0x1aa00a8a]
    unsigned int *v1;  // [bp-0x8]

    v1 = v3;
    v8 = _ccall(2, v4, v5, v6, v7);
    if (!((char)v8))
    {
        *(p) = *(v3);
        v11 = p + 1;
        v0 = v12;
        v13 = (char)v12 + 43 | 197;
        v14 = _ccall(4, 1, (unsigned long long)((v13 & 160) - 127), 102, 0);
        if ((char)v14)
        {
            [D] amd64g_dirtyhelper_storeF80le(vvar_20{r72|8b}, Reinterpret(F64->I64, ((([D] unsupported_<class 'pyvex.expr.GetI'>() != 0x0<8>)) ? ([D] unsupported_<class 'pyvex.expr.GetI'>()) : (nan<64>))))
            [D] PutI(968:I8x8)[t8,0] = 0x00()
        }
        InterlockedExchange(_INSERT((v13 & 160) - 25 CONCAT 0, 0, (v13 & 160) - 25 & 84) + 2039429851, (unsigned int)v11);
        g_7fefce75db8 = -(g_7fefce75db8);
    }
    else if ((a0 & 31))
    {
        *((int *)&ptr[29]) = (int)ptr[29] >> (a0 & 31);
    }
    else
    {
        *((int *)&ptr[29]) = (int)ptr[29] >> (a0 & 31);
    }
}


/* VA 0x7ff29107b78, RVA 0x7b78, CFG name sub_7ff29107b78; exports: [] */
typedef struct struct_0 {
    char padding_0[32];
    char field_20;
} struct_0;

unsigned int sub_7ff29107b78(struct_0 *a0)
{
    struct_0 *ptr;  // rbx
    unsigned int v2;  // eax

    ptr = &a0[1].padding_0[15];
    if (ptr[2].padding_0[14])
        return 2147942487;
    ptr[2].padding_0[14] = 1;
    v2 = sub_7ff291069a4(sub_7ff29107bf8, ptr);
    if (v2 >= 0)
        return 0;
    ptr[2].padding_0[14] = 0;
    return v2;
}


/* VA 0x7ff29109e54, RVA 0x9e54, CFG name sub_7ff29109e54; exports: [] */
typedef struct struct_0 {
    char padding_0[17];
    char field_11;
} struct_0;

extern char g_7ff3600ad67;

void sub_7ff29109e54(char *ptr3, void* p, unsigned long a2, unsigned long a3, char a4)
{
    unsigned int *ptr4;  // rax
    char v3;  // 4105
    unsigned long v12;  // cc_ndep
    unsigned long v13;  // 4186
    char v14;  // 4096
    unsigned long v15;  // 4121
    unsigned long long v16;  // 4139
    unsigned long long v17;  // cc_ndep
    char *ptr;  // rax
    char v19;  // 4100
    unsigned long v20;  // 4115
    char v4;  // al
    char *ptr5;  // rax
    char *ptr6;  // rsi
    char v7;  // 4120
    struct_0 *ptr7;  // rax
    unsigned long long v9;  // rcx
    char *addr;  // rax
    char v11;  // 4143
    char v0;  // [bp+0x0]

    *((unsigned int *)p) = *((int *)p) + (unsigned int)ptr3;
    *(ptr4) = *(ptr4) + (unsigned int)ptr4;
    v3 = *((char *)p);
    v4 = _INSERT(ptr4, 1, *((char *)((void*)&ptr4 + 1)) | *((char *)p));
    *(ptr3) = *(ptr3) + v4;
    ptr5 = v4 | 4;
    *((char *)(&v0 + ptr6)) = *((char *)(&v0 + ptr6)) + *((char *)&ptr3);
    v7 = *(ptr5);
    ptr7 = (struct_0 *)_INSERT(ptr5, 0, v4 | 4 | *(ptr5) | 114);
    ptr7->field_11 = ptr7->field_11 | *((char *)((void*)&p + 1));
    v9 = _INSERT(ptr3, 0, *((char *)&ptr3) & *((char *)p));
    *((char *)p) = *((char *)p) + (*((char *)((void*)&ptr4 + 1)) | v3);
    addr = (char *)_INSERT(ptr7, 0, (v4 | 4 | v7 | 114) ^ 25);
    v11 = g_7ff3600ad67;
    g_7ff3600ad67 = v11 + *((char *)&p);
    v13 = _ccall(5, 1, (unsigned long long)v11, (unsigned long long)*((char *)(void*)&p), v12);
    if (!(v9 - 1 & (char)v13))
    {
        v14 = *(addr);
        v15 = _ccall(1, (unsigned long long)v11, (unsigned long long)*((char *)(void*)&p), v12);
        *(addr) = v14 >> 1 | v14 * 128;
        v16 = _ccall(41, (unsigned long long)(__ROR__(v14, 1)), 0, v15);
        v17 = v16;
        *(ptr6) = *(ptr6);
    }
    ptr = v9 - 1 & 4294967295;
    v19 = *(ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    v20 = _ccall(0, 1, (unsigned long long)v19, (unsigned long long)*((char *)(void*)&ptr), v17);
    if ((char)v20)
    {
        *(ptr) = *(ptr) + *((char *)&ptr);
        *(ptr) = *(ptr) + *((char *)&ptr);
        *(ptr) = *(ptr) + *((char *)&ptr);
    }
    *(ptr) = *(ptr) + *((char *)&ptr);
}


/* VA 0x7ff29108e8c, RVA 0x8e8c, CFG name sub_7ff29108e8c; exports: [] */
typedef struct struct_0 {
    char padding_0[36];
    unsigned int field_24;
} struct_0;

extern char g_7ff29100000;

int sub_7ff29108e8c(long long a0)
{
    struct_0 *ptr;  // rax

    ptr = sub_7ff29108e00(&g_7ff29100000);
    if ((unsigned int)ptr)
    {
        ptr = sub_7ff29108e40(&g_7ff29100000, a0 - &g_7ff29100000, a0 - &g_7ff29100000);
        if (ptr)
            ptr = ~(ptr->field_24 >> 31) & 1;
    }
    return *((unsigned int *)&ptr);
}


/* VA 0x7ff29104958, RVA 0x4958, CFG name sub_7ff29104958; exports: [] */
typedef struct struct_0 {
    char padding_0[56];
    char field_38;
} struct_0;

struct_0 * sub_7ff29104958(struct_0 *a0, char a1)
{
    struct_0 *ptr;  // rcx

    ptr = &a0->padding_0[16];
    if (ptr->padding_0[40])
    {
        ptr->padding_0[40] = 0;
        DeleteCriticalSection(ptr);
    }
    if ((a1 & 1))
        free(a0);
    return a0;
}


/* VA 0x7ff29107bf8, RVA 0x7bf8, CFG name sub_7ff29107bf8; exports: [] */
unsigned int sub_7ff29107bf8(char *ptr)
{
    unsigned int v1;  // eax

    if (ptr)
        *(ptr) = 0;
    v1 = sub_7ff291073f4(ptr);
    if (v1 >= 0)
    {
        return 0;
    }
    else if (*(ptr))
    {
        DeleteCriticalSection(ptr + 8);
        return v1;
    }
    else
    {
        return v1;
    }
}


/* VA 0x7ff29107c40, RVA 0x7c40, CFG name sub_7ff29107c40; exports: [] */
unsigned int sub_7ff29107c40(char *ptr)
{
    unsigned int v1;  // eax

    if (ptr)
        *(ptr) = 0;
    v1 = sub_7ff291073f4(ptr);
    if (v1 >= 0)
        return 0;
    if (!*(ptr))
        return v1;
    DeleteCriticalSection(ptr + 8);
    return v1;
}


/* VA 0x7ff29102990, RVA 0x2990, CFG name sub_7ff29102990; exports: [] */
extern char g_7fef91029c5;
extern unsigned int g_90000029;

int sub_7ff29102990(void)
{
    void* ptr;  // rax

    *((unsigned int *)ptr) = *((int *)ptr) + (unsigned int)ptr;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    [D] PutI(904:F64x8)[t122,0] = t123()
    [D] PutI(968:I8x8)[t122,0] = 0x01()
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    g_90000029 = g_90000029 + 1879048151;
    *((char *)&g_90000029) = (char)g_90000029 + 41;
    *((char *)&g_90000029) = (char)g_90000029 + 41;
    *((char *)&g_90000029) = (char)g_90000029 + 41;
    *((char *)&g_90000029) = (char)g_90000029 + 41;
    *((char *)&g_90000029) = (char)g_90000029 + 41;
    *((char *)&g_90000029) = (char)g_90000029 + 41;
    *((char *)&g_90000029) = (char)g_90000029 + 41;
    *((char *)&g_90000029) = (char)g_90000029 + 41;
    *((char *)&g_90000029) = (char)g_90000029 + 41;
    *((char *)&g_90000029) = (char)g_90000029 + 41;
    *((char *)&g_90000029) = (char)g_90000029 + 41;
    *((char *)&g_90000029) = (char)g_90000029 + 41;
    g_7fef91029c5 = g_7fef91029c5 + 41;
    g_90000029 = g_90000029 + 1879048151;
    *((char *)&g_90000029) = (char)g_90000029 + 41;
    *((char *)&g_90000029) = (char)g_90000029 + 41;
    *((char *)&g_90000029) = (char)g_90000029 + 41;
    *((char *)&g_90000029) = (char)g_90000029 + 41;
}


/* VA 0x7ff29103b90, RVA 0x3b90, CFG name sub_7ff29103b90; exports: [] */
unsigned int sub_7ff29103b90(long long a0, unsigned int a1, long long a2, unsigned short a3)
{
    char v1;  // [bp+0x28]

    sub_7ff29103acc();
    sub_7ff29103978(a0, a1, a2, a3, &v1);
    return 0;
}


/* VA 0x7ff29106a30, RVA 0x6a30, CFG name sub_7ff29106a30; exports: [] */
unsigned int sub_7ff29106a30(long long a0, unsigned short a1, long long a2, unsigned int a3)
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
    return sub_7ff29103b90(a0, 43, a2, a1);
}


/* VA 0x7ff29102ae1, RVA 0x2ae1, CFG name sub_7ff29102ae1; exports: [] */
char sub_7ff29102ae1(char a0, char *ptr4)
{
    char *ptr5;  // rax
    char v2;  // 4097
    void* ptr;  // rax
    char *addr;  // rax
    char *v5;  // rax
    void* ptr3;  // rax
    char *p;  // rax

    v2 = *(ptr5);
    ptr = (void*)_INSERT(ptr5, 0, *((char *)&ptr5) - v2);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr5) - v2;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr5) - v2;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr5) - v2;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr5) - v2;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr5) - v2;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr5) - v2;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr5) - v2;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr5) - v2;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr5) - v2;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr5) - v2;
    *(ptr4) = *(ptr4) + *((char *)&ptr5) - v2;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr5) - v2;
    *((char *)ptr) = *((char *)ptr) + a0;
    addr = (unsigned int)ptr - *((int *)ptr);
    *(addr) = *(addr) + *((char *)&addr);
    *(addr) = *(addr) + *((char *)&addr);
    *(addr) = *(addr) + *((char *)&addr);
    *(addr) = *(addr) + *((char *)&addr);
    v5 = (char *)_INSERT(addr, 0, *((char *)&addr) + a0);
    ptr3 = (void*)_INSERT(v5, 0, *((char *)&addr) + a0 - *(v5));
    *((char *)ptr3) = *((char *)ptr3) + *((char *)((void*)&ptr3 + 1));
    p = (unsigned int)ptr3 - *((int *)ptr3);
    *(p) = *(p) + *((char *)&p);
    *(p) = *(p) + *((char *)&p);
    *(p) = *(p) + *((char *)&p);
    *(p) = *(p) + *((char *)&p);
    *(p) = *(p) + *((char *)&p);
    *(p) = *(p) + *((char *)&p);
    *(p) = *(p) + *((char *)&p);
    *(p) = *(p) + *((char *)&p);
    *(p) = *(p) + *((char *)&ptr4);
    return *((char *)&p);
}


/* VA 0x7ff29109b78, RVA 0x9b78, CFG name sub_7ff29109b78; exports: [] */
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

extern struct_2 *g_7ff2910ca40;
extern char g_7ff2910ca48;
extern long long g_7ff2910d210;

long long sub_7ff29109b78(void)
{
    struct_0 **i;  // rbx
    struct_0 **v2;  // rax

    i = g_7ff2910ca40;
    for (v2 = *((long long *)&g_7ff2910ca48); i < v2; i += 1)
    {
        if (*(i))
        {
            *(i)->field_40(0);
            v2 = *((long long *)&g_7ff2910ca48);
        }
    }
    return sub_7ff291040f4(&g_7ff2910d210);
}


/* VA 0x7ff29108e40, RVA 0x8e40, CFG name sub_7ff29108e40; exports: [] */
typedef struct struct_0 {
    char padding_0[6];
    unsigned short field_6;
    char padding_8[12];
    unsigned short field_14;
    char padding_16[38];
    unsigned int field_3c;
} struct_0;

unsigned int [10] sub_7ff29108e40(struct_0 *p, unsigned long a1)
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


/* VA 0x7ff29101a0b, RVA 0x1a0b, CFG name sub_7ff29101a0b; exports: [] */
extern unsigned int g_7feb9c680af;

void sub_7ff29101a0b(char a0, unsigned long a1, unsigned long a2, unsigned long a3, char a4)
{
    char v2;  // al
    unsigned long v12;  // cc_dep2
    unsigned long v13;  // 4101
    unsigned long v14;  // 4101
    char v4;  // ah
    void* ptr;  // rax
    unsigned long v6;  // cc_op
    unsigned long v7;  // cc_dep1
    unsigned long v8;  // cc_dep2
    unsigned long v9;  // cc_ndep
    unsigned long v10;  // 4105
    long long v11;  // cc_dep1
    unsigned long long v0;  // [bp-0x8]

    ptr = (void*)_INSERT(_INSERT(v2 CONCAT 0, 1, 0), 0, v2 + v4 * 114);
    v10 = _ccall(0, v6, v7, v8, v9);
    if ((char)v10)
        [D] Unsupported jumpkind Ijk_Privileged at address 8792486976015()
    while (true)
    {
        v0 = 1629334360;
        v11 = g_7feb9c680af >> 1;
        v12 = g_7feb9c680af;
        g_7feb9c680af = g_7feb9c680af >> 1;
        if ([D] unsupported_<class 'pyvex.expr.GetI'>())
        {
            [D] PutI(904:F64x8)[t3,0] = t4()
            [D] PutI(968:I8x8)[t3,0] = 0x01()
            v13 = _ccall(0, 35, v11, v12, v9);
            if ((char)v13)
                break;
        }
        else
        {
            [D] PutI(904:F64x8)[t3,0] = t4()
            [D] PutI(968:I8x8)[t3,0] = 0x01()
            v14 = _ccall(0, 35, v11, v12, v9);
            if ((char)v14)
                break;
        }
        a0 = _INSERT(a0, 1, a0 + *((char *)ptr));
        *((char *)&ptr[642621691]) = (char)ptr[642621691] | a0;
        ptr = (void*)_INSERT(ptr, 0, (*((char *)&ptr) | 198) & 233);
    }
    [D] Unsupported jumpkind Ijk_NoDecode at address 8792486976135()
}


/* VA 0x7ff2910297b, RVA 0x297b, CFG name sub_7ff2910297b; exports: [] */
void sub_7ff2910297b(unsigned long a0, char *ptr3)
{
    unsigned long v2;  // cc_op
    unsigned long v3;  // cc_dep1
    char v12;  // bl
    unsigned long v4;  // cc_dep2
    unsigned long v5;  // cc_ndep
    unsigned long v6;  // 4102
    unsigned long long v7;  // r14
    unsigned long v8;  // 4105
    char *p;  // rax
    void* addr;  // rax
    char ptr[50331843];  // rax
    unsigned long long v0;  // [bp-0x8]

    v6 = _ccall(0, v2, v3, v4, v5);
    if ((char)v6)
    {
        *(p) = *(p) + *((char *)&p);
        *(ptr3) = *(ptr3) + 1;
        *(p) = *(p) + *((char *)&p);
        v0 = 18446744072770027562;
        addr = (void*)_INSERT(p, 0, *((char *)&p) - *(p));
        *((char *)addr) = *((char *)addr) + *((char *)((void*)&addr + 1));
        ptr = (unsigned int)addr - *((int *)addr);
        ptr[0] = ptr[0] + *((char *)&ptr);
        ptr[0] = ptr[0] + *((char *)&ptr);
        ptr[0] = ptr[0] + *((char *)&ptr);
        ptr[0] = ptr[0] + *((char *)&ptr);
        ptr[0] = ptr[0] + *((char *)&ptr);
        ptr[0] = ptr[0] + *((char *)&ptr);
        ptr[0] = ptr[0] + *((char *)&ptr);
        ptr[0] = ptr[0] + *((char *)&ptr);
        ptr[0] = ptr[0] + *((char *)&ptr);
        ptr[0] = ptr[0] + *((char *)&ptr);
        ptr[0] = ptr[0] + *((char *)&ptr);
        ptr[0] = ptr[0] + *((char *)&ptr);
        ptr[0] = ptr[0] + *((char *)&ptr);
        ptr[0] = ptr[0] + *((char *)&ptr);
        ptr[50331842] = ptr[50331842] + v12;
        ptr[0] = ptr[0] + *((char *)&ptr);
        ptr[0] = ptr[0] + *((char *)&ptr);
        ptr[0] = ptr[0] + *((char *)&ptr);
    }
    v0 = v7;
    v8 = _ccall(0, v2, v3, v4, v5);
    if ((char)v8)
        goto LABEL_0x7ff291029ec;
    else
        goto LABEL_0x7ff29102988;
}


/* VA 0x7ff291091f0, RVA 0x91f0, CFG name sub_7ff291091f0; exports: [] */
void sub_7ff291091f0(void)
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


/* VA 0x7ff29101623, RVA 0x1623, CFG name sub_7ff29101623; exports: [] */
extern unsigned int g_24d192e819c76c51;

char sub_7ff29101623(unsigned long a0, unsigned int *ptr)
{
    unsigned long v4;  // cc_op
    unsigned long v5;  // cc_dep1
    unsigned long v6;  // cc_dep2
    unsigned long v7;  // cc_ndep
    unsigned long v8;  // 4130
    char v9;  // al
    unsigned long v10;  // cc_dep1
    unsigned long v11;  // 4109
    char *v0;  // [bp-0x18]
    unsigned long v1;  // [bp-0x10]
    unsigned long v2;  // [bp+0x0]

    [D] PutI(904:F64x8)[t16,0] = t17()
    [D] PutI(968:I8x8)[t16,0] = 0x01()
    v8 = _ccall(v4, v5, v6, v7);
    *(ptr) = *(ptr) - 66 + ((unsigned int)v8 & 1);
    v10 = v9 & 195;
    if ((v9 & 195) >= 0)
        goto LABEL_0x7ff2910163b;
    while ((char)v10)
    ;
    v1 = v2;
    v0 = &v1;
    v11 = _ccall(2, 17, v10, 0, v8 & 1);
    if ((char)v11)
        return v9 & 195;
    g_24d192e819c76c51 = *((int *)0x70a81a664ba2bfe8);
}


/* VA 0x7ff29109244, RVA 0x9244, CFG name sub_7ff29109244; exports: [] */
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

int sub_7ff29109244(struct_3 **a0, struct_1 *ptr)
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


/* VA 0x7ff291092a4, RVA 0x92a4, CFG name sub_7ff291092a4; exports: [] */
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

int sub_7ff291092a4(struct_3 **a0, struct_1 *ptr)
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


/* VA 0x7ff29109304, RVA 0x9304, CFG name sub_7ff29109304; exports: [] */
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

int sub_7ff29109304(struct_3 **a0, struct_1 *ptr)
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


/* VA 0x7ff291093c4, RVA 0x93c4, CFG name sub_7ff291093c4; exports: [] */
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

int sub_7ff291093c4(struct_3 **a0, struct_1 *ptr)
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


/* VA 0x7ff29109424, RVA 0x9424, CFG name sub_7ff29109424; exports: [] */
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

int sub_7ff29109424(struct_3 **a0, struct_1 *ptr)
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


/* VA 0x7ff29109484, RVA 0x9484, CFG name sub_7ff29109484; exports: [] */
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

int sub_7ff29109484(struct_3 **a0, struct_1 *ptr)
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


/* VA 0x7ff291083ac, RVA 0x83ac, CFG name sub_7ff291083ac; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    HANDLE field_10;
} struct_0;

typedef struct struct_1 {
    char padding_0[16];
    unsigned int field_10;
    char padding_14[8];
    char field_1c;
} struct_1;

extern unsigned int g_7ff29102180;
extern struct_1 *g_7ff2910c310;

void* sub_7ff291083ac(struct_0 *a0, UIntPtr a1)
{
    void* v1;  // rax

    v1 = HeapAlloc(a0->field_10, HEAP_NONE, a1);
    if (v1)
        return v1;
    if (g_7ff2910c310 == &g_7ff2910c310 || !(g_7ff2910c310->field_1c & 1))
        return NULL;
    sub_7ff2910742c(*((long long *)&g_7ff2910c310->field_10), 12, &g_7ff29102180, a1);
    return NULL;
}


/* VA 0x7ff2910139e, RVA 0x139e, CFG name sub_7ff2910139e; exports: [] */
typedef struct struct_0 {
    char padding_0[1591073389];
    char field_5ed5da6d;
} struct_0;

extern unsigned int g_45706fbed807aa98;
extern char g_7fed035db08;
extern char g_7ff1a220565;

void sub_7ff2910139e(unsigned long a0, unsigned int *addr)
{
    unsigned int *v2;  // rcx
    char v3;  // 4106
    char v12;  // 4123
    unsigned long v13;  // 4198
    char v14;  // al
    unsigned long v15;  // 4210
    char v16;  // cc_dep1
    void* ptr3;  // rbx
    unsigned long v5;  // cc_ndep
    unsigned long v6;  // 4169
    void* ptr;  // r15
    unsigned long long v8;  // 4117
    unsigned long v9;  // 4187
    unsigned long long v10;  // r13
    struct_0 *p;  // rsi
    char v0;  // [bp+0x0]

    v2 = (unsigned int *)_INSERT(a0, 1, 233);
    v3 = g_7ff1a220565;
    v6 = _ccall(7, (unsigned long long)*(v2), ptr3 & 4294967295, v5);
    g_7ff1a220565 = g_7ff1a220565 * 2 | g_7ff1a220565 >> 7;
    v8 = (long long)ptr[1841331548];
    v9 = _ccall(37, (unsigned long long)(__ROL__(v3, 1)), 0, v6);
    *((unsigned long long *)&ptr[1841331548]) = (long long)ptr[1841331548] - v10 - (v9 & 1);
    v12 = p->field_5ed5da6d;
    v13 = _ccall(16, v8, v10 ^ v9 & 1, v9 & 1);
    p->field_5ed5da6d = p->field_5ed5da6d - v14 - ((char)v13 & 1);
    v15 = _ccall(13, (unsigned long long)v12, (unsigned long long)(v14 ^ (char)v13 & 1), v13 & 1);
    g_45706fbed807aa98 = _INSERT(v14 CONCAT 0, 0, v14 + 85 - ((char)v15 & 1) + *((char *)ptr3));
    *((unsigned int *)&ptr3[125]) = (int)ptr3[125] + (unsigned int)ptr3;
    *(addr) = *(addr) ^ (unsigned int)&v0;
    if ((*(addr) ^ (unsigned int)&v0) >= 0)
    {
        while (true)
        {
            g_7fed035db08 = g_7fed035db08 ^ 6;
            v16 = g_7fed035db08 ^ 6;
            if ([D] unsupported_<class 'pyvex.expr.GetI'>())
            {
                [D] PutI(968:I8x8)[t11,0] = 0x00()
                if (v16)
                    break;
            }
            else
            {
                [D] PutI(968:I8x8)[t11,0] = 0x00()
                if (v16)
                    break;
            }
        }
    }
}


/* VA 0x7ff29107ae8, RVA 0x7ae8, CFG name sub_7ff29107ae8; exports: [] */
unsigned long long sub_7ff29107ae8(unsigned long a0, unsigned long a1, unsigned long long a2)
{
    unsigned int v4;  // eax
    unsigned long long v0;  // [bp-0x28]
    unsigned long long v1;  // [bp-0x18]
    unsigned int flag;  // [bp+0x20]

    v0 = a2;
    v1 = 4;
    flag = 0;
    v4 = sub_7ff2910795c();
    if (v4 != 2147942634 && (v4 < 0 || flag == 4))
    {
        if (v4 == 2147942402)
            return 2147942402;
        if (v4 >= 0)
            v4 = 0;
        return v4;
    }
    return 2147944029;
}


/* VA 0x7ff29108500, RVA 0x8500, CFG name sub_7ff29108500; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    HANDLE field_10;
} struct_0;

typedef struct struct_1 {
    char padding_0[16];
    unsigned int field_10;
    char padding_14[8];
    char field_1c;
} struct_1;

extern unsigned int g_7ff29102180;
extern struct_1 *g_7ff2910c310;

void* sub_7ff29108500(struct_0 *a0, void* a1, UIntPtr a2)
{
    void* ptr;  // rax

    ptr = HeapReAlloc(a0->field_10, HEAP_NONE, a1, a2);
    if (ptr)
        return ptr;
    if (g_7ff2910c310 == &g_7ff2910c310 || !(g_7ff2910c310->field_1c & 1))
        return NULL;
    sub_7ff2910742c(*((long long *)&g_7ff2910c310->field_10), 14, &g_7ff29102180, a2);
    return NULL;
}


/* VA 0x7ff29109c01, RVA 0x9c01, CFG name sub_7ff29109c01; exports: [] */
extern char g_7ff6d109cbb;

int sub_7ff29109c01(unsigned long long a0, char *ptr7, unsigned long a2, unsigned long a3, unsigned long a4)
{
    char v2;  // al
    unsigned long ptr10;  // rax
    char *ptr8;  // rax
    char v13;  // 4163
    void* ptr5;  // rax
    void* ptr6;  // rdi
    char *addr;  // rax
    char v17;  // 4181
    char *p;  // rax
    char v19;  // 4136
    unsigned long v20;  // 4193
    char *ptr;  // rax
    char *ptr3;  // rsi
    char v22;  // 4105
    unsigned long v23;  // 4118
    char v24;  // 4144
    char *ptr9;  // rax
    unsigned int v26;  // ebx
    char v5;  // 4104
    unsigned int v6;  // edx
    unsigned long long v7;  // rcx
    unsigned long v8;  // cc_ndep
    unsigned long v9;  // 4101
    char *ptr4;  // rax
    char v11;  // 4104
    char v1;  // [bp+0xfff92]

    ptr10 = v2 ^ 10;
    *(ptr3) = *(ptr3) + *((char *)&ptr7);
    v5 = *(ptr7);
    v6 = _INSERT(ptr7, 0, *((char *)&ptr7) ^ v5);
    v7 = a0 - 1;
    if (a0 - 1 & (*((char *)&ptr7) ^ v5))
    {
        v9 = _ccall(0, 17, (unsigned long long)(*((char *)(void*)&ptr7) ^ v5), 0, v8);
        if (!((char)v9))
            goto LABEL_0x7ff29109c1b;
        g_7ff6d109cbb = g_7ff6d109cbb + (char)v6;
        ptr4 = v6;
        v11 = *(ptr4);
        *(ptr4) = *(ptr4) + *((char *)&ptr4);
        ptr8 = (unsigned int)ptr4 + 771752074 + ((unsigned int)(v11 + *((char *)&ptr4) <= v11 ? 1 : 0) & 1);
        v13 = *(ptr8);
        ptr5 = (void*)_INSERT(ptr8, 0, *(ptr8));
        *((char *)&ptr5[118]) = (char)ptr5[118] + (char)v7;
        *((char *)ptr5) = *((char *)ptr5) + v13;
        *((char *)ptr6) = *(ptr3);
        addr = ptr10 & 255 & 4294967295;
        *(addr) = *(addr) + *((char *)&addr);
        v17 = *(addr);
        p = (char *)_INSERT(addr, 0, v17);
        v1 += *((char *)((void*)&p + 1));
        v19 = *(p);
        *(p) = *(p) + v17;
        v20 = _ccall(14, 1, (unsigned long long)v19, (unsigned long long)v17, (v11 + *((char *)(void*)&ptr4) <= v11 ? 1 : 0) & 1);
        if (!((char)v20))
            goto LABEL_0x7ff29109bd8;
        *(p) = *(p) + *((char *)&p);
        ptr = (char *)_INSERT(p, 0, *((char *)&p) - 109);
        v22 = *(ptr);
        *(ptr) = *(ptr) + *((char *)&p) - 109;
        v23 = _ccall(14, 1, (unsigned long long)v22, (unsigned long long)(*((char *)(void*)&p) - 109), (v11 + *((char *)(void*)&ptr4) <= v11 ? 1 : 0) & 1);
        if (!((char)v23))
            goto LABEL_0x7ff29109be0;
        *(ptr) = *(ptr) + *((char *)&ptr);
        v24 = *(ptr);
        ptr9 = (char *)_INSERT(ptr, 0, *(ptr));
        *((char *)((ptr5 & 4294967295) + v7 * 4 - 0x6c9c0000)) = *((char *)((ptr5 & 4294967295) + v7 * 4 - 0x6c9c0000)) + *((char *)((void*)&v7 + 1));
        *(ptr9) = *(ptr9) + v24;
        *((char *)&ptr6[838860661]) = (char)ptr6[838860661] + (char)v26;
        *((char *)v26) = *((char *)v26) + (char)v26;
    }
    *(ptr3) = *(ptr3) >> 1 | *(ptr3) * 128;
    *((char *)(ptr10 + ptr3 * 2)) = *((char *)(ptr10 + ptr3 * 2)) >> 3 | *((char *)(ptr10 + ptr3 * 2)) * 32;
}


/* VA 0x7ff2910445c, RVA 0x445c, CFG name sub_7ff2910445c; exports: [] */
typedef struct struct_0 {
    char padding_0[8];
    unsigned int field_8;
    char padding_c[44];
    char field_38;
} struct_0;

extern char g_7ff29101950;

unsigned int sub_7ff2910445c(struct_0 *ptr)
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
        *((char **)&ptr->padding_0[0]) = &g_7ff29101950;
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


/* VA 0x7ff29102b2f, RVA 0x2b2f, CFG name sub_7ff29102b2f; exports: [] */
char sub_7ff29102b2f(char *addr, char a1)
{
    void* p;  // rax
    unsigned long v2;  // cc_op
    unsigned long v3;  // cc_dep1
    unsigned long v4;  // cc_dep2
    unsigned long v5;  // cc_ndep
    unsigned long v6;  // 4191
    void* ptr;  // rax
    char v8;  // 4185
    unsigned long v9;  // 4244
    char v10;  // bl

    *((unsigned int *)p) = *((int *)p) + 1;
    v6 = _ccall(v2, v3, v4, v5);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    ptr = p - *((long long *)p);
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
    *(addr) = *(addr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)&ptr[43]) = (char)ptr[43] + *((char *)((void*)&ptr + 1));
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    v8 = *((char *)ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    v9 = _ccall(0, 1, (unsigned long long)v8, (unsigned long long)*((char *)(void*)&ptr), v6);
    if ((char)v9)
    {
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        return *((char *)&ptr) + v10;
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
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
}


/* VA 0x7ff291069a4, RVA 0x69a4, CFG name sub_7ff291069a4; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    unsigned int field_10;
    char padding_14[8];
    char field_1c;
} struct_0;

extern unsigned int g_7ff291021f0;
extern struct_0 *g_7ff2910c310;

unsigned int sub_7ff291069a4(unsigned long a0, char *a1)
{
    unsigned int v2;  // ebx
    unsigned long long v0;  // [bp-0x18]

    v0 = 18446744073709551614;
    v2 = sub_7ff29107c40(a1);
    if (v2 >= 0)
        return 0;
    if (g_7ff2910c310 == &g_7ff2910c310 || !(g_7ff2910c310->field_1c & 1))
        return v2;
    sub_7ff291067a8(*((long long *)&g_7ff2910c310->field_10), 10, &g_7ff291021f0, v2);
    return v2;
}


/* VA 0x7ff29109364, RVA 0x9364, CFG name sub_7ff29109364; exports: [] */
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

int sub_7ff29109364(struct_3 **a0, struct_1 *ptr)
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


/* VA 0x7ff291094e4, RVA 0x94e4, CFG name sub_7ff291094e4; exports: [] */
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

int sub_7ff291094e4(struct_3 **a0, struct_1 *ptr)
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


/* VA 0x7ff291047c0, RVA 0x47c0, CFG name sub_7ff291047c0; exports: [] */
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

extern long long g_7ff29101810;

unsigned int sub_7ff291047c0(struct_3 **a0, unsigned int *a1, struct_2 **ptr)
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
        v1 = sub_7ff29104a38(a0 + 3, &g_7ff29101810, a1, ptr);
    }
    return v1;
}


/* VA 0x7ff291049a0, RVA 0x49a0, CFG name sub_7ff291049a0; exports: [] */
typedef struct struct_0 {
    char padding_0[64];
    struct struct_1 *field_40;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

unsigned int sub_7ff291049a0(struct_0 *a0, unsigned long long a1, unsigned int *a2, unsigned long long *ptr)
{
    if (!ptr)
        return 2147500035;
    *(ptr) = 0;
    if (!a1 || !*(a2) && !a2[1] && a2[2] == 192 && a2[3] == 0x46000000)
        return a0->field_40(a1, a2, ptr);
    return 2147746064;
    return a0->field_40(a1, a2, ptr);
}


/* VA 0x7ff2910485c, RVA 0x485c, CFG name sub_7ff2910485c; exports: [] */
typedef struct struct_0 {
    char padding_0[8];
    unsigned int field_8;
    char padding_c[44];
    char field_38;
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

extern char g_7ff29101898;
extern struct_3 *g_7ff2910d300;

struct_0 * sub_7ff2910485c(struct_0 *ptr, char a1)
{
    struct_0 *p;  // rcx

    ptr->field_8 = 3221225473;
    *((char **)&ptr->padding_0[0]) = &g_7ff29101898;
    g_7ff2910d300->field_0->field_10(g_7ff2910d300);
    p = &ptr->padding_c[4];
    if (p->padding_c[28])
    {
        p->padding_c[28] = 0;
        DeleteCriticalSection(p);
    }
    if ((a1 & 1))
        free(ptr);
    return ptr;
}


/* VA 0x7ff291065e8, RVA 0x65e8, CFG name sub_7ff291065e8; exports: [] */
typedef struct struct_0 {
    unsigned long long field_0;
    unsigned long long field_8;
} struct_0;

extern struct_0 *g_7ff2910d0a8;
extern unsigned long long g_7ff2910d200;
extern char g_7ff2910d208;

unsigned long long sub_7ff291065e8(unsigned long a0)
{
    unsigned long long ptr;  // rax
    unsigned long long *v3;  // rax
    unsigned long long v0;  // [bp-0x18]

    v0 = 18446744073709551614;
    while (true)
    {
        ptr = malloc(a0);
        if (ptr)
            return ptr;
        if (!g_7ff2910d208 || !((v3 = (unsigned long long *)(unsigned long long)(!g_7ff2910d0a8 ? sub_7ff29107ca4 : g_7ff2910d0a8->field_8 ^ g_7ff2910d0a8->field_0)(g_7ff2910d200), v3)))
            break;
        v3();
    }
    return 0;
}


/* VA 0x7ff29106654, RVA 0x6654, CFG name sub_7ff29106654; exports: [] */
typedef struct struct_4 {
    struct struct_3 *field_0;
} struct_4;

typedef struct struct_3 {
    unsigned long long field_0;
} struct_3;

typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

typedef struct struct_1 {
    struct struct_0 *field_0;
} struct_1;

typedef struct struct_2 {
    struct struct_1 *field_0;
} struct_2;

extern struct_2 *g_7ff2910d1e8;
extern unsigned int g_7ff2910d20c;

struct_4 ** sub_7ff29106654(void)
{
    unsigned int v2;  // ecx
    struct_4 **v3;  // rax
    struct_4 **v4;  // rcx
    unsigned long long v0;  // [bp-0x18]

    v0 = 18446744073709551614;
    v2 = g_7ff2910d20c;
    v3 = g_7ff2910d20c >> 2;
    if ((*((char *)&v3) & 1))
    {
        v3 = sub_7ff29106908(g_7ff2910d20c);
        v2 = g_7ff2910d20c;
    }
    if (((char)(v2 >> 1) & 1))
    {
        v3 = g_7ff2910d1e8;
        g_7ff2910d1e8 = 0;
        v4 = NULL;
        if (v3)
            v4 = v3;
        if (v4)
            v3 = *(v4)->field_0(v4, 1);
    }
    g_7ff2910d20c = 0;
    return v3;
}


/* VA 0x7ff29108194, RVA 0x8194, CFG name sub_7ff29108194; exports: [] */
extern char g_7ff291025d8;

unsigned int sub_7ff29108194(void* *ptr)
{
    void* p;  // rax
    unsigned long long v0;  // [bp-0x28]

    v0 = 18446744073709551614;
    p = HeapAlloc(GetProcessHeap(), HEAP_NONE, 0x20);
    if (p)
    {
        *((char **)p) = &g_7ff291025d8;
        memset(p + 8, 0, 24);
    }
    else
    {
        p = NULL;
    }
    if (p)
    {
        *(ptr) = p;
        return 0;
    }
    return 2147942414;
}


/* VA 0x7ff29105aa0, RVA 0x5aa0, CFG name sub_7ff29105aa0; exports: [] */
typedef struct struct_0 {
    char padding_0[8];
    unsigned int field_8;
    char padding_c[84];
    unsigned long long field_60;
} struct_0;

typedef struct struct_1 {
    char padding_0[8];
    unsigned int field_8;
    char padding_c[84];
    unsigned long long field_60;
} struct_1;

extern char g_7ff29102360;

unsigned int sub_7ff29105aa0(struct_1 **p)
{
    struct_0 *ptr;  // rax
    unsigned long long v0;  // [bp-0x18]
    unsigned long long flag;  // [bp+0x10]

    v0 = 18446744073709551614;
    ptr = sub_7ff291065e8(104);
    if (ptr)
    {
        ptr->field_8 = 0;
        *((char **)&ptr->padding_0[0]) = &g_7ff29102360;
        flag = 0;
        ptr->field_60 = 0;
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


/* VA 0x7ff29108d58, RVA 0x8d58, CFG name sub_7ff29108d58; exports: [] */
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

void sub_7ff29108d58(unsigned long long a0, struct_1 *p, void* ptr)
{
    unsigned long long v1;  // r9
    struct_2 *addr;  // rcx

    v1 = a0;
    if ((*((char *)ptr) & 4))
        a0 = (int)ptr[4] + a0 & -((int)ptr[8]);
    addr = p->field_10->field_8 + p->field_8;
    if ((addr->field_3 & 15))
        v1 += addr->field_3 & 0xfffffff0;
    sub_7ff29108bf0(v1 ^ *((long long *)((*((int *)ptr) & 0xfffffff8) + a0)));
    return;
}


/* VA 0x7ff2910a5b7, RVA 0xa5b7, CFG name sub_7ff2910a5b7; exports: [] */
typedef struct struct_0 {
    char padding_0[6];
    char field_6;
} struct_0;

typedef struct struct_1 {
    char field_0;
    char padding_1[65535];
    unsigned int field_10000;
} struct_1;

void sub_7ff2910a5b7(void* a0, char *ptr5, unsigned long a2, unsigned long a3, char a4)
{
    void* ptr3;  // rcx
    unsigned long v3;  // cc_op
    char v12;  // 4110
    unsigned long v13;  // rax
    unsigned int v14;  // 4115
    unsigned int v15;  // esi
    unsigned int v16;  // 4121
    unsigned long v17;  // 4257
    unsigned long v18;  // 4262
    struct_0 *v19;  // rdx
    unsigned long v20;  // 4265
    unsigned long v21;  // 4267
    unsigned long v4;  // cc_dep1
    char *ptr;  // rax
    unsigned long v23;  // 4270
    char v24;  // 4098
    void* ptr6;  // rcx
    unsigned long v26;  // 4112
    char v27;  // 4098
    unsigned long v28;  // 4107
    char v29;  // 4106
    struct_1 *p;  // rax
    unsigned long v31;  // 4127
    unsigned long v5;  // cc_dep2
    char *ptr7;  // rdi
    char *addr;  // rax
    char *ptr8;  // rax
    unsigned long v6;  // cc_ndep
    unsigned long v7;  // 4106
    char *ptr9;  // rax
    unsigned long v9;  // rax
    char ptr4[3];  // rax
    unsigned long v11;  // rbx
    char v0;  // [bp+0x0]

    ptr3 = a0 - 1;
    v7 = _ccall(5, v3, v4, v5, v6);
    if (!(a0 - 1 & (char)v7))
    {
        *(ptr5) = *(ptr5) >> 1 | *(ptr5) * 128;
        *(ptr9) = *(ptr9) | *(ptr9) * 0x100;
    }
    ptr4 = v9 & 4294967295;
    ptr4[2] = ptr4[2] + *((char *)&ptr4);
    ptr4[0] = ptr4[0] + *((char *)&ptr4);
    *((unsigned int *)ptr3) = *((int *)ptr3) + (unsigned int)v11;
    v12 = ptr4[0];
    v13 = _INSERT(ptr4, 0, *((char *)&ptr4) | ptr4[0]);
    v14 = *((int *)(v11 + (char *)ptr3));
    *((unsigned int *)(v11 + (char *)ptr3)) = *((int *)(v11 + (char *)ptr3)) - v15 - 0;
    v16 = *((int *)(ptr3 * 2));
    v17 = _ccall(15, (unsigned long long)v14, (unsigned long long)(v15 ^ 0), 0);
    *((unsigned int *)(ptr3 * 2)) = *((int *)(ptr3 * 2)) - (unsigned int)&v0 - ((unsigned int)v17 & 1);
    v18 = _ccall(15, (unsigned long long)v16, (unsigned long long)((unsigned int)&v0 ^ (unsigned int)v17 & 1), v17 & 1);
    *((unsigned int *)(v13 + (char *)ptr3)) = *((int *)(v13 + (char *)ptr3)) - v15 - ((unsigned int)v18 & 1);
    *((char *)ptr3) = *((char *)ptr3) + (char)v11;
    v19 = (struct_0 *)_INSERT(ptr5, 0, *((char *)&ptr5) ^ *(0x7ff3af0b9d3));
    v20 = _ccall(17, (unsigned long long)(*((char *)(void*)&ptr5) ^ *((char *)0x7ff3af0b9d3)), 0, v18 & 1);
    v21 = _ccall((unsigned long long)(char)*((char *)ptr3), 19, v20, 1);
    *((char *)ptr3) = v21;
    ptr = (char *)_INSERT(v13, 0, *((char *)&ptr4) | v12);
    v23 = _ccall(0, 17, (unsigned long long)(*((char *)((void*)&v19 + 1)) | v19->field_6), 0, 0);
    if (!((char)v23))
        goto LABEL_0x7ff2910a5ed;
    v24 = *(ptr);
    *(ptr) = *(ptr) + *((char *)&ptr);
    ptr6 = ptr3 - 1;
    v26 = _ccall(5, 1, (unsigned long long)v24, (unsigned long long)*((char *)(void*)&ptr), 0);
    if (ptr3 - 1 & (char)v26)
    {
        v27 = *(ptr);
        *(ptr) = *(ptr) + *((char *)&ptr);
        v28 = _ccall(8, 1, (unsigned long long)v27, (unsigned long long)*((char *)(void*)&ptr), 0);
        if (!((char)v28))
            goto LABEL_0x7ff2910a6a1;
        *(ptr) = *(ptr) + *((char *)&ptr);
        *(ptr) = *(ptr) + *((char *)&ptr);
        v29 = *(ptr);
        *(ptr) = *(ptr) + *((char *)&ptr);
        p = &v0 & 4294967295;
        v31 = _ccall(14, 1, (unsigned long long)v29, (unsigned long long)*((char *)(void*)&ptr), 0);
        if (!((char)v31))
            goto LABEL_7ff2910a62b;
LABEL_7ff2910a62b:
        *((char *)ptr6) = *((char *)ptr6) + *((char *)&p);
        p->field_0 = p->field_0 + *((char *)&p);
        *(ptr7) = *(ptr7) + *((char *)&ptr6);
        p->field_0 = p->field_0;
        p->field_0 = p->field_0 + *((char *)&p);
        p->field_0 = p->field_0 + *((char *)&p);
        addr = (unsigned int)p & p->field_10000;
        *(addr) = *(addr) + *((char *)&addr);
        *(addr) = *(addr);
        *(addr) = *(addr) + *((char *)&addr);
        *(addr) = *(addr) + *((char *)&addr);
        ptr8 = (char *)_INSERT(addr, 0, *((char *)&addr) + 128);
        *(ptr8) = *(ptr8) + *((char *)&addr) + 128;
    }
    *(ptr) = *(ptr) + *((char *)&ptr);
}


/* VA 0x7ff29108720, RVA 0x8720, CFG name sub_7ff29108720; exports: [] */
typedef struct CRITICAL_SECTION {
    struct CRITICAL_SECTION_DEBUG *DebugInfo;
    int LockCount;
    int RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    UIntPtr SpinCount;
} CRITICAL_SECTION;

typedef struct struct_2 {
    char padding_0[32];
    struct struct_3 *field_20;
} struct_2;

typedef struct struct_8 {
    char padding_0[32];
    struct struct_9 *field_20;
} struct_8;

typedef struct struct_6 {
    char padding_0[16];
    struct struct_7 *field_10;
} struct_6;

typedef struct struct_4 {
    char padding_0[16];
    struct struct_5 *field_10;
} struct_4;

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
    struct struct_0 *field_0;
} struct_3;

typedef struct struct_9 {
    struct struct_4 *field_0;
} struct_9;

typedef struct struct_7 {
    unsigned long long field_0;
} struct_7;

typedef struct struct_5 {
    unsigned long long field_0;
} struct_5;

typedef struct LIST_ENTRY {
    void* Flink;
    void* Blink;
} LIST_ENTRY;

typedef struct struct_0 {
    char padding_0[16];
    struct struct_1 *field_10;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

void sub_7ff29108720(CRITICAL_SECTION *ptr)
{
    struct_2 **cur;  // rdi
    struct_8 *p;  // rsi
    struct_6 **v3;  // rcx

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


/* VA 0x7ff291063a4, RVA 0x63a4, CFG name sub_7ff291063a4; exports: [] */
typedef struct struct_0 {
    char padding_0[8];
    unsigned int field_8;
    char padding_c[4];
    unsigned long long field_10;
    char padding_18[88];
    unsigned long long field_70;
} struct_0;

typedef struct struct_1 {
    char padding_0[8];
    unsigned int field_8;
    char padding_c[4];
    unsigned long long field_10;
    char padding_18[88];
    unsigned long long field_70;
} struct_1;

extern char g_7ff291024f8;

unsigned int sub_7ff291063a4(struct_1 **p)
{
    struct_0 *ptr;  // rax
    unsigned long long v0;  // [bp-0x18]
    unsigned long long flag;  // [bp+0x10]

    v0 = 18446744073709551614;
    ptr = sub_7ff291065e8(120);
    if (ptr)
    {
        ptr->field_8 = 0;
        *((char **)&ptr->padding_0[0]) = &g_7ff291024f8;
        flag = 0;
        ptr->field_10 = 0;
        ptr->field_70 = 0;
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


/* VA 0x7ff29108560, RVA 0x8560, CFG name sub_7ff29108560; exports: [] */
typedef struct struct_0 {
    char padding_0[72];
    struct struct_1 *field_48;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_2 {
    char padding_0[16];
    long long field_10;
    char padding_18[4];
    char field_1c;
} struct_2;

extern long long g_7ff29102180;
extern struct_2 *g_7ff2910c310;

unsigned long long sub_7ff29108560(struct_0 **a0, unsigned long a1, long long a2, long long a3, long long a4)
{
    unsigned long long v1;  // rax

    v1 = *(a0)->field_48();
    if (v1)
        return v1;
    if (g_7ff2910c310 == &g_7ff2910c310 || !(g_7ff2910c310->field_1c & 1))
        return 0;
    sub_7ff29108310(g_7ff2910c310->field_10, 15, &g_7ff29102180, a2, a3, a4);
    return 0;
}


/* VA 0x7ff291038f7, RVA 0x38f7, CFG name sub_7ff291038f7; exports: [] */
void sub_7ff291038f7(char a0, char *p, unsigned long a2, unsigned short a3, unsigned long a4, unsigned long a5)
{
    void* ptr;  // rax
    unsigned long v2;  // cc_op
    unsigned long v3;  // cc_dep1
    unsigned long v4;  // cc_dep2
    unsigned long v5;  // cc_ndep
    unsigned long v6;  // 4199
    char v7;  // ch
    char v8;  // 4193
    unsigned long v9;  // 4260

    *((unsigned int *)ptr) = *((int *)ptr) + 1;
    v6 = _ccall(v2, v3, v4, v5);
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
    *(p) = *(p) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + v7;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)&ptr[57]) = (char)ptr[57] + *((char *)&ptr);
    v8 = *((char *)ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    v9 = _ccall(8, 1, (unsigned long long)v8, (unsigned long long)*((char *)(void*)&ptr), v6);
    if ((char)v9)
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
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        sub_7ff29103978();
        return;
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
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
}


/* VA 0x7ff29103c88, RVA 0x3c88, CFG name sub_7ff29103c88; exports: [] */
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

extern struct_2 *g_7ff2910ca40;
extern char g_7ff2910ca48;

long long sub_7ff29103c88(unsigned long a0, char a1)
{
    struct_0 **i;  // rdi
    struct_0 **v2;  // rcx

    i = g_7ff2910ca40;
    for (v2 = *((long long *)&g_7ff2910ca48); i < v2; i += 1)
    {
        if (*(i))
        {
            *(i)->field_40(0);
            v2 = *((long long *)&g_7ff2910ca48);
        }
    }
    sub_7ff291040f4(a0);
    if ((a1 & 1))
        free(a0);
    return a0;
}


/* VA 0x7ff29105504, RVA 0x5504, CFG name sub_7ff29105504; exports: [] */
typedef struct struct_0 {
    char padding_0[8];
    unsigned int field_8;
    char padding_c[20];
    unsigned long long field_20;
} struct_0;

typedef struct struct_1 {
    char padding_0[8];
    unsigned int field_8;
    char padding_c[20];
    unsigned long long field_20;
} struct_1;

extern char g_7ff29102268;

unsigned int sub_7ff29105504(struct_1 **p)
{
    struct_0 *ptr;  // rax
    unsigned long long v0;  // [bp-0x18]

    v0 = 18446744073709551614;
    ptr = sub_7ff291065e8(40);
    if (ptr)
    {
        ptr->field_8 = 0;
        *((char **)&ptr->padding_0[0]) = &g_7ff29102268;
        memset(&ptr->padding_c[4], 0, 16);
        ptr->field_20 = 0;
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


/* VA 0x7ff2910641c, RVA 0x641c, CFG name sub_7ff2910641c; exports: [] */
typedef struct struct_3 {
    char padding_0[16];
    void* field_10;
    char padding_18[88];
    struct struct_1 *field_70;
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

extern char g_7ff29102280;

struct_3 * sub_7ff2910641c(struct_3 *ptr, char a1)
{
    struct_1 *v1;  // rcx
    unsigned long long flag;  // rdx

    v1 = ptr->field_70;
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
        free(ptr->field_10);
    *((char **)&ptr->padding_0[0]) = &g_7ff29102280;
    if ((a1 & 1))
        free(ptr);
    return ptr;
}


/* VA 0x7ff291048c0, RVA 0x48c0, CFG name sub_7ff291048c0; exports: [] */
typedef struct struct_0 {
    char padding_0[8];
    unsigned int field_8;
    char padding_c[68];
    char field_50;
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

extern char g_7ff291018c8;
extern struct_3 *g_7ff2910d300;

struct_0 * sub_7ff291048c0(struct_0 *ptr, char a1)
{
    struct_0 *p;  // rcx
    unsigned long long v0;  // [bp-0x18]
    struct_0 *v1;  // [bp+0x8]

    v1 = ptr;
    v0 = 18446744073709551614;
    *((char **)&ptr->padding_0[0]) = &g_7ff291018c8;
    ptr->field_8 = 3221225473;
    g_7ff2910d300->field_0->field_10(g_7ff2910d300);
    p = &ptr->padding_c[28];
    if (p->padding_c[28])
    {
        p->padding_c[28] = 0;
        DeleteCriticalSection(p);
    }
    if ((a1 & 1))
        free(ptr);
    return ptr;
}


/* VA 0x7ff29107ed0, RVA 0x7ed0, CFG name sub_7ff29107ed0; exports: [] */
typedef struct struct_6 {
    char padding_0[8];
    struct struct_7 *field_8;
    struct struct_8 *field_10;
    struct struct_9 *field_18;
} struct_6;

typedef struct struct_4 {
    char padding_0[8];
    struct struct_5 *field_8;
} struct_4;

typedef struct struct_2 {
    char padding_0[8];
    struct struct_3 *field_8;
} struct_2;

typedef struct struct_0 {
    char padding_0[8];
    struct struct_1 *field_8;
} struct_0;

typedef struct struct_7 {
    struct struct_0 *field_0;
} struct_7;

typedef struct struct_8 {
    struct struct_2 *field_0;
} struct_8;

typedef struct struct_9 {
    struct struct_4 *field_0;
} struct_9;

typedef struct struct_5 {
    unsigned long long field_0;
} struct_5;

typedef struct struct_3 {
    unsigned long long field_0;
} struct_3;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

extern char g_7ff291025c8;

struct_6 * sub_7ff29107ed0(struct_6 *ptr, char a1)
{
    struct_4 **v1;  // rcx
    struct_2 **v2;  // rcx
    struct_0 **v3;  // rcx

    v1 = ptr->field_18;
    if (v1)
        *(v1)->field_8(v1);
    v2 = ptr->field_10;
    if (v2)
        *(v2)->field_8(v2);
    v3 = ptr->field_8;
    if (v3)
        *(v3)->field_8(v3);
    *((char **)&ptr->padding_0[0]) = &g_7ff291025c8;
    if ((a1 & 1))
        HeapFree(GetProcessHeap(), HEAP_NONE, ptr);
    return ptr;
}


/* VA 0x7ff29101c2d, RVA 0x1c2d, CFG name sub_7ff29101c2d; exports: [] */
typedef struct struct_0 {
    char padding_0[37];
    char field_25;
} struct_0;

int sub_7ff29101c2d(unsigned long long a0, unsigned long long a1)
{
    unsigned long v4;  // cc_op
    unsigned long v5;  // cc_dep1
    unsigned int v14;  // eax
    struct_0 *ptr;  // rdi
    char v16;  // 4096
    unsigned long long v17;  // cc_dep1
    unsigned long long v18;  // cc_dep2
    char v19;  // 4096
    char v20;  // cl
    unsigned long v21;  // 4113
    unsigned long v6;  // cc_dep2
    unsigned int v22;  // eax
    unsigned int *addr;  // rbx
    char v24;  // al
    unsigned long v25;  // 4112
    unsigned long v26;  // 4101
    unsigned long v7;  // cc_ndep
    unsigned long v8;  // 4101
    unsigned int v9;  // eax
    unsigned long long v10;  // cc_op
    unsigned int v11;  // eax
    unsigned long long v12;  // cc_dep1
    void* p;  // rsi
    unsigned long v0;  // [bp-0x10]
    unsigned long long v1;  // [bp-0x8]
    unsigned short v3;  // [bp+0xfffe7]

    v8 = _ccall(10, v4, v5, v6, v7);
    if (!((char)v8))
        return v9;
    if ([D] unsupported_<class 'pyvex.expr.GetI'>())
        v3 = ([D] unsupported_<class 'pyvex.expr.GetI'>() + 0x8000 < 0x10000 ? (short)[D] unsupported_<class 'pyvex.expr.GetI'>() : 0x8000);
    else
        v3 = ((unsigned int)nan + 0x8000 < 0x10000 ? (unsigned short)nan : 0x8000);
    v10 = 17;
    v12 = (char)v11 & 239;
    if (((char)v11 & 239) >= 0)
        goto LABEL_0x7ff29101bfc;
    v14 = (int)p[116] * 449536435;
    *((unsigned int *)&p[68]) = (int)p[68] & 4294967200;
    if (((char)a0 & 31))
    {
        v16 = ptr->field_25;
        v10 = 33;
        v17 = (((char)a0 & 31) ? v16 >> ((char)a0 & 31) : v12);
        v18 = (((char)a0 & 31) ? v16 >> (((char)a0 & 31) - 1 & 31) : 0);
        ptr->field_25 = v16 >> ((char)a0 & 31);
    }
    else
    {
        v19 = ptr->field_25;
        v17 = (((char)a0 & 31) ? v19 >> ((char)a0 & 31) : v12);
        v18 = (((char)a0 & 31) ? v19 >> (((char)a0 & 31) - 1 & 31) : 0);
        ptr->field_25 = v19 >> ((char)a0 & 31);
    }
    v20 = a0 - 1;
    if (a0 == 1)
    {
        v1 = a1;
        v21 = _ccall(6, v10, v17, v18, v7);
        if (!((char)v21))
        {
            v0 = v14;
            return (((unsigned int)ptr | *((int *)(v0 - 1269132622))) + 4)();
        }
        [D] Unsupported jumpkind Ijk_SigTRAP at address 8792486976595()
    }
    else
    {
        v22 = __indword(183);
        __outdword((unsigned short)a1, v22);
        if ([D] unsupported_<class 'pyvex.expr.GetI'>())
        {
            [D] PutI(904:F64x8)[t3,0] = t4()
            [D] PutI(968:I8x8)[t3,0] = 0x01()
        }
        else
        {
            [D] PutI(904:F64x8)[t3,0] = t4()
            [D] PutI(968:I8x8)[t3,0] = 0x01()
        }
        *(addr) = ([D] unsupported_<class 'pyvex.expr.GetI'>() ? [D] unsupported_<class 'pyvex.expr.GetI'>() : nan);
        [D] PutI(968:I8x8)[t5,0] = 0x00()
        *((int *)&p[237706686]) = (int)p[237706686] << (v20 & 31) | (int)p[237706686] >> 32 - (v20 & 31);
        v1 = 534414190;
        v24 = [D] syscall()();
        v25 = _ccall(6, 45, (unsigned long long)v24, (unsigned long long)v20, v7);
        if ((char)v25)
            goto LABEL_0x7ff29101cdb;
        v26 = _ccall(4, 45, (unsigned long long)v24, (unsigned long long)v20, v7);
        if (!((char)v26))
        {
            [D] PutI(904:F64x8)[t8,0] = t9()
            [D] PutI(968:I8x8)[t8,0] = 0x01()
        }
    }
}


/* VA 0x7ff29104020, RVA 0x4020, CFG name sub_7ff29104020; exports: [] */
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

extern Guid g_7ff29101718;
extern Guid g_7ff291017d0;

int sub_7ff29104020(struct_5 *a0, struct_2 **ptr)
{
    struct_5 *v1;  // rbx
    int v2;  // edi

    if (!ptr)
        return -2147467261;
    v1 = &a0->field_40;
    v2 = 0;
    if (*((long long *)&v1->padding_0[0]) || (v2 = (int)(long long)CoCreateInstance(&g_7ff29101718.Data1, 0, CLSCTX_INPROC_SERVER, &g_7ff291017d0.Data1, v1), v2 >= 0))
    {
        *(ptr) = *((long long *)&v1->padding_0[0]);
        (*((long long *)(*((long long *)*((long long *)&v1->padding_0[0])) + 8)))(*((long long *)&v1->padding_0[0]), *((long long *)*((long long *)&v1->padding_0[0])));
    }
    return v2;
}


/* VA 0x7ff29108408, RVA 0x8408, CFG name sub_7ff29108408; exports: [] */
typedef struct struct_0 {
    char padding_0[24];
    struct struct_1 *field_18;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_2 {
    char padding_0[16];
    long long field_10;
    char padding_18[4];
    char field_1c;
} struct_2;

extern long long g_7ff29102180;
extern struct_2 *g_7ff2910c310;

unsigned long long sub_7ff29108408(struct_0 **a0, long long a1, long long a2, long long a3)
{
    unsigned long long v1;  // rax

    v1 = *(a0)->field_18();
    if (v1)
        return v1;
    if (g_7ff2910c310 == &g_7ff2910c310 || !(g_7ff2910c310->field_1c & 1))
        return 0;
    sub_7ff29108310(g_7ff2910c310->field_10, 13, &g_7ff29102180, a1, a2, a3);
    return 0;
}


/* VA 0x7ff29108698, RVA 0x8698, CFG name sub_7ff29108698; exports: [] */
typedef struct struct_1 {
    struct struct_2 *field_0;
    unsigned int field_8;
    char padding_c[4];
    unsigned long long field_10;
    char field_18;
    char padding_19[7];
    unsigned long long field_20;
} struct_1;

typedef struct struct_4 {
    struct struct_5 *field_0;
    unsigned int field_8;
    char padding_c[4];
    unsigned long long field_10;
    char field_18;
    char padding_19[7];
    unsigned long long field_20;
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

extern struct_0 *g_7ff291025e8;

unsigned int sub_7ff29108698(struct_4 **p)
{
    struct_1 *ptr;  // rbx
    unsigned long long v0;  // [bp-0x18]

    v0 = 18446744073709551614;
    ptr = sub_7ff291065e8(40);
    if (ptr)
    {
        ptr->field_8 = 0;
        ptr->field_0 = &g_7ff291025e8;
        ptr->field_10 = 0;
        ptr->field_18 = 0;
        ptr->field_20 = 0;
    }
    else
    {
        ptr = NULL;
    }
    if (!ptr)
        return 2147942414;
    ptr->field_0->field_0(ptr);
    *(p) = ptr;
    return 0;
}


/* VA 0x7ff29106c34, RVA 0x6c34, CFG name sub_7ff29106c34; exports: [] */
typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

extern struct_0 *g_7ff2910c300;

int sub_7ff29106c34(unsigned long a0, unsigned long a1, unsigned long a2, char *a3)
{
    char *v7;  // rdi
    unsigned long long v8;  // rcx
    char *v9;  // rax
    char *v10;  // rax
    char *v0;  // [bp-0x38]
    unsigned long long v1;  // [bp-0x30]
    char *v2;  // [bp-0x28]
    unsigned long long v3;  // [bp-0x20]
    unsigned long long flag;  // [bp-0x18]
    char v6;  // [bp+0x28]

    if (a3)
    {
        v7 = a3;
        do
        {
            if (false)
                break;
        } while (*(v7));
        v8 = ~(18446744073709551615);
    }
    else
    {
        v8 = 5;
    }
    v9 = "NULL";
    if (a3)
        v10 = a3;
    else
        v10 = v9;
    flag = 0;
    v3 = 4;
    v2 = &v6;
    v1 = v8;
    v0 = v10;
    return g_7ff2910c300();
}


/* VA 0x7ff29106a78, RVA 0x6a78, CFG name sub_7ff29106a78; exports: [] */
unsigned int sub_7ff29106a78(long long a0, unsigned short a1, long long a2, unsigned short *a3)
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
    return sub_7ff29103b90(a0, 43, a2, a1);
}


/* VA 0x7ff29109af4, RVA 0x9af4, CFG name sub_7ff29109af4; exports: [] */
extern char g_7ff29100000;
extern char g_7ff2910a900;
extern char g_7ff2910a908;
extern unsigned int g_7ff2910ca30;
extern unsigned long long g_7ff2910ca38;
extern unsigned long long g_7ff2910ca40;
extern unsigned long long g_7ff2910ca48;
extern char g_7ff2910ca50;
extern char g_7ff2910d2f8;

long long sub_7ff29109af4(void)
{
    memset(&g_7ff2910ca50, 0, 40);
    g_7ff2910ca30 = 0;
    g_7ff2910ca38 = &g_7ff29100000;
    g_7ff2910ca40 = &g_7ff2910a900;
    g_7ff2910ca48 = &g_7ff2910a908;
    if (sub_7ff291040cc(&g_7ff2910ca50) < 0)
        g_7ff2910d2f8 = 1;
    else
        g_7ff2910ca30 = 72;
    return sub_7ff29108cdc();
}


/* VA 0x7ff29108c50, RVA 0x8c50, CFG name sub_7ff29108c50; exports: [] */
extern unsigned long long g_7ff2910d338;
extern unsigned long long g_7ff2910d340;

long long sub_7ff29108c50(long long a0)
{
    long long v3;  // rbx
    unsigned long long v1;  // [bp+0x10]
    unsigned long v2;  // [bp+0x18]

    v1 = g_7ff2910d340;
    if (g_7ff2910d340 != 18446744073709551615)
    {
        _lock(8);
        v1 = g_7ff2910d340;
        v2 = g_7ff2910d338;
        v3 = __dllonexit(a0, &v1, &v2);
        g_7ff2910d340 = v1;
        g_7ff2910d338 = v2;
        _unlock(8, v2);
        return v3;
    }
    return (unsigned long long)_onexit();
}


/* VA 0x7ff29106548, RVA 0x6548, CFG name sub_7ff29106548; exports: [] */
typedef struct struct_0 {
    unsigned long long field_0;
    unsigned long long field_8;
} struct_0;

extern char g_7ff29102520;
extern long long g_7ff2910a8d8;
extern char g_7ff2910c200;
extern struct_0 *g_7ff2910d0a8;
extern unsigned long long g_7ff2910d200;
extern char g_7ff2910d208;

unsigned long long sub_7ff29106548(unsigned long a0)
{
    unsigned long v2;  // rcx
    unsigned long long ptr;  // rax
    unsigned long long *v4;  // rax
    char v0;  // [bp-0x28], Other Possible Types: unsigned long

    v2 = a0;
    while (true)
    {
        ptr = malloc(v2);
        if (ptr)
            return ptr;
        if (!g_7ff2910d208 || !((v4 = (unsigned long long *)(unsigned long long)(!g_7ff2910d0a8 ? sub_7ff29107ca4 : g_7ff2910d0a8->field_8 ^ g_7ff2910d0a8->field_0)(g_7ff2910d200), v4)))
            break;
        v4();
        v2 = a0;
    }
    exception::exception(&v0, &g_7ff2910c200, 1);
    v0 = &g_7ff29102520;
    _CxxThrowException(&v0, &g_7ff2910a8d8);
    [D] Unsupported jumpkind Ijk_SigTRAP at address 8792486995408()
}


/* VA 0x7ff291056a4, RVA 0x56a4, CFG name sub_7ff291056a4; exports: [] */
typedef struct struct_0 {
    char padding_0[96];
    HMODULE field_60;
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

typedef struct CRITICAL_SECTION {
    struct CRITICAL_SECTION_DEBUG *DebugInfo;
    int LockCount;
    int RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    UIntPtr SpinCount;
} CRITICAL_SECTION;

extern char g_7ff29102280;
extern char g_7ff29102360;
extern unsigned long long g_7ff2910d1f8;
extern CRITICAL_SECTION g_7ff2910d260;

struct_0 * sub_7ff291056a4(struct_0 *ptr, char a1)
{
    struct_0 *v1;  // r11

    *((char **)&ptr->padding_0[0]) = &g_7ff29102360;
    EnterCriticalSection(&g_7ff2910d260.DebugInfo);
    v1 = g_7ff2910d1f8;
    if (ptr == g_7ff2910d1f8)
        v1 = NULL;
    g_7ff2910d1f8 = v1;
    LeaveCriticalSection(&g_7ff2910d260.DebugInfo);
    if (ptr->field_60)
        FreeLibrary(ptr->field_60);
    *((char **)&ptr->padding_0[0]) = &g_7ff29102280;
    if ((a1 & 1))
        free(ptr);
    return ptr;
}


/* VA 0x7ff291085d0, RVA 0x85d0, CFG name sub_7ff291085d0; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    HANDLE field_10;
    char field_18;
} struct_0;

typedef struct struct_1 {
    char padding_0[16];
    unsigned int field_10;
    char padding_14[8];
    char field_1c;
} struct_1;

extern unsigned int g_7ff29102180;
extern char g_7ff29102548;
extern char g_7ff291025e8;
extern struct_1 *g_7ff2910c310;

struct_0 * sub_7ff291085d0(struct_0 *ptr, char a1)
{
    unsigned long v1;  // 4129
    unsigned int v2;  // eax

    v1 = ptr->field_18;
    *((char **)&ptr->padding_0[0]) = &g_7ff291025e8;
    if ((char)v1 && ptr->field_10 && !HeapDestroy(ptr->field_10))
    {
        v2 = sub_7ff29108208();
        if (g_7ff2910c310 != &g_7ff2910c310 && (g_7ff2910c310->field_1c & 1))
            sub_7ff291067a8(*((long long *)&g_7ff2910c310->field_10), 11, &g_7ff29102180, v2);
    }
    *((char **)&ptr->padding_0[0]) = &g_7ff29102548;
    if ((a1 & 1))
        free(ptr);
    return ptr;
}


/* VA 0x7ff29109148, RVA 0x9148, CFG name sub_7ff29109148; exports: [] */
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

unsigned int sub_7ff29109148(struct_2 *a0, unsigned long a1, long long a2, struct_1 *a3)
{
    sub_7ff29108d58(a1, a3, &a3->field_38->field_4);
    if (!(!((char)a0->field_4 & 102) ? a3->field_38->field_4 & 1 : a3->field_38->field_4 & 2))
        return 1;
    return __CxxFrameHandler3(a0, a1, a2, a3);
}


/* VA 0x7ff29106b9c, RVA 0x6b9c, CFG name sub_7ff29106b9c; exports: [] */
unsigned int sub_7ff29106b9c(long long a0, unsigned short a1, long long a2, unsigned short *a3)
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
    return sub_7ff29103b90(a0, 43, a2, a1);
}


/* VA 0x7ff29104f24, RVA 0x4f24, CFG name sub_7ff29104f24; exports: [] */
typedef struct struct_0 {
    char padding_0[4];
    char field_4;
    char padding_5[11];
    unsigned long long field_10;
    unsigned long long field_18;
} struct_0;

unsigned int sub_7ff29104f24(long long a0, struct_0 *a1)
{
    unsigned int v2;  // ebx
    char flag;  // [bp+0x10], Other Possible Types: unsigned int

    v2 = 0;
    if (!a1)
        return 2147942487;
    if (!(a1->field_4 & 1))
        return 0;
    if (!a1->field_10)
    {
        return 2147942487;
    }
    else if (!a1->field_18)
    {
        return 2147942487;
    }
    else
    {
        flag = 0;
        if (sub_7ff29104fc0() >= 0 && flag)
        {
            flag = 0;
            if ((int)sub_7ff291051c0(a0, a1, &flag) >= 0)
            {
                if (flag == 1 || flag - 1 == 1 || flag - 1 == 2)
                    v2 = 2147500037;
                return v2;
            }
        }
    }
    return 0;
}


/* VA 0x7ff29106908, RVA 0x6908, CFG name sub_7ff29106908; exports: [] */
typedef struct struct_0 {
    struct struct_0 *field_0;
    char padding_8[16];
    unsigned long long field_18;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
    unsigned long long field_8;
} struct_1;

extern struct_1 *g_7ff2910d0a8;
extern char g_7ff2910d209;
extern struct_0 g_7ff2910d310;
extern unsigned long long g_7ff2910d318;
extern unsigned int g_7ff2910d320;

int sub_7ff29106908(void)
{
    struct_0 *i;  // rbx
    unsigned int v3;  // eax
    unsigned int v4;  // eax

    if (!g_7ff2910d209)
        return v4;
    if (!((char)g_7ff2910d320 & 1))
    {
        i = &g_7ff2910d310.field_0;
        g_7ff2910d318 = &g_7ff2910d310.field_0;
        g_7ff2910d320 = g_7ff2910d320 | 1;
        g_7ff2910d310.field_0 = &g_7ff2910d310.field_0;
    }
    for (; i != &g_7ff2910d310.field_0; i = g_7ff2910d310.field_0)
    {
        g_7ff2910d310.field_0 = i->field_0;
        *((struct struct_0 ***)&g_7ff2910d310.field_0->padding_8[0]) = &g_7ff2910d310.field_0;
        (!g_7ff2910d0a8 ? sub_7ff29107ca4 : g_7ff2910d0a8->field_8 ^ g_7ff2910d0a8->field_0)(i->field_18)(i);
    }
    g_7ff2910d209 = 0;
    return v3;
}


/* VA 0x7ff29108310, RVA 0x8310, CFG name sub_7ff29108310; exports: [] */
typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

extern struct_0 *g_7ff2910c300;

int sub_7ff29108310(unsigned long a0, unsigned short a1, unsigned long a2, unsigned long a3, char *a4)
{
    char *v10;  // r8
    char *v11;  // rdi
    unsigned long long v12;  // rcx
    char *v13;  // rax
    char *v14;  // rax
    char *v0;  // [bp-0x48]
    unsigned long long v1;  // [bp-0x40]
    char *v2;  // [bp-0x38]
    unsigned long long v3;  // [bp-0x30]
    char *v4;  // [bp-0x28]
    unsigned long long v5;  // [bp-0x20]
    unsigned long long flag;  // [bp-0x18]
    unsigned long v8;  // [bp+0x20]
    char v9;  // [bp+0x30]

    v8 = a3;
    v10 = a4;
    if (v10)
    {
        v11 = v10;
        do
        {
            if (false)
                break;
        } while (*(v11));
        v12 = ~(18446744073709551615);
    }
    else
    {
        v12 = 5;
    }
    v13 = "NULL";
    if (v10)
        v14 = v10;
    else
        v14 = v13;
    flag = 0;
    v5 = 8;
    v4 = &v9;
    v3 = v12;
    v2 = v14;
    v1 = 8;
    v0 = &v8;
    return g_7ff2910c300();
}


/* VA 0x7ff29108270, RVA 0x8270, CFG name sub_7ff29108270; exports: [] */
int sub_7ff29108270(unsigned long p, unsigned short *a1)
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
        v5 = sub_7ff29108238(&ptr, n);
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


/* VA 0x7ff29106af8, RVA 0x6af8, CFG name sub_7ff29106af8; exports: [] */
extern long long g_7ff291021c0;

unsigned int sub_7ff29106af8(long long a0, unsigned long a1, unsigned long a2, unsigned short *a3)
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
    return sub_7ff29103b90(a0, 43, &g_7ff291021c0, 11);
}


/* VA 0x7ff291040f4, RVA 0x40f4, CFG name sub_7ff291040f4; exports: [] */
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

void sub_7ff291040f4(CRITICAL_SECTION *p)
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
            [D] Unsupported jumpkind Ijk_SigTRAP at address 8792486986036()
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


/* VA 0x7ff29106cb4, RVA 0x6cb4, CFG name sub_7ff29106cb4; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    long long field_10;
    char padding_18[4];
    char field_1c;
} struct_0;

extern long long g_7ff291021e0;
extern struct_0 *g_7ff2910c310;

unsigned int sub_7ff29106cb4(HMODULE *ptr, unsigned short *a1)
{
    HMODULE v2;  // rax
    unsigned int v3;  // eax
    unsigned int v0;  // [bp-0x18]

    if (g_7ff2910c310 != &g_7ff2910c310 && (g_7ff2910c310->field_1c & 4))
        sub_7ff29106a78(g_7ff2910c310->field_10, 25, &g_7ff291021e0, a1);
    v2 = LoadLibraryW(a1);
    *(ptr) = v2;
    if (v2)
        return 0;
    v3 = sub_7ff29108208();
    if (g_7ff2910c310 == &g_7ff2910c310 || !(g_7ff2910c310->field_1c & 1))
        return v3;
    v0 = v3;
    sub_7ff29106b9c(g_7ff2910c310->field_10, 26, &g_7ff291021e0, a1);
    return v3;
}


/* VA 0x7ff29106d5c, RVA 0x6d5c, CFG name sub_7ff29106d5c; exports: [] */
extern long long g_7ff291021e0;
extern void* g_7ff2910c310;

unsigned long long sub_7ff29106d5c(char *a0)
{
    unsigned int v2;  // ebx
    unsigned int v0;  // [bp-0x18]

    v2 = sub_7ff29108208();
    if (v2 == 2147942527)
        return 2147942527;
    if (!(a0 & 0xffffffffffff0000))
    {
        if (g_7ff2910c310 != &g_7ff2910c310 && ((char)g_7ff2910c310[28] & 2))
        {
            v0 = v2;
            sub_7ff29106a30((long long)g_7ff2910c310[16], 29, &g_7ff291021e0, (unsigned int)a0);
        }
    }
    else
    {
        if (g_7ff2910c310 != &g_7ff2910c310 && ((char)g_7ff2910c310[28] & 2))
        {
            v0 = v2;
            sub_7ff29106c34((long long)g_7ff2910c310[16], 30, &g_7ff291021e0, a0);
        }
    }
    return (v2 < 0 ? v2 : 0);
}


/* VA 0x7ff29105580, RVA 0x5580, CFG name sub_7ff29105580; exports: [] */
typedef struct struct_6 {
    char padding_0[16];
    struct struct_1 *field_10;
    struct struct_4 *field_18;
    unsigned long long field_20;
} struct_6;

typedef struct struct_13 {
    struct struct_14 *field_0;
    unsigned int field_8;
} struct_13;

typedef struct struct_10 {
    struct struct_11 *field_0;
    unsigned int field_8;
} struct_10;

typedef struct struct_1 {
    struct struct_2 *field_0;
    unsigned int field_8;
} struct_1;

typedef struct struct_4 {
    struct struct_5 *field_0;
    unsigned int field_8;
} struct_4;

typedef struct struct_14 {
    struct struct_12 *field_0;
} struct_14;

typedef struct struct_11 {
    struct struct_9 *field_0;
} struct_11;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_5 {
    struct struct_3 *field_0;
} struct_5;

typedef struct struct_12 {
    unsigned long long field_0;
} struct_12;

typedef struct struct_9 {
    unsigned long long field_0;
} struct_9;

typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

typedef struct struct_3 {
    unsigned long long field_0;
} struct_3;

typedef struct struct_8 {
    unsigned long long field_0;
} struct_8;

typedef struct struct_7 {
    char padding_0[24];
    struct struct_8 *field_18;
} struct_7;

extern char g_7ff29102280;
extern struct_7 *g_7ff2910d1f8;

struct_6 * sub_7ff29105580(struct_6 *ptr, char a1)
{
    struct_13 *v2;  // rcx
    unsigned long long flag;  // rdx
    struct_10 *v4;  // rcx
    unsigned long long choice;  // rdx
    unsigned long long v0;  // [bp-0x18]
    struct_6 *v1;  // [bp+0x8]

    v1 = ptr;
    v0 = 18446744073709551614;
    if (ptr->field_20)
        g_7ff2910d1f8->field_18(ptr->field_20);
    v2 = ptr->field_18;
    if (v2)
    {
        InterlockedExchangeAdd(&v2->field_8, 4294967295);
        if (v2->field_8 - 1 <= 0 && v2)
        {
            flag = 1;
            v2->field_0->field_0();
        }
    }
    v4 = ptr->field_10;
    if (v4)
    {
        InterlockedExchangeAdd(&v4->field_8, 4294967295);
        if (v4->field_8 - 1 <= 0 && v4)
        {
            choice = 1;
            v4->field_0->field_0();
        }
    }
    *((char **)&ptr->padding_0[0]) = &g_7ff29102280;
    if ((a1 & 1))
        free(ptr);
    return ptr;
}


/* VA 0x7ff29103bd8, RVA 0x3bd8, CFG name sub_7ff29103bd8; exports: [] */
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

unsigned int sub_7ff29103bd8(unsigned int a0, struct_0 *a1, unsigned int *ptr, void* a3)
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
LABEL_7ff29103c64:
        cur->field_10 = v2;
        cur->field_19 = v4;
        cur->field_1c = v3;
        goto LABEL_7ff29103c64;
    }
    return 0;
}


/* VA 0x7ff2910757c, RVA 0x757c, CFG name sub_7ff2910757c; exports: [] */
int sub_7ff2910757c(unsigned int a0, unsigned long long a1, unsigned short *a2)
{
    unsigned long long v1;  // rax
    unsigned long v2;  // cc_ndep
    unsigned long v3;  // 4101
    unsigned long long v4;  // rdx
    unsigned long long v5;  // rdx

    v1 = a1 & 4294967295;
    if (v1 != a1)
    {
LABEL_7ff29107588:
        v1 = _INSERT(v1, 0, 0);
    }
    else
    {
        v1 = 0;
        if (a2 || a0 == 3)
        {
            if (a0 <= 0)
            {
LABEL_7ff2910761d:
                v1 = 1;
            }
            else if (a0 <= 2)
            {
                if (!a1)
                    return 0;
                if (!((char)a1 & 1))
                {
                    v5 = a1 >> 1;
                    if (!a1 >> 1 || a2[1 + v5])
                        goto LABEL_7ff29107588;
                    do
                    {
                        if (false)
                            break;
                    } while (*(a2));
                    if (~(18446744073709551615) != v5)
                        goto LABEL_7ff29107588;
                    goto LABEL_7ff2910761d;
                }
            }
            else if (a0 != 3)
            {
                v3 = _ccall(6, 7, (unsigned long long)a0, 3, v2);
                if ((char)v3)
                    goto LABEL_7ff2910761d;
                if (a0 > 5)
                {
                    if (a0 != 7 || a1 && !((char)a1 & 1) && !((v4 = a1 >> 1, !a1 >> 1 || a2[1 + v4] || v4 != 1 && a2[2 + v4])))
                        goto LABEL_7ff2910761d;
                }
                else
                {
                    if (a1 == 4)
                        goto LABEL_7ff2910761d;
                }
            }
            else if (!(!a2) || !a1)
            {
                goto LABEL_7ff2910761d;
            }
        }
    }
    return v1;
}


/* VA 0x7ff29109a44, RVA 0x9a44, CFG name sub_7ff29109a44; exports: [] */
typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

extern char g_7ff2910d209;
extern long long g_7ff2910d290;
extern unsigned long long g_7ff2910d2c0;
extern unsigned long long g_7ff2910d2c8;
extern unsigned long long g_7ff2910d2d0;
extern unsigned long long g_7ff2910d2d8;
extern unsigned long long g_7ff2910d2e8;
extern unsigned long long g_7ff2910d2f0;
extern unsigned long long g_7ff2910d310;
extern struct_0 *g_7ff2910d318;
extern unsigned int g_7ff2910d320;

long long sub_7ff29109a44(void)
{
    unsigned long dst;  // rax
    unsigned long long *ptr;  // rcx

    dst = memset(&g_7ff2910d290, 0, 48);
    if (!g_7ff2910d209)
    {
        ptr = &g_7ff2910d310;
        if (!((char)g_7ff2910d320 & 1))
        {
            g_7ff2910d310 = &g_7ff2910d310;
            g_7ff2910d320 = g_7ff2910d320 | 1;
        }
        else
        {
            ptr = &g_7ff2910d318->field_0;
        }
        g_7ff2910d2c0 = &g_7ff2910d310;
        g_7ff2910d2c8 = ptr;
        *(ptr) = &g_7ff2910d2c0;
        g_7ff2910d318 = &g_7ff2910d2c0;
        g_7ff2910d2d0 = sub_7ff29107e54()(sub_7ff29107b78);
        dst = sub_7ff29107e54()(sub_7ff29107bbc);
        g_7ff2910d2d8 = dst;
    }
    g_7ff2910d2e8 = 0;
    g_7ff2910d2f0 = 0;
    return dst;
}


/* VA 0x7ff29104c44, RVA 0x4c44, CFG name sub_7ff29104c44; exports: [] */
extern long long g_7ff29102200;

unsigned int sub_7ff29104c44(long long a0, unsigned long a1, unsigned long a2, unsigned short *a3)
{
    unsigned long long v10;  // r8
    unsigned short *v11;  // rdi
    unsigned short *v12;  // rax
    unsigned short *v13;  // r9
    unsigned short *v0;  // [bp-0x48]
    unsigned long long v1;  // [bp-0x40]
    char *v2;  // [bp-0x38]
    unsigned long long v3;  // [bp-0x30]
    char *v4;  // [bp-0x28]
    unsigned long long v5;  // [bp-0x20]
    unsigned long long flag;  // [bp-0x18]
    char v8;  // [bp+0x28]
    char v9;  // [bp+0x30]

    v10 = 10;
    if (a3)
    {
        if (!*(a3))
        {
            v10 = 14;
        }
        else
        {
            v11 = a3;
            do
            {
                if (false)
                    break;
            } while (*(v11));
            v10 = ~(18446744073709551615) * 2;
        }
    }
    if (a3)
    {
        v12 = L"<NULL>";
        if (!*(a3))
            v13 = v12;
        else
            v13 = a3;
    }
    else
    {
        v13 = L"NULL";
    }
    flag = 0;
    v5 = 4;
    v4 = &v9;
    v3 = 8;
    v2 = &v8;
    v1 = v10;
    v0 = v13;
    return sub_7ff29103b90(a0, 43, &g_7ff29102200, 10);
}


/* VA 0x7ff29108eec, RVA 0x8eec, CFG name _security_init_cookie; exports: [] */
extern unsigned long long g_7ff2910c110;
extern unsigned long long g_7ff2910c118;

unsigned long long _security_init_cookie(void)
{
    unsigned int v2;  // eax
    unsigned int v3;  // eax
    unsigned int v4;  // eax
    unsigned long long v5;  // r11
    unsigned int flag[2];  // [bp+0x8], Other Possible Types: unsigned long long
    long long v1;  // [bp+0x10]

    flag = 0;
    if (g_7ff2910c110 != 47936899621426)
    {
        g_7ff2910c118 = ~(g_7ff2910c110);
        return g_7ff2910c118;
    }
    GetSystemTimeAsFileTime(&flag);
    v2 = GetCurrentProcessId();
    v3 = GetCurrentThreadId();
    v4 = GetTickCount();
    QueryPerformanceCounter(&v1);
    v5 = (unsigned long long)((v1 ^ flag ^ v2 ^ v3 ^ v4) & 281474976710655);
    if (v5 == 47936899621426)
        v5 = 47936899621427;
    g_7ff2910c110 = v5;
    g_7ff2910c118 = ~(v5);
    return 47936899621427;
}


/* VA 0x7ff29109974, RVA 0x9974, CFG name sub_7ff29109974; exports: [] */
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

extern char g_7ff29101778;
extern struct_2 *g_7ff2910ca40;
extern char g_7ff2910ca48;
extern unsigned long long g_7ff2910d210;
extern unsigned int g_7ff2910d218;
extern unsigned int g_7ff2910d21c;
extern unsigned long long g_7ff2910d220;
extern char g_7ff2910d228;
extern unsigned long long g_7ff2910d250;
extern char g_7ff2910d2f8;
extern unsigned long long g_7ff2910d300;

long long sub_7ff29109974(void)
{
    struct_0 **i;  // rbx
    struct_0 **v2;  // rax
    unsigned long v3;  // rcx

    memset(&g_7ff2910d228, 0, 40);
    g_7ff2910d218 = 0;
    g_7ff2910d220 = 0;
    g_7ff2910d21c = 0;
    g_7ff2910d250 = 0;
    g_7ff2910d300 = &g_7ff2910d210;
    if (sub_7ff291040cc(&g_7ff2910d228) < 0)
        g_7ff2910d2f8 = 1;
    else
        g_7ff2910d218 = 56;
    i = g_7ff2910ca40;
    for (v2 = *((long long *)&g_7ff2910ca48); i < v2; i += 1)
    {
        if (*(i))
        {
            *(i)->field_40(v3);
            v2 = *((long long *)&g_7ff2910ca48);
        }
    }
    g_7ff2910d210 = &g_7ff29101778;
    return sub_7ff29108cdc();
}


/* VA 0x7ff29107334, RVA 0x7334, CFG name sub_7ff29107334; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    struct struct_1 *field_10;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

extern long long g_7ff2910c718;
extern long long g_7ff2910c7e8;
extern long long g_7ff2910c810;
extern long long g_7ff2910c840;

unsigned long long sub_7ff29107334(long long a0)
{
    struct_0 **v2;  // rax
    long long v0;  // [bp-0x18]

    v2 = __RTDynamicCast();
    if (v2)
        return *(v2)->field_10(v2, *(v2));
    *((unsigned int *)&v0) = 0;
    if (__RTDynamicCast(a0, 0, &g_7ff2910c718, &g_7ff2910c7e8, v0))
        return 2147942414;
    *((unsigned int *)&v0) = 0;
    if (!__RTDynamicCast(a0, 0, &g_7ff2910c718, &g_7ff2910c840, v0))
    {
        *((unsigned int *)&v0) = 0;
        return (-(0 < __RTDynamicCast(a0, 0, &g_7ff2910c718, &g_7ff2910c810, v0)) & 442450) - 2147467259;
    }
    return 2147943813;
}


/* VA 0x7ff29103acc, RVA 0x3acc, CFG name sub_7ff29103acc; exports: [] */
extern unsigned long long g_7ff2910c300;
extern unsigned long long g_7ff2910c308;
extern unsigned int g_7ff2910d308;

HMODULE sub_7ff29103acc(void)
{
    HMODULE v1;  // rbx
    void* v2;  // rax

    v1 = LoadLibraryW(L"advapi32");
    if (!v1)
    {
        g_7ff2910d308 = 0;
        g_7ff2910c300 = sub_7ff29103aa8;
        g_7ff2910c308 = sub_7ff29103978;
        return v1;
    }
    g_7ff2910c300 = GetProcAddress(v1, "TraceMessage");
    if (!g_7ff2910c300)
    {
        g_7ff2910d308 = 0;
        g_7ff2910c300 = sub_7ff29103aa8;
        g_7ff2910c308 = sub_7ff29103978;
    }
    else
    {
        g_7ff2910d308 = 1;
        v2 = GetProcAddress(v1, "TraceMessageVa");
        if (!v2)
            v2 = sub_7ff29103978;
        g_7ff2910c308 = v2;
    }
    return FreeLibrary(v1);
}


/* VA 0x7ff29104b60, RVA 0x4b60, CFG name sub_7ff29104b60; exports: [] */
typedef struct struct_0 {
    char padding_0[8];
    unsigned long long field_8;
    char padding_10[48];
    unsigned int field_40;
    char padding_44[4];
    unsigned long long field_48;
} struct_0;

typedef struct struct_2 {
    unsigned long long field_0;
} struct_2;

typedef struct struct_1 {
    char padding_0[32];
    struct struct_2 *field_20;
} struct_1;

extern struct_1 *g_7ff2910d1f8;

long long sub_7ff29104b60(struct_0 *idx)
{
    unsigned long long v5;  // rbx
    unsigned long long v6;  // rsi
    unsigned long long v7;  // rdi
    unsigned int v8;  // edi
    unsigned long long v9;  // rsi
    unsigned long long v10[2];  // rbp
    unsigned long v11;  // rax
    unsigned long long v0;  // [bp-0x8]
    unsigned long long v1;  // [bp+0x8]
    unsigned long v2;  // [bp+0x10]
    unsigned long long v3;  // [bp+0x18]

    if (!idx)
        return v11;
    v1 = v5;
    v2 = vvar_106{r56|8b};
    v3 = v6;
    v0 = v7;
    if (idx->field_8)
        g_7ff2910d1f8->field_20(idx->field_8);
    if (!idx->field_48)
        return g_7ff2910d1f8->field_20(idx);
    v8 = 0;
    if (idx->field_40 > 0)
    {
        v9 = 0;
        do
        {
            v10 = *((long long *)(v9 + idx->field_48));
            if (v10)
            {
                if (v10[0])
                    g_7ff2910d1f8->field_20(v10[0]);
                if (v10[1])
                    g_7ff2910d1f8->field_20(v10[1]);
                g_7ff2910d1f8->field_20(v10);
            }
        } while ((v8 += 1, v9 += 8, v8 < idx->field_40));
    }
    g_7ff2910d1f8->field_20(idx->field_48);
    return g_7ff2910d1f8->field_20(idx);
}


/* VA 0x7ff29106e08, RVA 0x6e08, CFG name sub_7ff29106e08; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    unsigned int field_10;
    char padding_14[8];
    char field_1c;
} struct_0;

extern unsigned int g_7ff291021e0;
extern struct_0 *g_7ff2910c310;

unsigned long long sub_7ff29106e08(void* ptr, LPArray a1, HMODULE a2)
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
        v2 = GetModuleFileNameW(a2, a1, v1);
        v3 = v2;
        if (!v2)
        {
            v4 = sub_7ff29108208();
            if (g_7ff2910c310 == &g_7ff2910c310 || !(g_7ff2910c310->field_1c & 1))
                return v4;
            sub_7ff291067a8(*((long long *)&g_7ff2910c310->field_10), 32, &g_7ff291021e0, v4);
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


/* VA 0x7ff29107040, RVA 0x7040, CFG name sub_7ff29107040; exports: [] */
typedef struct SECURITY_ATTRIBUTES {
    unsigned int nLength;
    char padding_4[4];
    void* lpSecurityDescriptor;
    int bInheritHandle;
} SECURITY_ATTRIBUTES;

typedef struct struct_0 {
    char padding_0[16];
    long long field_10;
    char padding_18[4];
    char field_1c;
} struct_0;

extern long long g_7ff291021e0;
extern struct_0 *g_7ff2910c310;

unsigned int sub_7ff29107040(HANDLE *ptr, unsigned short *a1)
{
    HANDLE v1;  // rax
    unsigned int v2;  // eax

    *(ptr) = 0xffffffffffffffff;
    v1 = CreateFileW(a1, 0x80000000, 7, NULL, OPEN_EXISTING, SECURITY_ANONYMOUS, NULL);
    *(ptr) = v1;
    if (v1 != 0xffffffffffffffff)
        return 0;
    v2 = sub_7ff29108208();
    if (v2 != 2147942402)
    {
        if (g_7ff2910c310 != &g_7ff2910c310 && (g_7ff2910c310->field_1c & 1))
            sub_7ff29106b9c(g_7ff2910c310->field_10, 35, &g_7ff291021e0, a1);
    }
    else
    {
        if (g_7ff2910c310 != &g_7ff2910c310 && (g_7ff2910c310->field_1c & 2))
            sub_7ff29106a78(g_7ff2910c310->field_10, 34, &g_7ff291021e0, a1);
    }
    return v2;
}


/* VA 0x7ff29107888, RVA 0x7888, CFG name sub_7ff29107888; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    long long field_10;
    char padding_18[4];
    char field_1c;
} struct_0;

extern long long g_7ff291021c0;
extern struct_0 *g_7ff2910c310;

unsigned long long sub_7ff29107888(unsigned short *a0, unsigned long long a1, unsigned int flag, unsigned long long *a3, unsigned long a4)
{
    unsigned long long v1;  // rax

    if (!a4)
        return 0;
    if (flag != 1 && flag != 2)
    {
        if (flag != 7)
            goto LABEL_7ff291078fb;
        v1 = sub_7ff29107730(a1 >> 1, a4, a3);
    }
    else
    {
        v1 = sub_7ff2910762c(a1 >> 1, a4, a3);
    }
    if (!(unsigned int)v1)
        return v1;
    if ((unsigned int)v1 == 2147942634)
        return v1;
    if ((unsigned int)v1 == 2147947423)
        goto LABEL_7ff2910790e;
LABEL_7ff291078fb:
    if ((char)sub_7ff2910757c(flag, *(a3), a4))
        return 0;
LABEL_7ff2910790e:
    if (g_7ff2910c310 == &g_7ff2910c310 || !(g_7ff2910c310->field_1c & 1))
        return 2147947423;
    sub_7ff29106a78(g_7ff2910c310->field_10, 20, &g_7ff291021c0, a0);
    return 2147947423;
}


/* VA 0x7ff291066bc, RVA 0x66bc, CFG name sub_7ff291066bc; exports: [] */
typedef struct OSVERSIONINFOW {
    unsigned int dwOSVersionInfoSize;
    unsigned int dwMajorVersion;
    unsigned int dwMinorVersion;
    unsigned int dwBuildNumber;
    unsigned int dwPlatformId;
    Char szCSDVersion[128];
} OSVERSIONINFOW;

typedef struct struct_0 {
    char padding_0[16];
    unsigned int field_10;
    char padding_14[8];
    char field_1c;
} struct_0;

extern unsigned int g_7ff291021b0;
extern struct_0 *g_7ff2910c310;
extern unsigned long long g_7ff2910d0b0;
extern OSVERSIONINFOW g_7ff2910d0b8;
extern unsigned int g_7ff2910d0bc;
extern unsigned int g_7ff2910d0c0;
extern unsigned int g_7ff2910d0c4;
extern unsigned int g_7ff2910d1d4;
extern unsigned long long g_7ff2910d1d8;
extern unsigned int g_7ff2910d20c;

int sub_7ff291066bc(void)
{
    unsigned int v1;  // ebx

    if (g_7ff2910d20c)
    {
        v1 = 2147942487;
    }
    else
    {
        g_7ff2910d0b8.dwOSVersionInfoSize = 284;
        if (!GetVersionExW(&g_7ff2910d0b8.dwOSVersionInfoSize))
        {
            v1 = sub_7ff29108208();
            if (g_7ff2910c310 != &g_7ff2910c310 && (g_7ff2910c310->field_1c & 1))
                sub_7ff291067a8(*((long long *)&g_7ff2910c310->field_10), 12, &g_7ff291021b0, v1);
        }
        else
        {
            g_7ff2910d0b0 = 304;
            g_7ff2910d1d4 = g_7ff2910d0bc * 0x10000 | g_7ff2910d0c0;
            v1 = 0;
            g_7ff2910d1d8 = g_7ff2910d1d4 * 0x100000000 | g_7ff2910d0c4;
        }
        if (v1 >= 0)
        {
            v1 = sub_7ff29107f44();
            if (v1 >= 0)
            {
                g_7ff2910d20c = g_7ff2910d20c | 2;
                v1 = sub_7ff291067e4();
                if (v1 >= 0)
                {
                    g_7ff2910d20c = g_7ff2910d20c | 4;
                    v1 = 0;
                }
            }
            if (v1 >= 0)
                return 0;
        }
    }
    sub_7ff29106654();
    return v1;
}


/* VA 0x7ff2910762c, RVA 0x762c, CFG name sub_7ff2910762c; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    unsigned int field_10;
    char padding_14[8];
    char field_1c;
} struct_0;

extern struct_0 *g_7ff2910c310;

unsigned int sub_7ff2910762c(unsigned long long a0, unsigned short *a1, unsigned long long *ptr)
{
    unsigned short *p;  // rsi
    unsigned long long idx;  // rdi
    unsigned long long v3;  // rcx
    unsigned long long v4;  // rcx

    p = a1;
    if (((char)*(ptr) & 1))
        *(ptr) = *(ptr) - 1;
    idx = *(ptr) >> 1;
    if (*(ptr) >> 1 && !a1[1 + idx])
    {
        do
        {
            if (false)
                break;
        } while (*(a1));
        v3 = ~(18446744073709551615) * 2;
        if (*(ptr) == v3)
            return 0;
        *(ptr) = v3;
        return 0;
    }
    if (idx < a0)
    {
        if (g_7ff2910c310 != &g_7ff2910c310 && (g_7ff2910c310->field_1c & 1))
            sub_7ff29106a0c(*((long long *)&g_7ff2910c310->field_10), 13);
        *(ptr) = *(ptr) + 2;
        p[idx] = 0;
        do
        {
            if (false)
                break;
        } while (*(p));
        v4 = ~(18446744073709551615) * 2;
        if (*(ptr) == v4)
            return 0;
        *(ptr) = v4;
        return 0;
    }
    else
    {
        if (g_7ff2910c310 != &g_7ff2910c310 && (g_7ff2910c310->field_1c & 2))
            sub_7ff29106a0c(*((long long *)&g_7ff2910c310->field_10), 14);
        *(ptr) = *(ptr) + 2;
        return 2147942634;
    }
}


/* VA 0x7ff291044d4, RVA 0x44d4, CFG name sub_7ff291044d4; exports: [] */
typedef struct struct_6 {
    struct struct_3 *field_0;
    unsigned int field_8;
    char padding_c[44];
    char field_38;
} struct_6;

typedef struct struct_3 {
    struct struct_4 *field_0;
    char padding_8[24];
    struct struct_5 *field_20;
} struct_3;

typedef struct struct_4 {
    unsigned long long field_0;
} struct_4;

typedef struct struct_5 {
    unsigned long long field_0;
} struct_5;

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

extern char g_7ff29101898;
extern struct_2 *g_7ff2910d300;

unsigned int sub_7ff291044d4(unsigned long a0, unsigned long long a1, unsigned long long *p)
{
    unsigned int v6;  // r12d
    struct_6 *ptr;  // rdi
    unsigned int v8;  // eax
    struct_6 *v0;  // [bp-0x38], Other Possible Types: unsigned long long
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
    ptr = sub_7ff29106548(64);
    if (ptr)
    {
        ptr->field_8 = 0;
        memset((struct struct_6 *)&ptr->padding_c[4], 0, 40);
        ptr->field_38 = 0;
        ptr->field_0 = &g_7ff29101898;
        g_7ff2910d300->field_0->field_8(g_7ff2910d300);
        v0 = ptr;
    }
    else
    {
        ptr = NULL;
        v0 = 0;
    }
    if (ptr)
    {
        InterlockedIncrement(&ptr->field_8);
        v8 = sub_7ff291040cc(&ptr->padding_c[4]);
        if (v8 >= 0)
            ptr->field_38 = 1;
        v6 = (0 <= v8 ? 0 : v8);
        InterlockedDecrement(&ptr->field_8);
        if (v6 || (v6 = (unsigned int)(unsigned long long)ptr->field_0->field_0(ptr, a1, p), v6))
            ptr->field_0->field_20(ptr, 1, ptr->field_0);
    }
    return v6;
}


/* VA 0x7ff29108080, RVA 0x8080, CFG name sub_7ff29108080; exports: [] */
typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_0 {
    char padding_0[8];
    struct struct_1 *field_8;
} struct_0;

typedef struct struct_4 {
    struct struct_5 *field_0;
    unsigned int field_8;
    char padding_c[4];
    unsigned long long field_10;
    char field_18;
    char padding_19[7];
    unsigned long long field_20;
} struct_4;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_5 {
    struct struct_3 *field_0;
} struct_5;

typedef struct struct_3 {
    unsigned long long field_0;
} struct_3;

extern unsigned long long g_10;
extern char g_18;
extern unsigned long long g_20;
extern unsigned int g_7ff29102180;
extern struct_3 *g_7ff2910c310;

unsigned int sub_7ff29108080(struct_2 **p, unsigned long a1, UIntPtr a2, UIntPtr a3, unsigned long long a4)
{
    struct_4 *v1;  // rdi
    unsigned int v2;  // esi
    unsigned long v3;  // rax
    struct_4 *ptr;  // rbx
    HANDLE v5;  // rax
    struct_4 *addr;  // [bp+0x8]

    *(p) = NULL;
    v1 = NULL;
    addr = NULL;
    v2 = sub_7ff29108698(&addr);
    if (v2 < 0)
    {
        if (!addr)
            goto LABEL_7ff29108159;
        v3 = addr->field_0;
        goto LABEL_7ff291080cd;
    }
    else
    {
        ptr = addr;
        ptr->field_10 = a4;
        if (!a4)
        {
            v5 = HeapCreate(HEAP_NONE, a2, a3);
            ptr->field_10 = v5;
            if (!v5)
            {
                v2 = sub_7ff29108208();
                if (g_7ff2910c310 != &g_7ff2910c310 && (g_7ff2910c310->field_1c & 1))
                    sub_7ff291067a8(*((long long *)&g_7ff2910c310->field_10), 10, &g_7ff29102180, v2);
                if (v2 < 0)
                    goto LABEL_7ff29108149;
            }
            ptr->field_18 = 1;
        }
        v2 = 0;
        ptr->field_20 = a1;
        if (false)
        {
LABEL_7ff29108149:
            v3 = ptr->field_0;
LABEL_7ff291080cd:
            (*((long long *)(v3 + 8)))();
        }
        else
        {
            v1 = ptr;
            v2 = 0;
        }
    }
LABEL_7ff29108159:
    if (v2 >= 0)
    {
        *(p) = v1;
        return 0;
    }
    else if (v1)
    {
        v1->field_0[1].field_0(v1);
        return v2;
    }
    else
    {
        return v2;
    }
}


/* VA 0x7ff29107468, RVA 0x7468, CFG name sub_7ff29107468; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    long long field_10;
    char padding_18[4];
    char field_1c;
} struct_0;

extern long long g_7ff291021c0;
extern struct_0 *g_7ff2910c310;

unsigned int sub_7ff29107468(unsigned long long *ptr, unsigned long a1, unsigned short *a2, enum REG_SAM_FLAGS a3)
{
    unsigned int v1;  // edi
    HKEY flag;  // [bp+0x8], Other Possible Types: unsigned long long

    *(ptr) = 0;
    flag = 0;
    v1 = (unsigned long long)RegOpenKeyExW(0xffffffff80000000, a2, 0, a3, &flag);
    if (v1 == 2)
    {
        if (g_7ff2910c310 != &g_7ff2910c310 && ((char)v1 & g_7ff2910c310->field_1c))
            sub_7ff29106a78(g_7ff2910c310->field_10, (unsigned short)v1 + 8, &g_7ff291021c0, a2);
        if (!flag)
            return 2147942402;
        RegCloseKey(flag);
        return 2147942402;
    }
    else
    {
        if (v1)
        {
            if (g_7ff2910c310 != &g_7ff2910c310 && (g_7ff2910c310->field_1c & 1))
                sub_7ff29106af8(g_7ff2910c310->field_10, 11, &g_7ff291021c0, a2);
            if ((v1 <= 0 ? v1 : v1 & 65535 | 0x80070000) < 0)
            {
                if (!flag)
                    return (v1 <= 0 ? v1 : v1 & 65535 | 0x80070000);
                RegCloseKey(flag);
                return (v1 <= 0 ? v1 : v1 & 65535 | 0x80070000);
            }
        }
        if (flag)
        {
            *(ptr) = flag;
            return 0;
        }
        return 2147549183;
    }
}


/* VA 0x7ff29107f44, RVA 0x7f44, CFG name sub_7ff29107f44; exports: [] */
typedef struct struct_5 {
    struct struct_6 *field_0;
    struct struct_7 *field_8;
    struct struct_8 *field_10;
} struct_5;

typedef struct struct_6 {
    struct struct_0 *field_0;
} struct_6;

typedef struct struct_7 {
    struct struct_1 *field_0;
} struct_7;

typedef struct struct_8 {
    struct struct_3 *field_0;
} struct_8;

typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

typedef struct struct_1 {
    char padding_0[8];
    struct struct_2 *field_8;
} struct_1;

typedef struct struct_3 {
    char padding_0[8];
    struct struct_4 *field_8;
} struct_3;

typedef struct struct_2 {
    unsigned long long field_0;
} struct_2;

typedef struct struct_4 {
    unsigned long long field_0;
} struct_4;

extern unsigned long long g_10;
extern unsigned long long g_7ff2910d1e8;
extern unsigned long long g_8;

unsigned int sub_7ff29107f44(void)
{
    struct_5 *v5;  // rbx
    unsigned int v6;  // eax
    struct_5 *v7;  // rcx
    struct_5 *ptr;  // rdi
    unsigned long v9;  // rcx
    unsigned long v10;  // rcx
    unsigned int v11;  // eax
    unsigned long long v0;  // [bp-0x28]
    struct_5 *flag3;  // [bp+0x8]
    unsigned long long flag;  // [bp+0x10]
    unsigned long long choice;  // [bp+0x18]
    unsigned long long flag2;  // [bp+0x20]

    v0 = 18446744073709551614;
    flag = 0;
    v5 = NULL;
    choice = 0;
    flag2 = 0;
    flag3 = NULL;
    v6 = sub_7ff29108194(&flag3);
    if (v6 < 0)
    {
        v7 = flag3;
        if (v7)
            v7->field_0->field_0(v7, 1);
    }
    else
    {
        ptr = flag3;
        v9 = ptr->field_8;
        if (v9)
        {
            (*((long long *)(*((long long *)v9) + 8)))(v9);
            ptr->field_8 = 0;
        }
        v6 = sub_7ff29108080(&ptr->field_8, "MpProcessHeap", NULL, NULL, GetProcessHeap());
        if (v6 >= 0)
        {
            v10 = ptr->field_10;
            if (v10)
            {
                (*((long long *)(*((long long *)v10) + 8)))(v10);
                ptr->field_10 = 0;
            }
            v11 = sub_7ff29108080(&ptr->field_10, "MpPublicHeap", NULL, NULL, 0);
            v6 = (v11 < 0 ? v11 : 0);
        }
        if (v6 >= 0)
        {
            v5 = ptr;
            v6 = 0;
        }
        else if (ptr)
        {
            ptr->field_0->field_0(ptr, 1);
        }
    }
    if (v6 >= 0)
    {
        g_7ff2910d1e8 = v5;
        return 0;
    }
    if (!v5)
        return v6;
    v5->field_0->field_0(v5, 1, v5->field_0);
    return v6;
}


/* VA 0x7ff29101e56, RVA 0x1e56, CFG name sub_7ff29101e56; exports: [] */
typedef struct struct_0 {
    char padding_0[2055240640];
    unsigned int field_7a807bc0;
} struct_0;

typedef struct struct_1 {
    char padding_0[1245743745];
    unsigned long long field_4a408a81;
} struct_1;

extern char g_7ff15920c1f;

void sub_7ff29101e56(void* cur, char *ptr5, unsigned int *ptr6, unsigned long a3, unsigned long a4)
{
    unsigned long v3;  // rax
    void* ptr;  // rsi
    void* addr;  // rdi
    void* v13;  // rsi
    void* p;  // rax
    unsigned int v6;  // edi
    void* iter;  // rdi
    unsigned long long v8;  // rdx
    unsigned long v1;  // [bp+0x0]

    __outdword(*((unsigned short *)&ptr5), v3 & 4294967295);
    g_7ff15920c1f = g_7ff15920c1f + *((char *)((void*)&cur + 1));
    p = _INSERT((char)v3 - 1 CONCAT 0, 0, (char)__inbyte(192) & 128) & 654370113;
    iter = v6 * 2;
    __outbyte(64, *((char *)&p));
    *(ptr5) = *(ptr5) + *((char *)((void*)&p + 1));
    v8 = (unsigned int)ptr5 * 2;
    if (cur)
    {
        p = (unsigned int)p & *((int *)cur);
        cur -= 1;
        if (!(cur - 1 & !((unsigned int)p & *((int *)cur))))
            [D] Unsupported jumpkind Ijk_NoDecode at address 8792486977147()
    }
    *((char *)&cur[32]) = (char)cur[32] & *((char *)&p);
    *((unsigned int *)&p[1635803328]) = (int)p[1635803328] + (unsigned int)&v1;
    p = *((int *)0x6240a281a3c16300);
    *((char *)&ptr[63]) = (char)ptr[63] + (char)*((int *)0x6240a281a3c16300);
    addr = iter + 1;
    v13 = ptr + 1;
    *((unsigned int *)&addr[1526634688]) = (int)addr[1526634688] & 1686136256;
    *((char *)addr) = *((char *)v13);
    iter = addr + 1;
    ptr = v13 + 1;
    *(-84 + (char *)cur + 8 * *((int *)0x6240a281a3c16300)) = *(-84 + (char *)cur + 8 * *((int *)0x6240a281a3c16300)) + *((char *)((void*)&cur + 1));
}


/* VA 0x7ff29104300, RVA 0x4300, CFG name sub_7ff29104300; exports: [] */
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

extern char g_7ff29101868;
extern char g_7ff29101950;

unsigned int sub_7ff29104300(unsigned long long a0, unsigned long long a1, unsigned long long *p)
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
    ptr = sub_7ff29106548(72);
    if (ptr)
    {
        ptr->field_8 = 0;
        memset((struct struct_1 *)&ptr->padding_c[4], 0, 40);
        ptr->field_38 = 0;
        ptr->field_0 = &g_7ff29101868;
    }
    else
    {
        ptr = NULL;
    }
    v0 = ptr;
    if (ptr)
    {
        ptr->field_40 = a0;
        v8 = sub_7ff291040cc(&ptr->padding_c[4]);
        if (v8 >= 0)
            ptr->field_38 = 1;
        v6 = (0 <= v8 ? 0 : v8);
        if (v6 || (v6 = (unsigned int)(unsigned long long)ptr->field_0->field_0(ptr, a1, p), v6))
        {
            ptr->field_8 = 3221225473;
            ptr->field_0 = &g_7ff29101950;
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


/* VA 0x7ff291045f8, RVA 0x45f8, CFG name sub_7ff291045f8; exports: [] */
typedef struct struct_3 {
    struct struct_0 *field_0;
    unsigned int field_8;
    char padding_c[20];
    unsigned long long field_20;
    char padding_28[40];
    char field_50;
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

extern char g_7ff291018c8;
extern char g_7ff291018f0;
extern struct_6 *g_7ff2910d300;

int sub_7ff291045f8(unsigned long a0, unsigned long long a1, unsigned long long *p)
{
    int v7;  // r12d
    struct_3 *ptr;  // rsi
    int v9;  // eax
    struct_3 *v0;  // [bp-0x58], Other Possible Types: unsigned long long
    unsigned long long v1;  // [bp-0x50]
    struct_3 *v2;  // [bp-0x48]
    unsigned long long v4;  // [bp+0x10]
    unsigned long long *v5;  // [bp+0x18]
    unsigned int v6;  // [bp+0x20]

    v5 = p;
    v4 = a1;
    v1 = 18446744073709551614;
    if (!p)
        return -2147467261;
    *(p) = 0;
    v7 = -2147024882;
    v6 = 2147942414;
    v0 = 0;
    ptr = sub_7ff29106548(88);
    v2 = ptr;
    if (ptr)
    {
        ptr->field_8 = 0;
        ptr->field_0 = &g_7ff291018c8;
        memset((struct struct_3 *)&ptr->padding_28, 0, 40);
        ptr->field_50 = 0;
        *((char **)&ptr->padding_c[12]) = &g_7ff291018f0;
        ptr->field_20 = a0;
        g_7ff2910d300->field_0->field_8(g_7ff2910d300);
    }
    else
    {
        ptr = NULL;
    }
    v0 = ptr;
    if (ptr)
    {
        v9 = sub_7ff291040cc(&ptr->padding_28);
        if (v9 >= 0)
            ptr->field_50 = 1;
        v7 = (0 <= v9 ? 0 : v9);
        if (0 <= v7)
            v7 = 0;
        if (v7 || (v7 = (int)(unsigned int)(unsigned long long)ptr->field_0->field_0(ptr, a1, p), v7))
            ptr->field_0->field_18(ptr, 1, ptr->field_0);
    }
    return v7;
}


/* VA 0x7ff291067e4, RVA 0x67e4, CFG name sub_7ff291067e4; exports: [] */
typedef struct struct_0 {
    struct struct_0 *field_0;
    struct struct_0 *field_8;
    unsigned long long field_10;
    unsigned long long field_18;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
    unsigned long long field_8;
} struct_1;

extern struct_1 *g_7ff2910d0a8;
extern char g_7ff2910d209;
extern struct_0 g_7ff2910d310;
extern unsigned long long g_7ff2910d318;
extern unsigned int g_7ff2910d320;

int sub_7ff291067e4(void)
{
    int v1;  // edi
    struct_0 *cur;  // rbx

    v1 = 0;
    if (g_7ff2910d209)
        return -2147024809;
    if (!((char)g_7ff2910d320 & 1))
    {
        cur = &g_7ff2910d310.field_0;
        g_7ff2910d318 = &g_7ff2910d310.field_0;
        g_7ff2910d320 = g_7ff2910d320 | 1;
        g_7ff2910d310.field_0 = &g_7ff2910d310.field_0;
    }
    else
    {
        cur = g_7ff2910d310.field_0;
    }
    if (cur == &g_7ff2910d310.field_0)
        return 1;
    g_7ff2910d209 = 1;
    while (true)
    {
        if (cur != &g_7ff2910d310.field_0 && cur)
        {
            v1 = (!g_7ff2910d0a8 ? sub_7ff29107ca4 : g_7ff2910d0a8->field_8 ^ g_7ff2910d0a8->field_0)(cur->field_10)(cur);
            if (v1 < 0)
                goto LABEL_7ff29106896;
            cur = cur->field_0;
        }
        else
        {
            if (v1 >= 0)
                return 0;
            while (true)
            {
LABEL_7ff29106896:
                cur = cur->field_8;
                if (cur == &g_7ff2910d310.field_0 || !cur)
                    break;
                (!g_7ff2910d0a8 ? sub_7ff29107ca4 : g_7ff2910d0a8->field_8 ^ g_7ff2910d0a8->field_0)(cur->field_18)(cur);
            }
            for (; g_7ff2910d310.field_0 != &g_7ff2910d310.field_0; g_7ff2910d310.field_0->field_8 = &g_7ff2910d310.field_0)
            {
                g_7ff2910d310.field_0 = g_7ff2910d310.field_0->field_0;
            }
        }
    }
    g_7ff2910d209 = 0;
    return v1;
}


/* VA 0x7ff29108fa8, RVA 0x8fa8, CFG name sub_7ff29108fa8; exports: [] */
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

extern EXCEPTION_POINTERS g_7ff29101368;
extern unsigned long long g_7ff2910c110;
extern unsigned long long g_7ff2910c118;
extern unsigned int g_7ff2910cb00;
extern unsigned int g_7ff2910cb04;
extern unsigned long long g_7ff2910cb10;
extern char g_7ff2910cba0;
extern unsigned long long g_7ff2910cc20;
extern unsigned long long g_7ff2910cc38;
extern unsigned long long g_7ff2910cc98;

int sub_7ff29108fa8(unsigned long a0)
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
    RtlCaptureContext(&g_7ff2910cba0);
    v3 = g_7ff2910cc98;
    v2 = RtlLookupFunctionEntry(v3, &v4, NULL);
    if (v2)
    {
        RtlVirtualUnwind(UNW_FLAG_NHANDLER, v4, v3, v2, &g_7ff2910cba0, &v0, &v1, NULL);
    }
    else
    {
        g_7ff2910cc98 = v7;
        g_7ff2910cc38 = &v8;
    }
    g_7ff2910cb10 = g_7ff2910cc98;
    g_7ff2910cc20 = v8;
    g_7ff2910cb00 = 3221226505;
    g_7ff2910cb04 = 1;
    v5 = g_7ff2910c110;
    v6 = g_7ff2910c118;
    SetUnhandledExceptionFilter(NULL);
    UnhandledExceptionFilter(&g_7ff29101368.ExceptionRecord);
    return TerminateProcess(GetCurrentProcess(), 3221226505);
}


/* VA 0x7ff29104a38, RVA 0x4a38, CFG name sub_7ff29104a38; exports: [] */
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

unsigned int sub_7ff29104a38(unsigned long long a0, struct_0 *p, unsigned long a2, struct_5 **ptr)
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


/* VA 0x7ff29103978, RVA 0x3978, CFG name sub_7ff29103978; exports: [] */
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

unsigned int sub_7ff29103978(unsigned long long a0, unsigned long a1, unsigned long a2, unsigned short a3, void* a4)
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


/* VA 0x7ff291060b4, RVA 0x60b4, CFG name sub_7ff291060b4; exports: [] */
typedef struct struct_2 {
    char padding_0[112];
    struct struct_0 *field_70;
} struct_2;

typedef struct struct_0 {
    char padding_0[72];
    struct struct_1 *field_48;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_5 {
    unsigned long long field_0;
} struct_5;

typedef struct struct_4 {
    unsigned long long field_0;
} struct_4;

typedef struct struct_3 {
    char padding_0[80];
    struct struct_4 *field_50;
    struct struct_5 *field_58;
} struct_3;

extern struct_3 *g_7ff2910d1f8;

unsigned int sub_7ff291060b4(struct_2 *a0, unsigned long a1, unsigned long ptr)
{
    unsigned int v6;  // eax
    unsigned int v7;  // ebx
    unsigned long v0;  // [bp-0x28]
    unsigned long choice;  // [bp-0x20]
    unsigned long long v2;  // [bp-0x18]
    unsigned long long flag;  // [bp-0x10]
    unsigned int v5;  // [bp+0x20]

    v2 = 18446744073709551614;
    v5 = 0;
    if (sub_7ff291061e8() >= 0)
    {
        *((unsigned int *)ptr) = v5;
        return 0;
    }
    flag = 0;
    choice = 0;
    v6 = a0->field_70->field_48(L"Real-Time Protection", &choice);
    if (v6 < 0)
    {
        if (!choice)
            return v6;
        g_7ff2910d1f8->field_58(choice, g_7ff2910d1f8);
        return v6;
    }
    else
    {
        *((unsigned int *)&v0) = 0;
        v5 = 0;
        *((unsigned int *)((char *)&v0 + 4)) = 4;
        v7 = g_7ff2910d1f8->field_50(choice, L"IOAVMaxSize", &v0, (char *)&v0 + 4, &v5, 0, v0);
        if (v7 >= 0)
        {
            if ((unsigned int)v0 != 1 && (unsigned int)v0)
            {
                v7 = 2147944029;
            }
            else
            {
                if (!*((unsigned int *)((void*)&v0 + 4)))
                {
                    v5 = 0;
                    v5 = 0;
                }
                *((unsigned int *)ptr) = v5;
                if (!choice)
                    return v7;
                g_7ff2910d1f8->field_58(choice);
                return v7;
            }
        }
        if (!choice)
            return v7;
        g_7ff2910d1f8->field_58(choice);
        return v7;
    }
}


/* VA 0x7ff291041b8, RVA 0x41b8, CFG name sub_7ff291041b8; exports: [] */
typedef struct struct_1 {
    char padding_0[8];
    unsigned int field_8;
    char padding_c[20];
    unsigned long long field_20;
} struct_1;

int sub_7ff291041b8(unsigned long a0, unsigned long a1)
{
    struct_1 *flag;  // rbx
    struct_1 *flag2;  // rsi
    unsigned int v4;  // ebp
    struct_1 *v5;  // rax
    struct_1 *v6;  // rsi
    struct_1 *v7;  // rdi
    struct_1 *v8;  // rbx
    unsigned int v9;  // eax
    struct_1 *choice;  // [bp+0x18]

    flag = NULL;
    choice = NULL;
    flag2 = NULL;
    v4 = sub_7ff29105504(&choice);
    if (v4 < 0)
    {
        v5 = choice;
        v6 = flag2;
        if (v5 && !((InterlockedExchangeAdd(v5 + 8, 4294967295), v6 = flag2, v5 > NULL)))
            goto LABEL_7ff2910420a;
    }
    else
    {
        v7 = choice;
        v4 = sub_7ff29104cf8(v7);
        if (v4 < 0)
        {
            v6 = flag2;
            if (v7 && !((InterlockedExchangeAdd(v7 + 8, 4294967295), v6 = flag2, v7 > NULL)))
            {
LABEL_7ff2910420a:
                (*((long long *)&choice->padding_0))(choice, 1);
                v6 = flag2;
            }
        }
        else
        {
            v4 = 0;
            v6 = v7;
        }
    }
    if (v4 < 0)
    {
        v8 = flag;
        if (v6)
        {
            InterlockedExchangeAdd(&v6->field_8, 4294967295);
            v8 = flag;
            if (v6->field_8 + 4294967295 <= 0)
            {
                (*((long long *)&v6->padding_0))(v6, 1);
                v8 = flag;
            }
        }
    }
    else
    {
        v8 = v6;
    }
    if (v4 < 0)
    {
        if (!v8)
            return v4;
        InterlockedExchangeAdd(&v8->field_8, 4294967295);
        if (v8->field_8 + 4294967295 <= 0)
            (*((long long *)&v8->padding_0))(v8, 1, v8->padding_0);
        return v4;
    }
    else
    {
        v9 = (*((long long *)&v8->padding_0[8]))(v8, a1);
        if (v9 < 0)
        {
            InterlockedExchangeAdd(&v8->field_8, 4294967295);
            if (v8->field_8 + 4294967295 <= 0)
                (*((long long *)&v8->padding_0))(v8, 1, v8->padding_0);
        }
        else
        {
            InterlockedExchangeAdd(&v8->field_8, 4294967295);
            if (v8->field_8 + 4294967295 <= 0)
                (*((long long *)&v8->padding_0))(v8, 1);
        }
        return v9;
    }
}


/* VA 0x7ff29107d04, RVA 0x7d04, CFG name sub_7ff29107d04; exports: [] */
typedef struct struct_0 {
    unsigned long long field_0;
    struct struct_0 *field_8;
} struct_0;

extern struct_0 *g_7ff2910d0a8;
extern unsigned long long g_7ff2910d1e0;

void* sub_7ff29107d04(void)
{
    void* v1;  // rsi
    unsigned long long v2;  // rbp
    unsigned long long v11;  // rbp
    unsigned long v12;  // rdx
    char v13;  // cl
    unsigned long long v14;  // rbp
    void* ptr;  // rdi
    HMODULE v4;  // rax
    void* v5;  // rax
    void* v6;  // rax
    void* v7;  // rax
    unsigned int v8;  // ebx
    unsigned int v10;  // eax
    char *v0;  // [bp+0x8], Other Possible Types: unsigned long

    v1 = NULL;
    v2 = 16;
    ptr = HeapAlloc(GetProcessHeap(), HEAP_NONE, 0x10);
    if (!ptr)
        return ptr;
    v4 = GetModuleHandleW(L"kernel32.dll");
    if (!v4 || (v5 = (void*)GetProcAddress(v4, "EncodePointer"), *((void* *)ptr) = v5, !v5 || (v6 = (void*)GetProcAddress(v4, "DecodePointer"), *((void* *)&ptr[8]) = v6, !v6)))
    {
        v7 = sub_7ff29108208();
        v8 = (unsigned int)v7;
    }
    else
    {
        *((unsigned long *)ptr) = *((long long *)ptr) ^ ptr;
        v7 = *((long long *)ptr) ^ v6;
        v8 = 0;
        *((void* *)&ptr[8]) = v7;
    }
    if (v8 < 0)
    {
        v7 = HeapFree(GetProcessHeap(), HEAP_NONE, ptr);
    }
    else
    {
        v1 = ptr;
        v8 = 0;
    }
    if (v8 >= 0)
    {
        v7 = sub_7ff29108cdc();
        if (!(unsigned int)v7)
        {
            v7 = g_7ff2910d0a8;
            g_7ff2910d0a8 = v1;
            v1 = v7;
        }
    }
    if (!v1)
        return v7;
    HeapFree(GetProcessHeap(), HEAP_NONE, v1);
    v0 = &v0;
    v10 = GetTickCount();
    do
    {
        v11 = v2;
        v13 = (char)v10 * (char)v0 & 63;
    } while ((v0 = (char *)((v13 & 63) ? v12 << (v13 & 63) | v12 >> 64 - (v13 & 63) : v12 << (v13 & 63) | v12 >> 64 - (v13 & 63)), v14 = v11 - 1, v2 = v11 - 1, v11 != 1));
    if (!v0)
        v0 = 0xab46ed1d;
    g_7ff2910d1e0 = v0;
    return 0xab46ed1d;
}


/* VA 0x7ff29107730, RVA 0x7730, CFG name sub_7ff29107730; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    unsigned int field_10;
    char padding_14[8];
    char field_1c;
} struct_0;

extern struct_0 *g_7ff2910c310;

unsigned int sub_7ff29107730(unsigned long long a0, unsigned short *p, unsigned long long *ptr)
{
    unsigned long long v1;  // rax
    unsigned int v2;  // edi
    unsigned long long idx;  // rbx

    if (((char)*(ptr) & 1))
        *(ptr) = *(ptr) - 1;
    v1 = *(ptr);
    v2 = 0;
    idx = v1 >> 1;
    if (idx <= 1)
    {
        if (idx == 1)
            goto LABEL_7ff29107790;
LABEL_7ff29107797:
        if (idx <= 0)
            goto LABEL_7ff291077ef;
LABEL_7ff2910779c:
        if (!p[1 + idx])
        {
            if (idx < a0)
            {
                if (g_7ff2910c310 != &g_7ff2910c310 && (g_7ff2910c310->field_1c & 1))
                    sub_7ff29106a0c(*((long long *)&g_7ff2910c310->field_10), 15);
                *(ptr) = *(ptr) + 2;
                p[idx] = 0;
            }
            else
            {
                *(ptr) = v1 + 2;
                return 2147942634;
            }
        }
        else
        {
LABEL_7ff291077ef:
            if (idx + 1 < a0)
            {
                if (g_7ff2910c310 != &g_7ff2910c310 && (g_7ff2910c310->field_1c & 1))
                    sub_7ff29106a0c(*((long long *)&g_7ff2910c310->field_10), 16);
                p[idx] = 0;
                p[1 + idx] = 0;
            }
            else
            {
                if (g_7ff2910c310 != &g_7ff2910c310 && (g_7ff2910c310->field_1c & 2))
                    sub_7ff29106a0c(*((long long *)&g_7ff2910c310->field_10), 17);
                v2 = 2147942634;
            }
            *(ptr) = *(ptr) + 4;
            return v2;
        }
    }
    else if (!(!p[2 + idx] && !p[1 + idx]))
    {
        if (idx != 1)
            goto LABEL_7ff29107797;
LABEL_7ff29107790:
        if (*(p))
            goto LABEL_7ff2910779c;
    }
    else if (idx == 2)
    {
        *(ptr) = v1 - 2;
    }
    return 0;
}


/* VA 0x7ff291089a0, RVA 0x89a0, CFG name sub_7ff291089a0; exports: [] */
typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

extern unsigned int g_7ff2910c120;
extern char g_7ff2910caec;
extern unsigned int g_7ff2910caf0;
extern struct_0 *g_7ff2910d348;

unsigned int sub_7ff291089a0(long long a0, unsigned int flag, long long a2)
{
    unsigned int v3;  // ebx
    unsigned int v0;  // [bp-0x138]
    long long v1;  // [bp+0x8]
    unsigned int v2;  // [bp+0x10]

    v2 = flag;
    v1 = a0;
    v3 = 1;
    v0 = 1;
    g_7ff2910c120 = flag;
    if (!flag && *((int *)&g_7ff2910caec) == flag)
    {
        v3 = 0;
        v0 = 0;
    }
    else
    {
        if (flag == 1 || flag == 2)
        {
            if (g_7ff2910d348)
            {
                g_7ff2910caf0 = 1;
                v3 = g_7ff2910d348();
                v0 = v3;
            }
            if (v3)
            {
                v3 = sub_7ff291087c8(a0, flag, a2);
                v0 = v3;
            }
            if (!v3)
            {
                g_7ff2910c120 = 4294967295;
                return v3;
            }
        }
        v3 = sub_7ff29103cfc(a0, flag, a2);
        v0 = v3;
        if (flag == 1 && !v3)
        {
            sub_7ff29103cfc(a0, 0, 0);
            sub_7ff291087c8(a0, 0, 0);
            if (g_7ff2910d348)
                g_7ff2910d348(a0, 0, 0);
        }
        if (!flag || flag == 3)
        {
            v3 = sub_7ff291087c8(a0, flag, a2);
            v0 = v3;
            if (g_7ff2910d348 && g_7ff2910caf0)
            {
                v3 = g_7ff2910d348(a0, flag, a2);
                v0 = v3;
            }
        }
    }
    g_7ff2910c120 = 4294967295;
    return v3;
}


/* VA 0x7ff29102809, RVA 0x2809, CFG name sub_7ff29102809; exports: [] */
typedef struct struct_0 {
    char field_0;
    unsigned int field_1;
    unsigned int field_5;
} struct_0;

typedef struct struct_1 {
    char field_0;
    unsigned int field_1;
    unsigned int field_5;
    char padding_9[3145728];
    char field_300009;
} struct_1;

extern char g_2800[4];
extern void g_8000048;
extern char g_80000a4;

void sub_7ff29102809(char *ptr8, char *ptr12)
{
    void* ptr;  // rax
    unsigned long v9;  // cc_ndep
    unsigned long v10;  // 4223
    char v11;  // 4140
    char *ptr14;  // rax
    struct_0 *ptr15;  // rdi
    struct_1 *v14;  // rsi
    char v15;  // 4210
    void* ptr5;  // rax
    void* p;  // rax
    struct_1 *ptr17;  // rsi
    char v19;  // 4296
    void* ptr6;  // rax
    void* addr;  // rax
    char *ptr16;  // rax
    char *ptr9;  // rax
    char *ptr4;  // rax
    char *ptr7;  // rax
    char v26;  // 4114
    char *ptr10;  // rax
    unsigned long v28;  // rbx
    struct_0 *cur;  // rdi
    struct_1 *v4;  // rsi
    char v5;  // 4132
    char *ptr3;  // rax
    char *ptr11;  // rax
    char v8;  // 4167
    char v0;  // [bp+0x0]

    [D] Unsupported jumpkind Ijk_NoDecode at address 8792486979593()
    do
    {
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((unsigned int *)ptr) = *((int *)ptr) + (unsigned int)ptr;
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        v5 = *((char *)&ptr) & *(0x7ff291241b9);
        ptr3 = (char *)_INSERT(ptr, 0, *((char *)&ptr) & *(0x7ff291241b9));
        *(ptr3) = *(ptr3) + (*((char *)&ptr) & *(0x7ff291241b9));
        ptr8[0x10000] = ptr8[0x10000] - *((char *)((void*)&ptr3 + 1));
        *(ptr3) = *(ptr3) + v5;
        if ([D] unsupported_<class 'pyvex.expr.GetI'>())
        {
            [D] PutI(904:F64x8)[t3,0] = t4()
            [D] PutI(968:I8x8)[t3,0] = 0x01()
        }
        else
        {
            [D] PutI(904:F64x8)[t3,0] = t4()
            [D] PutI(968:I8x8)[t3,0] = 0x01()
        }
        *(ptr3) = *(ptr3) + *((char *)&ptr3);
        *((char *)(ptr3 * 2 + 0x2800)) = *((char *)(ptr3 * 2 + 0x2800)) + *((char *)((void*)&ptr3 + 1));
        *(ptr3) = *(ptr3) + *((char *)&ptr3);
        *(ptr3) = *(ptr3) + *((char *)&ptr3);
        *(ptr8) = *(ptr8) + *((char *)&ptr3);
        *(ptr3) = *(ptr3) + *((char *)&ptr3);
        *(ptr3) = *(ptr3) + *((char *)&ptr3);
        *(ptr3) = *(ptr3) + *((char *)&ptr3);
        *(ptr3) = *(ptr3) + *((char *)&ptr3);
        *(ptr3) = *(ptr3) + *((char *)&ptr3);
        *(ptr12) = *(ptr12) + *((char *)((void*)&ptr3 + 1));
        ptr11 = (unsigned int)ptr3 + 137619;
        *(ptr11) = *(ptr11) + *((char *)&ptr11);
        ptr8[0x10000] = ptr8[0x10000] - *((char *)((void*)&ptr11 + 1));
        *(ptr11) = *(ptr11) + *((char *)&ptr11);
        cur->field_0 = v4->field_0;
        cur = &(&cur->field_0)[1];
        v4 = &(&v4->field_0)[1];
        *(ptr11) = *(ptr11) + *((char *)&ptr11);
        ptr = (void*)_INSERT(ptr11, 0, *((char *)&ptr11));
        v8 = *((char *)ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr11);
        v10 = _ccall(4, 1, (unsigned long long)v8, (unsigned long long)*((char *)(void*)&ptr11), v9);
    } while ((char)v10);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) - *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((unsigned int *)ptr) = *((int *)ptr) + (unsigned int)ptr;
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    v11 = *((char *)&ptr) & *(0x7ff29124219);
    ptr14 = (char *)_INSERT(ptr, 0, *((char *)&ptr) & *(0x7ff29124219));
    *(ptr14) = *(ptr14) + (*((char *)&ptr) & *(0x7ff29124219));
    ptr8[0x10000] = ptr8[0x10000] - *((char *)((void*)&ptr14 + 1));
    *(ptr14) = *(ptr14) + v11;
    g_80000a4 = g_80000a4 + 164;
    cur->field_0 = v4->field_0;
    ptr15 = &(&cur->field_0)[1];
    v14 = &(&v4->field_0)[1];
    g_8000048 = g_8000048 + 72;
    g_8000048 = g_8000048 & 72;
    g_8000048 = g_8000048 + 72;
    g_8000048 = g_8000048 + 72;
    g_8000048 = g_8000048 + 72;
    *((void **)&g_8000048) = &(&g_8000048)[*((int *)&g_8000048)];
    g_8000048 = g_8000048 + 72;
    g_8000048 = g_8000048 + 72;
    g_8000048 = g_8000048 + 72;
    g_8000048 = g_8000048 + 72;
    g_8000048 = g_8000048 + 72;
    v15 = 72 & *(0x7ff29114249);
    ptr5 = 72 & *(0x7ff29114249) | 0x8000000;
    *((char *)ptr5) = *((char *)ptr5) + v15;
    *((char *)ptr5) = *((char *)ptr5) + v15;
    *((char *)ptr5) = *((char *)ptr5) + v15;
    *((char *)ptr5) = *((char *)ptr5) + v15;
    *((char *)ptr5) = *((char *)ptr5) + v15;
    *((char *)ptr5) = *((char *)ptr5) + v15;
    p = (unsigned int)ptr5 + *((int *)ptr5);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((int *)&ptr15->field_0) = *((int *)&v14->field_0);
    ptr17 = &v14->field_1;
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) & *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((unsigned int *)p) = *((int *)p) + (unsigned int)p;
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    *((char *)p) = *((char *)p) + *((char *)&p);
    v19 = *((char *)&p) & *(0x7ff29124279);
    ptr6 = (void*)_INSERT(p, 0, *((char *)&p) & *(0x7ff29124279));
    *((char *)ptr6) = *((char *)ptr6) + v19;
    ptr15->field_1 = *((int *)&ptr17->field_0);
    *((char *)ptr6) = *((char *)ptr6) + v19;
    *((char *)ptr6) = *((char *)ptr6) + v19;
    *((char *)ptr6) = *((char *)ptr6) + v19;
    *((char *)ptr6) = *((char *)ptr6) + v19;
    *((char *)ptr6) = *((char *)ptr6) + v19;
    addr = (unsigned int)ptr6 | *((int *)ptr6);
    *((char *)addr) = *((char *)addr) + *((char *)&addr);
    ptr17->padding_9[3145720] = ptr17->padding_9[3145720] | *((char *)((void*)&addr + 1));
    *((char *)addr) = *((char *)addr) + *((char *)&addr);
    *((char *)addr) = *((char *)addr) + *((char *)&addr);
    *((char *)addr) = *((char *)addr) + *((char *)&addr);
    *((unsigned int *)addr) = *((int *)addr) + (unsigned int)addr;
    *((char *)addr) = *((char *)addr) + *((char *)&addr);
    *((char *)addr) = *((char *)addr) + *((char *)&addr);
    *((char *)addr) = *((char *)addr) + *((char *)&addr);
    *((char *)addr) = *((char *)addr) + *((char *)&addr);
    *((char *)addr) = *((char *)addr) + *((char *)&addr);
    ptr16 = (char *)_INSERT(addr, 0, *((char *)&addr) & *(0x7ff291142a9));
    *(ptr16) = *(ptr16) + (*((char *)&addr) & *(0x7ff291142a9));
    ptr9 = &v0 & 4294967295;
    *(ptr9) = *(ptr9) + *((char *)&ptr9);
    *(ptr9) = *(ptr9) + *((char *)&ptr9);
    *(ptr9) = *(ptr9) + *((char *)&ptr9);
    *(ptr9) = *(ptr9) + *((char *)&ptr9);
    *(ptr9) = *(ptr9) + *((char *)&ptr9);
    ptr4 = (unsigned int)ptr9 - 0x64000000;
    *(ptr4) = *(ptr4) + *((char *)&ptr4);
    *(ptr4) = *(ptr4) + *((char *)&ptr4);
    *(ptr4) = *(ptr4) + *((char *)&ptr4);
    *(ptr4) = *(ptr4) + *((char *)&ptr4);
    *(ptr8) = *(ptr8) + *((char *)&ptr4);
    *(ptr4) = *(ptr4) + *((char *)&ptr4);
    *(ptr4) = *(ptr4) + *((char *)&ptr4);
    *(ptr4) = *(ptr4) + *((char *)&ptr4);
    *(ptr4) = *(ptr4) + *((char *)&ptr4);
    *(ptr4) = *(ptr4) + *((char *)&ptr4);
    *(ptr12) = *(ptr12) + *((char *)((void*)&ptr4 + 1));
    ptr7 = (unsigned int)ptr4 + 268691;
    *(ptr7) = *(ptr7) + *((char *)&ptr7);
    *(ptr7) = *(ptr7) + *((char *)&ptr7);
    *(ptr7) = *(ptr7) + *((char *)&ptr7);
    *(ptr7) = *(ptr7) + *((char *)&ptr7);
    *(ptr7) = *(ptr7) + *((char *)&ptr7);
    v26 = *(ptr7);
    *(ptr7) = *(ptr7) + *((char *)&ptr7);
    ptr10 = (unsigned int)ptr7 - 0x1c000000 - ((unsigned int)(v26 + *((char *)&ptr7) <= v26 ? 1 : 0) & 1);
    *(ptr10) = *(ptr10) + *((char *)&ptr10);
    *(ptr10) = *(ptr10);
    *(ptr10) = *(ptr10) + *((char *)&ptr10);
    *(ptr10) = *(ptr10) + *((char *)&ptr10);
    *(ptr8) = *(ptr8) + *((char *)&ptr10);
    *(ptr10) = *(ptr10) + *((char *)&ptr10);
    ptr12[83] = ptr12[83] + *((char *)&ptr12);
    *((unsigned long *)((ptr16 & 4294967295) - 8)) = v28;
}


/* VA 0x7ff29106ed4, RVA 0x6ed4, CFG name sub_7ff29106ed4; exports: [] */
extern unsigned long long g_7ff2910c110;

void sub_7ff29106ed4(unsigned int a0, HMODULE a1)
{
    unsigned int v6;  // eax
    void* ptr;  // rbx
    unsigned long long v8;  // rdi
    unsigned long long v9;  // rdx
    unsigned int v10;  // eax
    char v0;  // [bp-0x268]
    unsigned long long v1;  // [bp-0x248]
    void* v2;  // [bp-0x240]
    char v3;  // [bp-0x238]
    unsigned long long v4;  // [bp-0x28]

    v4 = g_7ff2910c110 ^ &v0;
    v1 = 260;
    v6 = sub_7ff29106e08(&v1, &v3, a1);
    if (v6 >= 0)
    {
        sub_7ff29108270(a0, &v3);
        sub_7ff29108bf0(v4 ^ &v0);
        return;
    }
    if (v6 == 2147942522)
        v6 = 0;
    if (v6 < 0)
    {
        sub_7ff29108bf0(v4 ^ &v0);
        return;
    }
    ptr = NULL;
    v2 = NULL;
    v8 = v1 * 3 >> 1;
    if (v1 < v8)
    {
        do
        {
            v1 = v8;
            if (ptr)
            {
                free(ptr);
                ptr = NULL;
                v2 = NULL;
            }
            v9 = v8 * 2;
            if (v9 >> 1 == v8)
            {
                ptr = v2;
                if ((int)sub_7ff29108238(&v2, v9) < 0)
                    goto LABEL_7ff29107027;
                v10 = sub_7ff29106e08(&v1, ptr, a1);
                if (v10 >= 0)
                {
                    sub_7ff29108270(a0, ptr);
                    goto LABEL_7ff29107027;
                }
                else if (!(v10 == 2147942522))
                {
                    goto LABEL_7ff29107027;
                }
            }
            else
            {
LABEL_7ff29107027:
                if (ptr)
                    free(ptr);
                sub_7ff29108bf0(v4 ^ &v0);
                return;
            }
        } while ((v8 = v1 * 3 >> 1, v1 < v8));
        if (ptr)
            free(ptr);
    }
    sub_7ff29108bf0(v4 ^ &v0);
    return;
}


/* VA 0x7ff2910795c, RVA 0x795c, CFG name sub_7ff2910795c; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    long long field_10;
    char padding_18[4];
    char field_1c;
} struct_0;

extern long long g_7ff291021c0;
extern struct_0 *g_7ff2910c310;

unsigned long long sub_7ff2910795c(HKEY a0, unsigned short *a1, unsigned int *a2, unsigned long long *ptr, Byte *a4)
{
    unsigned int v2;  // ebx
    unsigned long long v3;  // rax
    unsigned long long v4;  // rax
    unsigned int v1;  // [bp+0x20]

    v1 = *(ptr);
    v2 = (unsigned long long)RegQueryValueExW(a0, a1, NULL, a2, a4, &v1);
    if (v2 > 0)
        v2 = v2 & 65535 | 0x80070000;
    if (v2 >= 0)
    {
        if (a4 && !((v3 = (unsigned long long)v1, v3 <= *(ptr))))
        {
            *(ptr) = v3;
            v2 = 2147942634;
        }
        else
        {
            *(ptr) = v1;
LABEL_7ff29107ac4:
            return sub_7ff29107888(a1, v1, *(a2), ptr, a4);
        }
    }
    else
    {
        if (v2 == 2147942402)
        {
            if (g_7ff2910c310 != &g_7ff2910c310 && (g_7ff2910c310->field_1c & 4))
                sub_7ff29106a78(g_7ff2910c310->field_10, 18, &g_7ff291021c0, a1);
            v2 = 2147942402;
        }
        else if (v2 == 2147942634)
        {
            v4 = v1;
            if (*(ptr) >= v4)
            {
                v2 = 2147549183;
            }
            else
            {
                *(ptr) = v4;
                v2 = 2147942634;
LABEL_7ff29107aa4:
                if (v2 != 2147942634 && v2 != 2147942402 && v2 >= 0)
                    goto LABEL_7ff29107ac4;
            }
        }
        else if (g_7ff2910c310 != &g_7ff2910c310 && (g_7ff2910c310->field_1c & 1))
        {
            sub_7ff29106b9c(g_7ff2910c310->field_10, 19, &g_7ff291021c0, a1);
            goto LABEL_7ff29107aa4;
        }
    }
    return v2;
}


/* VA 0x7ff291061e8, RVA 0x61e8, CFG name sub_7ff291061e8; exports: [] */
typedef struct struct_0 {
    char padding_0[24];
    unsigned long long field_18;
} struct_0;

unsigned int sub_7ff291061e8(struct_0 *a0, unsigned long long a1, unsigned int a2, unsigned long addr)
{
    unsigned int v4;  // eax
    unsigned long ptr;  // rbx
    unsigned int v6;  // eax
    unsigned long long v7;  // rbp
    unsigned int v8;  // eax
    unsigned long p;  // [bp-0x38], Other Possible Types: unsigned long long
    unsigned long v1;  // [bp-0x30]
    unsigned long v2;  // [bp-0x28]
    unsigned int flag;  // [bp+0x8], Other Possible Types: unsigned long

    flag = 0;
    v4 = sub_7ff2910730c(&flag, L"CLSID\\%s\\Hosts\\%s", a0 + 1, a1);
    if (v4 < 0)
    {
        if (!flag)
            return v4;
        free(flag);
        return v4;
    }
    else
    {
        ptr = flag;
        p = 0;
        v6 = sub_7ff2910730c(&p, L"%s\\%s", ptr, a0->field_18);
        if (v6 < 0)
        {
            if (p)
                free(p);
            if (!ptr)
                return v6;
            free(ptr);
            return v6;
        }
        else
        {
            v2 = ptr;
            v7 = 0;
            v1 = p;
            while (true)
            {
                p = 0;
                v8 = sub_7ff29107468(&p, 0xffffffff80000000, (&v1)[v7], 0x80000000);
                if (v8 >= 0 && !((flag = 0, v8 = (unsigned int)sub_7ff29107ae8(p, a2, &flag), v8 < 0)))
                    break;
                if (p)
                    RegCloseKey(p);
                v7 += 1;
                if (v7 >= 2)
                {
                    if (p)
                        free(p);
                    if (!ptr)
                        return v8;
                    free(ptr);
                    return v8;
                }
            }
            *((unsigned int *)addr) = flag;
            if (p)
                RegCloseKey(p);
            if (p)
                free(p);
            if (!ptr)
                return 0;
            free(ptr);
            return 0;
        }
    }
}


/* VA 0x7ff29105b14, RVA 0x5b14, CFG name sub_7ff29105b14; exports: [] */
typedef struct struct_1 {
    char padding_0[8];
    unsigned int field_8;
    char padding_c[4];
    unsigned long long field_10;
    char padding_18[88];
    unsigned long long field_70;
} struct_1;

typedef struct struct_0 {
    char padding_0[2];
    unsigned short field_2;
} struct_0;

typedef struct Guid {
    unsigned int Data1;
    unsigned short Data2;
    unsigned short Data3;
    char Data4[8];
} Guid;

extern unsigned long long g_10;
extern unsigned long long g_18;
extern unsigned long long g_70;
extern Guid g_7ff291017f0;

int sub_7ff29105b14(struct_1 **addr, unsigned long long a1)
{
    struct_1 *v2;  // rdi
    unsigned int v3;  // esi
    struct_1 *ptr;  // rbx
    unsigned int v5;  // r14d
    struct_0 *v6;  // rax
    struct_0 *v7;  // rax
    unsigned long long v8;  // r8
    struct_1 *p;  // rax
    struct_1 *v10;  // rcx
    unsigned long long flag;  // rdx
    struct_1 *choice;  // [bp+0x18]

    v2 = NULL;
    choice = NULL;
    v3 = sub_7ff291063a4(&choice);
    if (v3 >= 0)
    {
        ptr = choice;
        if (ptr->field_10)
        {
            free(ptr->field_10);
            ptr->field_10 = 0;
        }
        v5 = (unsigned long long)sub_7ff29106ed4(*((unsigned int *)&(struct struct_1 *)&ptr->field_10), NULL);
        if (v5 >= 0)
        {
            v6 = wcsrchr(ptr->field_10, 92);
            *((struct_0 **)&ptr->padding_18[0]) = v6;
            if (!v6 || (v7 = v6 + 2, *((struct_0 **)&ptr->padding_18[0]) = v7, !v7->padding_0))
            {
                v3 = 2147942523;
            }
            else
            {
                v8 = 39;
                if (!StringFromGUID2(&g_7ff291017f0.Data1, &ptr->padding_18[8], 39))
                {
                    v3 = 2147942522;
                }
                else
                {
                    p = &ptr->field_70;
                    if (a1)
                    {
                        InterlockedIncrement(a1 + 8);
                        ptr = choice;
                    }
                    v10 = (struct_1 *)p->padding_0;
                    *((unsigned long long *)&p->padding_0[0]) = a1;
                    if (v10)
                    {
                        InterlockedExchangeAdd(&v10->field_8, 4294967295);
                        if (v10->field_8 - 1 <= 0)
                        {
                            flag = 1;
                            (*((long long *)&v10->padding_0))();
                        }
                        ptr = choice;
                    }
                    goto LABEL_7ff29105c40;
                }
            }
LABEL_7ff29105c48:
            if (ptr)
                InterlockedExchangeAdd(&ptr->field_8, 4294967295);
        }
        else
        {
LABEL_7ff29105c40:
            v3 = v5;
            if (v3 < 0)
                goto LABEL_7ff29105c48;
            v2 = ptr;
            v3 = 0;
        }
    }
    else if (choice)
    {
        InterlockedExchangeAdd(&choice->field_8, 4294967295);
    }
    if (v3 >= 0)
    {
        *(addr) = v2;
        return v3;
    }
    else if (v2)
    {
        InterlockedExchangeAdd(&v2->field_8, 4294967295);
        if (v2->field_8 - 1 > 0)
            return v3;
        (*((long long *)&v2->padding_0))(v2, 1, v2->padding_0);
        return v3;
    }
    else
    {
        return v3;
    }
}


/* VA 0x7ff29103cfc, RVA 0x3cfc, CFG name sub_7ff29103cfc; exports: [] */
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

typedef struct CRITICAL_SECTION {
    struct CRITICAL_SECTION_DEBUG *DebugInfo;
    int LockCount;
    int RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    UIntPtr SpinCount;
} CRITICAL_SECTION;

extern char g_7ff29101760;
extern struct_1 *g_7ff2910c310;
extern unsigned long long g_7ff2910d078;
extern struct_0 *g_7ff2910d080;
extern unsigned long long g_7ff2910d090;
extern char g_7ff2910d098;
extern char g_7ff2910d099;
extern unsigned short g_7ff2910d09a;
extern unsigned int g_7ff2910d09c;
extern Guid *g_7ff2910d0a0;
extern unsigned int g_7ff2910d20c;
extern CRITICAL_SECTION g_7ff2910d258;
extern char g_7ff2910d2f8;
extern void g_7ff2910d324;

unsigned int sub_7ff29103cfc(unsigned long a0, unsigned int flag)
{
    struct_0 **p;  // rsi
    Guid **v4;  // rbp
    unsigned int v7;  // eax
    struct_1 *ptr;  // rdi
    int v0;  // [bp-0x18], Other Possible Types: TRACE_GUID_REGISTRATION

    if (flag)
    {
        if (flag != 1)
            goto LABEL_7ff29103e79;
        sub_7ff29103acc();
        g_7ff2910d098 = flag;
        p = &g_7ff2910d080;
        g_7ff2910d090 = 0;
        g_7ff2910d080 = 0;
        g_7ff2910d099 = 0;
        g_7ff2910d09a = 0;
        g_7ff2910c310 = &g_7ff2910d080;
        g_7ff2910d09c = 0;
        g_7ff2910d0a0 = &g_7ff29101760;
        v4 = &g_7ff2910d0a0;
        do
        {
            *((Guid **)&v0) = *(v4);
            v0.RegHandle = 0;
            RegisterTraceGuidsW(sub_7ff29103bd8, p, *(v4), 1, &v0, NULL, NULL, p + 1);
            p = *(p);
            v4 += 1;
        } while (p);
        g_7ff2910d078 = a0;
        *((unsigned int *)&g_7ff2910d324) = 0;
        if (sub_7ff291066bc() < 0)
            return 0;
        *((unsigned int *)&g_7ff2910d324) = *((int *)&g_7ff2910d324) | 2;
        if ((!DisableThreadLibraryCalls(a0) ? (unsigned int)sub_7ff29108208() : 0) < 0)
            return 0;
        v7 = sub_7ff291073f4(&g_7ff2910d258.DebugInfo);
        if ((v7 < 0 ? v7 : 0) < 0)
            return 0;
        *((unsigned int *)&g_7ff2910d324) = *((int *)&g_7ff2910d324) | 1;
LABEL_7ff29103e7e:
        if (g_7ff2910d2f8)
            return 0;
    }
    else
    {
        if ((g_7ff2910d324 & 2) && g_7ff2910d20c)
            sub_7ff29106654();
        ptr = g_7ff2910c310;
        if (g_7ff2910c310 != &g_7ff2910c310)
        {
            for (g_7ff2910d078 = 0; ptr; ptr = ptr->field_0)
            {
                if (ptr->field_8)
                {
                    UnregisterTraceGuids(ptr->field_8);
                    ptr->field_8 = 0;
                }
            }
            g_7ff2910c310 = &g_7ff2910c310;
LABEL_7ff29103e79:
            if (flag == 1)
                goto LABEL_7ff29103e7e;
        }
    }
    return 1;
}


/* VA 0x7ff29102658, RVA 0x2658, CFG name sub_7ff29102658; exports: [] */
typedef struct struct_0 {
    char field_0;
    char padding_1[524287];
    char field_80000;
    char padding_80001[1572863];
    char field_200000;
} struct_0;

typedef struct struct_1 {
    char padding_0[2097152];
    unsigned short field_200000;
} struct_1;

extern char g_a2b8000000080000;
extern unsigned long long g_a324000000010000;

void sub_7ff29102658(char *ptr10, struct_0 *ptr14, unsigned long a2, unsigned long a3, unsigned long a4)
{
    char v1;  // al
    void* ptr4;  // rax
    char v11;  // 4106
    unsigned long v12;  // 4492
    void* p;  // rax
    struct_1 *ptr18;  // rdi
    unsigned short v15;  // ds_seg
    char v16;  // 4158
    void* ptr8;  // rax
    char v18;  // 4164
    void* ptr5;  // rax
    char *ptr15;  // rax
    char v3;  // 4143
    char *ptr16;  // rax
    char v22;  // 4593
    void* ptr9;  // rax
    char v24;  // 4278
    char v25;  // 4277
    void* addr;  // rax
    char v27;  // 4341
    char ptr6[536871074];  // rax
    void* ptr3;  // rax
    void* ptr;  // rax
    char *ptr12;  // rax
    char v31;  // 4145
    char *ptr13;  // rax
    char *ptr17;  // rsi
    char v6;  // bl
    char *ptr7;  // rax
    void* ptr11;  // rax
    char v9;  // 4217
    unsigned long v10;  // 4303

    ptr4 = (void*)_INSERT(v1 CONCAT 0, 0, v1 & 158);
    *((char *)ptr4) = *((char *)ptr4) + (v1 & 158);
    *((char *)ptr4) = *((char *)ptr4) & v1 & 158;
    *((char *)ptr4) = *((char *)ptr4) + (v1 & 158);
    *((char *)ptr4) = *((char *)ptr4) + (v1 & 158);
    *((char *)ptr4) = *((char *)ptr4) + (v1 & 158);
    *((unsigned int *)ptr4) = *((int *)ptr4) + (unsigned int)ptr4;
    *((char *)ptr4) = *((char *)ptr4) + (v1 & 158);
    *((char *)ptr4) = *((char *)ptr4) + (v1 & 158);
    *((char *)ptr4) = *((char *)ptr4) + (v1 & 158);
    *((char *)ptr4) = *((char *)ptr4) + (v1 & 158);
    *((char *)ptr4) = *((char *)ptr4) + (v1 & 158);
    v3 = v1 & 158 & *(0x7ff29114009);
    ptr12 = (char *)_INSERT(ptr4, 0, v1 & 158 & *(0x7ff29114009));
    *(ptr12) = *(ptr12) + v3;
    *(ptr17) = v6;
    *(ptr12) = *(ptr12) + v3;
    *(ptr12) = *(ptr12) + v3;
    *(ptr12) = *(ptr12) + v3;
    ptr7 = (unsigned int)ptr12 | 0x90000000;
    *(ptr7) = *(ptr7) + *((char *)&ptr7);
    *(ptr7) = *(ptr7) + *((char *)&ptr7);
    *(ptr7) = *(ptr7) + *((char *)&ptr7);
    *(ptr7) = *(ptr7) + *((char *)&ptr7);
    *(ptr10) = *(ptr10) + *((char *)&ptr7);
    *(ptr7) = *(ptr7) + *((char *)&ptr7);
    *(ptr7) = *(ptr7) + *((char *)&ptr7);
    *(ptr7) = *(ptr7) + *((char *)&ptr7);
    *(ptr7) = *(ptr7) + *((char *)&ptr7);
    *(ptr7) = *(ptr7) + *((char *)&ptr7);
    ptr14->field_0 = ptr14->field_0 + *((char *)((void*)&ptr7 + 1));
    ptr11 = (unsigned int)ptr7 + 203155;
    v9 = *((char *)ptr11);
    *((char *)ptr11) = *((char *)ptr11) + *((char *)&ptr11);
    v10 = _ccall(4, 1, (unsigned long long)v9, (unsigned long long)*((char *)(void*)&ptr11), 0);
    if (!((char)v10))
    {
        *((char *)ptr11) = *((char *)ptr11) + *((char *)&ptr11);
        *((unsigned int *)ptr11) = *((int *)ptr11) + (unsigned int)ptr11;
        v11 = *((char *)ptr11);
        *((char *)ptr11) = *((char *)ptr11) + *((char *)&ptr11);
        v12 = _ccall(1, (unsigned long long)v11, (unsigned long long)*((char *)(void*)&ptr11), 0);
        p = ptr11 & 4294902015 | (v12 & 213 | 2) * 0x100;
        *((char *)p) = *((char *)p) + *((char *)&p);
        *((unsigned int *)p) = *((int *)p) | (unsigned int)p;
        *((char *)p) = *((char *)p) + *((char *)&p);
        ptr18->field_200000 = v15;
        *((char *)p) = *((char *)p) + *((char *)&p);
        *((char *)p) = *((char *)p) + *((char *)&p);
        *((char *)p) = *((char *)p) + *((char *)&p);
        *((unsigned int *)p) = *((int *)p) + (unsigned int)p;
        *((char *)p) = *((char *)p) + *((char *)&p);
        *((char *)p) = *((char *)p) + *((char *)&p);
        *((char *)p) = *((char *)p) + *((char *)&p);
        *((char *)p) = *((char *)p) + *((char *)&p);
        *((char *)p) = *((char *)p) + *((char *)&p);
        v16 = *((char *)&p) & *(0x7ff29114069);
        ptr8 = (void*)_INSERT(p, 0, *((char *)&p) & *(0x7ff29114069));
        v18 = *((char *)ptr8);
        *((char *)ptr8) = *((char *)ptr8) + v16;
        *((char *)ptr8) = *((char *)ptr8) - *((char *)((void*)&ptr8 + 1)) - ((char)(v18 + v16 <= v18 ? 1 : 0) & 1);
        *((char *)ptr8) = *((char *)ptr8) + v16;
        *((char *)ptr8) = *((char *)ptr8) + v16;
        *((char *)ptr8) = *((char *)ptr8) + v16;
        ptr5 = (unsigned int)ptr8 + *((int *)ptr8);
        *((char *)ptr5) = *((char *)ptr5) + *((char *)&ptr5);
        *((char *)&ptr5[0x200000]) = (char)ptr5[0x200000] & *((char *)((void*)&ptr5 + 1));
        *((char *)ptr5) = *((char *)ptr5) + *((char *)&ptr5);
        *((char *)ptr5) = *((char *)ptr5) + *((char *)&ptr5);
        *((char *)ptr5) = *((char *)ptr5) + *((char *)&ptr5);
        *((unsigned int *)ptr5) = *((int *)ptr5) + (unsigned int)ptr5;
        *((char *)ptr5) = *((char *)ptr5) + *((char *)&ptr5);
        *((char *)ptr5) = *((char *)ptr5) + *((char *)&ptr5);
        *((char *)ptr5) = *((char *)ptr5) + *((char *)&ptr5);
        *((char *)ptr5) = *((char *)ptr5) + *((char *)&ptr5);
        *((char *)ptr5) = *((char *)ptr5) + *((char *)&ptr5);
        ptr15 = (char *)_INSERT(ptr5, 0, *((char *)&ptr5) & *(0x7ff29134099));
        *(ptr15) = *(ptr15) + (*((char *)&ptr5) & *(0x7ff29134099));
        ptr16 = (char *)_INSERT(ptr15, 0, *((char *)0));
        *(ptr16) = *(ptr16) + *(NULL);
        v22 = *(0x200000);
        ptr9 = (void*)_INSERT((unsigned int)ptr16 + 0x64000000, 0, v22);
        *((char *)ptr9) = *((char *)ptr9) + v22;
        *((unsigned int *)ptr9) = *((int *)ptr9) + (unsigned int)ptr9;
        *((char *)ptr9) = *((char *)ptr9) + v22;
        *((char *)ptr9) = *((char *)ptr9) + v22;
        *((char *)ptr9) = *((char *)ptr9) + v22;
        *((char *)ptr9) = *((char *)ptr9) + v22;
        *((char *)ptr9) = *((char *)ptr9) + v22;
        v24 = *(0x7ff291240c9);
        v25 = v22 & *(0x7ff291240c9);
        addr = (void*)_INSERT(ptr9, 0, v22 & *(0x7ff291240c9));
        *((char *)addr) = *((char *)addr) + v25;
        ptr10[0x10000] = ptr10[0x10000] - *((char *)((void*)&addr + 1));
        *((char *)addr) = *((char *)addr) + v25;
        ptr10[0x40000] = ptr10[0x40000] + *((char *)((void*)&addr + 1));
        *((char *)addr) = *((char *)addr) + v25;
        *((char *)addr) = *((char *)addr) + v25;
        *((char *)addr) = *((char *)addr) + v25;
        *((char *)addr) = *((char *)addr) + v25;
        *((unsigned int *)addr) = *((int *)addr) + (unsigned int)addr;
        *((char *)addr) = *((char *)addr) + v25;
        *((char *)addr) = *((char *)addr) + v25;
        *((char *)addr) = *((char *)addr) + v25;
        *((char *)addr) = *((char *)addr) + v25;
        *((char *)addr) = *((char *)addr) + v25;
        v27 = v22 & v24 & *(0x7ff291240f9);
        ptr6 = (char [536871074])_INSERT(addr, 0, v25 & *(0x7ff291240f9));
        ptr6[0] = ptr6[0] + v27;
        ptr10[0x10000] = ptr10[0x10000] - *((char *)((void*)&addr + 1));
        ptr6[0] = ptr6[0] + v27;
        ptr10[0x80000] = 0;
        ptr6[536871073] = ptr6[536871073] + *((char *)((void*)&ptr10 + 1));
        ptr6[0] = ptr6[0] + v27;
        ptr6[0] = ptr6[0] + v27;
        ptr6[0] = ptr6[0] + v27;
        *(ptr10) = *(ptr10) + v27;
        ptr6[0] = ptr6[0] + v27;
        ptr6[0] = ptr6[0] + v27;
        ptr6[0] = ptr6[0] + v27;
        ptr6[0] = ptr6[0] + v27;
        ptr6[0] = ptr6[0] + v27;
        ptr14->field_0 = ptr14->field_0 + *((char *)((void*)&addr + 1));
        ptr3 = (unsigned int)ptr6 + 137619;
        *((char *)ptr3) = *((char *)ptr3) + *((char *)&ptr3);
        ptr10[0x10000] = ptr10[0x10000] - *((char *)((void*)&ptr3 + 1));
        *((char *)ptr3) = *((char *)ptr3) + *((char *)&ptr3);
        ptr14->field_80000 = ptr14->field_80000 | *((char *)((void*)&ptr3 + 1));
        *((char *)ptr3) = *((char *)ptr3) + *((char *)&ptr3);
        ptr14->field_200000 = ptr14->field_200000 ^ *((char *)((void*)&ptr3 + 1));
        *((char *)ptr3) = *((char *)ptr3) + *((char *)&ptr3);
        *((char *)ptr3) = *((char *)ptr3) + *((char *)&ptr3);
        *((char *)ptr3) = *((char *)ptr3) + *((char *)&ptr3);
        *((unsigned int *)ptr3) = *((int *)ptr3) + (unsigned int)ptr3;
        *((char *)ptr3) = *((char *)ptr3) + *((char *)&ptr3);
        *((char *)ptr3) = *((char *)ptr3) + *((char *)&ptr3);
        *((char *)ptr3) = *((char *)ptr3) + *((char *)&ptr3);
        *((char *)ptr3) = *((char *)ptr3) + *((char *)&ptr3);
        *((char *)ptr3) = *((char *)ptr3) + *((char *)&ptr3);
        ptr = (void*)_INSERT(ptr3, 0, *((char *)&ptr3) & *(0x7ff29124159));
        *((char *)ptr) = *((char *)ptr) + (*((char *)&ptr3) & *(0x7ff29124159));
        ptr10[0x10000] = ptr10[0x10000] - *((char *)((void*)&ptr3 + 1));
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        g_a2b8000000080000 = *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) & *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((unsigned int *)ptr) = *((int *)ptr) + (unsigned int)ptr;
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        v31 = *((char *)&ptr) & *(0x7ff29144189);
        ptr13 = (char *)_INSERT(ptr, 0, *((char *)&ptr) & *(0x7ff29144189));
        *(ptr13) = *(ptr13) + v31;
        g_a324000000010000 = ptr13;
        *(ptr13) = *(ptr13) + v31;
        *(ptr13) = *(ptr13) | v31;
        *(ptr13) = *(ptr13) + v31;
    }
    *((char *)*((int *)0x9dfc000000010000)) = *((char *)*((int *)0x9dfc000000010000)) + (char)*((int *)0x9dfc000000010000);
}


/* VA 0x7ff291087c8, RVA 0x87c8, CFG name sub_7ff291087c8; exports: [] */
typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

extern long long g_7ff29101278;
extern long long g_7ff291012a0;
extern struct_0 *g_7ff291012a8;
extern struct_0 *g_7ff291012b8;
extern int g_7ff2910caec;
extern unsigned int g_7ff2910d328;
extern char g_7ff2910d330;
extern void* g_7ff2910d338;
extern void* g_7ff2910d340;
extern struct_1 *g_7ff2910d350;

unsigned int sub_7ff291087c8(unsigned long a0, unsigned int flag, unsigned long a2)
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
        if (g_7ff2910caec > 0)
        {
            g_7ff2910caec = g_7ff2910caec - 1;
            while (InterlockedCompareExchange64(&g_7ff2910d330, 1, 0))
            {
                Sleep(1000);
            }
            if (g_7ff2910d328 != 2)
            {
                _amsg_exit(31);
                return 1;
            }
            if (g_7ff2910d340)
            {
                for (i = g_7ff2910d338 - 8; i >= g_7ff2910d340; i -= 8)
                {
                    if (*((long long *)i))
                        (*((long long *)i))();
                }
                free(g_7ff2910d340);
                g_7ff2910d338 = 0;
                g_7ff2910d340 = 0;
            }
            g_7ff2910d328 = 0;
            InterlockedExchange64(&g_7ff2910d330, 0);
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
                v4 = InterlockedCompareExchange64(&g_7ff2910d330, *((long long *)(*((long long *)(48 + v3)) + 8)), 0);
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
            if (g_7ff2910d328)
            {
                _amsg_exit(31);
            }
            else
            {
                cur = &g_7ff291012a8;
                g_7ff2910d328 = 1;
                v6 = 0;
                do
                {
                    if (v6)
                        return 0;
                    v7 = *(cur);
                    if (v7)
                        v6 = v7(v7);
                    cur += 1;
                } while (cur < &g_7ff291012b8);
                if (v6)
                    return 0;
                _initterm(&g_7ff29101278, &g_7ff291012a0);
                g_7ff2910d328 = 2;
            }
            if (!v2)
                InterlockedExchange64(&g_7ff2910d330, 0);
            if (g_7ff2910d350 && sub_7ff29108e8c(&g_7ff2910d350))
                g_7ff2910d350(a0, 2, a2);
            g_7ff2910caec = g_7ff2910caec + 1;
            return 1;
        }
        else
        {
            return 1;
        }
    }
}


/* VA 0x7ff29107114, RVA 0x7114, CFG name sub_7ff29107114; exports: [] */
extern unsigned long long g_7ff2910c110;

void sub_7ff29107114(void* p, long long a1, long long a2)
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

    v3 = g_7ff2910c110 ^ &v0;
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
        ptr = sub_7ff291065e8(v10);
        if (!ptr)
        {
            v12 = -2147024882;
        }
        else
        {
            memmove(ptr, &i, v9 * 2);
            v12 = 0;
        }
LABEL_7ff291072a2:
        if (v12 < 0)
            goto LABEL_7ff291072c2;
        if (ptr)
        {
            v13 = 0;
            if (v13 >= 0)
            {
                *((unsigned long *)p) = ptr;
                sub_7ff29108bf0(v3 ^ &v0);
                return;
            }
LABEL_7ff291072c2:
            if (ptr)
                free(ptr);
        }
        sub_7ff29108bf0(v3 ^ &v0);
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
            ptr = sub_7ff291065e8(v14);
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
                    goto LABEL_7ff2910728e;
                }
                *((unsigned short *)(ptr + idx * 2)) = 0;
LABEL_7ff2910728e:
            }
            if (v17 != -2147024774)
            {
                v12 = (v17 < 0 ? v17 : 0);
                goto LABEL_7ff291072a2;
            }
        }
    }
}


/* VA 0x7ff29104fc0, RVA 0x4fc0, CFG name sub_7ff29104fc0; exports: [] */
typedef struct struct_4 {
    char padding_0[24];
    struct struct_5 *field_18;
} struct_4;

typedef struct struct_6 {
    char padding_0[16];
    unsigned short *field_10;
    unsigned long long field_18;
} struct_6;

typedef struct struct_5 {
    struct struct_0 *field_0;
} struct_5;

typedef struct struct_0 {
    char padding_0[8];
    struct struct_1 *field_8;
    struct struct_2 *field_10;
    struct struct_3 *field_18;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_2 {
    unsigned long long field_0;
} struct_2;

typedef struct struct_3 {
    unsigned long long field_0;
} struct_3;

extern unsigned int g_7ff291021e0;
extern unsigned int g_7ff29102200;
extern void* g_7ff2910c310;

unsigned long long sub_7ff29104fc0(struct_4 *a0, struct_6 *a1, char *ptr)
{
    unsigned long long v8;  // rax
    unsigned long long v9;  // rax
    unsigned long long v10;  // rax
    unsigned int v11;  // edi
    unsigned int v12;  // eax
    long long v13;  // rbp
    void* v14;  // rcx
    unsigned long v15;  // r8
    unsigned long v16;  // rbp
    unsigned int v0;  // [bp-0x58], Other Possible Types: unsigned long long
    unsigned int v1;  // [bp-0x50]
    unsigned long long flag2;  // [bp-0x48]
    unsigned long long choice;  // [bp-0x40]
    HANDLE v4;  // [bp-0x38]
    long long v5;  // [bp-0x30]
    char flag3;  // [bp+0x8]
    unsigned int flag;  // [bp+0x20]

    flag3 = 0;
    v8 = a0->field_18->field_0->field_8(a0->field_18, &flag3);
    if ((unsigned int)v8 < 0)
        return v8;
    if (!flag3)
    {
LABEL_7ff29105000:
        *(ptr) = 0;
    }
    else
    {
        v9 = a0->field_18->field_0->field_10(a0->field_18, a1->field_18, &flag3);
        if ((unsigned int)v9 < 0)
            return v9;
        if (!flag3)
            goto LABEL_7ff29105000;
        flag = 0;
        v10 = a0->field_18->field_0->field_18(a0->field_18, a1->field_18, &flag);
        v11 = v10;
        if ((unsigned int)v10 < 0)
        {
            return v10;
        }
        else if (flag)
        {
            choice = 0;
            flag2 = 0;
            v1 = 0;
            v4 = 0xffffffffffffffff;
            v0 = 3;
            v12 = sub_7ff29107040(&v4, a1->field_10);
            if (v12 < 0)
            {
                if (v4 == 0xffffffffffffffff)
                    return v12;
                CloseHandle(v4);
                return v12;
            }
            else
            {
                v13 = 0;
                if (!GetFileSizeEx(v4, &v5))
                {
                    v11 = sub_7ff29108208();
                    v14 = g_7ff2910c310;
                    if (g_7ff2910c310 == &g_7ff2910c310 || !((char)g_7ff2910c310[28] & 1))
                        goto LABEL_7ff29105121;
                    sub_7ff291067a8((long long)g_7ff2910c310[16], 43, &g_7ff291021e0, v11);
                    v13 = 0;
                }
                else
                {
                    v11 = 0;
                    v13 = v5;
                }
                v14 = g_7ff2910c310;
LABEL_7ff29105121:
                if (v11 >= 0)
                {
                    v15 = flag;
                    v16 = v13 >> 10;
                    if (v16 > v15)
                    {
                        if (v14 != &g_7ff2910c310 && ((char)v14[28] & 2))
                        {
                            v1 = v15;
                            v0 = v16;
                            sub_7ff29104c44((long long)v14[16], 10, &g_7ff29102200, a1->field_10);
                        }
                        *(ptr) = 0;
                        if (v4 != 0xffffffffffffffff)
                            CloseHandle(v4);
                    }
                    else
                    {
                        if (v4 != 0xffffffffffffffff)
                            CloseHandle(v4);
                        *(ptr) = 1;
                        return v11;
                    }
                }
                else if (v4 != 0xffffffffffffffff)
                {
                    CloseHandle(v4);
                    return v11;
                }
                else
                {
                    return v11;
                }
            }
        }
        else
        {
            *(ptr) = 1;
            return v11;
        }
    }
    return 0;
}


/* VA 0x7ff29104cf8, RVA 0x4cf8, CFG name sub_7ff29104cf8; exports: [] */
typedef struct struct_8 {
    char padding_0[16];
    struct struct_1 *field_10;
    struct struct_6 *field_18;
    unsigned long long field_20;
} struct_8;

typedef struct struct_1 {
    struct struct_2 *field_0;
    unsigned int field_8;
    char padding_c[4];
    struct struct_3 *field_10;
    struct struct_4 *field_18;
} struct_1;

typedef struct struct_10 {
    struct struct_11 *field_0;
    unsigned int field_8;
    char padding_c[4];
    struct struct_12 *field_10;
    struct struct_13 *field_18;
} struct_10;

typedef struct struct_6 {
    struct struct_7 *field_0;
    unsigned int field_8;
} struct_6;

typedef struct struct_2 {
    struct struct_0 *field_0;
} struct_2;

typedef struct struct_3 {
    unsigned long long field_0;
} struct_3;

typedef struct struct_4 {
    unsigned long long field_0;
} struct_4;

typedef struct struct_11 {
    struct struct_9 *field_0;
} struct_11;

typedef struct struct_12 {
    unsigned long long field_0;
} struct_12;

typedef struct struct_13 {
    unsigned long long field_0;
} struct_13;

typedef struct struct_7 {
    struct struct_5 *field_0;
} struct_7;

typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

typedef struct struct_9 {
    unsigned long long field_0;
} struct_9;

typedef struct struct_5 {
    unsigned long long field_0;
} struct_5;

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

typedef struct CRITICAL_SECTION {
    struct CRITICAL_SECTION_DEBUG *DebugInfo;
    int LockCount;
    int RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    UIntPtr SpinCount;
} CRITICAL_SECTION;

extern struct_10 *g_7ff2910d1f8;
extern CRITICAL_SECTION g_7ff2910d260;

unsigned long long sub_7ff29104cf8(struct_8 *ptr)
{
    struct_1 *v1;  // rcx
    unsigned long long flag;  // rdx
    struct_1 *v11;  // rdi
    unsigned long long flag2;  // rdx
    unsigned long long v13;  // rax
    struct_1 *i;  // rdi
    struct_1 *v4;  // rbx
    unsigned int v5;  // ebp
    struct_1 *v6;  // rax
    struct_1 *v7;  // rsi
    struct_1 *v8;  // rcx
    unsigned long long choice;  // rdx
    struct_6 *v10;  // rcx
    struct_1 *flag3;  // [bp+0x8]

    v1 = ptr->field_10;
    if (v1)
    {
        InterlockedExchangeAdd(&v1->field_8, 4294967295);
        if (v1->field_8 + 4294967295 <= 0 && v1)
        {
            flag = 1;
            v1->field_0->field_0();
        }
        ptr->field_10 = NULL;
    }
    i = NULL;
    do
    {
        v4 = NULL;
        if (g_7ff2910d1f8)
            continue;
        flag3 = NULL;
        v5 = sub_7ff29105aa0(&flag3);
        if (v5 < 0)
        {
            v6 = flag3;
            if (!v6 || (InterlockedExchangeAdd(v6 + 8, 4294967295), v6 > NULL))
                goto LABEL_7ff29104dba;
            goto LABEL_7ff29104d7f;
        }
        else
        {
            v7 = flag3;
            v5 = sub_7ff29105734(v7);
            if (v5 < 0)
            {
                if (!v7 || (InterlockedExchangeAdd(v7 + 8, 4294967295), v7 > NULL))
                    goto LABEL_7ff29104dba;
LABEL_7ff29104d7f:
                flag3->field_0->field_0(flag3, 1);
                goto LABEL_7ff29104dba;
            }
            else
            {
                v4 = v7;
                v5 = 0;
LABEL_7ff29104dba:
                if (v5 < 0)
                {
                    if (v4)
                    {
                        InterlockedExchangeAdd(&v4->field_8, 4294967295);
                        if (v4->field_8 + 4294967295 <= 0)
                            v4->field_0->field_0(v4, 1);
                    }
                    if (i)
                    {
                        InterlockedExchangeAdd(&i->field_8, 4294967295);
                        if (i->field_8 + 4294967295 <= 0)
                        {
                            i->field_0->field_0(i, 1);
                            goto LABEL_7ff29104e50;
                        }
                    }
                }
            }
        }
        EnterCriticalSection(&g_7ff2910d260.DebugInfo);
        i = g_7ff2910d1f8;
        if (!i)
        {
            g_7ff2910d1f8 = v4;
            i = v4;
            v4 = i;
        }
        else
        {
            InterlockedExchangeAdd(&i->field_8, 1);
            v8 = i;
            if (v8)
            {
                InterlockedExchangeAdd(&v8->field_8, 4294967295);
                if (v8->field_8 + 4294967295 <= 0)
                {
                    choice = 1;
                    v8->field_0->field_0();
                }
            }
        }
        LeaveCriticalSection(&g_7ff2910d260.DebugInfo);
        if (v4)
        {
            InterlockedExchangeAdd(&v4->field_8, 4294967295);
            if (v4->field_8 + 4294967295 <= 0)
                v4->field_0->field_0(v4, 1);
        }
    } while (!i);
    ptr->field_10 = i;
    v5 = 0;
LABEL_7ff29104e50:
    if (v5 < 0)
        return v5;
    v10 = ptr->field_18;
    v11 = ptr->field_10;
    if (v10)
    {
        InterlockedExchangeAdd(&v10->field_8, 4294967295);
        if (v10->field_8 + 4294967295 <= 0 && v10)
        {
            flag2 = 1;
            v10->field_0->field_0();
        }
        ptr->field_18 = NULL;
    }
    v13 = sub_7ff29105b14(&ptr->field_18, v11);
    if ((unsigned int)v13 < 0)
        return v13;
    if (!ptr->field_20)
        return ptr->field_10->field_10(0, &ptr->field_20);
    g_7ff2910d1f8->field_18(ptr->field_20);
    ptr->field_20 = 0;
    return ptr->field_10->field_10(0, &ptr->field_20);
}


/* VA 0x7ff291051c0, RVA 0x51c0, CFG name sub_7ff291051c0; exports: [] */
typedef struct struct_0 {
    char padding_0[4];
    char field_4;
    char padding_5[27];
    unsigned long long field_20;
} struct_0;

typedef struct struct_6 {
    char padding_0[16];
    struct struct_1 *field_10;
    char padding_18[8];
    unsigned long long field_20;
} struct_6;

typedef struct struct_9 {
    char padding_0[40];
    unsigned int field_28;
} struct_9;

typedef struct struct_1 {
    char padding_0[40];
    struct struct_2 *field_28;
    struct struct_3 *field_30;
    struct struct_4 *field_38;
    struct struct_5 *field_40;
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

typedef struct struct_8 {
    unsigned long long field_0;
} struct_8;

typedef struct struct_7 {
    char padding_0[24];
    struct struct_8 *field_18;
} struct_7;

extern unsigned long long g_7ff2910c110;
extern struct_7 *g_7ff2910d1f8;

void sub_7ff291051c0(struct_6 *a0, struct_0 *addr, unsigned int *p)
{
    unsigned long ptr;  // rbx
    unsigned long long v23;  // rcx
    unsigned long v24;  // rax
    char v0;  // [bp-0x158]
    unsigned long long flag10;  // [bp-0x138]
    char *v2;  // [bp-0x130]
    unsigned long flag9;  // [bp-0x128]
    unsigned long flag5;  // [bp-0x120]
    unsigned long flag3;  // [bp-0x118]
    struct_9 *index;  // [bp-0x110]
    unsigned int choice;  // [bp-0x108]
    char *v8;  // [bp-0x100]
    char v9;  // [bp-0xf8], Other Possible Types: unsigned long long
    unsigned long v10;  // [bp-0xf0]
    unsigned int flag;  // [bp-0xe8]
    unsigned long long flag2;  // [bp-0xe0]
    unsigned long long v13;  // [bp-0xd8]
    unsigned long long flag4;  // [bp-0xd0]
    unsigned long long flag8;  // [bp-0xc8]
    unsigned long long flag6;  // [bp-0xc0]
    char v17;  // [bp-0xb8]
    unsigned int v18;  // [bp-0x90]
    unsigned int v19;  // [bp-0x8c]
    unsigned long long v20;  // [bp-0x28]

    v13 = 18446744073709551614;
    v20 = g_7ff2910c110 ^ &v0;
    flag2 = 0;
    ptr = 0;
    flag3 = 0;
    v23 = L"file";
    v24 = *((long long *)&addr->padding_5[11]);
    if ((addr->field_4 & 8) && addr->field_20)
    {
        if ((int)sub_7ff2910730c(&flag3, L"%s|%s", v24, addr->field_20) < 0)
        {
            if (flag3)
                free(flag3);
            sub_7ff29108bf0(v20 ^ &v0);
            return;
        }
        v23 = L"webfile";
        ptr = flag3;
        v24 = ptr;
    }
    flag = 0;
    choice = 1;
    v8 = &v9;
    v9 = v23;
    v10 = v24;
    flag8 = 0;
    flag9 = 0;
    v2 = &flag9;
    flag10 = 0;
    if (a0->field_10->field_28(a0->field_20, 3) < 0)
    {
        if (flag9)
            g_7ff2910d1f8->field_18(flag9, g_7ff2910d1f8);
        if (ptr)
            free(ptr);
        sub_7ff29108bf0(v20 ^ &v0);
        return;
    }
    else if (a0->field_10->field_30(flag9, &v17) < 0)
    {
        if (flag9)
            g_7ff2910d1f8->field_18(flag9, g_7ff2910d1f8);
        if (ptr)
            free(ptr);
        sub_7ff29108bf0(v20 ^ &v0);
        return;
    }
    else
    {
        if (!v18 && !v19)
        {
            if (flag9)
                g_7ff2910d1f8->field_18(flag9);
            if (ptr)
                free(ptr);
            sub_7ff29108bf0(v20 ^ &v0);
            return;
        }
        flag4 = 0;
        flag5 = 0;
        if (a0->field_10->field_38(flag9, 0, 0, &flag5) < 0)
        {
            if (flag5)
                g_7ff2910d1f8->field_18(flag5, g_7ff2910d1f8);
            if (flag9)
                g_7ff2910d1f8->field_18(flag9);
            if (ptr)
                free(ptr);
            sub_7ff29108bf0(v20 ^ &v0);
            return;
        }
        else
        {
            flag6 = 0;
            index = NULL;
            if (a0->field_10->field_40(flag5, &index) < 0)
            {
                if (index)
                    sub_7ff29104b60(index);
                if (flag5)
                    g_7ff2910d1f8->field_18(flag5);
                if (flag9)
                    g_7ff2910d1f8->field_18(flag9);
                if (ptr)
                    free(ptr);
                sub_7ff29108bf0(v20 ^ &v0);
                return;
            }
            else
            {
                *(p) = index->field_28;
                sub_7ff29104b60(index);
                if (flag5)
                    g_7ff2910d1f8->field_18(flag5);
                if (flag9)
                    g_7ff2910d1f8->field_18(flag9);
                if (ptr)
                    free(ptr);
                sub_7ff29108bf0(v20 ^ &v0);
                return;
            }
        }
    }
}


/* VA 0x7ff29105734, RVA 0x5734, CFG name sub_7ff29105734; exports: [] */
typedef struct struct_0 {
    char padding_0[16];
    void* field_10;
    void* field_18;
    void* field_20;
    void* field_28;
    void* field_30;
    void* field_38;
    void* field_40;
    void* field_48;
    void* field_50;
    void* field_58;
    HMODULE field_60;
} struct_0;

extern HMODULE g_7ff2910d078;

unsigned int sub_7ff29105734(struct_0 *ptr, unsigned long a1, unsigned long a2, unsigned long long a3)
{
    unsigned int v2;  // eax
    unsigned long p;  // rbx
    void* v13;  // rax
    void* v15;  // rax
    void* v17;  // rax
    void* v19;  // rax
    void* v21;  // rax
    unsigned short *ptr3;  // rax
    void* v23;  // rax
    void* v25;  // rax
    unsigned int v5;  // eax
    unsigned int v6;  // esi
    void* v7;  // rax
    void* v9;  // rax
    void* v11;  // rax
    unsigned long addr;  // [bp+0x10]

    addr = 0;
    v2 = (unsigned long long)sub_7ff29106ed4(*((unsigned int *)&&addr), g_7ff2910d078);
    if (v2 < 0)
    {
        if (!addr)
            return v2;
        free(addr);
        return v2;
    }
    else
    {
        p = addr;
        ptr3 = wcsrchr(p, 92);
        if (!ptr3)
        {
            if (!p)
                return 2147942523;
            free(p);
            return 2147942523;
        }
        else
        {
            *(ptr3) = 0;
            addr = 0;
            v5 = sub_7ff2910730c(&addr, L"%s\\MPCLIENT.DLL", p, a3);
            if (v5 < 0)
            {
                if (addr)
                    free(addr);
                if (!p)
                    return v5;
                free(p);
                return v5;
            }
            else
            {
                if (ptr->field_60)
                {
                    FreeLibrary(ptr->field_60);
                    ptr->field_60 = NULL;
                }
                v6 = sub_7ff29106cb4(&ptr->field_60, addr);
                if (v6 >= 0)
                {
                    v7 = GetProcAddress(ptr->field_60, "MpManagerOpen");
                    ptr->field_10 = v7;
                    v6 = (!v7 ? (unsigned int)sub_7ff29106d5c("MpManagerOpen") : 0);
                    if (v6 >= 0)
                    {
                        v9 = GetProcAddress(ptr->field_60, "MpHandleClose");
                        ptr->field_18 = v9;
                        v6 = (!v9 ? (unsigned int)sub_7ff29106d5c("MpHandleClose") : 0);
                        if (v6 >= 0)
                        {
                            v11 = GetProcAddress(ptr->field_60, "MpFreeMemory");
                            ptr->field_20 = v11;
                            v6 = (!v11 ? (unsigned int)sub_7ff29106d5c("MpFreeMemory") : 0);
                            if (v6 >= 0)
                            {
                                v13 = GetProcAddress(ptr->field_60, "MpScanStart");
                                ptr->field_28 = v13;
                                v6 = (!v13 ? (unsigned int)sub_7ff29106d5c("MpScanStart") : 0);
                                if (v6 >= 0)
                                {
                                    v15 = GetProcAddress(ptr->field_60, "MpScanResult");
                                    ptr->field_30 = v15;
                                    v6 = (!v15 ? (unsigned int)sub_7ff29106d5c("MpScanResult") : 0);
                                    if (v6 >= 0)
                                    {
                                        v17 = GetProcAddress(ptr->field_60, "MpThreatOpen");
                                        ptr->field_38 = v17;
                                        v6 = (!v17 ? (unsigned int)sub_7ff29106d5c("MpThreatOpen") : 0);
                                        if (v6 >= 0)
                                        {
                                            v19 = GetProcAddress(ptr->field_60, "MpThreatEnumerate");
                                            ptr->field_40 = v19;
                                            v6 = (!v19 ? (unsigned int)sub_7ff29106d5c("MpThreatEnumerate") : 0);
                                            if (v6 >= 0)
                                            {
                                                v21 = GetProcAddress(ptr->field_60, "MpConfigOpen");
                                                ptr->field_48 = v21;
                                                v6 = (!v21 ? (unsigned int)sub_7ff29106d5c("MpConfigOpen") : 0);
                                                if (v6 >= 0)
                                                {
                                                    v23 = GetProcAddress(ptr->field_60, "MpConfigGetValue");
                                                    ptr->field_50 = v23;
                                                    v6 = (!v23 ? (unsigned int)sub_7ff29106d5c("MpConfigGetValue") : 0);
                                                    if (v6 >= 0)
                                                    {
                                                        v25 = GetProcAddress(ptr->field_60, "MpConfigClose");
                                                        ptr->field_58 = v25;
                                                        v6 = (!v25 ? (unsigned int)sub_7ff29106d5c("MpConfigClose") : 0);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (addr)
                    free(addr);
                if (!p)
                    return v6;
                free(p);
                return v6;
            }
        }
    }
}


/* VA 0x7ff29105cbc, RVA 0x5cbc, CFG name sub_7ff29105cbc; exports: [] */
typedef struct struct_2 {
    char padding_0[112];
    struct struct_0 *field_70;
} struct_2;

typedef struct struct_0 {
    char padding_0[72];
    struct struct_1 *field_48;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_5 {
    unsigned long long field_0;
} struct_5;

typedef struct struct_4 {
    unsigned long long field_0;
} struct_4;

typedef struct struct_3 {
    char padding_0[80];
    struct struct_4 *field_50;
    struct struct_5 *field_58;
} struct_3;

extern struct_3 *g_7ff2910d1f8;

unsigned int sub_7ff29105cbc(struct_2 *a0, char *ptr)
{
    unsigned int v11;  // eax
    unsigned int v12;  // eax
    char v13;  // sil
    unsigned long long v14;  // r13
    void* v15;  // rbp
    unsigned int v16;  // eax
    unsigned int v17;  // eax
    unsigned long long v18;  // rdi
    unsigned int v19;  // ebx
    unsigned long v0;  // [bp-0x88]
    unsigned int flag;  // [bp-0x84]
    unsigned int v2;  // [bp-0x80]
    unsigned long long v3;  // [bp-0x78]
    unsigned long long v4;  // [bp-0x70]
    unsigned long long flag3;  // [bp-0x68]
    int v6;  // [bp-0x60], Other Possible Types: unsigned long
    unsigned long long v7;  // [bp-0x58]
    unsigned int v8;  // [bp+0x8]
    unsigned int choice;  // [bp+0x18]
    unsigned int flag2;  // [bp+0x20]

    v4 = 18446744073709551614;
    flag3 = 0;
    v3 = 0;
    v11 = a0->field_70->field_48(".", &v3);
    if (v11 < 0)
    {
        if (!v3)
            return v11;
        g_7ff2910d1f8->field_58(v3, g_7ff2910d1f8);
        return v11;
    }
    else
    {
        flag2 = 0;
        v8 = 0;
        *((unsigned int *)&v0) = 4;
        v12 = g_7ff2910d1f8->field_50(v3, L"ProductFeature", &flag2, &v0, &v8, 0, v0);
        if (v12 >= 0)
        {
            if (flag2 != 1 && flag2)
            {
                v12 = 2147944029;
            }
            else
            {
                if (!(unsigned int)v0)
                {
                    v8 = 0;
                    v8 = 0;
                }
                if (v8 > 2)
                {
                    if (!v3)
                        return 2147942413;
                    g_7ff2910d1f8->field_58(v3);
                    return 2147942413;
                }
                else
                {
                    *((unsigned int *)&v6) = 1;
                    *((wchar **)&(&v6)[8]) = L"DisableAntiVirus";
                    *((unsigned int *)&(&v6)[16]) = 2;
                    *((wchar **)&(&v6)[24]) = L"DisableAntiSpyware";
                    v13 = 1;
                    v14 = 0;
                    v15 = &v6 - 8;
                    do
                    {
                        if (v8 && (int)v15[8] != v8)
                            continue;
                        flag = 0;
                        choice = 0;
                        v2 = 4;
                        v16 = g_7ff2910d1f8->field_50(v3, *((long long *)v15), &flag, &v2, &choice, 0);
                        if (v16 < 0)
                        {
LABEL_7ff29106029:
                            if (!v3)
                                return v16;
                            g_7ff2910d1f8->field_58(v3);
                            return v16;
                        }
                        else if (flag == 1 || !flag)
                        {
                            choice &= -(0 < v2);
                            if (v13 && choice)
                                v13 = 1;
                            else
                                v13 = 0;
                        }
                        else
                        {
                            v16 = 2147944029;
                            goto LABEL_7ff29106029;
                        }
                    } while ((v14 += 1, v15 += 16, v14 < 2));
                    if (v13)
                    {
                        *(ptr) = 0;
                        if (!v3)
                            return 0;
                        g_7ff2910d1f8->field_58(v3);
                        return 0;
                    }
                    else
                    {
                        v6 = L"DisableRealtimeMonitoring";
                        v7 = L"DisableIOAVProtection";
                        if (v3)
                        {
                            g_7ff2910d1f8->field_58(v3);
                            v3 = 0;
                        }
                        v17 = a0->field_70->field_48(L"Real-Time Protection", &v3);
                        if (v17 >= 0)
                        {
                            v18 = 0;
                            while (true)
                            {
                                choice = 0;
                                v8 = 0;
                                flag2 = 4;
                                v19 = g_7ff2910d1f8->field_50(v3, (&v6)[v18], &choice, &flag2, &v8, 0);
                                if (v19 >= 0)
                                {
                                    if (choice == 1 || !choice)
                                    {
                                        v8 &= -(0 < flag2);
                                        if (!v8)
                                        {
                                            v18 += 1;
                                            if (v18 >= 2)
                                            {
                                                *(ptr) = 1;
                                                if (!v3)
                                                    return v19;
                                                g_7ff2910d1f8->field_58(v3);
                                                return v19;
                                            }
                                        }
                                        else
                                        {
                                            *(ptr) = 0;
                                            if (!v3)
                                                return 0;
                                            g_7ff2910d1f8->field_58(v3);
                                            return 0;
                                        }
                                    }
                                    else
                                    {
                                        v19 = 2147944029;
                                        goto LABEL_7ff29106011;
                                    }
                                }
                                else
                                {
LABEL_7ff29106011:
                                    if (!v3)
                                        return v19;
                                    g_7ff2910d1f8->field_58(v3);
                                    return v19;
                                }
                            }
                        }
                        else if (v3)
                        {
                            g_7ff2910d1f8->field_58(v3, g_7ff2910d1f8);
                        }
                    }
                    return v17;
                }
            }
        }
        if (!v3)
            return v12;
        g_7ff2910d1f8->field_58(v3);
        return v12;
    }
}


