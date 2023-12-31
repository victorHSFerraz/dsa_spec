#include <stdio.h>
#include <stdlib.h>

void quit(int* ptrRunning) {
    *ptrRunning = 0;
}

void clean_buffer() {
    // clear the buffer when the user input invalid value
    while (getchar() != '\n') {
    };
}

void insert_at(int* array, int size) {
    int pos = 0;
    printf("Insert the position of the value: ");
    while (scanf("%d", &pos) != 1) {
        printf("Invalid position %d\n", pos);
        clean_buffer();
    }
    if (pos > 0 && pos <= size) {
        int value = 0;
        printf("Insert integer value: ");
        while (scanf("%d", &value) != 1) {
            printf("Invalid integer value %d\n", value);
            clean_buffer();
        }
        *(array + (pos - 1)) = value;
    } else {
        printf("Invalid position %d\n", pos);
    }
}

void remove_at(int* array, int size) {
    int pos = 0;
    printf("Remove at position: ");
    while (scanf("%d", &pos) != 1) {
        printf("Invalid position %d\n", pos);
        clean_buffer();
    }
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
            printf("\n\n1 - Display array\n2 - Add value\n3 - Remove value\n0 - Exit\n\n");
            scanf("%d", &selectedOption);
            switch (selectedOption) {
                case 0:
                    quit(ptrRunning);
                    break;

                case 1:
                    display_array(array, size);
                    continue;

                case 2:
                    insert_at(array, size);
                    continue;

                case 3:
                    remove_at(array, size);
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