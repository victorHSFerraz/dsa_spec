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
                    add_value(array, size);
                    continue;

                case 3:
                    remove_value(array, size);
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
