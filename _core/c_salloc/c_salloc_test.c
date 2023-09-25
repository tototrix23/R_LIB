/*
 * c_salloc_test.c
 *
 *  Created on: Sep 8, 2023
 *      Author: Christophe
 */


#include "c_salloc_test.h"
#include "_core/c_error/c_error.h"
#include "__plugins/unity.h"

#ifdef R_LIB_UNIT_TEST_MODE
void c_salloc_test1(void);


void c_salloc_test1(void)
{

    void *ptr1;
    void *ptr2;
    void *ptr3;
    void *ptr4;
    void *ptr5;

    return_t ret =   C_SALLOC( 0x00,0x00);
    TEST_ASSERT_EQUAL( X_RET_ASSERTION, ret );


    ret =   C_SALLOC( 10,0x00);
    TEST_ASSERT_EQUAL( X_RET_ASSERTION, ret );

    ret =   C_SALLOC( 0x00,&ptr1);
    TEST_ASSERT_EQUAL( X_RET_ASSERTION, ret );

    ret =   C_SALLOC( 1000,&ptr1);
    TEST_ASSERT_EQUAL( X_RET_OK, ret );

    ret =   C_SALLOC( 1000,&ptr2);
    TEST_ASSERT_EQUAL( X_RET_OK, ret );

    ret = C_SFREE(ptr1);
    TEST_ASSERT_EQUAL( X_RET_UNSUPPORTED_FUNCTION, ret );

    ret =   C_SALLOC( 1000,&ptr3);
    TEST_ASSERT_EQUAL( X_RET_OK, ret );

    ret =   C_SALLOC( 1000,&ptr4);
    TEST_ASSERT_EQUAL( X_RET_OK, ret );

    ret =   C_SALLOC( 1,&ptr5);
    TEST_ASSERT_EQUAL( X_RET_ASSERTION, ret );

    void *ptrBase = c_salloc_get_addr();

    volatile uint8_t *pBase = ptrBase;
    volatile uint8_t *p1 = ptr1;
    volatile uint8_t *p2 = ptr2;

    if((p1 != pBase) || (p2!=pBase+1000))
        TEST_FAIL_MESSAGE("C_SALLOC allocation addresses error");

    c_salloc_init();

   /* ret =   C_SALLOC(0x00, 10);
    TEST_ASSERT_EQUAL( X_RET_ASSERTION, ret );

    ret =   C_SALLOC(&err,0);
    TEST_ASSERT_EQUAL( X_RET_ASSERTION, ret );

    ret =   C_SALLOC(&err,10);
    TEST_ASSERT_EQUAL( X_RET_OK, ret );*/


}

void c_salloc_test(void)
{

    RUN_TEST(c_salloc_test1);

}
#endif
