/*
 * h_drv8316.h
 *
 *  Created on: 25 sept. 2023
 *      Author: Ch.Leclercq
 */

#ifndef HAL_H_DRV8316_H_DRV8316_H_
#define HAL_H_DRV8316_H_DRV8316_H_

#include "_core/c_typedefs.h"
#include "_core/c_return_codes.h"
#include "_core/c_error/c_error.h"
#include "_core/c_log.h"
#include "_hal/h_return_codes.h"
#include "_interfaces/i_spi/i_spi.h"





typedef union{
   struct
   {
       unsigned FAULT            : 1;
       unsigned OT               : 1;
       unsigned OVP              : 1;
       unsigned NPOR             : 1;
       unsigned OCP              : 1;
       unsigned SPI_FLT          : 1;
       unsigned BK_FLT           : 1;
       unsigned                  : 1;
   }bits;
   uint8_t value;
}DRV8316_IC_REG;

typedef union{
   struct
   {
       unsigned OCP_LA           : 1;
       unsigned OCP_HA           : 1;
       unsigned OCP_LB           : 1;
       unsigned OCP_HB           : 1;
       unsigned OCP_LC           : 1;
       unsigned OCP_HC           : 1;
       unsigned OTS              : 1;
       unsigned OTW              : 1;
   }bits;
   uint8_t value;
}DRV8316_STATUS_REG1;

typedef union{
   struct
   {
       unsigned SPI_ADDR_FLT     : 1;
       unsigned SPI_SCLK_FLT     : 1;
       unsigned SPI_PARITY       : 1;
       unsigned VCP_UV           : 1;
       unsigned BUCK_UV          : 1;
       unsigned BUCK_OCP         : 1;
       unsigned OTP_ERR          : 1;
       unsigned                  : 1;
   }bits;
   uint8_t value;
}DRV8316_STATUS_REG2;


typedef union{
   struct
   {
       unsigned REG_LOCK         : 3;
       unsigned                  : 5;
   }bits;
   uint8_t value;
}DRV8316_CONTROL_REG1;

typedef union{
   struct
   {
       unsigned CLR_FLT          : 1;
       unsigned PWM_MODE         : 2;
       unsigned SLEW             : 2;
       unsigned SDO_MODE         : 1;
       unsigned                  : 2;
   }bits;
   uint8_t value;
}DRV8316_CONTROL_REG2;

typedef union{
   struct
   {
       unsigned OTW_REP          : 1;
       unsigned                  : 1;
       unsigned OVP_EN           : 1;
       unsigned OVP_SEL          : 1;
       unsigned PWM_100_DUTY_SEL : 1;
       unsigned                  : 3;
   }bits;
   uint8_t value;
}DRV8316_CONTROL_REG3;

typedef union{
   struct
   {
       unsigned OCP_MODE         : 2;
       unsigned OCP_LVL          : 1;
       unsigned OCP_RETRY        : 1;
       unsigned OCP_DEG          : 2;
       unsigned OCP_CBC          : 1;
       unsigned DRV_OFF          : 1;
   }bits;
   uint8_t value;
}DRV8316_CONTROL_REG4;

typedef union{
   struct
   {
       unsigned CSA_GAIN         : 2;
       unsigned EN_ASR           : 1;
       unsigned EN_AAR           : 1;
       unsigned                  : 2;
       unsigned ILIM_RECIR       : 1;
       unsigned                  : 1;
   }bits;
   uint8_t value;
}DRV8316_CONTROL_REG5;

typedef union{
   struct
   {
       unsigned BUCK_DIS         : 1;
       unsigned BUCK_SEL         : 2;
       unsigned BUCK_CL          : 1;
       unsigned BUCK_PS_DIS      : 1;
       unsigned                  : 3;
   }bits;
   uint8_t value;
}DRV8316_CONTROL_REG6;

typedef union{
   struct
   {
       unsigned DLY_TARGET       : 4;
       unsigned DLYCMP_EN        : 1;
       unsigned                  : 3;
   }bits;
   uint8_t value;
}DRV8316_CONTROL_REG10;


typedef struct h_drv8316_t
{
    i_spi_h interface;

    struct
    {
        DRV8316_IC_REG ic_status;
        DRV8316_STATUS_REG1 status1;
        DRV8316_STATUS_REG2 status2;
        DRV8316_CONTROL_REG1 ctrl1;
        DRV8316_CONTROL_REG2 ctrl2;
        DRV8316_CONTROL_REG3 ctrl3;
        DRV8316_CONTROL_REG4 ctrl4;
        DRV8316_CONTROL_REG5 ctrl5;
        DRV8316_CONTROL_REG6 ctrl6;
        DRV8316_CONTROL_REG10 ctrl10;
    }registers;
}h_drv8316_t;

typedef h_drv8316_t* h_drv8316_h;

return_t h_drv8316_init(h_drv8316_h handler,i_spi_h interface,bool_t read_registers);
return_t h_drv8316_read_all_registers(h_drv8316_h handler);
return_t h_drv8316_read_status_registers(h_drv8316_h handler);
return_t h_drv8316_write_all_registers(h_drv8316_h handler);
return_t h_drv8313_clear_fault(h_drv8316_h handler);

#endif /* HAL_H_DRV8316_H_DRV8316_H_ */
