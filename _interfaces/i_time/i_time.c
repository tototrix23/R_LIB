/*
 * i_time.c
 *
 *  Created on: Aug 28, 2023
 *      Author: Christophe
 */


#include "i_time.h"

#undef  LOG_LEVEL
#define LOG_LEVEL      R_LIB_LOG_LEVEL
#undef  LOG_MODULE
#define LOG_MODULE     R_LIB_LOG_MODULE

return_t i_time_init(c_error_h err,i_time_h handler, void* func_init, void* func_time_update)
{
#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(err != NULL)
    ASSERT(handler != NULL)
    ASSERT(func_init != NULL)
    ASSERT(func_time_update != NULL)
    ERROR_CHECK(err)
#endif

    memset(handler, 0, sizeof(i_time_t));
    handler->func_time_update = func_time_update;
    handler->func_init = func_init;
    return X_RET_OK;
}
