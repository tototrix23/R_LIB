/*
 * c_linked_list_test.c
 *
 *  Created on: Sep 12, 2023
 *      Author: Christophe
 */


#include "c_linked_list_test.h"
#include "_core/c_error/c_error.h"
#include "__plugins/unity.h"

#ifdef R_LIB_UNIT_TEST_MODE
void c_linked_list_test_init(void);
void c_linked_list_test1(void);

typedef struct c_ll_obj_t
{
  uint16_t id;
  uint8_t array[20];
}c_ll_obj_t;

c_ll_obj_t c_ll_test_arr[8];

void c_linked_list_test_init(void)
{
   uint8_t i,j=0;
   for(i=0;i<8;i++)
   {
       c_ll_test_arr[i].id = i;
       for(j=0;j<20;j++)
           c_ll_test_arr[i].array[j] = i+1;
   }
}


void c_linked_list_test1(void)
{
    uint8_t i=0;

    c_linked_list_test_init();

    //------------------------------------
    // c_linked_list_init
    //------------------------------------
    return_t ret =   c_linked_list_init(0x00);
    TEST_ASSERT_EQUAL( X_RET_ASSERTION, ret );

    // Test avec une liste valide
    c_linked_list_t list;
    ret =   c_linked_list_init(&list);
    TEST_ASSERT_EQUAL( X_RET_OK, ret );

    //------------------------------------
    // c_linked_list_append
    //------------------------------------
    ret =   c_linked_list_append(0x00,0x00);
    TEST_ASSERT_EQUAL( X_RET_ASSERTION, ret );

    ret =   c_linked_list_append(&list,0x00);
    TEST_ASSERT_EQUAL( X_RET_ASSERTION, ret );

    ret =   c_linked_list_append(0x00,&c_ll_test_arr[0]);
    TEST_ASSERT_EQUAL( X_RET_ASSERTION, ret );

    for(i=0;i<8;i++)
    {
       ret =   c_linked_list_append(&list,(void*)(&c_ll_test_arr[i]));
       TEST_ASSERT_EQUAL( X_RET_OK, ret );
    }

    //------------------------------------
    // c_linked_list_get_count
    //------------------------------------
    uint32_t count=0;

    ret =   c_linked_list_get_count(0x00,0x00);
    TEST_ASSERT_EQUAL( X_RET_ASSERTION, ret );

    ret =   c_linked_list_get_count(&list,0x00);
    TEST_ASSERT_EQUAL( X_RET_ASSERTION, ret );

    ret =   c_linked_list_get_count(0x00,&count);
    TEST_ASSERT_EQUAL( X_RET_ASSERTION, ret );

    ret =   c_linked_list_get_count(&list,&count);
    TEST_ASSERT_EQUAL( X_RET_OK, ret );
    TEST_ASSERT_EQUAL( count, 8 );

    //------------------------------------
    // c_linked_list_get_by_index
    //------------------------------------
    c_linked_list_h ptr;

    ret =   c_linked_list_get_by_index(0x00,0x00,0x00);
    TEST_ASSERT_EQUAL( X_RET_ASSERTION, ret );

    ret =   c_linked_list_get_by_index(&list,0x00,0x00);
    TEST_ASSERT_EQUAL( X_RET_ASSERTION, ret );

    ret =   c_linked_list_get_by_index(0x00,0x00,(void**)(&ptr));
    TEST_ASSERT_EQUAL( X_RET_ASSERTION, ret );

    for(i=0;i<8;i++)
    {
       ret =   c_linked_list_get_by_index(&list,i,(void**)(&ptr));
       TEST_ASSERT_EQUAL( X_RET_OK, ret );
       TEST_ASSERT_EQUAL( ptr, &c_ll_test_arr[i] );
       TEST_ASSERT_EQUAL( i, c_ll_test_arr[i].id );

    }

    ret =   c_linked_list_get_by_index(&list,8,(void**)(&ptr));
    TEST_ASSERT_EQUAL( X_RET_PARAM_RANGE, ret );

}

void c_linked_list_test(void)
{

    RUN_TEST(c_linked_list_test1);

}
#endif
