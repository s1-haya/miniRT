/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:09:01 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/06 10:25:39 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color
{
	double	red;
	double	green;
	double	blue;
}	t_color;

t_color	new_color(double red, double green, double blue);
void	set_color(double red, double green, double blue);
void	add_color(t_color *color1, t_color color2);
void	multi_color(t_color *color1, t_color color2);
void	get_radiance_to_color(t_color *color, double min, double max);

#endif
