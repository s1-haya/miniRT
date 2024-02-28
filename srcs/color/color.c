/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:00:11 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/20 19:04:30 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "vector.h"

t_color	new_color(double red, double green, double blue);
void	set_color(double red, double green, double blue);
void	add_color(t_color *color1, t_color color2);
void	multi_color(t_color *color1, t_color color2);
void	get_radiance_to_color(t_color *color, double min, double max);
double	clamp(double v, double v_min, double v_max);

t_color	new_color(double red, double green, double blue)
{
	t_color	color;

	color.red = red;
	color.green = green;
	color.blue = blue;
	return (color);
}

void	add_color(t_color *color1, t_color color2)
{
	(*color1).red += color2.red;
	(*color1).green += color2.green;
	(*color1).blue += color2.blue;
}

void	get_radiance_to_color(t_color *color, double min, double max)
{
	(*color).red = 255 * clamp((*color).red, min, max);
	(*color).green = 255 * clamp((*color).green, min, max);
	(*color).blue = 255 * clamp((*color).blue, min, max);
}
