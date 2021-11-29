//
// Created by mate on 28.11.2021.
//

#include "heapSort.h"

void heapify(long* array, const long heapLength, const long index) {
    long largestIndex = index;
    long leftIndex = (2 * index) + 1;
    long rightIndex = (2 * index) + 2;


    if (leftIndex < heapLength && *(array + leftIndex) > *(array + largestIndex)) {
        largestIndex = leftIndex;
    }

    if (rightIndex < heapLength && *(array + rightIndex) > *(array + largestIndex)) {
        largestIndex = rightIndex;
    }

    if (largestIndex != index) {
        swap(array + index, array + largestIndex);
        heapify(array, heapLength, largestIndex);
    }
}

void buildHeap(long* array, const long length) {
    for (long i = (length / 2) - 1; i >= 0; i--) {
        heapify(array, length, i);
    }
}

void heapSort(long* array, const long length) {
    buildHeap(array, length);

    for (long i = length - 1; i > 0; i--) {
        swap(array + 0, array + i);
        heapify(array, i, 0);
    }
}