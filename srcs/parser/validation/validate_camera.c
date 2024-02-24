/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:39:02 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/24 11:14:22 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

#define MIN_HORIZONTAL_ANGLE (0)
#define MAX_HORIZONTAL_ANGLE (180)

void	validate_camera(char **value, bool *result)
{
	size_t	size;

	size = get_string_array_size(value);
	if (size != 3 && size != 5)
	{
		*result = false;
		return ;
	}
	convert_value_to_vector_in_range(value[0], INT_MIN,
										INT_MAX, result);
	convert_value_to_vector_in_range(value[1], MIN_DIRECTION,
										MAX_DIRECTION, result);
	convert_string_to_unint8_in_range(value[2], MIN_HORIZONTAL_ANGLE,
										MAX_HORIZONTAL_ANGLE, result);
	if (size == 5)
	{
		// 注視点t_vector(double x, double y, double z)
		// convert_value_to_vector_in_range(value[3])
		// スクリーンまでの距離（焦点距離） double型
		// convert_string_to_double_in_range(value[3])
		
	}
}
