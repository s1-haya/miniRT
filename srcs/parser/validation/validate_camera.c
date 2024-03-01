/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:39:02 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/01 17:46:50 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"
#include <math.h>

#define MIN_HORIZONTAL_ANGLE (0)
#define MAX_HORIZONTAL_ANGLE (180)

#define SCREEN_WIDTH (3.5)

void	validate_camera(t_scene *scene, char **value,
				t_param_count *count, bool *result)
{
	size_t	size;
	double	horizontal_value;

	size = get_string_array_size(value);
	if (size != 3)
	{
		*result = false;
		return ;
	}
	count->camera ++;
	scene->camera.view_point = convert_value_to_vector_in_range(value[0], INT_MIN,
										INT_MAX, result);
	scene->camera.look_at_point = convert_value_to_normal_vector(value[1], result);
	horizontal_value = convert_string_to_unint8_in_range(value[2], MIN_HORIZONTAL_ANGLE,
										MAX_HORIZONTAL_ANGLE, result) * M_PI / 180.0;
	scene->camera.distance = (SCREEN_WIDTH / 2.0) / tan(horizontal_value / 2.0);
	scene->camera.horizontal_viewing_angle = horizontal_value;
}
