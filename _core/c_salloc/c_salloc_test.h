/*
 * c_salloc.test.h
 *
 *  Created on: Sep 8, 2023
 *      Author: Christophe
 */

#ifndef CORE_C_SALLOC_C_SALLOC_TEST_H_
#define CORE_C_SALLOC_C_SALLOC_TEST_H_

#include "_core/c_common.h"
#include "_core/c_salloc/c_salloc.h"

#ifdef R_LIB_UNIT_TEST_MODE
void c_salloc_test(void);
#endif
#endif /* CORE_C_SALLOC_C_SALLOC_TEST_H_ */
