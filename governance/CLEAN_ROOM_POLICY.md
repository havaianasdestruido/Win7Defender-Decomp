# Two-team clean-room policy

**Policy ID:** CRP-001

**Version:** 1.0

**Effective date:** 2026-10-15

**Owner:** project sponsor

## 1. Purpose and claims

This policy separates observation of the supplied Windows Defender binaries
from implementation of compatible behavior. It is a process control, not a
legal opinion, a license from Microsoft, or proof that a future implementation
is non-infringing. A clean-room claim may be made only for a module whose role,
specification, transfer, implementation, and validation records satisfy this
policy.

The repository's existing generated pseudocode and compatibility model were
created by people with access to analysis evidence. They are analysis products,
not clean-team implementation.

## 2. Roles and disqualifying access

### Analysis team (Team A)

Team A may access `bin/`, `analysis/`, `src/`, disassembly, decompiler output,
resource bytes, and runtime observations. Team A:

1. records observations and uncertainty;
2. writes behavioral requirements without copying decompiler expressions or
   original implementation structure;
3. supplies evidence traceability to an analysis reviewer;
4. resolves implementation questions by revising the reviewed specification;
   and
5. never contributes implementation source for a module it analyzed.

Opening an original binary, generated pseudocode, disassembly, instruction
trace, analyst-only evidence map, or a history containing those artifacts makes
a person **analysis-exposed** for that module. Exposure is permanent for the
project unless counsel approves a documented exception; elapsed time is not a
cure.

### Clean implementation team (Team B)

Team B may access only:

- approved specification packages exported from `specifications/released/`;
- public platform documentation independently selected by Team B;
- build tools and test fixtures whose provenance is recorded; and
- black-box test results reduced to pass/fail and behavioral deltas that contain
  no original code, bytes, addresses, or decompiler-derived structure.

Team B must not access this repository, its Git history, original inputs,
analysis reports, `src/`, analyst behavior notes, or analyst-only discussions.
Before work, each implementer signs a module-specific non-access attestation and
is entered in the team register. Team B authors implementation and
implementation tests in a separate clean repository.

### Specification reviewers and transfer coordinator

A Team A reviewer checks traceability, uncertainty, and the absence of copied
implementation expression. Reviewers must be listed in `team-register.json`
with their assigned modules and `technical` and/or `expression` review kinds.
The technical and expression approvals for one release must come from different
people, neither of whom may be an author or Team B member for that module. Scope
approval comes from the registered sponsor. The transfer coordinator verifies
approvals, exports the package, records its digest, and delivers it without
adding technical content. These roles are not Team B roles for the same module.

### Validation team

Validation may execute originals in an authorized isolated environment and
compare them with Team B outputs. A validator who sees restricted evidence is
Team A for that module and communicates failures only through Team A. Team B
receives a revised approved specification or a sanitized test case, never raw
original output that reveals implementation expression.

### Sponsor

The sponsor controls scope, authorization, role assignments, exceptions, and
release decisions. Sponsorship does not make a person a clean implementer; the
access rules above still apply.

## 3. Per-module separation

Separation is tracked per module, but broad repository access is conservatively
recorded as exposure to all current modules. No individual may be both Team A
and Team B for the same module. Accounts, organizations, contractors, and AI
agents are recorded by stable identifier where available. Unassigned identities
are not implicitly approved.

The canonical assignments are in `team-register.json`. An empty Team B roster
means that governance is established but no strict clean-room implementation
work may begin.

## 4. Specification release gate

A specification can be transferred only when all of the following are true:

1. it conforms to `SPECIFICATION_FORMAT.md` and its schema;
2. every normative requirement has one or more Team A evidence IDs;
3. unknowns and non-goals are explicit;
4. an analyst other than the author completed technical review;
5. a clean-room expression reviewer found no original code, instruction bytes,
   addresses, decompiler variable names, or copied pseudocode;
6. the sponsor approved the declared scope;
7. the file is placed under `specifications/released/`; and
8. the exporter records all package SHA-256 hashes.

Draft specifications are not implementation inputs. Direct use of
`src/*/reviewed-behavior.md` is prohibited: those documents intentionally retain
analyst evidence and addresses.

## 5. Implementation import gate

Implementation arrives from Team B as a source archive plus:

- specification package digest;
- author identities and signed module attestations;
- clean repository commit identity;
- dependency and fixture provenance;
- build and test instructions; and
- a declaration that no original or analysis artifact was accessed.

The coordinator may place accepted source under `implementation/`. Builds must
not read `bin/`, `analysis/`, `src/`, draft specifications, reviewed-behavior
notes, or the analyst-only evidence map. Mechanical boundary checks supplement,
but do not replace, human review.

## 6. Communication protocol

Questions from Team B use observable, implementation-neutral language and cite
specification requirement IDs. Team A records the question, performs any needed
analysis, revises the specification, obtains review, and issues a new package.
Team A does not send code, pseudocode, disassembly, register-level explanations,
layout guesses, or screenshots of restricted tools.

## 7. Exceptions and incidents

There are no informal exceptions. A sponsor and legal reviewer must approve a
written exception before access, naming the module, person, material, purpose,
duration, and effect on clean-room claims.

Suspected exposure stops affected implementation work immediately. The incident
record must preserve what was accessed, by whom, when, and the affected modules.
The sponsor decides whether to discard work, reassign it, narrow claims, or seek
legal review. The project must not describe affected work as clean-room while an
incident is unresolved.

## 8. Required attestations

Before each module assignment, Team B attests:

> I have not accessed the module's original binaries, disassembly, decompiler
> output, analyst notes, analysis repository/history, or restricted discussion.
> I will implement only from the identified released specification package and
> permitted public references. I will report accidental exposure immediately.

At source handoff, Team B repeats the attestation and identifies every reference,
dependency, and fixture used. Records are retained with the implementation
release evidence.

## 9. Auditing and retention

Authorization, role assignments, input provenance, behavior-note revisions,
specification approvals, exported package manifests, implementation
attestations, incidents, and release decisions are version-controlled. Records
must not be rewritten to conceal superseded facts; corrections state what
changed and why.

A module may be called “clean-room implemented” only when the complete audit
trail exists and no unresolved exposure or authorization issue applies.
