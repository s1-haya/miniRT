/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:32:00 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/05 18:29:15 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_scene.h"
#include "utils.h"
#include "color.h"

t_rgb	get_rgb_in_shape(t_shape *shape);
void	my_mlx_pixel_put(t_img *img_data, int x, int y, int color);

void	draw_shadow_shading(t_scene *scene, \
					t_shape *nearest_shape, t_color *color, t_light *light)
{
	t_vector	incident_vector;
	t_ray		shadow_ray;

	incident_vector = subtract_vectors(light->point, \
				nearest_shape->intersection.point);
	light->distance = vector_length(incident_vector);
	normalize_vector(&incident_vector);
	shadow_ray = new_ray(add_vectors(nearest_shape->intersection.point, \
				scalar_multiply(incident_vector, C_EPSILON)), incident_vector);
	if (determine_intersection_ray_and_object(scene->shape, shadow_ray, \
							(*light).distance - C_EPSILON) != NULL)
		return ;
	add_diffuse_reflection(color, nearest_shape, incident_vector, *light);
	add_specular_reflection(color, scene, nearest_shape, *light);
	return ;
}

void	shading(t_scene *scene, t_shape *nearest_shape, int x, int y)
{
	t_color		color;
	t_light		*light;
	int			int_color;

	color = new_color(0, 0, 0);
	light = scene->light;
	if (nearest_shape != NULL)
	{
		add_ambient_light(&color, scene->ambient, nearest_shape);
		while (light != NULL)
		{
			draw_shadow_shading(scene, nearest_shape, &color, light);
			light = light->next;
		}
		get_radiance_to_color(&color, 0.0, 1.0);
		int_color = ((int)color.red << 16) | \
					((int)color.green << 8) | (int)color.blue;
		my_mlx_pixel_put(&scene->mlx.img, x, y, int_color);
	}
	else
		my_mlx_pixel_put(&scene->mlx.img, x, y, 0x0000000);
}
