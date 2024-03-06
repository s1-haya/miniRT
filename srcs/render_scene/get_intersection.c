/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:11:39 by erin              #+#    #+#             */
/*   Updated: 2024/03/05 18:26:05 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_scene.h"
#include "utils.h"

t_intersection	determine_intersection_ray_and_cylinder(t_cylinder \
														*cylinder, t_ray ray)
{
	t_intersection	intersection;
	double			a;
	double			b;
	double			c;
	double			d;

	intersection.is_success = false;
	a = pow(vector_length(cross_product(ray.direction, cylinder->axis)), 2.0);
	b = 2 * dot_product(cross_product(ray.direction, cylinder->axis), \
		cross_product(subtract_vectors(ray.point, cylinder->origin), \
				cylinder->axis));
	c = pow(vector_length(cross_product(subtract_vectors(ray.point, \
		cylinder->origin), cylinder->axis)), 2.0) - pow(cylinder->radius, 2.0);
	if (a == 0)
		return (intersection);
	d = discriminant(a, b, c);
	if (d < 0)
		return (intersection);
	return (get_intersection_ray_and_cylinder(cylinder, ray, \
			(-b - sqrt(d)) / (2 * a), (-b + sqrt(d)) / (2 * a)));
}

t_intersection	get_intersection_ray_and_object(t_shape *shape, t_ray ray)
{
	t_intersection	intersection;

	if (shape->object == PLANE)
		intersection = \
			determine_intersection_ray_and_plane(shape->substance, ray);
	else if (shape->object == SPHERE)
		intersection = \
			determine_intersection_ray_and_sphere(shape->substance, ray);
	else if (shape->object == CYLINDER)
		intersection = \
			determine_intersection_ray_and_cylinder(shape->substance, ray);
	else
		intersection.is_success = false;
	return (intersection);
}

t_shape	*determine_intersection_ray_and_object(t_list *shape_list, \
								t_ray ray, double light_source_distance)
{
	t_list			*iterator;
	t_shape			*nearest_shape;
	t_intersection	intersection;

	iterator = shape_list;
	nearest_shape = NULL;
	while (iterator != NULL)
	{
		intersection = get_intersection_ray_and_object(iterator->content, ray);
		if (intersection.is_success && light_source_distance > \
			vector_length(subtract_vectors(intersection.point, ray.point)))
		{
			((t_shape *)iterator->content)->intersection = intersection;
			nearest_shape = iterator->content;
			light_source_distance = \
				vector_length(subtract_vectors(intersection.point, ray.point));
		}
		iterator = iterator->next;
	}
	return (nearest_shape);
}
