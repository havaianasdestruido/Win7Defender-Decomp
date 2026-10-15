#!/usr/bin/env python3
"""Create a deterministic, sanitized ESF-001 package for a registered Team B member."""

from __future__ import annotations

import argparse
import hashlib
import json
import sys
import zipfile
from datetime import date
from pathlib import Path
from typing import Any

from validate_governance import json_schema_errors

ROOT = Path(__file__).resolve().parents[2]
SPECS = ROOT / "specifications"
GOVERNANCE = ROOT / "governance"
RELEASE_RECORDS = GOVERNANCE / "specification-releases"
ZIP_TIMESTAMP = (1980, 1, 1, 0, 0, 0)
TRANSFER = """Clean-room specification package

Use only the released specifications and public references declared inside
them. Do not seek or accept the analysis repository, original inputs, analyst
notes, decompiler output, disassembly, or implementation hints. Questions must
cite a specification requirement ID and return through the transfer
coordinator. Report accidental exposure immediately and stop affected work.

Verify MANIFEST.json hashes before use and retain the package/archive SHA-256 in
the clean implementation provenance record.
"""


def load(path: Path) -> Any:
    return json.loads(path.read_text(encoding="utf-8"))


def encoded(value: Any) -> bytes:
    return (json.dumps(value, indent=2, sort_keys=True) + "\n").encode("utf-8")


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def assigned(member: dict[str, Any], module: str) -> bool:
    return module in member.get("modules", []) or "*" in member.get("modules", [])


def fail(message: str) -> None:
    raise SystemExit(f"error: {message}")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--release-id", required=True, help="REL-* identifier referenced by every spec")
    parser.add_argument("--recipient", required=True, help="registered Team B identity")
    parser.add_argument("--coordinator", required=True, help="registered transfer-coordinator identity")
    parser.add_argument("--output", required=True, type=Path, help="destination .zip")
    args = parser.parse_args()

    if not args.release_id.startswith("REL-"):
        fail("--release-id must start with REL-")
    if args.output.suffix.lower() != ".zip":
        fail("--output must end in .zip")

    release_specs = sorted((SPECS / "released").glob("*.json"))
    if not release_specs:
        fail("no released specifications are available")

    team = load(GOVERNANCE / "team-register.json")
    recipient = next(
        (item for item in team.get("clean_implementation_team", []) if item.get("id") == args.recipient),
        None,
    )
    coordinator = next(
        (item for item in team.get("transfer_coordinators", []) if item.get("id") == args.coordinator),
        None,
    )
    if recipient is None:
        fail("recipient is not a registered clean implementation team member")
    if coordinator is None:
        fail("coordinator is not registered")

    record_path = RELEASE_RECORDS / f"{args.release_id}.json"
    if record_path.exists():
        fail(f"release record already exists: {record_path.relative_to(ROOT)}")

    specs: list[tuple[Path, dict[str, Any], bytes]] = []
    author_ids = {item.get("id") for item in team.get("analysis_team", [])}
    implementation_ids = {
        item.get("id") for item in team.get("clean_implementation_team", [])
    }
    specification_reviewers = {
        item.get("id"): item for item in team.get("specification_reviewers", [])
    }
    sponsor_id = team.get("sponsor", {}).get("id")
    schema_path = SPECS / "schema" / "specification.schema.json"
    specification_schema = load(schema_path)
    for path in release_specs:
        spec = load(path)
        schema_errors = json_schema_errors(spec, specification_schema)
        if schema_errors:
            fail(f"{path.name} violates specification.schema.json: {schema_errors[0]}")
        module = spec.get("module")
        if spec.get("status") != "released":
            fail(f"{path.name} is under released/ but status is not released")
        release = spec.get("release") or {}
        if release.get("release_record_id") != args.release_id:
            fail(f"{path.name} does not reference {args.release_id}")
        if release.get("transfer_coordinator", {}).get("id") != args.coordinator:
            fail(f"{path.name} names another transfer coordinator")
        if not assigned(recipient, str(module)):
            fail(f"recipient is not assigned to {module}")
        authors = {item.get("id") for item in spec.get("authors", [])}
        if not authors or not authors <= author_ids:
            fail(f"{path.name} has an unregistered Team A author")
        approvals = spec.get("approvals", {})
        if not all(approvals.get(kind) for kind in ("technical", "expression", "scope")):
            fail(f"{path.name} lacks release approvals")
        technical_ids = {
            item.get("reviewer", {}).get("id") for item in approvals["technical"]
        }
        expression_ids = {
            item.get("reviewer", {}).get("id") for item in approvals["expression"]
        }
        scope_ids = {
            item.get("reviewer", {}).get("id") for item in approvals["scope"]
        }
        reviewers = technical_ids | expression_ids
        if reviewers & (authors | implementation_ids):
            fail(f"{path.name} reviewers are not independent from authors and Team B")
        if not technical_ids or not all(
            reviewer_id in specification_reviewers
            and "technical" in specification_reviewers[reviewer_id].get("review_kinds", [])
            and assigned(specification_reviewers[reviewer_id], str(module))
            for reviewer_id in technical_ids
        ):
            fail(f"{path.name} has an unregistered or unassigned technical reviewer")
        if not expression_ids or not all(
            reviewer_id in specification_reviewers
            and "expression" in specification_reviewers[reviewer_id].get("review_kinds", [])
            and assigned(specification_reviewers[reviewer_id], str(module))
            for reviewer_id in expression_ids
        ):
            fail(f"{path.name} has an unregistered or unassigned expression reviewer")
        if not technical_ids.isdisjoint(expression_ids):
            fail(f"{path.name} reuses a reviewer across technical and expression approval")
        if scope_ids != {sponsor_id}:
            fail(f"{path.name} scope approval is not from the registered sponsor")
        data = path.read_bytes()
        specs.append((path, spec, data))

    payloads: list[tuple[str, bytes]] = [
        ("schema/specification.schema.json", schema_path.read_bytes()),
        ("TRANSFER.txt", TRANSFER.encode("utf-8")),
    ]
    payloads.extend((f"specifications/{path.name}", data) for path, _, data in specs)
    included = [
        {"path": name, "size_bytes": len(data), "sha256": sha256(data)}
        for name, data in payloads
    ]
    manifest = {
        "schema_version": 1,
        "standard": "ESF-001",
        "release_id": args.release_id,
        "exported_date": date.today().isoformat(),
        "recipient": args.recipient,
        "coordinator": args.coordinator,
        "included_files": included,
    }
    manifest_bytes = encoded(manifest)

    args.output.parent.mkdir(parents=True, exist_ok=True)
    with zipfile.ZipFile(args.output, "w", compression=zipfile.ZIP_DEFLATED, compresslevel=9) as archive:
        for name, data in [*payloads, ("MANIFEST.json", manifest_bytes)]:
            info = zipfile.ZipInfo(name, ZIP_TIMESTAMP)
            info.compress_type = zipfile.ZIP_DEFLATED
            info.external_attr = 0o100644 << 16
            archive.writestr(info, data, compress_type=zipfile.ZIP_DEFLATED, compresslevel=9)

    archive_data = args.output.read_bytes()
    release_record = {
        "schema_version": 1,
        "policy": "CRP-001",
        "format_standard": "ESF-001",
        "record_id": args.release_id,
        "status": "exported-pending-delivery",
        "exported_date": date.today().isoformat(),
        "coordinator": {"id": args.coordinator},
        "recipient": {"id": args.recipient},
        "specifications": [
            {
                "specification_id": spec["specification_id"],
                "revision": spec["revision"],
                "module": spec["module"],
                "sha256": sha256(data),
            }
            for _, spec, data in specs
        ],
        "included_files": included,
        "manifest_sha256": sha256(manifest_bytes),
        "archive_name": args.output.name,
        "archive_sha256": sha256(archive_data),
        "delivery": {"status": "pending", "date": None, "channel_record": None},
    }
    record_path.write_bytes(encoded(release_record))
    print(f"wrote {args.output} ({len(archive_data)} bytes)")
    print(f"archive sha256 {release_record['archive_sha256']}")
    print(f"record {record_path.relative_to(ROOT)}")
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (OSError, ValueError, json.JSONDecodeError) as error:
        print(f"error: {error}", file=sys.stderr)
        raise SystemExit(1)
