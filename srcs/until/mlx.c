/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:29:23 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/01 17:30:22 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "minirt.h"

#define FAILURE 1
#define FAILED_TO_ALLOCATE_MEMORY "Error: Failed to allocate memory"

void	delete_mlx_data(t_mlx_data mlx)
{
	free(mlx.data);
	free(mlx.window);
	free(mlx.img.data);
}

t_mlx_data	new_mlx_data()
{
	t_mlx_data	mlx;

	mlx.data = mlx_init();
	if (mlx.data == NULL)
	{
		perror(FAILED_TO_ALLOCATE_MEMORY);
		exit(FAILURE);
	}
	mlx.window = mlx_new_window(mlx.data, WINDOW_WIDTH, WINDOW_HEIGHT, MLX_TITLE);
	if (mlx.window == NULL)
	{
		free(mlx.data);
		perror(FAILED_TO_ALLOCATE_MEMORY);
		exit(FAILURE);
	}
	mlx.img.data = mlx_new_image(mlx.data, IMG_MAX_X, IMG_MAX_Y);
	if (mlx.img.data == NULL)
	{
		free(mlx.data);
		free(mlx.window);
		perror(FAILED_TO_ALLOCATE_MEMORY);
		exit(FAILURE);
	}
	mlx.img.address = mlx_get_data_addr(mlx.img.data, &mlx.img.bits_per_pixel, &mlx.img.size_line,
											   &mlx.img.endian);
	return (mlx);
}
