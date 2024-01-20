/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:34:21 by hsawamur          #+#    #+#             */
/*   Updated: 2024/01/20 18:38:33 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <stdio.h>
#include "vector.h"
#include "light_source.h"

#define VIEWPOINT new_vector(0, 0, -5)
#define ORIGIN_OF_THE_SPHERE new_vector(0, 0, 5)
#define LIGHT_SOURCE new_vector(-5, 5, -5)
#define RADIUS 1.0
#define SIZE 2
#define LIGHT_SIZE 1

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


typedef struct s_data
{
	t_light_source	*light_source;
	void			*img;
	char			*address;
	int				bits_per_pixel;
	int 			size_line;
	int				endian;
} t_data;

#endif