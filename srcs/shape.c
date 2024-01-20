/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:23:42 by hsawamur          #+#    #+#             */
/*   Updated: 2024/01/19 16:30:06 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shape.h"

// t_shape		*new_shape();
// t_sphere	new_sphere();
// t_plane		*new_plane();
t_material	*new_material(t_color ambient, t_color diffuse, t_color specular, double shininess)
{
	t_material	*material;

	material = malloc(sizeof(t_material));
	if (material == NULL)
		return (NULL);
	material->ambient = ambient;
	material->diffuse = diffuse;
	material->specular = specular;
	material->shininess = shininess;
	return (material);
}

t_plane	*new_plane(t_vector normal, t_vector point)
{
	t_plane	*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (plane == NULL)
		return (NULL);
	plane->normal = normal;
	plane->point = point;
	return (plane);
}

t_sphere	*new_sphere(t_vector origin, double radius)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (sphere == NULL)
		return (NULL);
	sphere->origin = origin;
	sphere->radius = radius;
	return (sphere);
}

t_shape	*new_shape(void *shape, t_material *material, enum e_object object, int id)
{
	t_shape	*new_shape;
	
	new_shape = (t_shape *)malloc(sizeof(t_shape));
	if (new_shape == NULL)
		return (NULL);
	new_shape->id = id;
	new_shape->object = object;
	if (object == PLANE)
		new_shape->plane = shape;
	else if (object == SPHERE)
		new_shape->sphere = shape;
	else if (object == SYLINDER)
		new_shape->sphere = shape;
	new_shape->intersection = NULL;
	new_shape->material = material;
	return (new_shape);
}

// t_shape		*new_shape()
// {
// 	return (shape);
// }
