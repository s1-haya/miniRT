/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_a_shadow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:32:00 by hsawamur          #+#    #+#             */
/*   Updated: 2024/01/11 10:11:39 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "minirt.h"
#include "vector.h"

double get_value_in_range(double v, double v_min, double v_max);
void my_mlx_pixel_put(t_data *img_data, int x, int y, int color);

void print_vector(t_vector vector, char *name);

void cast_a_shadow(double t, t_data *img_data, int x, int y)
{
	// 交点の位置
	t_vector point_of_intersection;
	// 入射ベクトル
	t_vector incident_vector;
	// 法線ベクトル
	t_vector normal_vector;
	// 入射ベクトルと法線ベクトルの内積（0, 1制限）
	double nldot;

	if (t > 0)
	{
		scalar_multiply(&img_data->vector->line_of_sight_vector, t);
		point_of_intersection = add_vectors(img_data->vector->intersection_vector, img_data->vector->line_of_sight_vector);
		incident_vector = subtract_vectors(LIGHT_SOURCE, point_of_intersection);
		normalize_vector(&incident_vector);
		normal_vector = subtract_vectors(point_of_intersection, img_data->vector->origin_of_the_sphere);
		normalize_vector(&normal_vector);
		nldot = get_value_in_range(dot_product(normal_vector, incident_vector), 0.0, 1.0);
		printf("nldot %f\n", nldot);
		int gray = (int)(255 * nldot);
		int color = (gray << 16) | (gray << 8) | gray;
		my_mlx_pixel_put(img_data, x, y, color);
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
	// 	point_of_intersection = add_vectors(img_data->img_data->vector->intersection_vector, img_data->img_data->vector->line_of_sight_vector);
	// 	print_vector(point_of_intersection, "point_of_intersection");
	// 	incident_vector = subtract_vectors(LIGHT_SOURCE, point_of_intersection);
	// 	print_vector(incident_vector, "incident_vector");
	// 	normalize_vector(&incident_vector);
	// 	print_vector(incident_vector, "incident_vector");
	// 	normal_vector = subtract_vectors(point_of_intersection, img_data->img_data->vector->origin_of_the_sphere);
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