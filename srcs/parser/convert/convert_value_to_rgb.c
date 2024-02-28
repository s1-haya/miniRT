/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_value_to_rgb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:27:15 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/26 17:53:55 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#define DELMITER_CHAR ','
#define ERROR_NOT_MEMORY_ALLOCATED "Error: Memory allocation failed.\
 Please close other applications and try again.\n"
#define ERROR_NOT_CORRECT_SIZE "Error: parameter size do not correct\n"
#define UINT8_MIN (0)

char	**ft_split(char const *str, char c);
void	delete_value(char **value);
uint8_t	convert_string_to_unint8_in_range(const char *value,
			uint8_t min, uint8_t max, bool *result);
size_t	get_string_array_size(char **array);

t_rgb	convert_value_to_rgb(const char *value, bool *result)
{
	char	**value_rgb;
	t_rgb	rgb;

	value_rgb = ft_split(value, DELMITER_CHAR);
	if (*result == false || value_rgb == NULL
		|| get_string_array_size(value_rgb) != 3)
	{
		if (value_rgb == NULL)
			write(STDERR_FILENO, ERROR_NOT_MEMORY_ALLOCATED,
				sizeof(ERROR_NOT_MEMORY_ALLOCATED) - 1);
		else if (get_string_array_size(value_rgb) != 3)
			write(STDERR_FILENO, ERROR_NOT_CORRECT_SIZE,
				sizeof(ERROR_NOT_CORRECT_SIZE) - 1);
		*result = false;
		rgb.red = 0;
		delete_value(value_rgb);
		return (rgb);
	}
	rgb.red = convert_string_to_unint8_in_range(value_rgb[0],
			UINT8_MIN, UINT8_MAX, result);
	rgb.green = convert_string_to_unint8_in_range(value_rgb[1],
			UINT8_MIN, UINT8_MAX, result);
	rgb.blue = convert_string_to_unint8_in_range(value_rgb[2],
			UINT8_MIN, UINT8_MAX, result);
	delete_value(value_rgb);
	return (rgb);
}
