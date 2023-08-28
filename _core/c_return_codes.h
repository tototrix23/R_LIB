/*
 * c_return_codes.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Christophe
 */

#ifndef CORE_C_RETURN_CODES_H_
#define CORE_C_RETURN_CODES_H_

#define X_RET_OK                                  0
#define X_RET_ASSERTION                          -1
#define X_RET_ERROR_EXIST                        -2
#define X_RET_ERR_GENERIC                        -3
#define X_RET_PARAM_NULL                         -4
#define X_RET_MISSING_DEPENDENCY                 -5
#define X_RET_MISSING_INTERFACE                  -6
#define X_RET_PARAM_RANGE                        -7
#define X_RET_MEMORY_ALLOCATION                  -8
#define X_RET_CONTAINER_EMPTY                    -9
#define X_RET_CONTAINER_FULL                     -10
#define X_RET_CANCELED_EXISTING_ERROR            -11
#define X_RET_BAD_OWNER                          -12
#define X_RET_ONLY_ONE_INSTANCE_ALLOWED          -13
#define X_RET_UNSUPPORTED_FUNCTION               -14
#define X_RET_BAD_GUID                           -15
#define X_RET_NOT_FOUND                          -16
#define X_RET_REGISTRATION                       -17
#define X_RET_UNREGISTRATION                     -18
#define X_RET_NOT_READY                          -19
#define X_RET_INVALID_PARAM                      -20
#define X_RET_BUFFER_SIZE                        -21
#define X_RET_BAD_LENGTH                         -22

#endif /* CORE_C_RETURN_CODES_H_ */
