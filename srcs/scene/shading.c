/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:32:00 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/23 11:49:44 by erin             ###   ########.fr       */
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
t_shape	*determine_intersection_ray_and_object(t_shape **shape, t_ray ray, double light_source_distance, bool exit);

void print_vector(t_vector vector, char *name);

t_color	get_ambient_right(t_color ambient, double intensity)
{
	t_color	ambient_right;

	ambient_right.red = ambient.red * intensity;
	ambient_right.green = ambient.green * intensity;
	ambient_right.blue = ambient.blue * intensity;
	return (ambient_right);
}

t_color	get_diffuse_reflection(t_color coefficient, t_color intensity_of_light_source, t_vector normal, t_vector incident)
{
	t_color	diffue;

	diffue.red = coefficient.red * intensity_of_light_source.red * clamp(dot_product(normal, incident), 0.0, 1.0);
	diffue.green = coefficient.green * intensity_of_light_source.green * clamp(dot_product(normal, incident), 0.0, 1.0);
	diffue.blue = coefficient.blue * intensity_of_light_source.blue * clamp(dot_product(normal, incident), 0.0, 1.0);
	return (diffue);
}

t_color get_specular_reflection(t_color coefficient, t_color intensity_of_light_source, t_vector normal, t_vector incident, t_vector viewpoint)
{
	t_color	specular;
	//入射角の正反射
	t_vector a;
	//視点ベクトルの反対
	t_vector b;

	specular.red = 0;
	specular.green = 0;
	specular.blue = 0;
	if (!(dot_product(normal, incident) > 0))
		return (specular);
	a = subtract_vectors(scalar_multiply(normal, 2 * dot_product(normal, incident)), get_inverse_vector(incident));
	// normalize_vector(&a);
	b = get_inverse_vector(viewpoint);
	normalize_vector(&b);
	specular.red = coefficient.red * intensity_of_light_source.red * pow(clamp(dot_product(a, b), 0.0, 1.0), GLOSS_FACTOR);
	specular.green = coefficient.green * intensity_of_light_source.green * pow(clamp(dot_product(a, b), 0.0, 1.0), GLOSS_FACTOR);
	specular.blue = coefficient.blue * intensity_of_light_source.blue * pow(clamp(dot_product(a, b), 0.0, 1.0), GLOSS_FACTOR);
	return (specular);
}

void	shading(t_scene *scene, t_shape *nearest_shape, int x, int y)
{
	t_vector	incident_vector;
	t_vector	normal_vector;
	t_color		diffuse_reflection;
	t_color		specular_reflection;
	t_color		color;
	t_color		ambient_right;
	size_t		i;
	t_ray		shade_ray;

	color = new_color(0, 0, 0);
	i = 0;
	if (nearest_shape != NULL)
	{
		while (i  < LIGHT_SIZE)
		{
			incident_vector = subtract_vectors(scene->light[i].light_ray.point, nearest_shape->intersection->point);
			scene->light[i].distance = vector_length(incident_vector);
			normalize_vector(&incident_vector);
			shade_ray = new_ray(add_vectors(nearest_shape->intersection->point, scalar_multiply(incident_vector, C_EPSILON)), incident_vector);
			if (determine_intersection_ray_and_object(scene->shape, shade_ray, scene->light[i].distance - C_EPSILON, true) != NULL)
			{
				i++;
				continue;
			}
			// get_radiance(shape *shape, t_intesection *intesection, t_light *light)
			if (nearest_shape->object == PLANE)
				normal_vector = nearest_shape->plane->normal;
			else if (nearest_shape->object == SPHERE)
				normal_vector = subtract_vectors(nearest_shape->intersection->point, nearest_shape->sphere->origin);
			else
			{
				//double dot_product(t_vector v1, t_vector v2)
				normal_vector = subtract_vectors(nearest_shape->intersection->point, nearest_shape->cylinder->origin);
				// normal_vector.y = 0;
				if (dot_product(nearest_shape->intersection->point, normal_vector) == 0)
					normal_vector.y = 0; 
				// normal_vector = subtract_vectors(nearest_shape->intersection->point, nearest_shape->cylinder->origin);
			}
			normalize_vector(&normal_vector);
			ambient_right = get_ambient_right(nearest_shape->material->ambient, AMBIENT_LIGHT_INTENSITY);
			add_color(&color, ambient_right);
			diffuse_reflection = get_diffuse_reflection(nearest_shape->material->diffuse, scene->light[i].intensity, new_vector(2 * ((normal_vector.x + 1) / 2) - 1, 2 * ((normal_vector.y + 1) / 2) - 1, 2 * ((normal_vector.z + 1) / 2) - 1), incident_vector);
			add_color(&color, diffuse_reflection);
			specular_reflection = get_specular_reflection(nearest_shape->material->specular, scene->light[i].intensity, normal_vector, incident_vector, scene->camera.view_point);
			add_color(&color, specular_reflection);
			i++;
		}
		get_radiance_to_color(&color, 0.0, 1.0);
		int int_color = ((int)color.red << 16) | ((int)color.green << 8) | (int)color.blue;
		my_mlx_pixel_put(&scene->mlx.img, x, y, int_color);
	}
	else
		my_mlx_pixel_put(&scene->mlx.img, x, y, 0x000000FF);
}
