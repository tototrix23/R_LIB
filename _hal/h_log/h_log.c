/*
 * h_log.c
 *
 *  Created on: Aug 28, 2023
 *      Author: Christophe
 */

#include "h_log.h"

i_log_struct i_log =
{ .write_e = 0x00, .write_w = 0x00, .write_i = 0x00, .write_d = 0x00 };


void h_log_write_e(uint8_t mode,char *module, char* s, char* file,const char* func, uint16_t line, ...)
{
    va_list ap;
    va_start(ap, line);
    if (i_log.write_e == NULL) return;
    i_log.write_e(mode,module, s, file, func, line, ap);
    va_end(ap);
}

void h_log_write_w(uint8_t mode,char *module, char* s, char* file,const char* func, uint16_t line, ...)
{
    va_list ap;
    va_start(ap, line);
    if (i_log.write_w == NULL) return;
    i_log.write_w(mode,module, s, file, func, line, ap);
    va_end(ap);
}

void h_log_write_i(uint8_t mode,char *module, char* s, char* file,const char* func, uint16_t line, ...)
{
    va_list ap;
    va_start(ap, line);
    if (i_log.write_i == NULL) return;
    i_log.write_i(mode,module, s, file, func, line, ap);
    va_end(ap);
}

void h_log_write_d(uint8_t mode,char *module, char* s, char* file, const char* func, uint16_t line, ...)
{
    va_list ap;
    va_start(ap, line);
    if (i_log.write_d == NULL) return;
    i_log.write_d(mode,module, s, file, func, line, ap);

    va_end(ap);
}
