/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_util1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:08:00 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/04 19:00:24 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_vector	new_vector(double x, double y, double z)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

double	vector_length(t_vector v)
{
	double	length;

	length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (length);
}

void	normalize_vector(t_vector *v)
{
	double	length;
	double	inv_length;

	length = vector_length(*v);
	if (length < 1e-8)
	{
		v->x = 0;
		v->y = 0;
		v->z = 0;
	}
	else
	{
		inv_length = 1.0 / length;
		v->x *= inv_length;
		v->y *= inv_length;
		v->z *= inv_length;
	}
}

t_vector	get_inverse_vector(t_vector v)
{
	t_vector	vector;

	vector.x = -1 * (v.x);
	vector.y = -1 * (v.y);
	vector.z = -1 * (v.z);
	return (vector);
}

t_vector	add_vectors(t_vector v1, t_vector v2)
{
	t_vector	vector;

	vector.x = v1.x + v2.x;
	vector.y = v1.y + v2.y;
	vector.z = v1.z + v2.z;
	return (vector);
}
