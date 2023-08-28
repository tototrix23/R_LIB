/*
 * c_error.c
 *
 *  Created on: Aug 28, 2023
 *      Author: Christophe
 */

#include <string.h>
#include "_core/c_error.h"
#include "_core/c_log.h"


#undef  LOG_LEVEL
#define LOG_LEVEL      R_LIB_LOG_LEVEL
#undef  LOG_MODULE
#define LOG_MODULE     R_LIB_LOG_MODULE


return_t c_error_init(c_error_h err)
{
#if FW_CHECK_PARAM_ENABLE == 1
    ASSERT(err != NULL)
#endif

    memset(err, 0, sizeof(c_error_t));
    return X_RET_OK;
}
c_error_t c_error_create_t(void)
{
    c_error_t t;
    memset(&t, 0, sizeof(c_error_t));
    return t;
}



void c_error_set(c_error_h handler, return_t code, char* file,const char* function, uint16_t line)
{
    if (handler == NULL) return;
    handler->code = code;
    handler->file = file;
    handler->function = function;
    handler->line = line;
}

