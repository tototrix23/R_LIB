/*
 * h_drv8323s.c
 *
 *  Created on: 11 juin 2024
 *      Author: Christophe
 */


#include "h_drv8323s.h"

#define DRV8323S_FAULT_STATUS1_REGISTER_ADDR           0x0
#define DRV8323S_VGS_STATUS2_REGISTER_ADDR             0x1
#define DRV8323S_DRV_CONTROL_REGISTER_ADDR             0x2
#define DRV8323S_GATE_DRIVE_HS_REGISTER_ADDR           0x3
#define DRV8323S_GATE_DRIVE_LS_REGISTER_ADDR           0x4
#define DRV8323S_OCP_CONTROL_REGISTER_ADDR             0x5
#define DRV8323S_CSA_CONTROL_REGISTER_ADDR             0x6


static return_t h_drv8323s_read_reg(h_drv8323s_h handler,uint8_t addr);
static return_t h_drv8323s_write_reg(h_drv8323s_h handler,uint8_t addr);

return_t h_drv8323s_init(h_drv8323s_h handler,i_spi_h interface,bool_t read_registers)
{
#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(handler != NULL);
    ASSERT(interface != NULL);
#endif
    handler->interface = interface;
    handler->interface->func_cs_inactive();

    if(read_registers == TRUE)
       return h_drv8323s_read_all_registers(handler);
    else
        return X_RET_OK;
}

return_t h_drv8323s_read_all_registers(h_drv8323s_h handler)
{
#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(handler != NULL);
#endif
    return_t ret = X_RET_OK;



    ret = h_drv8323s_read_reg(handler,DRV8323S_FAULT_STATUS1_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8323s_read_reg(handler,DRV8323S_VGS_STATUS2_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8323s_read_reg(handler,DRV8323S_DRV_CONTROL_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8323s_read_reg(handler,DRV8323S_GATE_DRIVE_HS_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8323s_read_reg(handler,DRV8323S_GATE_DRIVE_LS_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8323s_read_reg(handler,DRV8323S_OCP_CONTROL_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8323s_read_reg(handler,DRV8323S_CSA_CONTROL_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    return X_RET_OK;

}

return_t h_drv8323s_read_status_registers(h_drv8323s_h handler)
{
#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(handler != NULL);
#endif
    return_t ret = X_RET_OK;
    ret = h_drv8323s_read_reg(handler,DRV8323S_FAULT_STATUS1_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8323s_read_reg(handler,DRV8323S_VGS_STATUS2_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    return X_RET_OK;
}

return_t h_drv8323s_write_all_registers(h_drv8323s_h handler)
{
#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(handler != NULL);
#endif
    return_t ret = X_RET_OK;

    ret = h_drv8323s_write_reg(handler,DRV8323S_DRV_CONTROL_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8323s_write_reg(handler,DRV8323S_GATE_DRIVE_HS_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8323s_write_reg(handler,DRV8323S_GATE_DRIVE_LS_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8323s_write_reg(handler,DRV8323S_OCP_CONTROL_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8323s_write_reg(handler,DRV8323S_CSA_CONTROL_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;



    return h_drv8323s_read_all_registers(handler);
}

return_t h_drv8323s_clear_fault(h_drv8323s_h handler)
{
#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(handler != NULL);
#endif
    return_t ret = X_RET_OK;
    ret = h_drv8323s_read_reg(handler,DRV8323S_DRV_CONTROL_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    handler->registers.drv_control.bits.CLR_FLT = 1;
    ret = h_drv8323s_write_reg(handler,DRV8323S_DRV_CONTROL_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;

    return h_drv8323s_read_all_registers(handler);
}

static return_t h_drv8323s_read_reg(h_drv8323s_h handler,uint8_t addr)
{
    return_t ret = X_RET_OK;

    uint8_t buffer_tx[2];
    uint8_t buffer_rx[2];
    volatile uint8_t data_temp = 0x00;

    data_temp = (uint8_t)(addr<<3);
    data_temp |= 0x80;
    buffer_tx[0] = data_temp;
    buffer_tx[1] = 0x00;

    tx_mutex_get(handler->interface->mutex_ptr,TX_WAIT_FOREVER);

    ret = handler->interface->func_open();
    if(ret != X_RET_OK) goto end_error;

    handler->interface->func_cs_active();
    TEMPO_US(1);
    ret = handler->interface->func_read((char*)(&buffer_tx[0]),(char*)(&buffer_rx[0]),2);
    if(ret != X_RET_OK) goto end_error;

    handler->interface->func_cs_inactive();
    handler->interface->func_close();
    tx_mutex_put(handler->interface->mutex_ptr);

    volatile uint16_t value = buffer_rx[0];
    value <<=8;
    value += buffer_rx[1];

    switch(addr)
    {
        case DRV8323S_FAULT_STATUS1_REGISTER_ADDR:
            handler->registers.fault_status1.value = (value & 0x07FF);
            break;

        case DRV8323S_VGS_STATUS2_REGISTER_ADDR:
            handler->registers.vgs_status2.value = (value & 0x07FF);
            break;

        case DRV8323S_DRV_CONTROL_REGISTER_ADDR:
            handler->registers.drv_control.value = (value & 0x07FF);
            break;

        case DRV8323S_GATE_DRIVE_HS_REGISTER_ADDR:
            handler->registers.gate_drive_hs.value = (value & 0x07FF);
            break;

        case DRV8323S_GATE_DRIVE_LS_REGISTER_ADDR:
            handler->registers.gate_drive_ls.value = (value & 0x07FF);
            break;

        case DRV8323S_OCP_CONTROL_REGISTER_ADDR:
            handler->registers.ocp_control.value = (value & 0x07FF);
            break;

        case DRV8323S_CSA_CONTROL_REGISTER_ADDR:
            handler->registers.csa_control.value = (value & 0x07FF);
            break;

        default:

            break;
    }

    return X_RET_OK;

    // Liberation des ressources si erreur
    end_error:
    handler->interface->func_cs_inactive();
    handler->interface->func_close();
    tx_mutex_put(handler->interface->mutex_ptr);
    return ret;
}

static return_t h_drv8323s_write_reg(h_drv8323s_h handler,uint8_t addr)
{
    return_t ret = X_RET_OK;
    uint8_t buffer_tx[2];
    uint8_t buffer_rx[2];
    volatile uint16_t data_temp = 0x00;

    data_temp = (uint16_t)(addr<<11);


    switch(addr)
            {
        case DRV8323S_FAULT_STATUS1_REGISTER_ADDR:
            return X_RET_OK;
            break;

        case DRV8323S_VGS_STATUS2_REGISTER_ADDR:
            return X_RET_OK;
            break;

        case DRV8323S_DRV_CONTROL_REGISTER_ADDR:
            data_temp += handler->registers.drv_control.value;
            break;

        case DRV8323S_GATE_DRIVE_HS_REGISTER_ADDR:
            data_temp += handler->registers.gate_drive_hs.value;
            break;

        case DRV8323S_GATE_DRIVE_LS_REGISTER_ADDR:
            data_temp += handler->registers.gate_drive_ls.value;
            break;

        case DRV8323S_OCP_CONTROL_REGISTER_ADDR:
            data_temp += handler->registers.ocp_control.value;
            break;

        case DRV8323S_CSA_CONTROL_REGISTER_ADDR:
            data_temp += handler->registers.csa_control.value;
            break;

        default:
            return X_RET_OK;
            break;
      }
    volatile uint16_t temp_save = data_temp;
    buffer_tx[0] = (uint8_t)(data_temp>>8);
    buffer_tx[1] = (uint8_t)(data_temp&0x00FF);

    tx_mutex_get(handler->interface->mutex_ptr,TX_WAIT_FOREVER);
    ret = handler->interface->func_open();
    if(ret != X_RET_OK) goto end_error;

    handler->interface->func_cs_active();
    TEMPO_US(1);
    ret = handler->interface->func_write((char*)(&buffer_tx[0]),(char*)(&buffer_rx[0]),2);
    if(ret != X_RET_OK) goto end_error;

    handler->interface->func_cs_inactive();
    TEMPO_US(1);
    handler->interface->func_cs_active();

    data_temp = 0x00;
    data_temp = (uint16_t)(addr<<11);
    data_temp |= 0x8000;
    buffer_tx[0] = (uint8_t)(data_temp>>8);
    buffer_tx[1] = (uint8_t)(data_temp&0x00FF);

    ret = handler->interface->func_read((char*)(&buffer_tx[0]),(char*)(&buffer_rx[0]),2);
    if(ret != X_RET_OK) goto end_error;

    handler->interface->func_cs_inactive();
    handler->interface->func_close();
    tx_mutex_put(handler->interface->mutex_ptr);

    volatile uint16_t data_verify = buffer_rx[0];
    data_verify <<=8;
    data_verify += buffer_rx[1];

    if((data_verify & 0x7FF) != (temp_save & 0x7FF))
    {
       return X_RET_VERIFY_FAILED;
    }

    return X_RET_OK;

    end_error:
    handler->interface->func_cs_inactive();
    handler->interface->func_close();
    tx_mutex_put(handler->interface->mutex_ptr);
    return ret;

}
