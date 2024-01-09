/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:08:00 by hsawamur          #+#    #+#             */
/*   Updated: 2024/01/07 16:47:01 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

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

// ベクトルの加算
t_vector	add_vectors(t_vector v1, t_vector v2)
{
	t_vector vector;

	vector.x = v1.x + v2.x;
	vector.y = v1.y + v2.y;
	vector.z = v1.z + v2.z;
	return (vector);
}

// ベクトルの減算
t_vector	subtract_vectors(t_vector v1, t_vector v2)
{
	t_vector	vector;

	vector.x = v1.x - v2.x;
	vector.y = v1.y - v2.y;
	vector.z = v1.z - v2.z;
	return (vector);
}

// ベクトルの内積
double	dot_product(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

// ベクトルの外積
t_vector	cross_product(t_vector v1, t_vector v2)
{
	t_vector	vector;

	vector.x = v1.y * v2.z - v1.z * v2.y;
	vector.y = v1.z * v2.x - v1.x * v2.z;
	vector.z = v1.x * v2.y - v1.y * v2.x;
	return (vector);
}

// #include <stdio.h>
// int main() {
//     t_vector vector1 = new_vector(3, 4, 5);
//     t_vector vector2 = new_vector(6, 7, 8);
//     t_vector vector3 = new_vector(9, 10, 11);

//     printf("Vector1: (%ld, %ld, %ld)\n", vector1.x, vector1.y, vector1.z);
//     printf("Vector2: (%ld, %ld, %ld)\n", vector2.x, vector2.y, vector2.z);
//     printf("Vector3: (%ld, %ld, %ld)\n", vector3.x, vector3.y, vector3.z);

//     t_vector sum = add_vectors(vector1, vector2);
//     printf("Vector addition: (%ld, %ld, %ld)\n", sum.x, sum.y, sum.z);

//     t_vector difference = subtract_vectors(vector1, vector2);
//     printf("Vector subtraction: (%ld, %ld, %ld)\n", difference.x, difference.y, difference.z);

//     double dot = dot_product(vector2, vector3);
//     printf("Dot product: %ld\n", dot);

//     t_vector cross = cross_product(vector2, vector3);
//     printf("Cross product: (%ld, %ld, %ld)\n", cross.x, cross.y, cross.z);

//     return 0;
// }
