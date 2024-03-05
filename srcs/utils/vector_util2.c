/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_util2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:33:17 by erin              #+#    #+#             */
/*   Updated: 2024/03/04 19:00:36 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_vector	subtract_vectors(t_vector v1, t_vector v2)
{
	t_vector	vector;

	vector.x = v1.x - v2.x;
	vector.y = v1.y - v2.y;
	vector.z = v1.z - v2.z;
	return (vector);
}

double	dot_product(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vector	cross_product(t_vector v1, t_vector v2)
{
	t_vector	vector;

	vector.x = v1.y * v2.z - v1.z * v2.y;
	vector.y = v1.z * v2.x - v1.x * v2.z;
	vector.z = v1.x * v2.y - v1.y * v2.x;
	return (vector);
}

t_vector	scalar_multiply(t_vector v, double scalar)
{
	t_vector	vector;

	vector.x = scalar * v.x;
	vector.y = scalar * v.y;
	vector.z = scalar * v.z;
	return (vector);
}

void	print_vector(t_vector vec, char *name)
{
	printf("%s: (%lf, %lf, %lf)\n",name, vec.x, vec.y, vec.z);
}
