# Coverage and progress — 2026-10-14

## Coverage semantics

Every input has an inventory entry. Every PE has a module directory, resource/API inventory and REA results. Candidate functions are the union of angr discoveries, export/entry starts and `.pdata` starts. `.pdata` records can describe funclets, not distinct source functions; leaf functions can lack unwind records. CFG scanning can mistake data/padding for code. Therefore neither count is a ground-truth total. No percentage here means semantic completeness.

| Module | Unwind records | Candidate starts | Pseudocode emitted | Timeout | Deferred | Other gaps |
|---|---:|---:|---:|---:|---:|---:|
| MSASCui.exe | 3349 | 5073 | 3665 | 0 | 1404 | 4 |
| MpAsDesc.dll | 26 | 52 | 52 | 0 | 0 | 0 |
| MpClient.dll | 2062 | 3286 | 2701 | 0 | 578 | 7 |
| MpCmdRun.exe | 537 | 824 | 815 | 5 | 0 | 4 |
| MpCommu.dll | 1117 | 1783 | 1698 | 0 | 80 | 5 |
| MpEvMsg.dll | 0 | 0 | 0 | 0 | 0 | 0 |
| MpOAV.dll | 171 | 334 | 333 | 0 | 0 | 1 |
| MpRTP.dll | 721 | 1122 | 1106 | 0 | 12 | 4 |
| MpSvc.dll | 3897 | 5799 | 4019 | 0 | 1774 | 6 |
| MsMpCom.dll | 188 | 315 | 313 | 0 | 0 | 2 |
| MsMpLics.dll | 0 | 0 | 0 | 0 | 0 | 0 |
| MsMpRes.dll | 23 | 50 | 50 | 0 | 0 | 0 |
| pt-BR__MpAsDesc.dll.mui | 0 | 0 | 0 | 0 | 0 | 0 |
| pt-BR__MpEvMsg.dll.mui | 0 | 0 | 0 | 0 | 0 | 0 |
| pt-BR__MsMpRes.dll.mui | 0 | 0 | 0 | 0 | 0 | 0 |

## Exact remaining work

- Each timeout/deferred/error/seed-not-recovered row contains the exact VA and reason. Use the row and disassembly to re-run the module with larger budgets or a Ghidra session; validate boundaries before trusting pseudocode. Successful emission is **not manual verification**.
- All unresolved indirect jumps are listed in each module’s indirect-jumps.json. Resolved targets are static candidates; runtime callbacks and plugin/COM virtual dispatch require object/state recovery.
- Original PDB references (10 code images) are recorded by GUID/age/path; no matching PDB was supplied or loaded. Recover them only from an authorized matching source, then rerun type/symbol analysis.
- Native REA provider blocked by missing Ghidra/JDK and release-host restrictions. Supply Ghidra 12.1.x + host JDK 21+, run rea doctor, then REA analyze/decompile on the original read-only inputs.
- Reconstruct MpClient/MpSvc RPC NDR procedure/type tables, plugin engine callback layouts, COM implementation vtables, complete UI/command state machines, and undocumented file formats before attempting full DLL replacements.
- Decode dialogs, menus, accelerators, MUI and WEVT semantic tables fully; cross-check TYPELIB against Windows LoadTypeLib or Wine. The present bounded MSFT decoder covers this supplied artifact, not arbitrary hostile typelibs.
- Full Windows integration requires an isolated VM with matching services, registry, external engine/driver/signature data. Neither Wine nor a Windows VM is available; no service/UI execution or live network behavior has been tested.
- Only the MpAsDesc non-tracing resolver has a meaningful buildable behavior model. No stubs falsely stand in for unrecovered modules.
