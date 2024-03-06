/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:29:23 by hsawamur          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/05 19:55:04 by erin             ###   ########.fr       */
=======
/*   Updated: 2024/03/06 14:19:53 by erin             ###   ########.fr       */
>>>>>>> 84d2404
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define FAILURE 1
#define FAILED_TO_ALLOCATE_MEMORY "Error: Failed to allocate memory"

void	new_mlx_window(t_mlx_data *mlx, bool *result)
{
	mlx->window = mlx_new_window(mlx->data, \
				WINDOW_WIDTH, WINDOW_HEIGHT, MLX_TITLE);
	if (*result && mlx->window == NULL)
	{
		mlx->data = NULL;
		perror(FAILED_TO_ALLOCATE_MEMORY);
		*result = false;
	}
}

void	new_mlx_img(t_mlx_data *mlx, bool *result)
{
	mlx->img.data = mlx_new_image(mlx->data, \
		max(WINDOW_HEIGHT, WINDOW_WIDTH), max(WINDOW_HEIGHT, WINDOW_WIDTH));
	if (*result && mlx->img.data == NULL)
	{
		mlx_destroy_window(mlx->data, mlx->window);
		mlx->window = NULL;
		mlx->data = NULL;
		perror(FAILED_TO_ALLOCATE_MEMORY);
		exit(FAILURE);
		*result = false;
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
		perror(FAILED_TO_ALLOCATE_MEMORY);
		*result = false;
	}
	new_mlx_window(&mlx, result);
	new_mlx_img(&mlx, result);
	return (mlx);
}
