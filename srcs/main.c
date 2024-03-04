/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:52:18 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/04 19:08:43 by erin             ###   ########.fr       */
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
#include "mlx_data.h"

#define SUCCESS 0
#define FAILURE 1

bool verify_single_argument(int argc);
void parser(t_scene *scene, const char *file_name, bool *result);
t_shape *determine_intersection_ray_and_object(t_list *shape, t_ray ray, double light_distance);
void shading(t_scene *scene, t_shape *nearest_shape, int x, int y);
t_mlx_data	new_mlx_data(bool *result);
t_camera new_camera(t_vector view_point, t_vector look_at_point, double horizontal_value);
double clamp(double v, double v_min, double v_max);
void	free_scene(t_scene *scene);

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
	t_vector	up;
	t_vector	d_x;
	t_vector	d_y;
	t_vector	pw;

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

void render_scene(t_scene *scene)
{
	int		x;
	int		y;
	t_ray	ray;
	t_shape	*nearest_shape;

	x = IMG_ORIGIN_X;
	while (x < IMG_MAX_X)
	{
		y = IMG_ORIGIN_Y;
		while (y < IMG_MAX_Y)
		{
			ray = set_viewpoint(&scene->camera, \
				map((double)x, IMG_MAX_X, -1.0, 1.0), \
					map((double)y, IMG_MAX_Y, 1.0, -1.0));
			nearest_shape = \
			determine_intersection_ray_and_object(scene->shape, ray, LONG_MAX);
			shading(scene, nearest_shape, x, y);
			y++;
		}
		x++;
	}
}

void	print_shape(t_list *list);

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
	if (scene.shape != NULL)
		print_shape(scene.shape);
	render_scene(&scene);
	mlx_conf(&scene);
	return (SUCCESS);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q miniRT");
}
