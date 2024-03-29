/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:39:42 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/13 11:35:53 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

#define ERROR_INVALID_SPHERE "Error:\nInvalid sphere value.\n"
#define MIN (1)

void	validate_sphere(t_scene *scene, char **value, \
							bool *result, t_param_count *count)
{
	t_sphere	*sphere;
	size_t		size;

	size = get_string_array_size(value);
	if (size != 3)
		return (error_message(ERROR_NOT_CORRECT_SIZE, result));
	sphere = new_sphere(convert_value_to_vector_in_range(value[0],
				INT_MIN, INT_MAX, result),
			convert_string_to_double_in_range(value[1],
				MIN, INT_MAX, result),
			convert_value_to_rgb(value[2], result));
	if (*result && sphere == NULL)
		error_message(ERROR_NOT_MEMORY_ALLOCATED, result);
	if (*result == false)
	{
		free(sphere);
		return ;
	}
	ft_lstadd_back(&scene->shape, ft_lstnew(new_shape(sphere, SPHERE)));
	count->objs += 1;
}
