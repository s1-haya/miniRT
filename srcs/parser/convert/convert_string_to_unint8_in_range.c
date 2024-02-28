/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string_to_unint8_in_range.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:16:54 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/27 15:18:26 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>

#define ERROR (0xFF)
#define ERROR_VALUE_RANGE "Error: The value is not within the allowed range.\n"
#define ERROR_NULL_STRING "Error: The string is NULL.\n"

double	ft_strtod(const char *str, char **endptr);

uint8_t	convert_string_to_unint8_in_range(const char *value,
						uint8_t min, uint8_t max, bool *result)
{
	double	value_double;
	char	*end;

	if (result == false)
		return (ERROR);
	if (value == NULL)
	{
		write(STDERR_FILENO, ERROR_NULL_STRING, sizeof(ERROR_NULL_STRING) - 1);
		*result = false;
		return (ERROR);
	}
	value_double = ft_strtod(value, &end);
	if (*end != '\0' || value_double < min || max < value_double
		|| (uint8_t)value_double != value_double)
	{
		write(STDERR_FILENO, ERROR_VALUE_RANGE, sizeof(ERROR_VALUE_RANGE) - 1);
		*result = false;
		return (ERROR);
	}
	return ((uint8_t)value_double);
}
