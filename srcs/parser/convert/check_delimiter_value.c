/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_delimiter_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:54:32 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/13 13:44:49 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#define DELMITER_CHAR ','
#define ERROR_INVALID_DELIMITER "Error:\nInvalid delimiter value\n"
#define ERROR_NOT_MEMORY_ALLOCATED "Error:\nMemory allocation failed.\
 Please close other applications and try again.\n"
#define ERROR_NOT_CORRECT_SIZE "Error:\nIncorrect number of parameters.\n"

static bool	is_valid_delimiter_string(const char *value, char delimiter_char)
{
	bool	is_invalid_delimiter;

	if (value == NULL || *value == delimiter_char)
		return (false);
	is_invalid_delimiter = false;
	while (*value != '\0')
	{
		if (*value == delimiter_char)
		{
			if (is_invalid_delimiter)
				return (false);
			is_invalid_delimiter = true;
		}
		else
			is_invalid_delimiter = false;
		value ++;
	}
	return (true);
}

char	**check_delimiter_value(const char *value,
							char delimiter_char, bool *result)
{
	char	**value_arr;

	if (!is_valid_delimiter_string(value, delimiter_char))
		return (get_null_error_message(ERROR_INVALID_DELIMITER, result));
	value_arr = ft_split(value, DELMITER_CHAR);
	if (value_arr == NULL)
		return (get_null_error_message(ERROR_NOT_MEMORY_ALLOCATED, result));
	if (get_string_array_size(value_arr) != 3)
	{
		delete_value(value_arr);
		return (get_null_error_message(ERROR_NOT_CORRECT_SIZE, result));
	}
	return (value_arr);
}
