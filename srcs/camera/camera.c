/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 07:58:00 by hsawamur          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/05 20:01:04 by erin             ###   ########.fr       */
=======
/*   Updated: 2024/03/06 14:03:08 by erin             ###   ########.fr       */
>>>>>>> 84d2404
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

<<<<<<< HEAD
t_camera	new_camera(t_vector view_point, \
			t_vector look_at_point, double horizontal_value)
=======
#include <math.h>

t_camera	new_camera(t_vector view_point, \
				t_vector look_at_point, double horizontal_value)
>>>>>>> 84d2404
{
	t_camera	camera;

	camera.view_point = view_point;
	camera.look_at_point = look_at_point;
	horizontal_value *= M_PI / 180.0;
	camera.distance = (3.5 / 2.0) / tan(horizontal_value / 2.0);
	camera.horizontal_viewing_angle = horizontal_value;
	return (camera);
}
