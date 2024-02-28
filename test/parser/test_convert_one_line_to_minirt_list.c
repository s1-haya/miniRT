#include "unity.h"
#include "parser.h"

t_minirt_list	*convert_one_line_to_minirt_list(char *line, bool *result);
void	delete_minirt_list(t_minirt_list *list);
void	print_minirt_list(t_minirt_list *list);

void	test_convert_with_true(void)
{
	bool result = true;
	t_minirt_list *list = convert_one_line_to_minirt_list("a a b c", &result);
	TEST_ASSERT_TRUE(result);
	TEST_ASSERT_EQUAL_STRING("a", list->identifier);
	const char *testStrings[] = { "a", "b", "c" };
	TEST_ASSERT_EQUAL_STRING_ARRAY(testStrings, list->value, 3);
	print_minirt_list(list);
	delete_minirt_list(list);
}


void	test_convert_front_space_string_with_true(void)
{
	bool result = true;
	t_minirt_list *list = convert_one_line_to_minirt_list("      a  a  b c", &result);
	TEST_ASSERT_TRUE(result);
	TEST_ASSERT_NOT_NULL(list);
	if (list == NULL)
		return ;
	TEST_ASSERT_EQUAL_STRING("a", list->identifier);
	const char *testStrings[] = { "a", "b", "c" };
	TEST_ASSERT_EQUAL_STRING_ARRAY(testStrings, list->value, 3);
	print_minirt_list(list);
	delete_minirt_list(list);
}

void	test_convert_back_space_string_with_true(void)
{
	bool result = true;
	t_minirt_list *list = convert_one_line_to_minirt_list("a a  b c           ", &result);
	TEST_ASSERT_TRUE(result);
	TEST_ASSERT_NOT_NULL(list);
	if (list == NULL)
		return ;
	TEST_ASSERT_EQUAL_STRING("a", list->identifier);
	const char *testStrings[] = { "a", "b", "c", NULL };
	TEST_ASSERT_EQUAL_STRING_ARRAY(testStrings, list->value, 4);
	print_minirt_list(list);
	delete_minirt_list(list);
}

void	test_convert_front_and_back_space_string_with_true(void)
{
	bool result = true;
	t_minirt_list *list = convert_one_line_to_minirt_list("    a   a  b cdd           ", &result);
	TEST_ASSERT_TRUE(result);
	TEST_ASSERT_NOT_NULL(list);
	if (list == NULL)
		return ;
	TEST_ASSERT_EQUAL_STRING("a", list->identifier);
	const char *testStrings[] = { "a", "b", "cdd", NULL};
	TEST_ASSERT_EQUAL_STRING_ARRAY(testStrings, list->value, 4);
	print_minirt_list(list);
	delete_minirt_list(list);
}

void	test_convert_newline_charactor_in_string_with_true(void)
{
	bool result = true;
	t_minirt_list *list = convert_one_line_to_minirt_list("    \n a a  '\n' b cdd           ", &result);
	TEST_ASSERT_TRUE(result);
	TEST_ASSERT_NOT_NULL(list);
	if (list == NULL)
		return ;
	TEST_ASSERT_EQUAL_STRING("\n", list->identifier);
	const char *testStrings[] = { "a", "a", "'\n'", "b", "cdd", NULL};
	TEST_ASSERT_EQUAL_STRING_ARRAY(testStrings, list->value, 4);
	print_minirt_list(list);
	delete_minirt_list(list);
}

void	test_convert_empty_string_with_error(void)
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
	print_minirt_list(list);
}

void	test_convert_not_space_string_with_error(void)
{
	bool result = true;
	t_minirt_list *list = convert_one_line_to_minirt_list("aa", &result);
	TEST_ASSERT_FALSE(result);
	TEST_ASSERT_NULL(list);
	if (list == NULL)
		return ;
	TEST_ASSERT_EQUAL_STRING("aa", list->identifier);
	const char *testStrings[] = { "a", "b", "c" };
	TEST_ASSERT_EQUAL_STRING_ARRAY(testStrings, list->value, 3);
	delete_minirt_list(list);
	print_minirt_list(list);
}

void	test_convert_one_string_with_error(void)
{
	bool result = true;
	t_minirt_list *list = convert_one_line_to_minirt_list("      a\ta      ", &result);
	TEST_ASSERT_FALSE(result);
	TEST_ASSERT_NULL(list);
	if (list == NULL)
		return ;
	TEST_ASSERT_EQUAL_STRING("aa", list->identifier);
	const char *testStrings[] = { "a", "b", "c" };
	TEST_ASSERT_EQUAL_STRING_ARRAY(testStrings, list->value, 3);
	delete_minirt_list(list);
	print_minirt_list(list);
}

void	test_convert_one_line_to_minirt_list(void)
{
	RUN_TEST(test_convert_with_true);
	RUN_TEST(test_convert_front_space_string_with_true);
	RUN_TEST(test_convert_back_space_string_with_true);
	RUN_TEST(test_convert_front_and_back_space_string_with_true);
	RUN_TEST(test_convert_newline_charactor_in_string_with_true);

	RUN_TEST(test_convert_empty_string_with_error);
	RUN_TEST(test_convert_not_space_string_with_error);
	RUN_TEST(test_convert_one_string_with_error);
}
