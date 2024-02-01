/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:55:17 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/01 20:07:05 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "vector.h"
# include "ray.h"
# include "color.h"

typedef struct s_light
{
	double		distance;
	t_ray		light_ray;
	t_color		intensity;
}	t_light;

typedef struct s_point_light
{
	t_light	light;
}	t_point_light;

typedef struct s_direction_light
{
	t_light	light;
}	t_direction_light;

t_light	new_light(t_vector point, t_color intensity);

#endif
