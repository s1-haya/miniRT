/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:42:30 by hsawamur          #+#    #+#             */
/*   Updated: 2024/01/18 01:25:45 by hsawamur         ###   ########.fr       */
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
	t_vector point;
	t_vector direction;
	t_vector viewpoint;
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

typedef struct s_shape
{
	enum e_object	object;
	t_plane			*plane;
	t_sphere		*sphere;
	t_intersection	*intersection;
}	t_shape;

// t_shape shape[sphere, plane, sphere, shpere]
// t_shape		*new_shape();
// t_sphere	new_sphere();
// t_plane		*new_plane();
t_shape		*new_shape(void *shape, enum e_object object);
t_sphere	*new_sphere(t_vector origin, double radius);
t_ray	new_ray(t_vector viewpoint, t_vector screenpoint);
t_intersection	*new_intersection(t_ray ray, double t);

#endif
