/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:49:12 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/04 17:00:03 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "shape.h"
# include "light.h"
# include "camera.h"
# include "minirt.h"
# include "libft.h"

typedef struct s_scene {
	t_list			*shape;
	t_light			*light;
	t_camera		camera;
	t_mlx_data		mlx;
	t_ambient_light	ambient;
}	t_scene;

#endif