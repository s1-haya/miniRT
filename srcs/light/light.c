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

#include "minirt.h"

t_light	*new_light(t_vector point, double intensity, t_rgb rgb)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (light == NULL)
		return (NULL);
	light->point = point;
	light->intensity = intensity;
	light->rgb = rgb;
	light->next = NULL;
	return (light);
}
