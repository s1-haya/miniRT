#include "unity.h"
#include "parser.h"
#include "scene.h"

void parser(t_scene *scene, const char *file_name, bool *result);
void delete_minirt_list(t_minirt_list *list);
void print_minirt_list(t_minirt_list *list);
t_scene new_scene(t_shape **shape,
				  t_light *light,
				  t_camera camera,
				  t_mlx_data data);

void test_parser_multi_line_with_true()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/success/multi_line.rt", &result);
	TEST_ASSERT_TRUE(result);
}

void test_parser_basic_with_true()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/success/basic.rt", &result);
	TEST_ASSERT_TRUE(result);
}

void test_parser_one_line_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	// exit(0);
	parser(&scene, "./rt_file/error/one_line.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_parser_one_line_in_new_line_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	// exit(0);
	parser(&scene, "./rt_file/error/one_line_in_new_line.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_parser_only_new_line_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	// exit(0);
	parser(&scene, "./rt_file/error/only_new_line.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_multi_ambient_and_camera_identifier_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	// exit(0);
	parser(&scene, "./rt_file/error/ambient_and_camera_line.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_last_char_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/success/last_char.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_multi_ambient_identifier_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/error/multi_ambient_identifier.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_multi_camera_identifier_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/error/multi_camera_identifier.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_multi_light_identifier_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/error/multi_light_identifier.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_only_space_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/error/only_space.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_only_tab_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/error/only_tab.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_not_file_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/error/not_file.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_wrong_identifier_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/error/wrong_identifier.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_wrong_value_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/error/wrong_value.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_multi_identifier_and_acl_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/error/multi_identifier_and_acl.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_rgb_in_out_of_range_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/error/rgb_in_out_of_range.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_not_unint8_fov_value_in_camera_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/error/not_unint8_fov_value_in_camera.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_before_comma_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/error/before_comma.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_more_int_max_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/error/more_int_max.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_more_param_size_in_light_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/error/more_param_size_in_light.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_more_param_size_in_ambient_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/error/more_param_size_in_ambient.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_more_param_size_in_camera_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/error/more_param_size_in_camera.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_more_param_size_in_plane_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/error/more_param_size_in_plane.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_more_param_size_in_sphere_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/error/more_param_size_in_sphere.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_more_param_size_in_cylinder_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/error/more_param_size_in_cylinder.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_less_param_size_in_light_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/error/less_param_size_in_light.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_less_param_size_in_ambient_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/error/less_param_size_in_ambient.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_less_param_size_in_camera_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/error/less_param_size_in_camera.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_less_param_size_in_plane_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/error/less_param_size_in_plane.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_less_param_size_in_sphere_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/error/less_param_size_in_sphere.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_less_param_size_in_cylinder_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./rt_file/error/less_param_size_in_cylinder.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void test_parser_with_false()
{
	RUN_TEST(test_parser_one_line_with_false);
	RUN_TEST(test_parser_one_line_in_new_line_with_false);
	RUN_TEST(test_parser_only_new_line_with_false);
	RUN_TEST(test_last_char_with_false);
	RUN_TEST(test_only_space_with_false);
	RUN_TEST(test_only_tab_with_false);
	RUN_TEST(test_not_file_with_false);
	RUN_TEST(test_wrong_identifier_with_false);
	RUN_TEST(test_wrong_value_with_false);
	RUN_TEST(test_multi_ambient_identifier_with_false);
	RUN_TEST(test_multi_ambient_and_camera_identifier_with_false);
	RUN_TEST(test_multi_camera_identifier_with_false);
	RUN_TEST(test_multi_light_identifier_with_false);
	RUN_TEST(test_multi_identifier_and_acl_with_false);
	RUN_TEST(test_not_unint8_fov_value_in_camera_with_false);
	RUN_TEST(test_rgb_in_out_of_range_with_false);
	RUN_TEST(test_before_comma_with_false);
	RUN_TEST(test_more_int_max_with_false);

	RUN_TEST(test_more_param_size_in_ambient_with_false);
	RUN_TEST(test_more_param_size_in_camera_with_false);
	RUN_TEST(test_more_param_size_in_light_with_false);
	RUN_TEST(test_more_param_size_in_plane_with_false);
	RUN_TEST(test_more_param_size_in_cylinder_with_false);
	RUN_TEST(test_more_param_size_in_sphere_with_false);

	RUN_TEST(test_less_param_size_in_ambient_with_false);
	RUN_TEST(test_less_param_size_in_camera_with_false);
	RUN_TEST(test_less_param_size_in_light_with_false);
	RUN_TEST(test_less_param_size_in_plane_with_false);
	RUN_TEST(test_less_param_size_in_cylinder_with_false);
	RUN_TEST(test_less_param_size_in_sphere_with_false);
}

void test_parser(void)
{
	RUN_TEST(test_parser_multi_line_with_true);
	RUN_TEST(test_parser_basic_with_true);
	test_parser_with_false();
}
