#include "unity_internals.h"
// #define UNITY_INCLUDE_DOUBLE
#include "unity.h"
#include <stdbool.h>
#include <string.h>


double convert_string_to_double_in_range(char *string, double min, double max, bool *result);

void test_double_value_with_true(void) {
	bool result = true;
	double value = convert_string_to_double_in_range("42.0", 0.0, 100.0, &result);
	TEST_ASSERT_TRUE(result);
	TEST_ASSERT_DOUBLE_WITHIN(0.00001, 42.0, value);
}

void test_convert_string_to_double_in_range_out_of_range_with_false(void) {
	bool result = true;
	double value = convert_string_to_double_in_range("150.0", 0.0, 100.0, &result);
	TEST_ASSERT_FALSE(result);
	TEST_ASSERT_DOUBLE_WITHIN(0.00001, 0, value);
}

void	test_convert_string_to_double_in_range(void)
{
	RUN_TEST(test_double_value_with_true);
	RUN_TEST(test_convert_string_to_double_in_range_out_of_range_with_false);
}
