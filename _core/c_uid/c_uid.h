/*
 * c_uid.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Christophe
 */

#ifndef CORE_C_UID_C_UID_H_
#define CORE_C_UID_C_UID_H_

#include "c_typedefs.h"
#include "c_return_codes.h"
#include "_core/c_error/c_error.h"
#include "c_log.h"

typedef struct c_uid_t
{
    bool_t initialised;
    uint32_t id;
}c_uid_t;

typedef c_uid_t* c_uid_h;

return_t c_uid_init(c_uid_h ptr);

#endif /* CORE_C_UID_C_UID_H_ */
