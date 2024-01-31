/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:29:23 by hsawamur          #+#    #+#             */
/*   Updated: 2024/01/31 18:58:39 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "minirt.h"

void	delete_mlx_data(t_mlx_data *data)
{
	free(data->mlx);
	free(data->window);
	free(data->img);
	free(data);
}

t_mlx_data	*new_mlx_data()
{
	t_mlx_data	*data;

	data = malloc(sizeof(t_mlx_data));
	if (data == NULL)
		return (NULL);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		free(data);
		return (NULL);
	}
	data->window = mlx_new_window(data->mlx, WINDOW_MAX_X, WINDOW_MAX_Y, MLX_TITLE);
	if (data->window == NULL)
	{
		free(data->mlx);
		free(data);
		return (NULL);
	}
	data->img = mlx_new_image(data->mlx, WINDOW_MAX_X, WINDOW_MAX_Y);
	if (data->img == NULL)
	{
		free(data->window);
		free(data->mlx);
		free(data);
		return (NULL);
	}
	data->address = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->size_line,
											   &data->endian);
	return (data);
}
