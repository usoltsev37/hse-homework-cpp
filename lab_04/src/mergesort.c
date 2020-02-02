#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>

void merge (void * arr, size_t elements, size_t element_size, int (*comparator) (const void *, const void *)) {
    char * last = (char*)arr + elements * element_size;
    char * temp = (char*)malloc(elements * element_size);
    assert(temp);
    char * middle = (char*)arr + (elements / 2) * element_size;
    char * right = middle;
    char * left = (char*)arr;

    while ((char*)left < (char*)middle && (char*)right < (char*)last) {
        if (comparator(left, right) > 0) {
            memcpy (temp, left, element_size);
            left += element_size;
        }
        else {
            memcpy (temp, right, element_size);
            right += element_size;
        }
        temp += element_size;
    }

    while ((char*)left < (char*)middle) {
        memcpy (temp, left, element_size);
        left += element_size;
        temp += element_size;
    }

    while ((char*)right < (char*)last) {
        memcpy (temp, right, element_size);
        right += element_size;
        temp += element_size;
    }

    temp -= elements * element_size;

    for (size_t i = 0; i < elements * element_size; i += element_size) {
        memcpy((char*)arr + i, temp + i, element_size);
    }

    free (temp);
}

void my_mergesort (void * arr, size_t elements, size_t element_size,  int (*comparator) (const void *, const void *)) {
    if (elements == 1)
        return;
    size_t middle = elements / 2;
    my_mergesort(arr, middle, element_size, comparator);
    my_mergesort(arr + middle * element_size, elements - middle, element_size, comparator);
    merge(arr, elements, element_size, comparator);
}