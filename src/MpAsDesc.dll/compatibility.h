#ifndef MPASDESC_COMPATIBILITY_H
#define MPASDESC_COMPATIBILITY_H
#include <stdint.h>
#include <stddef.h>
/* Analysis-informed portable model, NOT a drop-in Windows Defender DLL.
 * Field widths and stride observed at original RVA 0x11f0, 7 x 12 bytes.
 * Field names are analyst-assigned; category meanings are not recovered.
 */
typedef struct mp_description_range {
    uint32_t first_id;
    uint32_t limit_id; /* exclusive */
    uint32_t fallback_id;
} mp_description_range;
extern const mp_description_range mp_description_ranges[7];
/* Adapter returns nonzero iff original LoadStringW(..., id, buffer, 2)
 * would return nonzero. Host callback/context are new model interfaces.
 */
typedef int (*mp_string_probe)(void *context, uint32_t id);
uint32_t mp_description_resolve(int32_t category, uint32_t value,
                                uint32_t *out_id, mp_string_probe probe,
                                void *context);
#endif
