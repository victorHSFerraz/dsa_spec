#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdio.h>
#include <stdlib.h>

void quit(int* ptrRunning);

void insert_at(int* array, int size, int pos, int value);

void remove_at(int* array, int size, int pos);

void display_array(int* array, int size);

#endif