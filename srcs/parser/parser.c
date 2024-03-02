/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:45:34 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/02 12:40:21 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include "scene.h"
#include "parser.h"

#define ERROR_NOT_SET_UPEER_CHARACTER "Error: Prameter don't set. \
parameter of upeer character must be set, please."

t_minirt_list	*read_rt_file(const char *file_name, bool *result);
bool			validate(t_scene *scene, t_minirt_list *list,
					t_param_count *count, bool *result);
t_param_count	init_parameter_count();
void			check_set_parameter(t_param_count parameter_count, bool *result);
void			delete_minirt_list(t_minirt_list *list);
void			print_minirt_list(t_minirt_list *list);

void	parser(t_scene *scene, const char *file_name, bool *result)
{
	t_minirt_list	*list;
	t_param_count	count_parameter;
	t_minirt_list	*free_list;

	list = read_rt_file(file_name, result);
	free_list = list;
	if (result == false)
	{
		*result = false;
		return ;
	}
	count_parameter = init_parameter_count();
	while (list != NULL)
	{
		validate(scene, list, &count_parameter, result);
		if (*result == false)
		{
			delete_minirt_list(free_list);
			*result = false;
			return ;
		}
		list = list->next;
	}
	check_set_parameter(count_parameter, result);
	delete_minirt_list(free_list);
}
