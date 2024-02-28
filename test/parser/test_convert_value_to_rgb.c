#include "unity.h"
#include "color.h"
#include <stdbool.h>

t_rgb	convert_value_to_rgb(const char *value, bool *result);

void	test_convert_value_to_rgb_with_true()
{
	bool result = true;
	t_rgb rgb = convert_value_to_rgb("255,255,255", &result);
	TEST_ASSERT_TRUE(result);
	TEST_ASSERT_EQUAL_UINT8(rgb.red, 255);
	TEST_ASSERT_EQUAL_UINT8(rgb.green, 255);
	TEST_ASSERT_EQUAL_UINT8(rgb.blue, 255);
}

void	test_convert_value_to_rgb(void)
{
	RUN_TEST(test_convert_value_to_rgb_with_true);
}
