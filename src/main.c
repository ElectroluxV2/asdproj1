#include "shared.h"
#include "algorithms/heapSort.h"
#include "algorithms/quickSort.h"
#include "algorithms/radixSort.h"
#include "algorithms/timSort.h"
#include <stdlib.h>

int main(int argc, char** argv) {
    const long testSize = argc >= 2 ? strtol(*(argv + 1), NULL, 10) : 100000;
    const char* fileName = argc >= 3 ? *(argv + 2) : "./../random";
    long* arrayCopy = malloc(sizeof(long) * testSize);

    printf("Test size: %li elements\n", testSize);
    printf("Input file: %s\n", fileName);

    if (redirectFileToStdin(fileName) == NULL) {
        printf("Failed to open %s\n", fileName);
        return 1;
    }

    timerStart("Reading array ... ");
    long* inputArray = getInputArray(testSize);
    timerStop();



    timerStart("Copying array for HeapSort ... ");
    memcpy(arrayCopy, inputArray, sizeof(long) * testSize);
    timerStop();

    timerStart("Performing HeapSort ... ");
    heapSort(arrayCopy, testSize);
    timerStop();



    timerStart("Copying array for RadixSort ... ");
    memcpy(arrayCopy, inputArray, sizeof(long) * testSize);
    timerStop();

    timerStart("Performing RadixSort ... ");
    radixSort(arrayCopy, testSize);
    timerStop();



    timerStart("Copying array for TimSort ... ");
    memcpy(arrayCopy, inputArray, sizeof(long) * testSize);
    timerStop();

    timerStart("Performing TimSort ... ");
    timSort(arrayCopy, testSize);
    timerStop();



    timerStart("Copying array for QuickSort ... ");
    memcpy(arrayCopy, inputArray, sizeof(long) * testSize);
    timerStop();

    timerStart("Performing QuickSort ... ");
    quickSort(arrayCopy, 0, testSize - 1);
    timerStop();

    free(inputArray);
    free(arrayCopy);
    return 0;
}
