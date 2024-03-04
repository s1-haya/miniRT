/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:03:36 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/04 14:10:40 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include <stdbool.h>

typedef struct s_ray
{
	t_vector point;
	t_vector direction;
}	t_ray;

typedef struct s_intersection
{
	double		distance;
	t_vector	point;
	t_vector	normal;
	bool		is_success;
}	t_intersection;

#endif
