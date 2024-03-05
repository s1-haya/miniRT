/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:52:18 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/05 18:41:47 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <mlx.h>
#include "minirt.h"
#include "shape.h"
#include "color.h"
#include "scene.h"
#include "libft.h"
#include "mlx_data.h"

bool verify_single_argument(int argc);
void parser(t_scene *scene, const char *file_name, bool *result);
t_shape *determine_intersection_ray_and_object(t_list *shape, t_ray ray, double light_distance);
void shading(t_scene *scene, t_shape *nearest_shape, int x, int y);
t_mlx_data	new_mlx_data(bool *result);
t_camera new_camera(t_vector view_point, t_vector look_at_point, double horizontal_value);
double clamp(double v, double v_min, double v_max);
void	free_scene(t_scene *scene);
t_ray set_viewpoint(t_camera *camera, double lx, double ly);
void	render_scene(t_scene *scene);
void	print_shape(t_list *list);

int main(int argc, char *argv[])
{
	t_scene	scene;
	bool	result;

	if (!verify_single_argument(argc))
		return (FAILURE);
	ft_bzero(&scene, sizeof(t_scene));
	result = true;
	parser(&scene, argv[1], &result);
	if (!result)
	{
		free_scene(&scene);
		return (FAILURE);
	}
	scene.mlx = new_mlx_data(&result);
	if (scene.shape != NULL)
		print_shape(scene.shape);
	render_scene(&scene);
	mlx_conf(&scene);
	return (SUCCESS);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q miniRT");
}
