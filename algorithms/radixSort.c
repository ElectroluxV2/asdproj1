//
// Created by mate on 29.11.2021.
//

#include "radixSort.h"

long findMax(const long* array, const long length) {
    long max = *array;
    for (long i = 1; i < length; i++) {
        if (*(array + i) > max) max = *(array + i);
    }

    return max;
}

void radixSort(long* array, const long length) {
    const long max = findMax(array, length);
    for (long exp = 1; max / exp > 0; exp *= 10) {
        countingSort(array, length, exp);
    }
}