/*
 * h_time_test.c
 *
 *  Created on: Sep 11, 2023
 *      Author: Christophe
 */


#include "h_time_test.h"
#include "__plugins/unity.h"

#ifdef R_LIB_UNIT_TEST_MODE
void h_time_test1(void);
void h_time_test2(void);
void h_time_test3(void);
void h_time_test4(void);
i_time_t i;
return_t h_time_test_init(void);
return_t h_time_test_update(c_timespan_h handler);

return_t h_time_test_init(void)
{
    return X_RET_OK;
}

return_t h_time_test_update(c_timespan_h handler)
{
    if(handler == NULL)
        return X_RET_ASSERTION;

    handler->ms = 1000;


    return X_RET_OK;
}


void h_time_test1(void)
{
    return_t ret = h_time_init(0x00);
    TEST_ASSERT_EQUAL( X_RET_ASSERTION, ret );


    i.func_init = 0x0;
    i.func_time_update = 0x0;
    ret = h_time_init(&i);
    TEST_ASSERT_EQUAL( X_RET_MISSING_INTERFACE, ret );


    i.func_init = h_time_test_init;
    ret = h_time_init(&i);
    TEST_ASSERT_EQUAL( X_RET_MISSING_INTERFACE, ret );

    i.func_init = 0x00;
    i.func_time_update =  h_time_test_update;
    ret = h_time_init(&i);
    TEST_ASSERT_EQUAL( X_RET_MISSING_INTERFACE, ret );

    i.func_init = h_time_test_init;
    i.func_time_update =  h_time_test_update;
    ret = h_time_init(&i);
    TEST_ASSERT_EQUAL( X_RET_OK, ret );
}

void h_time_test2(void)
{
   c_timespan_t ts;
   return_t ret = h_time_update(0x00);
   TEST_ASSERT_EQUAL( X_RET_ASSERTION, ret );
   ret = h_time_update(&ts);
   TEST_ASSERT_EQUAL( X_RET_OK, ret );
}

void h_time_test3(void)
{
    c_timespan_t ts;
    c_timespan_t ts_ref;
    ts.ms = 0;
    ts_ref.ms = 0;

    return_t ret = h_time_get_elapsed(0x00, &ts);
    TEST_ASSERT_EQUAL( X_RET_ASSERTION, ret );
    ret = h_time_get_elapsed(&ts_ref, 0x00);
    TEST_ASSERT_EQUAL( X_RET_ASSERTION, ret );
    ret = h_time_get_elapsed(&ts_ref, &ts);
    TEST_ASSERT_EQUAL( X_RET_OK, ret );
    TEST_ASSERT_EQUAL( 1000, ts.ms );
}

void h_time_test4(void)
{
    c_timespan_t ts;
    ts.ms = 0;
    bool_t res;
    return_t ret = h_time_is_elapsed_ms(0x00, 0x00, 0x00);
    TEST_ASSERT_EQUAL( X_RET_ASSERTION, ret );
    ret = h_time_is_elapsed_ms(&ts, 0x00, 0x00);
    TEST_ASSERT_EQUAL( X_RET_ASSERTION, ret );
    ret = h_time_is_elapsed_ms(&ts, 0x00, &res);
    TEST_ASSERT_EQUAL( X_RET_OK, ret );
    ret = h_time_is_elapsed_ms(&ts, 1001, &res);
    TEST_ASSERT_EQUAL( X_RET_OK, ret );
    TEST_ASSERT_EQUAL( res, FALSE );
    ret = h_time_is_elapsed_ms(&ts, 1000, &res);
    TEST_ASSERT_EQUAL( X_RET_OK, ret );
    TEST_ASSERT_EQUAL( res, TRUE );

}


void h_time_test(void)
{

    RUN_TEST(h_time_test1);
    RUN_TEST(h_time_test2);
    RUN_TEST(h_time_test3);
    RUN_TEST(h_time_test4);
}
#endif
