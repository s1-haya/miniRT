/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:47:23 by erin              #+#    #+#             */
/*   Updated: 2024/03/04 18:52:28 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DATA_H
# define MLX_DATA_H

# include "scene.h"
# include <mlx.h>

int esc_key(int keycode, t_scene *scene);
int close_window(t_scene *scene);
void	mlx_conf(t_scene *scene);

#endif