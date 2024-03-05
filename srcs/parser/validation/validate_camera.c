/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:39:02 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/05 19:42:45 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define MIN_HORIZONTAL_ANGLE (0)
#define MAX_HORIZONTAL_ANGLE (180)

#define SCREEN_WIDTH (3.5)

void	validate_camera(t_scene *scene, char **value,
			t_param_count *count, bool *result)
{
	t_camera	camera;
	size_t		size;

	size = get_string_array_size(value);
	if (size != 3)
		return (error_message(ERROR_NOT_CORRECT_SIZE, result));
	count->camera++;
	camera = new_camera(convert_value_to_vector_in_range(value[0],
				INT_MIN, INT_MAX, result),
			convert_value_to_normal_vector(value[1], result),
			convert_string_to_unint8_in_range(value[2],
				MIN_HORIZONTAL_ANGLE,
				MAX_HORIZONTAL_ANGLE, result));
	scene->camera = camera;
}
