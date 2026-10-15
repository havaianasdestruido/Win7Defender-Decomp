# Phase 0 completion — governance, legal scope, and provenance

**Completed:** 2026-10-15

**Status:** governance controls established; automated governance validation
passes. No strict clean-team implementation has begun.

## Completion evidence

| Phase 0 requirement | Evidence |
|---|---|
| Define a two-team clean-room boundary | `governance/CLEAN_ROOM_POLICY.md` (CRP-001) defines Team A, Team B, reviewer/coordinator/validator roles, disqualifying access, per-module separation, sanitized transfer, attestations, incidents, and audit retention. `team-register.json` records currently exposed identities and an intentionally empty Team B roster. |
| Record provenance, hashes, source, and redistribution status for every input | `governance/input-provenance.json` individually records all 17 files, sizes, SHA-256, SHA-512, Git blob IDs, acquisition event, first/current Git records, copyright/license evidence, and redistribution status. `INPUT_PROVENANCE.md` records the sponsor-reported authorized Windows 7 installation/media source and every known chain-of-custody gap. |
| Obtain written authorization and scope | AUTH-2026-10-15-001 preserves the sponsor's exact written attestation and defines authorized analysis, isolated testing, specification, clean implementation, validation, and resulting-implementation redistribution. It explicitly does not grant Microsoft rights or authorize original-input redistribution. |
| Establish an evidence-only specification format | ESF-001, its JSON schema, template, and a non-released MpAsDesc example define atomic requirements, evidence claims, uncertainty, approval stages, prohibited expression, deterministic export, and hashed release records. |
| Separate analysis from implementation and prevent raw dependency | The analysis-exposed resolver model moved to `analysis/models/`; generated/decompiler material remains under `src/`; `implementation/` is a separate empty handoff area. The governance validator rejects implementation symlinks, executable payloads, forbidden dependencies, and build manifests under recovered `src/`. CI compiles the analysis model directly without `src/` pseudocode. |
| Control manual behavior-note changes | BCC-001 requires stable note IDs, increasing revisions, BCRs, independent technical/expression review, exact hashes, specification impact analysis, and retained superseded records. BCR-0001 registers all four pre-policy notes as `baseline-recorded` without inventing retroactive peer review. Pull-request base comparison enforces new BCR/revision records. |

## Mechanical verification

`python3 analysis/tools/validate_governance.py` records **198 passing checks and
zero failures** in `governance-validation.json`. The pull-request comparison
mode adds controls that changed manual notes carry a changed registry, a new BCR,
and an increased revision. The GitHub workflow runs both governance modes where
applicable and compiles the isolated analysis model and recovered declaration
smoke test.

Checks include all current input hashes and first Git objects, exact input and
behavior-note path sets, authorization references, role separation, note
content hashes/BCRs, specification reference integrity, release records, and
implementation dependency boundaries.

## Deliberate non-claims and next gates

Phase 0 completion means the governance **process and records** are in place. It
does not mean:

- Microsoft authorized or licensed redistribution of the original PE/MUI files;
- unknown source edition/media/extraction/custody facts were recovered;
- baseline behavior notes received retroactive independent review;
- any specification is released (the current example remains a draft);
- a non-exposed Team B member or transfer coordinator has been appointed; or
- any current model is a clean-room implementation.

These are enforced gates, not hidden omissions. Implementation cannot begin
under a strict clean-room claim until eligible people are registered and attest,
a specification receives independent reviews and sponsor scope approval, and
the exporter creates a verified `REL-*` package/record.
