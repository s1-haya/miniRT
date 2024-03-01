/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:39:02 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/01 16:06:25 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"
#include <math.h>

#define MIN_HORIZONTAL_ANGLE (0)
#define MAX_HORIZONTAL_ANGLE (180)
#define SCREEN_WIDTH (3.5)

void	check_direction_vector(t_vector vector, bool *result);

void	validate_camera(t_scene *scene, char **value,
				t_param_count *count, bool *result)
{
	size_t	size;

	size = get_string_array_size(value);
	if (size != 3)
	{
		*result = false;
		return ;
	}
	count->camera ++;
	scene->camera = new_camera(convert_value_to_vector_in_range(value[0],
								INT_MIN, INT_MAX, result),
								convert_value_to_vector_in_range(value[1],
									MIN_DIRECTION, MAX_DIRECTION, result),
								convert_string_to_unint8_in_range(value[2],
								MIN_HORIZONTAL_ANGLE, MAX_HORIZONTAL_ANGLE, result));
	check_direction_vector(scene->camera.look_at_point, result);
}
