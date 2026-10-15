# Clean-room specifications

This directory is the controlled analyst-to-implementer transfer surface defined
by ESF-001 in `governance/SPECIFICATION_FORMAT.md`.

- `schema/` — normative machine-readable format.
- `templates/` — non-normative starting documents.
- `drafts/` — analyst work; **never implementation input**.
- `released/` — approved specifications eligible for clean export.

A path under `released/` is necessary but not sufficient: status, approvals,
team assignments, source identity, and release metadata must all pass the
governance validator. Clean implementers receive an exported package and must
not browse this repository.

The current MpAsDesc resolver draft demonstrates the format only. It has no
independent reviewers or release metadata and is intentionally unavailable to a
clean implementation team.
