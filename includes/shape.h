/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:42:30 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/04 14:37:38 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "vector.h"
# include "ray.h"
# include "color.h"

typedef enum e_object
{
	PLANE,
	SPHERE, 
	CYLINDER
}	t_object;

typedef struct s_plane
{
	t_vector	point;
	t_vector	normal;
	t_rgb		rgb;
}	t_plane;

typedef struct s_sphere
{
	t_vector	origin;
	double		radius;
	t_rgb		rgb;
}	t_sphere;


typedef struct s_cylinder
{
	t_vector	origin;
	t_vector	axis;
	double		radius;
	double		height;
	t_rgb		rgb;
}	t_cylinder;

typedef struct s_shape
{
	enum e_object	object;
	void			*substance;
	t_intersection	intersection;
}	t_shape;

t_shape			*new_shape(void *shape, enum e_object object);
t_sphere		*new_sphere(t_vector origin, double radius, t_rgb rgb);
t_cylinder		*new_cylinder(t_vector origin, t_vector axis, double radius, double height, t_rgb rgb);
t_plane			*new_plane(t_vector normal, t_vector point, t_rgb rgb);
t_ray			new_ray(t_vector point, t_vector direction);
t_intersection	new_intersection(t_ray ray, double t);

#endif
