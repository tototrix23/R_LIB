/*
 * t_delay.c
 *
 *  Created on: 20 oct. 2023
 *      Author: Ch.Leclercq
 */
#include <_config_compiler/config.h>
#include "t_delay.h"

#if OPERATING_SYSTEM == T_OS_THREADX
#include "tx_api.h"
#define TICKS_RES (uint32_t)(1000U/THREADX_TICKS)
#endif

#ifdef TARGET_RENESAS_RA
#include "bsp_api.h"



void delay_us(uint32_t value)
{
#if OPERATING_SYSTEM == T_OS_THREADX
    R_BSP_SoftwareDelay(value, BSP_DELAY_UNITS_MICROSECONDS);
#else
    R_BSP_SoftwareDelay(value, BSP_DELAY_UNITS_MICROSECONDS);
#endif
}

void delay_ms(uint32_t value)
{
#if OPERATING_SYSTEM == T_OS_THREADX
    volatile ULONG delay=value;
    if(delay >= TICKS_RES)
    {
        delay = (ULONG)(delay/TICKS_RES);
    }
    else
    {
        delay = 1;
    }
    tx_thread_sleep (delay);


#else
    R_BSP_SoftwareDelay(value, BSP_DELAY_UNITS_MILLISECONDS);
#endif
}

void delay_s(uint32_t value)
{
#if OPERATING_SYSTEM == T_OS_THREADX
    volatile ULONG delay = (ULONG)(value * 1000U);
    delay = (ULONG)(delay/TICKS_RES);
    tx_thread_sleep (delay);
#else
    R_BSP_SoftwareDelay(value, BSP_DELAY_UNITS_SECONDS);
#endif
}
#else
void delay_us(uint32_t value)
{

}
void delay_ms(uint32_t value)
{

}
void delay_s(uint32_t value)
{

}
#endif
