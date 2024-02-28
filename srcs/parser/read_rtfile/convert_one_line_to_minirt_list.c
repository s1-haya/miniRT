/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_one_line_to_minirt_list.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:01:42 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/22 23:18:57 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <stdlib.h>

void			*set_error_and_return_null(bool *result);
t_minirt_list	*init_minirt_list();
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_strdup(const char *src);
char			**ft_split(char const *str, char c);
char			*ft_strndup(const char *s1, size_t n);
void			delete_minirt_list(t_minirt_list *list);

t_minirt_list	*convert_one_line_to_minirt_list(char *line, bool *result)
{
	t_minirt_list	*list;
	char			*first_space;

	list = init_minirt_list();
	if (list == NULL)
		return (set_error_and_return_null(result));
	while (*line == ' ')
		line++;
	first_space = ft_strchr(line, ' ');
	if (first_space == NULL)
	{
		delete_minirt_list(list);
		return (set_error_and_return_null(result));
	}
	list->identifier = ft_strndup(line, first_space - line);
	list->value = ft_split(first_space + 1, ' ');
	if (list == NULL || list->value[0] == NULL)
	{
		delete_minirt_list(list);
		return (set_error_and_return_null(result));
	}
	return (list);
}
