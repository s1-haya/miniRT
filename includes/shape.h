/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:42:30 by hsawamur          #+#    #+#             */
/*   Updated: 2024/01/27 15:14:21 by hsawamur         ###   ########.fr       */
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

typedef struct s_cylinder
{
	t_vector	origin;
	double		radius;
	double		height;
}	t_cylinder;

typedef struct s_shape
{
	int				id;
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