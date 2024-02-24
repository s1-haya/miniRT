#include "unity.h"
#include "parser.h"
#include <stdbool.h>

bool	validate(t_minirt_list *list, bool *result);
// テストするためのモックオブジェクトを作成
t_minirt_list create_mock_object(char *identifier, char **value) {
    t_minirt_list mock;
    mock.identifier = identifier;
    mock.value = value;
    return mock;
}

// AMBIENT_LIGHTINGのテスト
void test_validate_ambient_lighting_with_true(void) {
    char *value[] = {"0.2", "255,255,255", NULL};
    t_minirt_list mock = create_mock_object("A", value);
    bool result = true;
    validate(&mock, &result);
    TEST_ASSERT_TRUE(result);
}

// CAMERAのテスト
void test_validate_camera_with_true(void) {
    char *value[] = {"0,0,20", "0,0,-1", "70", NULL};
    t_minirt_list mock = create_mock_object("C", value);
    bool result = true;
    validate(&mock, &result);
    TEST_ASSERT_TRUE(result);
}

// LIGHTのテスト
void test_validate_light_with_true(void) {
    char *value[] = {"0,0,20", "0.5", "255,255,255", NULL};
    t_minirt_list mock = create_mock_object("L", value);
    bool result = true;
    validate(&mock, &result);
    TEST_ASSERT_TRUE(result);
}

// PLANEのテスト
void test_validate_plane_with_true(void) {
    char *value[] = {"0,1,0", "0,0,1", "255,255,255", NULL};
    t_minirt_list mock = create_mock_object("pl", value);
    bool result = true;
    validate(&mock, &result);
    TEST_ASSERT_TRUE(result);
}

// SPHEREのテスト
void test_validate_sphere_with_true(void) {
    char *value[] = {"0,0,20", "5", "255,0,0", NULL};
    t_minirt_list mock = create_mock_object("sp", value);
    bool result = true;
    validate(&mock, &result);
    TEST_ASSERT_TRUE(result);
}

// CYLINDERのテスト
void test_validate_cylinder_with_true(void) {
    char *value[] = {"0,0,20", "0,0,1", "5", "10", "255,255,0", NULL};
    t_minirt_list mock = create_mock_object("cy", value);
    bool result = true;
    validate(&mock, &result);
    TEST_ASSERT_TRUE(result);
}

void test_validate_other_with_error(void) {
    char *value[] = {"0,0,20", "0,0,1", "5", "10", "255,255,0", NULL};
    t_minirt_list mock = create_mock_object("y", value);
    bool result = true;
    validate(&mock, &result);
    TEST_ASSERT_FALSE(result);
}

void	test_validate(void)
{
	RUN_TEST(test_validate_ambient_lighting_with_true);
	RUN_TEST(test_validate_camera_with_true);
	RUN_TEST(test_validate_light_with_true);
	RUN_TEST(test_validate_plane_with_true);
	RUN_TEST(test_validate_sphere_with_true);
	RUN_TEST(test_validate_cylinder_with_true);
	RUN_TEST(test_validate_other_with_error);
}
