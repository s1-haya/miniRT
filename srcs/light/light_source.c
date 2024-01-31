/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_source.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:35:48 by hsawamur          #+#    #+#             */
/*   Updated: 2024/01/27 13:33:17 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light_source.h"

t_light_source	new_light_source(t_vector point, t_color intensity)
{
	t_light_source	light_source;

	// light_source = malloc(sizeof(t_light_source));
	// if (light_source == NULL)
	// 	return (NULL);
	light_source.light_ray.point = point;
	light_source.intensity = intensity;
	return (light_source);
}
