//
// Created by mate on 28.11.2021.
//

#include "insertionSort.h"

void insertionSort(long* array, const long left, const long right) {
    for (long i = left + 1; i <= right; i++) {
        long key = *(array + i);
        long j = i - 1;

        while (j >= left && key < *(array + j)) {
            *(array + j + 1) = *(array + j);
            j--;
        }

        *(array + j + 1) = key;
    }
}