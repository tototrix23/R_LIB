/*
 * c_uid_test.c
 *
 *  Created on: Sep 8, 2023
 *      Author: Christophe
 */


#include "c_uid_test.h"
#include "_core/c_error/c_error.h"
#include "__plugins/unity.h"

#ifdef R_LIB_UNIT_TEST_MODE
void c_uid_test1(void);


void c_uid_test1(void)
{
   c_uid_t id;

   return_t ret = c_uid_init(0x00);
   TEST_ASSERT_EQUAL( X_RET_ASSERTION, ret );

   ret = c_uid_init(&id);
   TEST_ASSERT_EQUAL( X_RET_OK, ret );
}

void c_uid_test(void)
{

    RUN_TEST(c_uid_test1);

}
#endif
