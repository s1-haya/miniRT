/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_target_file_extension.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 08:28:45 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/07 14:47:14 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "libft.h"

#define SUCCESS (0)
#define FAILURE (1)
#define ERROR_NOT_TARGET_FILE_EXTENSION "Error: Incorrect filename \
Please check the file you have entered. The file extension must be .ft.\n"

size_t	ft_strlen_s(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

bool	is_target_file_extension(const char *filename, const char *extension)
{
	size_t		name_len;
	size_t		ext_len;
	const char	*file_ext;

	name_len = ft_strlen_s(filename);
	ext_len = ft_strlen_s(extension);
	if (name_len <= ext_len)
	{
		write(STDERR_FILENO, ERROR_NOT_TARGET_FILE_EXTENSION, \
			sizeof(ERROR_NOT_TARGET_FILE_EXTENSION) - 1);
		return (false);
	}
	file_ext = filename + (name_len - ext_len);
	if (ft_strncmp(file_ext, extension, ext_len) == 0)
		return (true);
	else
	{
		write(STDERR_FILENO, ERROR_NOT_TARGET_FILE_EXTENSION, \
			sizeof(ERROR_NOT_TARGET_FILE_EXTENSION) - 1);
		return (false);
	}
}
