# Manual behavior-note change control

**Policy:** BCC-001

**Version:** 1.0

**Effective date:** 2026-10-15

## Scope

This policy covers every `src/*/reviewed-behavior.md` file and any future manual
behavior note used to support a specification. Automatic reports and generated
pseudocode have separate reproducibility records and are never promoted by
renaming them “reviewed.”

The canonical note registry is `behavior-notes.json`. A visible control line at
the start of each note names its stable note ID, revision, lifecycle status, and
registry. The registry records the exact content SHA-256, original module
SHA-256, responsible identities, and latest behavior change request (BCR).

## Lifecycle states

- `draft` — incomplete analysis; not acceptable for specification release.
- `baseline-recorded` — pre-policy content has been brought under hash/revision
  control without retroactively claiming independent review.
- `analysis-reviewed` — evidence was checked by a reviewer other than the
  author, but clean-room expression review may remain outstanding.
- `approved-for-specification` — technical and expression reviews passed; the
  note may support a specification, but the note itself is never sent to Team B.
- `superseded` or `withdrawn` — retained for provenance and unavailable as
  current support.

A filename containing `reviewed-behavior` does not override its registry state.
The initial four notes are `baseline-recorded`, not retroactively peer-approved.
They may inform drafts; a released specification requires fresh independent
technical and expression review under ESF-001.

## Required change request

Every add, edit, split, merge, status change, or deletion requires a JSON BCR
under `governance/behavior-changes/`. Use
`behavior-change.template.json`. A BCR contains:

1. stable BCR and note IDs;
2. old and proposed revisions and content hashes;
3. exact module input identity;
4. reason and a behavior-level summary;
5. restricted evidence IDs consulted and confidence/unknowns affected;
6. specification requirements affected, or an explicit `none`;
7. author, technical reviewer, and expression reviewer decisions;
8. whether normative behavior changed; and
9. disposition and date.

Revision numbers always increase for content or status changes. Typographical
changes are still changes; their BCR may say `normative_change: false`.

## Review rules

- The author and technical reviewer must be different identities.
- Approval requires the technical reviewer to re-check cited restricted
  evidence, boundaries, errors, side effects, and uncertainty.
- Approval for specification use additionally requires an expression reviewer
  to reject copied code, pseudocode, disassembly expression, internal structure,
  and unsupported source-level names.
- Reviewers must be assigned in `team-register.json` and must not be Team B for
  the module.
- Conflicts and low-confidence findings stay explicit. A reviewer cannot resolve
  an unknown merely by approving prose.
- The sponsor approves scope/status but does not substitute for technical review
  unless separately assigned and qualified in the team register.

## Merge sequence

1. Create a proposed BCR with the old registry hash and next revision.
2. Edit the note and its visible control line.
3. Obtain review decisions in the BCR.
4. Update the registry with the new exact hash, revision, status, and BCR ID.
5. Update affected draft/released specifications. A change affecting a released
   requirement requires a new specification revision; never edit a released
   package silently.
6. Run `analysis/tools/validate_governance.py` and the artifact validator.
7. Merge the BCR, note, registry, and specification changes together.

Deletion removes neither history nor the registry entry: mark the note
`withdrawn`, record the final hash/path, and add the BCR. Emergency corrections
use the same sequence and must not be communicated ad hoc to Team B.

## Baseline adoption

BCR-0001 registers the four notes that predate BCC-001. Its disposition is
`baseline-record`, not `approved`. It establishes stable IDs and hashes without
fabricating independent reviewers for past work.
