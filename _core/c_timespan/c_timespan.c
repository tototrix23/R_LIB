/*
 * c_timespan.c
 *
 *  Created on: Aug 28, 2023
 *      Author: Christophe
 */

#include "_core/c_timespan/c_timespan.h"

#undef  LOG_LEVEL
#define LOG_LEVEL      R_LIB_LOG_LEVEL
#undef  LOG_MODULE
#define LOG_MODULE    R_LIB_LOG_MODULE


return_t c_timespan_init(c_timespan_h ptr)
{
#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(ptr != NULL)
#endif
    memset(ptr, 0, sizeof(c_timespan_t));
    return X_RET_OK;
}
