/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:14:11 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/06 14:02:21 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_scene.h"

t_ray	new_ray(t_vector point, t_vector direction)
{
	t_ray	ray;

	ray.point = point;
	ray.direction = direction;
	return (ray);
}

t_intersection	new_intersection(t_ray ray, double t)
{
	t_intersection	intersection;

	intersection.is_success = false;
	if (t >= 0)
	{
		intersection.point = \
			add_vectors(ray.point, scalar_multiply(ray.direction, t));
		intersection.distance = vector_length(intersection.point);
		intersection.normal = new_vector(0, 0, 0);
		normalize_vector(&(intersection.normal));
		intersection.is_success = true;
		return (intersection);
	}
	return (intersection);
}
