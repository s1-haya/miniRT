/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:39:42 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/01 17:55:28 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

void	validate_sphere(t_scene *scene, char **value, bool *result)
{
	t_sphere	*sphere;
	size_t		size;

	size = get_string_array_size(value);
	if (size != 3)
	{
		*result = false;
		return ;
	}
	sphere = new_sphere(convert_value_to_vector_in_range(value[0], INT_MIN, INT_MAX, result),
						convert_string_to_double_in_range(value[1], INT_MIN, INT_MAX, result),
						convert_value_to_rgb(value[2], result));
	if (sphere->radius <= 0)
		*result = false;
	if (*result == false)
		return ;
	ft_lstadd_back(&scene->shape, ft_lstnew(new_shape(sphere, SPHERE)));
}
