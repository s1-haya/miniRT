/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_into_minirt_list.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:59:23 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/20 15:23:54 by hsawamur         ###   ########.fr       */
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

t_minirt_list	init_minirt_list()
{
	t_minirt_list	list;

	list.identifer = NULL;
	list.value = NULL;
	list.next = NULL;
	return (list);
}


t_minirt_list	*convert_one_line_to_minirt_list(char *line, bool *result)
{
	t_minirt_list	*list;
	t_minirt_list	tmp;

	tmp = init_minirt_list();
	list = &(tmp);
	// line
	// identifer　文字列
	// value 文字列配列
	list->identifer = "A";
	// list.value = ["Value", "key"];
	return (list);
}

void	add_back_minirt_list(t_minirt_list **head, t_minirt_list *new_list)
{
	t_minirt_list *current;

	current = (*head);
	if (head == NULL)
		*head = new_list;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new_list;
	}
}

void	load_file_into_minirt_list(t_minirt_list *head, const char *file_name, bool *result)
{
	t_minirt_list	iterator;
	char			*line;
	int				fd;

	head = NULL;
	// *result = is_target_file_extension(file_name, ".rt");
	iterator = init_minirt_list();
	fd = open(file_name, O_RDONLY);
	while (result)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		iterator.identifer = "B";
		add_back_minirt_list(&head, &iterator);
		if (head != NULL)
		{
			printf("line: %s\n", head->identifer);
			printf("line: %s\n", line);
		}
		// list = list->next;
		free(line);
	}
	close(fd);
}

void	print_minirt_list(t_minirt_list *list)
{
	if (list != NULL)
	{
		while (list->identifer != NULL)
		{
			printf("identifer:   %s\n", list->identifer);
			// printf("value: %s\n", list->value);
			list = list->next;
		}
		// printf("identifer:   %s\n", hashmap->identifer);
	}
}

int main(void)
{
	t_minirt_list list;
	list = init_minirt_list();
	bool result = true;
	load_file_into_minirt_list(&list, "./get_next_line/test.rt", &result);
	printf("identifer:   %s\n", list.identifer);
	print_minirt_list(&list);
	return (0);
}
