#include "test.h"

void setUp(void) {
}

void tearDown(void) {
}

int main(void) {
    UNITY_BEGIN(); 
	// parse
    test_is_target_file_extension();

    return UNITY_END();
}
