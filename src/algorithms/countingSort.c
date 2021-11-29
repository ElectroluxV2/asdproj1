//
// Created by mate on 28.11.2021.
//

#include "countingSort.h"

long* countOccurrences(const long* array, const long length, const long exp) {
    long* occurrences = calloc(10, sizeof(long));

    for (long i = 0; i < length; i++) {
        *(occurrences + (*(array + i) / exp) % 10) += 1;
    }

    return occurrences;
}

void countingSort(long* array, const long length, const long exp) {

    long* indices = countOccurrences(array, length, exp);
    // Sum occurrences to create 1 based indices
    for (long i = 1; i < 10; i++) {
        *(indices + i) += *(indices + i -1);
    }

    // Transform to 0 based indices
    for (long i = 0; i < 10; i++) {
        *(indices + i) -= 1;
    }

    long* output = malloc(length * sizeof(long));
    for (long i = length - 1; i >= 0; i--) {
        *(output + (*(indices + (*(array + i) / exp) % 10))--) = *(array + i);
    }

    memmove(array, output, length * sizeof(long));
    free(output);
}