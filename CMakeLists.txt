cmake_minimum_required(VERSION 3.20)
project(asdproj1 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(asdproj1 main.c algorithms/shared.h algorithms/shared.c algorithms/countingSort.c algorithms/countingSort.h algorithms/insertionSort.c algorithms/insertionSort.h algorithms/heapSort.c algorithms/heapSort.h algorithms/quickSort.c algorithms/quickSort.h algorithms/radixSort.c algorithms/radixSort.h algorithms/timSort.c algorithms/timSort.h)
