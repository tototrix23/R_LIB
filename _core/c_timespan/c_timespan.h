/*
 * c_timespan.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Christophe
 */

#ifndef C_TIMESPAN_C_TIMESPAN_H_
#define C_TIMESPAN_C_TIMESPAN_H_

#include "_core/c_error.h"
#include "_core/c_log.h"
#include "_core/c_return_codes.h"

typedef struct c_timespan_t
{
    uint64_t ms;
}c_timespan_t;
typedef c_timespan_t* c_timespan_h;

return_t c_timespan_init(c_error_h err,c_timespan_h ptr);

#endif /* C_TIMESPAN_C_TIMESPAN_H_ */
