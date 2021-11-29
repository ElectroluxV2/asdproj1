cmake_minimum_required(VERSION 3.20)
project(asdproj1 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS_RELEASE "-Wall -Wextra")
set(CMAKE_C_FLAGS_RELEASE "-O3")

add_executable(asdproj1 src/main.c src/shared.h src/shared.c src/algorithms/countingSort.c src/algorithms/countingSort.h src/algorithms/insertionSort.c src/algorithms/insertionSort.h src/algorithms/heapSort.c src/algorithms/heapSort.h src/algorithms/quickSort.c src/algorithms/quickSort.h src/algorithms/radixSort.c src/algorithms/radixSort.h src/algorithms/timSort.c src/algorithms/timSort.h)
