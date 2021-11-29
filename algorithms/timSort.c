//
// Created by mate on 29.11.2021.
//

#include "timSort.h"

long min(const long a, const long b) {
    return a < b ? a : b;
}


void merge(long *array, long l, long m, long r) {

    long lengthLeft = m - l + 1, lengthRight = r - m;
    long* arrayLeft = malloc(lengthLeft * sizeof(long));
    long* arrayRight = malloc(lengthRight * sizeof(long));
    
    for (long i = 0; i < lengthLeft; i++) {
        arrayLeft[i] = *(array + l + i);
    }
    
    for (long i = 0; i < lengthRight; i++) {
        arrayRight[i] = *(array + m + 1 + i);
    }

    long i = 0;
    long j = 0;
    long k = l;
    
    while (i < lengthLeft && j < lengthRight) {
        if (*(arrayLeft + i) <= *(arrayRight + j)) {
            *(array + k) = *(arrayLeft + i);
            i++;
        } else {
            *(array + k) = *(arrayRight + j);
            j++;
        }
        k++;
    }
    
    while (i < lengthLeft) {
        *(array + k) = *(arrayLeft + i);
        k++;
        i++;
    }
    
    while (j < lengthRight) {
        *(array + l) = *(arrayRight + j);
        k++;
        j++;
    }
}

void timSort(long *array, long length) {
    int RUN = 32;

    for (long i = 0; i < length; i += RUN) {
        insertionSort(array, i, min(i + RUN - 1, length - 1));
    }

    for (long size = RUN; size < length; size = 2 * size) {
        for (long arrayLeft = 0; arrayLeft < length; arrayLeft += 2 * size) {
            long mid = arrayLeft + size - 1;
            long arrayRight = min((arrayLeft + 2*size - 1), (length-1));

            if (mid < arrayRight) {
                merge(array, arrayLeft, mid, arrayRight);
            }
        }
    }
}