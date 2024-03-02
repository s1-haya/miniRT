#include "unity.h"
#include "shape.h"
#include "scene.h"
// #include <mlx.h>
#include <stdbool.h>


// bool verify_single_argument(int argc);
void parser(t_scene *scene, const char *file_name, bool *result);
t_shape *determine_intersection_ray_and_object(t_list *shape, t_ray ray, double light_distance);
void shading(t_scene *scene, t_shape *nearest_shape, int x, int y);
t_mlx_data new_mlx_data();
t_camera new_camera(t_vector view_point, t_vector look_at_point, double horizontal_value);
double clamp(double v, double v_min, double v_max);

void	printVector(t_vector vector, char *name)
{
	printf("%s: x %d, y %d, z %d\n", name, vector.x, vector.y, vector.z);
}


void	printRGB(t_rgb rgb)
{
	printf("red %d, green %d, blue %d\n", rgb.red, rgb.green, rgb.blue);
}

void	printSphere(t_sphere *sphere)
{
	printf("sphere:\n");
	printVector(sphere->origin, "sphere origin");
	printf("radius %f\n", sphere->radius);
	printRGB(sphere->rgb);
}

void	printPlane(t_plane *plane)
{
	printf("plane:\n");
	printVector(plane->point, "plane point");
	printVector(plane->normal, "plane normal");
	printRGB(plane->rgb);
}

void	printCylinder(t_cylinder *cylinder)
{
	printf("cylinder:\n");
	printVector(cylinder->origin, "cylinder origin");
	printVector(cylinder->axis, "cylinder axis");
	printf("radius: %f", cylinder->radius);
	printf("height: %f", cylinder->height);
	printRGB(cylinder->rgb);
}

void	printShape(t_list *list)
{
	while (list != NULL)
	{
		if (((t_shape *)list->content)->object == PLANE)
			printPlane((t_plane *)(((t_shape *)list->content)->substance));
		else if (((t_shape *)list->content)->object == SPHERE)
			printSphere((t_sphere *)(((t_shape *)list->content)->substance));
		else if (((t_shape *)list->content)->object == CYLINDER)
			printCylinder((t_cylinder *)(((t_shape *)list->content)->substance));
		else
			printf("none;\n");
		list = list->next;
	}
}


void	test_exec_with_true()
{
	t_scene	scene;
	bool	result;

	result = true;
	// scene.mlx = new_mlx_data();
	parser(&scene, "./ft_file/success/three_shpere.rt", &result);
	TEST_ASSERT_TRUE(result);
	if (scene.shape != NULL)
	{
		printf("ok\n");
		printShape(scene.shape);
		printf("end\n");
	}
}

void	test_exec(void)
{
	RUN_TEST(test_exec_with_true);

}
