/*
 * t_targets.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Christophe
 */

#ifndef TARGET_T_TARGETS_H_
#define TARGET_T_TARGETS_H_

#define TARGET_RENESAS_RA   1
#define TARGET_X86          2
#define TARGET_COUNT        2

#define PARAMETER_NOT_USED(p)    (void) ((p))

#ifdef TARGET_RENESAS_RA
#include "bsp_api.h"
#endif

#if OPERATING_SYSTEM == T_OS_THREADX
#include "tx_api.h"
#endif

#ifdef TARGET_RENESAS_RA
#define RESET() NVIC_SystemReset()
#else
#define RESET() (void)()
#endif





#endif /* TARGET_T_TARGETS_H_ */
