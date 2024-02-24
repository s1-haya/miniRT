/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:42:30 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/24 17:49:55 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "vector.h"
# include "ray.h"
# include "material.h"

typedef enum e_object
{
	PLANE,
	SPHERE, 
	CYLINDER
}	t_object;

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

#include <stdbool.h>

typedef struct s_cylinder
{
	t_vector	origin;
	double		radius;
	double		height;
	bool		from_bottom;
}	t_cylinder;

typedef struct s_shape
{
	enum e_object	object;
	t_plane			*plane;
	t_sphere		*sphere;
	t_cylinder		*cylinder;
	t_intersection	*intersection;
	t_material		*material;
}	t_shape;

// t_shape shape[sphere, plane, sphere, shpere]
// t_shape		*new_shape();
// t_sphere	new_sphere();
// t_plane		*new_plane();
t_shape	*new_shape(void *shape, t_material *material, enum e_object object, int id);
t_sphere	*new_sphere(t_vector origin, double radius);
t_cylinder	*new_cylinder(t_vector origin, double radius, double height);
t_plane	*new_plane(t_vector normal, t_vector point);
t_ray	new_ray(t_vector point, t_vector direction);
t_intersection	*new_intersection(t_ray ray, double t);
t_material	*new_material(t_color ambient, t_color diffuse, t_color specular, double shininess);
#endif
