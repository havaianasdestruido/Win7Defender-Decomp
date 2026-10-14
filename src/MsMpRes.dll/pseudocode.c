/* AUTOMATED ANGR PSEUDOCODE, NOT ORIGINAL SOURCE; NOT A BUILD TARGET.
 * Types, signatures, locals, calling conventions and control flow are inferred, unverified.
 * Input SHA256: 87116782261671ab9790228dcd67a641f09464dcf81b9fe6a07b4a0e7cc57d14; addresses use preferred image base.
 * Per-function omissions and errors: analysis/report/modules/MsMpRes.dll/function-coverage.json
 */

/* VA 0x7ff3a081640, RVA 0x1640, CFG name GetMsMpResModuleHandle; exports: ['GetMsMpResModuleHandle'] */
extern unsigned long long g_7ff3a0836e8;

long long GetMsMpResModuleHandle(void)
{
    return g_7ff3a0836e8;
}


/* VA 0x7ff3a081a58, RVA 0x1a58, CFG name _start; exports: [] */
void _start(long long a0, unsigned int flag, long long a2)
{
    if (flag == 1)
        _security_init_cookie();
    sub_7ff3a081864(a0, flag, a2);
    return;
}


/* VA 0x7ff3a081bb6, RVA 0x1bb6, CFG name sub_7ff3a081bb6; exports: [] */
int sub_7ff3a081bb6(void)
{
}


/* VA 0x7ff3a082155, RVA 0x2155, CFG name sub_7ff3a082155; exports: [] */
char sub_7ff3a082155(unsigned long a0, char *ptr)
{
    char v2;  // al
    unsigned long v0;  // [bp-0x8]

    v0 = v2 ^ *(ptr);
}


/* VA 0x7ff3a081a34, RVA 0x1a34, CFG name sub_7ff3a081a34; exports: [] */
void sub_7ff3a081a34(void)
{
    unsigned int flag;  // [bp+0x20]

    flag = 0;
}


/* VA 0x7ff3a081ad6, RVA 0x1ad6, CFG name _XcptFilter; exports: [] */
// attributes: PLT stub
int _XcptFilter(void)
{
    ::msvcrt.dll::_XcptFilter();
    return;
}


/* VA 0x7ff3a081bc4, RVA 0x1bc4, CFG name _initterm; exports: [] */
// attributes: PLT stub
int _initterm(void)
{
    ::msvcrt.dll::_initterm();
    return;
}


/* VA 0x7ff3a081bd0, RVA 0x1bd0, CFG name _amsg_exit; exports: [] */
// attributes: PLT stub
int _amsg_exit(void)
{
    ::msvcrt.dll::_amsg_exit();
    return;
}


/* VA 0x7ff3a081bdc, RVA 0x1bdc, CFG name __C_specific_handler; exports: [] */
// attributes: PLT stub
int __C_specific_handler(void)
{
    ::msvcrt.dll::__C_specific_handler();
    return;
}


/* VA 0x7ff3a081dcc, RVA 0x1dcc, CFG name RtlVirtualUnwind; exports: [] */
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


/* VA 0x7ff3a081dd8, RVA 0x1dd8, CFG name RtlLookupFunctionEntry; exports: [] */
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


/* VA 0x7ff3a081de4, RVA 0x1de4, CFG name memcpy; exports: [] */
// attributes: PLT stub
int memcpy(void)
{
    ::msvcrt.dll::memcpy();
    return;
}


/* VA 0x7ff3a0811d7, RVA 0x11d7, CFG name sub_7ff3a0811d7; exports: [] */
void sub_7ff3a0811d7(unsigned long a0)
{
    [D] Unsupported jumpkind Ijk_SigTRAP at address 8792771662295()
}


/* VA 0x7ff3a081aa6, RVA 0x1aa6, CFG name sub_7ff3a081aa6; exports: [] */
void sub_7ff3a081aa6(unsigned long a0)
{
    sub_7ff3a081ab0();
    return;
}


/* VA 0x7ff3a081970, RVA 0x1970, CFG name sub_7ff3a081970; exports: [] */
void sub_7ff3a081970(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
}


/* VA 0x7ff3a081992, RVA 0x1992, CFG name sub_7ff3a081992; exports: [] */
void sub_7ff3a081992(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
}


/* VA 0x7ff3a0819bd, RVA 0x19bd, CFG name sub_7ff3a0819bd; exports: [] */
void sub_7ff3a0819bd(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
}


/* VA 0x7ff3a0818d9, RVA 0x18d9, CFG name sub_7ff3a0818d9; exports: [] */
void sub_7ff3a0818d9(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
    unsigned int flag;  // [bp+0x20]

    flag = 0;
}


/* VA 0x7ff3a08190c, RVA 0x190c, CFG name sub_7ff3a08190c; exports: [] */
void sub_7ff3a08190c(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
    unsigned int flag;  // [bp+0x20]

    flag = 0;
}


/* VA 0x7ff3a081943, RVA 0x1943, CFG name sub_7ff3a081943; exports: [] */
void sub_7ff3a081943(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
    unsigned int flag;  // [bp+0x20]

    flag = 0;
}


/* VA 0x7ff3a0819f3, RVA 0x19f3, CFG name sub_7ff3a0819f3; exports: [] */
void sub_7ff3a0819f3(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
    unsigned int flag;  // [bp+0x20]

    flag = 0;
}


/* VA 0x7ff3a081208, RVA 0x1208, CFG name sub_7ff3a081208; exports: [] */
long long sub_7ff3a081208(unsigned long a0, unsigned long a1, unsigned long a2, unsigned short a3)
{
    unsigned long long v7;  // rbx
    unsigned long long v8;  // rsi
    unsigned long long v9;  // rdi
    unsigned long long v10;  // r12
    unsigned long long v0;  // [bp-0x18]
    unsigned long long v1;  // [bp-0x10]
    unsigned long long v2;  // [bp-0x8]
    unsigned long long v3;  // [bp+0x8]
    unsigned long v4;  // [bp+0x10]
    unsigned short v5;  // [bp+0x20]

    v3 = v7;
    v4 = vvar_6{r56|8b};
    v5 = a3;
    v2 = v8;
    v1 = v9;
    v0 = v10;
}


/* VA 0x7ff3a0820f0, RVA 0x20f0, CFG name sub_7ff3a0820f0; exports: [] */
extern unsigned int g_7ff3a083110;

void sub_7ff3a0820f0(unsigned long a0, unsigned long a1)
{
    g_7ff3a083110 = 4294967295;
    return;
}


/* VA 0x7ff3a081338, RVA 0x1338, CFG name sub_7ff3a081338; exports: [] */
long long sub_7ff3a081338(unsigned int a0, unsigned int a1, unsigned int a2, unsigned short a3)
{
    char *v0;  // [bp-0x18]
    unsigned short v2;  // [bp+0x20]
    char v3;  // [bp+0x28]

    v2 = a3;
    v0 = &v3;
    return sub_7ff3a081208(a0, a1, a2, a3);
}


/* VA 0x7ff3a081ab0, RVA 0x1ab0, CFG name sub_7ff3a081ab0; exports: [] */
extern char g_7ff3a083118;

void sub_7ff3a081ab0(unsigned long a0)
{
    if (a0 != *((long long *)&g_7ff3a083118))
    {
        sub_7ff3a081ca4();
        return;
    }
    else if (!(unsigned short)(__ROL__(a0, 16)))
    {
        return;
    }
    else
    {
        sub_7ff3a081ca4();
        return;
    }
}


/* VA 0x7ff3a08210f, RVA 0x210f, CFG name sub_7ff3a08210f; exports: [] */
typedef struct struct_0 {
    unsigned int field_0;
} struct_0;

long long sub_7ff3a08210f(struct_0 **a0, unsigned long a1)
{
    return *(a0)->field_0 == 3221225477;
}


/* VA 0x7ff3a082141, RVA 0x2141, CFG name sub_7ff3a082141; exports: [] */
extern char g_7ff6209395f;

void sub_7ff3a082141(void* a0, char *ptr3, unsigned long a2, unsigned long a3, char a4)
{
    char v1;  // al
    char *addr;  // rax
    char v11;  // bl
    char *ptr4;  // rax
    char *ptr;  // rsi
    char v4;  // 4104
    char v5;  // dl
    void* p;  // rcx
    unsigned long v7;  // cc_ndep
    unsigned long v8;  // 4111
    char v9;  // 4104
    unsigned long v10;  // 4125

    addr = v1 ^ 10;
    *(ptr) = *(ptr) + *((char *)&ptr3);
    v4 = *(ptr3);
    v5 = *((char *)&ptr3) ^ v4;
    p = a0 - 1;
    if (a0 - 1 & (*((char *)&ptr3) ^ v4))
    {
        v8 = _ccall(17, (unsigned long long)(*((char *)(void*)&ptr3) ^ v4), 0, v7);
        g_7ff6209395f = g_7ff6209395f - *((char *)&addr) - ((char)v8 & 1);
        v9 = *((char *)p);
        *((char *)p) = *((char *)p) + v5;
        v10 = _ccall(0, 1, (unsigned long long)v9, (unsigned long long)v5, v8 & 1);
        if (!((char)v10))
            goto LABEL_0x7ff3a082163;
        *(addr) = *(addr) - *((char *)&addr) - ((char)(*((char *)&p) + v11 <= *((char *)&p) ? 1 : 0) & 1);
        ptr4 = _INSERT(addr, 0, *((char *)&addr) + v5) - 0x18d90000 - ((unsigned int)(*((char *)&addr) + v5 <= *((char *)&addr) ? 1 : 0) & 1);
        *(ptr4) = *(ptr4) + *((char *)&ptr4);
    }
    *(ptr) = *(ptr) >> 1 | *(ptr) * 128;
    *(addr + 0x2 * ptr) = *(addr + 0x2 * ptr) >> 3 | *(addr + 0x2 * ptr) * 32;
}


/* VA 0x7ff3a081af0, RVA 0x1af0, CFG name sub_7ff3a081af0; exports: [] */
unsigned int sub_7ff3a081af0(void* ptr)
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


/* VA 0x7ff3a081650, RVA 0x1650, CFG name sub_7ff3a081650; exports: [] */
extern unsigned long long g_7ff3a083700;
extern unsigned long long g_7ff3a083708;

unsigned int sub_7ff3a081650(void)
{
    unsigned long long *ptr;  // rax

    ptr = malloc(0x100);
    g_7ff3a083708 = ptr;
    g_7ff3a083700 = ptr;
    if (ptr)
    {
        *(ptr) = 0;
        return 0;
    }
    return 1;
}


/* VA 0x7ff3a08218c, RVA 0x218c, CFG name sub_7ff3a08218c; exports: [] */
typedef struct struct_0 {
    char padding_0[1879048217];
    char field_70000019;
} struct_0;

void sub_7ff3a08218c(void* p, struct_0 *ptr4, unsigned int *addr, unsigned long a3, char a4)
{
    char v1;  // al
    void* ptr;  // rax
    unsigned long v11;  // 4131
    char v12;  // 4098
    char v13;  // 4098
    unsigned int v3;  // ebx
    char v4;  // 4109
    char v5;  // 4119
    char v6;  // 4133
    unsigned long v7;  // 4187
    char v8;  // 4098
    char *ptr3;  // rdi
    char v10;  // 4108

    ptr = v1 | 25;
    *((char *)ptr) = *((char *)ptr) + (v1 | 25);
    *((unsigned int *)p) = *((int *)p) - v3;
    v4 = *((char *)ptr);
    *((char *)ptr) = *((char *)ptr) + (v1 | 25);
    *(addr) = *(addr) - (unsigned int)ptr - ((unsigned int)(v4 + (v1 | 25) <= v4 ? 1 : 0) & 1);
    v5 = (char)ptr[1124073502];
    *((char *)&ptr[1124073502]) = (char)ptr[1124073502] + *((char *)((void*)&ptr4 + 1));
    *((unsigned int *)ptr) = *((int *)ptr) - (unsigned int)ptr - ((unsigned int)(v5 + *((char *)((void*)&ptr4 + 1)) <= v5 ? 1 : 0) & 1);
    *((char *)&p[25]) = (char)p[25] + *((char *)((void*)&ptr + 1));
    v6 = *((char *)ptr);
    *((char *)ptr) = *((char *)ptr) + (v1 | 25);
    v7 = _ccall(0, 1, (unsigned long long)v6, (unsigned long long)(v1 | 25), (v5 + *((char *)((void*)&ptr4 + 1)) <= v5 ? 1 : 0) & 1);
    if (!((char)v7))
    {
        v8 = *((char *)ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        *(ptr3) = *(ptr3) + (char)v3 + ((char)(v8 + *((char *)&ptr) <= v8 ? 1 : 0) & 1);
        v10 = *((char *)ptr);
        *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
        v11 = _ccall(0, 1, (unsigned long long)v10, (unsigned long long)*((char *)(void*)&ptr), (v8 + *((char *)(void*)&ptr) <= v8 ? 1 : 0) & 1);
        if (!((char)v11))
        {
            v12 = *((char *)ptr);
            *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
            *((unsigned int *)p) = *((int *)p) - ((unsigned int)(v12 + *((char *)&ptr) <= v12 ? 1 : 0) & 1);
            ptr4->field_70000019 = ptr4->field_70000019 + *((char *)&ptr4);
        }
    }
    else
    {
        v13 = (char)p[1124073447];
        *((char *)&p[1124073447]) = (char)p[1124073447] + *((char *)((void*)&ptr4 + 1));
        *((unsigned int *)ptr) = *((int *)ptr) - (unsigned int)ptr - ((unsigned int)(v13 + *((char *)((void*)&ptr4 + 1)) <= v13 ? 1 : 0) & 1);
    }
}


/* VA 0x7ff3a081b7c, RVA 0x1b7c, CFG name sub_7ff3a081b7c; exports: [] */
typedef struct struct_0 {
    char padding_0[36];
    unsigned int field_24;
} struct_0;

extern char g_7ff3a080000;

int sub_7ff3a081b7c(long long a0)
{
    struct_0 *ptr;  // rax

    ptr = sub_7ff3a081af0(&g_7ff3a080000);
    if ((unsigned int)ptr)
    {
        ptr = sub_7ff3a081b30(&g_7ff3a080000, a0 - &g_7ff3a080000, a0 - &g_7ff3a080000);
        if (ptr)
            ptr = ~(ptr->field_24 >> 31) & 1;
    }
    return *((unsigned int *)&ptr);
}


/* VA 0x7ff3a081420, RVA 0x1420, CFG name sub_7ff3a081420; exports: [] */
unsigned int sub_7ff3a081420(unsigned int a0, unsigned int a1, unsigned int a2, unsigned short a3)
{
    char *v0;  // [bp-0x28]
    char v2;  // [bp+0x28]

    sub_7ff3a08135c();
    v0 = &v2;
    sub_7ff3a081208(a0, a1, a2, a3);
    return 0;
}


/* VA 0x7ff3a081b30, RVA 0x1b30, CFG name sub_7ff3a081b30; exports: [] */
typedef struct struct_0 {
    char padding_0[6];
    unsigned short field_6;
    char padding_8[12];
    unsigned short field_14;
    char padding_16[38];
    unsigned int field_3c;
} struct_0;

unsigned int [10] sub_7ff3a081b30(struct_0 *p, unsigned long a1)
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


/* VA 0x7ff3a082207, RVA 0x2207, CFG name sub_7ff3a082207; exports: [] */
typedef struct struct_0 {
    char field_0;
    char padding_1[16777242];
    char field_100001b;
    char padding_100001c[234881023];
    char field_f00001b;
} struct_0;

void sub_7ff3a082207(char a0, unsigned long ptr8, unsigned long a2, unsigned long a3, char a4)
{
    void* addr;  // rdi
    char v2;  // al
    struct_0 *ptr4;  // rsi
    char v12;  // 4127
    unsigned long v13;  // rax
    char *ptr5;  // rdx
    char *v15;  // rax
    unsigned long v16;  // 4191
    unsigned int *ptr3;  // rax
    unsigned int *ptr6;  // rdx
    void* v3;  // rax
    void* p;  // rbx
    unsigned long v5;  // rcx
    unsigned long v6;  // cc_ndep
    unsigned long v7;  // 4122
    void* ptr;  // rax
    void* ptr7;  // rax
    char v10;  // 4106

    *((char *)addr) = *((char *)addr) + a0;
    v3 = v2 ^ 6;
    *((char *)addr) = *((char *)addr) + a0;
    v5 = a0 ^ *((char *)p);
    v7 = _ccall(0, 17, (unsigned long long)(a0 ^ *((char *)p)), 0, v6);
    ptr = v3;
    if (!((char)v7))
    {
        ptr7 = (void*)_INSERT(v3, 0, *((char *)&v3) + 1);
        *((char *)(ptr8 + ptr7 * 2)) = *((char *)(ptr8 + ptr7 * 2)) + *((char *)&v3) + 1;
        *((char *)ptr7) = *((char *)ptr7) + *((char *)&v3) + 1;
        [D] PutI(968:I8x8)[t30,0] = 0x00()
        ptr = ptr7;
    }
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((unsigned int *)ptr) = *((int *)ptr) + (unsigned int)ptr;
    v10 = *((char *)ptr);
    *((char *)ptr) = *((char *)ptr) + *((char *)&ptr);
    *((unsigned int *)p) = *((int *)p) - ((unsigned int)(v10 + *((char *)&ptr) <= v10 ? 1 : 0) & 1);
    ptr4->field_f00001b = ptr4->field_f00001b + *((char *)((void*)&ptr8 + 1));
    *((unsigned int *)ptr) = *((int *)ptr) & (unsigned int)ptr;
    ptr4->field_100001b = ptr4->field_100001b + *((char *)((void*)&ptr8 + 1));
    v12 = *((char *)(ptr * 2));
    v13 = _INSERT(ptr, 0, *((char *)&ptr) | v12);
    ptr5 = (char *)_INSERT(ptr8, 1, *((char *)((void*)&ptr8 + 1)) | *((char *)(v13 + v5)));
    *(ptr5) = *(ptr5) + (char)v5;
    v15 = (char *)_INSERT(v13, 0, (*((char *)&ptr) | v12) ^ ptr4->field_0);
    v16 = _ccall(0, 17, (unsigned long long)((*((char *)(void*)&ptr) | v12) ^ ptr4->field_0), 0, (v10 + *((char *)(void*)&ptr) <= v10 ? 1 : 0) & 1);
    if (!((char)v16))
        [D] Unsupported jumpkind Ijk_NoDecode at address 8792771666493()
    ptr3 = (unsigned int *)_INSERT(v15, 0, *((char *)&v15) + *(v15) | 1);
    *(ptr3) = *(ptr3) + (unsigned int)ptr3;
    *((unsigned int *)p) = *((int *)p) + (unsigned int)p;
    *(ptr3) = *(ptr3) | (unsigned int)ptr3;
    ptr6 = (unsigned int)ptr5 - *((int *)(addr + p)) - 0;
    *((char *)p) = *((char *)p) + *((char *)&p);
    *(ptr6) = *(ptr6) + (unsigned int)p;
    *((char *)(ptr3 * 9)) = *((char *)(ptr3 * 9)) + *((char *)&ptr6);
}


/* VA 0x7ff3a081df0, RVA 0x1df0, CFG name sub_7ff3a081df0; exports: [] */
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

int sub_7ff3a081df0(struct_3 **a0, struct_1 *ptr)
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


/* VA 0x7ff3a081e50, RVA 0x1e50, CFG name sub_7ff3a081e50; exports: [] */
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

int sub_7ff3a081e50(struct_3 **a0, struct_1 *ptr)
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


/* VA 0x7ff3a081eb0, RVA 0x1eb0, CFG name sub_7ff3a081eb0; exports: [] */
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

int sub_7ff3a081eb0(struct_3 **a0, struct_1 *ptr)
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


/* VA 0x7ff3a081f70, RVA 0x1f70, CFG name sub_7ff3a081f70; exports: [] */
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

int sub_7ff3a081f70(struct_3 **a0, struct_1 *ptr)
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


/* VA 0x7ff3a081fd0, RVA 0x1fd0, CFG name sub_7ff3a081fd0; exports: [] */
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

int sub_7ff3a081fd0(struct_3 **a0, struct_1 *ptr)
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


/* VA 0x7ff3a082030, RVA 0x2030, CFG name sub_7ff3a082030; exports: [] */
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

int sub_7ff3a082030(struct_3 **a0, struct_1 *ptr)
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


/* VA 0x7ff3a081f10, RVA 0x1f10, CFG name sub_7ff3a081f10; exports: [] */
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

int sub_7ff3a081f10(struct_3 **a0, struct_1 *ptr)
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


/* VA 0x7ff3a082090, RVA 0x2090, CFG name sub_7ff3a082090; exports: [] */
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

int sub_7ff3a082090(struct_3 **a0, struct_1 *ptr)
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


/* VA 0x7ff3a081468, RVA 0x1468, CFG name sub_7ff3a081468; exports: [] */
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

unsigned int sub_7ff3a081468(unsigned int a0, struct_0 *a1, unsigned int *ptr, void* a3)
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
LABEL_7ff3a0814f4:
        cur->field_10 = v2;
        cur->field_19 = v4;
        cur->field_1c = v3;
        goto LABEL_7ff3a0814f4;
    }
    return 0;
}


/* VA 0x7ff3a081be8, RVA 0x1be8, CFG name _security_init_cookie; exports: [] */
extern unsigned long long g_7ff3a083118;
extern unsigned long long g_7ff3a083120;

unsigned long long _security_init_cookie(void)
{
    unsigned int v2;  // eax
    unsigned int v3;  // eax
    unsigned int v4;  // eax
    unsigned long long v5;  // r11
    unsigned int flag[2];  // [bp+0x8], Other Possible Types: unsigned long long
    long long v1;  // [bp+0x10]

    flag = 0;
    if (g_7ff3a083118 != 47936899621426)
    {
        g_7ff3a083120 = ~(g_7ff3a083118);
        return g_7ff3a083120;
    }
    GetSystemTimeAsFileTime(&flag);
    v2 = GetCurrentProcessId();
    v3 = GetCurrentThreadId();
    v4 = GetTickCount();
    QueryPerformanceCounter(&v1);
    v5 = (unsigned long long)((v1 ^ flag ^ v2 ^ v3 ^ v4) & 281474976710655);
    if (v5 == 47936899621426)
        v5 = 47936899621427;
    g_7ff3a083118 = v5;
    g_7ff3a083120 = ~(v5);
    return 47936899621427;
}


/* VA 0x7ff3a08135c, RVA 0x135c, CFG name sub_7ff3a08135c; exports: [] */
extern unsigned long long g_7ff3a083128;
extern unsigned long long g_7ff3a083130;
extern unsigned int g_7ff3a0836f0;

HMODULE sub_7ff3a08135c(void)
{
    HMODULE v1;  // rbx
    void* v2;  // rax

    v1 = LoadLibraryW(L"advapi32");
    if (!v1)
    {
        g_7ff3a0836f0 = 0;
        g_7ff3a083128 = sub_7ff3a081338;
        g_7ff3a083130 = sub_7ff3a081208;
        return v1;
    }
    g_7ff3a083128 = GetProcAddress(v1, "TraceMessage");
    if (!g_7ff3a083128)
    {
        g_7ff3a0836f0 = 0;
        g_7ff3a083128 = sub_7ff3a081338;
        g_7ff3a083130 = sub_7ff3a081208;
    }
    else
    {
        g_7ff3a0836f0 = 1;
        v2 = GetProcAddress(v1, "TraceMessageVa");
        if (!v2)
            v2 = sub_7ff3a081208;
        g_7ff3a083130 = v2;
    }
    return FreeLibrary(v1);
}


/* VA 0x7ff3a0811e2, RVA 0x11e2, CFG name sub_7ff3a0811e2; exports: [] */
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

unsigned int sub_7ff3a0811e2(unsigned long long a0, unsigned long long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, void* a33)
{
    unsigned long v2;  // cc_op
    unsigned long v3;  // cc_dep1
    unsigned long v12;  // 4101
    unsigned long long v13;  // 4097
    void* p;  // rax
    void* iter;  // rsi
    void* addr;  // rax
    HLOCAL v17;  // rdi
    unsigned long long v18;  // r12
    void* cur;  // r8
    UIntPtr v20;  // rbx
    unsigned long v4;  // cc_dep2
    void* idx;  // rax
    void* ptr5;  // rax
    UIntPtr v23;  // rcx
    unsigned long long i;  // rbp
    unsigned long v5;  // cc_ndep
    unsigned long v6;  // 4101
    void* ptr;  // rax
    char v8;  // 4102
    unsigned long v9;  // cc_dep1
    unsigned long v10;  // cc_dep2
    unsigned long v11;  // 4101
    int v1;  // [bp+0x20]

    v6 = _ccall(12, v2, v3, v4, v5);
    if (!((char)v6))
        goto LABEL_0x7ff3a0811a5;
    *((unsigned int *)ptr) = *((int *)ptr) + (unsigned int)ptr;
    v8 = *((char *)ptr);
    *((char *)ptr) = v8 + *((char *)&ptr);
    v9 = v8;
    v10 = *((char *)&ptr);
    if ((char)__CFADD__(v8, *((char *)&ptr)))
    {
        v11 = _ccall(0, 1, v9, v10, v5);
        if ((char)v11)
            goto LABEL_7ff3a08123f;
        if ((char)__CFADD__(v9, v10))
        {
            v12 = _ccall(0, 1, v9, v10, v5);
            if ((char)v12)
                goto LABEL_7ff3a081256;
        }
        else
        {
            v13 = __inbyte((unsigned short)a1);
            p = (void*)_INSERT(ptr, 0, __inbyte((unsigned short)a1));
            *((char *)p) = *((char *)p) * 2 | *((char *)p) >> 7;
            *((char *)p) = *((char *)p) + (char)v13;
            iter = a33;
            addr = p + 32;
            v17 = NULL;
        }
    }
    *((unsigned long *)&(&v1)[24]) = a2;
LABEL_7ff3a08123f:
    a9 = (unsigned int)addr;
    v18 = a0;
    addr = iter;
    *((unsigned int *)&(&v1)[44]) = 0x1a0000;
    *((char *)&(&v1)[4]) = 255;
LABEL_7ff3a081256:
    a10 = (int)_INSERT(a10 CONCAT 0, 0, 2);
    cur = &a10;
    while (true)
    {
        idx = addr;
        if (!(long long)idx[8])
            break;
        ptr5 = idx + 16;
        v23 = *((long long *)ptr5);
        v20 += v23;
        if (v20 < v23)
            return 0;
        a1 += 1;
        cur += 16;
        addr = ptr5;
        if (a1 <= 7)
        {
            *((long long *)&cur[8]) = (long long)idx[8];
            *((unsigned int *)cur) = (unsigned int)v23;
            addr = ptr5;
        }
    }
    if (v20 > 0x2000)
        return 0;
    if (a1 > 7)
    {
        v17 = LocalAlloc(GMEM_FIXED, v20);
        if (!v17)
            return 0;
        a11 = v17;
        a12 = (unsigned int)v20;
        for (i = 0; (long long)iter[8]; i += *((long long *)iter))
        {
            iter += 16;
            memcpy(v17 + i);
        }
        *((unsigned short *)&v1) = 80;
    }
    else
    {
        *((unsigned short *)&v1) = ((unsigned short)a1 + 4) * 16;
    }
    TraceEvent(v18, &v1);
    if (!v17)
        return 0;
    LocalFree(v17);
    return 0;
}


/* VA 0x7ff3a081518, RVA 0x1518, CFG name sub_7ff3a081518; exports: [] */
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

extern char g_7ff3a0811c0;
extern struct_1 *g_7ff3a083138;
extern struct_0 *g_7ff3a0836c0;
extern unsigned long long g_7ff3a0836d0;
extern char g_7ff3a0836d8;
extern char g_7ff3a0836d9;
extern unsigned short g_7ff3a0836da;
extern unsigned int g_7ff3a0836dc;
extern Guid *g_7ff3a0836e0;
extern unsigned long long g_7ff3a0836e8;

unsigned int sub_7ff3a081518(unsigned long a0, unsigned int flag)
{
    struct_0 **p;  // rbx
    Guid **v3;  // rdi
    Guid **v4;  // rdi
    struct_1 *ptr;  // rbx
    int v0;  // [bp-0x18], Other Possible Types: TRACE_GUID_REGISTRATION

    if (!flag)
    {
        ptr = g_7ff3a083138;
        if (g_7ff3a083138 == &g_7ff3a083138)
            return 1;
        for (g_7ff3a0836e8 = 0; ptr; ptr = ptr->field_0)
        {
            if (ptr->field_8)
            {
                UnregisterTraceGuids(ptr->field_8);
                ptr->field_8 = 0;
            }
        }
        g_7ff3a083138 = &g_7ff3a083138;
        return 1;
    }
    else if (flag == 1)
    {
        g_7ff3a0836e8 = a0;
        DisableThreadLibraryCalls(a0);
        sub_7ff3a08135c();
        p = &g_7ff3a0836c0;
        g_7ff3a0836e0 = &g_7ff3a0811c0;
        g_7ff3a083138 = &g_7ff3a0836c0;
        g_7ff3a0836d0 = 0;
        g_7ff3a0836c0 = 0;
        g_7ff3a0836d8 = 1;
        g_7ff3a0836d9 = 0;
        g_7ff3a0836da = 0;
        g_7ff3a0836dc = 0;
        v3 = &g_7ff3a0836e0;
        do
        {
            v4 = v3 + 1;
            *((Guid **)&v0) = *(v3);
            v0.RegHandle = 0;
            RegisterTraceGuidsW(sub_7ff3a081468, p, *(v3), 1, &v0, NULL, NULL, p + 1);
            p = *(p);
            v3 = v4;
        } while (p);
        return 1;
    }
    else
    {
        return 1;
    }
}


/* VA 0x7ff3a081ca4, RVA 0x1ca4, CFG name sub_7ff3a081ca4; exports: [] */
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

extern EXCEPTION_POINTERS g_7ff3a081178;
extern unsigned long long g_7ff3a083118;
extern unsigned long long g_7ff3a083120;
extern unsigned int g_7ff3a083150;
extern unsigned int g_7ff3a083154;
extern unsigned long long g_7ff3a083160;
extern char g_7ff3a0831f0;
extern unsigned long long g_7ff3a083270;
extern unsigned long long g_7ff3a083288;
extern unsigned long long g_7ff3a0832e8;

int sub_7ff3a081ca4(unsigned long a0)
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
    RtlCaptureContext(&g_7ff3a0831f0);
    v3 = g_7ff3a0832e8;
    v2 = RtlLookupFunctionEntry(v3, &v4, NULL);
    if (v2)
    {
        RtlVirtualUnwind(UNW_FLAG_NHANDLER, v4, v3, v2, &g_7ff3a0831f0, &v0, &v1, NULL);
    }
    else
    {
        g_7ff3a0832e8 = v7;
        g_7ff3a083288 = &v8;
    }
    g_7ff3a083160 = g_7ff3a0832e8;
    g_7ff3a083270 = v8;
    g_7ff3a083150 = 3221226505;
    g_7ff3a083154 = 1;
    v5 = g_7ff3a083118;
    v6 = g_7ff3a083120;
    SetUnhandledExceptionFilter(NULL);
    UnhandledExceptionFilter(&g_7ff3a081178.ExceptionRecord);
    return TerminateProcess(GetCurrentProcess(), 3221226505);
}


/* VA 0x7ff3a081864, RVA 0x1864, CFG name sub_7ff3a081864; exports: [] */
typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

extern unsigned int g_7ff3a083110;
extern char g_7ff3a083148;
extern unsigned int g_7ff3a08314c;
extern struct_0 *g_7ff3a083710;

unsigned int sub_7ff3a081864(long long a0, unsigned int flag, long long a2)
{
    unsigned int v3;  // ebx
    unsigned int v0;  // [bp-0x138]
    long long v1;  // [bp+0x8]
    unsigned int v2;  // [bp+0x10]

    v2 = flag;
    v1 = a0;
    v3 = 1;
    v0 = 1;
    g_7ff3a083110 = flag;
    if (!flag && *((int *)&g_7ff3a083148) == flag)
    {
        v3 = 0;
        v0 = 0;
    }
    else
    {
        if (flag == 1 || flag == 2)
        {
            if (g_7ff3a083710)
            {
                g_7ff3a08314c = 1;
                v3 = g_7ff3a083710();
                v0 = v3;
            }
            if (v3)
            {
                v3 = sub_7ff3a08168c(a0, flag, a2);
                v0 = v3;
            }
            if (!v3)
            {
                g_7ff3a083110 = 4294967295;
                return v3;
            }
        }
        v3 = sub_7ff3a081518(a0, flag);
        v0 = v3;
        if (flag == 1 && !v3)
        {
            sub_7ff3a081518(a0, 0);
            sub_7ff3a08168c(a0, 0, 0);
            if (g_7ff3a083710)
                g_7ff3a083710(a0, 0, 0);
        }
        if (!flag || flag == 3)
        {
            v3 = sub_7ff3a08168c(a0, flag, a2);
            v0 = v3;
            if (g_7ff3a083710 && g_7ff3a08314c)
            {
                v3 = g_7ff3a083710(a0, flag, a2);
                v0 = v3;
            }
        }
    }
    g_7ff3a083110 = 4294967295;
    return v3;
}


/* VA 0x7ff3a08168c, RVA 0x168c, CFG name sub_7ff3a08168c; exports: [] */
typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

extern long long g_7ff3a081118;
extern long long g_7ff3a081120;
extern struct_0 *g_7ff3a081128;
extern struct_0 *g_7ff3a081138;
extern int g_7ff3a083148;
extern unsigned int g_7ff3a0836f4;
extern char g_7ff3a0836f8;
extern void* g_7ff3a083700;
extern void* g_7ff3a083708;
extern struct_1 *g_7ff3a083718;

unsigned int sub_7ff3a08168c(unsigned long a0, unsigned int flag, unsigned long a2)
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
        if (g_7ff3a083148 > 0)
        {
            g_7ff3a083148 = g_7ff3a083148 - 1;
            while (InterlockedCompareExchange64(&g_7ff3a0836f8, 1, 0))
            {
                Sleep(1000);
            }
            if (g_7ff3a0836f4 != 2)
            {
                _amsg_exit(31);
                return 1;
            }
            if (g_7ff3a083708)
            {
                for (i = g_7ff3a083700 - 8; i >= g_7ff3a083708; i -= 8)
                {
                    if (*((long long *)i))
                        (*((long long *)i))();
                }
                free(g_7ff3a083708);
                g_7ff3a083700 = 0;
                g_7ff3a083708 = 0;
            }
            g_7ff3a0836f4 = 0;
            InterlockedExchange64(&g_7ff3a0836f8, 0);
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
                v4 = InterlockedCompareExchange64(&g_7ff3a0836f8, *((long long *)(*((long long *)(48 + v3)) + 8)), 0);
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
            if (g_7ff3a0836f4)
            {
                _amsg_exit(31);
            }
            else
            {
                cur = &g_7ff3a081128;
                g_7ff3a0836f4 = 1;
                v6 = 0;
                do
                {
                    if (v6)
                        return 0;
                    v7 = *(cur);
                    if (v7)
                        v6 = v7(v7);
                    cur += 1;
                } while (cur < &g_7ff3a081138);
                if (v6)
                    return 0;
                _initterm(&g_7ff3a081118, &g_7ff3a081120);
                g_7ff3a0836f4 = 2;
            }
            if (!v2)
                InterlockedExchange64(&g_7ff3a0836f8, 0);
            if (g_7ff3a083718 && sub_7ff3a081b7c(&g_7ff3a083718))
                g_7ff3a083718(a0, 2, a2);
            g_7ff3a083148 = g_7ff3a083148 + 1;
            return 1;
        }
        else
        {
            return 1;
        }
    }
}


