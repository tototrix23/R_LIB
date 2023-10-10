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




#ifdef TARGET_RENESAS_RA
#include "bsp_api.h"
#define RESET() NVIC_SystemReset()
#define TEMPO_US(x) R_BSP_SoftwareDelay(x, BSP_DELAY_UNITS_MICROSECONDS)
#define TEMPO_MS(x) R_BSP_SoftwareDelay(x, BSP_DELAY_UNITS_MILLISECONDS)
#define TEMPO_S(x) R_BSP_SoftwareDelay(x, BSP_DELAY_UNITS_SECONDS)
#else

#endif



#endif /* TARGET_T_TARGETS_H_ */
