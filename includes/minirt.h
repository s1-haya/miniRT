/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:34:21 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/07 13:26:48 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include "vector.h"
# include "light.h"

double	max(double n1, double n2);

# define MLX_TITLE "MINIRT"
# define WINDOW_ORIGIN_X 0
# define WINDOW_ORIGIN_Y 0
# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 1000
# define SUCCESS 0
# define FAILURE 1

# define DIFFUSE_REFLECTION_COEFFICIENT 0.69
# define SPECULAR_REFLECTION_COEFFICIENT 0.30
# define GLOSS_FACTOR 50

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
	t_img	img;
}	t_mlx_data;

#endif