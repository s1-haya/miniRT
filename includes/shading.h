/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:36:37 by erin              #+#    #+#             */
/*   Updated: 2024/03/04 19:13:08 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADING_H
# define SHADING_H

# include <math.h>
# include <stdlib.h>
# include <stdbool.h>
# include "minirt.h"
# include "scene.h"
# include "shape.h"
# include "vector.h"
# include "color.h"
# include "libft.h"

# define C_EPSILON (1.0 / 512)

t_intersection	determine_intersection_ray_and_plane(t_plane *plane, t_ray ray);
t_intersection	determine_intersection_ray_and_sphere(t_sphere *sphere, t_ray ray);
t_vector		cylinder_normal(t_intersection intersection, t_cylinder *cylinder);
t_intersection	get_intersection_ray_and_cylinder(t_cylinder *cylinder, t_ray ray, double t1, double t2);
t_intersection	determine_intersection_ray_and_cylinder(t_cylinder *cylinder, t_ray ray);
t_intersection	get_intersection_ray_and_object(t_shape *shape, t_ray ray);
t_shape			*determine_intersection_ray_and_object(t_list *shape_list, t_ray ray, double light_source_distance);


#endif