# pt-BR__MpAsDesc.dll.mui

Input: `bin/pt-BR/MpAsDesc.dll.mui`; SHA-256 `e216a0aa285b6cbe242af409ff1a27678652c9c30b065f85d1ea2fec748d3586`.

Native AMD64 PE32+; preferred image base `0x180000000`, entry RVA `0x0`. Addresses in automatic pseudocode refer to preferred-image virtual addresses, not runtime ASLR addresses.

- `interfaces.json`: exact imports, exports and IAT locations; these tables do not encode C prototypes.
- `resources.json`: resource tree with original RVA/file-offset/hash provenance and decoded RT_STRING, RT_MESSAGETABLE and RT_MANIFEST where present. Icons, dialogs, version, MUI and custom resources are inventoried, not all semantically decoded.
- Structural evidence and strings: `analysis/report/modules/pt-BR__MpAsDesc.dll.mui/`.
- Automated function recovery/decompilation, when code exists: see per-function coverage there. Pseudocode is not original source and inferred types are unverified.

## Compatibility constraints

Windows x64, little-endian, Microsoft x64 calling convention (RCX/RDX/R8/R9 integer arguments, shadow space, RAX return as appropriate); signatures vary. PE directory references are RVAs except the certificate table. Required imported DLLs are listed without assuming host implementations. No runtime equivalence or complete clean-room reimplementation is claimed. No DLL build target is supplied for opaque, unreconstructed interfaces.
