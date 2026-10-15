# MpAsDesc analysis model

This portable C model captures the manually reviewed, non-tracing resolver
decision logic for controlled comparison in `validate_behavior.py`. It was
written by the analysis team with access to original instructions, table data,
and generated pseudocode. It is therefore intentionally ineligible for a
strict clean-room implementation.

The CMake target is a Linux shared test library, not a Windows DLL. It excludes
all files under `src/`, including `pseudocode.c`; does not embed original
resources; and does not implement loader, WPP, MUI, or ABI replacement behavior.
