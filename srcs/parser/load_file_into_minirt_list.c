/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_into_minirt_list.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:59:23 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/21 11:42:08 by hsawamur         ###   ########.fr       */
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

void load_file_into_minirt_list(t_minirt_list **head, const int fd, bool *result)
{
	char	*line;

	while (*result)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("line: %s\n", line);
		add_back_minirt_list(head, convert_one_line_to_minirt_list(line, result));
		free(line);
	}
}

// 文字列からt_minirt_listを作成する関数（空白1文字で区切る、res）
// #include <libc.h>
// int main(void)
// {
// 	t_minirt_list *list;
// 	list = init_minirt_list();
// 	list->identifier = strdup("A");
// 	bool result = true;
// 	load_file_into_minirt_list(list, "./get_next_line/test.rt", &result);
// 	if (result)
// 	{
// 		print_minirt_list(list);
// 		delete_minirt_list(list);
// 		system("leaks -q a.out");
// 		return (0);
// 	}
// 	printf("ERROR: \n");
// 	print_minirt_list(list);
// 	delete_minirt_list(list);
// 	system("leaks -q a.out");
// 	return (1);
// }
