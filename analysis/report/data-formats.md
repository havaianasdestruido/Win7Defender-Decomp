# Data formats and recovered structures

## Coordinates and evidence

All 15 images are little-endian AMD64 PE32+ (`Machine=0x8664`, optional magic `0x20b`). `inventory.json` supplies the complete per-image facts; `src/<module>/resources.json` preserves resource RVA, source file offset, byte length, language ID and SHA-256. No proprietary scan database sample is supplied: this report must not be mistaken for a definition/signature/quarantine file-format specification.

For a file-backed section, `file_offset = PointerToRawData + (RVA - VirtualAddress)` within its raw bounds. `VA = preferred_ImageBase + RVA`. Zero-filled virtual tails have no equivalent original file bytes. The security/certificate directory is the PE exception: its address is a file offset, not an RVA. Imported addresses in `interfaces.json` are IAT **VAs**, not resolved runtime targets.

## PE/COFF containers — decoded using pefile, checked against objdump and REA

- DOS signature `4d 5a`; little-endian dword `e_lfanew` at file offset `0x3c` locates `50 45 00 00`.
- COFF header follows the signature, 20 bytes; includes machine, number of sections, timestamp, symbol-table pointer/count, optional-header size and characteristics. Timestamps are unauthenticated metadata.
- PE32+ optional header contains 64-bit ImageBase at offset `0x18` relative to the optional header, entry RVA at `0x10`, alignments at `0x20/0x24`, SizeOfImage at `0x38`, checksum at `0x40`, subsystem/DllCharacteristics at `0x44/0x46`, and directory count at `0x6c`. Directory array begins at `0x70`; each pair is u32 address/u32 length. These are file-layout offsets, not a recommendation to cast an unaligned C pointer.
- Section records are 40 bytes: 8-byte name; VirtualSize at +8, RVA at +12, raw size at +16, raw offset at +20, flags at +36. Executable sections are selected by `IMAGE_SCN_MEM_EXECUTE=0x20000000`, not by name alone. `.text` in these files also contains data/import metadata; linear objdump output over it is not a perfect code classification.
- Resource leaves: `IMAGE_RESOURCE_DATA_ENTRY` is four u32 values (payload RVA, size, codepage, reserved). The three tree levels observed are type/name/language, with numeric or named type/name entries. Named directory entries carry high-bit-relative string offsets; leaf tables preserve language IDs, notably 1033 (en-US), 1046 (pt-BR) and any other observed values verbatim.
- Relocation entries: u16 high four bits type and low 12 bits page offset; block header is u32 page RVA/u32 block size. `DIR64=10` patches a 64-bit field; `ABSOLUTE=0` is padding, not a real pointer. Exact entries are retained; pointer targets are not all semantically named.
- AMD64 exception entries: three u32 RVAs, `{BeginAddress, EndAddress, UnwindData}`, 12 bytes, end exclusive. Unwind records may describe exception funclets. UNWIND_INFO begins with packed version/flags, prolog length, unwind-code count and frame-register/frame-offset bytes, followed by two-byte unwind codes and optional aligned handler/chained data. The project inventories runtime-function triples but does not fully reconstruct all language-specific exception scopes or destructor behavior.
- RSDS CodeView: `RSDS` magic, 16-byte mixed-endian GUID, u32 age, NUL-terminated PDB filename. Ten code-bearing images have these references; no PDB was loaded. `metadata.json/debug` records exact identifiers.
- No TLS directory, overlay, certificate table or valid nested PE was observed in this corpus (see validator and per-image evidence). Absence of an embedded signature does not assess possible external catalog signing. No cryptographic publisher authenticity was validated.

## Packing, nested data and instruction-set limits

No packer was established by this pass. The ten code-bearing images have conventional section names, parsable imports/unwind metadata and `.text` entropy roughly 5.7–6.1 bits/byte. Higher resource entropy (up to about 7.49) coincides with graphics-bearing resource sections; entropy alone is not a packer diagnosis. Embedded MZ/archive magic hits are retained as candidates, and no secondary MZ candidate had a valid nested PE signature under the recorded check. No unpacking was performed. A custom/stealth packer or an unrecognized container has **not** been ruled out by these heuristics.

AMD64 header identity and decoded x86-64 instructions are verified; a complete minimum-CPU feature audit is not. Do not infer an exact SSE/AVX requirement, source compiler version or original optimization flags solely from the machine/linker fields. Individual CFG/call/decode coverage remains explicit in module evidence.

## Decoded resource layouts

### RT_STRING (type 6)

Each block holds exactly 16 UTF-16LE strings: u16 code-unit length followed by that many u16 code units, without a mandatory terminator. String identifier = `(block_id - 1) * 16 + index`. Empty entries are omitted from decoded text but remain represented by the block inventory. String byte positions are preserved as RVAs. Decoded Portuguese text comes from structured resources; the generic raw UTF-16 string scan is intentionally ASCII-range-only and is not complete Unicode extraction.

### RT_MESSAGETABLE (type 11)

u32 block count followed by `{u32 LowId, u32 HighId, u32 OffsetToEntries}` records. Entry positions are relative to the resource start. Each entry begins `{u16 Length, u16 Flags}`, followed by message bytes. Flags bit 0 selects UTF-16LE; otherwise this tooling uses cp1252 (an explicit assumption, not locale autodetection). Length includes the four-byte header. Entries are walked from LowId through HighId. Text may contain insert tokens such as `%1`; these are not executed or formatted. Exact numeric IDs and flags are retained in `resources.json`.

### RT_MANIFEST (type 24) and version resources

Manifests in the two EXEs are decoded as UTF-8 XML text with original hashes. Requested execution level and dependent assembly strings can be inspected there; no XML-driven process activation was tested. pefile decodes version string tables; raw version resource leaves and hashes remain available. The code/neutral resources predominantly report 6.1.7601.23403, while the event module and Portuguese satellites report 6.1.7600.16385.

### Named REGISTRY resources

Decoded cp1252 text in `resource-details.json`. MpOAV carries CLSID `2781761e-28e0-4109-99fe-b9d127c57afe` with InprocServer32 `%MODULE%`, ThreadingModel `Both`, and host settings. MsMpCom has AppID `%APPID%` / DllSurrogate metadata. Placeholder substitution and installation are not performed. Both modules' registration exports actually return `0x80070032`.

### PNG and AVI in MsMpRes

All 54 named PNG resource leaves are parsed with the standard eight-byte PNG magic, big-endian chunk lengths, four-byte chunk names, IHDR dimensions/depth/color type, data and CRC32 over chunk name+data. Chunk CRC results and trailing byte counts are retained; pixels are not rendered and full compressed-stream validation is not claimed.

AVI resource `/AVI/142/1033`: RVA `0x66558`, file offset `0x63558`, resource length 78,336. It begins `RIFF`, little-endian declared RIFF length plus 8, form `AVI `. Top-level chunk tags/offsets/lengths are recorded, with even-byte chunk padding. The contained streams/codecs are not decoded. Check `resource-details.json` for the distinction between resource length and declared RIFF extent.

### MUI and event metadata: partial only

MUI resources begin `cd fe cd fe`, followed by observed total size and version-like prefix fields (u32 values retained). They contain locale/type mapping material, but checksum field semantics, resource redirection and language fallback have not been fully decoded. Do not reinterpret their 16-byte fields as GUIDs without evidence.

MpEvMsg `WEVT_TEMPLATE/1/1033`, RVA `0x14a0`, file offset `0x6a0`, size 49,930: begins `CRIM`; a `WEVT` signature follows at resource +`0x24`. The 16 bytes at +`0x10` decode as GUID candidate `11cd958a-c507-4ef3-b3f2-5fd9dfbd2c78`. Header numeric fields and raw prefixes are retained, not promoted to a complete event-schema specification. Dedicated template parsing is required to recover event IDs, payload field types and provider relationships reliably.

## MsMpCom MSFT type library

`TYPELIB/1/1033` occupies original file offset `0xd130`, RVA `0xf530`, 5,848 bytes. Magic `MSFT`; 84-byte little-endian header; ten typeinfo offsets; fifteen 16-byte segment-directory entries. Segment offsets are relative to the resource. Interpretation follows Wine's documented/reverse-engineered MSFT structures (pinned source references in methodology).

- Typeinfo records have stride 100 bytes. Type kind is the low nibble; member counts pack function count in the low 16 bits and variable count in the high 16. Names/GUIDs refer to separate segments. Declared vtable lengths and implemented-interface counts are retained.
- Name records have a 12-byte prefix, length in the low eight bits of the third word, byte-string data and four-byte alignment. This supplied artifact's names decode as cp1252.
- GUID records have a 16-byte GUID plus two signed 32-bit reference/hash fields (24-byte stride). GUIDs use standard Windows mixed-endian byte order.
- Member data has a byte-length-prefixed record area followed by three equal-sized arrays: member IDs, name offsets and record offsets. Function records carry return typedesc, flags, vtable offset, packed function/invocation/calling-convention bits and parameter counts. The trailing parameter records are `{i32 datatype, i32 name_offset, i32 flags}`.
- Negative datatype values embed a VARTYPE; nonnegative ones offset into eight-byte type-descriptor records. Pointers and internal enum references are resolved; three external user-defined href values (13, 25, 37) are deliberately not guessed.
- Enum constant records here contain immediate packed values with VT_I4; recovered values are 0..4, **not Windows registry REG_* constants**. See `src/MsMpCom.dll/config-types.h`.

Recovered: library GUID `8c389764-f036-48f2-9ae2-88c260dcf43b`; six coclasses; three dispatch interfaces; 19 method declarations; five enum constants. Exact signatures, parameter flags, DISPIDs and offsets are in `src/MsMpCom.dll/type-library.md`. An independent LoadTypeLib cross-check is still required before treating this partial custom decoder as a general TYPELIB reader.

## Application-specific recovered layout

MpAsDesc table at RVA `0x11f0`, file offset `0x5f0`: seven records of three little-endian u32 values, naturally aligned, stride 12. Verified ranges/fallbacks are documented in `src/MpAsDesc.dll/compatibility.h` and `reviewed-behavior.md`. A partially observed COM object-map prefix is documented separately in `src/MpOAV.dll/reviewed-behavior.md`; its total allocation size is not known.

## Not yet specified

Actual engine signature packages, quarantine containers, RPC NDR structures, plugin callback tables, complete COM object layouts, menu/dialog control templates, accelerator semantics, MUI checksum/fallback rules and complete WEVT payload schemas are not reconstructed. Exact available starting evidence and next operations are listed in progress.md; no speculative structures are substituted for missing evidence.
