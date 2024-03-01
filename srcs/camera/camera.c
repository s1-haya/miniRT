/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 07:58:00 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/29 11:42:53 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "minirt.h"
// #include <math.h>
// #include <stdlib.h>
// #include "minirt.h"

// #ifndef M_PI
// # define M_PI (3.14159265358979323846264338327950288)
// #endif
// FOV =2⋅atan(WIDTH_MAX/2*vector_length(ray.direction))
// double	get_degrees_to_radians(size_t fov)
// {
// 	return (fov * (M_PI / 180));
// }

// double	get_fov(t_vector )
// {
// 	return (2 * atan(WINDOW_MAX_X / 2 * vector_length()))
// }

#include <math.h>

// distanceとhorizontal_viewing_angleは関数で求める（現在は0）
t_camera	new_camera(t_vector view_point, t_vector look_at_point, double horizontal_value)
{
	t_camera	camera;

	camera.view_point = view_point;
	camera.look_at_point = look_at_point;
	normalize_vector(&camera.look_at_point); //引数の段階でチェックする
	horizontal_value *= M_PI / 180.0;
	camera.distance = (3.5 / 2.0) / tan(horizontal_value / 2.0); // 3.5はスクリーンの幅(defineする)
	camera.horizontal_viewing_angle = horizontal_value;
	return (camera);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("radians: 180 -> %f\n", get_degrees_to_radians(180));
// 	return (0);
// }
