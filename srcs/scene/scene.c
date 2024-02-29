/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:03:27 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/29 12:25:09 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_scene	new_scene(t_shape *shape,
				t_light *light, 
				t_mlx_data data)
{
	t_scene	scene;

	scene.shape = shape;
	scene.light = light;
	scene.mlx = data;
	return (scene);
}
