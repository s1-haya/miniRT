/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:29:23 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/13 11:58:44 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "minirt.h"

void	new_mlx_window(t_mlx_data *mlx, bool *result)
{
	if (*result == false)
		return ;
	mlx->window = mlx_new_window(mlx->data, \
				WINDOW_WIDTH, WINDOW_HEIGHT, MLX_TITLE);
	if (mlx->window == NULL)
	{
		mlx->data = NULL;
		perror("Error:\n");
		*result = false;
	}
}

void	new_mlx_img(t_mlx_data *mlx, bool *result)
{
	if (*result == false)
		return ;
	mlx->img.data = mlx_new_image(mlx->data, \
		WINDOW_WIDTH, WINDOW_HEIGHT);
	if (mlx->img.data == NULL)
	{
		mlx_destroy_window(mlx->data, mlx->window);
		mlx->window = NULL;
		mlx->data = NULL;
		perror("Error:\n");
		*result = false;
		return ;
	}
	mlx->img.address = mlx_get_data_addr(mlx->img.data, \
			&mlx->img.bits_per_pixel, &mlx->img.size_line, &mlx->img.endian);
}

t_mlx_data	new_mlx_data(bool *result)
{
	t_mlx_data	mlx;

	mlx.data = mlx_init();
	if (mlx.data == NULL)
	{
		perror("Error:\n");
		*result = false;
	}
	new_mlx_window(&mlx, result);
	new_mlx_img(&mlx, result);
	return (mlx);
}
