/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:34:21 by hsawamur          #+#    #+#             */
/*   Updated: 2024/01/11 10:07:00 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <stdio.h>
#include "vector.h"

#define VIEWPOINT new_vector(0, 0, -5);
#define ORIGIN_OF_THE_SPHERE new_vector(0, 0, 5)
#define LIGHT_SOURCE new_vector(-5, 5, -5)
#define RADIUS 1.0

typedef enum e_object
{
	PLANE,
	SPHERE, 
	SYLINDER
}	t_object;

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
	t_vector_data	*vector;
	void			*img;
	char			*address;
	int				bits_per_pixel;
	int 			size_line;
	int				endian;
} t_data;

#endif