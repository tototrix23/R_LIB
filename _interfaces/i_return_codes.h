/*
 * i_return_codes.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Christophe
 */

#ifndef INTERFACES_I_RETURN_CODES_H_
#define INTERFACES_I_RETURN_CODES_H_

#define I_RET_ERROR_GENERIC                  -2000
#define I_RET_ERROR_TIME_OPEN                -2001
#define I_RET_ERROR_TIME_START               -2002
#define I_RET_ERROR_TIME_STOP                -2003
#define I_RET_ERROR_TIME_CLOSE               -2004
#define I_RET_ERROR_TIME_INIT                -2005


#define I_RET_ERROR_SERIAL_OPEN              -2010
#define I_RET_ERROR_SERIAL_CLOSE             -2011
#define I_RET_ERROR_SERIAL_CHG_BAUDRATE      -2012
#define I_RET_ERROR_SERIAL_WRITE             -2013
#define I_RET_ERROR_SERIAL_WRITE_TIMEOUT     -2014
#define I_RET_ERROR_SERIAL_WRITE_FAILED      -2015

#endif /* INTERFACES_I_RETURN_CODES_H_ */
