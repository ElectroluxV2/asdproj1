//
// Created by mate on 28.11.2021.
//

#include "quickSort.h"

long partition(long* array, long p, long r) {
    long x = *(array + r);
    long i = p - 1;

    for (long j = p; j <= r - 1; j++) {
        if (*(array + j) <= x) {
            i++;
            swap(array + i, array + j);
        }
    }

    swap(array + i + 1, array + r);
    return i + 1;
}

void quickSort(long* array, const long p, const long r) {
    if (p < r) {
        const long q = partition(array, p, r);
        quickSort(array, p, q - 1);
        quickSort(array, q + 1, r);
    }
}