/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:09:01 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/05 19:57:04 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "define.h"

t_color	new_color(double red, double green, double blue);
void	add_color(t_color *color1, t_color color2);
t_rgb	get_rgb_in_shape(t_shape *shape);
void	get_radiance_to_color(t_color *color, double min, double max);
t_color	multiply_color(t_color color, double scalar);
void	my_mlx_pixel_put(t_img *img_data, int x, int y, int color);

#endif
