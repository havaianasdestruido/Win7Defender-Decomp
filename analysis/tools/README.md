# Analysis tooling

All custom tooling lives here. Run from the repository root; scripts derive the root from their own location and never intentionally write original inputs. Outputs are regenerated only under `analysis/report/` and the corresponding generated `src/<module>/` files. Do not run duplicate decompilers for the same module concurrently.

## Dependencies

- Python 3.11 virtual environment: `python3 -m venv analysis/tools/.venv`; `analysis/tools/.venv/bin/pip install -r analysis/tools/requirements.lock.txt`.
- Node 22.19+ in the supported 22.x line (used 22.22.3): `npm ci --prefix analysis/tools --ignore-scripts --omit=optional`.
- GNU objdump 2.40 and a C compiler/make for the compatibility model.
- Exact top-level versions and restrictions are documented in `analysis/report/methodology.md`. Angr needs bitstring 4.3.1, not the incompatible 5.0.0 release encountered initially.
- `vendor/`, `runtime/`, `.venv/`, `node_modules/` are ignored downloaded/runtime dependencies, not deliverables. No tool binaries are committed.

## Scripts and interfaces

| Tool | Purpose / input | Output | Key limitations |
|---|---|---|---|
| `inventory.py` | Recursively inspect all `bin/` files using pefile and objdump | inventory JSON/Markdown; module metadata/strings/disassembly; `src/*/interfaces.json`, resources and generated READMEs | Not a general unpacker, not full Unicode-string discovery; resource semantic decoding is selective; preserves pefile warnings |
| `run_rea.py` | Use installed REA 6.5.0 CLI on every PE in inventory | full REA artifact/managed evidence per module and `rea-crosscheck.json` | Root manifests and managed identity only; no native-provider decompilation without external engine |
| `resource_details.py` | Bounded supplementary parsing of resource bytes indexed by pefile | `src/*/resource-details.json` | Supplied MSFT typelib, PNG CRC/IHDR, RIFF top-level chunks, registry text, partial MUI/WEVT; not a universal format decoder |
| `decompile.py --module NAME --budget 240 --function-seconds 3` | Original PE + `.pdata`/export/entry roots, angr CFG/decompiler | module pseudocode, per-function ledger, calls/xrefs/indirect jumps | Inferred boundaries/types and imperfect CFG; explicit deadlines and error states; no OS execution |
| `batch_decompile.py --budget 240 --workers 2 [--module NAME ...]` | Supervise isolated per-module decompiler subprocesses; optional restricted list | per-module logs and exact invocation receipts | Per-process outer timeout; bounded automatic recovery does not imply complete semantics |
| `static_calls.py` | Independent Capstone decode within original `.pdata` ranges | `static-calls.json.gz`, `disassembly-coverage.json`, `dynamic-lookup-sites.json` per module | No reachability proof; no arbitrary computed targets; API string arguments traced only through a bounded branch-free local window |
| `make_reports.py` | Consolidate saved inventory, coverage and resource facts | required module/API/dependency/progress reports, DOT/JSON graph, COM metadata declarations | Does not rerun analysis; run after worker completion to avoid stale counts |
| `validate_artifacts.py` | Rehash inputs, compare Git objects, independent PE/REA/objdump checks, resources, imports and ledgers | `artifact-validation.json`; normalizes emitted pseudocode line anchors | Checks consistency/provenance, not semantic equivalence or cryptographic publisher trust |
| `validate_governance.py [--base-ref REF] [--no-receipt]` | Check authorization, approved-baseline provenance, full ESF schema conformance, team/approver separation, behavior-note revisions, immutable release history and every implementation handoff file | `governance-validation.json` unless suppressed; nonzero exit on failure | Mechanical policy checks supplement human/legal review; base-ref mode also blocks input changes, note-ledger erasure, and released-spec/record deletion |
| `test_governance.py` | Exercise schema completeness, reviewer roles, RVA filtering, shell-helper scanning, release-batch selection and fixed input baseline | unittest result on stdout | Focused regressions supplement the full repository validator |
| `export_specifications.py --release-id REL-ID --recipient ID --coordinator ID --output FILE.zip` | Package only the requested approved release batch/schema for a registered clean implementer | Deterministic ZIP plus analyst-side release record with exact hashes | Refuses incomplete schemas, expression leakage, unregistered approvers/identities, module assignment mismatches and reused release IDs |
| `validate_behavior.py --library PATH` | Compare compiled portable resolver with bounded original-instruction emulation | `behavior-validation.json` and stdout summary | WPP disabled; LoadStringW stubbed; no Windows loader/service/MUI behavior; 21,180 resolver cases plus six accessor/constant-return cases |
| `header_smoke.c` | C11 syntax/static-width checks for reconstructed declarations | use `cc -std=c11 -Wall -Wextra -Werror -fsyntax-only analysis/tools/header_smoke.c` | Compile-time layout/constants only; not DLL compatibility |
| `finalize_reports.py` | Summarize completed evidence/build/test receipts | validation and final report | Reports partial work explicitly; cannot substitute for missing runs |

Governance validation has no third-party Python dependency:

```sh
python3 analysis/tools/validate_governance.py
# In a pull request, also compare note revisions with the base commit:
python3 analysis/tools/validate_governance.py --base-ref origin/main --no-receipt
```

Specification export intentionally fails until released specifications, a Team B
recipient, and a transfer coordinator are all registered.

Example module command:

```sh
analysis/tools/.venv/bin/python analysis/tools/decompile.py --module MpOAV.dll --budget 240 --function-seconds 3
```

Optional `--cfg-seconds N` changes the initial CFG deadline. `--seeded` disables prologue/linear smart scanning while retaining all unwind/export/entry roots and reachable calls; this reduces heuristic discovery and can miss unreferenced leaf functions. These options are available for follow-up, not evidence that every configuration was run.

### Cache-side-effect guard

Angr's default large-image cache can create an `_angr_rtdb` directory adjacent to an input. The initial MpSvc run did so without changing any original file; the generated sidecar was removed from `bin/` after the process completed. It is now prevented by setting `RTDB_BASE` to ignored `analysis/tools/runtime/angr` **before importing angr**. The corrected implementation additionally disables `functions`, `cfg_nodes` and `cfg_edges` cache limits because the initial cache-backed runs returned empty call-site collections for four large modules. Their old result identities/summary counts are retained in `cache-issue.json`; corrected reruns replace their generated artifacts. No original input file was modified.

### Reusing existing software instead of duplicating it

PE, relocation, resource-tree and exception parsing use pefile; disassembly uses GNU objdump and Capstone; CFG/pseudocode uses angr; isolated execution uses Unicorn. Custom code glues these tools together, decodes resource formats not covered by those utilities, and records evidence/validation. REA's verified published CLI is used directly, not a guessed Python API or an invented generic decompiler command. Wine TYPELIB source references are pinned in methodology; custom decoder outputs remain independently checkable against raw resource offsets.

### Output boundaries

- Generated pseudocode and recovered resource/interface definitions: `src/`.
- Analysis-exposed behavior models and their CMake files: `analysis/models/`.
- Clean-team source, once independently authored and accepted: `implementation/`.
- All custom code/config/dependency locks: this directory.
- Evidence, logs, validation receipts and narrative findings: singular `analysis/report/`.
- Analysis-model build products: ignored `analysis/models/MpAsDesc.dll/build/`.
- Original executable/resource inputs: `bin/`, unchanged.

`inventory.py` rewrites generated module READMEs; hand-written behavioral notes are separate and preserved. `decompile.py` replaces the generated pseudocode/ledger for a module. `make_reports.py` regenerates consolidated reports and typelib declarations. Avoid hand-editing generated files when the intended change belongs in a generator. Narrative methodology/data-format/REA-limitations documents are maintained separately.
