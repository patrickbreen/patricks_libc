#include "ds.h"

#include <stdlib.h>
#include <stdio.h>

void vec_init(vector* v)
{
    v->capacity = 4;
    v->len = 0;
    v->vals = malloc(sizeof(void*) * v->capacity);
}

void vec_free(vector* v)
{
    for (uint32_t i=0; i < v->len; i++)
        free(v->vals[i]);

    free(v->vals); 
}

void vec_set(vector* v, uint32_t i, void* val)
{
    v->vals[i] = val;
}

void* vec_get(vector* v, uint32_t i)
{
    return v->vals[i];
}

static void vec_resize(vector* v, uint32_t size)
{
    void** vals = realloc(v->vals, sizeof(void*) * size);

    if (!v->vals) {
        printf("vec_resize memory error");
        exit(1);
    }

    v->vals = vals;
    v->capacity = size;
}

void vec_append(vector* v, void* val)
{
    if (v->len < v->capacity) {
        v->vals[v->len] = val;
        v->len++;
    } else {
        vec_resize(v, (v->capacity) * 2);
        vec_append(v, val);
    }
}


uint32_t vec_len(vector* v)
{
    return v->len;
}



