/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 07:58:00 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/03 23:19:50 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "minirt.h"

#include <math.h>

t_camera	new_camera(t_vector view_point, t_vector look_at_point, double horizontal_value)
{
	t_camera	camera;

	camera.view_point = view_point;
	camera.look_at_point = look_at_point;
	horizontal_value *= M_PI / 180.0;
	camera.distance = (3.5 / 2.0) / tan(horizontal_value / 2.0);
	camera.horizontal_viewing_angle = horizontal_value;
	return (camera);
}
