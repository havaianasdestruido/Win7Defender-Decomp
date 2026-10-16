# Reviewed signature-description resolver

> **BCC-001 control:** `NOTE-MPASDESC-001` · revision **1** · status **baseline-recorded** · registry: `governance/behavior-notes.json`

## Evidence and confidence

The two named exports were manually compared with GNU objdump and angr output. The resolver control flow below is disassembly-backed; category meanings and original C typedef names remain unknown. Original file SHA-256 is in `interfaces.json`. Preferred base is `0x7ff25ce0000`.

- `GetMpAsDescModuleHandle`, RVA `0x1758`: returns the 64-bit global at RVA `0x36e8` with no arguments or other instructions before `ret`. Naming the return `HMODULE` is supported by its use as the first argument of LoadStringW, not by export metadata.
- `MpGetSignatureDescriptionResourceIdentifier`, RVA `0x1768` through `0x18a0`: observed register inputs ECX (signed 32-bit category), EDX (unsigned 32-bit value), R8 (pointer to writable 32-bit output). Return EAX is an HRESULT-like 32-bit status.
- Category validation at `0x1787..0x179b`: reject category <= 0, category >= 8, or null output; return `0x80070057`, leaving output untouched. Non-null invalid addresses are not validated.
- Seven 12-byte records start at RVA `0x11f0`, file offset `0x5f0`. Fields are u32 base, exclusive limit, fallback. Their analyst-assigned C declaration is in `compatibility.h`; no special packed representation is necessary because all three are u32 at offsets 0/4/8.
- At `0x17bc..0x17c0`, the code subtracts base from limit and performs unsigned `ja` against value. Only values below the span reach the resource probe.
- For in-range values, RVA `0x1805` computes base+value. RVA `0x181e` calls IAT slot `0x10d8`, verified import `USER32.dll!LoadStringW`, with saved module, candidate ID, stack buffer, capacity **2 UTF-16 code units**. It tests the returned count, not last error. Nonzero yields candidate; zero yields fallback.
- Out-of-range values also yield fallback. Both successful choices return zero, including a missing candidate resource; the fallback itself is not loaded or verified by this function.
- Error/fallback paths optionally emit tracing when the list/global at RVA `0x3138` is not the sentinel and the byte at offset `0x1c` has the corresponding flag. These tracing helpers are NOT fully reconstructed.

## Manually reconstructed pseudocode

```c
// Analyst types; Windows x64 ABI. Logging has been abstracted, not removed silently.
uint32_t MpGetSignatureDescriptionResourceIdentifier(
    int32_t category, uint32_t value, uint32_t *out)
{
    if (category <= 0 || category >= 8 || out == NULL) {
        optional_trace_invalid_arguments(category, out);
        return 0x80070057;
    }
    const Range *r = &ranges[category - 1];
    if (value >= (uint32_t)(r->limit - r->base)) {
        optional_trace_fallback(category, value);
        *out = r->fallback;
    } else {
        uint32_t id = r->base + value;
        uint16_t scratch[2];
        if (LoadStringW(saved_module, id, scratch, 2) != 0)
            *out = id;
        else {
            optional_trace_missing_resource(category, value);
            *out = r->fallback;
        }
    }
    return 0;
}
```

## Automated decompiler discrepancy

The angr text in `pseudocode.c` does **not** reliably assign `*out` on the out-of-range path with tracing disabled: its label restructuring places the fallback write inside the inner branch. Original RVA `0x17f7` writes the fallback in this case. Do not compile or treat the automated rendering as equivalent source. The independent `compatibility.c` model follows the actual branch destinations and is different from uncorrected decompiler output.

## Buildable scope

The analysis-only `mpasdesc_model` under `analysis/models/MpAsDesc.dll/` implements the resolver's non-tracing decision logic through a resource-probe callback. It is not ABI-compatible with the original export, does not embed proprietary resources, and does not implement DllMain, module-handle tracking, WPP tracing, MUI fallback or Windows loader behavior. Callback/context and null-callback behavior are new testable interfaces, clearly distinguished from recovered interfaces. See the validation report for original-instruction emulation against controlled LoadStringW stubs. This is analysis-informed reconstruction, not a claim that independent personnel performed a strict two-team clean-room process.
