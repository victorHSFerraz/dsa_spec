#include "../include/buffer_utils.h"

void clean_buffer(GetCharFunc getCharFunc) {
    // clear the buffer when the user input invalid value through scanf to avoid infinite loop
    while (getCharFunc() != '\n') {
    };
}

int actual_getchar() {
    return getchar();
}