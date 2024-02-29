/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:34:21 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/29 09:28:02 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <stdio.h>
#include "vector.h"
#include "light.h"

#define MLX_TITLE "MINIRT"
#define WINDOW_ORIGIN_X 0
#define WINDOW_ORIGIN_Y 0
#define WINDOW_MAX_X 512
#define WINDOW_MAX_Y 512
#define VIEWPOINT new_vector(0, 7, -6)
#define LOOKATPOINT new_vector(0, -1, 1)
// #define LOOKATPOINT new_vector(5, 0, -25)
#define SIZE 5
#define LIGHT_SIZE 3

// #define CYLINDER_AXIS new_vector(0, 1, 0) //fileから読み込む

// 環境光反射係数
#define AMBIENT_LIGNT_REFLECTION_COEFFICIENT new_color(0.01,0.01,0.01)
// 拡散反射係数
// diffuse reflection coefficient
#define DIFFUSE_REFLECTION_COEFFICIENT 0.69
// 鏡面反射係数
// specular reflection coefficient
#define SPECULAR_REFLECTION_COEFFICIENT new_color(0.30,0.30,0.30)
// 光沢度
// Gloss factor
#define GLOSS_FACTOR 8
// 環境光の強度
// ambient light intensity
#define AMBIENT_LIGHT_INTENSITY 0.1
// 光源の光の強度
// light intensity of light source
#define  LIGHT_INTENSITY_OF_LIGHT_SOURCE 1.0

typedef struct s_range
{
	int	value;
	int	min;
	int	max;
}	t_range;

typedef struct s_three_d_map
{
	t_range	x;
	t_range	y;
	t_range	z;
}	t_three_d_map;

typedef	struct s_img
{
	void		*data;
	char		*address;
	int			bits_per_pixel;
	int 		size_line;
	int			endian;
}	t_img;

typedef struct s_mlx_data
{
	void			*data;
	void			*window;
	void			*mlx;
	t_img			img;
} t_mlx_data;

#endif