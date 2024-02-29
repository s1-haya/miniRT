/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:39:11 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/29 13:07:00 by hsawamur         ###   ########.fr       */
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
	size_t	size;

	size = get_string_array_size(value);
	if (size != 5)
	{
		*result = false;
		return ;
	}
	t_cylinder *cylinder = new_cylinder(convert_value_to_vector_in_range(value[0], INT_MIN, INT_MAX, result),
							convert_value_to_vector_in_range(value[1], MIN_DIRECTION, MAX_DIRECTION, result),
							convert_string_to_double_in_range(value[2], INT_MIN, INT_MAX, result),
							convert_string_to_double_in_range(value[3], INT_MIN, INT_MAX, result),
							convert_value_to_rgb(value[4], result));
	scene->shape = new_shape(cylinder, new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.00, 0.69, 0.00), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), CYLINDER);
	scene->shape->next = new_shape(new_cylinder(new_vector(2, 0, 20), new_vector(0, 1, 0), 1, 2, new_rgb(255, 255, 255)), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69, 0.00, 0.00), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), CYLINDER);
	scene->shape->next->next = new_shape(new_cylinder(new_vector(0, 2, 2), new_vector(1, 0, 0), 1, 5, new_rgb(255, 255, 255)), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.00, 0.00, 0.69), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), CYLINDER);
	scene->shape->next->next->next = new_shape(new_cylinder(new_vector(0, 0, 0), new_vector(0, 1, 0), 1, 2, new_rgb(255, 255, 255)), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69, 0.69, 0.00), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), CYLINDER);
	scene->shape->next->next->next->next = new_shape(new_plane(new_vector(0, 1, 0), new_vector(0, 0, 0)), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69, 0.69, 1), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), PLANE);

}

