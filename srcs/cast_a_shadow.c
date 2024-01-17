/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_a_shadow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:32:00 by hsawamur          #+#    #+#             */
/*   Updated: 2024/01/18 00:54:37 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "minirt.h"
#include "shape.h"
#include "vector.h"
#include "color.h"

double get_value_in_range(double v, double v_min, double v_max);
void my_mlx_pixel_put(t_data *img_data, int x, int y, int color);

void print_vector(t_vector vector, char *name);

double	get_ambient_right(double reflection_coefficient, double intensity)
{
	return (reflection_coefficient * intensity);
}

double	get_diffuse_reflection(double coefficient, double intensity_of_light_source, t_vector normal, t_vector incident)
{
	return (coefficient * intensity_of_light_source * get_value_in_range(dot_product(normal, incident), 0.0, 1.0));
}

double get_specular_reflection(t_vector normal, t_vector incident, t_vector viewpoint)
{
	//入射角の正反射
	t_vector a;
	//視点ベクトルの反対
	t_vector b;

	if (!(dot_product(normal, incident) > 0))
		return (0);
	a = subtract_vectors(scalar_multiply(normal, 2 * dot_product(normal, incident)), get_inverse_vector(incident));
	// normalize_vector(&a);
	b = get_inverse_vector(viewpoint);
	normalize_vector(&b);
	return (SPECULAR_REFLECTION_COEFFICIENT * LIGHT_INTENSITY_OF_LIGHT_SOURCE * pow(get_value_in_range(dot_product(a, b), 0.0, 1.0), GLOSS_FACTOR));
}

void cast_a_shadow(double t, t_shape *shape, int x, int y, t_data *img_data)
{
	// 入射ベクトル
	t_vector	incident_vector;
	// 法線ベクトル
	t_vector	normal_vector;
	// 入射ベクトルと法線ベクトルの内積（0, 1制限）
	t_color		diffuse_reflection;
	t_color		specular_reflection;
	t_color		color;
	t_color		ambient_right;

	color = new_color(0, 0, 0);
	if (t > 0)
	{
		incident_vector = subtract_vectors(LIGHT_SOURCE, shape->intersection->point);
		normalize_vector(&incident_vector);
		normal_vector = subtract_vectors(shape->intersection->point, shape->sphere->origin);
		normalize_vector(&normal_vector);
		ambient_right = new_color(get_ambient_right(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, AMBIENT_LIGHT_INTENSITY), get_ambient_right(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, AMBIENT_LIGHT_INTENSITY), get_ambient_right(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, AMBIENT_LIGHT_INTENSITY));
		add_color(&color, ambient_right);
		diffuse_reflection = new_color(get_diffuse_reflection(DIFFUSE_REFLECTION_COEFFICIENT, LIGHT_INTENSITY_OF_LIGHT_SOURCE, normal_vector, incident_vector), get_diffuse_reflection(0.0, LIGHT_INTENSITY_OF_LIGHT_SOURCE, normal_vector, incident_vector), get_diffuse_reflection(0.0, LIGHT_INTENSITY_OF_LIGHT_SOURCE, normal_vector, incident_vector));
		add_color(&color, diffuse_reflection);
		specular_reflection = new_color(get_specular_reflection(normal_vector, incident_vector, VIEWPOINT), get_specular_reflection(normal_vector, incident_vector, VIEWPOINT), get_specular_reflection(normal_vector, incident_vector, VIEWPOINT));
		add_color(&color, specular_reflection);
		get_radiance_to_color(&color, 0.0, 1.0);
		color.color = ((int)color.red << 16) | ((int)color.green << 8) | (int)color.blue;
		my_mlx_pixel_put(img_data, x, y, color.color);
	}
	else
		my_mlx_pixel_put(img_data, x, y, 0x000000FF);

	// if (t > 0)
	// {
	// 	printf("t: %f\n", t);
	// 	// printf("t: %.2f\n", t);
	// 	print_vector(img_data->img_data->vector->line_of_sight_vector, "line_of_sight_vector");
	// 	scalar_multiply(&img_data->img_data->vector->line_of_sight_vector, t);
	// 	print_vector(img_data->img_data->vector->line_of_sight_vector, "line_of_sight_vector");
	// 	shape->intersection->point = add_vectors(img_data->img_data->vector->intersection_vector, img_data->img_data->vector->line_of_sight_vector);
	// 	print_vector(shape->intersection->point, "shape->intersection->point");
	// 	incident_vector = subtract_vectors(LIGHT_SOURCE, shape->intersection->point);
	// 	print_vector(incident_vector, "incident_vector");
	// 	normalize_vector(&incident_vector);
	// 	print_vector(incident_vector, "incident_vector");
	// 	normal_vector = subtract_vectors(shape->intersection->point, img_data->img_data->vector->origin_of_the_sphere);
	// 	print_vector(normal_vector, "normal_vector");
	// 	normalize_vector(&normal_vector);
	// 	print_vector(normal_vector, "normal_vector");
	// 	// if ((int)vector_length(incident_vector) == (int)vector_length(normal_vector))
	// 	// {
	// 	// 	printf("incident_length: %f\n", vector_length(incident_vector));
	// 	// 	printf("normal_length:   %f\n", vector_length(normal_vector));
	// 	// 	exit(0);
	// 	// }
	// 	if (0 < dot_product(normal_vector, incident_vector))
	// 	{
	// 		nldot = dot_product(normal_vector, incident_vector);
	// 		printf("nldot %f\n", nldot);
	// 	}
	// 	nldot = get_value_in_range(dot_product(normal_vector, incident_vector), 0.0, 1.0);
	// 	// printf("nldot %f\n", nldot);
	// 	int gray = (int)(255 * nldot);				   // グレースケールの色を作成
	// 	int color = (gray << 16) | (gray << 8) | gray; // RGBを組み合わせて24ビットの色を作成
	// 	my_mlx_pixel_put(img_data, x, y, color);
	// }
	// else
	// 	my_mlx_pixel_put(img_data, x, y, 0x000000FF);
}