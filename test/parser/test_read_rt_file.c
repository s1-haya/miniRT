#include "unity.h"
#include "parser.h"

t_minirt_list	*read_rt_file(const char *file_name, bool *result);
void	delete_minirt_list(t_minirt_list *list);
void	print_minirt_list(t_minirt_list *list);

void	test_read_one_line_file_with_true()
{
	bool	result = true;
	t_minirt_list	*list = read_rt_file("./ft_file/success/rt_test.rt", &result);
	TEST_ASSERT_TRUE(result);
	TEST_ASSERT_NOT_NULL(list);
	if (list == NULL)
		return ;
	TEST_ASSERT_EQUAL_STRING("fa", list->identifier);
	const char *testStrings[] = { "fa", "afasd", "faf", "a", NULL};
	TEST_ASSERT_EQUAL_STRING_ARRAY(testStrings, list->value, 5);
	print_minirt_list(list);
	delete_minirt_list(list);
}

void	test_read_rt_file(void)
{
	RUN_TEST(test_read_one_line_file_with_true);
}
