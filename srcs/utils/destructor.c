/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:49:42 by erin              #+#    #+#             */
/*   Updated: 2024/03/05 19:44:21 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	if (scene->mlx.data && scene->mlx.window)
		mlx_destroy_window(scene->mlx.data, scene->mlx.window);
	if (scene->mlx.data && scene->mlx.img.data)
		mlx_destroy_image(scene->mlx.data, scene->mlx.img.data);
	delete_shape(&(scene->shape));
	while (scene->light)
	{
		free(scene->light);
		scene->light = scene->light->next;
	}
}
