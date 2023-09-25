/*
 * h_log.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Christophe
 */

#ifndef HAL_H_LOG_H_LOG_H_
#define HAL_H_LOG_H_LOG_H_

#include <stdarg.h>
#include <stddef.h>
#include "_core/c_typedefs.h"
#include "_core/c_return_codes.h"
#include "_core/c_error/c_error.h"
#include "_interfaces/i_log/i_log.h"

#define R_LIB_LOG_MODULE  "RLIB"

#define LOG_STD            0
#define LOG_CRLF           1

#define LOG_LVL_NONE       0
#define LOG_LVL_ERROR      1
#define LOG_LVL_WARN       2
#define LOG_LVL_INFO       3
#define LOG_LVL_DEBUG      4

void h_log_write_e(uint8_t mode,char *module, char* s, char* file,const char* func, uint16_t line, ...);
void h_log_write_w(uint8_t mode,char *module, char* s, char* file,const char* func, uint16_t line, ...);
void h_log_write_i(uint8_t mode,char *module, char* s, char* file,const char* func, uint16_t line, ...);
void h_log_write_d(uint8_t mode,char *module, char* s, char* file,const char* func, uint16_t line, ...);

#endif /* HAL_H_LOG_H_LOG_H_ */
