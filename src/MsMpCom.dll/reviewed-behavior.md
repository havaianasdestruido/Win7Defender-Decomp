# Reviewed export behavior

> **BCC-001 control:** `NOTE-MSMPCOM-001` · revision **1** · status **baseline-recorded** · registry: `governance/behavior-notes.json`
Original preferred base `0x7ff28f20000`. `DllRegisterServer` and `DllUnregisterServer` are two exported names at **RVA 0x3b0c**. The bytes `b8 32 00 07 80 c3` implement:

```c
// Windows x64; exact 32-bit return value verified by instruction emulation.
uint32_t registration_entry(void) { return 0x80070032; }
```

The HRESULT-like value corresponds to ERROR_NOT_SUPPORTED, not success. No arguments are used. Other COM exports have automated pseudocode but have not been fully validated. The embedded REGISTRY resource's DllSurrogate declaration does not imply these exports register it.

`type-library.md` documents metadata-backed declarations for 19 methods across three dispatch interfaces, six coclass GUIDs and a five-value configuration enum. `config-types.h` expresses only those verified enum values; imported user-defined types remain explicitly unresolved. Automatic decompiler classes/layouts in `pseudocode.c` are not equivalent to type-library declarations.

No CMake module target is provided: building an empty or constant-return substitute would not implement the COM interfaces. The enum header is syntax-checked separately by the analysis validation tool.
