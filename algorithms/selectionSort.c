//
// Created by mate on 28.11.2021.
//

#include "selectionSort.h"

void selectionSort(long* array, const long length) {
    for (long i = length - 1; i >= 0; i--) {
        long max = *(array + i);
        long maxIndex = i;

        for (long j = i - 1; j >= 0; j--) {
            if (*(array + j) > max) {
                max = *(array + j);
                maxIndex = j;
            }
        }

        swap(array + i, array + maxIndex);
    }
}
