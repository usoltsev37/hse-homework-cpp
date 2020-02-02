#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mergesort.h"
#include <assert.h>

int comparator_int (const void * x, const void * y) {
    return *(const int*)y - *(const int*)x;
}

int comparator_char (const void * x, const void * y) {
    return *(const char*)y - *(const char*)x;
}

int comparator_str (const void * x, const void * y) {
    return strcmp(*(char**)y, *(char**)x);
}

int main(int argc, char ** argv) {
    if (strcmp(argv[1], "int") == 0 && (argc - 2)) {
        int array[argc - 2];
        for (int i = 2; i < argc; i++) {
            array[i - 2] = atoi(argv[i]);
        }
        my_mergesort(&array, argc - 2, sizeof(int), comparator_int);
        for (int i = 0; i < argc - 3; i++) {
            printf("%d ", array[i]);
        }
        printf("%d", array[argc - 3]);
    }
    else if(strcmp(argv[1], "char") == 0 && (argc - 2)) {
        char array[argc - 2];
        for (int i = 2; i < argc; i++) {
            array[i - 2] = argv[i][0];
        }
        my_mergesort(&array, argc - 2, sizeof(char), comparator_char);
        for (int i = 0; i < argc - 3; i++) {
            printf("%c ", array[i]);
        }
        printf("%c", array[argc - 3]);
    }
    else if(strcmp(argv[1], "str") == 0 && (argc - 2)) {
        char * array[argc - 2];
        for (int i = 2; i < argc; i++) {
            array[i - 2] = argv[i];
        }
        my_mergesort(&array, argc - 2, sizeof(char *), comparator_str);
        for (int i = 0; i < argc - 3; i++) {
            printf("%s ", array[i]);
        }
        printf("%s", array[argc - 3]);
    }
    else if (argc - 2) {
        assert(!"Unknown type to sort");
    }
    printf("\n");
}