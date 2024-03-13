/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:39:11 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/13 11:34:43 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"
#include "minirt.h"

#define ERROR_INVALID_CYLINDER_VALUE "Error:\nInvalid cylinder value.\n"
#define MIN (1)

void	validate_cylinder(t_scene *scene, char **value, \
							bool *result, t_param_count *count)
{
	t_cylinder	*cylinder;
	size_t		size;

	size = get_string_array_size(value);
	if (size != 5)
		return (error_message(ERROR_NOT_CORRECT_SIZE, result));
	cylinder = new_cylinder(convert_value_to_vector_in_range(value[0],
				INT_MIN, INT_MAX, result),
			convert_value_to_normal_vector(value[1], result),
			convert_string_to_double_in_range(value[2],
				MIN, INT_MAX, result) / 2,
			convert_string_to_double_in_range(value[3],
				MIN, INT_MAX, result));
	cylinder->rgb = convert_value_to_rgb(value[4], result);
	if (*result && cylinder == NULL)
		error_message(ERROR_NOT_MEMORY_ALLOCATED, result);
	if (*result == false)
	{
		free(cylinder);
		return ;
	}
	ft_lstadd_back(&scene->shape, ft_lstnew(new_shape(cylinder, CYLINDER)));
	count->objs += 1;
}
