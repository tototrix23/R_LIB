/*
 * i_log.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Christophe
 */

#ifndef INTERFACES_I_LOG_I_LOG_H_
#define INTERFACES_I_LOG_I_LOG_H_

#include <stdarg.h>
#include <_core/c_typedefs.h>
#include <_core/c_error/c_error.h>

typedef struct i_log_struct
{
    void(*write_e)(uint8_t mode,char *module, char* s, char* file,const char* func, uint16_t line, va_list argp);
    void(*write_w)(uint8_t mode,char *module, char* s, char* file,const char* func, uint16_t line, va_list argp);
    void(*write_i)(uint8_t mode,char *module, char* s, char* file,const char* func, uint16_t line, va_list argp);
    void(*write_d)(uint8_t mode,char *module, char* s, char* file,const char* func, uint16_t line, va_list argp);
}i_log_struct;

extern i_log_struct i_log;

#endif /* INTERFACES_I_LOG_I_LOG_H_ */
