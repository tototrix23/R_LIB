/*
 * c_circular_buffer.h
 *
 *  Created on: Sep 12, 2023
 *      Author: Christophe
 */

#ifndef CORE_C_CIRCULAR_BUFFER_C_CIRCULAR_BUFFER_H_
#define CORE_C_CIRCULAR_BUFFER_C_CIRCULAR_BUFFER_H_

#include <_core/c_typedefs.h>
#include <_core/c_return_codes.h>
#include <_core/c_error/c_error.h>


typedef struct c_circular_buf_t {
    uint8_t* buffer;
    uint8_t* head;
    uint8_t* tail;
    uint32_t max;
    uint16_t element_size;
    bool_t full;
    uint32_t memory_size;
    uint8_t* buff_end;
}c_circular_buf_t;

typedef c_circular_buf_t* c_circular_buf_h;


/// Constructeur dynamique (retourne un pointeur)
c_circular_buf_h c_circular_buf_create_h(c_error_h err, uint8_t* buffer,uint16_t obj_size,size_t obj_count);

c_circular_buf_t c_circular_buf_create_t(c_error_h err, uint8_t* buffer,uint16_t obj_size,size_t obj_count);


/// Reset the circular buffer to empty, head == tail
return_t c_circular_buf_reset(c_error_h err, c_circular_buf_h cbuf);

/// Put version 1 continues to add data if the buffer is full
/// Old data is overwritten
return_t c_circular_buf_put(c_error_h err, c_circular_buf_h cbuf, uint8_t *data);

/// Put Version 2 rejects new data if the buffer is full
/// Returns 0 on success, -1 if buffer is full
return_t c_circular_buf_put2(c_error_h err, c_circular_buf_h cbuf, uint8_t *data);

/// Retrieve a value from the buffer
/// Returns 0 on success, -1 if the buffer is empty
return_t c_circular_buf_get(c_error_h err, c_circular_buf_h cbuf, uint8_t *data);

return_t c_circular_buf_read(c_error_h err, c_circular_buf_h cbuf, uint8_t *data);

/// Returns true if the buffer is empty
bool_t c_circular_buf_empty(c_error_h err, c_circular_buf_h cbuf);

/// Returns true if the buffer is full
bool_t c_circular_buf_full(c_error_h err, c_circular_buf_h cbuf);

/// Returns the maximum capacity of the buffer
uint32_t c_circular_buf_capacity(c_error_h err, c_circular_buf_h cbuf);

uint32_t c_circular_buf_size(c_error_h err, c_circular_buf_h cbuf);

#endif /* CORE_C_CIRCULAR_BUFFER_C_CIRCULAR_BUFFER_H_ */
