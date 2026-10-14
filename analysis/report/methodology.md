# Methodology and reproducibility

## Scope, evidence and trust

Analysis date: 2026-10-14 UTC. Checkout began at commit `33232708e2502dcd5cb9335157140a2fd8457e27`. The working branch remains `arena/b2cd6b59-win7defender-decomp`. Existing inputs were the only tracked files; none was overwritten. The tools open `bin/` read-only and validation compares every file both with its baseline SHA-256 and its original Git object.

Confidence categories:

1. **Observed bytes/metadata**: PE fields, import/export names, resource records, instruction encodings, version strings. Descriptive metadata is not authenticated truth about runtime behavior.
2. **Interpreted format**: types recovered by pefile or the bounded MSFT typelib decoder, with the format/reference and raw offsets retained.
3. **Automated inference**: angr function boundaries, CFG edges, pseudocode, prototypes and local structures. These can be wrong, including successful decompilations.
4. **Manually reviewed**: selected branches and register/data accesses cross-checked against disassembly, with scope stated in `src/*/reviewed-behavior.md`.
5. **Validated limited behavior**: compiled model compared with selected original instructions in emulation under documented state/API stubs. This is not full Windows compatibility.

Pseudocode is not proprietary original source. Compatibility code is analysis-informed reconstruction. This single-agent session does not establish personnel separation for a strict two-team clean-room claim. No original binaries, raw replacement resource bundles or downloaded tool distributions have been added to tracked source deliverables.

## Environment and versions

- Debian 12 Linux x86-64; Python 3.11.2; Node.js 22.22.3.
- GNU objdump/binutils 2.40; GCC 12.2.0; CMake 4.1.3 (Python wheel).
- pefile 2024.8.26; angr/cle/claripy/archinfo/pyvex 9.2.213; Capstone 5.0.6; Unicorn 2.1.4.
- REA npm package `rea-agents` **6.5.0**, installed locally with optional dependencies and lifecycle scripts disabled. `analysis/tools/package-lock.json` preserves npm integrity identities; `requirements.lock.txt` records resolved Python dependencies.
- angr initially failed importing because newly resolved bitstring 5.0.0 lacks `ConstBitStream`; pinning **bitstring 4.3.1** fixed this. The installation/fix logs preserve that actual failure and remedy. Unicorn was installed later for explicit selected-function emulation, not for operating-system emulation.
- Initially absent: Ghidra, Java, IDA, Radare2, Rizin, Wine, gdb, `file`, system CMake. objdump and Python parsing were available; parser functionality was reused rather than reimplementing PE loading/disassembly.

## REA assessment, actual contribution and limitations

Repository inspected: https://github.com/morluto/rea at commit **`fffb0741936067530d1ce9777461cd53e87398c2`** (shallow checkout excluded from Git under `analysis/tools/vendor/rea`). Reviewed README, `docs/installation.md`, `docs/cli.md`, `docs/ghidra-provider.md`, and CLI implementation files `src/cli/artifactCommands.ts` / `src/cli/managedCommands.ts`. The inspected main commit and installed published package are distinct identities; package CLI help and actual receipts verify the commands used, rather than assuming main's docs exactly describe an older release.

Verified interfaces used:

```sh
analysis/tools/node_modules/.bin/rea --help
analysis/tools/node_modules/.bin/rea providers --json
analysis/tools/node_modules/.bin/rea doctor --provider ghidra --json
analysis/tools/node_modules/.bin/rea inspect-artifact /absolute/path/to/file.dll --json
analysis/tools/node_modules/.bin/rea inspect-managed-artifact /absolute/path/to/file.dll --json
```

Both inspectors were run on **all 15 PE images** by `run_rea.py`. Saved JSON retains full evidence envelopes, provider IDs, SHA-256, coverage and limitations. REA artifact inspection contributed independent PE classification/identity/size and root artifact manifests. Its managed inspector independently decoded machine/section count/PE32+ and reported **not-managed, CLI directory absent**, excluding a CIL-decompiler workflow for these artifacts. `rea-crosscheck.json` compares machine/section counts/hashes with pefile. Artifact-graph “complete” means complete within that root/substep only, **not complete PE semantic analysis**.

One preliminary `inspect-go-binary` probe on MpOAV used REA's documented built-in ELF/PE/thin Mach-O build-info reader. It found no recognized Go build-info record; that negative result is not proof of compiler identity. We did not wastefully run it across all MSVC-like modules.

Native decompilation is **not a built-in provider-free REA operation**. It requires Hopper, Ghidra or IDA. The inspected Ghidra adapter accepts 12.1.x plus a compatible full host JDK (current bridge verified with 12.1.4/JDK21), `ps`, and a host native decompiler. The offline pwntools layout path is ELF-oriented and was not substituted for PE analysis. Managed CIL operations are unsuitable once CLI metadata is absent. Browser/Electron/Android/firmware/SQLite features are irrelevant to the discovered inputs.

`rea-ghidra-doctor.json` records missing engine/configuration. We attempted official GitHub release assets for Ghidra 12.1.4 (asset 579530646, 569649598 bytes) and Temurin JDK21 (asset 521122372, 207473347 bytes). Both redirected to `release-assets.githubusercontent.com` and failed with EOF; that host is outside this environment's outbound allowlist. No release binary was obtained or executed. We did not bypass the restriction, fabricate a Ghidra run, or claim REA generated the angr pseudocode. There is no configured Hopper/IDA fallback. REA agent-registration setup was unnecessary for direct CLI use and was not allowed to rewrite unrelated client configuration.

## Static pipeline

1. `inventory.py` enumerates every input, hashes bytes, parses PE with pefile, retains headers/directories/sections/imports/exports/relocations/unwind/TLS/load-config/debug/version/resource facts and parser warnings. It generates a compressed `objdump -x -d -w -M intel` listing per image.
2. Resource payloads are indexed by original offsets/hashes. Standard strings/messages/manifests are decoded. Additional `resource_details.py` parsing handles registry text, PNG/RIFF headers, partial MUI/WEVT prefixes and the supplied MSFT typelib.
3. REA independently inspects each PE without target execution. `run_rea.py` saves exact commands and exit codes.
4. `decompile.py` uses `angr.Project(path, auto_load_libs=False)`; `CFGFast(normalize=True, data_references=True, cross_references=True, function_prologues=True, function_starts=...)`. Seeds include all `.pdata` starts, all non-forwarded export addresses and the nonzero entry point. Defaults also perform indirect-jump resolution and heuristic scan. Calls, xrefs and indirect jumps are saved before decompilation.
5. A 240-second CFG deadline, 240-second decompilation budget per module and three-second per-function deadline bound the initial batch. Two isolated module workers run at once. Exports are attempted first, then entry, then increasing function size. Deadlines bound work rather than silently claiming completeness. The exact settings/elapsed times are in each coverage ledger; CPU load makes budget-based coverage nondeterministic.
6. One pseudocode file per code-bearing module avoids thousands of small files. Every candidate gets a status including non-recovered seed, deferred, timeout or exception. Names/types remain inferred. Call records report **call-block addresses**, not necessarily exact call-instruction offsets. Raw xref type codes follow angr (0=offset, 1=read, 2=write); source/target coordinates are explicit.
7. Manual review checks selected exports with objdump; it found a real bad branch restructuring in angr's resolver output. The corrected portable model is separate from the automatic file. Windows x64 ABI register conventions are used to interpret parameters, not invent unknown function signatures.
8. `static_calls.py` independently disassembles original `.pdata` ranges using Capstone. It records exact CALL/JMP instruction bytes/offsets and RIP-relative import slots, and traces literal LoadLibrary/GetProcAddress/GetModuleHandle arguments through a bounded branch-free local instruction window. This is static argument evidence, not runtime success or full dataflow proof. Results: `static-calls.json.gz`, `dynamic-lookup-sites.json`, `disassembly-coverage.json`.
9. `make_reports.py` consolidates findings, exact export addresses, dependency edges and coverage. `validate_artifacts.py` re-derives line anchors from emitted code and verifies inventory/evidence consistency.

### Corrections after the initial batch

Four large images initially returned empty call-site collections under angr's size-dependent caches. Those results were superseded by reruns with `cache_limits={'functions': None, 'cfg_nodes': None, 'cfg_edges': None}`. Initial counts/settings/output hashes are preserved in `cache-issue.json`; the exact upstream cache defect is not claimed diagnosed. The small-image default disables those caches already, so the smaller module results remain applicable.

Angr also created a temporary input-adjacent runtime database during the initial MpSvc run. It did not modify original binary bytes. That generated directory was removed from the input tree after the run; `RTDB_BASE` is now set to `analysis/tools/runtime/angr` before importing angr. The final validator checks the complete input file set and original contents.

SIGALRM deadlines are best-effort: a weakref-cleanup path logged an ignored Deadline during one MpClient attempt. A batch-level subprocess timeout remains the outer guard; exact recorded timings/statuses are authoritative, not a claim that each function was forcibly stopped at precisely three seconds. See run-history.md.

## Reproducing the saved pass

Run from the repository root. Network access is required only to install tools, not to analyze inputs.

```sh
python3 -m venv analysis/tools/.venv
analysis/tools/.venv/bin/pip install -r analysis/tools/requirements.lock.txt
npm ci --prefix analysis/tools --ignore-scripts --omit=optional
analysis/tools/.venv/bin/python analysis/tools/inventory.py
analysis/tools/.venv/bin/python analysis/tools/run_rea.py
analysis/tools/.venv/bin/python analysis/tools/resource_details.py
analysis/tools/.venv/bin/python analysis/tools/static_calls.py
analysis/tools/.venv/bin/python analysis/tools/batch_decompile.py --budget 240 --workers 2
analysis/tools/.venv/bin/python analysis/tools/validate_artifacts.py
analysis/tools/.venv/bin/python analysis/tools/make_reports.py
analysis/tools/.venv/bin/cmake -S src/MpAsDesc.dll -B src/MpAsDesc.dll/build -DCMAKE_BUILD_TYPE=Debug
analysis/tools/.venv/bin/cmake --build src/MpAsDesc.dll/build --verbose
analysis/tools/.venv/bin/python analysis/tools/validate_behavior.py --library src/MpAsDesc.dll/build/libmpasdesc_model.so
cc -std=c11 -Wall -Wextra -Werror -fsyntax-only analysis/tools/header_smoke.c
```

Native batch jobs can take minutes per module. Use a supervised background job, not repeated copies after a timeout. A module rerun overwrites its generated pseudocode/coverage, not manual source or original input. Example extended pass:

```sh
analysis/tools/.venv/bin/python analysis/tools/decompile.py --module MpSvc.dll --budget 1800 --function-seconds 30
```

If Ghidra/JDK are supplied later, the verified REA usage is:

```sh
export GHIDRA_INSTALL_DIR=/absolute/path/to/ghidra_12.1.4_PUBLIC
export JAVA_HOME=/absolute/path/to/jdk-21
analysis/tools/node_modules/.bin/rea doctor --provider ghidra --json
analysis/tools/node_modules/.bin/rea analyze "$PWD/bin/MpAsDesc.dll" --provider ghidra --json
analysis/tools/node_modules/.bin/rea decompile "$PWD/bin/MpAsDesc.dll" 0x7ff25ce1768 --provider ghidra --json
```

These are **next-step commands, not executed native-provider results**. Save their outputs under analysis/report/ and compare original-source identity before accepting results.

## Isolated behavior validation

`validate_behavior.py` loads original bytes into Unicorn at preferred image bases, sets up a bounded stack and return sentinel, and emulates only selected subroutines. It does not run the Windows loader, create a Defender process, scan files or contact any server. The resolver's WPP state is explicitly disabled; LoadStringW is a hook with controlled all-absent, all-present or observed-pt-BR-ID availability. The compiled portable resolver receives an equivalent probe callback. The test checks return values, output writes, call IDs and original LoadStringW handle/capacity arguments. Original module-handle accessors and constant registration returns are checked separately.

## External format reference

No installed utility covered the embedded standalone MSFT typelib, so a small bounded decoder supplements pefile. Format interpretation was cross-read from Wine (not a Windows proprietary source):

- [typelib.h](https://github.com/wine-mirror/wine/blob/892259ab87f9d2004df36486a1b94b0cd9f0e75f/dlls/oleaut32/typelib.h), SHA-256 `efca6340f50030d79a8c5024c1b9bc098defe925777325923bf9c16d6a22cf11`.
- [typelib.c](https://github.com/wine-mirror/wine/blob/968b915ea400be98a08b9b68c38ea4172b6f2ce3/dlls/oleaut32/typelib.c), SHA-256 `10ee530c71218c837582f9d94eaee70ae49dde1d3951dd48398ae5c9bfc80629`; specifically MSFT_GetTdesc, MSFT_DoFuncs, MSFT_DoVars and immediate constant interpretation.

Reference copies reside only in ignored vendor storage. No Windows LoadTypeLib/Wine runtime equivalence is claimed for our partial decoder. Complete byte-level outputs allow an independent tool to cross-check the interpretation.
