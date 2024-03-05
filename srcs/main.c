/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:52:18 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/05 20:00:29 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool		verify_single_argument(int argc);
void		parser(t_scene *scene, const char *file_name, bool *result);
t_mlx_data	new_mlx_data(bool *result);

int	main(int argc, char *argv[])
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
