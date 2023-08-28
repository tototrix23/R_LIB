/*
 * t_critical_section.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Christophe
 */

#ifndef TARGET_T_CRITICAL_SECTION_H_
#define TARGET_T_CRITICAL_SECTION_H_

#include <_config_compiler/config.h>

#if OPERATING_SYSTEM == T_OS_THREADX
#include <hal_data.h>
#define T_CRITICAL_SECTION_DEFINE FSP_CRITICAL_SECTION_DEFINE
#define T_CRITICAL_SECTION_ENTER FSP_CRITICAL_SECTION_ENTER
#define T_CRITICAL_SECTION_EXIT  FSP_CRITICAL_SECTION_EXIT
#else
#define T_CRITICAL_SECTION_DEFINE
#define T_CRITICAL_SECTION_ENTER
#define T_CRITICAL_SECTION_EXIT
#endif

#endif /* TARGET_T_CRITICAL_SECTION_H_ */
