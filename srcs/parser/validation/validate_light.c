/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:39:23 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/29 13:29:14 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

#define MIN_LIGHT (0.0)
#define MAX_LIGHT (1.0)

void	validate_light(t_scene *scene, char **value,
				t_param_count *count, bool *result)
{
	size_t	size;

	size = get_string_array_size(value);
	if (size != 3)
	{
		*result = false;
		return ;
	}
	count->light ++;
	scene->light = new_light(convert_value_to_vector_in_range(value[0], INT_MIN,
										INT_MAX, result),
							convert_string_to_double_in_range(value[1], MIN_LIGHT,
										MAX_LIGHT, result),
							convert_value_to_rgb(value[2], result));
	if (scene->light == NULL)
		*result = false;
}
