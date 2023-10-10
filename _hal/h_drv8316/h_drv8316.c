/*
 * h_drv8316.c
 *
 *  Created on: 25 sept. 2023
 *      Author: Ch.Leclercq
 */


#include "h_drv8316.h"

static uint8_t spi_calc_parity(uint16_t value);
static return_t h_drv8316_read_reg(h_drv8316_h handler,uint8_t addr);
static return_t h_drv8316_write_reg(h_drv8316_h handler,uint8_t addr);

#define DRV8316_IC_REGISTER_ADDR           0x0
#define DRV8316_STATUS1_REGISTER_ADDR      0x1
#define DRV8316_STATUS2_REGISTER_ADDR      0x2
#define DRV8316_CTRL1_REGISTER_ADDR        0x3
#define DRV8316_CTRL2_REGISTER_ADDR        0x4
#define DRV8316_CTRL3_REGISTER_ADDR        0x5
#define DRV8316_CTRL4_REGISTER_ADDR        0x6
#define DRV8316_CTRL5_REGISTER_ADDR        0x7
#define DRV8316_CTRL6_REGISTER_ADDR        0x8
#define DRV8316_CTRL10_REGISTER_ADDR       0xC






return_t h_drv8316_init(h_drv8316_h handler,i_spi_h interface,bool_t read_registers)
{
#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(handler != NULL);
    ASSERT(interface != NULL);
#endif

    handler->interface = interface;

    return_t ret = handler->interface->func_open();
    if(ret != X_RET_OK) return ret;

    handler->interface->func_cs_inactive();
    TEMPO_US(1);

    if(read_registers == TRUE)
       return h_drv8316_read_all_registers(handler);
    else
        return X_RET_OK;
}

return_t h_drv8316_read_all_registers(h_drv8316_h handler)
{
#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(handler != NULL);
#endif
    return_t ret = X_RET_OK;
    ret = h_drv8316_read_reg(handler,DRV8316_IC_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8316_read_reg(handler,DRV8316_STATUS1_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8316_read_reg(handler,DRV8316_STATUS2_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8316_read_reg(handler,DRV8316_CTRL1_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8316_read_reg(handler,DRV8316_CTRL2_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8316_read_reg(handler,DRV8316_CTRL3_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8316_read_reg(handler,DRV8316_CTRL4_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8316_read_reg(handler,DRV8316_CTRL5_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8316_read_reg(handler,DRV8316_CTRL6_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8316_read_reg(handler,DRV8316_CTRL10_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    return X_RET_OK;
}

return_t h_drv8316_read_status_registers(h_drv8316_h handler)
{
#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(handler != NULL);
#endif
    return_t ret = X_RET_OK;
    ret = h_drv8316_read_reg(handler,DRV8316_IC_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8316_read_reg(handler,DRV8316_STATUS1_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8316_read_reg(handler,DRV8316_STATUS2_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    return X_RET_OK;
}

return_t h_drv8316_write_all_registers(h_drv8316_h handler)
{
#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(handler != NULL);
#endif
    return_t ret = X_RET_OK;

    handler->registers.ctrl1.bits.REG_LOCK = 0x3;
    ret = h_drv8316_write_reg(handler,DRV8316_CTRL1_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;

    ret = h_drv8316_write_reg(handler,DRV8316_CTRL2_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8316_write_reg(handler,DRV8316_CTRL3_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8316_write_reg(handler,DRV8316_CTRL4_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8316_write_reg(handler,DRV8316_CTRL5_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8316_write_reg(handler,DRV8316_CTRL6_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    ret = h_drv8316_write_reg(handler,DRV8316_CTRL10_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;

    /*handler->registers.ctrl1.bits.REG_LOCK = 0x6;
    ret = h_drv8316_write_reg(handler,DRV8316_CTRL1_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;*/

    return h_drv8316_read_all_registers(handler);
}

return_t h_drv8313_clear_fault(h_drv8316_h handler)
{
#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(handler != NULL);
#endif
    return_t ret = X_RET_OK;
    ret = h_drv8316_read_reg(handler,DRV8316_CTRL2_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;
    handler->registers.ctrl2.bits.CLR_FLT = 1;
    ret = h_drv8316_write_reg(handler,DRV8316_CTRL2_REGISTER_ADDR);
    if(ret != X_RET_OK) return ret;

    return h_drv8316_read_all_registers(handler);
}

static uint8_t spi_calc_parity(uint16_t value)
{
    uint8_t par=0;
    for(uint8_t i=0;i<16;i++)
    {
        if (((value)>>i) & 0x0001)
             par+=1;
    }
    return (par&0x01)==0x01;
}

static return_t h_drv8316_read_reg(h_drv8316_h handler,uint8_t addr)
{
    uint8_t buffer_tx[2];
    uint8_t buffer_rx[2];
    uint16_t data_out = 0x00;

    data_out = (uint16_t)((((addr<<1) | 0x80)<<8)|0x0000);
    if (spi_calc_parity(data_out))
        data_out |= 0x0100;

    buffer_tx[0] = (uint8_t)(data_out>>8);
    buffer_tx[1] = 0x00;

    handler->interface->func_cs_active();
    TEMPO_US(1);

    return_t ret = handler->interface->func_read((char*)(&buffer_tx[0]),(char*)(&buffer_rx[0]),2);
    if(ret != X_RET_OK)
    {
        handler->interface->func_cs_inactive();
        return ret;
    }
    handler->interface->func_cs_inactive();


    switch(addr)
    {
        case DRV8316_IC_REGISTER_ADDR:
            handler->registers.ic_status.value = buffer_rx[1];
            break;

        case DRV8316_STATUS1_REGISTER_ADDR:
            handler->registers.ic_status.value = buffer_rx[0];
            handler->registers.status1.value = buffer_rx[1];
            break;

        case DRV8316_STATUS2_REGISTER_ADDR:
            handler->registers.ic_status.value = buffer_rx[0];
            handler->registers.status2.value = buffer_rx[1];
            break;

        case DRV8316_CTRL1_REGISTER_ADDR:
            handler->registers.ic_status.value = buffer_rx[0];
            handler->registers.ctrl1.value = buffer_rx[1];
            break;

        case DRV8316_CTRL2_REGISTER_ADDR:
            handler->registers.ic_status.value = buffer_rx[0];
            handler->registers.ctrl2.value = buffer_rx[1];
            break;

        case DRV8316_CTRL3_REGISTER_ADDR:
            handler->registers.ic_status.value = buffer_rx[0];
            handler->registers.ctrl3.value = buffer_rx[1];
            break;

        case DRV8316_CTRL4_REGISTER_ADDR:
            handler->registers.ic_status.value = buffer_rx[0];
            handler->registers.ctrl4.value = buffer_rx[1];
            break;

        case DRV8316_CTRL5_REGISTER_ADDR:
            handler->registers.ic_status.value = buffer_rx[0];
            handler->registers.ctrl5.value = buffer_rx[1];
            break;


        case DRV8316_CTRL6_REGISTER_ADDR:
            handler->registers.ic_status.value = buffer_rx[0];
            handler->registers.ctrl6.value = buffer_rx[1];
            break;

        case DRV8316_CTRL10_REGISTER_ADDR:
            handler->registers.ic_status.value = buffer_rx[0];
            handler->registers.ctrl10.value = buffer_rx[1];
            break;
    }
    return X_RET_OK;
}


static return_t h_drv8316_write_reg(h_drv8316_h handler,uint8_t addr)
{
    uint8_t buffer_tx[2];
    uint8_t buffer_rx[2];
    uint16_t data_out = 0x00;

    data_out = (uint16_t)((((addr<<1))<<8)|0x0000);


    switch(addr)
        {
            case DRV8316_IC_REGISTER_ADDR:
                return X_RET_OK;
                break;

            case DRV8316_STATUS1_REGISTER_ADDR:
                return X_RET_OK;
                break;

            case DRV8316_STATUS2_REGISTER_ADDR:
                return X_RET_OK;
                break;

            case DRV8316_CTRL1_REGISTER_ADDR:
                data_out += handler->registers.ctrl1.value;
                break;

            case DRV8316_CTRL2_REGISTER_ADDR:
                data_out += handler->registers.ctrl2.value;
                break;

            case DRV8316_CTRL3_REGISTER_ADDR:
                data_out += handler->registers.ctrl3.value;
                break;

            case DRV8316_CTRL4_REGISTER_ADDR:
                data_out += handler->registers.ctrl4.value;
                break;

            case DRV8316_CTRL5_REGISTER_ADDR:
                data_out += handler->registers.ctrl5.value;
                break;


            case DRV8316_CTRL6_REGISTER_ADDR:
                data_out += handler->registers.ctrl6.value;
                break;

            case DRV8316_CTRL10_REGISTER_ADDR:
                data_out += handler->registers.ctrl10.value;
                break;
        }

    if (spi_calc_parity(data_out))
        data_out |= 0x0100;

    buffer_tx[0] = (uint8_t)(data_out>>8);
    buffer_tx[1] = (uint8_t)(data_out & 0x00FF);

    handler->interface->func_cs_active();
    TEMPO_US(1);

    return_t ret = handler->interface->func_write((char*)(&buffer_tx[0]),(char*)(&buffer_rx[0]),2);
    if(ret != X_RET_OK)
    {
        handler->interface->func_cs_inactive();
        return ret;
    }
    handler->interface->func_cs_inactive();

    handler->registers.ic_status.value = buffer_rx[0];




    return X_RET_OK;
}

