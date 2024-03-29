/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string_to_unint8_in_range.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:16:54 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/11 13:48:06 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>

#define ERROR (0xFF)
#define ERROR_VALUE_RANGE "Error:\nThe value is not within the allowed range.\n"
#define ERROR_NULL_STRING "Error:\nThe string is NULL.\n"

void	error_message(char *error_message, bool *result);
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
		error_message(ERROR_NULL_STRING, result);
		return (ERROR);
	}
	value_double = ft_strtod(value, &end);
	if (*result && (*end != '\0' || (uint8_t)value_double != value_double \
		|| value_double < min || max < value_double))
	{
		error_message(ERROR_VALUE_RANGE, result);
		return (ERROR);
	}
	return ((uint8_t)value_double);
}
