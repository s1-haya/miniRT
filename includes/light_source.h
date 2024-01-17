/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_source.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:55:17 by hsawamur          #+#    #+#             */
/*   Updated: 2024/01/17 15:01:36 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_SOURCE_H
# define LIGHT_SOURCE_H

# include "vector.h"

typedef struct s_light_source
{
	double		distance;
	t_vector	point;
	t_vector	direction;
	double		intensity;
}	t_light_source;

typedef struct s_point_light_source
{
	s_light_source	light_source;
}	t_point_light_source;

typedef struct s_direction_light_source
{
	s_light_source	light_source;
}	t_direction_light_source;



#endif
