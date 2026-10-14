# Module analysis

Scope: all inputs structurally inventoried; bounded automated native analysis; selected disassembly review and isolated instruction emulation. **Not complete semantic reconstruction.** Addresses are preferred-image VAs unless marked RVA or file offset. Names in version resources describe intended roles, not verified runtime behavior.

## MSASCui.exe

User-interface version description; imports user32, GDI/GDI+, common controls, accessibility and MpClient. Event flow, dialog semantics, COM/RPC callbacks and UI state transitions are not fully reviewed.

Version resource: **6.1.7601.23403 (win7sp1_ldr.160325-0600)**. COFF timestamp `2016-03-25T17:59:04+00:00` (not authenticated). Linker field `9.0`; native x64 with CLI directory absent.

Entry RVA `0x9d374`; 3349 unwind table entries; 3062 relocation entries (including padding types); resource leaf counts `{'3': 10, '14': 1, '16': 1, '24': 1}`.

- String evidence, file offset `0x56d0`: `http://`
- String evidence, file offset `0x58b0`: `Software\Microsoft\RecoveryEnvironment`
- String evidence, file offset `0x5d68`: `LastScanType`
- String evidence, file offset `0xc3a10`: `.?AVCUpdateContext@CSignatureUpdateController@ThreatAbstraction@@`
- String evidence, file offset `0xc3a70`: `.?AVCSignatureUpdateController@ThreatAbstraction@@`
- String evidence, file offset `0xcefb1`: `    <asmv3:windowsSettings xmlns="http://schemas.microsoft.com/SMI/2005/WindowsSettings">`

Function status: bounded pass complete; 3665/5073 candidates emitted pseudocode. See `modules/MSASCui.exe/function-coverage.json`, `calls.json`, `xrefs.json`, `indirect-jumps.json` and `objdump.txt.gz`. For resource-only images, call graphs and pseudocode are inapplicable.

## MpAsDesc.dll

Resource-description helper. Both exports manually reviewed; a buildable resolver model and emulation tests cover non-tracing behavior. See src/MpAsDesc.dll/reviewed-behavior.md.

Version resource: **6.1.7601.23403 (win7sp1_ldr.160325-0600)**. COFF timestamp `2016-03-25T18:59:41+00:00` (not authenticated). Linker field `9.0`; native x64 with CLI directory absent.

Entry RVA `0x1cb0`; 26 unwind table entries; 8 relocation entries (including padding types); resource leaf counts `{'MUI': 1, '16': 1}`.


Function status: bounded pass complete; 52/52 candidates emitted pseudocode. See `modules/MpAsDesc.dll/function-coverage.json`, `calls.json`, `xrefs.json`, `indirect-jumps.json` and `objdump.txt.gz`. For resource-only images, call graphs and pseudocode are inapplicable.

## MpClient.dll

Central exported client façade (52 exports). MpConfig*, MpScan*, MpThreat*, cleaning and handle APIs are named in exports. RPC import and ncalrpc string evidence supports local RPC participation, but no complete NDR/IDL contract has been recovered.

Version resource: **6.1.7601.23403 (win7sp1_ldr.160325-0600)**. COFF timestamp `2016-03-25T18:59:42+00:00` (not authenticated). Linker field `9.0`; native x64 with CLI directory absent.

Entry RVA `0x63de8`; 2062 unwind table entries; 1632 relocation entries (including padding types); resource leaf counts `{'16': 1}`.

- String evidence, file offset `0x6be0`: `ncalrpc`
- String evidence, file offset `0x6f80`: `SOFTWARE\Microsoft\Windows\Windows Error Reporting\Consent`
- String evidence, file offset `0x7190`: `SOFTWARE\Microsoft\%MpOffline_ProductName%\UX Configuration`
- String evidence, file offset `0x7210`: `SOFTWARE\Microsoft\%MpOffline_ProductName%\Threats\ThreatTypeDefaultAction`
- String evidence, file offset `0x72b0`: `SOFTWARE\Microsoft\%MpOffline_ProductName%\Threats\ThreatSeverityDefaultAction`
- String evidence, file offset `0x7350`: `SOFTWARE\Microsoft\%MpOffline_ProductName%\Threats\ThreatIDDefaultAction`
- String evidence, file offset `0x73f0`: `SOFTWARE\Microsoft\%MpOffline_ProductName%\Threats`
- String evidence, file offset `0x7460`: `SOFTWARE\Microsoft\%MpOffline_ProductName%\SpyNet`
- String evidence, file offset `0x74d0`: `SOFTWARE\Microsoft\%MpOffline_ProductName%\Signature Updates`
- String evidence, file offset `0x7550`: `SOFTWARE\Microsoft\%MpOffline_ProductName%\Scan`
- String evidence, file offset `0x75b0`: `SOFTWARE\Microsoft\%MpOffline_ProductName%\Reporting`
- String evidence, file offset `0x7620`: `SOFTWARE\Microsoft\%MpOffline_ProductName%\Real-Time Protection\Checkpoints`
- String evidence, file offset `0x76c0`: `SOFTWARE\Microsoft\%MpOffline_ProductName%\Real-Time Protection`
- String evidence, file offset `0x7740`: `SOFTWARE\Microsoft\%MpOffline_ProductName%\Quarantine`
- String evidence, file offset `0x77b0`: `SOFTWARE\Microsoft\%MpOffline_ProductName%\Miscellaneous Configuration`
- String evidence, file offset `0x7840`: `SOFTWARE\Microsoft\%MpOffline_ProductName%\Exclusions\Processes`

Function status: bounded pass complete; 2701/3286 candidates emitted pseudocode. See `modules/MpClient.dll/function-coverage.json`, `calls.json`, `xrefs.json`, `indirect-jumps.json` and `objdump.txt.gz`. For resource-only images, call graphs and pseudocode are inapplicable.

## MpCmdRun.exe

Command-line utility by version metadata and embedded help strings; imports MpClient and Cabinet. Argument parser and command dispatch have automatic pseudocode but command behavior is not validated on Windows.

Version resource: **6.1.7601.23403 (win7sp1_ldr.160325-0600)**. COFF timestamp `2016-03-25T17:58:22+00:00` (not authenticated). Linker field `9.0`; native x64 with CLI directory absent.

Entry RVA `0x24ce8`; 537 unwind table entries; 222 relocation entries (including padding types); resource leaf counts `{'16': 1, '24': 1}`.

- String evidence, file offset `0x1158`: `   -RemoveDefinitions [-All]       Restores the installed signature definitions`
- String evidence, file offset `0x146e`: `   -SignatureUpdate                Checks for new definition updates`
- String evidence, file offset `0x14f8`: `   -Scan [-ScanType]               Scans for malicious software`
- String evidence, file offset `0x16b2`: `   -Scan [-ScanType]`
- String evidence, file offset `0x21f0`: `   -RemoveDefinitions`
- String evidence, file offset `0x26e8`: `SignatureUpdate`
- String evidence, file offset `0x2770`: `RemoveDefinitions`
- String evidence, file offset `0x2b90`: `ScanType`
- String evidence, file offset `0x33c8`: `NoSignatureUpdates`
- String evidence, file offset `0x3710`: `Start: MpSignatureUpdate()`
- String evidence, file offset `0x3770`: `MpCmdRun_SignatureUpdateTerminationTimeOut`
- String evidence, file offset `0x3948`: `Finish: MpSignatureUpdate()`
- String evidence, file offset `0x3a30`: `Start: MpRemoveDefinitions(%d)`
- String evidence, file offset `0x3bf8`: `Finish: MpRemoveDefinitions()`
- String evidence, file offset `0x7138`: `LastScanType`

Function status: bounded pass complete; 815/824 candidates emitted pseudocode. See `modules/MpCmdRun.exe/function-coverage.json`, `calls.json`, `xrefs.json`, `indirect-jumps.json` and `objdump.txt.gz`. For resource-only images, call graphs and pseudocode are inapplicable.

## MpCommu.dll

Communication/download subsystem: four MpCommunication exports, WinHTTP imports, SOAP/WS-Security literal templates and update URL strings. No network requests were made. Authentication/session/error semantics not fully reconstructed.

Version resource: **6.1.7601.23403 (win7sp1_ldr.160325-0600)**. COFF timestamp `2016-03-25T18:59:43+00:00` (not authenticated). Linker field `9.0`; native x64 with CLI directory absent.

Entry RVA `0x37690`; 1117 unwind table entries; 654 relocation entries (including padding types); resource leaf counts `{'16': 1}`.

- String evidence, file offset `0x13a0`: `http://go.microsoft.com/fwlink/?LinkID=121721&clcid=0x409&arch=%ls&eng=%ls&asdelta=%ls&prod=%ls`
- String evidence, file offset `0x1460`: `http://go.microsoft.com/fwlink/?LinkID=121721&clcid=0x409&arch=%ls&eng=%ls&avdelta=%ls&asdelta=%ls&prod=%ls`
- String evidence, file offset `0x1740`: `<wsse:UsernameToken xmlns:wsu="http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd" wsu:Id="`
- String evidence, file offset `0x1a30`: `<wsse:Password Type="http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-username-token-profile-1.0#PasswordDigest">`
- String evidence, file offset `0x1be0`: `<wsa:ReplyTo><wsa:Address>http://schemas.xmlsoap.org/ws/2004/08/addressing/role/anonymous</wsa:Address></wsa:ReplyTo>`
- String evidence, file offset `0x1ec0`: `<soap:Envelope xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema" xmlns:soap="http://schemas.xmlsoap.org/soap/envelope/" xmlns:wsa="http://schemas.xmlsoap.org/ws/2004/08/addressing" xmlns:wsse="http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd" xmlns:wsu="http://docs.oa`
- String evidence, file offset `0x2678`: `http://`
- String evidence, file offset `0x2800`: `http://Microsoft.com/AntiMalwareServices/SpynetReportSrvc`
- String evidence, file offset `0x37b0`: `HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\WindowsUpdate\Test`
- String evidence, file offset `0x4340`: `Software\Wow6432Node\Microsoft\PCHealth\ErrorReporting\DW\Installed`
- String evidence, file offset `0x47d0`: `SOFTWARE\Microsoft\Windows\Windows Error Reporting`
- String evidence, file offset `0x48238`: `.?AVCThreadContext@CSignatureUpdate@@`
- String evidence, file offset `0x48388`: `.?AVCSignatureUpdate@@`
- String evidence, file offset `0x483b0`: `.?AUISignatureUpdate@@`

Function status: bounded pass complete; 1698/1783 candidates emitted pseudocode. See `modules/MpCommu.dll/function-coverage.json`, `calls.json`, `xrefs.json`, `indirect-jumps.json` and `objdump.txt.gz`. For resource-only images, call graphs and pseudocode are inapplicable.

## MpEvMsg.dll

Resource-only event module, no executable section/entry/imports. WEVT_TEMPLATE contains CRIM/WEVT signatures; custom event schema retained as offset/hash/prefix and partial header facts. Requires a dedicated event-template parser for full reconstruction.

Version resource: **6.1.7600.16385 (win7_rtm.090713-1255)**. COFF timestamp `2009-07-14T01:29:17+00:00` (not authenticated). Linker field `9.0`; native x64 with CLI directory absent.

Entry RVA `0x0`; 0 unwind table entries; 0 relocation entries (including padding types); resource leaf counts `{'MUI': 1, 'WEVT_TEMPLATE': 1, '16': 1}`.


Function status: resource-only; no executable section; 0/0 candidates emitted pseudocode. See `modules/MpEvMsg.dll/function-coverage.json`, `calls.json`, `xrefs.json`, `indirect-jumps.json` and `objdump.txt.gz`. For resource-only images, call graphs and pseudocode are inapplicable.

## MpOAV.dll

IOfficeAntiVirus module by version metadata and embedded registry script. Four COM exports, with register/unregister aliases returning 0x80070032. Class-object factory error paths manually inspected. Actual scan interface/vtable still needs recovery.

Version resource: **6.1.7601.23403 (win7sp1_ldr.160325-0600)**. COFF timestamp `2016-03-25T18:59:50+00:00` (not authenticated). Linker field `9.0`; native x64 with CLI directory absent.

Entry RVA `0x8b94`; 171 unwind table entries; 172 relocation entries (including padding types); resource leaf counts `{'MUI': 1, 'REGISTRY': 1, '16': 1}`.


Function status: bounded pass complete; 333/334 candidates emitted pseudocode. See `modules/MpOAV.dll/function-coverage.json`, `calls.json`, `xrefs.json`, `indirect-jumps.json` and `objdump.txt.gz`. For resource-only images, call graphs and pseudocode are inapplicable.

## MpRTP.dll

Real-time monitor/plugin by version metadata and eight MpPlugin exports. State transitions, engine callback structures, concurrency and teardown semantics remain inferred in automatic code.

Version resource: **6.1.7601.23403 (win7sp1_ldr.160325-0600)**. COFF timestamp `2016-03-25T18:59:57+00:00` (not authenticated). Linker field `9.0`; native x64 with CLI directory absent.

Entry RVA `0x23ef8`; 721 unwind table entries; 310 relocation entries (including padding types); resource leaf counts `{'16': 1}`.

- String evidence, file offset `0x1c30`: `Software\Wow6432Node\Microsoft\PCHealth\ErrorReporting\DW\Installed`
- String evidence, file offset `0x20d0`: `SOFTWARE\Microsoft\Windows\Windows Error Reporting`
- String evidence, file offset `0x2d132`: `MpPluginGetState`
- String evidence, file offset `0x2d143`: `MpPluginInitialize`
- String evidence, file offset `0x2d156`: `MpPluginReportThreadStatus`
- String evidence, file offset `0x2d171`: `MpPluginSetEngine`
- String evidence, file offset `0x2d183`: `MpPluginSetState`
- String evidence, file offset `0x2d194`: `MpPluginSetUserInformation`
- String evidence, file offset `0x2d1af`: `MpPluginShutdown`
- String evidence, file offset `0x2d1c0`: `MpPluginStop`
- String evidence, file offset `0x2d848`: `.?AVCMpPluginWorkItemBase@RealtimeProtection@@`

Function status: bounded pass complete; 1106/1122 candidates emitted pseudocode. See `modules/MpRTP.dll/function-coverage.json`, `calls.json`, `xrefs.json`, `indirect-jumps.json` and `objdump.txt.gz`. For resource-only images, call graphs and pseudocode are inapplicable.

## MpSvc.dll

Service module exporting ServiceMain, ServiceCrtMain, SvchostPushServiceGlobals. RPC server imports, ncalrpc literal and plugin-name literals are present. mpengine.dll and mpfilter.sys string references point outside supplied inputs; complete scanning behavior cannot be recreated from this corpus alone.

Version resource: **6.1.7601.23403 (win7sp1_ldr.160325-0600)**. COFF timestamp `2016-03-25T18:59:59+00:00` (not authenticated). Linker field `9.0`; native x64 with CLI directory absent.

Entry RVA `0xb2204`; 3897 unwind table entries; 2210 relocation entries (including padding types); resource leaf counts `{'16': 1}`.

- String evidence, file offset `0x6d30`: `ncalrpc`
- String evidence, file offset `0x6ea0`: `MpPluginInitialize`
- String evidence, file offset `0x6eb8`: `MpPluginShutdown`
- String evidence, file offset `0x6ed0`: `MpPluginSetEngine`
- String evidence, file offset `0x6ee8`: `MpPluginReportThreadStatus`
- String evidence, file offset `0x6f08`: `MpPluginGetState`
- String evidence, file offset `0x6f20`: `MpPluginStop`
- String evidence, file offset `0x6f30`: `MpPluginSetState`
- String evidence, file offset `0x6f48`: `MpPluginSetUserInformation`
- String evidence, file offset `0x7198`: `SignatureUpdateInterval`
- String evidence, file offset `0x72b0`: `LastScanType`
- String evidence, file offset `0x8400`: `Software\Wow6432Node\Microsoft\PCHealth\ErrorReporting\DW\Installed`
- String evidence, file offset `0x9060`: `SignatureUpdate -ScheduleJob -RestrictPrivileges`
- String evidence, file offset `0x90d0`: `Scan -ScheduleJob -RestrictPrivileges -ScanType 1`
- String evidence, file offset `0xa740`: `SOFTWARE\Microsoft\Windows NT\CurrentVersion`
- String evidence, file offset `0xaa40`: `http://go.microsoft.com/fwlink/?linkid=37020&name=%s&threatid=%u`

Function status: bounded pass complete; 4019/5799 candidates emitted pseudocode. See `modules/MpSvc.dll/function-coverage.json`, `calls.json`, `xrefs.json`, `indirect-jumps.json` and `objdump.txt.gz`. For resource-only images, call graphs and pseudocode are inapplicable.

## MsMpCom.dll

COM utility with three dispatch-interface definitions recovered from embedded MSFT typelib (19 declared methods), six coclasses, one enum. Four COM exports; registration aliases return 0x80070032. Method metadata does not prove implementation behavior.

Version resource: **6.1.7601.23403 (win7sp1_ldr.160325-0600)**. COFF timestamp `2016-03-25T19:01:54+00:00` (not authenticated). Linker field `9.0`; native x64 with CLI directory absent.

Entry RVA `0x8fe0`; 188 unwind table entries; 210 relocation entries (including padding types); resource leaf counts `{'REGISTRY': 1, 'TYPELIB': 1, '16': 1}`.


Function status: bounded pass complete; 313/315 candidates emitted pseudocode. See `modules/MsMpCom.dll/function-coverage.json`, `calls.json`, `xrefs.json`, `indirect-jumps.json` and `objdump.txt.gz`. For resource-only images, call graphs and pseudocode are inapplicable.

## MsMpLics.dll

Resource-only license module: four RT_STRING blocks plus version. No executable code to decompile.

Version resource: **6.1.7601.23403 (win7sp1_ldr.160325-0600)**. COFF timestamp `2016-03-25T19:01:58+00:00` (not authenticated). Linker field `9.0`; native x64 with CLI directory absent.

Entry RVA `0x0`; 0 unwind table entries; 0 relocation entries (including padding types); resource leaf counts `{'6': 4, '16': 1}`.

- String evidence, file offset `0x6ca`: `AntiSpyware#SOFTWARE\Microsoft\Windows Defender,SOFTWARE\Policies\Microsoft\Windows Defender$925A3ACA-C353-458A-AC8D-A7E5EB378092`
- String evidence, file offset `0xbb0`: `KSignature Updates, CheckAlternateHttpLocation, , , MP_CONFIG_ORIGIN_POLICY,PReal-Time Protection, DisableBehaviorMonitoring, 1 , , MP_CONFIG_ORIGIN_DEFAULT,3., DisableAntiVirus, 1, , MP_CONFIG_ORIGIN_DEFAULT,MReal-Time Protection, DisableRealtimeMonitoring, , , MP_CONFIG_ORIGIN_POLICY,=., DisableRoutinelyTakingAction, , , MP_CONFIG_ORIGIN_POLICY,=`

Function status: resource-only; no executable section; 0/0 candidates emitted pseudocode. See `modules/MsMpLics.dll/function-coverage.json`, `calls.json`, `xrefs.json`, `indirect-jumps.json` and `objdump.txt.gz`. For resource-only images, call graphs and pseudocode are inapplicable.

## MsMpRes.dll

Resource library: 54 PNGs, AVI, bitmap, icons and MUI metadata. The sole export returns a saved module-handle global; 64-bit return instruction emulated. Runtime localization is not validated.

Version resource: **6.1.7601.23403 (win7sp1_ldr.160325-0600)**. COFF timestamp `2016-03-25T19:01:59+00:00` (not authenticated). Linker field `9.0`; native x64 with CLI directory absent.

Entry RVA `0x1a58`; 23 unwind table entries; 8 relocation entries (including padding types); resource leaf counts `{'AVI': 1, 'MUI': 1, 'PNG': 54, '2': 1, '3': 46, '14': 5, '16': 1}`.


Function status: bounded pass complete; 50/50 candidates emitted pseudocode. See `modules/MsMpRes.dll/function-coverage.json`, `calls.json`, `xrefs.json`, `indirect-jumps.json` and `objdump.txt.gz`. For resource-only images, call graphs and pseudocode are inapplicable.

## pt-BR__MpAsDesc.dll.mui

Resource-only Portuguese description satellite: RT_STRING, message table, version and MUI metadata. Localized IDs can be compared with the resolver table; actual Windows MUI lookup is not emulated.

Version resource: **6.1.7600.16385 (win7_rtm.090713-1255)**. COFF timestamp `2009-07-13T23:53:10+00:00` (not authenticated). Linker field `9.0`; native x64 with CLI directory absent.

Entry RVA `0x0`; 0 unwind table entries; 0 relocation entries (including padding types); resource leaf counts `{'MUI': 1, '6': 20, '11': 1, '16': 1}`.


Function status: resource-only; no executable section; 0/0 candidates emitted pseudocode. See `modules/pt-BR__MpAsDesc.dll.mui/function-coverage.json`, `calls.json`, `xrefs.json`, `indirect-jumps.json` and `objdump.txt.gz`. For resource-only images, call graphs and pseudocode are inapplicable.

## pt-BR__MpEvMsg.dll.mui

Resource-only Portuguese event-message satellite. Decoded message IDs/text/flags retain original resource/RVA provenance.

Version resource: **6.1.7600.16385 (win7_rtm.090713-1255)**. COFF timestamp `2009-07-13T23:53:11+00:00` (not authenticated). Linker field `9.0`; native x64 with CLI directory absent.

Entry RVA `0x0`; 0 unwind table entries; 0 relocation entries (including padding types); resource leaf counts `{'MUI': 1, '11': 1, '16': 1}`.


Function status: resource-only; no executable section; 0/0 candidates emitted pseudocode. See `modules/pt-BR__MpEvMsg.dll.mui/function-coverage.json`, `calls.json`, `xrefs.json`, `indirect-jumps.json` and `objdump.txt.gz`. For resource-only images, call graphs and pseudocode are inapplicable.

## pt-BR__MsMpRes.dll.mui

Resource-only Portuguese UI satellite. Strings decoded; two menu resources, ten dialogs and one accelerator are inventoried but their detailed control/menu layouts are not decoded.

Version resource: **6.1.7600.16385 (win7_rtm.090713-1255)**. COFF timestamp `2009-07-13T23:53:11+00:00` (not authenticated). Linker field `9.0`; native x64 with CLI directory absent.

Entry RVA `0x0`; 0 unwind table entries; 0 relocation entries (including padding types); resource leaf counts `{'MUI': 1, '4': 2, '5': 10, '6': 54, '9': 1, '16': 1}`.

- String evidence, file offset `0x4194`: `m<a href="http://go.microsoft.com/fwlink/?LinkId=52661">Exiba mais informa`
- String evidence, file offset `0x4366`: `Caminho do ArquivoIhttp://go.microsoft.com/fwlink/?linkid=37020&name=%1!s!&threatid=%2!I32u!.Exibir mais informa`
- String evidence, file offset `0x5002`: `Itens de alerta &baixo:e<a href="http://go.microsoft.com/fwlink/?LinkId=63849">Veja dicas de solu`
- String evidence, file offset `0x5cb4`: `es</A> e<A HREF="http://go.microsoft.com/fwlink/?linkid=104288">Leia a declara`
- String evidence, file offset `0x65de`: `o no computador.T<A HREF="http://go.microsoft.com/fwlink/?LinkId=55273">Site do Windows Defender</A> `
- String evidence, file offset `0x800a`: `o atualizada, acesse o site do <a href="http://go.microsoft.com/fwlink/?LinkId=55273">Centro de Download da Microsoft</a> `
- String evidence, file offset `0x9554`: `Erro: 0x%1!0x!.e<a href="http://go.microsoft.com/fwlink/?LinkId=67233">Veja dicas de solu`
- String evidence, file offset `0x960a`: `o de problemas online</a> e<a href="http://go.microsoft.com/fwlink/?LinkId=67234">Veja dicas de solu`
- String evidence, file offset `0x96d6`: `o de problemas online</a> e<a href="http://go.microsoft.com/fwlink/?LinkId=67235">Veja dicas de solu`
- String evidence, file offset `0x99da`: `pia original agora,http://go.microsoft.com/fwlink/?linkid=62022%Deseja exibir os detalhes deste erro?-http://go.microsoft.com/fwlink/?linkid=104288`
- String evidence, file offset `0xb160`: `http://go.microsoft.com/fwlink/?LinkID=96776`
- String evidence, file offset `0xb6d0`: `<a href="http://go.microsoft.com/fwlink/?LinkID=96776">http://go.microsoft.com/fwlink/?LinkID=96776</a> `
- String evidence, file offset `0xc36c`: `k<A HREF="http://go.microsoft.com/fwlink/?LinkID=121338">Centro de Prote`

Function status: resource-only; no executable section; 0/0 candidates emitted pseudocode. See `modules/pt-BR__MsMpRes.dll.mui/function-coverage.json`, `calls.json`, `xrefs.json`, `indirect-jumps.json` and `objdump.txt.gz`. For resource-only images, call graphs and pseudocode are inapplicable.
