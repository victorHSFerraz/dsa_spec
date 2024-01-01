#include "../include/array.h"

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