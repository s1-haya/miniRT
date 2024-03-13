/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_one_line_to_minirt_list.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:01:42 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/13 12:15:06 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

#define ERROR_NOT_MEMORY_ALLOCATED "Error:\nMemory allocation failed.\
 Please close other applications and try again.\n"
#define ERROR_NOT_CORRECT_SIZE "Error:\nIncorrect number of parameters.\n"

void			*get_null_error_message(char *message, bool *result);
t_minirt_list	*init_minirt_list(void);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_strdup(const char *src);
char			**ft_split(char const *str, char c);
char			*ft_strndup(const char *s1, size_t n);
void			delete_minirt_list(t_minirt_list *list);
void			error_message(char *error_message, bool *result);

t_minirt_list	*convert_one_line_to_minirt_list(char *line, bool *result)
{
	t_minirt_list	*list;
	char			*first_space;

	list = init_minirt_list();
	if (list == NULL)
		return (get_null_error_message(ERROR_NOT_MEMORY_ALLOCATED, result));
	while (*line == ' ')
		line++;
	first_space = ft_strchr(line, ' ');
	if (first_space == NULL)
	{
		delete_minirt_list(list);
		return (get_null_error_message(ERROR_NOT_CORRECT_SIZE, result));
	}
	list->identifier = ft_strndup(line, first_space - line);
	list->value = ft_split(first_space + 1, ' ');
	if (list->identifier == NULL || list->value == NULL)
	{
		delete_minirt_list(list);
		return (get_null_error_message(ERROR_NOT_MEMORY_ALLOCATED, result));
	}
	return (list);
}
