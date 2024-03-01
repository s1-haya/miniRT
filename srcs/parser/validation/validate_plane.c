/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:39:33 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/01 16:03:45 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

void	check_direction_vector(t_vector vector, bool *result);

void	validate_plane(t_scene *scene, char **value, bool *result)
{
	t_plane	*plane;
	size_t	size;

	size = get_string_array_size(value);
	if (size != 3)
	{
		*result = false;
		return ;
	}
	plane = new_plane(convert_value_to_vector_in_range(value[0], INT_MIN, INT_MAX, result),
						convert_value_to_vector_in_range(value[1], MIN_DIRECTION, MAX_DIRECTION, result),
						convert_value_to_rgb(value[2], result));
	check_direction_vector(plane->normal, result);
	if (*result == false)
		return ;
	ft_lstadd_back(&scene->shape, ft_lstnew(new_shape(plane, PLANE)));
}
