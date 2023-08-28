/*
 * c_uid.c
 *
 *  Created on: Aug 28, 2023
 *      Author: Christophe
 */


#include <_config_compiler/config.h>
#include "c_uid.h"
#include <_target/t_critical_section.h>

#undef  LOG_LEVEL
#define LOG_LEVEL     R_LIB_LOG_LEVEL
#undef  LOG_MODULE
#define LOG_MODULE    R_LIB_LOG_MODULE

static uint32_t static_uid = 1;


return_t c_uid_init(c_error_h err,c_uid_h ptr)
{
#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(err != NULL)
    ASSERT(ptr != NULL)
    ERROR_CHECK(err)
#endif

    memset(ptr, 0, sizeof(c_uid_t));
    T_CRITICAL_SECTION_DEFINE;
    T_CRITICAL_SECTION_ENTER;
    ptr->id = static_uid++;
    ptr->initialised = TRUE;
    T_CRITICAL_SECTION_EXIT;
    return X_RET_OK;
}
