#include "../include/array.h"

#include <time.h>

void quit(int* ptrRunning) {
    *ptrRunning = 0;
}

void insert_at(int* array, int size, int pos, int value) {
    if (pos > 0 && pos <= size) {
        *(array + (pos - 1)) = value;
    } else {
        printf("Invalid position %d\n", pos);
    }
}

void remove_at(int* array, int size, int pos) {
    if (pos > 0 && pos <= size) {
        *(array + (pos - 1)) = 0;
    } else {
        printf("Invalid position %d\n", pos);
    }
}

void display_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(array + i));
    }
}

void set_random_values(int* array, int size, int maxRandomValue) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < size; i++) {
        *(array + i) = rand() % (maxRandomValue + 1);
    }
}