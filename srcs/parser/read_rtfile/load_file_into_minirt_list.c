/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_into_minirt_list.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:59:23 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/26 11:25:53 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft ファイルを一行ずつ読み取りt_hashmapに格納する関数作成
// 入力 ftファイル
// 出力 t_hashmap *

#include "parser.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void add_back_minirt_list(t_minirt_list **head, t_minirt_list *new_list);
void delete_minirt_list(t_minirt_list *list);
void print_minirt_list(t_minirt_list *list);
t_minirt_list *init_minirt_list();
t_minirt_list *convert_one_line_to_minirt_list(char *line, bool *result);
char *get_next_line(int fd);
// char	*ft_strndup(const char *s1, size_t n);
// size_t	ft_strlen(const char *str);

static bool	check_only_new_line(char *line)
{
	//改行をチェックしているというより、空文字列を確認してる気がする。けど値がない場合もあるからその場合の対応もしないとダメだよね。
	size_t i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '\n')
			return (false);
		i++;
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

void load_file_into_minirt_list(t_minirt_list **head, const int fd, bool *result)
{
	char	*line;

	while (*result)
	{
		line = get_next_line_except_for_last_new_line(fd);
		if (line == NULL)
			break;
		if (!check_only_new_line(line))
			add_back_minirt_list(head, convert_one_line_to_minirt_list(line, result));
		free(line);
	}
}