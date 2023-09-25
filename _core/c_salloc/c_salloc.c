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
#define LOG_LEVEL     R_LIB_LOG_LEVEL
#undef  LOG_MODULE
#define LOG_MODULE    R_LIB_LOG_MODULE




#if USE_SALLOC == 1
static uint8_t salloc_initialised=FALSE;
static uint8_t salloc_buffer[SALLOC_SIZE_BYTES];
static uint32_t salloc_index= 0;





void c_salloc_init(void)
{
    memset(&salloc_buffer,0x00,sizeof(salloc_buffer));
    salloc_initialised = TRUE;
    salloc_index = 0x00;
}


void* c_salloc_get_addr(void)
{
    return &salloc_buffer[0];
}



return_t c_salloc(size_t size,void **ptr)
{
#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(size > 0)
    ASSERT(ptr  != NULL)
#endif


    if(salloc_initialised == FALSE)
        c_salloc_init ();

    void *nextBlock = NULL;
    *ptr=NULL;
    ASSERT((salloc_index + size) <= SALLOC_SIZE_BYTES)

    nextBlock = &salloc_buffer[salloc_index];
    salloc_index += size;

    *ptr = nextBlock;

    return X_RET_OK;
}



return_t  c_sfree(void *ptr)
{
#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(ptr  != NULL)
#endif


    return X_RET_UNSUPPORTED_FUNCTION;
}
#endif



