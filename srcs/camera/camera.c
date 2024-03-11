/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 07:58:00 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/11 11:58:50 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "minirt.h"

#include <math.h>

t_camera	new_camera(t_vector view_point, \
				t_vector look_at_point, double horizontal)
{
	t_camera		camera;
	double			radian;
	const double	aspect = (double)WINDOW_HEIGHT / WINDOW_WIDTH;

	camera.view_point = view_point;
	camera.look_at_point = look_at_point;
	radian = horizontal * M_PI / 180.0;
	camera.distance = 1.0;
	camera.horizontal_viewing_angle = radian;
	camera.screen_width = 2.0 * camera.distance * tan(radian / 2.0);
	camera.screen_height = camera.screen_width * aspect;
	return (camera);
}
