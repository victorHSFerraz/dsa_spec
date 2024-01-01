#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdio.h>
#include <stdlib.h>

void quit(int* ptrRunning);

void clean_buffer();

void insert_at(int* array, int size);

void remove_at(int* array, int size);

void display_array(int* array, int size);

#endif