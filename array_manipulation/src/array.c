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
    printf("\n");
}

void set_random_values(int* array, int size, int maxRandomValue) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < size; i++) {
        *(array + i) = rand() % (maxRandomValue + 1);
    }
}

int linear_search(int* array, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (*(array + i) == target) {
            return i;
        }
    }
    return -1;
}

// 1, 2, 10, 3, 11, 8
int binary_search(int* array, int size, int target) {
    // target = 11
    // define low and high variables to keep track of the range of the array
    int low = 0;
    int high = size - 1;  // 5

    while (low <= high) {
        int middle = low + (high - low) / 2;  // 2 ---- 4
        int value = *(array + middle);        // 10 ---- 11

        if (value > target) {
            // discard the right side of the array setting a lower high value
            high = middle - 1;
        } else if (value < target) {
            // discard the left side of the array setting a higher low value
            low = middle + 1;  // 3
        } else {
            // the value is equal to the target
            return middle;  // ---- 4
        }
    }

    return -1;
}

// 1, 2, 10, 3, 11, 8
void quick_sort(int* array, int start, int end) {
    if (start < end) {
        int pivot = *(array + end);  // 8
        int i = start - 1;
        for (int j = start; j < end; j++) {
            // if the current value array[j] is less than the pivot then increment i and swap array[i] and array[j] values
            if (*(array + j) < pivot) {
                i++;
                int temp = *(array + i);
                *(array + i) = *(array + j);
                *(array + j) = temp;
            }
        }
        // 1, 2, 3, 10, 11, 8
        // i = 2
        // now we have to swap the pivot with the value at array[i + 1]
        int temp = *(array + end);
        *(array + end) = *(array + i + 1);
        *(array + i + 1) = temp;
        // // 1, 2, 3, 8, 11, 10
        // all the values less than the pivot are now on the left side of the pivot
        // now we have to sort the left side and the right side of the pivot
        // with recursive calls to quick_sort with start and end values for the left side and the right side
        quick_sort(array, start, i);
        quick_sort(array, i + 2, end);
    }
}

// 1, 2, 10, 3, 11, 8
void bubble_sort(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        // compare the current value with the next value
        for (int j = 0; j < size - i - 1; j++) {
            // if the current value is greater than the next value then swap them
            if (*(array + j) > *(array + j + 1)) {
                int temp = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = temp;
            }
        }
    }
}

void selection_sort(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        // find the minimum value in the unsorted array
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (*(array + j) < *(array + minIndex)) {
                minIndex = j;
            }
        }
        // swap the minimum value with the first value of the unsorted array
        int temp = *(array + i);
        *(array + i) = *(array + minIndex);
        *(array + minIndex) = temp;
    }
}

void insertion_sort(int* array, int size) {
    for (int i = 1; i < size; i++) {
        // store the current value
        int value = *(array + i);
        // store the index of the previous value
        int j = i - 1;
        // while the previous value is greater than the current value
        // and the index is greater than or equal to 0
        while (*(array + j) > value && j >= 0) {
            // move the previous value to the next position
            *(array + j + 1) = *(array + j);
            // decrement the index
            j--;
        }
        // insert the current value at the correct position
        *(array + j + 1) = value;
    }
}

void reverse_array(int* array, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = *(array + i);
        *(array + i) = *(array + size - i - 1);
        *(array + size - i - 1) = temp;
    }
}
