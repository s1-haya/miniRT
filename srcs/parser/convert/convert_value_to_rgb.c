/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_value_to_rgb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:27:15 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/13 13:54:42 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "parser.h"

#define ERROR_NOT_MEMORY_ALLOCATED "Error:\nMemory allocation failed.\
 Please close other applications and try again.\n"
#define ERROR_NOT_CORRECT_SIZE "Error:\nIncorrect number of parameters.\n"
#define UINT8_MIN (0)

void	error_message(char *error_message, bool *result);
char	**ft_split(char const *str, char c);
void	delete_value(char **value);
uint8_t	convert_string_to_unint8_in_range(const char *value,
			uint8_t min, uint8_t max, bool *result);
size_t	get_string_array_size(char **array);
char	**check_delimiter_value(const char *value,
			char delimiter_char, bool *result);

t_rgb	convert_value_to_rgb_until(char **value_rgb, bool *result)
{
	t_rgb	rgb;

	rgb.red = convert_string_to_unint8_in_range(value_rgb[0],
			UINT8_MIN, UINT8_MAX, result);
	rgb.green = convert_string_to_unint8_in_range(value_rgb[1],
			UINT8_MIN, UINT8_MAX, result);
	rgb.blue = convert_string_to_unint8_in_range(value_rgb[2],
			UINT8_MIN, UINT8_MAX, result);
	return (rgb);
}

t_rgb	convert_value_to_rgb(const char *value, bool *result)
{
	char	**value_rgb;
	t_rgb	rgb;

	rgb.red = 0;
	if (*result == false)
		return (rgb);
	value_rgb = check_delimiter_value(value, DELMITER_CHAR, result);
	if (value_rgb == NULL)
		return (rgb);
	rgb = convert_value_to_rgb_until(value_rgb, result);
	delete_value(value_rgb);
	return (rgb);
}
