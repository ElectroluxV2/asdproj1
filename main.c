#include "algorithms/shared.h"
#include "algorithms/heapSort.h"
#include "algorithms/quickSort.h"
#include "algorithms/radixSort.h"
#include "algorithms/timSort.h"
#include <time.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    clock_t start, stop;
    long* arrayCopy;
    const long testSize = strtol(*(argv + 1), NULL, 10);
    printf("Test size: %s elements\n", *(argv + 1));
    printf("Input file: %s\n", *(argv + 2));

    printf("Reading array ... ");
    start = clock();
    redirectFileToStdin(*(argv + 2));
    long* inputArray = getInputArray(testSize);
    stop = clock();
    printf("took %.2fms\n\n", 1000 * (double) (stop - start) / CLOCKS_PER_SEC);



    printf("Copying array for HeapSort ... ");
    start = clock();
    arrayCopy = malloc(sizeof(long) * testSize);
    memcpy(arrayCopy, inputArray, sizeof(long) * testSize);
    stop = clock();
    printf("took %.2fms\n", 1000 * (double) (stop - start) / CLOCKS_PER_SEC);

    printf("Performing HeapSort ... ");
    start = clock();
    heapSort(arrayCopy, testSize);
    free(arrayCopy);
    stop = clock();
    printf("took %.2fms\n\n", 1000 * (double) (stop - start) / CLOCKS_PER_SEC);



    printf("Copying array for RadixSort ... ");
    start = clock();
    arrayCopy = malloc(sizeof(long) * testSize);
    memcpy(arrayCopy, inputArray, sizeof(long) * testSize);
    stop = clock();
    printf("took %.2fms\n", 1000 * (double) (stop - start) / CLOCKS_PER_SEC);

    printf("Performing RadixSort ... ");
    start = clock();
    radixSort(arrayCopy, testSize);
    free(arrayCopy);
    stop = clock();
    printf("took %.2fms\n\n", 1000 * (double) (stop - start) / CLOCKS_PER_SEC);



    printf("Copying array for TimSort ... ");
    start = clock();
    arrayCopy = malloc(sizeof(long) * testSize);
    memcpy(arrayCopy, inputArray, sizeof(long) * testSize);
    stop = clock();
    printf("took %.2fms\n", 1000 * (double) (stop - start) / CLOCKS_PER_SEC);

    printf("Performing TimSort ... ");
    start = clock();
    timSort(arrayCopy, testSize);
    free(arrayCopy);
    stop = clock();
    printf("took %.2fms\n\n", 1000 * (double) (stop - start) / CLOCKS_PER_SEC);



    printf("Copying array for QuickSort ... ");
    start = clock();
    arrayCopy = malloc(sizeof(long) * testSize);
    memcpy(arrayCopy, inputArray, sizeof(long) * testSize);
    stop = clock();
    printf("took %.2fms\n", 1000 * (double) (stop - start) / CLOCKS_PER_SEC);

    printf("Performing QuickSort ... ");
    start = clock();
    quickSort(arrayCopy, 0, testSize - 1);
    free(arrayCopy);
    stop = clock();
    printf("took %.2fms\n\n", 1000 * (double) (stop - start) / CLOCKS_PER_SEC);

    free(inputArray);
    return 0;
}
