#include "../include/array.h"
#include "../include/buffer_utils.h"

void add_value(int* array, int size) {
    int pos = 0;
    printf("Insert the position of the value: ");
    while (scanf("%d", &pos) != 1) {
        printf("Invalid position %d\n", pos);
        clean_buffer(actual_getchar);
    }
    int value = 0;
    printf("Insert integer value: ");
    while (scanf("%d", &value) != 1) {
        printf("Invalid integer value %d\n", value);
        clean_buffer(actual_getchar);
    }
    insert_at(array, size, pos, value);
}

void remove_value(int* array, int size) {
    int pos = 0;
    printf("Remove at position: ");
    while (scanf("%d", &pos) != 1) {
        printf("Invalid position %d\n", pos);
        clean_buffer(actual_getchar);
    }
    remove_at(array, size, pos);
}

void setup_linear_search(int* array, int size) {
    printf("Search for value: ");
    int value = 0;
    while (scanf("%d", &value) != 1) {
        printf("Invalid value\n");
        clean_buffer(actual_getchar);
    }

    int result = linear_search(array, size, value);
    if (result == -1) {
        printf("Value %d not found\n", value);
    } else {
        printf("Value %d found at index %d\n", value, result);
    }
}

void setup_binary_search(int* array, int size) {
    printf("Search for value: ");
    int value = 0;
    while (scanf("%d", &value) != 1) {
        printf("Invalid value\n");
        clean_buffer(actual_getchar);
    }

    quick_sort(array, 0, size - 1);

    printf("Array sorted\n");

    int result = binary_search(array, size, value);
    if (result == -1) {
        printf("Value %d not found\n", value);
    } else {
        printf("Value %d found at index %d\n", value, result);
    }
}

int main(void) {
    int running = 1;
    int* ptrRunning = &running;
    while (running) {
        printf("Input array size: ");
        int size;
        scanf("%d", &size);
        int* array = calloc(size, sizeof(int));
        if (array == NULL) {
            break;
        }

        while (running) {
            int selectedOption = 0;
            printf("\n\n1 - Display array\n");
            printf("2 - Add value\n");
            printf("3 - Remove value\n");
            printf("4 - Set random values\n");
            printf("5 - Linear Search\n");
            printf("6 - Quick Sort\n");
            printf("7 - Binary Search\n");
            printf("8 - Bubble Sort\n");
            printf("9 - Selection Sort\n");
            // printf("9 - Modify array size\n");
            printf("0 - Exit\n\n");
            scanf("%d", &selectedOption);
            printf("\n");
            switch (selectedOption) {
                case 0:
                    quit(ptrRunning);
                    break;

                case 1:
                    display_array(array, size);
                    continue;

                case 2:
                    add_value(array, size);
                    continue;

                case 3:
                    remove_value(array, size);
                    continue;

                case 4:
                    set_random_values(array, size, 10000);
                    continue;

                case 5:
                    setup_linear_search(array, size);
                    continue;

                case 6:
                    quick_sort(array, 0, size - 1);
                    continue;

                case 7:
                    setup_binary_search(array, size);
                    continue;

                case 8:
                    bubble_sort(array, size);
                    continue;

                case 9:
                    selection_sort(array, size);
                    continue;

                default:
                    break;
            }
        }
        if (array != NULL) {
            free(array);
        }
    }
    return 0;
}
