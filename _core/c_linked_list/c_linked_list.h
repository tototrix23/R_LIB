/*
 * c_linked_list.h
 *
 *  Created on: Sep 11, 2023
 *      Author: Christophe
 */

#ifndef CORE_C_LINKED_LIST_C_LINKED_LIST_H_
#define CORE_C_LINKED_LIST_C_LINKED_LIST_H_

#include <_core/c_typedefs.h>
#include <_core/c_return_codes.h>

typedef struct c_linked_list_t
{
    void* item;
    struct c_linked_list_t* prev;
    struct c_linked_list_t* next;
}c_linked_list_t;
typedef c_linked_list_t* c_linked_list_h;

return_t c_linked_list_init(c_linked_list_h list);
return_t c_linked_list_append(c_linked_list_h list, void* item);
return_t c_linked_list_get_count(c_linked_list_h list, uint32_t* result);
return_t c_linked_list_get_by_index(c_linked_list_h list, uint32_t index,void** ptr);


#endif /* CORE_C_LINKED_LIST_C_LINKED_LIST_H_ */
