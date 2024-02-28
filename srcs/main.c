/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:52:18 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/25 13:38:36 by erin             ###   ########.fr       */
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

#define SUCCESS 0
#define FAILURE 1

bool	verify_single_argument(int argc);
void	parser(t_scene *scene, const char *file_name, bool *result);
t_shape		*determine_intersection_ray_and_object(t_shape **shape, t_ray ray, double light_distance);
void		shading(t_scene *scene, t_shape *nearest_shape, int x, int y);
t_mlx_data	new_mlx_data();
t_camera	new_camera(t_vector view_point, t_vector look_at_point, double horizontal_value);
t_scene	new_scene(t_shape **shape,
				t_light *light, 
				t_camera camera,
				t_mlx_data data);
double clamp(double v, double v_min, double v_max);

double	scaling(double value, double t_min, double t_max)
{
	return (t_min + (t_max - t_min) * value);
}

double	map(double x, double max, double assign, double sign)
{
	return (sign * (2 * x) / (max - 1) + assign);
}

t_ray	set_viewpoint(t_camera *camera, double lx, double ly)
{
	const t_vector	up = new_vector(0, 1, 0);
	t_vector		d_x;
	t_vector		d_y;
	t_vector		pw;

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
int	esc_key(int keycode, t_mlx_data *mlx) // sceneにしてこの中でfree
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->data, mlx->window);
		// ft_free_exit(data->map, EXIT_SUCCESS, -1);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	close_window(t_mlx_data *mlx) // sceneにしてこの中でfree
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
	int		x;
	int		y;
	double	lx;
	double	ly;
	t_ray	ray;
	t_shape	*nearest_shape;

	x = WINDOW_ORIGIN_X;
	while (x < WINDOW_MAX_X)
	{
		lx = map((double)x, WINDOW_MAX_X, -1.0, 1.0);
		y = WINDOW_ORIGIN_Y;
		while (y < WINDOW_MAX_Y)
		{
			ly = map((double)y, WINDOW_MAX_Y, 1.0, -1.0);
			ray = set_viewpoint(&scene->camera, lx, ly);
			nearest_shape = determine_intersection_ray_and_object(scene->shape, ray, LONG_MAX);
			shading(scene, nearest_shape, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(scene->mlx.data, scene->mlx.window, scene->mlx.img.data, WINDOW_ORIGIN_X, WINDOW_ORIGIN_Y);
	mlx_hook(scene->mlx.window, 2, 1L << 0, esc_key, &scene->mlx);
	mlx_hook(scene->mlx.window, 17, 1L << 17, close_window, &scene->mlx);
	mlx_loop(scene->mlx.data);
}

#include <libc.h>
int main(int argc, char *argv[])
{
	t_scene			scene;
	bool			result;
	// 1 is_valid
	// 2 init(parse)
	// 3 draw
	// 4 hook, loop
	if (!verify_single_argument(argc))
		return (FAILURE);
	result = true;
	scene = new_scene(NULL, NULL,  new_camera(VIEWPOINT, LOOKATPOINT, 70), new_mlx_data());
	parser(&scene, argv[1], &result);
	if (！result)
  {
    //sceneをfreeする。
    return (FAILURE);
  }
	render_scene(&scene);
	return (SUCCESS);
}
