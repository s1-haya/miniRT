#include "test.h"
#include "stdbool.h"

void setUp(void) {
}

void tearDown(void) {
}

#include <libc.h>
int main(void) {
    UNITY_BEGIN(); 
	// parse
    test_is_target_file_extension();
    test_convert_one_line_to_minirt_list();
    test_read_rt_file();
    // test_load_file_into_minirt_list();
    system("leaks -q test_miniRT");
    return UNITY_END();
}
