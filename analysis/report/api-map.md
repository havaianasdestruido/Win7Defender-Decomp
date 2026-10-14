# Consolidated API map

PE names/ordinals/IAT addresses are verified table contents. The PE tables do not encode parameter/return types. Windows x64 ABI is the platform default, not evidence for a particular prototype. Full exact tables: `src/<module>/interfaces.json`. Automated inferred signatures: per-function coverage JSON and pseudocode. Manually supported declarations are explicitly identified below.

## MSASCui.exe

Image base `0x100000000`; entry RVA `0x9d374`. 467 imported symbol entries; 0 exports.


Imports: `ADVAPI32.dll` (15), `COMCTL32.dll` (8), `COMDLG32.dll` (2), `GDI32.dll` (35), `KERNEL32.dll` (87), `MpClient.dll` (35), `MsMpRes.dll` (1), `OLEACC.dll` (2), `OLEAUT32.dll` (24), `RPCRT4.dll` (9), `SHELL32.dll` (7), `SHLWAPI.dll` (8), `USER32.dll` (121), `VERSION.dll` (3), `gdiplus.dll` (47), `msvcrt.dll` (58), `ole32.dll` (5).

### Literal dynamic-lookup arguments

Independent Capstone pass over `.pdata` ranges. The listed string definition reaches the API argument within a local linear window without an intervening branch/call/register overwrite. Runtime reachability, incoming branches and the identity of GetProcAddress’s module handle remain unproven. Full instruction/definition evidence: dynamic-lookup-sites.json.

| Call VA | Imported API | Literal argument |
|---|---|---|
| `0x10001dd09` | LoadLibraryW | `advapi32` |
| `0x10001dd21` | GetProcAddress | `TraceMessage` |
| `0x10001dd6b` | GetProcAddress | `TraceMessageVa` |
| `0x10002c7d6` | LoadLibraryW | `MSFTEDIT.DLL` |

## MpAsDesc.dll

Image base `0x7ff25ce0000`; entry RVA `0x1cb0`. 33 imported symbol entries; 2 exports.

| Export | Ordinal | RVA | Forwarder |
|---|---:|---:|---|
| GetMpAsDescModuleHandle | 1 | `0x1758` | — |
| MpGetSignatureDescriptionResourceIdentifier | 2 | `0x1768` | — |

Imports: `ADVAPI32.dll` (6), `KERNEL32.dll` (19), `USER32.dll` (1), `msvcrt.dll` (7).

### Literal dynamic-lookup arguments

Independent Capstone pass over `.pdata` ranges. The listed string definition reaches the API argument within a local linear window without an intervening branch/call/register overwrite. Runtime reachability, incoming branches and the identity of GetProcAddress’s module handle remain unproven. Full instruction/definition evidence: dynamic-lookup-sites.json.

| Call VA | Imported API | Literal argument |
|---|---|---|
| `0x7ff25ce13d9` | LoadLibraryW | `advapi32` |
| `0x7ff25ce13f1` | GetProcAddress | `TraceMessage` |
| `0x7ff25ce143b` | GetProcAddress | `TraceMessageVa` |

## MpClient.dll

Image base `0x7ff3d360000`; entry RVA `0x63de8`. 228 imported symbol entries; 52 exports.

| Export | Ordinal | RVA | Forwarder |
|---|---:|---:|---|
| MpAllocMemory | 1 | `0x62d90` | — |
| MpCleanControl | 2 | `0x1eb00` | — |
| MpCleanOpen | 3 | `0x1e584` | — |
| MpCleanPrecheckStart | 4 | `0x1e948` | — |
| MpCleanStart | 5 | `0x1ea24` | — |
| MpClientUtilExportFunctions | 6 | `0x229bc` | — |
| MpClose | 7 | `0x19eec` | — |
| MpConfigClose | 8 | `0x21e50` | — |
| MpConfigDelValue | 9 | `0x21f94` | — |
| MpConfigGetValue | 10 | `0x21e74` | — |
| MpConfigGetValueAlloc | 11 | `0x21ee8` | — |
| MpConfigInitialize | 12 | `0x21e00` | — |
| MpConfigIteratorClose | 13 | `0x21e50` | — |
| MpConfigIteratorEnum | 14 | `0x21fec` | — |
| MpConfigIteratorOpen | 15 | `0x21fbc` | — |
| MpConfigOpen | 16 | `0x21e28` | — |
| MpConfigRegisterForNotifications | 17 | `0x2202c` | — |
| MpConfigSetValue | 18 | `0x21f54` | — |
| MpConfigUninitialize | 19 | `0x21e10` | — |
| MpConfigUnregisterNotifications | 20 | `0x22068` | — |
| MpDebugExportFunctions | 21 | `0x180b0` | — |
| MpElevateCleanHandle | 22 | `0x1fd24` | — |
| MpElevationHandleActivate | 23 | `0x24320` | — |
| MpElevationHandleAttach | 24 | `0x24070` | — |
| MpElevationHandleOpen | 25 | `0x23dbc` | — |
| MpErrorMessageFormat | 26 | `0x23754` | — |
| MpFreeMemory | 27 | `0x62d9c` | — |
| MpGetEngineVersion | 28 | `0x21850` | — |
| MpHandleClose | 29 | `0x196c4` | — |
| MpManagerDisable | 30 | `0x1b580` | — |
| MpManagerEnable | 31 | `0x1b344` | — |
| MpManagerOpen | 32 | `0x19228` | — |
| MpManagerStatusQuery | 33 | `0x19518` | — |
| MpManagerVersionQuery | 34 | `0x1935c` | — |
| MpNotificationRegister | 35 | `0x1a494` | — |
| MpOpen | 36 | `0x19ae4` | — |
| MpQuarantineRequest | 37 | `0x20cf0` | — |
| MpSampleQuery | 38 | `0x22c7c` | — |
| MpSampleSubmit | 39 | `0x230fc` | — |
| MpScanControl | 40 | `0x1bbf8` | — |
| MpScanResult | 41 | `0x1bdf8` | — |
| MpScanStart | 42 | `0x1ba2c` | — |
| MpThreatEnumerate | 43 | `0x1d12c` | — |
| MpThreatHistoryRequest | 44 | `0x1ddec` | — |
| MpThreatOpen | 45 | `0x1ccc8` | — |
| MpThreatQuery | 46 | `0x1d210` | — |
| MpUpdateControl | 47 | `0x24dc4` | — |
| MpUpdateEngine | 48 | `0x219b4` | — |
| MpUpdateStart | 49 | `0x24b08` | — |
| MpUtilsExportFunctions | 50 | `0x180c0` | — |
| WDEnable | 51 | `0x234b4` | — |
| WDStatus | 52 | `0x23288` | — |

Imports: `ADVAPI32.dll` (51), `CRYPT32.dll` (1), `KERNEL32.dll` (96), `OLEAUT32.dll` (5), `RPCRT4.dll` (11), `SHELL32.dll` (1), `USER32.dll` (1), `USERENV.dll` (2), `VERSION.dll` (3), `WINTRUST.dll` (9), `msvcrt.dll` (45), `ole32.dll` (3).

### Literal dynamic-lookup arguments

Independent Capstone pass over `.pdata` ranges. The listed string definition reaches the API argument within a local linear window without an intervening branch/call/register overwrite. Runtime reachability, incoming branches and the identity of GetProcAddress’s module handle remain unproven. Full instruction/definition evidence: dynamic-lookup-sites.json.

| Call VA | Imported API | Literal argument |
|---|---|---|
| `0x7ff3d378235` | LoadLibraryW | `advapi32` |
| `0x7ff3d37824d` | GetProcAddress | `TraceMessage` |
| `0x7ff3d378297` | GetProcAddress | `TraceMessageVa` |
| `0x7ff3d398b11` | GetProcAddress | `GetSystemMetrics` |
| `0x7ff3d398be4` | GetModuleHandleW | `verifier.dll` |
| `0x7ff3d398bf6` | GetModuleHandleW | `vrfcore.dll` |
| `0x7ff3d39a808` | GetModuleHandleW | `kernel32.dll` |
| `0x7ff3d39a829` | GetProcAddress | `EncodePointer` |
| `0x7ff3d39a841` | GetProcAddress | `DecodePointer` |
| `0x7ff3d39d59c` | GetModuleHandleW | `kernel32.dll` |
| `0x7ff3d39d5c5` | GetProcAddress | `CreateThreadpoolWork` |
| `0x7ff3d39d5fa` | GetProcAddress | `SubmitThreadpoolWork` |
| `0x7ff3d39d62f` | GetProcAddress | `WaitForThreadpoolWorkCallbacks` |
| `0x7ff3d39d664` | GetProcAddress | `CloseThreadpoolWork` |
| `0x7ff3d39d699` | GetProcAddress | `CreateThreadpool` |
| `0x7ff3d39d6ce` | GetProcAddress | `CloseThreadpool` |
| `0x7ff3d39d6ff` | GetProcAddress | `SetThreadpoolThreadMinimum` |
| `0x7ff3d39d730` | GetProcAddress | `SetThreadpoolThreadMaximum` |
| `0x7ff3d39fab4` | GetProcAddress | `MpGetSignatureDescriptionResourceIdentifier` |
| `0x7ff3d3bef07` | GetProcAddress | `EventRegister` |
| `0x7ff3d3bef42` | GetProcAddress | `EventUnregister` |
| `0x7ff3d3bef7d` | GetProcAddress | `EventEnabled` |
| `0x7ff3d3befb8` | GetProcAddress | `EventWrite` |
| `0x7ff3d3c0a82` | LoadLibraryW | `Authz.dll` |
| `0x7ff3d3c0afb` | GetProcAddress | `AuthzReportSecurityEventFromParams` |
| `0x7ff3d3c0b75` | GetProcAddress | `AuthzUnregisterSecurityEventSource` |
| `0x7ff3d3c0bef` | GetProcAddress | `AuthzRegisterSecurityEventSource` |
| `0x7ff3d3c10e2` | GetProcAddress | `MpCommunicationInitialize` |
| `0x7ff3d3c1128` | GetProcAddress | `MpCommunicationUninitialize` |
| `0x7ff3d3c116d` | GetProcAddress | `MpCommunicationCreateInstance` |
| `0x7ff3d3c31f7` | GetProcAddress | `MpDebugExportFunctions` |

## MpCmdRun.exe

Image base `0x100000000`; entry RVA `0x24ce8`. 187 imported symbol entries; 0 exports.


Imports: `ADVAPI32.dll` (29), `Cabinet.dll` (4), `KERNEL32.dll` (58), `MpClient.dll` (21), `OLEAUT32.dll` (2), `RPCRT4.dll` (1), `USERENV.dll` (4), `msvcrt.dll` (64), `ole32.dll` (4).

### Literal dynamic-lookup arguments

Independent Capstone pass over `.pdata` ranges. The listed string definition reaches the API argument within a local linear window without an intervening branch/call/register overwrite. Runtime reachability, incoming branches and the identity of GetProcAddress’s module handle remain unproven. Full instruction/definition evidence: dynamic-lookup-sites.json.

| Call VA | Imported API | Literal argument |
|---|---|---|
| `0x10000d069` | LoadLibraryW | `advapi32` |
| `0x10000d081` | GetProcAddress | `TraceMessage` |
| `0x10000d0cb` | GetProcAddress | `TraceMessageVa` |
| `0x10001bef3` | GetProcAddress | `EvtQuery` |
| `0x10001bf65` | GetProcAddress | `EvtCreateRenderContext` |
| `0x10001bfd1` | GetProcAddress | `EvtRender` |
| `0x10001c040` | GetProcAddress | `EvtNext` |
| `0x10001c0af` | GetProcAddress | `EvtClose` |
| `0x10001c11e` | GetProcAddress | `EvtOpenPublisherMetadata` |
| `0x10001c18d` | GetProcAddress | `EvtFormatMessage` |
| `0x100022d82` | GetProcAddress | `MpCommunicationInitialize` |
| `0x100022dc8` | GetProcAddress | `MpCommunicationUninitialize` |
| `0x100022e0d` | GetProcAddress | `MpCommunicationCreateInstance` |

## MpCommu.dll

Image base `0x7ff36340000`; entry RVA `0x37690`. 165 imported symbol entries; 4 exports.

| Export | Ordinal | RVA | Forwarder |
|---|---:|---:|---|
| MpCommunicationCreateInstance | 1 | `0xaf40` | — |
| MpCommunicationDownloadFile | 2 | `0xe460` | — |
| MpCommunicationInitialize | 3 | `0xad0c` | — |
| MpCommunicationUninitialize | 4 | `0xaed0` | — |

Imports: `ADVAPI32.dll` (20), `KERNEL32.dll` (58), `MpClient.dll` (15), `OLEAUT32.dll` (7), `USER32.dll` (1), `VERSION.dll` (3), `WINHTTP.dll` (18), `msvcrt.dll` (36), `ole32.dll` (6), `urlmon.dll` (1).

### Literal dynamic-lookup arguments

Independent Capstone pass over `.pdata` ranges. The listed string definition reaches the API argument within a local linear window without an intervening branch/call/register overwrite. Runtime reachability, incoming branches and the identity of GetProcAddress’s module handle remain unproven. Full instruction/definition evidence: dynamic-lookup-sites.json.

| Call VA | Imported API | Literal argument |
|---|---|---|
| `0x7ff3634a949` | LoadLibraryW | `advapi32` |
| `0x7ff3634a961` | GetProcAddress | `TraceMessage` |
| `0x7ff3634a9ab` | GetProcAddress | `TraceMessageVa` |
| `0x7ff363535c6` | LoadLibraryW | `Crypt32.dll` |
| `0x7ff3635365f` | GetProcAddress | `CryptBinaryToStringW` |
| `0x7ff363709b8` | LoadLibraryW | `Wer.dll` |
| `0x7ff36370a2f` | GetProcAddress | `WerReportCreate` |
| `0x7ff36370aa7` | GetProcAddress | `WerReportAddFile` |
| `0x7ff36370b1b` | GetProcAddress | `WerReportSubmit` |
| `0x7ff36370b98` | GetProcAddress | `WerReportCloseHandle` |
| `0x7ff36370c0c` | GetProcAddress | `WerReportSetParameter` |

## MpEvMsg.dll

Image base `0x400000`; entry RVA `0x0`. 0 imported symbol entries; 0 exports.


Imports: none.

## MpOAV.dll

Image base `0x7ff29100000`; entry RVA `0x8b94`. 75 imported symbol entries; 4 exports.

| Export | Ordinal | RVA | Forwarder |
|---|---:|---:|---|
| DllCanUnloadNow | 1 | `0x3ea8` | — |
| DllGetClassObject | 2 | `0x3ed4` | — |
| DllRegisterServer | 3 | `0x3ff4` | — |
| DllUnregisterServer | 4 | `0x3ff4` | — |

Imports: `ADVAPI32.dll` (9), `KERNEL32.dll` (40), `msvcrt.dll` (24), `ole32.dll` (2).

### Literal dynamic-lookup arguments

Independent Capstone pass over `.pdata` ranges. The listed string definition reaches the API argument within a local linear window without an intervening branch/call/register overwrite. Runtime reachability, incoming branches and the identity of GetProcAddress’s module handle remain unproven. Full instruction/definition evidence: dynamic-lookup-sites.json.

| Call VA | Imported API | Literal argument |
|---|---|---|
| `0x7ff29103ad9` | LoadLibraryW | `advapi32` |
| `0x7ff29103af1` | GetProcAddress | `TraceMessage` |
| `0x7ff29103b3b` | GetProcAddress | `TraceMessageVa` |
| `0x7ff2910583b` | GetProcAddress | `MpManagerOpen` |
| `0x7ff29105875` | GetProcAddress | `MpHandleClose` |
| `0x7ff291058af` | GetProcAddress | `MpFreeMemory` |
| `0x7ff291058e9` | GetProcAddress | `MpScanStart` |
| `0x7ff29105923` | GetProcAddress | `MpScanResult` |
| `0x7ff2910595d` | GetProcAddress | `MpThreatOpen` |
| `0x7ff29105997` | GetProcAddress | `MpThreatEnumerate` |
| `0x7ff291059d1` | GetProcAddress | `MpConfigOpen` |
| `0x7ff29105a07` | GetProcAddress | `MpConfigGetValue` |
| `0x7ff29105a3d` | GetProcAddress | `MpConfigClose` |
| `0x7ff29107d44` | GetModuleHandleW | `kernel32.dll` |
| `0x7ff29107d65` | GetProcAddress | `EncodePointer` |
| `0x7ff29107d7d` | GetProcAddress | `DecodePointer` |

## MpRTP.dll

Image base `0x7ff31900000`; entry RVA `0x23ef8`. 133 imported symbol entries; 8 exports.

| Export | Ordinal | RVA | Forwarder |
|---|---:|---:|---|
| MpPluginGetState | 1 | `0x6120` | — |
| MpPluginInitialize | 2 | `0x5b5c` | — |
| MpPluginReportThreadStatus | 3 | `0x6234` | — |
| MpPluginSetEngine | 4 | `0x5ecc` | — |
| MpPluginSetState | 5 | `0x5f70` | — |
| MpPluginSetUserInformation | 6 | `0x6338` | — |
| MpPluginShutdown | 7 | `0x5e0c` | — |
| MpPluginStop | 8 | `0x6040` | — |

Imports: `ADVAPI32.dll` (27), `KERNEL32.dll` (51), `MpClient.dll` (14), `PSAPI.DLL` (1), `VERSION.dll` (3), `msvcrt.dll` (35), `tdh.dll` (2).

### Literal dynamic-lookup arguments

Independent Capstone pass over `.pdata` ranges. The listed string definition reaches the API argument within a local linear window without an intervening branch/call/register overwrite. Runtime reachability, incoming branches and the identity of GetProcAddress’s module handle remain unproven. Full instruction/definition evidence: dynamic-lookup-sites.json.

| Call VA | Imported API | Literal argument |
|---|---|---|
| `0x7ff31905779` | LoadLibraryW | `advapi32` |
| `0x7ff31905791` | GetProcAddress | `TraceMessage` |
| `0x7ff319057db` | GetProcAddress | `TraceMessageVa` |
| `0x7ff319113a5` | LoadLibraryW | `Kernel32.dll` |
| `0x7ff31911405` | GetProcAddress | `GetVolumePathNamesForVolumeNameW` |
| `0x7ff3191d7a8` | LoadLibraryW | `Wer.dll` |
| `0x7ff3191d81f` | GetProcAddress | `WerReportCreate` |
| `0x7ff3191d897` | GetProcAddress | `WerReportAddFile` |
| `0x7ff3191d90b` | GetProcAddress | `WerReportSubmit` |
| `0x7ff3191d988` | GetProcAddress | `WerReportCloseHandle` |
| `0x7ff3191d9fc` | GetProcAddress | `WerReportSetParameter` |

## MpSvc.dll

Image base `0x7ff43100000`; entry RVA `0xb2204`. 258 imported symbol entries; 3 exports.

| Export | Ordinal | RVA | Forwarder |
|---|---:|---:|---|
| ServiceCrtMain | 1 | `0x1fedc` | — |
| ServiceMain | 2 | `0x1f3d4` | — |
| SvchostPushServiceGlobals | 3 | `0x1f3c4` | — |

Imports: `ADVAPI32.dll` (53), `KERNEL32.dll` (109), `MpClient.dll` (24), `OLEAUT32.dll` (3), `RPCRT4.dll` (14), `VERSION.dll` (3), `WTSAPI32.dll` (2), `msvcrt.dll` (44), `ole32.dll` (5), `sfc.dll` (1).

### Literal dynamic-lookup arguments

Independent Capstone pass over `.pdata` ranges. The listed string definition reaches the API argument within a local linear window without an intervening branch/call/register overwrite. Runtime reachability, incoming branches and the identity of GetProcAddress’s module handle remain unproven. Full instruction/definition evidence: dynamic-lookup-sites.json.

| Call VA | Imported API | Literal argument |
|---|---|---|
| `0x7ff4311f2a1` | LoadLibraryW | `advapi32` |
| `0x7ff4311f2b9` | GetProcAddress | `TraceMessage` |
| `0x7ff4311f303` | GetProcAddress | `TraceMessageVa` |
| `0x7ff431244ff` | GetProcAddress | `__rsignal` |
| `0x7ff43129abf` | GetModuleHandleW | `verifier.dll` |
| `0x7ff4312a726` | GetProcAddress | `MpPluginInitialize` |
| `0x7ff4312a772` | GetProcAddress | `MpPluginShutdown` |
| `0x7ff4312a7be` | GetProcAddress | `MpPluginSetEngine` |
| `0x7ff4312a80a` | GetProcAddress | `MpPluginReportThreadStatus` |
| `0x7ff4312a856` | GetProcAddress | `MpPluginGetState` |
| `0x7ff4312a8a2` | GetProcAddress | `MpPluginStop` |
| `0x7ff4312a8ee` | GetProcAddress | `MpPluginSetState` |
| `0x7ff4312a93a` | GetProcAddress | `MpPluginSetUserInformation` |
| `0x7ff4313c3d1` | LoadLibraryW | `SrClient.dll` |
| `0x7ff4313c422` | GetProcAddress | `SRSetRestorePointW` |
| `0x7ff4314e678` | GetProcAddress | `WerReportCreate` |
| `0x7ff4314e6e9` | GetProcAddress | `WerReportSetParameter` |
| `0x7ff4314e75a` | GetProcAddress | `WerReportAddFile` |
| `0x7ff4314e7cb` | GetProcAddress | `WerReportSubmit` |
| `0x7ff4314e83c` | GetProcAddress | `WerReportCloseHandle` |
| `0x7ff4314e8ad` | GetProcAddress | `WerReportAddDump` |
| `0x7ff4314ec0c` | GetModuleHandleW | `kernel32.dll` |
| `0x7ff4314ec6e` | GetProcAddress | `WerRegisterFile` |
| `0x7ff4315911e` | GetModuleHandleW | `kernel32.dll` |
| `0x7ff43159183` | GetProcAddress | `PowerCreateRequest` |
| `0x7ff431591e7` | GetProcAddress | `PowerSetRequest` |
| `0x7ff4315924b` | GetProcAddress | `PowerClearRequest` |
| `0x7ff43159fff` | GetModuleHandleW | `rpcrt4.dll` |
| `0x7ff4315e670` | GetProcAddress | `GetModuleFileNameExW` |
| `0x7ff431840ff` | GetProcAddress | `WscUnRegisterChanges` |
| `0x7ff43184263` | GetProcAddress | `WscGetSecurityProviderHealth` |
| `0x7ff431850b7` | GetProcAddress | `WscRegisterForChanges` |
| `0x7ff4318a6a3` | GetModuleHandleW | `MpSvc.dll` |
| `0x7ff431acfb5` | LoadLibraryW | `Wer.dll` |
| `0x7ff431ad032` | GetProcAddress | `WerReportCreate` |
| `0x7ff431ad0a4` | GetProcAddress | `WerReportAddFile` |
| `0x7ff431ad118` | GetProcAddress | `WerReportSubmit` |
| `0x7ff431ad18f` | GetProcAddress | `WerReportCloseHandle` |
| `0x7ff431ad211` | GetProcAddress | `WerReportSetParameter` |

## MsMpCom.dll

Image base `0x7ff28f20000`; entry RVA `0x8fe0`. 110 imported symbol entries; 4 exports.

| Export | Ordinal | RVA | Forwarder |
|---|---:|---:|---|
| DllCanUnloadNow | 1 | `0x399c` | — |
| DllGetClassObject | 2 | `0x39c8` | — |
| DllRegisterServer | 3 | `0x3b0c` | — |
| DllUnregisterServer | 4 | `0x3b0c` | — |

Imports: `ADVAPI32.dll` (15), `KERNEL32.dll` (30), `MpClient.dll` (22), `OLEAUT32.dll` (8), `RPCRT4.dll` (1), `USER32.dll` (1), `msvcrt.dll` (29), `ole32.dll` (4).

### Literal dynamic-lookup arguments

Independent Capstone pass over `.pdata` ranges. The listed string definition reaches the API argument within a local linear window without an intervening branch/call/register overwrite. Runtime reachability, incoming branches and the identity of GetProcAddress’s module handle remain unproven. Full instruction/definition evidence: dynamic-lookup-sites.json.

| Call VA | Imported API | Literal argument |
|---|---|---|
| `0x7ff28f235f9` | LoadLibraryW | `advapi32` |
| `0x7ff28f23611` | GetProcAddress | `TraceMessage` |
| `0x7ff28f2365b` | GetProcAddress | `TraceMessageVa` |

## MsMpLics.dll

Image base `0x400000`; entry RVA `0x0`. 0 imported symbol entries; 0 exports.


Imports: none.

## MsMpRes.dll

Image base `0x7ff3a080000`; entry RVA `0x1a58`. 32 imported symbol entries; 1 exports.

| Export | Ordinal | RVA | Forwarder |
|---|---:|---:|---|
| GetMsMpResModuleHandle | 1 | `0x1640` | — |

Imports: `ADVAPI32.dll` (6), `KERNEL32.dll` (19), `msvcrt.dll` (7).

### Literal dynamic-lookup arguments

Independent Capstone pass over `.pdata` ranges. The listed string definition reaches the API argument within a local linear window without an intervening branch/call/register overwrite. Runtime reachability, incoming branches and the identity of GetProcAddress’s module handle remain unproven. Full instruction/definition evidence: dynamic-lookup-sites.json.

| Call VA | Imported API | Literal argument |
|---|---|---|
| `0x7ff3a081369` | LoadLibraryW | `advapi32` |
| `0x7ff3a081381` | GetProcAddress | `TraceMessage` |
| `0x7ff3a0813cb` | GetProcAddress | `TraceMessageVa` |

## pt-BR__MpAsDesc.dll.mui

Image base `0x180000000`; entry RVA `0x0`. 0 imported symbol entries; 0 exports.


Imports: none.

## pt-BR__MpEvMsg.dll.mui

Image base `0x180000000`; entry RVA `0x0`. 0 imported symbol entries; 0 exports.


Imports: none.

## pt-BR__MsMpRes.dll.mui

Image base `0x180000000`; entry RVA `0x0`. 0 imported symbol entries; 0 exports.


Imports: none.
