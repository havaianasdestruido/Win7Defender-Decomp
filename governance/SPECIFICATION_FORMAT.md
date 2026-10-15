# Evidence-only specification format

**Standard:** ESF-001

**Version:** 1.0

## Purpose

The specification is the only technical transfer from the analysis team to the
clean implementation team. It states reviewed, observable requirements and
uncertainty; it does not recreate the original source or expose the evidence
corpus. JSON is used so release checks can reject incomplete or unreviewed
records.

The normative schema is
`specifications/schema/specification.schema.json`. The prose rules below are
also mandatory where a schema cannot judge technical meaning.

## Required document model

Each specification contains:

- a stable specification ID, integer revision, lifecycle status, target module,
  and original-input SHA-256 identity;
- explicit included scope, excluded scope, platform constraints, and terms;
- implementation-neutral interface contracts;
- atomic requirements with stable IDs, confidence, evidence-claim IDs, inputs,
  outputs, errors, side effects, and externally observable ordering;
- unresolved questions and non-goals;
- Team A evidence claims stated as reviewed observations, without raw evidence;
- approval records for technical accuracy, clean-room expression, and scope;
  and
- release-package metadata when and only when status is `released`.

Normative words (`MUST`, `MUST NOT`, `SHOULD`, `MAY`) have their usual RFC 2119
meaning. One requirement must describe one independently testable behavior.

## Evidence claims

An evidence claim says what Team A concluded, its confidence, how it was
observed at a high level, and what remains unverified. Its ID maps to restricted
analysis evidence held by Team A. The clean package contains the reviewed claim
and ID, not the restricted map.

Permitted method classes are bounded static review, controlled black-box test,
controlled instruction emulation, platform-format metadata, and corroborated
public documentation. Automated decompiler output alone cannot support a
released requirement. Inference is labeled and cannot be silently promoted to
observation.

Every normative requirement has at least one evidence claim. Low-confidence or
conflicting evidence is expressed as an unknown or an explicitly scoped
compatibility choice, not a fabricated requirement.

## Expression rules

A transferred specification may contain behavior needed for compatibility,
including interface names, calling conventions, values, state transitions,
error results, required external interactions, wire/file layouts, and quirks
when those facts have passed review.

It must not contain:

- original or decompiler-generated code, copied control flow, or pseudocode;
- instruction bytes, disassembly, virtual addresses, RVAs, file offsets,
  register traces, decompiler temporaries, tool screenshots, or raw resources;
- internal structure chosen merely because the original used it;
- links or paths that give Team B access to `bin/`, `analysis/`, `src/`, Git
  history, analyst behavior notes, or restricted discussions;
- unverifiable claims phrased as requirements; or
- instructions to imitate defects that were not observed and approved as
  compatibility-relevant behavior.

Numeric errors, flags, identifiers, ABI layout values, and protocol constants
are allowed when they are themselves required behavior; the reviewer records
why they are not leaked implementation expression.

## Lifecycle

1. **Draft:** Team A creates a file under `specifications/drafts/`. Drafts are
   not implementation inputs.
2. **Technical review:** a Team A reviewer other than every listed author checks
   claims against restricted evidence and records approval.
3. **Expression review:** a different recorded reviewer checks the document for
   prohibited implementation expression and unnecessary disclosure.
4. **Scope approval:** the sponsor confirms that the specification fits the
   authorization record.
5. **Release:** status changes to `released`; the exact file is moved under
   `specifications/released/`; a clean exporter packages only released specs,
   schema, transfer instructions, and a digest manifest.
6. **Revision:** questions or validation failures return to Team A. A new
   integer revision supersedes the old one and repeats every approval. Released
   files are retained; they are not edited in place without a recorded revision.
7. **Retirement:** the sponsor may retire a revision without deleting its
   provenance.

Approval identities must be in `team-register.json`, and no clean implementer
for the module may author or review the specification. An empty reviewer roster
therefore prevents release.

## Implementation intake

Team B records the package manifest SHA-256 before opening a specification and
uses only that package plus its declared permitted public references. Questions
cite requirement IDs. Team A answers through a reviewed revision, never by
sending analyst notes or ad hoc code.

No file under `specifications/drafts/`, and no direct
`src/*/reviewed-behavior.md`, is a valid implementation dependency.
