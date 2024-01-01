#include "./test_suites/test_array.h"
#include "./unity/unity.h"

void setUp(void) {
}

void tearDown(void) {
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