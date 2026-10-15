#!/usr/bin/env python3
"""Validate Phase 0 clean-room governance with only the Python standard library."""

from __future__ import annotations

import argparse
import hashlib
import json
import re
import subprocess
from datetime import date
from pathlib import Path
from typing import Any

ROOT = Path(__file__).resolve().parents[2]
GOVERNANCE = ROOT / "governance"
SPECIFICATIONS = ROOT / "specifications"
IMPLEMENTATION = ROOT / "implementation"
REPORT = ROOT / "analysis" / "report" / "governance-validation.json"
APPROVED_INPUT_COMMIT = "9638320b682dfbed9eb0455750d78fac384b6598"

REQUIRED_SPEC_KEYS = {
    "schema_version",
    "standard",
    "specification_id",
    "revision",
    "status",
    "title",
    "module",
    "source_identity",
    "authorization_record",
    "scope",
    "platform_constraints",
    "terms",
    "interfaces",
    "requirements",
    "evidence_claims",
    "unknowns",
    "permitted_public_references",
    "authors",
    "approvals",
    "release",
}
IMPLEMENTATION_BUILD_NAMES = {
    "CMakeLists.txt", "Makefile", "meson.build", "build.ninja", "package.json",
    "pyproject.toml", "Cargo.toml", "go.mod", "build.gradle", "pom.xml",
}
FORBIDDEN_IMPLEMENTATION_PATTERNS = {
    re.compile(
        r"(?m)(?:^|[\s\"'`(=,:])(?:\.\.?/)*(?:bin|analysis|src)/"
        r"|/Win7Defender-Decomp/(?:bin|analysis|src)/"
        r"|(?:\$\{?[A-Za-z_][A-Za-z0-9_]*\}?|%[A-Za-z_]+%)/(?:bin|analysis|src)/",
        re.IGNORECASE,
    ): "original, analysis, or recovered artifact path",
    re.compile(
        r"(?m)(?:^|[\s\"'`(=,:])(?:\.\.?/)*specifications/drafts(?:/|\b)",
        re.IGNORECASE,
    ): "unreleased specification path",
    re.compile(r"\bpseudocode\.c\b", re.IGNORECASE): "generated pseudocode",
    re.compile(r"\breviewed-behavior\b", re.IGNORECASE): "analyst-only behavior note",
}
FORBIDDEN_RELEASE_PATTERNS = {
    re.compile(r"\bpseudocode\b", re.IGNORECASE): "pseudocode",
    re.compile(r"\bdisassembl(?:y|ies|ed|er)\b", re.IGNORECASE): "disassembly",
    re.compile(r"\binstruction bytes?\b", re.IGNORECASE): "instruction bytes",
    re.compile(r"\bvirtual addresses?\b", re.IGNORECASE): "virtual address",
    re.compile(r"\brvas?\b", re.IGNORECASE): "RVA",
    re.compile(r"\bfile offsets?\b", re.IGNORECASE): "file offset",
    re.compile(r"\bregister traces?\b", re.IGNORECASE): "register trace",
    re.compile(r"\breviewed-behavior\b", re.IGNORECASE): "analyst behavior note",
    re.compile(r"(?:^|[\s\"'`(=,:])(?:\.\.?/)*(?:analysis|src|bin)/", re.IGNORECASE):
        "restricted repository path",
}
FORBIDDEN_RELEASE_KEYS = {
    "rva", "virtual_address", "virtualaddress", "file_offset", "fileoffset",
    "instruction_bytes", "disassembly", "pseudocode",
}
CONTROL_RE = re.compile(
    r"BCC-001 control:\*\* `(?P<id>NOTE-[A-Z0-9-]+)` · revision \*\*(?P<revision>\d+)\*\* "
    r"· status \*\*(?P<status>[a-z-]+)\*\*"
)
HEX64_RE = re.compile(r"^[0-9a-f]{64}$")


def load_json(path: Path) -> Any:
    return json.loads(path.read_text(encoding="utf-8"))


def digest(path: Path, algorithm: str) -> str:
    h = hashlib.new(algorithm)
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            h.update(chunk)
    return h.hexdigest()


def git(*args: str, check: bool = True) -> subprocess.CompletedProcess[bytes]:
    return subprocess.run(
        ["git", *args], cwd=ROOT, check=check, capture_output=True
    )


def assigned_to_module(member: dict[str, Any], module: str) -> bool:
    modules = member.get("modules", [])
    return "*" in modules or module in modules


def _schema_type_matches(value: Any, expected: str) -> bool:
    """Implement the JSON Schema primitive types used by ESF-001."""
    if expected == "null":
        return value is None
    if expected == "object":
        return isinstance(value, dict)
    if expected == "array":
        return isinstance(value, list)
    if expected == "string":
        return isinstance(value, str)
    if expected == "boolean":
        return isinstance(value, bool)
    if expected == "integer":
        return isinstance(value, int) and not isinstance(value, bool)
    if expected == "number":
        return isinstance(value, (int, float)) and not isinstance(value, bool)
    return False


def _resolve_local_ref(root_schema: dict[str, Any], reference: str) -> dict[str, Any]:
    if not reference.startswith("#/"):
        raise ValueError(f"ESF schema uses unsupported non-local reference: {reference}")
    current: Any = root_schema
    for raw in reference[2:].split("/"):
        token = raw.replace("~1", "/").replace("~0", "~")
        current = current[token]
    if not isinstance(current, dict):
        raise ValueError(f"ESF schema reference does not resolve to an object: {reference}")
    return current


def json_schema_errors(
    value: Any,
    schema: dict[str, Any],
    root_schema: dict[str, Any] | None = None,
    path: str = "$",
) -> list[str]:
    """Validate the JSON Schema keywords used by specification.schema.json.

    Keeping this small standards-based evaluator in-tree lets the governance gate
    consume the declared schema directly without a network install in CI. Unknown
    schema keywords that affect validation are rejected so the schema cannot grow
    beyond the evaluator silently.
    """
    root = schema if root_schema is None else root_schema
    if "$ref" in schema:
        return json_schema_errors(value, _resolve_local_ref(root, schema["$ref"]), root, path)

    supported = {
        "$schema", "$id", "$defs", "title", "description", "type", "const",
        "enum", "required", "properties", "additionalProperties", "items",
        "minItems", "minLength", "minimum", "pattern", "format",
    }
    unsupported = sorted(set(schema) - supported)
    if unsupported:
        return [f"{path}: unsupported schema keywords: {', '.join(unsupported)}"]

    errors: list[str] = []
    expected_types = schema.get("type")
    if expected_types is not None:
        candidates = [expected_types] if isinstance(expected_types, str) else expected_types
        if not isinstance(candidates, list) or not all(isinstance(item, str) for item in candidates):
            return [f"{path}: schema type must be a string or string array"]
        if not any(_schema_type_matches(value, item) for item in candidates):
            return [f"{path}: expected type {' or '.join(candidates)}, got {type(value).__name__}"]

    if "const" in schema and value != schema["const"]:
        errors.append(f"{path}: expected constant {schema['const']!r}")
    if "enum" in schema and value not in schema["enum"]:
        errors.append(f"{path}: value {value!r} is not in the allowed enum")

    if isinstance(value, dict):
        required = schema.get("required", [])
        for name in required:
            if name not in value:
                errors.append(f"{path}: missing required property {name!r}")
        properties = schema.get("properties", {})
        for name, child in properties.items():
            if name in value:
                errors.extend(json_schema_errors(value[name], child, root, f"{path}.{name}"))
        if schema.get("additionalProperties") is False:
            for name in sorted(set(value) - set(properties)):
                errors.append(f"{path}: additional property {name!r} is not allowed")

    if isinstance(value, list):
        minimum_items = schema.get("minItems")
        if minimum_items is not None and len(value) < minimum_items:
            errors.append(f"{path}: expected at least {minimum_items} items")
        if "items" in schema:
            for index, item in enumerate(value):
                errors.extend(json_schema_errors(item, schema["items"], root, f"{path}[{index}]"))

    if isinstance(value, str):
        minimum_length = schema.get("minLength")
        if minimum_length is not None and len(value) < minimum_length:
            errors.append(f"{path}: expected length of at least {minimum_length}")
        pattern = schema.get("pattern")
        if pattern is not None and re.search(pattern, value) is None:
            errors.append(f"{path}: value does not match pattern {pattern!r}")
        if schema.get("format") == "date":
            try:
                date.fromisoformat(value)
            except ValueError:
                errors.append(f"{path}: value is not an ISO calendar date")

    if isinstance(value, (int, float)) and not isinstance(value, bool):
        minimum = schema.get("minimum")
        if minimum is not None and value < minimum:
            errors.append(f"{path}: value is below minimum {minimum}")
    return errors


def release_expression_violations(value: Any, path: str = "$") -> list[str]:
    """Find analyst-only implementation expression forbidden by ESF-001."""
    violations: list[str] = []
    if isinstance(value, dict):
        for key, child in value.items():
            normalized = re.sub(r"[^a-z0-9]+", "_", str(key).lower()).strip("_")
            if normalized in FORBIDDEN_RELEASE_KEYS:
                violations.append(f"{path}: forbidden field name {key!r}")
            violations.extend(release_expression_violations(child, f"{path}.{key}"))
    elif isinstance(value, list):
        for index, child in enumerate(value):
            violations.extend(release_expression_violations(child, f"{path}[{index}]"))
    elif isinstance(value, str):
        for pattern, meaning in FORBIDDEN_RELEASE_PATTERNS.items():
            if pattern.search(value):
                violations.append(f"{path}: contains forbidden {meaning}")
    return violations


def implementation_reference_violations(data: bytes) -> list[str]:
    text = data.decode("utf-8", errors="replace")
    return [
        reason
        for pattern, reason in FORBIDDEN_IMPLEMENTATION_PATTERNS.items()
        if pattern.search(text)
    ]


def release_approval_errors(spec: dict[str, Any], team: dict[str, Any]) -> list[str]:
    """Validate role, assignment, and independence for all release approvals."""
    errors: list[str] = []
    module = str(spec.get("module"))
    authors = {item.get("id") for item in spec.get("authors", [])}
    analysis_ids = {item.get("id") for item in team.get("analysis_team", [])}
    implementation_ids = {
        item.get("id") for item in team.get("clean_implementation_team", [])
    }
    reviewer_map = {
        item.get("id"): item for item in team.get("specification_reviewers", [])
    }
    approvals = spec.get("approvals", {})
    technical = approvals.get("technical", [])
    expression = approvals.get("expression", [])
    scope = approvals.get("scope", [])
    if not technical or not expression or not scope:
        errors.append("technical, expression, and scope approvals are all required")
    technical_ids = {item.get("reviewer", {}).get("id") for item in technical}
    expression_ids = {item.get("reviewer", {}).get("id") for item in expression}
    scope_ids = {item.get("reviewer", {}).get("id") for item in scope}
    reviewers = technical_ids | expression_ids
    if not reviewers.isdisjoint(authors | implementation_ids):
        errors.append("technical/expression reviewers must differ from authors and Team B")
    if not technical_ids or not all(
        reviewer_id in reviewer_map
        and reviewer_id in analysis_ids
        and "technical" in reviewer_map[reviewer_id].get("review_kinds", [])
        and assigned_to_module(reviewer_map[reviewer_id], module)
        for reviewer_id in technical_ids
    ):
        errors.append("technical reviewers must be registered and assigned for the module")
    if not expression_ids or not all(
        reviewer_id in reviewer_map
        and reviewer_id in analysis_ids
        and "expression" in reviewer_map[reviewer_id].get("review_kinds", [])
        and assigned_to_module(reviewer_map[reviewer_id], module)
        for reviewer_id in expression_ids
    ):
        errors.append("expression reviewers must be registered and assigned for the module")
    if not technical_ids.isdisjoint(expression_ids):
        errors.append("technical and expression reviewers must be different identities")
    sponsor_id = team.get("sponsor", {}).get("id")
    if not sponsor_id or scope_ids != {sponsor_id}:
        errors.append("scope approval must come from the registered sponsor")
    return errors


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--base-ref",
        help="also enforce that changed notes have a new BCR relative to this Git ref",
    )
    parser.add_argument(
        "--no-receipt", action="store_true", help="do not rewrite the validation receipt"
    )
    args = parser.parse_args()

    checks: list[dict[str, Any]] = []
    failures: list[dict[str, Any]] = []

    def check(name: str, passed: bool, detail: Any = None) -> None:
        record = {"check": name, "pass": bool(passed)}
        if detail is not None:
            record["detail"] = detail
        checks.append(record)
        if not passed:
            failures.append(record)

    required = [
        GOVERNANCE / "CLEAN_ROOM_POLICY.md",
        GOVERNANCE / "AUTHORIZATION.md",
        GOVERNANCE / "authorization.json",
        GOVERNANCE / "INPUT_PROVENANCE.md",
        GOVERNANCE / "input-provenance.json",
        GOVERNANCE / "SPECIFICATION_FORMAT.md",
        GOVERNANCE / "BEHAVIOR_CHANGE_CONTROL.md",
        GOVERNANCE / "team-register.json",
        GOVERNANCE / "behavior-notes.json",
        SPECIFICATIONS / "schema" / "specification.schema.json",
        IMPLEMENTATION / "README.md",
    ]
    for path in required:
        check(f"required governance record {path.relative_to(ROOT)}", path.is_file())

    authorization = load_json(GOVERNANCE / "authorization.json")
    exact_attestation = (
        "I authorize this project to analyze and test the supplied files, produce a "
        "clean-room implementation, and redistribute that implementation, subject to "
        "applicable law; I attest I am authorized to approve this project work."
    )
    check("authorization is active", authorization.get("status") == "active")
    check(
        "authorization carries exact sponsor attestation",
        authorization.get("attestation") == exact_attestation,
    )
    check(
        "authorization distinguishes resulting implementation from originals",
        any("original bin inputs" in item for item in authorization.get("excluded_activities", [])),
    )
    authorization_id = authorization.get("record_id")

    provenance = load_json(GOVERNANCE / "input-provenance.json")
    events = {event.get("id"): event for event in provenance.get("acquisition_events", [])}
    recorded = provenance.get("files", [])
    recorded_paths = {entry.get("path") for entry in recorded}
    actual_paths = {
        str(path.relative_to(ROOT)) for path in (ROOT / "bin").rglob("*") if path.is_file()
    }
    check(
        "provenance covers the exact bin file set",
        recorded_paths == actual_paths and len(recorded) == len(recorded_paths),
        {"recorded": len(recorded_paths), "actual": len(actual_paths)},
    )
    check(
        "provenance references active authorization",
        provenance.get("authorization_record") == authorization_id,
    )
    check("at least one acquisition event is recorded", bool(events))
    for entry in recorded:
        label = str(entry.get("path"))
        path = ROOT / label
        hashes = entry.get("hashes", {})
        check(f"{label} exists", path.is_file())
        if not path.is_file():
            continue
        check(f"{label} byte length", path.stat().st_size == entry.get("size_bytes"))
        check(f"{label} SHA-256", digest(path, "sha256") == hashes.get("sha256"))
        check(f"{label} SHA-512", digest(path, "sha512") == hashes.get("sha512"))
        blob = git("hash-object", label).stdout.decode().strip()
        check(f"{label} Git blob identity", blob == hashes.get("git_blob_sha1"))
        first = entry.get("first_repository_record", {})
        approved_path = label.removeprefix("bin/")
        check(
            f"{label} provenance points to approved baseline",
            first.get("commit") == APPROVED_INPUT_COMMIT
            and first.get("path") == approved_path,
        )
        original_spec = f"{APPROVED_INPUT_COMMIT}:{approved_path}"
        original = git("show", original_spec, check=False)
        check(
            f"{label} equals approved baseline object",
            original.returncode == 0 and original.stdout == path.read_bytes(),
        )
        check(
            f"{label} acquisition event resolves",
            entry.get("acquisition_event") in events,
        )
        license_record = entry.get("license", {})
        check(
            f"{label} license and redistribution status recorded",
            bool(license_record.get("status"))
            and bool(license_record.get("evidence"))
            and bool(entry.get("original_file_redistribution_status")),
        )

    team = load_json(GOVERNANCE / "team-register.json")
    analysis_ids = {member.get("id") for member in team.get("analysis_team", [])}
    implementation_members = team.get("clean_implementation_team", [])
    implementation_ids = {member.get("id") for member in implementation_members}
    implementation_by_id = {member.get("id"): member for member in implementation_members}
    specification_reviewers = {
        member.get("id"): member for member in team.get("specification_reviewers", [])
    }
    transfer_ids = {member.get("id") for member in team.get("transfer_coordinators", [])}
    check("Team A identities are unique", len(analysis_ids) == len(team.get("analysis_team", [])))
    check(
        "Team A and Team B identities do not overlap",
        analysis_ids.isdisjoint(implementation_ids),
        sorted((analysis_ids & implementation_ids) - {None}),
    )
    reviewer_ids = set(specification_reviewers)
    check(
        "specification reviewers are registered Team A and never Team B",
        None not in reviewer_ids
        and reviewer_ids <= analysis_ids
        and reviewer_ids.isdisjoint(implementation_ids),
    )
    check(
        "team register references active authorization",
        team.get("sponsor", {}).get("authorization_record") == authorization_id,
    )

    ledger = load_json(GOVERNANCE / "behavior-notes.json")
    note_entries = ledger.get("notes", [])
    note_ids = {entry.get("note_id") for entry in note_entries}
    active_note_paths = {
        entry.get("path") for entry in note_entries if entry.get("status") != "withdrawn"
    }
    actual_notes = {
        str(path.relative_to(ROOT)) for path in (ROOT / "src").glob("*/reviewed-behavior.md")
    }
    check(
        "behavior registry note IDs are unique",
        None not in note_ids and len(note_entries) == len(note_ids),
    )
    check(
        "behavior registry covers every active manual behavior note",
        active_note_paths == actual_notes and len(active_note_paths) == len(actual_notes),
        {"registered_active": len(active_note_paths), "actual": len(actual_notes)},
    )
    provenance_by_name = {Path(entry["path"]).name: entry for entry in recorded}
    for entry in note_entries:
        label = str(entry.get("path"))
        path = ROOT / label
        withdrawn = entry.get("status") == "withdrawn"
        check(
            f"{label} file presence agrees with registry status",
            not path.exists() if withdrawn else path.is_file(),
        )
        if path.is_file():
            check(
                f"{label} registered content hash",
                digest(path, "sha256") == entry.get("content_sha256"),
            )
            match = CONTROL_RE.search(path.read_text(encoding="utf-8")[:1000])
            check(
                f"{label} visible control metadata",
                bool(match)
                and match.group("id") == entry.get("note_id")
                and int(match.group("revision")) == entry.get("revision")
                and match.group("status") == entry.get("status"),
            )
        else:
            check(
                f"{label} withdrawn content hash retained",
                withdrawn and bool(HEX64_RE.fullmatch(str(entry.get("content_sha256", "")))),
            )
        module = provenance_by_name.get(str(entry.get("module")))
        check(
            f"{label} module identity",
            bool(module) and module["hashes"]["sha256"] == entry.get("module_sha256"),
        )
        bcr_path = GOVERNANCE / "behavior-changes" / f"{entry.get('latest_change_request')}.json"
        check(f"{label} latest BCR exists", bcr_path.is_file())
        if bcr_path.is_file():
            bcr = load_json(bcr_path)
            changes = bcr.get("notes", [bcr])
            change = next(
                (item for item in changes if item.get("note_id") == entry.get("note_id")), None
            )
            check(
                f"{label} latest BCR matches revision and hash",
                bool(change)
                and change.get("new_revision") == entry.get("revision")
                and change.get("new_content_sha256") == entry.get("content_sha256"),
            )

    specification_schema = load_json(
        SPECIFICATIONS / "schema" / "specification.schema.json"
    )
    spec_files = sorted((SPECIFICATIONS / "drafts").glob("*.json")) + sorted(
        (SPECIFICATIONS / "released").glob("*.json")
    )
    spec_ids: set[tuple[str, int]] = set()
    referenced_release_ids: set[str] = set()
    provenance_modules = {
        Path(entry["path"]).name: entry["hashes"]["sha256"] for entry in recorded
    }
    for path in spec_files:
        relative = path.relative_to(ROOT)
        spec = load_json(path)
        schema_errors = json_schema_errors(spec, specification_schema)
        check(
            f"{relative} conforms to specification.schema.json",
            not schema_errors,
            schema_errors[:30],
        )
        check(f"{relative} has ESF-001 top-level fields", REQUIRED_SPEC_KEYS <= set(spec))
        check(
            f"{relative} standard and schema version",
            spec.get("standard") == "ESF-001" and spec.get("schema_version") == 1,
        )
        identity = (spec.get("specification_id"), spec.get("revision"))
        check(f"{relative} specification identity is unique", identity not in spec_ids)
        spec_ids.add(identity)
        expected_status = "released" if path.parent.name == "released" else None
        check(
            f"{relative} directory agrees with lifecycle",
            spec.get("status") == expected_status if expected_status else spec.get("status") != "released",
        )
        source = spec.get("source_identity", {})
        check(
            f"{relative} source SHA-256 is recorded",
            bool(HEX64_RE.fullmatch(str(source.get("sha256", "")))),
        )
        module_hash = provenance_modules.get(str(spec.get("module")))
        check(
            f"{relative} source identity matches provenance",
            module_hash == source.get("sha256"),
        )
        check(
            f"{relative} references active authorization",
            spec.get("authorization_record") == authorization_id,
        )
        interface_ids = [item.get("id") for item in spec.get("interfaces", [])]
        evidence_ids = [item.get("id") for item in spec.get("evidence_claims", [])]
        requirement_ids = [item.get("id") for item in spec.get("requirements", [])]
        check(
            f"{relative} interface IDs are unique and present",
            bool(interface_ids) and len(interface_ids) == len(set(interface_ids)) and None not in interface_ids,
        )
        check(
            f"{relative} evidence IDs are unique and present",
            bool(evidence_ids) and len(evidence_ids) == len(set(evidence_ids)) and None not in evidence_ids,
        )
        check(
            f"{relative} requirement IDs are unique and present",
            bool(requirement_ids)
            and len(requirement_ids) == len(set(requirement_ids))
            and None not in requirement_ids,
        )
        evidence_set, interface_set = set(evidence_ids), set(interface_ids)
        refs_ok = all(
            set(requirement.get("evidence_ids", [])) <= evidence_set
            and bool(requirement.get("evidence_ids"))
            and set(requirement.get("interface_ids", [])) <= interface_set
            and bool(requirement.get("interface_ids"))
            for requirement in spec.get("requirements", [])
        )
        check(f"{relative} requirement references resolve", refs_ok)
        author_ids = {author.get("id") for author in spec.get("authors", [])}
        check(
            f"{relative} authors are registered Team A",
            bool(author_ids) and author_ids <= analysis_ids,
        )
        if spec.get("status") == "released":
            approval_errors = release_approval_errors(spec, team)
            check(
                f"{relative} release approvers are registered, assigned, and independent",
                not approval_errors,
                approval_errors,
            )
            leaked = release_expression_violations(spec)
            check(
                f"{relative} contains no prohibited analyst expression",
                not leaked,
                leaked[:30],
            )
            release = spec.get("release")
            check(f"{relative} release metadata present", isinstance(release, dict))
            if isinstance(release, dict):
                release_id = release.get("release_record_id")
                referenced_release_ids.add(str(release_id))
                coordinator_id = release.get("transfer_coordinator", {}).get("id")
                check(
                    f"{relative} coordinator is registered",
                    coordinator_id in transfer_ids,
                )
                record_path = GOVERNANCE / "specification-releases" / f"{release_id}.json"
                check(f"{relative} release record exists", record_path.is_file())
                if record_path.is_file():
                    record = load_json(record_path)
                    matching = next(
                        (
                            item
                            for item in record.get("specifications", [])
                            if item.get("specification_id") == spec.get("specification_id")
                            and item.get("revision") == spec.get("revision")
                        ),
                        None,
                    )
                    check(
                        f"{relative} release record carries exact spec hash",
                        bool(matching) and matching.get("sha256") == digest(path, "sha256"),
                    )
                    recipient_id = record.get("recipient", {}).get("id")
                    recipient = implementation_by_id.get(recipient_id, {})
                    check(
                        f"{relative} release recipient is assigned to module",
                        recipient_id in implementation_ids
                        and assigned_to_module(recipient, str(spec.get("module"))),
                    )
                    check(
                        f"{relative} package hashes are recorded",
                        bool(HEX64_RE.fullmatch(str(record.get("manifest_sha256", ""))))
                        and bool(HEX64_RE.fullmatch(str(record.get("archive_sha256", "")))),
                    )
        else:
            check(f"{relative} unreleased document has no release metadata", spec.get("release") is None)

    actual_release_ids = {
        path.stem
        for path in (GOVERNANCE / "specification-releases").glob("REL-*.json")
    }
    check(
        "specification release records match released specifications",
        actual_release_ids == referenced_release_ids,
        {"records": sorted(actual_release_ids), "referenced": sorted(referenced_release_ids)},
    )

    implementation_files = [path for path in IMPLEMENTATION.rglob("*") if path.is_file()]
    implementation_links = [path for path in IMPLEMENTATION.rglob("*") if path.is_symlink()]
    check("implementation tree has no symlinks", not implementation_links)
    build_manifests_under_src = [
        path for path in (ROOT / "src").rglob("*")
        if path.is_file() and (path.name in IMPLEMENTATION_BUILD_NAMES or path.suffix == ".cmake")
    ]
    check(
        "recovered src tree contains no build manifests",
        not build_manifests_under_src,
        [str(path.relative_to(ROOT)) for path in build_manifests_under_src],
    )
    for path in implementation_files:
        relative = path.relative_to(ROOT)
        data = path.read_bytes()
        check(
            f"{relative} is not a committed executable/object payload",
            not (data.startswith(b"MZ") or data.startswith(b"\x7fELF")),
        )
        bad = implementation_reference_violations(data)
        check(f"{relative} has no forbidden implementation dependency", not bad, bad)

    if args.base_ref:
        changed_result = git("diff", "--name-only", f"{args.base_ref}...HEAD", check=False)
        check(
            f"base ref {args.base_ref} can be compared",
            changed_result.returncode == 0,
            changed_result.stderr.decode(errors="replace").strip() or None,
        )
        if changed_result.returncode == 0:
            changed = set(changed_result.stdout.decode().splitlines())

            input_changes = git(
                "diff", "--name-only", f"{args.base_ref}...HEAD", "--", "bin", check=False
            )
            changed_inputs = input_changes.stdout.decode().splitlines()
            check(
                "approved input tree is unchanged from pull-request base",
                input_changes.returncode == 0 and not changed_inputs,
                changed_inputs,
            )

            base_ledger_result = git(
                "show", f"{args.base_ref}:governance/behavior-notes.json", check=False
            )
            base_notes: dict[str, dict[str, Any]] = {}
            if base_ledger_result.returncode == 0:
                base_notes = {
                    entry["note_id"]: entry
                    for entry in json.loads(base_ledger_result.stdout).get("notes", [])
                }
            current_notes = {entry["note_id"]: entry for entry in note_entries}
            for note_id, old in base_notes.items():
                current = current_notes.get(note_id)
                check(f"behavior ledger retains {note_id}", current is not None)
                if current is None:
                    continue
                old_path = str(old.get("path"))
                current_path = str(current.get("path"))
                note_changed = (
                    old != current or old_path in changed or current_path in changed
                )
                if old_path in changed and not (ROOT / old_path).exists():
                    check(
                        f"deleted behavior note {note_id} is marked withdrawn",
                        current.get("status") == "withdrawn",
                    )
                if not note_changed:
                    continue
                bcr_label = (
                    "governance/behavior-changes/"
                    f"{current.get('latest_change_request')}.json"
                )
                check(
                    f"{note_id} changes with registry and a new BCR",
                    "governance/behavior-notes.json" in changed
                    and bcr_label in changed,
                )
                check(
                    f"{note_id} increments controlled revision",
                    current.get("revision", 0) > old.get("revision", 0)
                    and current.get("latest_change_request")
                    != old.get("latest_change_request"),
                )
            for note_id, current in current_notes.items():
                if note_id in base_notes:
                    continue
                bcr_label = (
                    "governance/behavior-changes/"
                    f"{current.get('latest_change_request')}.json"
                )
                check(
                    f"new behavior note {note_id} has registry and BCR changes",
                    "governance/behavior-notes.json" in changed
                    and bcr_label in changed
                    and current.get("path") in changed,
                )

            base_release_paths_result = git(
                "ls-tree",
                "-r",
                "--name-only",
                args.base_ref,
                "--",
                "specifications/released",
                "governance/specification-releases",
                check=False,
            )
            check(
                f"release history at {args.base_ref} can be inspected",
                base_release_paths_result.returncode == 0,
            )
            if base_release_paths_result.returncode == 0:
                base_release_paths = base_release_paths_result.stdout.decode().splitlines()
                historical_specs = [
                    label
                    for label in base_release_paths
                    if label.startswith("specifications/released/")
                    and label.endswith(".json")
                ]
                historical_records = [
                    label
                    for label in base_release_paths
                    if label.startswith("governance/specification-releases/REL-")
                    and label.endswith(".json")
                ]
                for label in historical_specs:
                    current_path = ROOT / label
                    old_data = git("show", f"{args.base_ref}:{label}", check=False)
                    check(
                        f"released specification is retained byte-identically: {label}",
                        current_path.is_file()
                        and old_data.returncode == 0
                        and current_path.read_bytes() == old_data.stdout,
                    )
                for label in historical_records:
                    check(
                        f"specification release record is retained: {label}",
                        (ROOT / label).is_file(),
                    )

    receipt = {
        "result": "pass" if not failures else "fail",
        "validated_date": date.today().isoformat(),
        "policy_versions": {"clean_room": "CRP-001", "specification": "ESF-001", "behavior_change": "BCC-001"},
        "check_count": len(checks),
        "failed": failures,
        "checks": checks,
    }
    if not args.no_receipt:
        REPORT.write_text(json.dumps(receipt, indent=2) + "\n", encoding="utf-8")
    print(f"{receipt['result']} {len(checks)} checks; {len(failures)} failures")
    for failure in failures[:30]:
        print(failure)
    return int(bool(failures))


if __name__ == "__main__":
    raise SystemExit(main())
