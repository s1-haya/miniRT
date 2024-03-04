/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:52:18 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/04 16:30:44 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <mlx.h>
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
t_mlx_data	new_mlx_data(bool *result);
void	delete_mlx_data(t_mlx_data mlx);
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
	// printVector(camera->look_at_point, "lookat");
	// printVector(up, "up");
	d_x = cross_product(up, camera->look_at_point);
	normalize_vector(&d_x);
	d_y = cross_product(camera->look_at_point, d_x);
	normalize_vector(&d_y);
	// printVector(d_x, "dx");
	// printVector(d_y, "dy");
	// exit(EXIT_SUCCESS);
	pw = camera->view_point;
	pw = add_vectors(pw, scalar_multiply(camera->look_at_point, camera->distance));
	pw = add_vectors(pw, scalar_multiply(d_x, lx));
	pw = add_vectors(pw, scalar_multiply(d_y, ly));
	return (new_ray(camera->view_point, subtract_vectors(pw, camera->view_point)));
}

void	delete_shape(t_list **list)
{
	t_list	*current;
	t_list	*next;

	if (list == NULL || *list == NULL)
		return ;
	current = *list;
	while (current)
	{
		next = current->next;
		free(((t_shape *)(current->content))->substance);
		free((t_shape *)(current->content));
		free(current);
		current = next;
	}
	*list = NULL;
}

void	free_scene(t_scene *scene)
{
	mlx_destroy_window(scene->mlx.data, scene->mlx.window);
	mlx_destroy_image(scene->mlx.data, scene->mlx.img.data);
	mlx_destroy_display(scene->mlx.data);
	delete_shape(&(scene->shape));
	free(scene->light);
}

int esc_key(int keycode, t_scene *scene)
{
	if (keycode == 53)
	{
		free_scene(scene);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

// int close_window(t_scene *scene) __attribute__((noreturn));

int close_window(t_scene *scene)
{
	free_scene(scene);
	exit(EXIT_SUCCESS);
}

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
	mlx_hook(scene->mlx.window, 2, 1L << 0, esc_key, scene);
	mlx_hook(scene->mlx.window, 17, 1L << 17, close_window, scene);
	mlx_loop(scene->mlx.data);
}

void	printRGB(t_rgb rgb)
{
	printf("red %d, green %d, blue %d\n", rgb.red, rgb.green, rgb.blue);
}

void	printSphere(t_sphere *sphere)
{
	printf("sphere:\n");
	printVector(sphere->origin, "origin");
	printf("radius %f\n", sphere->radius);
	printRGB(sphere->rgb);
}

void	printPlane(t_plane *plane)
{
	printf("plane:\n");
	printVector(plane->point, "point");
	printVector(plane->normal, "normal");
	printRGB(plane->rgb);
}

void	printCylinder(t_cylinder *cylinder)
{
	printf("cylinder:\n");
	printVector(cylinder->origin, "center");
	printVector(cylinder->axis, "axis");
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
	result = true;
	scene.mlx = new_mlx_data(&result);
	parser(&scene, argv[1], &result);
	if (!result)
	{
		free_scene(&scene);
		return (FAILURE);
	}
	render_scene(&scene);
	return (SUCCESS);
}

#include <libc.h>

__attribute__((destructor))
static void destructor() {
    system("leaks -q miniRT");
}
