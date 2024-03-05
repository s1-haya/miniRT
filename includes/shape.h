/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:42:30 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/05 19:20:39 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "define.h"

t_shape			*new_shape(void *shape, enum e_object object);
t_sphere		*new_sphere(t_vector origin, double radius, t_rgb rgb);
t_cylinder		*new_cylinder(t_vector origin, t_vector axis, double radius, double height, t_rgb rgb);
t_plane			*new_plane(t_vector normal, t_vector point, t_rgb rgb);
t_ray			new_ray(t_vector point, t_vector direction);
t_intersection	new_intersection(t_ray ray, double t);

#endif
