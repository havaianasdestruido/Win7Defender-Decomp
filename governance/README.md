# Clean-room governance

This directory contains the controls for the analysis-to-implementation
boundary. These controls apply to every module in this repository.

## Authoritative records

- [`CLEAN_ROOM_POLICY.md`](CLEAN_ROOM_POLICY.md) — roles, information boundary,
  transfer process, attestations, and incident handling.
- [`team-register.json`](team-register.json) — current role assignments and
  contamination status.
- `AUTHORIZATION.md` and `authorization.json` — sponsor authorization and its
  precise scope.
- `input-provenance.json` — file-by-file acquisition, identity, licensing, and
  redistribution record for `bin/`.
- `SPECIFICATION_FORMAT.md` — analyst-to-implementer specification contract.
- `BEHAVIOR_CHANGE_CONTROL.md` — review rules for manual behavior notes.

Machine-checkable controls live in `analysis/tools/validate_governance.py`.
Policy text prevails when a mechanical check is necessarily narrower than the
policy.

## Repository classification

This repository is the **analysis environment**. Access to it contaminates a
person for strict clean-room implementation of every module they inspect. A
clean implementer must not clone or browse this repository. Implementers receive
only a reviewed specification export produced by the release process.

`implementation/` is a transfer location for source authored in a separate
clean implementation environment. Its presence in this analysis repository
does not make this repository safe for implementers.
