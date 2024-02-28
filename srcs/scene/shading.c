/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:32:00 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/25 13:13:02 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "minirt.h"
#include "scene.h"
#include "shape.h"
#include "vector.h"
#include "color.h"

#define C_EPSILON (1.0 / 512)

double clamp(double v, double v_min, double v_max);
void my_mlx_pixel_put(t_img *img_data, int x, int y, int color);
t_shape	*determine_intersection_ray_and_object(t_shape **shape, t_ray ray, double light_source_distance);

void print_vector(t_vector vector)
{
	printf("x: %lf\n", vector.x);
	printf("y: %lf\n", vector.y);
	printf("z: %lf\n", vector.z);
}

void	add_ambient_light(t_color *color, t_shape *nearest_shape)
{
	t_color				ambient_right;
	const t_color		ambient = nearest_shape->material->ambient;

	ambient_right.red = ambient.red * AMBIENT_LIGHT_INTENSITY;
	ambient_right.green = ambient.green * AMBIENT_LIGHT_INTENSITY;
	ambient_right.blue = ambient.blue * AMBIENT_LIGHT_INTENSITY;
	add_color(color, ambient_right);
}

void	add_diffuse_reflection(t_color *color, t_shape *nearest_shape, t_vector incident, t_light light)
{
	t_color			diffuse_reflection;
	const t_color	coefficient = nearest_shape->material->diffuse;
	const t_vector	normal = nearest_shape->intersection->normal;
	const t_color	intensity_of_light_source = light.intensity;

	diffuse_reflection.red = coefficient.red * intensity_of_light_source.red \
			* clamp(dot_product(normal, incident), 0.0, 1.0);
	diffuse_reflection.green = coefficient.green \
			* intensity_of_light_source.green \
			* clamp(dot_product(normal, incident), 0.0, 1.0);
	diffuse_reflection.blue = coefficient.blue * intensity_of_light_source.blue \
			* clamp(dot_product(normal, incident), 0.0, 1.0);
	add_color(color, diffuse_reflection);
}

void	add_specular_reflection(t_color *color, t_scene *scene, t_shape *nearest_shape, t_light light)
{
	t_color			specular_reflection;
	t_vector		a; //入射角の正反射
	t_vector		b; //視点ベクトルの反対
	const t_color	coefficient = nearest_shape->material->specular;
	t_vector		incident_vector;

	incident_vector = subtract_vectors(light.light_ray.point, \
					nearest_shape->intersection->point);
	normalize_vector(&incident_vector);
	specular_reflection = new_color(0, 0, 0);
	if (dot_product(nearest_shape->intersection->normal, incident_vector) <= 0)
		return ;
	a = subtract_vectors(scalar_multiply(nearest_shape->intersection->normal, \
		2 * dot_product(nearest_shape->intersection->normal, incident_vector)), \
			get_inverse_vector(incident_vector));
	b = get_inverse_vector(scene->camera.view_point);
	normalize_vector(&b);
	specular_reflection.red = coefficient.red * light.intensity.red * \
				pow(clamp(dot_product(a, b), 0.0, 1.0), GLOSS_FACTOR);
	specular_reflection.green = coefficient.green * light.intensity.green * \
				pow(clamp(dot_product(a, b), 0.0, 1.0), GLOSS_FACTOR);
	specular_reflection.blue = coefficient.blue * light.intensity.blue * \
				pow(clamp(dot_product(a, b), 0.0, 1.0), GLOSS_FACTOR);
	add_color(color, specular_reflection);
}

t_vector	get_incident_vec(t_light *light, t_shape *nearest_shape)
{
	t_vector	incident_vector;

	incident_vector = subtract_vectors(light->light_ray.point, \
				nearest_shape->intersection->point);
	light->distance = vector_length(incident_vector);
	normalize_vector(&incident_vector);
	return (incident_vector);
}

void	draw_shadow_shading(t_scene *scene, t_shape *nearest_shape, t_color *color, t_light *light)
{
	t_vector	incident_vector;
	t_ray		shadow_ray;

	incident_vector = get_incident_vec(light, nearest_shape);
	shadow_ray = new_ray(add_vectors(nearest_shape->intersection->point, scalar_multiply(incident_vector, C_EPSILON)), incident_vector);
	if (determine_intersection_ray_and_object(scene->shape, shadow_ray, (*light).distance - C_EPSILON) != NULL)
		return ;
	add_ambient_light(color, nearest_shape);
	add_diffuse_reflection(color, nearest_shape, incident_vector, *light);
	add_specular_reflection(color, scene, nearest_shape, *light);
	return ;
}

void	shading(t_scene *scene, t_shape *nearest_shape, int x, int y)
{
	t_color		color;
	size_t		i;

	color = new_color(0, 0, 0);
	i = 0;
	if (nearest_shape != NULL)
	{
		while (i < LIGHT_SIZE)
			draw_shadow_shading(scene, nearest_shape, &color, &scene->light[i++]);
		get_radiance_to_color(&color, 0.0, 1.0);
		int int_color = ((int)color.red << 16) | ((int)color.green << 8) | (int)color.blue;
		my_mlx_pixel_put(&scene->mlx.img, x, y, int_color);
	}
	else
		my_mlx_pixel_put(&scene->mlx.img, x, y, 0x000000FF);
}
