/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:03:27 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/24 11:27:22 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_scene	new_scene(t_shape **shape,
				t_light *light, 
				t_camera camera,
				t_mlx_data data)
{
	t_scene	scene;

	scene.shape = shape;
	scene.light = light;
	scene.camera = camera;
	scene.mlx = data;
	return (scene);
}
