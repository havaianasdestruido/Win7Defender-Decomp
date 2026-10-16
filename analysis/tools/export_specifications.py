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

from validate_governance import (
    json_schema_errors,
    release_approval_errors,
    release_expression_violations,
)

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


def specifications_for_release(
    paths: list[Path], release_id: str
) -> list[tuple[Path, dict[str, Any]]]:
    """Select one immutable release batch while leaving older batches untouched."""
    selected: list[tuple[Path, dict[str, Any]]] = []
    for path in paths:
        spec = load(path)
        if spec.get("status") != "released":
            fail(f"{path.name} is under released/ but status is not released")
        release = spec.get("release") or {}
        if release.get("release_record_id") == release_id:
            selected.append((path, spec))
    return selected


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

    released_paths = sorted((SPECS / "released").glob("*.json"))
    release_specs = specifications_for_release(released_paths, args.release_id)
    if not release_specs:
        fail(f"no released specifications reference {args.release_id}")

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
    schema_path = SPECS / "schema" / "specification.schema.json"
    specification_schema = load(schema_path)
    for path, spec in release_specs:
        schema_errors = json_schema_errors(spec, specification_schema)
        if schema_errors:
            fail(f"{path.name} violates specification.schema.json: {schema_errors[0]}")
        expression_leaks = release_expression_violations(spec)
        if expression_leaks:
            fail(f"{path.name} contains prohibited analyst expression: {expression_leaks[0]}")
        module = spec.get("module")
        release = spec.get("release") or {}
        if release.get("transfer_coordinator", {}).get("id") != args.coordinator:
            fail(f"{path.name} names another transfer coordinator")
        if not assigned(recipient, str(module)):
            fail(f"recipient is not assigned to {module}")
        authors = {item.get("id") for item in spec.get("authors", [])}
        if not authors or not authors <= author_ids:
            fail(f"{path.name} has an unregistered Team A author")
        approval_errors = release_approval_errors(spec, team)
        if approval_errors:
            fail(f"{path.name} has invalid release approvals: {approval_errors[0]}")
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
