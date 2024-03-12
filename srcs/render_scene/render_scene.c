/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:47:43 by erin              #+#    #+#             */
/*   Updated: 2024/03/11 12:00:29 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_scene.h"

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
	pw = add_vectors(pw, scalar_multiply(d_x, camera->screen_width / 2.0));
	pw = add_vectors(pw, scalar_multiply(d_y, camera->screen_height / 2.0));
	pw = add_vectors(pw, scalar_multiply(d_x, lx));
	pw = add_vectors(pw, scalar_multiply(d_y, ly));
	return (new_ray(camera->view_point, \
					subtract_vectors(pw, camera->view_point)));
}

void	render_scene(t_scene *scene)
{
	int				x;
	int				y;
	t_ray			ray;
	t_shape			*nearest_shape;

	x = WINDOW_ORIGIN_X;
	while (x < WINDOW_WIDTH)
	{
		y = WINDOW_ORIGIN_Y;
		while (y < WINDOW_HEIGHT)
		{
			ray = set_viewpoint(&scene->camera, \
				-x * scene->camera.screen_width / WINDOW_WIDTH, \
					-y * scene->camera.screen_height / WINDOW_HEIGHT);
			nearest_shape = \
			determine_intersection_ray_and_object(scene->shape, ray, LONG_MAX);
			shading(scene, nearest_shape, x, y);
			y++;
		}
		x++;
	}
}
