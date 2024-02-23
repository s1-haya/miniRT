/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_target_file_extension.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 08:28:45 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/21 11:43:47 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <string.h>
#include "libft.h"

# define SUCCESS 0
# define FAILURE 1

// bool	is_target_file_extension(const char *filename, const char *extension)
// {
// 	const char	*dot;

// 	if (!filename || !extension || *filename == '.' || *extension != '.')
// 		return (false);
// 	dot = ft_strrchr(filename, '.');
// 	if (!dot || dot == filename)
// 		return (false);
// 	return (ft_strncmp(dot, extension, ft_strlen(dot)) == 0);
// }

#include <stdio.h>

bool is_target_file_extension(const char *filename, const char *extension) {
	const char *dot;

	if (!filename || !extension)
		return (false);
	dot = ft_strrchr(filename, '.');
	if (dot == NULL || dot == filename)
		return (false);
	return (ft_strncmp(dot, extension, ft_strlen(extension) + 1) == 0);
}