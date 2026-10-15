# Win7Defender-Decomp

Clean-room-oriented reverse-engineering and reconstruction workspace for the
Windows 7 Defender binaries supplied under `bin/`.

This repository currently contains:

- Original, unmodified PE inputs under `bin/`.
- Generated structural evidence, reports, and tooling under `analysis/`.
- Recovered interfaces, resources, pseudocode, and limited compatibility models
  under `src/`.

No module is claimed to be fully reconstructed, buildable as a Windows DLL, or
behaviorally equivalent to the original. See
`analysis/report/final-report.md` for the current evidence and limitations.

## Reconstruction roadmap

The phased work required for a faithful 1:1 decompilation and clean-room
reconstruction is tracked in [`TODO.md`](TODO.md). That file is the canonical
todo list for this project and should be updated as phases are completed.

## Key references

- `analysis/report/final-report.md` — consolidated status and remaining work.
- `analysis/report/progress.md` — coverage and unresolved items.
- `analysis/report/validation.md` — validation results and unperformed tests.
- `analysis/tools/README.md` — tooling and reproducibility instructions.
