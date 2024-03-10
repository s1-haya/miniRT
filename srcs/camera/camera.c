/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 07:58:00 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/09 10:32:21 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "minirt.h"

#include <math.h>

t_camera	new_camera(t_vector view_point, \
				t_vector look_at_point, double horizontal)
{
	t_camera	camera;
	double		radian;

	camera.view_point = view_point;
	camera.look_at_point = look_at_point;
	radian = horizontal * M_PI / 180.0;
	camera.distance = (1.0 / 2.0) / tan(radian / 2.0);
	camera.horizontal_viewing_angle = radian;
	return (camera);
}
