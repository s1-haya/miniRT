#include "test.h"
#include "stdbool.h"

void setUp(void) {
}

void tearDown(void) {
}

int main(void) {
    UNITY_BEGIN(); 
	// parse
    test_convert_one_line_to_minirt_list();
    // test_is_target_file_extension();
    // test_load_file_into_minirt_list();
    return UNITY_END();
}
