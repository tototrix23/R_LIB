/*
 * c_salloc.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Christophe
 */

#ifndef CORE_C_SALLOC_C_SALLOC_H_
#define CORE_C_SALLOC_C_SALLOC_H_

#include <_config_compiler/config.h>
#include "_core/c_config_verify.h"
#include "_core/c_return_codes.h"
#include "_core/c_error.h"

#if USE_SALLOC == 1
void* c_salloc(c_error_h err,size_t size);
void  c_sfree(c_error_h err, void *ptr);

#define C_SALLOC(err,x)  c_salloc(err,x)
#define C_SFREE(err,x)  c_sfree(err,x)
#else
#include <stdlib.h>
#define C_SALLOC(err,x) c_malloc(x)
#define C_SFREE(err,x) c_free(x)
#endif

#endif /* CORE_C_SALLOC_C_SALLOC_H_ */
