#include "unity.h"
#include "parser.h"

t_minirt_list *read_rt_file(const char *file_name, bool *result);
void delete_minirt_list(t_minirt_list *list);
void print_minirt_list(t_minirt_list *list);

void test_read_one_line_file_with_true()
{
	bool result = true;
	t_minirt_list *list = read_rt_file("./rt_file/success/rt_test.rt", &result);
	TEST_ASSERT_TRUE(result);
	TEST_ASSERT_NOT_NULL(list);
	if (list == NULL)
		return;
	print_minirt_list(list);
	TEST_ASSERT_EQUAL_STRING("fa", list->identifier);
	const char *testStrings[] = {"fa", "afasd", "faf", "a", NULL};
	TEST_ASSERT_EQUAL_STRING_ARRAY(testStrings, list->value, 5);
	delete_minirt_list(list);
}

void test_read_multi_line_file_with_true()
{
	bool result = true;
	t_minirt_list *list = read_rt_file("./rt_file/success/rt.rt.rt", &result);
	TEST_ASSERT_TRUE(result);
	TEST_ASSERT_NOT_NULL(list);
	if (list == NULL)
		return;
	print_minirt_list(list);
	TEST_ASSERT_EQUAL_STRING("A", list->identifier);
	const char *testStrings[] = {"0.1", "122,255,122\n", NULL};
	TEST_ASSERT_EQUAL_STRING_ARRAY(testStrings, list->value, 2);
	delete_minirt_list(list);
}

void test_read_t_rtxt_rt_file_with_false()
{
	bool result = true;
	t_minirt_list *list = read_rt_file("./rt_file/error/t.rtxt_rt", &result);
	TEST_ASSERT_FALSE(result);
	TEST_ASSERT_NULL(list);
	if (list == NULL)
		return;
	print_minirt_list(list);
	TEST_ASSERT_EQUAL_STRING("A", list->identifier);
	const char *testStrings[] = {"0.1", "122,255,122\n", NULL};
	TEST_ASSERT_EQUAL_STRING_ARRAY(testStrings, list->value, 2);
	delete_minirt_list(list);
}

void test_read_test_txt_file_with_false()
{
	bool result = true;
	t_minirt_list *list = read_rt_file("./rt_file/error/text.txt", &result);
	TEST_ASSERT_FALSE(result);
	TEST_ASSERT_NULL(list);
	if (list == NULL)
		return;
	print_minirt_list(list);
	TEST_ASSERT_EQUAL_STRING("A", list->identifier);
	const char *testStrings[] = {"0.1", "122,255,122\n", NULL};
	TEST_ASSERT_EQUAL_STRING_ARRAY(testStrings, list->value, 2);
	delete_minirt_list(list);
}

void test_read_rt_file(void)
{
	RUN_TEST(test_read_one_line_file_with_true);
	RUN_TEST(test_read_multi_line_file_with_true);
	RUN_TEST(test_read_t_rtxt_rt_file_with_false);
	RUN_TEST(test_read_test_txt_file_with_false);
}
