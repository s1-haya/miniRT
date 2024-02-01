/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:35:48 by hsawamur          #+#    #+#             */
/*   Updated: 2024/01/27 13:33:17 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_light	new_light(t_vector point, t_color intensity)
{
	t_light	light;

	// light = malloc(sizeof(t_light));
	// if (light == NULL)
	// 	return (NULL);
	light.light_ray.point = point;
	light.intensity = intensity;
	return (light);
}
