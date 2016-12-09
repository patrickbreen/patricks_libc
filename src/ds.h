#ifndef DS_H
#define DS_H

#include <stdint.h>

// vector
typedef struct vector {
    uint32_t capacity;
    uint32_t len;
    void** vals;
} vector;

void vec_init(vector* v);
void vec_free(vector* v);

void vec_set(vector* v, uint32_t i, void* val);
void* vec_get(vector* v, uint32_t i);

void vec_append(vector* v, void* val);
uint32_t vec_len(vector* v);



#endif
