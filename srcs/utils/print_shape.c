/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:56:36 by erin              #+#    #+#             */
/*   Updated: 2024/03/05 19:55:59 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_rgb(t_rgb rgb)
{
	printf("red %d, green %d, blue %d\n", rgb.red, rgb.green, rgb.blue);
}

void	print_sphere(t_sphere *sphere)
{
	printf("sphere:\n");
	print_vector(sphere->origin, "origin");
	printf("radius %f\n", sphere->radius);
	print_rgb(sphere->rgb);
}

void	print_plane(t_plane *plane)
{
	printf("plane:\n");
	print_vector(plane->point, "point");
	print_vector(plane->normal, "normal");
	print_rgb(plane->rgb);
}

void	print_cylinder(t_cylinder *cylinder)
{
	printf("cylinder:\n");
	print_vector(cylinder->origin, "center");
	print_vector(cylinder->axis, "axis");
	printf("diameter %f\n", cylinder->radius * 2);
	printf("height %f\n", cylinder->height);
	print_rgb(cylinder->rgb);
}

void	print_shape(t_list *list)
{
	while (list != NULL)
	{
		if (((t_shape *)list->content)->object == PLANE)
			print_plane((t_plane *)(((t_shape *)list->content)->substance));
		else if (((t_shape *)list->content)->object == SPHERE)
			print_sphere((t_sphere *)(((t_shape *)list->content)->substance));
		else if (((t_shape *)list->content)->object == CYLINDER)
			print_cylinder((t_cylinder *) \
						(((t_shape *)list->content)->substance));
		else
			printf("none;\n");
		list = list->next;
	}
}
