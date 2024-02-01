/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:29:23 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/01 19:37:09 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "minirt.h"

void	delete_mlx_data(t_mlx_data *mlx)
{
	free(mlx->data);
	free(mlx->window);
	free(mlx->img.data);
	free(mlx);
}

t_mlx_data	*new_mlx_data()
{
	t_mlx_data	*mlx;

	mlx = malloc(sizeof(t_mlx_data));
	if (mlx == NULL)
		return (NULL);
	mlx->data = mlx_init();
	if (mlx->data == NULL)
	{
		free(mlx);
		return (NULL);
	}
	mlx->window = mlx_new_window(mlx->data, WINDOW_MAX_X, WINDOW_MAX_Y, MLX_TITLE);
	if (mlx->window == NULL)
	{
		free(mlx->data);
		free(mlx);
		return (NULL);
	}
	mlx->img.data = mlx_new_image(mlx->data, WINDOW_MAX_X, WINDOW_MAX_Y);
	if (mlx->img.data == NULL)
	{
		free(mlx->data);
		free(mlx->window);
		free(mlx);
		return (NULL);
	}
	mlx->img.address = mlx_get_data_addr(mlx->img.data, &mlx->img.bits_per_pixel, &mlx->img.size_line,
											   &mlx->img.endian);
	return (mlx);
}
