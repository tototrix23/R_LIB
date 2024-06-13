/*
 * i_spi.h
 *
 *  Created on: 25 sept. 2023
 *      Author: Ch.Leclercq
 */

#ifndef INTERFACES_I_SPI_I_SPI_H_
#define INTERFACES_I_SPI_I_SPI_H_

#include "_core/c_typedefs.h"
#include "_core/c_error/c_error.h"
#include <_config_compiler/config.h>



typedef struct i_spi_t
{
    TX_MUTEX *mutex_ptr;
    return_t(*func_open)(void);
    return_t(*func_close)(void);
    return_t(*func_read)( char* buffer_tx,char*buffer_rx,uint16_t count);
    return_t(*func_write)( char* buffer_tx,char* buffer_rx,uint16_t count);
    return_t(*func_cs_inactive)(void);
    return_t(*func_cs_active)(void);
}i_spi_t;

typedef i_spi_t* i_spi_h;



return_t i_spi_init(i_spi_h handler,TX_MUTEX *mutex_ptr,void* func_open,void*func_close,void *func_read,void*func_write,void*func_cs_inactive,void*func_cs_active);


#endif /* INTERFACES_I_SPI_I_SPI_H_ */
