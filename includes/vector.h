/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:18:06 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/05 19:21:34 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "define.h"

t_vector	new_vector(double x, double y, double z);
t_vector	add_vectors(t_vector v1, t_vector v2);
t_vector	subtract_vectors(t_vector v1, t_vector v2);
double		dot_product(t_vector v1, t_vector v2);
t_vector	cross_product(t_vector v1, t_vector v2);
double		vector_length(t_vector v);
void		normalize_vector(t_vector *v);
t_vector	scalar_multiply(t_vector v, double scalar);
t_vector	get_inverse_vector(t_vector v);
void		print_vector(t_vector vec, char *name);

#endif
