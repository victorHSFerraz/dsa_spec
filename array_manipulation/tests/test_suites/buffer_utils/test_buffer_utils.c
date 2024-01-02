#include "test_buffer_utils.h"

int mock_getchar() {
    const char mock_input[] = {'A', 'B', 'C', '\n'};
    const int num_calls = sizeof(mock_input) / sizeof(mock_input[0]);

    if (call_count < num_calls) {
        return mock_input[call_count++];
    }

    return '\n';
}

void test_clean_buffer(void) {
    clean_buffer(mock_getchar);
    TEST_ASSERT_EQUAL(4, call_count);
}
