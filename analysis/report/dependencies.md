# Dependencies

Static imports are observed loader dependencies, not proof that every imported function executes. DLL-name strings are candidates, not observed runtime loads. No imports were resolved against arbitrary Linux substitutes.

## MSASCui.exe

- `ADVAPI32.dll`: 15 entries; external runtime dependency.
- `COMCTL32.dll`: 8 entries; external runtime dependency.
- `COMDLG32.dll`: 2 entries; external runtime dependency.
- `GDI32.dll`: 35 entries; external runtime dependency.
- `KERNEL32.dll`: 87 entries; external runtime dependency.
- `MpClient.dll`: 35 entries; supplied in bin/.
- `MsMpRes.dll`: 1 entries; supplied in bin/.
- `OLEACC.dll`: 2 entries; external runtime dependency.
- `OLEAUT32.dll`: 24 entries; external runtime dependency.
- `RPCRT4.dll`: 9 entries; external runtime dependency.
- `SHELL32.dll`: 7 entries; external runtime dependency.
- `SHLWAPI.dll`: 8 entries; external runtime dependency.
- `USER32.dll`: 121 entries; external runtime dependency.
- `VERSION.dll`: 3 entries; external runtime dependency.
- `gdiplus.dll`: 47 entries; external runtime dependency.
- `msvcrt.dll`: 58 entries; external runtime dependency.
- `ole32.dll`: 5 entries; external runtime dependency.

Other filename **string candidates**, not confirmed dynamic resolutions:
- File offset `0x4690`: `pchealth\helpctr\binaries\helpctr.exe`
- File offset `0x52a0`: `%windir%\hh.exe`
- File offset `0x5668`: `MSFTEDIT.DLL`
- File offset `0x57e8`: `%s\System32\ntdll.dll`
- File offset `0x6a3c`: `*.EXE`
- File offset `0xc05c0`: `mpas-fe.exe`
- File offset `0xc05d8`: `mpam-fe.exe`
- File offset `0xcf310`: `MSASCUI.exe`

## MpAsDesc.dll

- `ADVAPI32.dll`: 6 entries; external runtime dependency.
- `KERNEL32.dll`: 19 entries; external runtime dependency.
- `USER32.dll`: 1 entries; external runtime dependency.
- `msvcrt.dll`: 7 entries; external runtime dependency.

Other filename **string candidates**, not confirmed dynamic resolutions:
- File offset `0x1d6c`: `MpAsDesc.dll`
- File offset `0x254c`: `mpasdesc.dll`

## MpClient.dll

- `ADVAPI32.dll`: 51 entries; external runtime dependency.
- `CRYPT32.dll`: 1 entries; external runtime dependency.
- `KERNEL32.dll`: 96 entries; external runtime dependency.
- `OLEAUT32.dll`: 5 entries; external runtime dependency.
- `RPCRT4.dll`: 11 entries; external runtime dependency.
- `SHELL32.dll`: 1 entries; external runtime dependency.
- `USER32.dll`: 1 entries; external runtime dependency.
- `USERENV.dll`: 2 entries; external runtime dependency.
- `VERSION.dll`: 3 entries; external runtime dependency.
- `WINTRUST.dll`: 9 entries; external runtime dependency.
- `msvcrt.dll`: 45 entries; external runtime dependency.
- `ole32.dll`: 3 entries; external runtime dependency.

Other filename **string candidates**, not confirmed dynamic resolutions:
- File offset `0x6770`: `msmplics.dll`
- File offset `0x6800`: `winhttp.dll`
- File offset `0x6d70`: `%MpOffline_ProductPath%\\MsASCUI.exe`
- File offset `0x6dc0`: `%MpOffline_ProductPath%\\MpSvc.dll`
- File offset `0x6e10`: `%MpOffline_ProductPath%\\MpClient.dll`
- File offset `0x7030`: `%MpOffline_ProductPath%\MsMpCom.dll`
- File offset `0x7e50`: `%MpOffline_ProductPath%\MsMpEng.exe`
- File offset `0x7ea0`: `%MpOffline_ProductPath%\mpam-fe.exe`
- File offset `0x85c8`: `verifier.dll`
- File offset `0x85e8`: `vrfcore.dll`
- File offset `0x8b70`: `\MsMpLics.dll`
- File offset `0x8f28`: `MpAsDesc.dll`
- File offset `0xb688`: `Authz.dll`
- File offset `0xb898`: `MpCommu.dll`
- File offset `0xb930`: `SOFTWARE\Microsoft\MpDebug\DebugValues\MsMpEng.exe`
- File offset `0x7f170`: `MpClient.dll`
- File offset `0x89ee0`: `mpclient.dll`

## MpCmdRun.exe

- `ADVAPI32.dll`: 29 entries; external runtime dependency.
- `Cabinet.dll`: 4 entries; external runtime dependency.
- `KERNEL32.dll`: 58 entries; external runtime dependency.
- `MpClient.dll`: 21 entries; supplied in bin/.
- `OLEAUT32.dll`: 2 entries; external runtime dependency.
- `RPCRT4.dll`: 1 entries; external runtime dependency.
- `USERENV.dll`: 4 entries; external runtime dependency.
- `msvcrt.dll`: 64 entries; external runtime dependency.
- `ole32.dll`: 4 entries; external runtime dependency.

Other filename **string candidates**, not confirmed dynamic resolutions:
- File offset `0x82d8`: `\MsMpLics.dll`
- File offset `0x9578`: `wevtapi.dll`
- File offset `0xa488`: `MpCommu.dll`
- File offset `0x2e120`: `MpCmdRun.exe`

## MpCommu.dll

- `ADVAPI32.dll`: 20 entries; external runtime dependency.
- `KERNEL32.dll`: 58 entries; external runtime dependency.
- `MpClient.dll`: 15 entries; supplied in bin/.
- `OLEAUT32.dll`: 7 entries; external runtime dependency.
- `USER32.dll`: 1 entries; external runtime dependency.
- `VERSION.dll`: 3 entries; external runtime dependency.
- `WINHTTP.dll`: 18 entries; external runtime dependency.
- `msvcrt.dll`: 36 entries; external runtime dependency.
- `ole32.dll`: 6 entries; external runtime dependency.
- `urlmon.dll`: 1 entries; external runtime dependency.

Other filename **string candidates**, not confirmed dynamic resolutions:
- File offset `0x12b0`: `%ls\mpam-%x.exe`
- File offset `0x1990`: `Crypt32.dll`
- File offset `0x2bf0`: `qmgr.dll`
- File offset `0x2c08`: `wuaueng.dll`
- File offset `0x2c20`: `MpSigDwn.dll`
- File offset `0x46f8`: `Wer.dll`
- File offset `0x4988`: `MsMpLics.dll`
- File offset `0x46e80`: `MpCommu.dll`
- File offset `0x4c104`: `MpCommu.dll`

## MpEvMsg.dll


Other filename **string candidates**, not confirmed dynamic resolutions:
- File offset `0x4d4`: `MpEvMsg.dll`
- File offset `0x594`: `MpEvMsg.dll`

## MpOAV.dll

- `ADVAPI32.dll`: 9 entries; external runtime dependency.
- `KERNEL32.dll`: 40 entries; external runtime dependency.
- `msvcrt.dll`: 24 entries; external runtime dependency.
- `ole32.dll`: 2 entries; external runtime dependency.

Other filename **string candidates**, not confirmed dynamic resolutions:
- File offset `0x1688`: `%s\MPCLIENT.DLL`
- File offset `0xa5e0`: `MpOAv.DLL`
- File offset `0xc194`: `MpOAV.dll`

## MpRTP.dll

- `ADVAPI32.dll`: 27 entries; external runtime dependency.
- `KERNEL32.dll`: 51 entries; external runtime dependency.
- `MpClient.dll`: 14 entries; supplied in bin/.
- `PSAPI.DLL`: 1 entries; external runtime dependency.
- `VERSION.dll`: 3 entries; external runtime dependency.
- `msvcrt.dll`: 35 entries; external runtime dependency.
- `tdh.dll`: 2 entries; external runtime dependency.

Other filename **string candidates**, not confirmed dynamic resolutions:
- File offset `0x1ff0`: `Wer.dll`
- File offset `0x2268`: `MsMpLics.dll`
- File offset `0x2d128`: `MpRtp.dll`
- File offset `0x306f0`: `mprtp.dll`

## MpSvc.dll

- `ADVAPI32.dll`: 53 entries; external runtime dependency.
- `KERNEL32.dll`: 109 entries; external runtime dependency.
- `MpClient.dll`: 24 entries; supplied in bin/.
- `OLEAUT32.dll`: 3 entries; external runtime dependency.
- `RPCRT4.dll`: 14 entries; external runtime dependency.
- `VERSION.dll`: 3 entries; external runtime dependency.
- `WTSAPI32.dll`: 2 entries; external runtime dependency.
- `msvcrt.dll`: 44 entries; external runtime dependency.
- `ole32.dll`: 5 entries; external runtime dependency.
- `sfc.dll`: 1 entries; external runtime dependency.

Other filename **string candidates**, not confirmed dynamic resolutions:
- File offset `0x6508`: `msmplics.dll`
- File offset `0x65f0`: `mpengine.dll`
- File offset `0x6d10`: `verifier.dll`
- File offset `0x6dee`: `xrpcrt4.dll`
- File offset `0x6e58`: `mprtp.dll`
- File offset `0x75f0`: `mpsvc.dll`
- File offset `0x7608`: `Drivers\mpfilter\mpfilter.sys`
- File offset `0x77a0`: `SrClient.dll`
- File offset `0x8180`: `Wer.dll`
- File offset `0x8e88`: `MpCmdRun.exe`
- File offset `0x93c0`: `psapi.dll`
- File offset `0xaba0`: `wscapi.dll`
- File offset `0xae00`: `MsMpRes.dll`
- File offset `0xb240`: `MpSvc.dll`
- File offset `0xb258`: `msascui.exe`
- File offset `0xc618`: `MsMpLics.dll`
- File offset `0xe30e6`: `MpSvc.dll`
- File offset `0xf4c20`: `MpSvc.dll`
- File offset `0xf4cdc`: `MpSvc.dll`

## MsMpCom.dll

- `ADVAPI32.dll`: 15 entries; external runtime dependency.
- `KERNEL32.dll`: 30 entries; external runtime dependency.
- `MpClient.dll`: 22 entries; supplied in bin/.
- `OLEAUT32.dll`: 8 entries; external runtime dependency.
- `RPCRT4.dll`: 1 entries; external runtime dependency.
- `USER32.dll`: 1 entries; external runtime dependency.
- `msvcrt.dll`: 29 entries; external runtime dependency.
- `ole32.dll`: 4 entries; external runtime dependency.

Other filename **string candidates**, not confirmed dynamic resolutions:
- File offset `0x958`: `dllhost.exe`
- File offset `0xb100`: `MsMpCom.DLL`
- File offset `0xcf80`: `MsMpCom.dll`

## MsMpLics.dll


Other filename **string candidates**, not confirmed dynamic resolutions:
- File offset `0x5ac`: `MsMpLics.dll`

## MsMpRes.dll

- `ADVAPI32.dll`: 6 entries; external runtime dependency.
- `KERNEL32.dll`: 19 entries; external runtime dependency.
- `msvcrt.dll`: 7 entries; external runtime dependency.

Other filename **string candidates**, not confirmed dynamic resolutions:
- File offset `0x1ab2`: `MsMpRes.dll`
- File offset `0x76cdc`: `MsMpRes.dll`

## pt-BR__MpAsDesc.dll.mui


## pt-BR__MpEvMsg.dll.mui


Other filename **string candidates**, not confirmed dynamic resolutions:
- File offset `0x3de0`: `MpEvMsg.dll`

## pt-BR__MsMpRes.dll.mui


## Corpus boundaries and unresolved load relationships

`msmpeng.exe`, `mpengine.dll`, `mpfilter.sys`, signature databases and matching PDB files are not in bin/. References to them do not establish exact versions, protocols or successful loads. The independent Capstone pass traces literal GetProcAddress arguments for all eight MpPlugin names in MpSvc, several MpCommunication names in MpClient and MpClient entry points in MpOAV. These match supplied exports, but module-handle provenance and runtime success remain unverified; do not label them as observed runtime edges. Satellite basenames/locales establish packaging relationships, not tested loader selection. Version resources mix 6.1.7601.23403 native components with 6.1.7600.16385 event/localized resources; compatibility across this mix is untested.
