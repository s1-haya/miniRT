/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:29:23 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/04 16:46:51 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "minirt.h"

#define FAILURE 1
#define FAILED_TO_ALLOCATE_MEMORY "Error: Failed to allocate memory"

t_mlx_data	new_mlx_data(bool *result)
{
	t_mlx_data	mlx;

	mlx.data = mlx_init();
	if (mlx.data == NULL)
	{
		perror(FAILED_TO_ALLOCATE_MEMORY);
		*result = false;
	}
	mlx.window = mlx_new_window(mlx.data, WINDOW_WIDTH, WINDOW_HEIGHT, MLX_TITLE);
	if (*result && mlx.window == NULL)
	{
		mlx.data = NULL;
		perror(FAILED_TO_ALLOCATE_MEMORY);
		*result = false;
	}
	mlx.img.data = mlx_new_image(mlx.data, IMG_MAX_X, IMG_MAX_Y);
	if (*result && mlx.img.data == NULL)
	{
		mlx_destroy_window(mlx.data, mlx.window);
		mlx.window = NULL;
		mlx.data = NULL;
		perror(FAILED_TO_ALLOCATE_MEMORY);
		exit(FAILURE);
		*result = false;
	}
	mlx.img.address = mlx_get_data_addr(mlx.img.data, &mlx.img.bits_per_pixel, &mlx.img.size_line,
											   &mlx.img.endian);
	return (mlx);
}
