/*
 * t_delay.h
 *
 *  Created on: 20 oct. 2023
 *      Author: Ch.Leclercq
 */

#ifndef TARGET_T_DELAY_H_
#define TARGET_T_DELAY_H_

//#include <_config_compiler/config.h>
//#include "_target/t_targets.h"
#include <_core/c_typedefs.h>





void delay_us(uint32_t value);
void delay_ms(uint32_t value);
void delay_s(uint32_t value);


#define TEMPO_US(x) delay_us(x)
#define TEMPO_MS(x) delay_ms(x)
#define TEMPO_S(x) delay_s(x)

#endif /* TARGET_T_DELAY_H_ */
