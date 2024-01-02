#include "./test_suites/array/test_array.h"
#include "./test_suites/buffer_utils/test_buffer_utils.h"
#include "./unity/unity.h"

void setUp(void) {
    call_count = 0;
}

void tearDown(void) {
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_quit);
    RUN_TEST(test_clean_buffer);
    RUN_TEST(test_insert_at);
    RUN_TEST(test_remove_at);
    return UNITY_END();
}