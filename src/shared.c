//
// Created by mate on 28.11.2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "shared.h"

const long RAW_INPUT_BUFFER_NUMBER = 50;

struct Timer {
    clock_t start, stop;
} static timer;

void timerStart(const char* message) {
    printf("%s", message);
    timer.start = clock();
}

void timerStop() {
    timer.stop = clock();
    printf("took %.2fms\n", 1000 * (double) (timer.stop - timer.start) / CLOCKS_PER_SEC);
}

FILE* redirectFileToStdin(const char* file) {
    return freopen(file, "r", stdin);
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