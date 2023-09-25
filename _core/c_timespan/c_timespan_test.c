/*
 * c_timespan_test.c
 *
 *  Created on: Sep 8, 2023
 *      Author: Christophe
 */


#include "c_timespan_test.h"
#include "_core/c_error/c_error.h"
#include "__plugins/unity.h"

#ifdef R_LIB_UNIT_TEST_MODE
void c_timespan_test1(void);


void c_timespan_test1(void)
{

    c_timespan_t ts;

    return_t ret = c_timespan_init(0x00);
    TEST_ASSERT_EQUAL( X_RET_ASSERTION, ret );

    ret = c_timespan_init(&ts);
    TEST_ASSERT_EQUAL( X_RET_OK, ret );
}

void c_timespan_test(void)
{

    RUN_TEST(c_timespan_test1);

}
#endif
