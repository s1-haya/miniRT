/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:45:34 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/21 18:30:15 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "scene.h"
#include "parser.h"

t_minirt_list	*read_rt_file(const char *file_name, bool *result);
bool			validate(t_minirt_list *list);
void			delete_minirt_list(t_minirt_list *list);

// void	parser(t_scene *scene, const char *file_name, bool *result)
// {
// 	t_minirt_list	*list;

// 	(void)scene
// 	list = read_rt_file(file_name, result);
// 	if (!result)
// 	{
// 		//error_fail_to_read
// 		return ;
// 	}
// 	while (list != NULL)
// 	{
// 		result = validate(list);
// 		if (!result)
// 		{
// 			//error_fail_to_validate
// 			delete_minirt_list(list);
// 			return ;
// 		}
// 		list = list->next;
// 	}
// }
