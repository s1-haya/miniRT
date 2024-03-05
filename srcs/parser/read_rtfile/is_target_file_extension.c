/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_target_file_extension.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 08:28:45 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/05 12:30:32 by hsawamur         ###   ########.fr       */
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

void	error_message(char *error_message, bool *result);

bool	is_target_file_extension(const char *filename, const char *extension)
{
	const char	*dot;
	bool		result;

	result = false;
	if (!filename || !extension)
		return (result);
	dot = ft_strchr(filename, '.');
	if (dot == NULL || dot == filename)
	{
		error_message(ERROR_NOT_TARGET_FILE_EXTENSION, result);
		return (result);
	}
	result = ft_strncmp(dot, extension, ft_strlen(extension) + 1) == 0;
	if (result == false)
		error_message(ERROR_NOT_TARGET_FILE_EXTENSION, result);
	return (result);
}
