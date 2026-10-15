# TODO — Faithful 1:1 Decompilation and Clean-Room Reconstruction

This checklist tracks the remaining work required to move from the current
**analysis and evidence corpus** to a faithful, independently verified,
clean-room reconstruction of the original Windows 7 Defender application and
service stack represented by the files in `bin/`.

It is intentionally conservative: an item is complete only when it has
source-level, behavioral, and provenance evidence. Automated pseudocode,
resource inventories, or successful Linux model builds do **not** by themselves
count as completion.

Current baseline: 17 input files (15 AMD64 PE32+ images and two text
artifacts), 14 code-bearing images, 5 resource-only images, 14,752/18,638
candidate function starts with automated pseudocode, 21,180 controlled
instruction-emulation cases, and 12,977 structural/provenance checks passing.
See `analysis/report/final-report.md`, `analysis/report/progress.md`, and
`analysis/report/validation.md`.

## Phase 0 — Clean-room governance, legal, and provenance

Completed 2026-10-15. See
[`analysis/report/phase-zero-completion.md`](analysis/report/phase-zero-completion.md)
and the machine-readable governance receipt. Completion establishes controls;
it does not claim Microsoft authorization for original-file redistribution or
that a clean implementation team has started work.

- [x] Define and document the two-team clean-room boundary: one team performs
      binary analysis and writes specifications; a separate team implements from
      those specifications without access to the original binaries or decompiler
      output.
- [x] Record the exact provenance, hashes, acquisition source, and license/
      redistribution status of every file under `bin/`.
- [x] Obtain written authorization and scope for reverse engineering,
      reconstruction, testing, and redistribution of the resulting clean-room
      implementation.
- [x] Establish an evidence-only specification format so implementation work
      consumes reviewed behavior documents rather than raw decompiler output.
- [x] Separate analysis artifacts (`analysis/`, `src/*/pseudocode.c`) from
      implementation artifacts and prevent implementation builds from depending
      on unreviewed pseudocode.
- [x] Add a change-control process for manual behavior notes such as
      `src/MpAsDesc.dll/reviewed-behavior.md`.

## Phase 1 — Input preservation and structural baseline

- [ ] Keep every original `bin/` file byte-identical and SHA-256-identical to
      the recorded baseline; rerun `analysis/tools/validate_artifacts.py` after
      any repository change.
- [ ] Preserve original PE section bytes, resource bytes, debug GUID/age/path
      references, and relocation/unwind tables without modification.
- [ ] Confirm no packer, overlay, TLS directory, certificate table, or nested
      PE is present; if any is later found, add unpacking and provenance work
      before decompilation.
- [ ] Reconcile the mixed build versions (6.1.7601.23403 code images versus
      6.1.7600.16385 event/localized resources) and document which original
      build is the reconstruction target.
- [ ] Obtain matching PDBs from an authorized source for all 10 code-bearing
      images and record their GUID/age/path verification.
- [ ] Obtain or identify the missing runtime components: engine DLL, service
      executable, filter driver, signature/definition packages, quarantine
      containers, and matching test fixtures.

## Phase 2 — Complete static structural recovery

- [ ] Finish function-boundary recovery for every deferred, timed-out, and
      otherwise omitted candidate in `function-coverage.json` and
      `disassembly-coverage.json`.
- [ ] Resolve all indirect jumps in `indirect-jumps.json` and classify each as
      code, data, padding, or unresolved.
- [ ] Recover complete call graphs and xrefs for MSASCui.exe, MpSvc.dll, and
      MpClient.dll, including callback and virtual-dispatch targets.
- [ ] Re-run decompilation with a supported Ghidra/JDK or IDA installation and
      compare high-risk functions against angr output.
- [ ] Run REA native-provider analysis on original read-only inputs and reconcile
      discrepancies with the current pefile/angr/Capstone evidence.
- [ ] Complete Unicode string recovery; the current scan is intentionally
      ASCII-range-only.
- [ ] Decode all dialog, menu, accelerator, icon, version, and manifest
      resources semantically rather than only inventorying them.
- [ ] Finish MUI resource decoding, including checksum fields, redirection,
      language fallback, and locale mapping.
- [ ] Fully parse MpEvMsg.dll WEVT templates, including event IDs, payload
      field types, provider relationships, and localized message tables.
- [ ] Independently validate the bounded MSFT type-library decoder against
      Windows LoadTypeLib or Wine.

## Phase 3 — Interface, COM, RPC, and dynamic dispatch recovery

- [ ] Recover exact prototypes for all 78 exports and 1,000+ imports; current
      PE tables do not encode C prototypes.
- [ ] Reconstruct MpClient RPC/IDL/NDR procedure and type tables, including
      handle, scan, threat, cleanup, config, and notification contracts.
- [ ] Recover COM implementation vtables for MsMpCom coclasses and dispatch
      interfaces; resolve the three unresolved href type references (13, 25, 37).
- [ ] Reconstruct plugin callback structures, ownership, locking, state
      transitions, and dynamic module-handle provenance in MpSvc/MpClient.
- [ ] Verify every literal dynamic-lookup argument and module handle at runtime
      in a controlled Windows environment.
- [ ] Document all callback registration, notification, and elevation-handle
      flows used by MSASCui and MpCmdRun.

## Phase 4 — Behavioral specification

- [ ] Manually review and document every export, entry point, and externally
      reachable function, following the MpAsDesc reviewed-behavior model.
- [ ] Specify UI state machines, command dispatch, dialog semantics, and
      accessibility behavior for MSASCui.exe.
- [ ] Specify scan, threat, quarantine, cleanup, and update workflows end to
      end, including error paths and cancellation.
- [ ] Specify configuration schema, registry paths, notification behavior, and
      default actions.
- [ ] Specify communication/download behavior, including SOAP/WS-Security
      templates, URL construction, retry, and error handling.
- [ ] Specify real-time protection, engine interaction, and service lifecycle
      behavior, including driver and filter interactions where applicable.
- [ ] Specify all undocumented file formats: engine packages, definitions,
      quarantine containers, logs, caches, and persisted state.
- [ ] Resolve category meanings and original type names for MpAsDesc resolver
      tables; current names are analyst-assigned.

## Phase 5 — Compatibility build and ABI reconstruction

- [ ] Expand buildable compatibility modules only as behavior becomes specified
      and validated; do not add fabricated successful stubs.
- [ ] Provide ABI-compatible exports for every recovered module, including
      correct calling conventions, structures, and error codes.
- [ ] Reconstruct DllMain, module-handle tracking, WPP tracing, and MUI
      fallback behavior where applicable.
- [ ] Build MSASCui.exe and MpCmdRun.exe equivalents with matching command-line
      and UI behavior.
- [ ] Add CMake/build targets for each module only after its interface and
      behavior are specified.
- [ ] Keep Linux model builds clearly labeled as models, not Windows DLL
      replacements.

## Phase 6 — Runtime integration and Windows validation

- [ ] Set up an isolated Windows VM with matching OS version, services,
      registry baseline, and no network access unless explicitly testing
      network behavior.
- [ ] Validate loader behavior, COM activation, RPC interoperability, service
      installation/lifecycle, and UI actions.
- [ ] Compare reconstructed modules against originals using controlled inputs,
      registry snapshots, file-system snapshots, and network captures.
- [ ] Test real-time protection, scanning, threat handling, updates, and
      elevation flows in the isolated VM.
- [ ] Run malformed-input and boundary tests for reconstructed parsers and
      protocol handlers.
- [ ] Perform synchronization, concurrency, and error-path verification.
- [ ] Validate MUI and locale fallback behavior with pt-BR and other available
      language resources.

## Phase 7 — Clean-room implementation

- [ ] Implement each module from reviewed behavior specifications only, using
      the clean-room team boundary.
- [ ] Preserve original external behavior, including undocumented quirks
      required for compatibility.
- [ ] Implement all required file formats and persisted state exactly enough for
      interoperability with original components where needed.
- [ ] Implement registration and installation behavior, replacing placeholder
      substitution and verifying against original registry exports.
- [ ] Implement update, communication, and SpyNet/reporting behavior only within
      an explicitly scoped and isolated test objective.

## Phase 8 — Verification, release, and maintenance

- [ ] Achieve module-by-module behavioral equivalence evidence before claiming
      any module is reconstructed.
- [ ] Add automated regression tests for all recovered behaviors and
      instruction-emulation comparisons.
- [ ] Document every remaining deviation from original behavior.
- [ ] Publish a final reconstruction report with confidence levels and known
      limitations.
- [ ] Define maintenance and update policy for the clean-room implementation.
- [ ] Re-run full validation after any change to analysis or implementation.

## Definition of done for "faithful 1:1"

A module is not considered faithfully reconstructed until all of the following
are true:

- [ ] Every reachable function and export has reviewed behavior or an explicit,
      justified omission.
- [ ] Public and internal ABI boundaries are specified and tested.
- [ ] Resource, COM, RPC, and file-format behavior matches the original in an
      isolated Windows environment.
- [ ] No unverified pseudocode or inferred type is treated as source.
- [ ] Build, runtime, and behavioral evidence is recorded in the repository.
