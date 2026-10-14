/* Recovered from MSFT enum metadata; all underlying values fit signed 32 bits. */
#ifndef MSMP_CONFIG_TYPES_H
#define MSMP_CONFIG_TYPES_H
#include <stdint.h>
typedef int32_t mp_com_config_type;
enum {
    MP_COM_CONFIG_TYPE_NONE = 0,
    MP_COM_CONFIG_TYPE_DWORD = 1,
    MP_COM_CONFIG_TYPE_SZ = 2,
    MP_COM_CONFIG_TYPE_MULTI_SZ = 3,
    MP_COM_CONFIG_TYPE_BINARY = 4,
};
#endif
