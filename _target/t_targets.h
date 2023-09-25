/*
 * t_targets.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Christophe
 */

#ifndef TARGET_T_TARGETS_H_
#define TARGET_T_TARGETS_H_

#define TARGET_RENESAS_RAM4 1
#define TARGET_X86          2
#define TARGET_COUNT        2




#ifdef TARGET_RENESAS_RAM4
#include "bsp_api.h"
#define RESET() NVIC_SystemReset()
#else
#define RESET() while(1)
#endif



#endif /* TARGET_T_TARGETS_H_ */
