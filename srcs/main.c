/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:52:18 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/01 18:14:56 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "minirt.h"
#include "shape.h"
#include "color.h"

#define SUCCESS 0
#define FAILURE 1

t_shape	*determine_intersection_ray_and_object(t_shape **shape, t_ray ray, double light_source_distance, bool exit);
void cast_a_shadow(t_shape **shape, t_shape *nearest_shape, int x, int y, t_mlx_data *img_data);
t_mlx_data	*new_mlx_data();
double get_value_in_range(double v, double v_min, double v_max);

// 　スクリーン（二次元）座標から三次元座標に変換
double convert_to_three_dimensional_coordinates(double value, double t_min, double t_max)
{
	return (t_min + (t_max - t_min) * value);
}

#include <stdio.h>
void draw_determine_intersection_of_ray_and_object(t_mlx_data *img_data)
{
	int x;
	int y;
	double lx;
	double ly;
	t_ray			ray;
	t_shape			*nearest_shape;
	t_shape			**shape;
	t_light_source	*light_source;

	x = 0;
	shape = (t_shape **)malloc(sizeof(t_shape *) * SIZE);
	if (shape == NULL)
		return;
	// shape[0] = new_shape(new_sphere(new_vector(3, 0, 25), 3), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.00,0.69,0.00), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), SPHERE, 0);
	// shape[1] = new_shape(new_sphere(new_vector(2, 0, 20), 1), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69,0.00,0.00), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), SPHERE, 1);
	// shape[2] = new_shape(new_sphere(new_vector(1, 0, 15), 1), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.00,0.00,0.69), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), SPHERE, 2);
	// shape[3] = new_shape(new_sphere(new_vector(0, 0, 10), 1), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.00,0.69,0.69), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), SPHERE, 3);
	// shape[4] = new_shape(new_sphere(new_vector(-1, 0, 5), 1), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69,0.69,0.00), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), SPHERE, 4);
	// shape[5] = new_shape(new_plane(new_vector(0, 1, 0), new_vector(0, -1, 0)),new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69,0.69,1), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), PLANE, 5);
	
	shape[0] = new_shape(new_cylinder(new_vector(3, 0, 25), 1, 2), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.00,0.69,0.00), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), CYLINDER, 0);
	shape[1] = new_shape(new_cylinder(new_vector(2, 0, 20), 1, 2), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69,0.00,0.00), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), CYLINDER, 1);
	shape[2] = new_shape(new_cylinder(new_vector(1, 0, 15), 1, 2), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.00,0.00,0.69), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), CYLINDER, 2);
	shape[3] = new_shape(new_cylinder(new_vector(0, 0, 10), 1, 2), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.00,0.69,0.69), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), CYLINDER, 3);
	shape[4] = new_shape(new_cylinder(new_vector(-1, 0, 5), 1, 2), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69,0.69,0.00), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), CYLINDER, 4);
	// shape[5] = new_shape(new_plane(new_vector(0, 1, 0), new_vector(0, -1, 0)),new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69,0.69,1), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), PLANE, 5);

	// shape[0] = new_shape(new_cylinder(new_vector(0, 0, 5), 1, 2), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69,0.00,0.69), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), CYLINDER, 2);
	// shape[1] = new_shape(new_plane(new_vector(0, 1, 0), new_vector(0, -1, 0)),new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69,0.69,1), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), PLANE, 5);
	light_source = (t_light_source *)malloc(sizeof(t_light_source) * LIGHT_SIZE);
	light_source[0] = new_light_source(new_vector(5, 1, -5), new_color(1,1,1));
	light_source[1] = new_light_source(new_vector(5, 0, -5), new_color(0.5,0.5,0.5));
	light_source[2] = new_light_source(new_vector(5, 20, -5), new_color(0.5,0.5,0.5));
	img_data->light_source = light_source;
	while (x < WINDOW_MAX_X)
	{
		// 　スクリーン（二次元）座標から三次元座標に変換
		lx = convert_to_three_dimensional_coordinates(get_value_in_range(x, WINDOW_ORIGIN_X, WINDOW_MAX_X - 1) / WINDOW_MAX_X - WINDOW_ORIGIN_X, -1.0, 1.0);
		y = 0;
		while (y < WINDOW_MAX_Y)
		{
			ly = convert_to_three_dimensional_coordinates(get_value_in_range(y, WINDOW_ORIGIN_Y, WINDOW_MAX_Y - 1) / WINDOW_MAX_Y - WINDOW_ORIGIN_Y, 1.0, -1.0);
			t_vector a = add_vectors(VIEWPOINT, scalar_multiply(subtract_vectors(LOOKATPOINT, VIEWPOINT), DISTANCE));
			t_vector b = add_vectors(VIEWPOINT, add_vectors(scalar_multiply(new_vector(1, 0, 0), lx), scalar_multiply(new_vector(0, 1, 0), ly)));
			t_vector z = add_vectors(a, b);
			ray = new_ray(VIEWPOINT, subtract_vectors(z, VIEWPOINT));
			nearest_shape = determine_intersection_ray_and_object(shape, ray, LONG_MAX, false);
			cast_a_shadow(shape, nearest_shape, x, y, img_data);
			y++;
		}
		x++;
	}
}

#include <libc.h>
int main(void)
{
	t_mlx_data	*data;

	data = new_mlx_data();
	if (data == NULL)
		return (FAILURE);
	draw_determine_intersection_of_ray_and_object(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img, WINDOW_ORIGIN_X, WINDOW_ORIGIN_Y);
	mlx_loop(data->mlx);
	system("leaks -q miniRT");
	return (SUCCESS);
}
