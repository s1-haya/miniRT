/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:49:42 by erin              #+#    #+#             */
/*   Updated: 2024/03/06 16:18:27 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "shape.h"
#include <mlx.h>
#include "utils.h"

void	delete_shape(t_list **list)
{
	t_list	*current;
	t_list	*next;

	if (list == NULL || *list == NULL)
		return ;
	current = *list;
	while (current)
	{
		next = current->next;
		free(((t_shape *)(current->content))->substance);
		free((t_shape *)(current->content));
		free(current);
		current = next;
	}
	*list = NULL;
}

void	free_scene(t_scene *scene)
{
	t_light	*current;
	t_light	*next;

	if (scene->mlx.data && scene->mlx.window)
		mlx_destroy_window(scene->mlx.data, scene->mlx.window);
	if (scene->mlx.data && scene->mlx.img.data)
		mlx_destroy_image(scene->mlx.data, scene->mlx.img.data);
	delete_shape(&(scene->shape));
	current = scene->light;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
