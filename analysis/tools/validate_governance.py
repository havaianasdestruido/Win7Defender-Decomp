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
IMPLEMENTATION_TEXT_EXTENSIONS = {
    ".c", ".cc", ".cpp", ".cxx", ".h", ".hh", ".hpp", ".hxx",
    ".asm", ".s", ".rs", ".go", ".py", ".java", ".cs", ".swift",
    ".kt", ".js", ".ts", ".cmake", ".mk", ".toml", ".yaml", ".yml",
}
IMPLEMENTATION_BUILD_NAMES = {
    "CMakeLists.txt", "Makefile", "meson.build", "build.ninja", "package.json",
    "pyproject.toml", "Cargo.toml", "go.mod", "build.gradle", "pom.xml",
}
FORBIDDEN_IMPLEMENTATION_REFS = {
    "bin/": "original input path",
    "analysis/": "analysis artifact path",
    "src/": "recovered/decompiler artifact path",
    "specifications/drafts": "unreleased specification path",
    "pseudocode.c": "generated pseudocode",
    "reviewed-behavior": "analyst-only behavior note",
}
FORBIDDEN_RELEASE_TEXT = (
    "pseudocode",
    "disassembly",
    "instruction bytes",
    "virtual address",
    "file offset",
    "reviewed-behavior",
    "analysis/report",
    "src/",
    "bin/",
)
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
        original_spec = f"{first.get('commit')}:{first.get('path')}"
        original = git("show", original_spec, check=False)
        check(
            f"{label} equals first repository object",
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
    transfer_ids = {member.get("id") for member in team.get("transfer_coordinators", [])}
    check("Team A identities are unique", len(analysis_ids) == len(team.get("analysis_team", [])))
    check(
        "Team A and Team B identities do not overlap",
        analysis_ids.isdisjoint(implementation_ids),
        sorted((analysis_ids & implementation_ids) - {None}),
    )
    check(
        "team register references active authorization",
        team.get("sponsor", {}).get("authorization_record") == authorization_id,
    )

    ledger = load_json(GOVERNANCE / "behavior-notes.json")
    note_entries = ledger.get("notes", [])
    note_paths = {entry.get("path") for entry in note_entries}
    actual_notes = {
        str(path.relative_to(ROOT)) for path in (ROOT / "src").glob("*/reviewed-behavior.md")
    }
    check(
        "behavior registry covers every manual behavior note",
        note_paths == actual_notes and len(note_entries) == len(note_paths),
        {"registered": len(note_paths), "actual": len(actual_notes)},
    )
    provenance_by_name = {Path(entry["path"]).name: entry for entry in recorded}
    for entry in note_entries:
        label = str(entry.get("path"))
        path = ROOT / label
        check(f"{label} registered file exists", path.is_file())
        if not path.is_file():
            continue
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
            approvals = spec.get("approvals", {})
            tech = approvals.get("technical", [])
            expression = approvals.get("expression", [])
            scope = approvals.get("scope", [])
            reviewers = {
                approval.get("reviewer", {}).get("id")
                for approval in [*tech, *expression]
            }
            check(f"{relative} release approvals complete", bool(tech and expression and scope))
            check(
                f"{relative} release reviewers differ from authors",
                bool(reviewers) and reviewers.isdisjoint(author_ids),
            )
            text = path.read_text(encoding="utf-8").lower()
            leaked = [token for token in FORBIDDEN_RELEASE_TEXT if token in text]
            check(f"{relative} contains no prohibited analyst expression", not leaked, leaked)
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
                    assigned_modules = recipient.get("modules", [])
                    check(
                        f"{relative} release recipient is assigned to module",
                        recipient_id in implementation_ids
                        and ("*" in assigned_modules or spec.get("module") in assigned_modules),
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
        inspect_text = path.name in IMPLEMENTATION_BUILD_NAMES or path.suffix in IMPLEMENTATION_TEXT_EXTENSIONS
        if inspect_text:
            text = data.decode("utf-8", errors="replace").lower()
            bad = [reason for token, reason in FORBIDDEN_IMPLEMENTATION_REFS.items() if token in text]
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
            base_ledger_result = git("show", f"{args.base_ref}:governance/behavior-notes.json", check=False)
            base_notes: dict[str, dict[str, Any]] = {}
            if base_ledger_result.returncode == 0:
                base_notes = {
                    entry["note_id"]: entry
                    for entry in json.loads(base_ledger_result.stdout).get("notes", [])
                }
            for entry in note_entries:
                if entry["path"] not in changed:
                    continue
                old = base_notes.get(entry["note_id"])
                bcr_label = f"governance/behavior-changes/{entry['latest_change_request']}.json"
                check(
                    f"{entry['path']} changes with registry and BCR",
                    "governance/behavior-notes.json" in changed and bcr_label in changed,
                )
                check(
                    f"{entry['path']} increments controlled revision",
                    old is None
                    or (
                        entry["revision"] > old.get("revision", 0)
                        and entry["latest_change_request"] != old.get("latest_change_request")
                    ),
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
