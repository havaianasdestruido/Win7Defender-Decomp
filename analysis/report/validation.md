# Validation results

## Input preservation and structural consistency

**PASS**: 12977 recorded checks, 0 failed. `artifact-validation.json` is the machine-readable receipt.

- Every original file is SHA-256-identical to baseline and byte-identical to its Git HEAD object (see individual receipts).
- REA and pefile hashes, PE architecture/section counts/managed classification cross-checked; GNU objdump architecture independently compared.
- PE checksums recomputed; resource offset/size/hash bounds and PNG chunk CRCs checked. This is not Authenticode validation.
- Internal imported names/ordinals checked against the corresponding supplied export table. Import presence does not prove loader success or runtime invocation.
- Every unwind/entry/export seed is represented in function coverage. Emitted pseudocode VA comments are matched to ledger rows and line anchors normalized.

## Build and declaration checks

The portable `mpasdesc_model` C11 shared-library target compiled with GCC 12.2.0, Debug/PIC and `-Wall -Wextra -Werror -Wpedantic`. See `compatibility-rebuild.log`. CMake deliberately excludes unverified pseudocode. The recovered enum/table header syntax and width checks passed (`header-validation.log`). These are Linux model/declaration checks, not Windows DLL builds.

## Controlled instruction-emulation comparisons

**PASS**: 21,180 resolver cases plus six simple-export cases using Unicorn 2.1.4.

- Compare original resolver at MpAsDesc RVA `0x1768` with compiled independent C decision logic. Verify HRESULT-like result, output/no-write behavior, callback ID sequence, original handle argument and buffer capacity 2.
- Test every category 1..7 with values 0..1001 and 0x7fffffff/0x80000000/0xffffffff; negative/zero/8/maximum categories, null output, resource absent/present and nonempty pt-BR string availability.
- The model’s seven 12-byte table records match original bytes at RVA `0x11f0`.
- Original 64-bit module-handle accessors return controlled zero/nonzero globals. Original aliased registration entries in MpOAV and MsMpCom return `0x80070032`.
- Full test receipt, boundary samples, stub assumptions and outcome digest: `behavior-validation.json`. No real Windows process, registry changes, scans or network requests occurred.

## Known discrepancies and repaired analysis infrastructure

1. Angr’s first automatic MpAsDesc resolver output misplaced a fallback assignment in the out-of-range branch. Disassembly and emulation support the manual model; the automatic rendering remains labeled unverified rather than silently represented as equivalent C.
2. The initial four large-module runs returned empty call-site collections with default size-dependent angr caches and inflated candidate counts. Those outputs were superseded by reruns with function/CFG node/edge caches disabled. `cache-issue.json` preserves initial identities/settings/counts. This workaround restores call-site evidence; the precise upstream cache defect has not been fully diagnosed.
3. Angr initially created a temporary runtime database adjacent to MpSvc in bin/. Original bytes were untouched. The sidecar was removed from the input tree after completion and RTDB_BASE is now forced under ignored analysis/tools/runtime before importing angr.
4. Pseudocode line anchors had an initial one-line offset; validation now derives them from actual VA comment locations.
5. Rebuilding the same Debug model in a different directory changed the ELF bytes (debug/build metadata); behavior tests were rerun against the final src/.../build location rather than asserting binary identity.

## Coverage is bounded, not semantic equivalence

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

Total: 14,752/18,638 candidate starts emitted automated pseudocode; 8,576/12,091 original unwind starts emitted; 78/78 export names have corresponding output (aliases can share one function). Omissions: {'timeouts': 5, 'deferred': 3848, 'other_gaps': 33}.

All successful automatic outputs can still have incorrect types, control-flow structure or function boundaries. Exact timeout/error/deferred/non-recovered VA rows are retained. Resource-only images have no executable code target. No entire Defender module has been certified equivalent to the original.

## Validation not performed

- Windows loader/MUI behavior, real COM activation, RPC client/server interoperability, service installation/lifecycle, driver interaction, real-time monitoring and UI actions.
- Live downloads, telemetry/authentication or threat scanning; engine, driver, signature data and service host inputs are absent.
- Independent Windows LoadTypeLib/Wine validation of the bounded MSFT decoder.
- All-path symbolic verification, malformed-input fuzzing of reconstructed parsers, complete synchronization/error-path verification, full call-graph reachability, publisher trust and packed-code proof.
