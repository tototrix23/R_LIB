/*
 * i_spi.c
 *
 *  Created on: 25 sept. 2023
 *      Author: Ch.Leclercq
 */

#include <_config_compiler/config.h>
#include "_core/c_typedefs.h"
#include "i_spi.h"

#undef  LOG_LEVEL
#define LOG_LEVEL      R_LIB_LOG_LEVEL
#undef  LOG_MODULE
#define LOG_MODULE    R_LIB_LOG_MODULE


return_t i_spi_init(i_spi_h handler,TX_MUTEX *mutex_ptr,void* func_open,void*func_close,void *func_read,void*func_write,void*func_cs_inactive,void*func_cs_active)
{
#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(mutex_ptr != NULL);
    ASSERT(handler != NULL);
    ASSERT(func_open != NULL);
    ASSERT(func_close != NULL);
    ASSERT(func_read != NULL);
    ASSERT(func_write != NULL);
    ASSERT(func_cs_inactive != NULL);
    ASSERT(func_cs_active != NULL);
#endif
    handler->mutex_ptr = mutex_ptr;
    handler->func_open = func_open;
    handler->func_close = func_close;
    handler->func_read = func_read;
    handler->func_write = func_write;
    handler->func_cs_inactive = func_cs_inactive;
    handler->func_cs_active = func_cs_active;
    return X_RET_OK;
}
