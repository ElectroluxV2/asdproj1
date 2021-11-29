//
// Created by mate on 28.11.2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "shared.h"

const long RAW_INPUT_BUFFER_NUMBER = 50;

void redirectFileToStdin(char* file) {
    FILE* ptr = freopen(file, "r", stdin);
    if (ptr == NULL) {
        printf("Failed to open %s\n", file);
    }
}

long* getInputArray(const unsigned long length) {
    long *array = malloc(sizeof(long) * length);

    for (long i = 0; i < length; i++) {
        char* buffer = malloc(sizeof(char) * RAW_INPUT_BUFFER_NUMBER);
        scanf("%s",  buffer);
        *(array + i) = strtol(buffer, NULL, 10);
        free(buffer);
    }

    return array;
}

void printArray(const long* array, const long length) {
    printf("Array (%ld) [", length);
    for (long i = 0; i < length; i++) {
        printf("%ld%s", *(array + i), i + 1 == length ? "" : ", ");
    }
    printf("]\n");
}

void swap(long* first, long* second) {
    const long tmp = *first;
    *first = *second;
    *second = tmp;
}