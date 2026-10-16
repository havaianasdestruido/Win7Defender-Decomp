/* Syntax-only regression checks for recovered declarations. Not application code. */
#include "../models/MpAsDesc.dll/compatibility.h"
#include "../../src/MsMpCom.dll/config-types.h"
_Static_assert(sizeof(mp_description_range) == 12, "table width");
_Static_assert(sizeof(mp_com_config_type) == 4, "typelib enum width");
_Static_assert(MP_COM_CONFIG_TYPE_NONE == 0, "metadata constant");
_Static_assert(MP_COM_CONFIG_TYPE_DWORD == 1, "not REG_DWORD (4)");
_Static_assert(MP_COM_CONFIG_TYPE_BINARY == 4, "metadata constant");
