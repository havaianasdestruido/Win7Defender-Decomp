#!/usr/bin/env python3
"""Focused regressions for Phase 0 governance gates."""

from __future__ import annotations

import copy
import json
import tempfile
import unittest
from pathlib import Path

from export_specifications import specifications_for_release
from validate_governance import (
    APPROVED_INPUT_COMMIT,
    implementation_reference_violations,
    json_schema_errors,
    release_approval_errors,
    release_expression_violations,
)

ROOT = Path(__file__).resolve().parents[2]


class GovernanceRegressionTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        cls.schema = json.loads(
            (ROOT / "specifications/schema/specification.schema.json").read_text()
        )
        cls.draft = json.loads(
            (ROOT / "specifications/drafts/SPEC-MPASDESC-RESOLVER.json").read_text()
        )

    def test_declared_schema_rejects_incomplete_requirement(self) -> None:
        self.assertEqual(json_schema_errors(self.draft, self.schema), [])
        incomplete = copy.deepcopy(self.draft)
        del incomplete["requirements"][0]["statement"]
        errors = json_schema_errors(incomplete, self.schema)
        self.assertTrue(any("statement" in error for error in errors), errors)

    def test_release_expression_rejects_rva_without_substring_false_positive(self) -> None:
        self.assertTrue(
            release_expression_violations({"statement": "Original RVA 0x1768 returns."})
        )
        self.assertTrue(release_expression_violations({"rva": 0x1768}))
        self.assertEqual(
            release_expression_violations(
                {"statement": "Preservation and arrival are observable behavior."}
            ),
            [],
        )

    def test_all_handoff_scripts_are_scanned(self) -> None:
        self.assertEqual(
            implementation_reference_violations(b"#!/bin/sh\necho safe\n"), []
        )
        self.assertTrue(
            implementation_reference_violations(
                b"#!/bin/sh\ncat ../src/private-analysis-input\n"
            )
        )

    def test_release_approvers_must_be_registered_and_role_separated(self) -> None:
        team = {
            "sponsor": {"id": "sponsor"},
            "analysis_team": [
                {"id": "author"},
                {"id": "technical-reviewer"},
                {"id": "expression-reviewer"},
            ],
            "clean_implementation_team": [],
            "specification_reviewers": [
                {
                    "id": "technical-reviewer",
                    "modules": ["Example.dll"],
                    "review_kinds": ["technical"],
                },
                {
                    "id": "expression-reviewer",
                    "modules": ["Example.dll"],
                    "review_kinds": ["expression"],
                },
            ],
        }
        approval = lambda reviewer: {
            "reviewer": {"id": reviewer, "role": "reviewer"},
            "decision": "approved",
            "date": "2026-10-15",
            "statement": "Reviewed and approved.",
        }
        spec = {
            "module": "Example.dll",
            "authors": [{"id": "author", "role": "analysis author"}],
            "approvals": {
                "technical": [approval("technical-reviewer")],
                "expression": [approval("expression-reviewer")],
                "scope": [approval("sponsor")],
            },
        }
        self.assertEqual(release_approval_errors(spec, team), [])

        unregistered = copy.deepcopy(spec)
        unregistered["approvals"]["expression"][0]["reviewer"]["id"] = "stranger"
        self.assertTrue(release_approval_errors(unregistered, team))

        reused = copy.deepcopy(spec)
        reused["approvals"]["expression"][0]["reviewer"]["id"] = "technical-reviewer"
        self.assertTrue(release_approval_errors(reused, team))

    def test_export_selects_only_requested_release_batch(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            for name, release_id in (("old.json", "REL-1"), ("new.json", "REL-2")):
                (root / name).write_text(
                    json.dumps(
                        {
                            "status": "released",
                            "release": {"release_record_id": release_id},
                        }
                    )
                )
            selected = specifications_for_release(
                sorted(root.glob("*.json")), "REL-2"
            )
            self.assertEqual([path.name for path, _ in selected], ["new.json"])

    def test_input_baseline_commit_is_fixed(self) -> None:
        self.assertEqual(
            APPROVED_INPUT_COMMIT,
            "9638320b682dfbed9eb0455750d78fac384b6598",
        )


if __name__ == "__main__":
    unittest.main()
