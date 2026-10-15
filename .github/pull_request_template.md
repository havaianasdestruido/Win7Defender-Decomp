## Summary

Describe the change, its evidence, and its scope.

## Validation

- [ ] `python3 analysis/tools/validate_governance.py --no-receipt`
- [ ] Relevant analysis/build/test checks pass.
- [ ] Files under `bin/` are unchanged.

## Governance impact

- [ ] No manual behavior note changed; **or** its new BCR, incremented revision,
      exact registry hash, reviewers, and affected specifications are included.
- [ ] No released specification changed in place; **or** a newly approved
      revision and release record are included.
- [ ] No implementation source reads or derives from `bin/`, `analysis/`,
      `src/`, drafts, pseudocode, or analyst notes.
- [ ] Any imported Team B source includes the released package digest, clean
      repository commit, dependency/fixture provenance, and non-access
      attestations.
- [ ] Authorization, licensing, privacy, safety, and redistribution scope remain
      accurate; any expansion has a new written approval.

## Reviewer declarations

List technical reviewer, clean-room expression reviewer, sponsor decision, and
any role conflicts. Use “not applicable” only with an explanation.
