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

void	test_parser_with_true()
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

void	test_parser(void)
{
	RUN_TEST(test_parser_with_true);
}
