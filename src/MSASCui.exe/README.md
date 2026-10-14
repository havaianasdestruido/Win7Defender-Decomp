# MSASCui.exe

Input: `bin/MSASCui.exe`; SHA-256 `aee55998074a62400809df27d276a3cac90210de4efcc5db88156de813098026`.

Native AMD64 PE32+; preferred image base `0x100000000`, entry RVA `0x9d374`. Addresses in automatic pseudocode refer to preferred-image virtual addresses, not runtime ASLR addresses.

- `interfaces.json`: exact imports, exports and IAT locations; these tables do not encode C prototypes.
- `resources.json`: resource tree with original RVA/file-offset/hash provenance and decoded RT_STRING, RT_MESSAGETABLE and RT_MANIFEST where present. Icons, dialogs, version, MUI and custom resources are inventoried, not all semantically decoded.
- Structural evidence and strings: `analysis/report/modules/MSASCui.exe/`.
- Automated function recovery/decompilation, when code exists: see per-function coverage there. Pseudocode is not original source and inferred types are unverified.

## Compatibility constraints

Windows x64, little-endian, Microsoft x64 calling convention (RCX/RDX/R8/R9 integer arguments, shadow space, RAX return as appropriate); signatures vary. PE directory references are RVAs except the certificate table. Required imported DLLs are listed without assuming host implementations. No runtime equivalence or complete clean-room reimplementation is claimed. No DLL build target is supplied for opaque, unreconstructed interfaces.
