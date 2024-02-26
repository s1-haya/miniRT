/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rt_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:56:05 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/21 17:47:17 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "parser.h"

#define ERROR (-1)

void load_file_into_minirt_list(t_minirt_list **head, const int fd, bool *result);

t_minirt_list *read_rt_file(const char *file_name, bool *result)
{
	t_minirt_list *head;
	int fd;

	*result = is_target_file_extension(file_name, ".rt");
	fd = open(file_name, O_RDONLY);
	if (fd == ERROR)
	{
		perror("open");
		*result = false;
	}
	head = NULL;
	if (result)
		load_file_into_minirt_list(&head, fd, result);
	close(fd);
	return (head);
}

// #include <libc.h>
// int main(void)
// {
// 	bool result = true;
// 	read_rt_file(list, "./get_next_line/test.rt", &result);
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