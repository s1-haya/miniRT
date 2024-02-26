#include "unity.h"
#include "parser.h"
#include "scene.h"

void	parser(t_scene *scene, const char *file_name, bool *result);
void	delete_minirt_list(t_minirt_list *list);
void	print_minirt_list(t_minirt_list *list);
t_scene	new_scene(t_shape **shape,
				t_light *light, 
				t_camera camera,
				t_mlx_data data);

void	test_parser_one_line_with_true()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	// exit(0);
	parser(&scene, "./ft_file/success/one_line.rt", &result);
	TEST_ASSERT_TRUE(result);
}

void	test_parser_one_line_in_new_line_with_true()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	// exit(0);
	parser(&scene, "./ft_file/success/one_line_in_new_line.rt", &result);
	TEST_ASSERT_TRUE(result);
}

void	test_parser_only_new_line_with_true()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	// exit(0);
	parser(&scene, "./ft_file/success/only_new_line.rt", &result);
	TEST_ASSERT_TRUE(result);
}

void	test_parser_multi_line_with_true()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	// exit(0);
	parser(&scene, "./ft_file/success/multi_line.rt", &result);
	TEST_ASSERT_TRUE(result);
}

void	test_last_char_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./ft_file/success/last_char.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void	test_only_space_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./ft_file/error/only_space.rt", &result);
	TEST_ASSERT_FALSE(result);
}
void	test_only_tab_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./ft_file/error/only_tab.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void	test_not_file_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./ft_file/error/not_file.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void	test_not_identifier_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./ft_file/error/not_identifier.rt", &result);
	TEST_ASSERT_FALSE(result);
}

void	test_not_value_with_false()
{
	t_scene scene;
	t_camera camera;
	t_mlx_data data;
	bool result = true;
	camera.distance = 0;
	data.data = 0;
	scene = new_scene(NULL, NULL, camera, data);
	parser(&scene, "./ft_file/error/not_value.rt", &result);
	TEST_ASSERT_FALSE(result);
}
void	test_parser(void)
{
	RUN_TEST(test_parser_one_line_with_true);
	RUN_TEST(test_parser_one_line_in_new_line_with_true);
	RUN_TEST(test_parser_only_new_line_with_true);
	RUN_TEST(test_last_char_with_false);
	RUN_TEST(test_only_space_with_false);
	RUN_TEST(test_only_tab_with_false);
	RUN_TEST(test_parser_multi_line_with_true);
	RUN_TEST(test_not_file_with_false);
	RUN_TEST(test_not_identifier_with_false);
	RUN_TEST(test_not_value_with_false);
}
