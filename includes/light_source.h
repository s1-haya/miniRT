/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_source.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:55:17 by hsawamur          #+#    #+#             */
/*   Updated: 2024/01/19 16:55:42 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_SOURCE_H
# define LIGHT_SOURCE_H

# include "vector.h"
# include "color.h"

typedef struct s_light_source
{
	double		distance;
	t_vector	point;
	t_vector	direction;
	t_color		intensity;
}	t_light_source;

typedef struct s_point_light_source
{
	t_light_source	light_source;
}	t_point_light_source;

typedef struct s_direction_light_source
{
	t_light_source	light_source;
}	t_direction_light_source;

t_light_source	new_light_source(t_vector point, t_color intensity);

#endif
