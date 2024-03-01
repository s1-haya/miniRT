/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:39:11 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/29 16:53:43 by hsawamur         ###   ########.fr       */
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
							convert_value_to_vector_in_range(value[1], MIN_DIRECTION, MAX_DIRECTION, result),
							convert_string_to_double_in_range(value[2], INT_MIN, INT_MAX, result),
							convert_string_to_double_in_range(value[3], INT_MIN, INT_MAX, result),
							convert_value_to_rgb(value[4], result));
	if (*result == false)
		return ;
	ft_lstadd_back(&scene->shape, ft_lstnew(new_shape(cylinder, CYLINDER)));
}

