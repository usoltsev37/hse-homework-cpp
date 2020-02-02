#pragma once

#include <stddef.h>

void my_mergesort (void * arr, size_t elements, size_t element_size,  int (*comparator)(const void *, const void *));