/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:39:02 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/23 17:34:02 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "color.h"
#include "vector.h"

// 視点の座標位置（x, y, z）、t_vector(double x, double y, double z)
// 各正規化方位ベクトルの範囲 [-1.0,1.0] double型
// 水平視野角の範囲 [0,180]: unsigned char型

#define MIN (-1.0)
#define MAX (1.0)
#define MIN_HORIZONTAL_ANGLE (0)
#define MAX_HORIZONTAL_ANGLE (180)

t_vector	convert_value_to_vector_in_range(const char **value,
												double min,
												double max,
												bool *result);
uint8_t	convert_string_to_unint8_in_range(const char *value,
												uint8_t min,
												uint8_t max,
												bool *result)
double convert_string_to_double_in_range(const char *string,
										 double min,
										 double max,
										 bool *result);

void	validate_camera(char **value, bool *result)
{
	size_t	size;

	size = get_string_array_size(value);
	if (size == 3 || size == 5)
	{
		convert_value_to_vector_in_range(value[0], MIN, MAX, result);
		convert_value_to_vector_in_range(value[1], MIN, MAX, result);
		convert_string_to_unint8_in_range(value[2], MIN_HORIZONTAL_ANGLE,
											MAX_HORIZONTAL_ANGLE, result);
		if (size == 5)
		{
			// 注視点t_vector(double x, double y, double z)
			// convert_value_to_vector_in_range(value[3])
			// スクリーンまでの距離（焦点距離） double型
			// convert_string_to_double_in_range(value[3])
			
		}
		return ;
	}
	*result = false;
}
