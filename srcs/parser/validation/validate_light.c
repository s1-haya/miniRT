/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:39:23 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/06 16:58:20 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

#define MIN_LIGHT (0.0)
#define MAX_LIGHT (1.0)

static void	add_light_to_scene(t_scene *scene, t_light *new_light)
{
	t_light	*current;

	if (scene == NULL || new_light == NULL)
		return ;
	if (scene->light == NULL)
		scene->light = new_light;
	else
	{
		current = scene->light;
		while (current->next != NULL)
			current = current->next;
		current->next = new_light;
	}
}

void	validate_light(t_scene *scene, char **value,
				t_param_count *count, bool *result)
{
	size_t	size;
	t_light	*light;

	size = get_string_array_size(value);
	if (size != 3)
		return (error_message(ERROR_NOT_CORRECT_SIZE, result));
	count->light ++;
	light = new_light(convert_value_to_vector_in_range(value[0], INT_MIN,
				INT_MAX, result),
			convert_string_to_double_in_range(value[1], MIN_LIGHT,
				MAX_LIGHT, result),
			convert_value_to_rgb(value[2], result));
	if (*result && light == NULL)
		error_message(ERROR_NOT_MEMORY_ALLOCATED, result);
	add_light_to_scene(scene, light);
}
