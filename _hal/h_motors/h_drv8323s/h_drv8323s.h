/*
 * h_drv8323s.h
 *
 *  Created on: 11 juin 2024
 *      Author: Christophe
 */

#ifndef HAL_H_DRV8323S_H_DRV8323S_H_
#define HAL_H_DRV8323S_H_DRV8323S_H_

#include <_core/c_common.h>
#include "_hal/h_return_codes.h"
#include "_interfaces/i_spi/i_spi.h"

typedef union{
   struct
   {
       unsigned VDS_LC           : 1;
       unsigned VDS_HC           : 1;
       unsigned VDS_LB           : 1;
       unsigned VDS_HB           : 1;
       unsigned VDS_LA           : 1;
       unsigned VDS_HA           : 1;
       unsigned OTSD             : 1;
       unsigned UVLO             : 1;
       unsigned GDF              : 1;
       unsigned VDS_OCP          : 1;
       unsigned FAULT            : 1;
       unsigned                  : 5;
   }bits;
   uint16_t value;
}DRV8323S_FAULT_STATUS1_REG;

typedef union{
   struct
   {
       unsigned VGS_LC           : 1;
       unsigned VGS_HC           : 1;
       unsigned VGS_LB           : 1;
       unsigned VGS_HB           : 1;
       unsigned VGS_LA           : 1;
       unsigned VGS_HA           : 1;
       unsigned CPUV             : 1;
       unsigned OTW              : 1;
       unsigned SC_OC            : 1;
       unsigned SB_OC            : 1;
       unsigned SA_OC            : 1;
       unsigned                  : 5;
   }bits;
   uint16_t value;
}DRV8323S_VGS_STATUS2_REG;

typedef union{
   struct
   {
       unsigned CLR_FLT          : 1;
       unsigned BRAKE            : 1;
       unsigned COAST            : 1;
       unsigned PWM_DIR          : 1;
       unsigned PWM_COM          : 1;
       unsigned PWM_MODE         : 2;
       unsigned OTW_REP          : 1;
       unsigned DIS_GDF          : 1;
       unsigned DIS_CPUV         : 1;
       unsigned                  : 6;
   }bits;
   uint16_t value;
}DRV8323S_DRV_CONTROL_REG;

typedef union{
   struct
   {
       unsigned IDRIVEN_HS       : 4;
       unsigned IDRIVEP_HS       : 4;
       unsigned LOCK             : 3;
       unsigned                  : 5;
   }bits;
   uint16_t value;
}DRV8323S_GATE_DRIVE_HS_REG;

typedef union{
   struct
   {
       unsigned IDRIVEN_LS       : 4;
       unsigned IDRIVEP_LS       : 4;
       unsigned TDRIVE           : 2;
       unsigned CBC              : 1;
       unsigned                  : 5;
   }bits;
   uint16_t value;
}DRV8323S_GATE_DRIVE_LS_REG;

typedef union{
   struct
   {
       unsigned VDS_LVL          : 4;
       unsigned OCP_DEG          : 2;
       unsigned OCP_MODE         : 2;
       unsigned DEAD_TIME        : 2;
       unsigned TRETRY           : 1;
       unsigned                  : 5;
   }bits;
   uint16_t value;
}DRV8323S_OCP_CONTROL_REG;

typedef union{
   struct
   {
       unsigned SEN_LVL          : 2;
       unsigned CSA_CAL_C        : 1;
       unsigned CSA_CAL_B        : 1;
       unsigned CSA_CAL_A        : 1;
       unsigned DIS_SEN          : 1;
       unsigned GAIN             : 2;
       unsigned LS_REF           : 1;
       unsigned VREF_DIV         : 1;
       unsigned CSA_FET          : 1;
       unsigned                  : 5;
   }bits;
   uint16_t value;
}DRV8323S_CSA_CONTROL_REG;

typedef struct h_drv8323s_t
{
    i_spi_h interface;

    struct
    {
        DRV8323S_FAULT_STATUS1_REG fault_status1;
        DRV8323S_VGS_STATUS2_REG vgs_status2;
        DRV8323S_DRV_CONTROL_REG drv_control;
        DRV8323S_GATE_DRIVE_HS_REG gate_drive_hs;
        DRV8323S_GATE_DRIVE_LS_REG gate_drive_ls;
        DRV8323S_OCP_CONTROL_REG ocp_control;
        DRV8323S_CSA_CONTROL_REG csa_control;
    }registers;
}h_drv8323s_t;

typedef h_drv8323s_t* h_drv8323s_h;

return_t h_drv8323s_init(h_drv8323s_h handler,i_spi_h interface,bool_t read_registers);
return_t h_drv8323s_read_all_registers(h_drv8323s_h handler);
return_t h_drv8323s_read_status_registers(h_drv8323s_h handler);
return_t h_drv8323s_write_all_registers(h_drv8323s_h handler);
return_t h_drv8323s_clear_fault(h_drv8323s_h handler);

#endif /* HAL_H_DRV8323S_H_DRV8323S_H_ */
