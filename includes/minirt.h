/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:34:21 by hsawamur          #+#    #+#             */
/*   Updated: 2024/01/08 15:44:21 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <stdio.h>

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
	void *img;
	char *address;
	int bits_per_pixel;
	int size_line;
	int endian;
} t_data;

#endif