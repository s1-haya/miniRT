/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:23:42 by hsawamur          #+#    #+#             */
/*   Updated: 2024/01/18 01:25:58 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shape.h"

// t_shape		*new_shape();
// t_sphere	new_sphere();
// t_plane		*new_plane();

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

t_shape	*new_shape(void *shape, enum e_object object)
{
	t_shape	*new_shape;
	
	new_shape = (t_shape *)malloc(sizeof(t_shape));
	if (new_shape == NULL)
		return (NULL);
	new_shape->object = object;
	if (object == PLANE)
		new_shape->plane = shape;
	else if (object == SPHERE)
		new_shape->sphere = shape;
	else if (object == SYLINDER)
		new_shape->sphere = shape;
	new_shape->intersection = NULL;
	return (new_shape);
}

// t_shape		*new_shape()
// {
// 	return (shape);
// }
