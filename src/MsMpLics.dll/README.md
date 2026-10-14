# MsMpLics.dll

Input: `bin/MsMpLics.dll`; SHA-256 `8c7baf81986a1d39964b8ab74a188443987df6b84bb82470ea849e438234a10a`.

Native AMD64 PE32+; preferred image base `0x400000`, entry RVA `0x0`. Addresses in automatic pseudocode refer to preferred-image virtual addresses, not runtime ASLR addresses.

- `interfaces.json`: exact imports, exports and IAT locations; these tables do not encode C prototypes.
- `resources.json`: resource tree with original RVA/file-offset/hash provenance and decoded RT_STRING, RT_MESSAGETABLE and RT_MANIFEST where present. Icons, dialogs, version, MUI and custom resources are inventoried, not all semantically decoded.
- Structural evidence and strings: `analysis/report/modules/MsMpLics.dll/`.
- Automated function recovery/decompilation, when code exists: see per-function coverage there. Pseudocode is not original source and inferred types are unverified.

## Compatibility constraints

Windows x64, little-endian, Microsoft x64 calling convention (RCX/RDX/R8/R9 integer arguments, shadow space, RAX return as appropriate); signatures vary. PE directory references are RVAs except the certificate table. Required imported DLLs are listed without assuming host implementations. No runtime equivalence or complete clean-room reimplementation is claimed. No DLL build target is supplied for opaque, unreconstructed interfaces.
