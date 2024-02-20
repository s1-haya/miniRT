/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_into_minirt_list.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:59:23 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/20 17:44:41 by hsawamur         ###   ########.fr       */
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

void	add_back_minirt_list(t_minirt_list **head, t_minirt_list *new_list);
void	delete_minirt_list(t_minirt_list *list);
void	print_minirt_list(t_minirt_list *list);
t_minirt_list	*init_minirt_list();

t_minirt_list	*convert_one_line_to_minirt_list(char *line, bool *result)
{
	t_minirt_list	*list;

	list = init_minirt_list();
	if (list == NULL)
	{
		*result = false;
		return (NULL);
	}
	list->identifier = ;
	list->value = 
	// list.value = ["Value", "key"];
	return (list);
}

void	load_file_into_minirt_list(t_minirt_list *head, const char *file_name, bool *result)
{
	char			*line;
	int				fd;

	// *result = is_target_file_extension(file_name, ".rt");
	fd = open(file_name, O_RDONLY);
	while (result)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		add_back_minirt_list(&head, convert_one_line_to_minirt_list(line, result));
		free(line);
	}
	close(fd);
}

// 文字列からt_minirt_listを作成する関数（空白1文字で区切る、res）
#include <libc.h>
int main(void)
{
	t_minirt_list *list;
	list = init_minirt_list();
	list->identifier = strdup("A");
	bool result = true;
	load_file_into_minirt_list(list, "./get_next_line/test.rt", &result);
	if (result)
	{
		print_minirt_list(list);
		delete_minirt_list(list);
		system("leaks -q a.out");
		return (0)
	}
	printf("ERROR: \n");
	return (1);
}
