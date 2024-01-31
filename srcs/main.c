/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:52:18 by hsawamur          #+#    #+#             */
/*   Updated: 2024/01/27 13:41:56 by hsawamur         ###   ########.fr       */
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
#define WINDOW_ORIGIN_X 0
#define WINDOW_ORIGIN_Y 0
#define MLX_TITLE "MINIRT"


t_shape	*determine_intersection_ray_and_object(t_shape **shape, t_ray ray, double light_source_distance, bool exit);
void cast_a_shadow(t_shape **shape, t_shape *nearest_shape, int x, int y, t_data *img_data);

void my_mlx_pixel_put(t_data *img_data, int x, int y, int color)
{
	char *target_pixel;
	int cie;

	cie = (y * img_data->size_line + x * (img_data->bits_per_pixel / 8));
	target_pixel = img_data->address + cie;
	*(unsigned int *)target_pixel = color;
}

double get_value_in_range(double v, double v_min, double v_max)
{
	if (v < v_min)
		return (v_min);
	else if (v_max < v)
		return (v_max);
	return (v);
}

// 　スクリーン（二次元）座標から三次元座標に変換
double convert_to_three_dimensional_coordinates(double value, double t_min, double t_max)
{
	return (t_min + (t_max - t_min) * value);
}

#include <stdio.h>
void draw_determine_intersection_of_ray_and_object(t_data *img_data)
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

// void draw_gradient(t_data *img_data) {
//     int x, y;
//     x = 0;
//     while (x < WINDOW_MAX_X) {
//         y = 0;
//         while (y < WINDOW_MAX_Y) {
//             // y 座標を0.0から1.0に正規化してグラデーションを作成
//             double fy = (double)y / (double)(WINDOW_MAX_Y - 1); // y 座標を0.0から1.0に正規化
//             int gray = (int)(255 * fy); // グレースケールの色を作成
//             int color = (gray << 16) | (gray << 8) | gray; // RGBを組み合わせて24ビットの色を作成
//             my_mlx_pixel_put(img_data, x, y, color); // ピクセルに色を設定
//             y++;
//         }
//         x++;
//     }
// }

int main(void)
{
	void *mlx;
	void *mlx_window;
	t_data mlx_image_data;

	mlx = mlx_init();
	if (mlx == NULL)
		return (FAILURE);
	mlx_window = mlx_new_window(mlx, WINDOW_MAX_X, WINDOW_MAX_Y, MLX_TITLE);
	if (mlx_window == NULL)
		return (FAILURE);
	mlx_image_data.img = mlx_new_image(mlx, WINDOW_MAX_X, WINDOW_MAX_Y);
	if (mlx_image_data.img == NULL)
		return (FAILURE);
	mlx_image_data.address = mlx_get_data_addr(mlx_image_data.img, &mlx_image_data.bits_per_pixel, &mlx_image_data.size_line,
											   &mlx_image_data.endian);
	// my_mlx_pixel_put(&mlx_image_data, 5, 5, 0x00FF0000);
	draw_determine_intersection_of_ray_and_object(&mlx_image_data);
	// draw_gradient(&mlx_image_data);
	mlx_put_image_to_window(mlx, mlx_window, mlx_image_data.img, WINDOW_ORIGIN_X, WINDOW_ORIGIN_Y);
	mlx_loop(mlx);
	return (SUCCESS);
}
