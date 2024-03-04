/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:42:33 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/04 11:17:32 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>
#include <stdio.h>

void	delete_value(char **value)
{
	size_t	i;

	i = 0;
	if (value != NULL)
	{
		while (value[i] != NULL)
		{
			free(value[i]);
			value[i] = NULL;
			i++;
		}
		free(value);
		value = NULL;
	}
}

void	delete_minirt_list(t_minirt_list *list)
{
	t_minirt_list	*iterator;

	while (list != NULL)
	{
		iterator = list;
		list = list->next;
		delete_value(iterator->value);
		free(iterator->identifier);
		iterator->identifier = NULL;
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
	list->identifier = NULL;
	list->value = NULL;
	list->next = NULL;
	return (list);
}

void	add_back_minirt_list(t_minirt_list **head, t_minirt_list *new_list)
{
	t_minirt_list *current;

	current = (*head);
	if (*head == NULL)
		*head = new_list;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new_list;
	}
}

#include <stdio.h>
void	print_value(char **value)
{
	size_t	i;

	i = 0;
	if (value != NULL)
	{
		while (value[i] != NULL)
		{
			printf("- value[%zu]:   %s\n", i, value[i]);
			i++;
		}
	}
}
void	print_minirt_list(t_minirt_list *list)
{
	if (list != NULL)
	{
		printf("minirt_list\n");
		while (list != NULL)
		{
			printf("- identifier: %s\n", list->identifier);
			print_value(list->value);
			list = list->next;
		}
		// printf("identifier:   %s\n", list->identifier);
	}
}
