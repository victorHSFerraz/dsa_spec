#include "test_array.h"

void test_quit(void) {
    int running = 1;
    int* ptrRunning = &running;
    quit(ptrRunning);
    TEST_ASSERT_EQUAL_INT(0, running);
}

void test_insert_at(void) {
    int test_array[] = {1, 2, 3, 4, 5};
    int size = sizeof(test_array) / sizeof(test_array[0]);
    insert_at(test_array, size, 3, 10);
    TEST_ASSERT_EQUAL_INT(10, test_array[2]);
}

void test_remove_at(void) {
    int test_array[] = {1, 2, 3, 4, 5};
    int size = sizeof(test_array) / sizeof(test_array[0]);
    remove_at(test_array, size, 3);
    TEST_ASSERT_EQUAL_INT(0, test_array[2]);
}

void test_set_random_values(void) {
    int test_array[] = {1, 2, 3, 4, 5};
    int size = sizeof(test_array) / sizeof(test_array[0]);
    int minRandomValue = 0;
    int maxRandomValue = 100;
    set_random_values(test_array, size, maxRandomValue);
    for (int i = 0; i < size; i++) {
        TEST_ASSERT_GREATER_OR_EQUAL_INT(minRandomValue, test_array[i]);
        TEST_ASSERT_LESS_OR_EQUAL_INT(maxRandomValue, test_array[i]);
    }
}

void test_linear_search(void) {
    int test_array[] = {1, 2, 3, 4, 5};
    int size = sizeof(test_array) / sizeof(test_array[0]);
    int resultSuccess = linear_search(test_array, size, 3);
    int resultFailure = linear_search(test_array, size, 10);
    TEST_ASSERT_EQUAL_INT(2, resultSuccess);
    TEST_ASSERT_EQUAL_INT(-1, resultFailure);
}
