/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:49:12 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/29 16:52:53 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "light.h"
#include "camera.h"
#include "minirt.h"
#include "libft.h"

typedef struct s_scene {
	t_list			*shape;
	t_light			*light;
	t_camera		camera;
	t_mlx_data		mlx;
	t_ambient_light	ambient;
}	t_scene;
