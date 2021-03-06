//
// Created by mate on 28.11.2021.
//

#ifndef ASDPROJ1_SHARED_H
#define ASDPROJ1_SHARED_H

#include <stdio.h>
#include <malloc.h>
#include <memory.h>

struct Timer;
void timerStart(const char* message);
void timerStop();
FILE* redirectFileToStdin(const char* file);
long* getInputArray(unsigned long length);
void printArray(const long* array, long length);
void swap(long* first, long* second);

#endif //ASDPROJ1_SHARED_H
