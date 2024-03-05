/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_conf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:46:12 by erin              #+#    #+#             */
/*   Updated: 2024/03/05 19:55:10 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	esc_key(int keycode, t_scene *scene)
{
	if (keycode == 53)
	{
		free_scene(scene);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	close_window(t_scene *scene)
{
	free_scene(scene);
	exit(EXIT_SUCCESS);
}

void	mlx_conf(t_scene *scene)
{
	mlx_put_image_to_window(scene->mlx.data, scene->mlx.window, \
			scene->mlx.img.data, IMG_ORIGIN_X, IMG_ORIGIN_Y);
	mlx_hook(scene->mlx.window, 2, 1L << 0, esc_key, scene);
	mlx_hook(scene->mlx.window, 17, 1L << 17, close_window, scene);
	mlx_loop(scene->mlx.data);
}
