/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:36:37 by erin              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/05 19:20:30 by erin             ###   ########.fr       */
=======
/*   Updated: 2024/03/06 14:33:43 by erin             ###   ########.fr       */
>>>>>>> 84d2404
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_SCENE_H
# define RENDER_SCENE_H

# include "define.h"

# define C_EPSILON 0.001953125

t_intersection	determine_intersection_ray_and_plane(t_plane *plane, t_ray ray);
t_intersection	determine_intersection_ray_and_sphere(t_sphere *sphere, \
														t_ray ray);
t_vector		cylinder_normal(t_intersection intersection, \
											t_cylinder *cylinder);
t_intersection	get_intersection_ray_and_cylinder(t_cylinder *cylinder, \
									t_ray ray, double t1, double t2);
t_intersection	determine_intersection_ray_and_cylinder(t_cylinder *cylinder, \
																	t_ray ray);
t_intersection	get_intersection_ray_and_object(t_shape *shape, t_ray ray);
t_shape			*determine_intersection_ray_and_object(t_list *shape_list, \
									t_ray ray, double light_source_distance);
void			add_ambient_light(t_color *color, t_ambient_light ambient, \
												t_shape *nearest_shape);
void			add_diffuse_reflection(t_color *color, t_shape *nearest_shape, \
											t_vector incident, t_light light);
void			add_specular_reflection(t_color *color, t_scene *scene, \
										t_shape *nearest_shape, t_light light);
void			draw_shadow_shading(t_scene *scene, t_shape *nearest_shape, \
										t_color *color, t_light *light);
void			shading(t_scene *scene, t_shape *nearest_shape, int x, int y);
t_ray			set_viewpoint(t_camera *camera, double lx, double ly);
void			render_scene(t_scene *scene);

#endif