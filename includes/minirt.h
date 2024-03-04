/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:34:21 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/04 16:58:57 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <stdio.h>
#include "vector.h"
#include "light.h"

double	max(double n1, double n2);

# define MLX_TITLE "MINIRT"
# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 1000
# define IMG_ORIGIN_X 0
# define IMG_ORIGIN_Y 0
# define IMG_MAX_X max(WINDOW_HEIGHT, WINDOW_WIDTH)
# define IMG_MAX_Y max(WINDOW_HEIGHT, WINDOW_WIDTH)

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
#define GLOSS_FACTOR 50
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

typedef struct s_img
{
	void	*data;
	char	*address;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_mlx_data
{
	void	*data;
	void	*window;
	void	*mlx;
	t_img	img;
}	t_mlx_data;

#endif