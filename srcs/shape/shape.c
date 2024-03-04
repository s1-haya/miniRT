/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:23:42 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/04 14:37:33 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shape.h"

// t_shape		*new_shape();
// t_sphere	new_sphere();
// t_plane		*new_plane();
// t_material	*new_material(t_color ambient, t_color diffuse, t_color specular)
// {
// 	t_material	*material;

// 	material = malloc(sizeof(t_material));
// 	if (material == NULL)
// 		return (NULL);
// 	material->ambient = ambient;
// 	material->diffuse = diffuse;
// 	material->specular = specular;
// 	return (material);
// }

t_plane	*new_plane(t_vector point, t_vector normal, t_rgb rgb)
{
	t_plane	*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (plane == NULL)
		return (NULL);
	plane->point = point;
	plane->normal = normal;
	plane->rgb = rgb;
	return (plane);
}

t_sphere	*new_sphere(t_vector origin, double radius, t_rgb rgb)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (sphere == NULL)
		return (NULL);
	sphere->origin = origin;
	sphere->radius = radius;
	sphere->rgb = rgb;
	return (sphere);
}

t_cylinder	*new_cylinder(t_vector origin, t_vector axis, double radius, double height, t_rgb rgb)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (cylinder == NULL)
		return (NULL);
	cylinder->origin = subtract_vectors(origin, scalar_multiply(axis, height / 2));
	cylinder->axis = axis;
	cylinder->radius = radius;
	cylinder->height = height;
	cylinder->rgb = rgb;
	return (cylinder);
}

t_shape	*new_shape(void *shape, enum e_object object)
{
	t_shape	*new_shape;
	
	new_shape = (t_shape *)malloc(sizeof(t_shape));
	if (new_shape == NULL)
		return (NULL);
	new_shape->object = object;
	new_shape->substance = shape;
	new_shape->intersection.is_success = false;
	return (new_shape);
}

// t_shape		*new_shape()
// {
// 	return (shape);
// }
