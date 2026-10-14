/* AUTOMATED ANGR PSEUDOCODE, NOT ORIGINAL SOURCE; NOT A BUILD TARGET.
 * Types, signatures, locals, calling conventions and control flow are inferred, unverified.
 * Input SHA256: cb11e89d0d48baad659f120a9bb66fec7aa47bca0866ae3677539801638010ef; addresses use preferred image base.
 * Per-function omissions and errors: analysis/report/modules/MpAsDesc.dll/function-coverage.json
 */

/* VA 0x7ff25ce1758, RVA 0x1758, CFG name GetMpAsDescModuleHandle; exports: ['GetMpAsDescModuleHandle'] */
extern unsigned long long g_7ff25ce36e8;

long long GetMpAsDescModuleHandle(void)
{
    return g_7ff25ce36e8;
}


/* VA 0x7ff25ce1768, RVA 0x1768, CFG name MpGetSignatureDescriptionResourceIdentifier; exports: ['MpGetSignatureDescriptionResourceIdentifier'] */
typedef struct struct_0 {
    char padding_0[16];
    long long field_10;
    char padding_18[4];
    char field_1c;
} struct_0;

extern long long g_7ff25ce11e0;
extern unsigned int g_7ff25ce11f0[4];
extern struct_0 *g_7ff25ce3138;
extern HINSTANCE g_7ff25ce36e8;

unsigned int MpGetSignatureDescriptionResourceIdentifier(int a0, unsigned int a1, unsigned int *ptr)
{
    unsigned long long idx;  // rsi
    struct_0 *v2;  // rcx
    unsigned int v3;  // r12d
    WCHAR v0[4];  // [bp+0x8]

    if (a0 > 0 && a0 < 8 && ptr)
    {
        idx = (a0 - 1) * 3;
        if (g_7ff25ce11f0[1 + idx] - g_7ff25ce11f0[idx] <= a1)
        {
            v2 = g_7ff25ce3138;
            if (g_7ff25ce3138 != &g_7ff25ce3138 && (g_7ff25ce3138->field_1c & 2))
                goto LABEL_7ff25ce17e0;
        }
        else
        {
            v3 = g_7ff25ce11f0[idx] + a1;
            if (!LoadStringW(g_7ff25ce36e8, v3, &v0, 2))
            {
                v2 = g_7ff25ce3138;
                if (g_7ff25ce3138 != &g_7ff25ce3138 && (g_7ff25ce3138->field_1c & 2))
                {
LABEL_7ff25ce17e0:
                    sub_7ff25ce14d8(v2->field_10);
                }
                *(ptr) = g_7ff25ce11f0[2 + idx];
            }
            else
            {
                *(ptr) = v3;
            }
        }
        return 0;
    }
    if (g_7ff25ce3138 != &g_7ff25ce3138 && (g_7ff25ce3138->field_1c & 1))
        sub_7ff25ce1528(g_7ff25ce3138->field_10, 10, &g_7ff25ce11e0, a0, ptr);
    return 2147942487;
}


/* VA 0x7ff25ce1cb0, RVA 0x1cb0, CFG name _start; exports: [] */
void _start(long long a0, unsigned int flag, long long a2)
{
    if (flag == 1)
        _security_init_cookie();
    sub_7ff25ce1abc(a0, flag, a2);
    return;
}


/* VA 0x7ff25ce1e06, RVA 0x1e06, CFG name sub_7ff25ce1e06; exports: [] */
int sub_7ff25ce1e06(void)
{
}


/* VA 0x7ff25ce23a5, RVA 0x23a5, CFG name sub_7ff25ce23a5; exports: [] */
char sub_7ff25ce23a5(unsigned long a0, char *ptr)
{
    char v2;  // al
    unsigned long v0;  // [bp-0x8]

    v0 = v2 ^ *(ptr);
}


/* VA 0x7ff25ce1c8c, RVA 0x1c8c, CFG name sub_7ff25ce1c8c; exports: [] */
void sub_7ff25ce1c8c(void)
{
    unsigned int flag;  // [bp+0x20]

    flag = 0;
}


/* VA 0x7ff25ce1d26, RVA 0x1d26, CFG name _XcptFilter; exports: [] */
// attributes: PLT stub
int _XcptFilter(void)
{
    ::msvcrt.dll::_XcptFilter();
    return;
}


/* VA 0x7ff25ce1e14, RVA 0x1e14, CFG name _initterm; exports: [] */
// attributes: PLT stub
int _initterm(void)
{
    ::msvcrt.dll::_initterm();
    return;
}


/* VA 0x7ff25ce1e20, RVA 0x1e20, CFG name _amsg_exit; exports: [] */
// attributes: PLT stub
int _amsg_exit(void)
{
    ::msvcrt.dll::_amsg_exit();
    return;
}


/* VA 0x7ff25ce1e2c, RVA 0x1e2c, CFG name __C_specific_handler; exports: [] */
// attributes: PLT stub
int __C_specific_handler(void)
{
    ::msvcrt.dll::__C_specific_handler();
    return;
}


/* VA 0x7ff25ce201c, RVA 0x201c, CFG name RtlVirtualUnwind; exports: [] */
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


/* VA 0x7ff25ce2028, RVA 0x2028, CFG name RtlLookupFunctionEntry; exports: [] */
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


/* VA 0x7ff25ce2034, RVA 0x2034, CFG name memcpy; exports: [] */
// attributes: PLT stub
int memcpy(void)
{
    ::msvcrt.dll::memcpy();
    return;
}


/* VA 0x7ff25ce1cf6, RVA 0x1cf6, CFG name sub_7ff25ce1cf6; exports: [] */
void sub_7ff25ce1cf6(unsigned long a0)
{
    sub_7ff25ce1d00();
    return;
}


/* VA 0x7ff25ce11e2, RVA 0x11e2, CFG name sub_7ff25ce11e2; exports: [] */
void sub_7ff25ce11e2(char a0, char a1)
{
    return;
}


/* VA 0x7ff25ce11cf, RVA 0x11cf, CFG name sub_7ff25ce11cf; exports: [] */
void sub_7ff25ce11cf(unsigned long a0)
{
    [D] Unsupported jumpkind Ijk_SigTRAP at address 8792432316879()
}


/* VA 0x7ff25ce1bc8, RVA 0x1bc8, CFG name sub_7ff25ce1bc8; exports: [] */
void sub_7ff25ce1bc8(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
}


/* VA 0x7ff25ce1bea, RVA 0x1bea, CFG name sub_7ff25ce1bea; exports: [] */
void sub_7ff25ce1bea(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
}


/* VA 0x7ff25ce1c15, RVA 0x1c15, CFG name sub_7ff25ce1c15; exports: [] */
void sub_7ff25ce1c15(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
}


/* VA 0x7ff25ce1b31, RVA 0x1b31, CFG name sub_7ff25ce1b31; exports: [] */
void sub_7ff25ce1b31(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
    unsigned int flag;  // [bp+0x20]

    flag = 0;
}


/* VA 0x7ff25ce1b64, RVA 0x1b64, CFG name sub_7ff25ce1b64; exports: [] */
void sub_7ff25ce1b64(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
    unsigned int flag;  // [bp+0x20]

    flag = 0;
}


/* VA 0x7ff25ce1b9b, RVA 0x1b9b, CFG name sub_7ff25ce1b9b; exports: [] */
void sub_7ff25ce1b9b(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
    unsigned int flag;  // [bp+0x20]

    flag = 0;
}


/* VA 0x7ff25ce1c4b, RVA 0x1c4b, CFG name sub_7ff25ce1c4b; exports: [] */
void sub_7ff25ce1c4b(unsigned long a0, unsigned long a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28, unsigned long a29, unsigned long a30, unsigned long a31, unsigned long a32, unsigned long a33, unsigned long a34, unsigned long a35, unsigned long a36, unsigned long a37, unsigned long a38, unsigned long a39, unsigned long a40, unsigned long a41, unsigned long a42, unsigned long a43, unsigned int a44)
{
    unsigned int flag;  // [bp+0x20]

    flag = 0;
}


/* VA 0x7ff25ce2340, RVA 0x2340, CFG name sub_7ff25ce2340; exports: [] */
extern unsigned int g_7ff25ce3110;

void sub_7ff25ce2340(unsigned long a0, unsigned long a1)
{
    g_7ff25ce3110 = 4294967295;
    return;
}


/* VA 0x7ff25ce13a8, RVA 0x13a8, CFG name sub_7ff25ce13a8; exports: [] */
long long sub_7ff25ce13a8(unsigned long a0, unsigned long a1, unsigned long a2, unsigned short a3)
{
    char *v0;  // [bp-0x18]
    unsigned short v2;  // [bp+0x20]
    char v3;  // [bp+0x28]

    v2 = a3;
    v0 = &v3;
    return sub_7ff25ce1278();
}


/* VA 0x7ff25ce1d00, RVA 0x1d00, CFG name sub_7ff25ce1d00; exports: [] */
extern char g_7ff25ce3118;

void sub_7ff25ce1d00(unsigned long a0)
{
    if (a0 != *((long long *)&g_7ff25ce3118))
    {
        sub_7ff25ce1ef4();
        return;
    }
    else if (!(unsigned short)(__ROL__(a0, 16)))
    {
        return;
    }
    else
    {
        sub_7ff25ce1ef4();
        return;
    }
}


/* VA 0x7ff25ce235f, RVA 0x235f, CFG name sub_7ff25ce235f; exports: [] */
typedef struct struct_0 {
    unsigned int field_0;
} struct_0;

long long sub_7ff25ce235f(struct_0 **a0, unsigned long a1)
{
    return *(a0)->field_0 == 3221225477;
}


/* VA 0x7ff25ce1278, RVA 0x1278, CFG name sub_7ff25ce1278; exports: [] */
long long sub_7ff25ce1278(unsigned long a0, unsigned long a1, unsigned long a2, unsigned short a3, unsigned long a4)
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
    v4 = vvar_7{r56|8b};
    v5 = a3;
    v2 = v8;
    v1 = v9;
    v0 = v10;
}


/* VA 0x7ff25ce1d40, RVA 0x1d40, CFG name sub_7ff25ce1d40; exports: [] */
unsigned int sub_7ff25ce1d40(void* ptr)
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


/* VA 0x7ff25ce18a8, RVA 0x18a8, CFG name sub_7ff25ce18a8; exports: [] */
extern unsigned long long g_7ff25ce3700;
extern unsigned long long g_7ff25ce3708;

unsigned int sub_7ff25ce18a8(void)
{
    unsigned long long *ptr;  // rax

    ptr = malloc(0x100);
    g_7ff25ce3708 = ptr;
    g_7ff25ce3700 = ptr;
    if (ptr)
    {
        *(ptr) = 0;
        return 0;
    }
    return 1;
}


/* VA 0x7ff25ce1dcc, RVA 0x1dcc, CFG name sub_7ff25ce1dcc; exports: [] */
typedef struct struct_0 {
    char padding_0[36];
    unsigned int field_24;
} struct_0;

extern char g_7ff25ce0000;

int sub_7ff25ce1dcc(long long a0)
{
    struct_0 *ptr;  // rax

    ptr = sub_7ff25ce1d40(&g_7ff25ce0000);
    if ((unsigned int)ptr)
    {
        ptr = sub_7ff25ce1d80(&g_7ff25ce0000, a0 - &g_7ff25ce0000, a0 - &g_7ff25ce0000);
        if (ptr)
            ptr = ~(ptr->field_24 >> 31) & 1;
    }
    return *((unsigned int *)&ptr);
}


/* VA 0x7ff25ce1490, RVA 0x1490, CFG name sub_7ff25ce1490; exports: [] */
unsigned int sub_7ff25ce1490(unsigned int a0, unsigned int a1, unsigned int a2, unsigned short a3)
{
    char v1;  // [bp+0x28]

    sub_7ff25ce13cc();
    sub_7ff25ce1278(a0, a1, a2, a3, &v1);
    return 0;
}


/* VA 0x7ff25ce1d80, RVA 0x1d80, CFG name sub_7ff25ce1d80; exports: [] */
typedef struct struct_0 {
    char padding_0[6];
    unsigned short field_6;
    char padding_8[12];
    unsigned short field_14;
    char padding_16[38];
    unsigned int field_3c;
} struct_0;

unsigned int [10] sub_7ff25ce1d80(struct_0 *p, unsigned long a1)
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


/* VA 0x7ff25ce14d8, RVA 0x14d8, CFG name sub_7ff25ce14d8; exports: [] */
unsigned int sub_7ff25ce14d8(unsigned int a0, unsigned short a1, unsigned long a2, unsigned int a3)
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
    return sub_7ff25ce1490(a0, 43, 634261984, a1);
}


/* VA 0x7ff25ce1528, RVA 0x1528, CFG name sub_7ff25ce1528; exports: [] */
unsigned int sub_7ff25ce1528(unsigned int a0, unsigned long a1, unsigned long a2, unsigned int a3)
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
    v3 = 8;
    v2 = &v7;
    v1 = 4;
    v0 = &v6;
    return sub_7ff25ce1490(a0, 43, 634261984, 10);
}


/* VA 0x7ff25ce2040, RVA 0x2040, CFG name sub_7ff25ce2040; exports: [] */
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

int sub_7ff25ce2040(struct_3 **a0, struct_1 *ptr)
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


/* VA 0x7ff25ce20a0, RVA 0x20a0, CFG name sub_7ff25ce20a0; exports: [] */
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

int sub_7ff25ce20a0(struct_3 **a0, struct_1 *ptr)
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


/* VA 0x7ff25ce2100, RVA 0x2100, CFG name sub_7ff25ce2100; exports: [] */
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

int sub_7ff25ce2100(struct_3 **a0, struct_1 *ptr)
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


/* VA 0x7ff25ce21c0, RVA 0x21c0, CFG name sub_7ff25ce21c0; exports: [] */
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

int sub_7ff25ce21c0(struct_3 **a0, struct_1 *ptr)
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


/* VA 0x7ff25ce2220, RVA 0x2220, CFG name sub_7ff25ce2220; exports: [] */
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

int sub_7ff25ce2220(struct_3 **a0, struct_1 *ptr)
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


/* VA 0x7ff25ce2280, RVA 0x2280, CFG name sub_7ff25ce2280; exports: [] */
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

int sub_7ff25ce2280(struct_3 **a0, struct_1 *ptr)
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


/* VA 0x7ff25ce2391, RVA 0x2391, CFG name sub_7ff25ce2391; exports: [] */
typedef struct struct_0 {
    unsigned int field_0;
    char padding_4[1677721628];
    char field_64000020;
} struct_0;

extern char g_7ff4dcf3baf;

void sub_7ff25ce2391(void* a0, char *ptr8, unsigned long a2, unsigned long a3, unsigned long a4)
{
    char v1;  // al
    void* ptr7;  // rax
    char v11;  // 4098
    void* p;  // rax
    void* addr;  // rbx
    char v14;  // 4120
    struct_0 *ptr5;  // rax
    char v16;  // 4134
    unsigned int *ptr9;  // rax
    char v18;  // 4144
    void* ptr3;  // rax
    char v20;  // 4162
    char *ptr6;  // rsi
    char v21;  // al
    unsigned int *ptr10;  // rax
    char ptr4[34];  // rax
    char v4;  // 4104
    char v5;  // dl
    void* ptr;  // rcx
    unsigned long v7;  // cc_ndep
    unsigned long v8;  // 4111
    char v9;  // 4104
    unsigned long v10;  // 4125

    ptr7 = v1 ^ 10;
    *(ptr6) = *(ptr6) + *((char *)&ptr8);
    v4 = *(ptr8);
    v5 = *((char *)&ptr8) ^ v4;
    ptr = a0 - 1;
    if (a0 - 1 & (*((char *)&ptr8) ^ v4))
    {
        v8 = _ccall(17, (unsigned long long)(*((char *)(void*)&ptr8) ^ v4), 0, v7);
        g_7ff4dcf3baf = g_7ff4dcf3baf - *((char *)&ptr7) - ((char)v8 & 1);
        v9 = *((char *)ptr);
        *((char *)ptr) = *((char *)ptr) + v5;
        v10 = _ccall(0, 1, (unsigned long long)v9, (unsigned long long)v5, v8 & 1);
        if (!((char)v10))
            goto LABEL_0x7ff25ce23b3;
        v11 = *((char *)ptr);
        *((char *)ptr) = *((char *)ptr) + v5;
        p = (unsigned int)ptr7 - *((int *)ptr7) - ((unsigned int)(v11 + v5 <= v11 ? 1 : 0) & 1);
        *((char *)&p[32]) = (char)p[32] + *((char *)&p);
        *((char *)p) = *((char *)p) + *((char *)&p);
        *((unsigned int *)addr) = *((int *)addr) ^ (unsigned int)addr;
        v14 = *((char *)p);
        *((char *)p) = *((char *)p) + *((char *)&p);
        ptr5 = p - *((long long *)p) - ((v14 + *((char *)&p) <= v14 ? 1 : 0) & 1);
        *((char *)(addr * 2)) = *((char *)(addr * 2)) + *((char *)((void*)&ptr5 + 1));
        v16 = ptr5->field_64000020;
        ptr5->field_64000020 = ptr5->field_64000020 + *((char *)((void*)&ptr5 + 1));
        ptr9 = (unsigned int)ptr5 - ptr5->field_0 - ((unsigned int)(v16 + *((char *)((void*)&ptr5 + 1)) <= v16 ? 1 : 0) & 1);
        v18 = (char)ptr[1694498789];
        *((char *)&ptr[1694498789]) = (char)ptr[1694498789] + *((char *)&ptr9);
        ptr3 = (unsigned int)ptr9 - *(ptr9) - ((unsigned int)(v18 + *((char *)&ptr9) <= v18 ? 1 : 0) & 1);
        *((char *)ptr3) = *((char *)ptr3) + *((char *)&ptr3);
        *((unsigned int *)ptr3) = *((int *)ptr3) & (unsigned int)ptr3;
        v20 = (char)addr[1191182309];
        *((char *)&addr[1191182309]) = (char)addr[1191182309] + *((char *)&addr);
        v21 = (unsigned int)ptr3 - *((int *)ptr3) - ((unsigned int)(v20 + *((char *)&addr) <= v20 ? 1 : 0) & 1);
        ptr10 = (unsigned int *)_INSERT(v21, 0, v21 + *((char *)&ptr));
        ptr4 = (unsigned int)ptr10 - *(ptr10) - ((unsigned int)(v21 + *((char *)&ptr) <= v21 ? 1 : 0) & 1);
        ptr4[33] = ptr4[33] + *((char *)((void*)&ptr4 + 1));
        ptr4[0] = ptr4[0] + *((char *)&ptr4);
        *((int *)addr) = ([D] unsupported_<class 'pyvex.expr.GetI'>() ? [D] unsupported_<class 'pyvex.expr.GetI'>() : nan);
        [D] PutI(968:I8x8)[t234,0] = 0x00()
        ptr4[0] = ptr4[0] + *((char *)&ptr4);
    }
    *(ptr6) = *(ptr6) >> 1 | *(ptr6) * 128;
    *((char *)ptr7 + 0x2 * ptr6) = *((char *)ptr7 + 0x2 * ptr6) >> 3 | *((char *)ptr7 + 0x2 * ptr6) * 32;
}


/* VA 0x7ff25ce2160, RVA 0x2160, CFG name sub_7ff25ce2160; exports: [] */
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

int sub_7ff25ce2160(struct_3 **a0, struct_1 *ptr)
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


/* VA 0x7ff25ce22e0, RVA 0x22e0, CFG name sub_7ff25ce22e0; exports: [] */
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

int sub_7ff25ce22e0(struct_3 **a0, struct_1 *ptr)
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


/* VA 0x7ff25ce1580, RVA 0x1580, CFG name sub_7ff25ce1580; exports: [] */
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

unsigned int sub_7ff25ce1580(unsigned int a0, struct_0 *a1, unsigned int *ptr, void* a3)
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
LABEL_7ff25ce160c:
        cur->field_10 = v2;
        cur->field_19 = v4;
        cur->field_1c = v3;
        goto LABEL_7ff25ce160c;
    }
    return 0;
}


/* VA 0x7ff25ce1e38, RVA 0x1e38, CFG name _security_init_cookie; exports: [] */
extern unsigned long long g_7ff25ce3118;
extern unsigned long long g_7ff25ce3120;

unsigned long long _security_init_cookie(void)
{
    unsigned int v2;  // eax
    unsigned int v3;  // eax
    unsigned int v4;  // eax
    unsigned long long v5;  // r11
    unsigned int flag[2];  // [bp+0x8], Other Possible Types: unsigned long long
    long long v1;  // [bp+0x10]

    flag = 0;
    if (g_7ff25ce3118 != 47936899621426)
    {
        g_7ff25ce3120 = ~(g_7ff25ce3118);
        return g_7ff25ce3120;
    }
    GetSystemTimeAsFileTime(&flag);
    v2 = GetCurrentProcessId();
    v3 = GetCurrentThreadId();
    v4 = GetTickCount();
    QueryPerformanceCounter(&v1);
    v5 = (unsigned long long)((v1 ^ flag ^ v2 ^ v3 ^ v4) & 281474976710655);
    if (v5 == 47936899621426)
        v5 = 47936899621427;
    g_7ff25ce3118 = v5;
    g_7ff25ce3120 = ~(v5);
    return 47936899621427;
}


/* VA 0x7ff25ce13cc, RVA 0x13cc, CFG name sub_7ff25ce13cc; exports: [] */
extern unsigned long long g_7ff25ce3128;
extern unsigned long long g_7ff25ce3130;
extern unsigned int g_7ff25ce36f0;

HMODULE sub_7ff25ce13cc(void)
{
    HMODULE v1;  // rbx
    void* v2;  // rax

    v1 = LoadLibraryW(L"advapi32");
    if (!v1)
    {
        g_7ff25ce36f0 = 0;
        g_7ff25ce3128 = sub_7ff25ce13a8;
        g_7ff25ce3130 = sub_7ff25ce1278;
        return v1;
    }
    g_7ff25ce3128 = GetProcAddress(v1, "TraceMessage");
    if (!g_7ff25ce3128)
    {
        g_7ff25ce36f0 = 0;
        g_7ff25ce3128 = sub_7ff25ce13a8;
        g_7ff25ce3130 = sub_7ff25ce1278;
    }
    else
    {
        g_7ff25ce36f0 = 1;
        v2 = GetProcAddress(v1, "TraceMessageVa");
        if (!v2)
            v2 = sub_7ff25ce1278;
        g_7ff25ce3130 = v2;
    }
    return FreeLibrary(v1);
}


/* VA 0x7ff25ce1630, RVA 0x1630, CFG name sub_7ff25ce1630; exports: [] */
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

extern char g_7ff25ce11d0;
extern struct_1 *g_7ff25ce3138;
extern struct_0 *g_7ff25ce36c0;
extern unsigned long long g_7ff25ce36d0;
extern char g_7ff25ce36d8;
extern char g_7ff25ce36d9;
extern unsigned short g_7ff25ce36da;
extern unsigned int g_7ff25ce36dc;
extern Guid *g_7ff25ce36e0;
extern unsigned long long g_7ff25ce36e8;

unsigned int sub_7ff25ce1630(unsigned long a0, unsigned int flag)
{
    struct_0 **p;  // rbx
    Guid **v3;  // rdi
    Guid **v4;  // rdi
    struct_1 *ptr;  // rbx
    int v0;  // [bp-0x18], Other Possible Types: TRACE_GUID_REGISTRATION

    if (!flag)
    {
        ptr = g_7ff25ce3138;
        if (g_7ff25ce3138 == &g_7ff25ce3138)
            return 1;
        for (g_7ff25ce36e8 = 0; ptr; ptr = ptr->field_0)
        {
            if (ptr->field_8)
            {
                UnregisterTraceGuids(ptr->field_8);
                ptr->field_8 = 0;
            }
        }
        g_7ff25ce3138 = &g_7ff25ce3138;
        return 1;
    }
    else if (flag == 1)
    {
        g_7ff25ce36e8 = a0;
        DisableThreadLibraryCalls(a0);
        sub_7ff25ce13cc();
        p = &g_7ff25ce36c0;
        g_7ff25ce36e0 = &g_7ff25ce11d0;
        g_7ff25ce3138 = &g_7ff25ce36c0;
        g_7ff25ce36d0 = 0;
        g_7ff25ce36c0 = 0;
        g_7ff25ce36d8 = 1;
        g_7ff25ce36d9 = 0;
        g_7ff25ce36da = 0;
        g_7ff25ce36dc = 0;
        v3 = &g_7ff25ce36e0;
        do
        {
            v4 = v3 + 1;
            *((Guid **)&v0) = *(v3);
            v0.RegHandle = 0;
            RegisterTraceGuidsW(sub_7ff25ce1580, p, *(v3), 1, &v0, NULL, NULL, p + 1);
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


/* VA 0x7ff25ce1ef4, RVA 0x1ef4, CFG name sub_7ff25ce1ef4; exports: [] */
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

extern EXCEPTION_POINTERS g_7ff25ce1188;
extern unsigned long long g_7ff25ce3118;
extern unsigned long long g_7ff25ce3120;
extern unsigned int g_7ff25ce3150;
extern unsigned int g_7ff25ce3154;
extern unsigned long long g_7ff25ce3160;
extern char g_7ff25ce31f0;
extern unsigned long long g_7ff25ce3270;
extern unsigned long long g_7ff25ce3288;
extern unsigned long long g_7ff25ce32e8;

int sub_7ff25ce1ef4(unsigned long a0)
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
    RtlCaptureContext(&g_7ff25ce31f0);
    v3 = g_7ff25ce32e8;
    v2 = RtlLookupFunctionEntry(v3, &v4, NULL);
    if (v2)
    {
        RtlVirtualUnwind(UNW_FLAG_NHANDLER, v4, v3, v2, &g_7ff25ce31f0, &v0, &v1, NULL);
    }
    else
    {
        g_7ff25ce32e8 = v7;
        g_7ff25ce3288 = &v8;
    }
    g_7ff25ce3160 = g_7ff25ce32e8;
    g_7ff25ce3270 = v8;
    g_7ff25ce3150 = 3221226505;
    g_7ff25ce3154 = 1;
    v5 = g_7ff25ce3118;
    v6 = g_7ff25ce3120;
    SetUnhandledExceptionFilter(NULL);
    UnhandledExceptionFilter(&g_7ff25ce1188.ExceptionRecord);
    return TerminateProcess(GetCurrentProcess(), 3221226505);
}


/* VA 0x7ff25ce1211, RVA 0x1211, CFG name sub_7ff25ce1211; exports: [] */
typedef struct struct_0 {
    char padding_0[23];
    char field_17;
} struct_0;

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

extern unsigned int g_b746235a5592026a;

unsigned int sub_7ff25ce1211(unsigned long long a0, void* ptr6, void* cur, unsigned long a3, char a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9, unsigned long a10, unsigned long a11, unsigned long a12, unsigned long a13, unsigned long a14, unsigned long a15, unsigned long a16, unsigned long a17, unsigned long a18, unsigned long a19, unsigned long a20, unsigned long a21, unsigned long a22, unsigned long a23, unsigned long a24, unsigned long a25, unsigned long a26, unsigned long a27, unsigned long a28)
{
    unsigned int *ptr9;  // rax
    void* ptr3;  // rax
    unsigned long long v16;  // cc_op
    unsigned long v17;  // cc_dep1
    unsigned long v18;  // cc_dep2
    unsigned long v19;  // 4189
    char v20;  // 4098
    char *ptr5;  // rax
    char v22;  // 4114
    void* p;  // rax
    char v24;  // 4130
    unsigned int *v25;  // rbp
    char v8;  // 4102
    unsigned long v26;  // 4130
    void* addr;  // rax
    char v28;  // 4113
    unsigned long v29;  // cc_dep1
    unsigned long v30;  // cc_dep2
    unsigned long v31;  // 4149
    unsigned long v32;  // 4101
    void* v33;  // rsi
    void* iter;  // rsi
    unsigned long long v35;  // r12
    unsigned int *ptr10;  // rax
    unsigned long long ptr14[3];  // rax
    void* v37;  // rbx
    unsigned long long off[3];  // rax
    unsigned long long ptr11[3];  // rax
    void* v40;  // rcx
    HLOCAL v41;  // rdi
    unsigned long long i;  // rbp
    char v10;  // 4112
    unsigned long long v11;  // cc_ndep
    char ptr[24];  // rax
    void* ptr12;  // rbx
    struct_0 *node;  // rdx
    char v15;  // 4131
    unsigned long v0;  // [bp-0x18]
    void* v1;  // [bp-0x10]
    void* v2;  // [bp-0x8]
    unsigned int *ptr13;  // [bp+0x0]
    EVENT_TRACE_HEADER v4;  // [bp+0x8], Other Possible Types: int
    char v5;  // [bp+0xc]

    ptr3 = (unsigned int)ptr9 | *(ptr9);
    v8 = (char)ptr3[2013265905];
    *((char *)&ptr3[2013265905]) = (char)ptr3[2013265905] + *((char *)((void*)&ptr3 + 1));
    ptr10 = (unsigned int)ptr3 + *((int *)ptr3) + ((unsigned int)(v8 + *((char *)((void*)&ptr3 + 1)) <= v8 ? 1 : 0) & 1);
    v10 = (char)ptr6[2013265905];
    *((char *)&ptr6[2013265905]) = (char)ptr6[2013265905] + *((char *)((void*)&ptr10 + 1));
    v11 = (v10 + *((char *)((void*)&ptr10 + 1)) <= v10 ? 1 : 0) & 1;
    ptr = (unsigned int)ptr10 + *(ptr10) + ((unsigned int)(v10 + *((char *)((void*)&ptr10 + 1)) <= v10 ? 1 : 0) & 1);
    ptr[23] = ptr[23] + *((char *)((void*)&ptr6 + 1));
    ptr[0] = ptr[0] + *((char *)&ptr);
    node = (struct_0 *)_INSERT(ptr6, 0, *((char *)ptr12));
    v15 = ptr[0];
    ptr[0] = v15 + *((char *)&ptr);
    v16 = 1;
    v17 = v15;
    v18 = *((char *)&ptr);
    v19 = _ccall(0, 1, (unsigned long long)v15, (unsigned long long)*((char *)(void*)&ptr), (v10 + *((char *)((void*)&ptr10 + 1)) <= v10 ? 1 : 0) & 1);
    if (!((char)v19))
    {
        v20 = ptr[0];
        ptr[0] = ptr[0] + *((char *)&ptr);
        ptr5 = (unsigned int)ptr13 - *(ptr13) - ((unsigned int)(v20 + *((char *)&ptr) <= v20 ? 1 : 0) & 1);
        node->field_17 = node->field_17 + *((char *)((void*)&node + 1));
        v22 = *(ptr5);
        *(ptr5) = *(ptr5) + *((char *)&ptr5);
        p = (unsigned int)*((unsigned long long *)&v4) - *((int *)*((unsigned long long *)&v4)) - ((unsigned int)(v22 + *((char *)&ptr5) <= v22 ? 1 : 0) & 1);
        *((char *)&p[31]) = (char)p[31] + *((char *)&p);
        v24 = *((char *)p);
        *((char *)p) = *((char *)p) + *((char *)&p);
        v25 = *((unsigned long long *)(&v4 + 8));
        v16 = 15;
        v17 = p & 4294967295;
        v18 = *((int *)p) ^ (unsigned int)(v24 + *((char *)&p) <= v24 ? 1 : 0) & 1;
        v11 = (v24 + *((char *)&p) <= v24 ? 1 : 0) & 1;
        ptr = (unsigned int)p - *((int *)p) - ((unsigned int)(v24 + *((char *)&p) <= v24 ? 1 : 0) & 1);
    }
    v2 = ptr12;
    v1 = ptr12;
    g_b746235a5592026a = (unsigned int)ptr;
    __outbyte(14, *((char *)&ptr));
    v26 = _ccall(v16, v17, v18, v11);
    addr = (unsigned int)ptr + 8157373 + ((unsigned int)v26 & 1);
    *((unsigned int *)addr) = *((int *)addr) + (unsigned int)addr;
    v28 = *((char *)addr);
    *((char *)addr) = v28 + *((char *)&addr);
    v29 = v28;
    v30 = *((char *)&addr);
    v31 = _ccall(0, 1, (unsigned long long)v28, (unsigned long long)*((char *)(void*)&addr), v26 & 1);
    if (!((char)v31))
    {
        if (!((char)__CFADD__(v29, v30)))
            goto LABEL_7ff25ce12a5;
        if (!((char)__CFADD__(v29, v30)))
            goto LABEL_7ff25ce12c7;
        v32 = _ccall(0, 1, v29, v30, v26 & 1);
        if ((char)v32)
            goto LABEL_7ff25ce12cb;
        else
            goto LABEL_0x7ff25ce1267;
    }
    else
    {
        v0 = *((long long *)ptr12);
LABEL_7ff25ce12a5:
        iter = v33 - 8;
        *((void* *)&(&v4)[24]) = cur;
        a6 = addr;
        v35 = a0;
        addr = iter;
        *((unsigned int *)&(&v4)[44]) = 0x1a0000;
        v5 = 255;
LABEL_7ff25ce12c7:
        addr = (void*)_INSERT(addr, 0, *((char *)&addr) & 88);
    }
LABEL_7ff25ce12cb:
    *((char *)addr) = *((char *)addr) + *((char *)&addr);
    *((char *)&v25[17 + a0]) = (char)v25[17 + a0] + (char)a0;
    ptr14 = (unsigned long long [3])_INSERT(addr, 0, *((char *)&addr) & 88);
    while (true)
    {
        off = ptr14;
        if (!off[1])
            break;
        ptr11 = &off[2];
        v40 = ptr11[0];
        v37 += v40;
        if (v37 < v40)
            return 0;
        node = &node->padding_0[1];
        cur += 16;
        ptr14 = ptr11;
        if (node <= 0x7)
        {
            *((unsigned long long *)&cur[8]) = off[1];
            *((unsigned int *)cur) = (unsigned int)v40;
            ptr14 = ptr11;
        }
    }
    if (v37 > 0x2000)
        return 0;
    if (node > 0x7)
    {
        v41 = LocalAlloc(GMEM_FIXED, v37);
        if (!v41)
            return 0;
        a8 = v41;
        a9 = (unsigned int)v37;
        for (i = 0; (long long)iter[8]; i += *((long long *)iter))
        {
            iter += 16;
            memcpy(v41 + i);
        }
        *((unsigned short *)&v4) = 80;
    }
    else
    {
        v4.Size = (*((unsigned short *)&node) + 4) * 16;
    }
    TraceEvent(v35, &v4);
    if (!v41)
        return 0;
    LocalFree(v41);
    return 0;
}


/* VA 0x7ff25ce1abc, RVA 0x1abc, CFG name sub_7ff25ce1abc; exports: [] */
typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

extern unsigned int g_7ff25ce3110;
extern char g_7ff25ce3140;
extern unsigned int g_7ff25ce3144;
extern struct_0 *g_7ff25ce3710;

unsigned int sub_7ff25ce1abc(long long a0, unsigned int flag, long long a2)
{
    unsigned int v3;  // ebx
    unsigned int v0;  // [bp-0x138]
    long long v1;  // [bp+0x8]
    unsigned int v2;  // [bp+0x10]

    v2 = flag;
    v1 = a0;
    v3 = 1;
    v0 = 1;
    g_7ff25ce3110 = flag;
    if (!flag && *((int *)&g_7ff25ce3140) == flag)
    {
        v3 = 0;
        v0 = 0;
    }
    else
    {
        if (flag == 1 || flag == 2)
        {
            if (g_7ff25ce3710)
            {
                g_7ff25ce3144 = 1;
                v3 = g_7ff25ce3710();
                v0 = v3;
            }
            if (v3)
            {
                v3 = sub_7ff25ce18e4(a0, flag, a2);
                v0 = v3;
            }
            if (!v3)
            {
                g_7ff25ce3110 = 4294967295;
                return v3;
            }
        }
        v3 = sub_7ff25ce1630(a0, flag);
        v0 = v3;
        if (flag == 1 && !v3)
        {
            sub_7ff25ce1630(a0, 0);
            sub_7ff25ce18e4(a0, 0, 0);
            if (g_7ff25ce3710)
                g_7ff25ce3710(a0, 0, 0);
        }
        if (!flag || flag == 3)
        {
            v3 = sub_7ff25ce18e4(a0, flag, a2);
            v0 = v3;
            if (g_7ff25ce3710 && g_7ff25ce3144)
            {
                v3 = g_7ff25ce3710(a0, flag, a2);
                v0 = v3;
            }
        }
    }
    g_7ff25ce3110 = 4294967295;
    return v3;
}


/* VA 0x7ff25ce18e4, RVA 0x18e4, CFG name sub_7ff25ce18e4; exports: [] */
typedef struct struct_0 {
    unsigned long long field_0;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

extern long long g_7ff25ce1128;
extern long long g_7ff25ce1130;
extern struct_0 *g_7ff25ce1138;
extern struct_0 *g_7ff25ce1148;
extern int g_7ff25ce3140;
extern unsigned int g_7ff25ce36f4;
extern char g_7ff25ce36f8;
extern void* g_7ff25ce3700;
extern void* g_7ff25ce3708;
extern struct_1 *g_7ff25ce3718;

unsigned int sub_7ff25ce18e4(unsigned long a0, unsigned int flag, unsigned long a2)
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
        if (g_7ff25ce3140 > 0)
        {
            g_7ff25ce3140 = g_7ff25ce3140 - 1;
            while (InterlockedCompareExchange64(&g_7ff25ce36f8, 1, 0))
            {
                Sleep(1000);
            }
            if (g_7ff25ce36f4 != 2)
            {
                _amsg_exit(31);
                return 1;
            }
            if (g_7ff25ce3708)
            {
                for (i = g_7ff25ce3700 - 8; i >= g_7ff25ce3708; i -= 8)
                {
                    if (*((long long *)i))
                        (*((long long *)i))();
                }
                free(g_7ff25ce3708);
                g_7ff25ce3700 = 0;
                g_7ff25ce3708 = 0;
            }
            g_7ff25ce36f4 = 0;
            InterlockedExchange64(&g_7ff25ce36f8, 0);
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
                v4 = InterlockedCompareExchange64(&g_7ff25ce36f8, *((long long *)(*((long long *)(48 + v3)) + 8)), 0);
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
            if (g_7ff25ce36f4)
            {
                _amsg_exit(31);
            }
            else
            {
                cur = &g_7ff25ce1138;
                g_7ff25ce36f4 = 1;
                v6 = 0;
                do
                {
                    if (v6)
                        return 0;
                    v7 = *(cur);
                    if (v7)
                        v6 = v7(v7);
                    cur += 1;
                } while (cur < &g_7ff25ce1148);
                if (v6)
                    return 0;
                _initterm(&g_7ff25ce1128, &g_7ff25ce1130);
                g_7ff25ce36f4 = 2;
            }
            if (!v2)
                InterlockedExchange64(&g_7ff25ce36f8, 0);
            if (g_7ff25ce3718 && sub_7ff25ce1dcc(&g_7ff25ce3718))
                g_7ff25ce3718(a0, 2, a2);
            g_7ff25ce3140 = g_7ff25ce3140 + 1;
            return 1;
        }
        else
        {
            return 1;
        }
    }
}


