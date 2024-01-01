#include "../include/array.h"
#include "./unity/unity.h"

void setUp(void) {
}

void tearDown(void) {
}

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

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_quit);
    RUN_TEST(test_clean_buffer);
    RUN_TEST(test_insert_at);
    RUN_TEST(test_remove_at);
    RUN_TEST(test_display_array);
    return UNITY_END();
}
