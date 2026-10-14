#include "compatibility.h"
_Static_assert(sizeof(mp_description_range) == 12, "observed table stride");
_Static_assert(offsetof(mp_description_range, fallback_id) == 8, "observed field offset");
const mp_description_range mp_description_ranges[7] = {
    {1000, 2000, 1027}, {2000, 3000, 2027}, {3000, 4000, 3063},
    {4000, 5000, 4002}, {5000, 6000, 5002}, {6000, 7000, 6002},
    {7000, 8000, 7005}
};
uint32_t mp_description_resolve(int32_t category, uint32_t value,
                                uint32_t *out_id, mp_string_probe probe,
                                void *context)
{
    /* Original RVA 0x1787..0x179b: signed category, non-null output. */
    if (category <= 0 || category >= 8 || !out_id)
        return UINT32_C(0x80070057);
    const mp_description_range *range = &mp_description_ranges[category - 1];
    uint32_t result = range->fallback_id;
    /* Original RVA 0x17bc..0x17c0: unsigned comparison, NOT signed. */
    if (value < range->limit_id - range->first_id) {
        uint32_t candidate = range->first_id + value;
        /* A null probe is a model-only convenience representing unavailable resources. */
        if (probe && probe(context, candidate))
            result = candidate;
    }
    *out_id = result;
    /* Optional WPP trace calls from the original are intentionally not reproduced. */
    return 0;
}
