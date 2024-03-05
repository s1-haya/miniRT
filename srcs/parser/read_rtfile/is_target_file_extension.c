/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_target_file_extension.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 08:28:45 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/04 19:51:11 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "libft.h"

# define SUCCESS (0)
# define FAILURE (1)
# define ERROR_NOT_TARGET_FILE_EXTENSION "Error: Incorrect filename \
Please check the file you have entered. The file extension must be .ft.\n"
#include <libc.h>

bool is_target_file_extension(const char *filename, const char *extension)
{
	const char *dot;
	bool		result;

	result = false;
	if (!filename || !extension)
		return (result);
	dot = ft_strchr(filename, '.');
	if (dot == NULL || dot == filename)
	{
		write(STDERR_FILENO, ERROR_NOT_TARGET_FILE_EXTENSION,
				sizeof(ERROR_NOT_TARGET_FILE_EXTENSION) - 1);
		return (result);
	}
	result = ft_strncmp(dot, extension, ft_strlen(extension) + 1) == 0;
	if (!result)
		write(STDERR_FILENO, ERROR_NOT_TARGET_FILE_EXTENSION,
				sizeof(ERROR_NOT_TARGET_FILE_EXTENSION) - 1);
	return (result);
}
