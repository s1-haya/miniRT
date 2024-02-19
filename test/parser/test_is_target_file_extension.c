#include "unity.h"
#include <stdbool.h>
#include <string.h>

// ここにis_target_file_extension関数を含めるか、別のヘッダファイルからインクルードします。
bool	is_target_file_extension(const char *filename, const char *extension);

void test_is_target_file_extension_with_correct_extension(void) {
    TEST_ASSERT_TRUE(is_target_file_extension("test.txt", ".txt"));
}

void test_is_target_file_extension_without_extension(void) {
    TEST_ASSERT_FALSE(is_target_file_extension("test", ".txt"));
}

void test_is_target_file_extension_with_null_filename(void) {
    TEST_ASSERT_FALSE(is_target_file_extension(NULL, ".txt"));
}

void test_is_target_file_extension_with_null_extension(void) {
    TEST_ASSERT_FALSE(is_target_file_extension("test.txt", NULL));
}

void test_is_target_file_extension_with_incorrect_start_of_extension(void) {
    TEST_ASSERT_FALSE(is_target_file_extension("test.txt", "txt"));
}

void test_is_target_file_extension_with_filename_starting_dot(void) {
    TEST_ASSERT_FALSE(is_target_file_extension(".test", ".txt"));
}

void test_is_target_file_extension_with_included_but_incorrect_extension(void) {
    TEST_ASSERT_FALSE(is_target_file_extension("test.txt.jpg", ".txt"));
}

void test_is_target_file_extension(void)
{
    RUN_TEST(test_is_target_file_extension_with_correct_extension);
    RUN_TEST(test_is_target_file_extension_without_extension);
    RUN_TEST(test_is_target_file_extension_with_null_filename);
    RUN_TEST(test_is_target_file_extension_with_null_extension);
    RUN_TEST(test_is_target_file_extension_with_incorrect_start_of_extension);
    RUN_TEST(test_is_target_file_extension_with_filename_starting_dot);
    RUN_TEST(test_is_target_file_extension_with_included_but_incorrect_extension);
}
