/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_reflection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:27:32 by erin              #+#    #+#             */
/*   Updated: 2024/03/05 18:30:46 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_scene.h"

t_rgb	get_rgb_in_shape(t_shape *shape);

t_color	add_reflection_util(t_rgb rgb, t_light light, double i)
{
	t_color	color;

	color = new_color(0, 0, 0);
	color.red = rgb.red / 255.0 * light.intensity * light.rgb.red / 255.0 * i;
	color.green = rgb.green / 255.0 * light.intensity * \
				light.rgb.green / 255.0 * i;
	color.blue = rgb.blue / 255.0 * light.intensity * \
				light.rgb.blue / 255.0 * i;
	return (color);
}

void	add_ambient_light(t_color *color, \
					t_ambient_light ambient, t_shape *nearest_shape)
{
	t_color	ambient_right;
	t_rgb	rgb;

	rgb = get_rgb_in_shape(nearest_shape);
	ambient_right.red = rgb.red / 255.0 * \
			ambient.rgb.red / 255.0 * ambient.intensity;
	ambient_right.green = rgb.green / 255.0 * \
			ambient.rgb.green / 255.0 * ambient.intensity;
	ambient_right.blue = rgb.blue / 255.0 * \
			ambient.rgb.blue / 255.0 * ambient.intensity;
	add_color(color, ambient_right);
}

void	add_diffuse_reflection(t_color *color, \
				t_shape *nearest_shape, t_vector incident, t_light light)
{
	t_color			diffuse_reflection;
	t_rgb			rgb;
	const t_vector	normal = nearest_shape->intersection.normal;

	rgb = get_rgb_in_shape(nearest_shape);
	diffuse_reflection = add_reflection_util(rgb, light, \
					clamp(dot_product(normal, incident), 0.0, 1.0));
	add_color(color, diffuse_reflection);
}

void	add_specular_reflection(t_color *color, t_scene *scene, \
				t_shape *nearest_shape, t_light light)
{
	t_color			specular_reflection;
	t_vector		a;
	t_vector		b;
	t_vector		incident_vector;
	t_rgb			rgb;

	incident_vector = subtract_vectors(light.point, \
					nearest_shape->intersection.point);
	normalize_vector(&incident_vector);
	specular_reflection = new_color(0, 0, 0);
	if (dot_product(nearest_shape->intersection.normal, incident_vector) <= 0)
		return ;
	a = subtract_vectors(scalar_multiply(nearest_shape->intersection.normal, \
		2 * dot_product(nearest_shape->intersection.normal, incident_vector)), \
			incident_vector);
	normalize_vector(&a);
	b = get_inverse_vector(scene->camera.view_point);
	normalize_vector(&b);
	rgb = get_rgb_in_shape(nearest_shape);
	specular_reflection = add_reflection_util(rgb, light, \
					pow(dot_product(a, b), GLOSS_FACTOR));
	add_color(color, specular_reflection);
}
