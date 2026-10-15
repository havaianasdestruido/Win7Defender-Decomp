# Clean implementation handoff

This directory is reserved for source authored by Team B in a separate clean
repository and accepted through CRP-001's implementation import gate. It is
currently empty: no clean implementation team has been appointed and no
specification has been released.

Code here may depend only on the exact released specification package recorded
at handoff, independently selected permitted public references, and clean-team
dependencies/fixtures with provenance. It must not read, include, generate from,
or link against:

- `bin/`;
- `analysis/`, including analysis behavior models;
- `src/`, including generated pseudocode and reviewed-behavior notes;
- `specifications/drafts/`; or
- repository Git history or other analyst-only material.

Clean implementers must not browse this analysis repository. The transfer
coordinator imports their separately authored source and attestations after
boundary validation. Presence under this directory alone is not proof of
clean-room provenance.
