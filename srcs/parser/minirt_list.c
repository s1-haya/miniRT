/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:42:33 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/20 17:10:52 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>

void	delete_minirt_list(t_minirt_list *list)
{
	t_minirt_list	*iterator;

	while (list != NULL)
	{
		iterator = list;
		list = list->next;
		free(iterator->identifer);
		iterator->identifer = NULL;
		free(iterator);
		iterator = NULL;
	}
}

t_minirt_list	*init_minirt_list()
{
	t_minirt_list	*list;

	list = (t_minirt_list *)malloc(sizeof(t_minirt_list));
	if (list == NULL)
		return (NULL);
	list->identifer = NULL;
	list->value = NULL;
	list->next = NULL;
	return (list);
}
