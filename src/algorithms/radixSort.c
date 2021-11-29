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
    long max = findMax(array, length);
    long exp = 1;
    do {
        countingSort(array, length, exp);

        exp *= 10;
        max /= 10;
    } while (max > 1);
}