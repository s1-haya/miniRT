/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:14:11 by hsawamur          #+#    #+#             */
/*   Updated: 2024/01/18 01:20:19 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include <stdlib.h>

t_ray	new_ray(t_vector viewpoint, t_vector screenpoint)
{
	t_ray	ray;

	ray.point = viewpoint;
	ray.direction = subtract_vectors(screenpoint, viewpoint);
	ray.viewpoint = viewpoint;
	return (ray);
}

t_intersection	*new_intersection(t_ray ray, double t)
{
	t_intersection	*intersection;

	intersection = malloc(sizeof(t_intersection));
	if (intersection == NULL)
		return (NULL);
	if (t > 0)
	{
		intersection->point = add_vectors(ray.point, scalar_multiply(ray.direction, t));
		intersection->distance = vector_length(intersection->point);
		intersection->normal = add_vectors(ray.point, scalar_multiply(ray.direction, t));
		normalize_vector(&(intersection->normal));
	}
	return (intersection);
}

