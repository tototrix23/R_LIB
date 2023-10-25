/*
 * c_config_verify.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Christophe
 */

#ifndef CORE_C_CONFIG_VERIFY_H_
#define CORE_C_CONFIG_VERIFY_H_

#include <_config_compiler/config.h>
#include "_core/c_log.h"
#include "_target/t_targets.h"
#include "_target/t_operating_systems.h"
#include "_target/t_delay.h"

#if !defined R_LIB_CHECK_PARAM_ENABLE
#error R_LIB_CHECK_PARAM_ENABLE is not defined
#endif

#if !defined R_LIB_ASSERT_MODE
#error R_LIB_ASSERT_MODE is not defined
#elif R_LIB_ASSERT_MODE <0
#error R_LIB_ASSERT_MODE bad value
#elif R_LIB_ASSERT_MODE > R_LIB_ASSERT_RESET
#error R_LIB_ASSERT_MODE bad value
#endif


#if !defined R_LIB_LOG_LEVEL
#error X_LIB_LOG_LEVEL is not defined in config.h.
#endif

#if !defined LOG_ENABLE
#error LOG_ENABLE is not defined.0 = disabled , 1=enabled
#elif LOG_ENABLE <0
#error LOG_ENABLE bad value
#elif LOG_ENABLE >1
#error LOG_ENABLE bad value
#endif



#if !defined TARGET
#error TARGET is not defined.See targets.h for complete list
#elif TARGET <1
#error TARGET bad value
#elif TARGET > TARGET_COUNT
#error TARGET bad value
#endif

#if !defined USE_SALLOC
#error USE_SALLOC is not defined
#elif USE_SALLOC <0
#error SALLOC bad value
#elif USE_SALLOC >1
#error SALLOC bad value
#endif

#if USE_SALLOC==1 && !defined SALLOC_SIZE_BYTES
#error SALLOC_SIZE_BYTES is not defined
#endif

#if !defined OPERATING_SYSTEM
#error OPERATING_SYSTEM is not defined.See t_os.h for complete list
#elif OPERATING_SYSTEM <1
#error OPERATING_SYSTEM bad value
#elif OPERATING_SYSTEM > T_OS_COUNT
#error OPERATING_SYSTEM bad value
#endif

#if !defined RESET
#error RESET not defined
#endif

#if !defined TEMPO_US
#error TEMPO_US not defined
#endif

#if !defined TEMPO_MS
#error TEMPO_MS not defined
#endif

#if !defined TEMPO_S
#error TEMPO_S not defined
#endif


#endif /* CORE_C_CONFIG_VERIFY_H_ */
