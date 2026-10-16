# Win7Defender-Decomp

Clean-room-oriented reverse-engineering and reconstruction workspace for the
Windows 7 Defender binaries supplied under `bin/`.

This repository currently contains:

- Original, unmodified PE inputs under `bin/`.
- Generated structural evidence, reports, and tooling under `analysis/`.
- Analysis-exposed behavior models under `analysis/models/`.
- Recovered interfaces, resources, pseudocode, and manual analyst notes under
  `src/`.
- Evidence-only clean-room specification drafts under `specifications/`.
- A separate, currently empty clean-team handoff area under `implementation/`.
- Authorization, provenance, team-boundary, release, and change-control records
  under `governance/`.

No module is claimed to be fully reconstructed, buildable as a Windows DLL, or
behaviorally equivalent to the original. No current source is claimed to have
been authored by a non-exposed implementation team. See
`analysis/report/final-report.md` for the analysis evidence and limitations and
`analysis/report/phase-zero-completion.md` for the completed governance baseline.

## Reconstruction roadmap

The phased work required for a faithful 1:1 decompilation and clean-room
reconstruction is tracked in [`TODO.md`](TODO.md). That file is the canonical
todo list for this project and should be updated as phases are completed.

## Key references

- `governance/CLEAN_ROOM_POLICY.md` — Team A/Team B boundary and transfer gates.
- `governance/AUTHORIZATION.md` — sponsor authorization, scope, and exclusions.
- `governance/INPUT_PROVENANCE.md` — acquisition and per-file rights status.
- `analysis/report/phase-zero-completion.md` — Phase 0 completion evidence.
- `analysis/report/final-report.md` — consolidated analysis status and remaining work.
- `analysis/report/progress.md` — coverage and unresolved items.
- `analysis/report/validation.md` — analysis validation and unperformed tests.
- `analysis/tools/README.md` — tooling and reproducibility instructions.
