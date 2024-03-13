/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_into_minirt_list.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:59:23 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/13 11:01:16 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void			add_back_minirt_list(t_minirt_list **head,
					t_minirt_list *new_list);
void			delete_minirt_list(t_minirt_list *list);
void			print_minirt_list(t_minirt_list *list);
t_minirt_list	*init_minirt_list(void);
t_minirt_list	*convert_one_line_to_minirt_list(char *line, bool *result);
char			*get_next_line(int fd);
void			error_message(char *error_message, bool *result);
int				ft_isspace(char c);

#define ERROR_NOT_SET_UPEER_CHARACTER "Error:\nThis file is empty. \
parameter of upeer character must be set, please.\n"

static bool	check_empty_string(char *line)
{
	while (*line != '\0')
	{
		if (!ft_isspace(*line))
			return (false);
		line++;
	}
	return (true);
}

static char	*get_next_line_except_for_last_new_line(int fd)
{
	char	*line;
	char	*line_except_for_last_new_line;

	line = get_next_line(fd);
	line_except_for_last_new_line = NULL;
	if (line != NULL && line[ft_strlen(line) - 1] == '\n')
	{
		line_except_for_last_new_line = ft_strndup(line, ft_strlen(line) - 1);
		free(line);
		return (line_except_for_last_new_line);
	}
	return (line);
}

void	load_file_into_minirt_list(t_minirt_list **head,
						const int fd, bool *result)
{
	char	*line;
	bool	is_empty_file;

	is_empty_file = true;
	while (*result)
	{
		line = get_next_line_except_for_last_new_line(fd);
		if (line == NULL)
		{
			if (is_empty_file)
				error_message(ERROR_NOT_SET_UPEER_CHARACTER, result);
			break ;
		}
		if (!check_empty_string(line))
		{
			add_back_minirt_list(head,
				convert_one_line_to_minirt_list(line, result));
			is_empty_file = false;
		}
		free(line);
	}
}
