/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:03:36 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/04 16:59:17 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <stdbool.h>

typedef struct s_ray
{
	t_vector	point;
	t_vector	direction;
}	t_ray;

typedef struct s_intersection
{
	double		distance;
	t_vector	point;
	t_vector	normal;
	bool		is_success;
}	t_intersection;

#endif
