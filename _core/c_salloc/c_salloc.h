/*
 * c_salloc.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Christophe
 */

#ifndef CORE_C_SALLOC_C_SALLOC_H_
#define CORE_C_SALLOC_C_SALLOC_H_

#include <_config_compiler/config.h>
#include <__config/c_config_verify.h>
#include "_core/c_return_codes.h"
#include "_core/c_error/c_error.h"

#if USE_SALLOC == 1
//return_t c_salloc2(c_error_h err,size_t size,void **ptr);

void c_salloc_init(void);
void* c_salloc_get_addr(void);
return_t c_salloc(size_t size,void **ptr);
return_t  c_sfree(void *ptr);


#define C_SALLOC(size,ptr)  c_salloc(size,ptr)
#define C_SFREE(ptr)  c_sfree(ptr)
#else
#include <stdlib.h>
#define C_SALLOC(err,x) c_malloc(x)
#define C_SFREE(err,x) c_free(x)
#endif

#endif /* CORE_C_SALLOC_C_SALLOC_H_ */
