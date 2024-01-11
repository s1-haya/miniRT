/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:18:06 by hsawamur          #+#    #+#             */
/*   Updated: 2024/01/10 12:51:48 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>

typedef struct s_vector
{
	double x;
	double y;
	double z;
} t_vector;

typedef struct s_vector_data
{
	t_vector viewpoint;
	t_vector screen_point;
	t_vector origin_of_the_sphere;
	t_vector line_of_sight_vector;
	t_vector intersection_vector;
} t_vector_data;

t_vector new_vector(double x, double y, double z);
t_vector add_vectors(t_vector v1, t_vector v2);
t_vector subtract_vectors(t_vector v1, t_vector v2);
double dot_product(t_vector v1, t_vector v2);
t_vector cross_product(t_vector v1, t_vector v2);
double vector_length(t_vector v);
void normalize_vector(t_vector *v);
void scalar_multiply(t_vector *vector, double scalar);

#endif
