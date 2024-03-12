/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:39:33 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/12 13:27:42 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

void	validate_plane(t_scene *scene, char **value, \
							bool *result, t_param_count *count)
{
	t_plane	*plane;
	size_t	size;

	size = get_string_array_size(value);
	if (size != 3)
	{
		error_message(ERROR_NOT_CORRECT_SIZE, result);
		return ;
	}
	plane = new_plane(convert_value_to_vector_in_range(value[0],
				INT_MIN, INT_MAX, result),
			convert_value_to_normal_vector(value[1], result),
			convert_value_to_rgb(value[2], result));
	if (*result && plane == NULL)
		error_message(ERROR_NOT_MEMORY_ALLOCATED, result);
	if (*result == false)
	{
		free(plane);
		return ;
	}
	ft_lstadd_back(&scene->shape, ft_lstnew(new_shape(plane, PLANE)));
	count->objs += 1;
}
