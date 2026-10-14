# Input inventory

All inputs opened read-only. Timestamps are untrusted COFF header values, not provenance proofs. SHA-256 identities are checked separately after analysis.

| File | Bytes | Format / architecture | SHA-256 | Status |
|---|---:|---|---|---|
| `bin/LICENSE` | 1211 | text / n/a | `6b0382b16279f26ff69014300541967a356a666eb0b91b422f6862f6b7dad17e` | inventoried; non-executable input |
| `bin/MSASCui.exe` | 960512 | PE32+ / IMAGE_FILE_MACHINE_AMD64 | `aee55998074a62400809df27d276a3cac90210de4efcc5db88156de813098026` | structural analysis complete; semantic coverage tracked separately |
| `bin/MpAsDesc.dll` | 10752 | PE32+ / IMAGE_FILE_MACHINE_AMD64 | `cb11e89d0d48baad659f120a9bb66fec7aa47bca0866ae3677539801638010ef` | structural analysis complete; semantic coverage tracked separately |
| `bin/MpClient.dll` | 571904 | PE32+ / IMAGE_FILE_MACHINE_AMD64 | `af49ac6648d89c5f52020c7a53ef8fe341220936afa1aee74d5675a0969a5d45` | structural analysis complete; semantic coverage tracked separately |
| `bin/MpCmdRun.exe` | 190976 | PE32+ / IMAGE_FILE_MACHINE_AMD64 | `e21b38e77047ca809cf472a2b5bbd6c6b438fb05043408dcb5bf5bf4487cbed2` | structural analysis complete; semantic coverage tracked separately |
| `bin/MpCommu.dll` | 314880 | PE32+ / IMAGE_FILE_MACHINE_AMD64 | `0939cd55e8ace40c43d23dae420986b7c81aa31b16f51c2809b74543c706389f` | structural analysis complete; semantic coverage tracked separately |
| `bin/MpEvMsg.dll` | 52224 | PE32+ / IMAGE_FILE_MACHINE_AMD64 | `7880b025413338a7b114becb5dc67605fc7a97142c26fd12f765a64a21805842` | structural analysis complete; semantic coverage tracked separately |
| `bin/MpOAV.dll` | 52224 | PE32+ / IMAGE_FILE_MACHINE_AMD64 | `b2913b2234cc75b1e57517a0ad0ca229c258a670f44c579e5260913ac5fb0269` | structural analysis complete; semantic coverage tracked separately |
| `bin/MpRTP.dll` | 200192 | PE32+ / IMAGE_FILE_MACHINE_AMD64 | `e82f41ffe21897c806693dd197f61f00709d31f6edc3cb9f808d7cd9a33941b5` | structural analysis complete; semantic coverage tracked separately |
| `bin/MpSvc.dll` | 1011712 | PE32+ / IMAGE_FILE_MACHINE_AMD64 | `83331020ceb57c5e7222992914ae9f45cda725e80c3f72d6335bad5a921a2fa7` | structural analysis complete; semantic coverage tracked separately |
| `bin/MsMpCom.dll` | 60928 | PE32+ / IMAGE_FILE_MACHINE_AMD64 | `9e8396674ed1969a87e8108f9beceb8df84e5a5b1d52a40d694c3af88c9887a0` | structural analysis complete; semantic coverage tracked separately |
| `bin/MsMpLics.dll` | 4608 | PE32+ / IMAGE_FILE_MACHINE_AMD64 | `8c7baf81986a1d39964b8ab74a188443987df6b84bb82470ea849e438234a10a` | structural analysis complete; semantic coverage tracked separately |
| `bin/MsMpRes.dll` | 487936 | PE32+ / IMAGE_FILE_MACHINE_AMD64 | `87116782261671ab9790228dcd67a641f09464dcf81b9fe6a07b4a0e7cc57d14` | structural analysis complete; semantic coverage tracked separately |
| `bin/README.md` | 14 | text / n/a | `f14a1935c7681d97ef9783c9b78ccc383c5ae78749a9b30320d5d496b2f90554` | inventoried; non-executable input |
| `bin/pt-BR/MpAsDesc.dll.mui` | 38912 | PE32+ / IMAGE_FILE_MACHINE_AMD64 | `e216a0aa285b6cbe242af409ff1a27678652c9c30b065f85d1ea2fec748d3586` | structural analysis complete; semantic coverage tracked separately |
| `bin/pt-BR/MpEvMsg.dll.mui` | 16384 | PE32+ / IMAGE_FILE_MACHINE_AMD64 | `c9c0337c6758cc8fe1b13130c1fcc730483e23728579f2d2095f3c9f303ac885` | structural analysis complete; semantic coverage tracked separately |
| `bin/pt-BR/MsMpRes.dll.mui` | 52224 | PE32+ / IMAGE_FILE_MACHINE_AMD64 | `ea1c9d52806befb7885eb6b768cd38c5009a5af202f1decd6a5c530f250412a2` | structural analysis complete; semantic coverage tracked separately |

## Duplicate identities
[]

## Detailed evidence
`inventory.json` and `modules/<filename>/metadata.json` retain sections, entropy, header flags, compiler indicators (not compiler proof), debug/PDB identities, exceptions, TLS, load config, relocation entries, resource inventory, certificate records, overlay hashes and embedded-magic candidates. An MZ byte hit alone is not a nested executable. No general-purpose unpacking or nested archive extraction is claimed.
