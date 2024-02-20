/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_one_line_to_minirt_list.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:01:42 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/20 19:32:33 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <stdlib.h>

#include <stdio.h>

void			*set_error_and_return_null(bool *result);
t_minirt_list	*init_minirt_list();
char			**ft_split(char const *str, char c);
char			*ft_strndup(const char *s1, size_t n);

t_minirt_list	*convert_one_line_to_minirt_list(char *line, bool *result)
{
	t_minirt_list	*list;
	char			*first_space;

	printf("line: %s\n", line);
	list = init_minirt_list();
	if (list == NULL)
		return (set_error_and_return_null(result));
	while (*line == ' ')
		line++;
	first_space = ft_strchr(line, ' ');
    if (first_space == NULL)
	{
		free(list->identifier);
		free(list->value);
		free(list);
		return (set_error_and_return_null(result));
	}
    list->identifier = ft_strndup(line, first_space - line);
    list->value = ft_split(first_space + 1, ' ');
    if (list->value[0] == NULL)
	{
		free(list->identifier);
		free(list->value);
		free(list);
		return (set_error_and_return_null(result));
	}
	printf("idnetifier: %s\n", list->identifier);
	// for
	// printf("value:      %s\n", list->value);
	return (list);
}
