/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:52:18 by hsawamur          #+#    #+#             */
/*   Updated: 2024/01/11 10:09:33 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdbool.h>
#include "minirt.h"

#define SUCCESS 0
#define FAILURE 1
#define WINDOW_ORIGIN_X 0
#define WINDOW_ORIGIN_Y 0
#define WINDOW_MAX_X 512
#define WINDOW_MAX_Y 512
#define MLX_TITLE "MINIRT"

double determine_intersection_ray_and_object(int x, int y, double lx, double ly, t_vector_data *vector, t_data *img_data);
void cast_a_shadow(double t, t_data *img_data, int x, int y);

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
	t_vector_data *vector_data;

	x = 0;
	vector_data = malloc(sizeof(t_vector_data));
	if (vector_data == NULL)
		return;
	img_data->vector = vector_data;
	while (x < WINDOW_MAX_X)
	{
		// 　スクリーン（二次元）座標から三次元座標に変換
		lx = convert_to_three_dimensional_coordinates(get_value_in_range(x, WINDOW_ORIGIN_X, WINDOW_MAX_X - 1) / WINDOW_MAX_X - WINDOW_ORIGIN_X, -1.0, 1.0);
		y = 0;
		while (y < WINDOW_MAX_Y)
		{
			ly = convert_to_three_dimensional_coordinates(get_value_in_range(y, WINDOW_ORIGIN_Y, WINDOW_MAX_Y - 1) / WINDOW_MAX_Y - WINDOW_ORIGIN_Y, 1.0, -1.0);
			// if (determine_intersection_ray_and_object(lx, ly, img_data->vector) >= 0)
			// 	my_mlx_pixel_put(img_data, x, y, 0x00FF0000);
			// else
			// 	my_mlx_pixel_put(img_data, x, y, 0x000000FF);
			// determine_intersection_ray_and_object(x, y, lx, ly, img_data->vector, img_data);
			cast_a_shadow(determine_intersection_ray_and_object(x, y, lx, ly, img_data->vector, img_data), img_data, x, y);
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
