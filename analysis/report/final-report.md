# Windows 7 Defender binary analysis — consolidated report

**Status: comprehensive input accounting and reproducible structural/automated analysis pass; full behavioral reconstruction remains incomplete.**

## Delivered

- All **17 input files** accounted for: **15 AMD64 PE32+ images** and two text artifacts. Fifteen module directories preserve original filename boundaries; three pt-BR satellites use a `pt-BR__` prefix.
- Original bin/ bytes verified against both baseline SHA-256 and original Git objects. No original binary was overwritten.
- Exact PE/section/import/export/resource/debug/relocation/unwind inventories; raw offset-linked strings; compressed GNU disassembly; independent Capstone call/jump sites; CFG calls/xrefs/indirect-jump evidence.
- Actual REA 6.5.0 execution on every PE: artifact inspection plus managed classification, with full evidence envelopes and independent hash/header cross-checks.
- Automated pseudocode for **14,752 of 18,638 candidate function starts** across 10 code-bearing images. These are candidate/inferred functions, not a count of understood source functions. Per-address omissions are explicit.
- Metadata-backed COM declarations for **19 methods**, three dispatch interfaces, six coclasses and five enum constants; **134 locally traced literal dynamic-API arguments** across the corpus.
- A manually reviewed, buildable MpAsDesc non-tracing resolver model. It is a portable behavior model, not a replacement Windows Defender DLL.
- **21,180 original-instruction/model comparison cases passed**, plus six simple-export cases. Structural/provenance checks: **12,977 checks, 0 failures**.

## Findings with strongest evidence

1. **The supplied code is native x64, not managed CIL.** REA’s managed inspector and pefile agree on the absent CLI directory. Ten images contain code; five are resource-only.
2. **MpClient is the main statically imported internal API surface.** MSASCui, MpCmdRun, MpSvc, MpCommu, MpRTP and MsMpCom import it. MpClient exports configuration, scan, threat, cleanup, handle and utility entry points; prototypes mostly remain unknown.
3. **There is a dynamic plugin/utility layer.** MpSvc contains direct GetProcAddress literal requests for all eight MpPlugin names. MpClient requests description/communication entry points, and MpOAV requests MpClient scan/config/handle functions. This is static evidence of lookup code, not proof that a runtime load succeeds.
4. **MpAsDesc’s resolver returns fallbacks successfully.** Valid categories are signed 1..7; value comparison is unsigned; a missing string or out-of-range value selects a fixed fallback and returns zero. Invalid category/null output returns 0x80070057. The original probes LoadStringW with a two-code-unit buffer.
5. **Registration exports are not installers.** MpOAV and MsMpCom each alias DllRegisterServer/DllUnregisterServer to a constant 0x80070032 return despite having REGISTRY resources.
6. **COM metadata materially improves interface recovery.** MsMpCom’s MSFT typelib carries factory, client utility and simple-configuration interfaces. Imported href types are kept unresolved, not guessed. The five configuration enum constants are not Windows REG_* values.
7. **The corpus mixes builds and lacks major runtime components.** Most native code reports 6.1.7601.23403; event/localized resources report 6.1.7600.16385. Engine DLL, service executable, filter driver, signatures and matching PDBs are absent. Version strings and filename references alone do not establish compatibility.

## REA contribution and constraint

REA was inspected, installed and executed, not merely cited. Its provider-free PE artifact/managed inspectors supplied independent identity/classification evidence. REA did not generate native pseudocode: Ghidra/Hopper/IDA were unavailable; official Ghidra/JDK downloads failed at a disallowed release-assets host. Angr, pefile, objdump, Capstone and Unicorn supplied clearly attributed fallbacks. See methodology.md and rea-limitations.md.

## Coverage summary

| Module | Candidate starts | Pseudocode | Unwind starts emitted / total | Export names emitted / total |
|---|---:|---:|---:|---:|
| MSASCui.exe | 5073 | 3665 | 2090 / 3349 | 0 / 0 |
| MpAsDesc.dll | 52 | 52 | 26 / 26 | 2 / 2 |
| MpClient.dll | 3286 | 2701 | 1509 / 2062 | 52 / 52 |
| MpCmdRun.exe | 824 | 815 | 528 / 537 | 0 / 0 |
| MpCommu.dll | 1783 | 1698 | 1032 / 1117 | 4 / 4 |
| MpEvMsg.dll | 0 | 0 | 0 / 0 | 0 / 0 |
| MpOAV.dll | 334 | 333 | 170 / 171 | 4 / 4 |
| MpRTP.dll | 1122 | 1106 | 705 / 721 | 8 / 8 |
| MpSvc.dll | 5799 | 4019 | 2307 / 3897 | 3 / 3 |
| MsMpCom.dll | 315 | 313 | 186 / 188 | 4 / 4 |
| MsMpLics.dll | 0 | 0 | 0 / 0 | 0 / 0 |
| MsMpRes.dll | 50 | 50 | 23 / 23 | 1 / 1 |
| pt-BR__MpAsDesc.dll.mui | 0 | 0 | 0 / 0 | 0 / 0 |
| pt-BR__MpEvMsg.dll.mui | 0 | 0 | 0 / 0 | 0 / 0 |
| pt-BR__MsMpRes.dll.mui | 0 | 0 | 0 / 0 | 0 / 0 |

A row’s emitted count is **not** a successful build, behavioral verification or original-source recovery claim. Candidate counts include inferred leaves and potential false positives. `.pdata` can split funclets. Seven unique export bodies have scoped original-instruction review indexed in `manual-review-index.json`; this does not certify automatic pseudocode. Tests cover only stated controlled conditions.

## Remaining work, in priority order

1. Supply a supported Ghidra/JDK or IDA installation and matching PDBs, then cross-check high-risk functions and decompiler discrepancies through REA. Prioritize the per-VA timeout/non-recovered/deferred rows, not undirected rescanning.
2. Recover MpClient/MpSvc NDR/RPC structures and request dispatch; confirm dynamic module-handle provenance; reconstruct plugin callback structures, ownership, locking and state transitions.
3. Resolve external COM typelib references, recover implementation vtables and compare type metadata with Windows LoadTypeLib or Wine. Finish MUI/WEVT/dialog/menu/accelerator decoding.
4. Obtain matching missing runtime artifacts and run controlled Windows VM comparisons. Keep tests offline unless network behavior is an explicitly isolated test objective.
5. Expand buildable compatibility modules only as behavior becomes specified and validated. Do not replace opaque DLLs with fabricated successful stubs.

## Navigation

- [Inventory](inventory.md) — all original identities and structural status.
- [Methodology](methodology.md) — versions, actual commands, configuration and reproducibility.
- [Module findings](module-analysis.md), [API map](api-map.md), [dependencies](dependencies.md), [formats](data-formats.md).
- [Progress and unresolved work](progress.md), [validation](validation.md), machine-readable per-function evidence in `modules/`.
- Recovered code/interfaces/resources: `../../src/`. Custom infrastructure: `../tools/README.md`.

No entire Windows Defender executable or DLL is claimed fully reconstructed, buildable or behaviorally equivalent. The saved project makes the verified subset and remaining work auditable.
