/*
 * c_salloc.c
 *
 *  Created on: Aug 28, 2023
 *      Author: Christophe
 */


#include <_config_compiler/config.h>
#include <_core/c_common.h>
#include "_core/c_salloc/c_salloc.h"
#include "_core/c_log.h"
#include "_target/t_critical_section.h"

#undef  LOG_LEVEL
#define LOG_LEVEL      R_LIB_LOG_LEVEL
#undef  LOG_MODULE
#define LOG_MODULE    R_LIB_LOG_MODULE




#if USE_SALLOC == 1
static uint8_t salloc_buffer[SALLOC_SIZE_BYTES];
uint32_t salloc_index= 0;
volatile uint32_t salloc_free_space = 0;

void* c_salloc(c_error_h err,size_t size)
{
#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(err != NULL)
    ASSERT(size > 0)
#endif

    ASSERT((salloc_index + size) < SALLOC_SIZE_BYTES)

    T_CRITICAL_SECTION_DEFINE;
    T_CRITICAL_SECTION_ENTER;
    void* nextBlock=NULL;
    nextBlock = &salloc_buffer[salloc_index];
    salloc_index += size;
    salloc_free_space = SALLOC_SIZE_BYTES - salloc_index;
    end:
    T_CRITICAL_SECTION_EXIT;
    LOG_D(LOG_STD, "SALLOC free=%d/%d bytes", salloc_free_space, SALLOC_SIZE_BYTES);
    return nextBlock;

}

void  c_sfree(c_error_h err,void* ptr)
{
/*#if R_LIB_CHECK_PARAM_ENABLE == 1
    ERROR_ASSERT(err != NULL,X_RET_PARAM_NULL)
    ERROR_ASSERT(ptr != NULL,X_RET_PARAM_NULL)
#endif

    LOG_D(LOG_STD, "SFREE unsupported");
    */
}
#endif
