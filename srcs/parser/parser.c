/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:45:34 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/05 19:43:35 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_minirt_list	*read_rt_file(const char *file_name, bool *result);
bool			validate(t_scene *scene, t_minirt_list *list,
					t_param_count *count, bool *result);
t_param_count	init_parameter_count(void);
void			check_set_parameter(t_param_count parameter_count,
					bool *result);
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
		delete_minirt_list(free_list);
		return ;
	}
	count_parameter = init_parameter_count();
	while (list != NULL)
	{
		validate(scene, list, &count_parameter, result);
		if (*result == false)
		{
			delete_minirt_list(free_list);
			return ;
		}
		list = list->next;
	}
	check_set_parameter(count_parameter, result);
	delete_minirt_list(free_list);
}
