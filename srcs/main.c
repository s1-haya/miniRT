/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:52:18 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/18 08:57:51 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "minirt.h"
#include "shape.h"
#include "color.h"
#include "scene.h"

#define SUCCESS 0
#define FAILURE 1

t_shape		*determine_intersection_ray_and_object(t_shape **shape, t_ray ray, double light_distance, bool exit);
void		cast_a_shadow(t_scene *scene, t_shape *nearest_shape, int x, int y);
t_mlx_data	new_mlx_data();
t_camera	new_camera(t_vector view_point, t_vector look_at_point, size_t horizontal_value);
t_scene	new_scene(t_shape **shape,
				t_light *light, 
				t_camera camera,
				t_mlx_data data);
double get_value_in_range(double v, double v_min, double v_max);

// 　スクリーン（二次元）座標から三次元座標に変換
double convert_to_three_dimensional_coordinates(double value, double t_min, double t_max)
{
	return (t_min + (t_max - t_min) * value);
}

#include <stdio.h>
void render_scene(t_scene *scene)
{
	int x;
	int y;
	double lx;
	double ly;
	t_ray			ray;
	t_shape			*nearest_shape;

	x = 0;
	while (x < WINDOW_MAX_X)
	{
		// 　スクリーン（二次元）座標から三次元座標に変換
		lx = convert_to_three_dimensional_coordinates(get_value_in_range(x, WINDOW_ORIGIN_X, WINDOW_MAX_X - 1) / WINDOW_MAX_X - WINDOW_ORIGIN_X, -1.0, 1.0);
		y = 0;
		while (y < WINDOW_MAX_Y)
		{
			ly = convert_to_three_dimensional_coordinates(get_value_in_range(y, WINDOW_ORIGIN_Y, WINDOW_MAX_Y - 1) / WINDOW_MAX_Y - WINDOW_ORIGIN_Y, 1.0, -1.0);
			// t_vector a = add_vectors(VIEWPOINT, scalar_multiply(subtract_vectors(LOOKATPOINT, VIEWPOINT), DISTANCE));
			// t_vector b = add_vectors(VIEWPOINT, add_vectors(scalar_multiply(new_vector(1, 0, 0), lx), scalar_multiply(new_vector(0, 1, 0), ly)));
			// t_vector z = add_vectors(a, b);
			ray = new_ray(scene->camera.view_point, subtract_vectors(new_vector(lx, ly, 0), scene->camera.view_point));
			nearest_shape = determine_intersection_ray_and_object(scene->shape, ray, LONG_MAX, false);
			cast_a_shadow(scene, nearest_shape, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(scene->mlx.data, scene->mlx.window, scene->mlx.img.data, WINDOW_ORIGIN_X, WINDOW_ORIGIN_Y);
	mlx_loop(scene->mlx.data);
}

#include <libc.h>
int main(void)
{
	t_shape			**shape;
	t_light			*light;
	t_scene		scene;
	// 1 is_valid
	// 2 init(parse)
	// 3 draw
	// 4 hook, loop
	shape = (t_shape **)malloc(sizeof(t_shape *) * SIZE);
	if (shape == NULL)
		return (FAILURE);
	// shape[0] = new_shape(new_sphere(new_vector(3, 0, 25), 3), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.00,0.69,0.00), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), SPHERE, 0);
	// shape[1] = new_shape(new_sphere(new_vector(2, 0, 20), 1), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69,0.00,0.00), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), SPHERE, 1);
	// shape[2] = new_shape(new_sphere(new_vector(1, 0, 15), 1), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.00,0.00,0.69), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), SPHERE, 2);
	// shape[3] = new_shape(new_sphere(new_vector(0, 0, 10), 1), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.00,0.69,0.69), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), SPHERE, 3);
	// shape[4] = new_shape(new_sphere(new_vector(-1, 0, 5), 1), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69,0.69,0.00), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), SPHERE, 4);
	// shape[5] = new_shape(new_plane(new_vector(0, 1, 0), new_vector(0, -1, 0)),new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69,0.69,1), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), PLANE, 5);
	
	shape[0] = new_shape(new_cylinder(new_vector(3, 0, 25), 1, 2), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.00,0.69,0.00), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), CYLINDER);
	shape[1] = new_shape(new_cylinder(new_vector(2, 0, 20), 1, 2), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69,0.00,0.00), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), CYLINDER);
	shape[2] = new_shape(new_cylinder(new_vector(1, 0, 15), 1, 2), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.00,0.00,0.69), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), CYLINDER);
	shape[3] = new_shape(new_cylinder(new_vector(0, 0, 10), 1, 2), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.00,0.69,0.69), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), CYLINDER);
	shape[4] = new_shape(new_cylinder(new_vector(-1, 0, 5), 1, 2), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69,0.69,0.00), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), CYLINDER);
	// shape[5] = new_shape(new_plane(new_vector(0, 1, 0), new_vector(0, -1, 0)),new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69,0.69,1), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), PLANE, 5);

	// shape[0] = new_shape(new_cylinder(new_vector(0, 0, 5), 1, 2), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69,0.00,0.69), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), CYLINDER, 2);
	// shape[1] = new_shape(new_plane(new_vector(0, 1, 0), new_vector(0, -1, 0)),new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69,0.69,1), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), PLANE, 5);
	light = (t_light *)malloc(sizeof(t_light) * LIGHT_SIZE);
	light[0] = new_light(new_vector(5, 1, -5), new_color(1,1,1));
	light[1] = new_light(new_vector(5, 0, -5), new_color(0.5,0.5,0.5));
	light[2] = new_light(new_vector(5, 20, -5), new_color(0.5,0.5,0.5));
	scene = new_scene(shape, light, new_camera(VIEWPOINT, LOOKATPOINT, 70), new_mlx_data());
	render_scene(&scene);
	return (SUCCESS);
}
