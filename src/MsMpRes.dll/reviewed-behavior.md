# Reviewed module-handle getter

`GetMsMpResModuleHandle` is the sole export, RVA `0x1640`, preferred VA `0x7ff3a081640`. Its bytes `48 8b 05 a1 20 00 00 c3` load a 64-bit global at RVA `0x36e8` into RAX and return.

```c
// Manual pseudocode, Windows x64 ABI. HMODULE spelling inferred from export role.
uintptr_t GetMsMpResModuleHandle(void) { return saved_global_at_0x36e8; }
```

Controlled instruction emulation verifies full 64-bit return for zero and `0x123456789abcdef0`. This does not validate DLL initialization, module lifetime, WPP initialization, actual Windows module handles or resource localization.

There is no meaningful standalone compatibility DLL build target yet: reproducing an accessor without reproducing loader initialization and resource behavior would be misleading. `resource-details.json` records all 54 PNG headers/chunk CRC checks and the embedded AVI RIFF chunk inventory. Original resource bytes have not been duplicated into a replacement DLL.
