#include "test_array.h"

void test_quit(void) {
    int running = 1;
    int* ptrRunning = &running;
    quit(ptrRunning);
    TEST_ASSERT_EQUAL_INT(0, running);
}

void test_clean_buffer(void) {
}

void test_insert_at(void) {
}

void test_remove_at(void) {
}

void test_display_array(void) {
}
