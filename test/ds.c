#include "vendor/unity.h"
#include "../src/ds.h"

#include <stdlib.h>
#include <stdio.h>


void test_vector(void)
{
    vector v;
    vec_init(&v);

    // append in values
    for(uint32_t i=0; i < 10; i++) {
        int* val = malloc(sizeof(int*));
        *val = i;

        vec_append(&v, val);
        TEST_ASSERT_EQUAL(i, *((int*) vec_get(&v, i)));

    }
    vec_free(&v);

}

int main(void)
{
    UnityBegin("test/ds.c");

    RUN_TEST(test_vector);

    UnityEnd();

    return 0;
}
