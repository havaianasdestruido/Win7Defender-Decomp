# Input provenance, licensing, and redistribution status

**Record:** PROV-2026-10-15-001

**Machine-readable inventory:** [`input-provenance.json`](input-provenance.json)

## Acquisition statement

On 2026-10-15 the project sponsor reported that the 17 files now under `bin/`
were extracted from an **authorized Windows 7 installation or installation
medium**. They first appear in repository commit
`9638320b682dfbed9eb0455750d78fac384b6598` at 2026-10-14 18:18:33 -03:00,
supplied by `github:havaianasdestruido`. Commit
`33232708e2502dcd5cb9335157140a2fd8457e27` moved the same Git blobs under
`bin/` two minutes later.

The sponsor did not supply the Windows edition, precise installation or media
identifier, source volume/image hash, extraction date or tool, or pre-Git chain
of custody. Those fields are `null` in the record. They are unknown, not
silently inferred from PE version metadata. The source statement is recorded as
reported and has not been independently authenticated.

## Identity

Every regular file recursively under `bin/` has an individual entry containing:

- byte length;
- SHA-256;
- SHA-512;
- repository-format Git blob SHA-1;
- original and current repository paths and commits;
- acquisition-event reference; and
- file-specific copyright, license, and redistribution findings.

The SHA-256 values agree with the prior structural inventory. The governance
validator rehashes the current files and checks the complete path set, all three
identities, sizes, acquisition references, and original Git blobs.

## License interpretation

The 15 PE/MUI files identify Microsoft Corporation and “All rights reserved” in
version resources. No license grant was recovered from those images. The text
in `bin/LICENSE` is an Unlicense/public-domain dedication, but its author,
provenance, and authority over neighboring files are not identified. Merely
placing it beside Microsoft files does not establish that it licenses them.

Accordingly:

- no PE/MUI input is marked redistributable by this project record;
- AUTH-2026-10-15-001 authorizes project work and redistribution of a resulting
  clean-team implementation, **not** redistribution of original inputs;
- original-file redistribution requires a separate valid license or legal basis
  and review; and
- the license and 14-byte README are themselves retained as provenance evidence
  with their uncertainty recorded individually.

This is a conservative evidence status, not a legal conclusion that every use
or repository copy is unlawful. Applicable statutory exceptions and licenses
must be evaluated by an authorized reviewer for the relevant jurisdiction and
use.

## File coverage

| Path | Bytes | SHA-256 | License / redistribution status |
|---|---:|---|---|
| `bin/LICENSE` | 1,211 | `6b0382b16279f26ff69014300541967a356a666eb0b91b422f6862f6b7dad17e` | Unlicense text; author and applicability unverified |
| `bin/MSASCui.exe` | 960,512 | `aee55998074a62400809df27d276a3cac90210de4efcc5db88156de813098026` | Microsoft / all rights reserved; no redistribution grant identified |
| `bin/MpAsDesc.dll` | 10,752 | `cb11e89d0d48baad659f120a9bb66fec7aa47bca0866ae3677539801638010ef` | Microsoft / all rights reserved; no redistribution grant identified |
| `bin/MpClient.dll` | 571,904 | `af49ac6648d89c5f52020c7a53ef8fe341220936afa1aee74d5675a0969a5d45` | Microsoft / all rights reserved; no redistribution grant identified |
| `bin/MpCmdRun.exe` | 190,976 | `e21b38e77047ca809cf472a2b5bbd6c6b438fb05043408dcb5bf5bf4487cbed2` | Microsoft / all rights reserved; no redistribution grant identified |
| `bin/MpCommu.dll` | 314,880 | `0939cd55e8ace40c43d23dae420986b7c81aa31b16f51c2809b74543c706389f` | Microsoft / all rights reserved; no redistribution grant identified |
| `bin/MpEvMsg.dll` | 52,224 | `7880b025413338a7b114becb5dc67605fc7a97142c26fd12f765a64a21805842` | Microsoft / all rights reserved; no redistribution grant identified |
| `bin/MpOAV.dll` | 52,224 | `b2913b2234cc75b1e57517a0ad0ca229c258a670f44c579e5260913ac5fb0269` | Microsoft / all rights reserved; no redistribution grant identified |
| `bin/MpRTP.dll` | 200,192 | `e82f41ffe21897c806693dd197f61f00709d31f6edc3cb9f808d7cd9a33941b5` | Microsoft / all rights reserved; no redistribution grant identified |
| `bin/MpSvc.dll` | 1,011,712 | `83331020ceb57c5e7222992914ae9f45cda725e80c3f72d6335bad5a921a2fa7` | Microsoft / all rights reserved; no redistribution grant identified |
| `bin/MsMpCom.dll` | 60,928 | `9e8396674ed1969a87e8108f9beceb8df84e5a5b1d52a40d694c3af88c9887a0` | Microsoft / all rights reserved; no redistribution grant identified |
| `bin/MsMpLics.dll` | 4,608 | `8c7baf81986a1d39964b8ab74a188443987df6b84bb82470ea849e438234a10a` | Microsoft / all rights reserved; no redistribution grant identified |
| `bin/MsMpRes.dll` | 487,936 | `87116782261671ab9790228dcd67a641f09464dcf81b9fe6a07b4a0e7cc57d14` | Microsoft / all rights reserved; no redistribution grant identified |
| `bin/README.md` | 14 | `f14a1935c7681d97ef9783c9b78ccc383c5ae78749a9b30320d5d496b2f90554` | No file-specific license; applicability of neighboring text unverified |
| `bin/pt-BR/MpAsDesc.dll.mui` | 38,912 | `e216a0aa285b6cbe242af409ff1a27678652c9c30b065f85d1ea2fec748d3586` | Microsoft / all rights reserved; no redistribution grant identified |
| `bin/pt-BR/MpEvMsg.dll.mui` | 16,384 | `c9c0337c6758cc8fe1b13130c1fcc730483e23728579f2d2095f3c9f303ac885` | Microsoft / all rights reserved; no redistribution grant identified |
| `bin/pt-BR/MsMpRes.dll.mui` | 52,224 | `ea1c9d52806befb7885eb6b768cd38c5009a5af202f1decd6a5c530f250412a2` | Microsoft / all rights reserved; no redistribution grant identified |

The table is a human index. `input-provenance.json` is authoritative for the
full SHA-512, Git identity, source event, and per-file status text.
