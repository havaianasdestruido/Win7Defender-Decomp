# Reviewed COM entry points

> **BCC-001 control:** `NOTE-MPOAV-001` · revision **1** · status **baseline-recorded** · registry: `governance/behavior-notes.json`
Evidence: `interfaces.json`, original disassembly in `analysis/report/modules/MpOAV.dll/objdump.txt.gz`, and selected instruction-emulation results in `behavior-validation.json`. Preferred base `0x7ff29100000`.

## Registration exports

`DllRegisterServer` and `DllUnregisterServer` **alias the same RVA 0x3ff4**:

```c
// Verified instructions: b8 32 00 07 80 c3
// Windows x64 ABI, 32-bit HRESULT-like result, no arguments used.
uint32_t registration_entry(void) { return 0x80070032; }
```

This corresponds to HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED). The original entry was emulated and returned that value. An embedded REGISTRY resource is therefore not evidence that these exports apply it.

## DllCanUnloadNow, RVA 0x3ea8

Observed: read a vtable pointer from object RVA `0xd210`, call slot `+0x18` with RCX pointing at that object, then return `1` if EAX is nonzero, otherwise `0`. This matches COM S_FALSE/S_OK encoding. Calling the virtual result a lock count is plausible, but the object constructor/vtable binding has not been verified. The object is initialized at runtime; static zero-filled bytes are not a usable vtable.

## DllGetClassObject, RVA 0x3ed4

Three input registers are saved: RCX (16-byte class identifier pointer), RDX (requested interface identifier), R8 (output pointer). These agree with the standard COM entry signature; pointer typedef spelling is not present in the binary.

Disassembly-backed control flow:

1. At RVA `0x3eed`, if the 32-bit global at `0xca30` is zero, return `0x8000ffff` (E_UNEXPECTED), before output-pointer handling.
2. At `0x3f09`, null output returns `0x80004003` (E_POINTER). Otherwise clear the output pointer at `0x3f18`.
3. Scan pointers from globals `0xca40` to `0xca48`. Ignore null entries and entries with zero callback at offset `0x10`. Compare the requested class identifier to four dwords through the entry's pointer at offset `0x00` (`0x3f44..0x3f63`).
4. On match, if cached pointer at entry `+0x20` is null, enter the critical section at `0xca50` using IAT `0x1080`; recheck cache under the lock. Invoke the callback at entry `+0x10` with RCX=entry `+0x18`, RDX=pointer at RVA `0x17c0`, R8=&entry `+0x20`; retain EAX. GUID bytes at `0x17c0` decode to `00000000-0000-0000-c000-000000000046` (IUnknown). Leave critical section via IAT `0x1088`.
5. If the cached interface exists, invoke its first vtable slot with the requested interface identifier and output pointer (QueryInterface-compatible shape); preserve its status.
6. A missing match, or null output with zero status, returns `0x80040111` (CLASS_E_CLASSNOTAVAILABLE). Otherwise return the retained status. Input GUID pointers are not explicitly null-checked here.

### Partially reconstructed entry layout

```c
// Analyst field names; based on accesses, not original declarations.
// Windows x64: pointers 8 bytes, apparent natural alignment 8.
struct ObjectMapEntry_observed_prefix {
    const void *class_guid;           // +0x00, 16 readable GUID bytes
    uint64_t unrecovered_08;          // +0x08, meaning unverified
    void *create_callback;            // +0x10, callable; inferred HRESULT-like return
    void *creation_context;           // +0x18, passed as RCX
    void *cached_unknown;             // +0x20, object with first virtual slot
}; // observed prefix 0x28; total record size NOT established
```

The full factory lifetime and concurrency contract are not established. No build target is provided for this incomplete COM implementation.

## Registry-resource evidence

`REGISTRY/101/1033` at file offset `0xc2a0` records CLSID `{2781761E-28E0-4109-99FE-B9D127C57AFE}`, `ThreadingModel=Both`, urlmon and shdocvw host settings, and `MaxFileSize=20971520`. Exact text and hash are in `resource-details.json`. These are declarative embedded settings, not proof of effective registry state or an enforced size limit.
