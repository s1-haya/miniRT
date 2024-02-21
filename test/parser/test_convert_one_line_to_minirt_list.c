#include "unity.h"
#include "parser.h"

t_minirt_list	*convert_one_line_to_minirt_list(char *line, bool *result);
void	delete_minirt_list(t_minirt_list *list);

void	test_convert_with_true(void)
{
	bool result = true;
	t_minirt_list *list = convert_one_line_to_minirt_list("a a b c", &result);
	TEST_ASSERT_TRUE(result);
	TEST_ASSERT_EQUAL_STRING("a", list->identifier);
	const char *testStrings[] = { "a", "b", "c" };
	TEST_ASSERT_EQUAL_STRING_ARRAY(testStrings, list->value, 3);
	delete_minirt_list(list);
}

void	test_convert_with_error(void)
{
	bool result = true;
	t_minirt_list *list = convert_one_line_to_minirt_list("", &result);
	TEST_ASSERT_FALSE(result);
	TEST_ASSERT_NULL(list);
	if (list == NULL)
		return ;
	TEST_ASSERT_EQUAL_STRING("a", list->identifier);
	const char *testStrings[] = { "a", "b", "c" };
	TEST_ASSERT_EQUAL_STRING_ARRAY(testStrings, list->value, 3);
	delete_minirt_list(list);
}

void	test_convert_one_line_to_minirt_list(void)
{
	RUN_TEST(test_convert_with_true);
	RUN_TEST(test_convert_with_error);
}
