/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:52:18 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/01 18:02:30 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "minirt.h"
#include "shape.h"
#include "color.h"
#include "scene.h"
#include "libft.h"

#define SUCCESS 0
#define FAILURE 1

bool verify_single_argument(int argc);
void parser(t_scene *scene, const char *file_name, bool *result);
t_shape *determine_intersection_ray_and_object(t_list *shape, t_ray ray, double light_distance);
void shading(t_scene *scene, t_shape *nearest_shape, int x, int y);
t_mlx_data new_mlx_data();
t_camera new_camera(t_vector view_point, t_vector look_at_point, double horizontal_value);
double clamp(double v, double v_min, double v_max);

double scaling(double value, double t_min, double t_max)
{
	return (t_min + (t_max - t_min) * value);
}

double map(double x, double max, double orig, double sign)
{
	return (sign * (2 * x) / (max - 1) + orig);
}

bool	comp_vector(t_vector a, t_vector b)
{
	return (a.x == b.x && a.y == b.y && a.z == b.z);
}

t_ray set_viewpoint(t_camera *camera, double lx, double ly)
{
	t_vector up;
	t_vector d_x;
	t_vector d_y;
	t_vector pw;

	up = new_vector(0, 1, 0);
	if (vector_length(cross_product(up, camera->look_at_point)) == 0)
		up = new_vector(1, 0, 0);
	d_x = cross_product(up, camera->look_at_point);
	normalize_vector(&d_x);
	d_y = cross_product(camera->look_at_point, d_x);
	normalize_vector(&d_y);
	pw = camera->view_point;
	pw = add_vectors(pw, scalar_multiply(camera->look_at_point, camera->distance));
	pw = add_vectors(pw, scalar_multiply(d_x, lx));
	pw = add_vectors(pw, scalar_multiply(d_y, ly));
	return (new_ray(camera->view_point, subtract_vectors(pw, camera->view_point)));
}

/////////////////////////////////////////////////////////////////////////// keyconf
int esc_key(int keycode, t_mlx_data *mlx) // sceneにしてこの中でfree
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->data, mlx->window);
		// ft_free_exit(data->map, EXIT_SUCCESS, -1);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int close_window(t_mlx_data *mlx) // sceneにしてこの中でfree
{
	mlx_destroy_window(mlx->data, mlx->window);
	// ft_free_exit(data->map, EXIT_SUCCESS, -1);
	exit(EXIT_SUCCESS);
	return (0);
}

///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
void render_scene(t_scene *scene)
{
	int x;
	int y;
	double lx;
	double ly;
	t_ray ray;
	t_shape *nearest_shape;

	x = IMG_ORIGIN_X;
	while (x < IMG_MAX_X)
	{
		lx = map((double)x, IMG_MAX_X, -1.0, 1.0);
		y = IMG_ORIGIN_Y;
		while (y < IMG_MAX_Y)
		{
			ly = map((double)y, IMG_MAX_Y, 1.0, -1.0);
			ray = set_viewpoint(&scene->camera, lx, ly);
			nearest_shape = determine_intersection_ray_and_object(scene->shape, ray, LONG_MAX);
			shading(scene, nearest_shape, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(scene->mlx.data, scene->mlx.window, scene->mlx.img.data, IMG_ORIGIN_X, IMG_ORIGIN_Y);
	mlx_hook(scene->mlx.window, 2, 1L << 0, esc_key, &scene->mlx);
	mlx_hook(scene->mlx.window, 17, 1L << 17, close_window, &scene->mlx);
	mlx_loop(scene->mlx.data);
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
	printVector(cylinder->origin, "cylinder center");
	printVector(cylinder->axis, "cylinder axis");
	printf("diameter %f\n", cylinder->radius * 2);
	printf("height %f\n", cylinder->height);
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

#include <libc.h>
int main(int argc, char *argv[])
{
	t_scene	scene;
	bool	result;

	if (!verify_single_argument(argc))
		return (FAILURE);
	ft_bzero(&scene, sizeof(t_scene));
	scene.mlx = new_mlx_data();
	parser(&scene, argv[1], &result);
	if (!result)
	{
		// sceneをfreeする。
		return (FAILURE);
	}
	if (scene.shape != NULL)
		printShape(scene.shape);
	render_scene(&scene);
	return (SUCCESS);
}
