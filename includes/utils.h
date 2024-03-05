/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:58:21 by erin              #+#    #+#             */
/*   Updated: 2024/03/05 19:56:11 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "define.h"

# define ERROR_INCORRCT_NUMBER_OF_ARGUMENTS "Error: \
Incorrect number of arguments.\n Usage: ./miniRT <filename>"

double		clamp(double v, double v_min, double v_max);
double		min(double n1, double n2);
double		max(double n1, double n2);
double		discriminant(double a, double b, double c);
double		min_solution(double a, double b, double c);
t_vector	new_vector(double x, double y, double z);
double		vector_length(t_vector v);
void		normalize_vector(t_vector *v);
t_vector	get_inverse_vector(t_vector v);
t_vector	add_vectors(t_vector v1, t_vector v2);
t_vector	subtract_vectors(t_vector v1, t_vector v2);
double		dot_product(t_vector v1, t_vector v2);
t_vector	cross_product(t_vector v1, t_vector v2);
t_vector	scalar_multiply(t_vector v, double scalar);
void		print_vector(t_vector vec, char *name);
void		delete_shape(t_list **list);
void		free_scene(t_scene *scene);
void		print_rgb(t_rgb rgb);
void		print_sphere(t_sphere *sphere);
void		print_plane(t_plane *plane);
void		print_cylinder(t_cylinder *cylinder);
void		print_shape(t_list *list);


#endif