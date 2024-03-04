/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:39:11 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/04 19:28:28 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"
#include "minirt.h"

t_rgb new_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	t_rgb rgb;

	rgb.red = red;
	rgb.green = green;
	rgb.blue = blue;
	return (rgb);
}

void	validate_cylinder(t_scene *scene, char **value, bool *result)
{
	t_cylinder	*cylinder;
	size_t		size;

	size = get_string_array_size(value);
	if (size != 5)
	{
		*result = false;
		return ;
	}
	cylinder = new_cylinder(convert_value_to_vector_in_range(value[0], INT_MIN, INT_MAX, result),
							convert_value_to_normal_vector(value[1], result),
							convert_string_to_double_in_range(value[2], INT_MIN, INT_MAX, result) / 2,
							convert_string_to_double_in_range(value[3], INT_MIN, INT_MAX, result),
							convert_value_to_rgb(value[4], result));
	if (cylinder == NULL || cylinder->radius <= 0 || cylinder->height <= 0)
		*result = false;
	if (*result == false)
	{
		free(cylinder);
		return ;
	}
	ft_lstadd_back(&scene->shape, ft_lstnew(new_shape(cylinder, CYLINDER)));
}

