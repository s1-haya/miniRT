/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_target_file_extension.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 08:28:45 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/18 10:44:36 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <string.h>

# define SUCCESS 0
# define FAILURE 1

bool	is_target_file_extension(const char *filename, const char *extension)
{
	const char	*dot;

	if (!filename || !extension || *filename == '.' || *extension != '.')
		return (false);
	dot = ft_strrchr(filename, '.');
	if (!dot || dot == filename)
		return (false);
	return (ft_strcmp(dot, extension) == 0);
}

// #include "stdio.h"
// int main(void)
// {
// 	if (is_target_file_extension("text.ft", ".rt"))
// 		printf("good\n");
// 	else
// 		printf("bad\n");
// 	if (is_target_file_extension("text.ft", "objs"))
// 		printf("good\n");
// 	else
// 		printf("bad\n");
// 	return (SUCCESS);
// }
