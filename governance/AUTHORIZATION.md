# Project authorization and scope

**Record:** AUTH-2026-10-15-001

**Status:** active

**Approved:** 2026-10-15, America/Sao_Paulo (the approval interface did not
retain a wall-clock time)

**Sponsor:** `github:havaianasdestruido` (PatoFlamejanteTV), repository owner
and project sponsor

## Written attestation

In response to the Phase 0 authorization gate, the sponsor selected this exact
statement:

> I authorize this project to analyze and test the supplied files, produce a
> clean-room implementation, and redistribute that implementation, subject to
> applicable law; I attest I am authorized to approve this project work.

The approval was given interactively in the Arena repository session for branch
`arena/4e15e46d-win7defender-decomp`. This committed record is the durable
project copy of that authorization. It is not represented as a Microsoft
signature, a transfer of Microsoft rights, or advice from counsel.

## Authorized activities

Subject to the clean-room policy and applicable law, the project may:

1. preserve and hash the supplied files;
2. perform read-only static analysis and controlled, isolated dynamic testing;
3. document interfaces, resources, formats, and observed behavior;
4. create and review implementation-neutral behavioral specifications;
5. have a separate, non-exposed team implement those specifications;
6. compare the clean implementation with originals in an authorized isolated
   environment; and
7. publish and redistribute the project's resulting clean-team source and
   binaries after provenance, review, and release gates pass.

## Required controls

- Original inputs remain immutable and are used only in the analysis/validation
  environment.
- Network-facing, update, telemetry, SpyNet, malware-handling, driver, filter,
  and service-lifecycle tests require an explicit test plan and isolation review.
- Team B receives only approved specification packages and permitted public
  references.
- Each release must exclude Microsoft code, original resource payloads, names or
  marks beyond what is legally necessary for compatibility, secrets, signing
  material, definition packages, quarantine content, and original binaries.
- Safety, privacy, export-control, platform-license, trademark, patent,
  copyright, and local reverse-engineering requirements remain applicable.

## Explicit exclusions

This record does **not**:

- claim that the sponsor owns the copyrights in the supplied PE/MUI files;
- grant a license from Microsoft or any other third party;
- authorize redistribution of the original files under `bin/`;
- authorize bypassing access controls, signatures, licensing, or security
  protections;
- authorize deployment as a replacement security product; or
- waive independent legal review where required.

The bundled `bin/LICENSE` is provenance evidence only. Its applicability and
its author's authority are not assumed.

## Duration, amendment, and revocation

Authorization remains active until the sponsor revokes or supersedes it in
writing. Expansion beyond the activities above requires a new record. A change
in input source, ownership claim, intended distribution, jurisdictional risk,
or security-sensitive test scope pauses the affected work pending sponsor and,
where appropriate, legal review.

Corrections preserve this record in Git history and identify the superseding
record rather than silently rewriting the attestation.
