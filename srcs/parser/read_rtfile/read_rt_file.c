/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rt_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:56:05 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/05 19:58:50 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define ERROR (-1)

void	load_file_into_minirt_list(t_minirt_list **head,
			const int fd, bool *result);

static int	get_file_descriptor(const char *file_name, bool *result)
{
	int	fd;

	if (*result == false)
		return (ERROR);
	fd = open(file_name, O_RDONLY);
	if (fd == ERROR)
	{
		perror("open");
		*result = false;
	}
	return (fd);
}

t_minirt_list	*read_rt_file(const char *file_name, bool *result)
{
	t_minirt_list	*head;
	int				fd;

	*result = is_target_file_extension(ft_strrchr(file_name, '/'), ".rt");
	fd = get_file_descriptor(file_name, result);
	head = NULL;
	if (*result)
		load_file_into_minirt_list(&head, fd, result);
	close(fd);
	return (head);
}
