/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:12:21 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/05 17:41:46 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	my_mlx_pixel_put(t_img *img_data, int x, int y, int color)
{
	char	*target_pixel;
	int		cie;

	cie = (y * img_data->size_line + x * (img_data->bits_per_pixel / 8));
	target_pixel = img_data->address + cie;
	*(unsigned int *)target_pixel = color;
}
