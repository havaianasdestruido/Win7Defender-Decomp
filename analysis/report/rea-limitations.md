# REA suitability and limitation register

## Verified assessment and use

- Repository: morluto/rea, inspected commit `fffb0741936067530d1ce9777461cd53e87398c2`.
- Installed executable: local npm `rea-agents@6.5.0`; lockfile preserves artifact integrity. Runtime Node 22.22.3 meets the documented 22.x minimum.
- Consulted README, installation, CLI, Ghidra provider semantics, and the artifact/managed CLI registration source. Local `--help`, `providers --json` and `doctor --provider ghidra --json` were actually executed and retained.
- All 15 supplied PE images were processed by `inspect-artifact` and `inspect-managed-artifact`; exact commands, exit codes and SHA-256 comparisons appear in `rea-crosscheck.json`. Each full result lives under `modules/<filename>/rea-*.json`.

| Workflow | Applicability | Actual outcome / fallback |
|---|---|---|
| Provider-free artifact graph | Supported root PE recognition/identity | Ran on every image. Reports one root artifact; does not decode PE resources or infer native algorithms. Its coverage wording applies to the root inventory only. |
| Provider-free managed inspection | Supported PE/CLI classification | Ran on every image. Native/not-managed with no CLI directory. Machine and section count cross-checked with pefile. No CIL decompiler used. |
| Provider-free Go build metadata | Documented PE support | One preliminary MpOAV probe found no recognized record. Not treated as proof that a compiler is or is not Go. |
| Native decompilation/calls/types | Requires Ghidra, Hopper or IDA | No engine available. REA itself is not substituted for a disassembler. Native output comes from angr/objdump/Capstone, not REA. |
| Ghidra adapter | Native PE supported with provider prerequisites | Doctor reports missing configuration/engine. Official Ghidra/JDK release downloads failed at a redirected host outside the allowlist. No native-provider analysis was fabricated. |
| Offline pwntools layout | Documented ELF-oriented path | Not used as a PE parser. pefile + objdump + REA PE identity supplied structural cross-checks instead. |
| Managed reconstruction, JavaScript, Android, browser, SQLite, EVM, WASM | Not relevant to the observed native PE/resource corpus | Not invoked merely to inflate tool usage. |
| Resource extraction and Windows execution | No admitted general-purpose Windows runtime established here | pefile/resource supplements handle static resource structure; Unicorn emulates selected subroutines with explicit stubs. No full Windows behavior claimed. |

## Constraints and reproducibility

The native provider is blocked by environment prerequisites, **not a claim that REA cannot analyze PE**. The intended recovery is to supply Ghidra 12.1.x and a compatible full JDK with the host decompiler, set `GHIDRA_INSTALL_DIR`/`JAVA_HOME`, verify `rea doctor`, and use the documented native CLI. There is no need to reinstall client integrations for the current direct-CLI workflow.

No GitHub release binary was successfully downloaded, so there is no installed Ghidra/JDK version to report as used. Release metadata was inspected through the GitHub API; downloads failed on `release-assets.githubusercontent.com`. Network restrictions were not bypassed.

REA’s static root manifests do not prove resource inventory completeness, signatures, symbol authenticity, packer absence, behavior or dependency resolution. Independent receipts identify exactly which facts were cross-checked. Missing native PDBs and Windows runtime components are separate constraints that installing REA alone would not solve.
