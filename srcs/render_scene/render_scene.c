/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:47:43 by erin              #+#    #+#             */
/*   Updated: 2024/03/05 19:44:03 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	map(double x, double max, double orig, double sign)
{
	return (sign * (2 * x) / (max - 1) + orig);
}

t_ray	set_viewpoint(t_camera *camera, double lx, double ly)
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
	pw = add_vectors(pw, \
		scalar_multiply(camera->look_at_point, camera->distance));
	pw = add_vectors(pw, scalar_multiply(d_x, lx));
	pw = add_vectors(pw, scalar_multiply(d_y, ly));
	return (new_ray(camera->view_point, \
					subtract_vectors(pw, camera->view_point)));
}

void	render_scene(t_scene *scene)
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
