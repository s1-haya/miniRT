/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:39:33 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/01 17:49:10 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

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
						convert_value_to_normal_vector(value[1], result),
						convert_value_to_rgb(value[2], result));
	ft_lstadd_back(&scene->shape, ft_lstnew(new_shape(plane, PLANE)));
	if (*result == false)
		return ;
}
