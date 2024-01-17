/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:42:30 by hsawamur          #+#    #+#             */
/*   Updated: 2024/01/17 14:51:45 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

#include "vector.h"

typedef enum e_object
{
	PLANE,
	SPHERE, 
	SYLINDER
}	t_object;

typedef struct s_ray
{
	t_vector start_point;
	t_vector direction;
}	t_ray;

typedef struct s_intersection
{
	double		distance;
	t_vector	point;
	t_vector	normal;
}	t_intersection;

typedef struct s_plane
{
	t_vector	normal;
	t_vector	point;
}	t_plane;

typedef struct s_sphere
{
	t_vector	origin;
	double		radius;
}	t_sphere;


#endif
