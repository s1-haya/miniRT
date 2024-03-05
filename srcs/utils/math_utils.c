/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:10:49 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/20 19:03:59 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	clamp(double v, double v_min, double v_max)
{
	if (v < v_min)
		return (v_min);
	else if (v_max < v)
		return (v_max);
	return (v);
}

double	min(double n1, double n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

double	max(double n1, double n2)
{
	if (n1 < n2)
		return (n2);
	return (n1);
}

double	discriminant(double a, double b, double c)
{
	return (pow(b, 2.0) - 4 * a * c);
}

double	min_solution(double a, double b, double c)
{
	double	d;
	double	t1;
	double	t2;

	d = discriminant(a, b, c);
	if (d < 0)
		return (-1);
	t1 = (-b + sqrt(d)) / (2 * a);
	t2 = (-b - sqrt(d)) / (2 * a);
	if (t1 >= 0 && t2 >= 0)
		return (min(t1, t2));
	else if (t2 >= 0)
		return (t2);
	else if (t1 >= 0)
		return (t1);
	return (-1);
}
