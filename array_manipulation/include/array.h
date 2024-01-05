#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdio.h>
#include <stdlib.h>

void quit(int* ptrRunning);

void insert_at(int* array, int size, int pos, int value);

void remove_at(int* array, int size, int pos);

void display_array(int* array, int size);

void set_random_values(int* array, int size, int maxRandomValue);

int linear_search(int* array, int size, int value);

int binary_search(int* array, int size, int value);

void quick_sort(int* array, int size);

// void bubble_sort(int* array, int size);

// void selection_sort(int* array, int size);

// void insertion_sort(int* array, int size);

// void reverse_array(int* array, int size);

#endif