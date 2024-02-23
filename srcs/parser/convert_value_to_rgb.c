/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_value_to_rgb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:27:15 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/23 16:20:07 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#define DELMITER_CHAR ','
#define MIN (0)
#define MAX (255)
#define ERROR (0xFF)
#define ERROR_NOT_IN_RANGE "Error: The value is not within the allowed range.\n"
#define ERROR_NULL_STRING "Error: The string is NULL.\n"

char	**ft_split(char const *str, char c);
double	ft_strtod(const char *str, char **endptr);
void	delete_value(char **value);
double convert_string_to_double_in_range(const char *string,
										 double min,
										 double max,
										 bool *result);

uint8_t	convert_string_to_unint8_in_range(const char *value,
												uint8_t min,
												uint8_t max,
												bool *result)
{
	double	value_double;
	char	*end;

	if (value == NULL)
	{
		write(STDERR_FILENO, ERROR_NULL_STRING, sizeof(ERROR_NULL_STRING) - 1);
		*result = false;
		return (ERROR);
	}
	value_double = ft_strtod(value, &end);
	if (*end != '\0' || value_double < min || max < value_double)
	{
		write(STDERR_FILENO, ERROR_NOT_IN_RANGE, sizeof(ERROR_NOT_IN_RANGE) - 1);
		*result = false;
		return (ERROR);
	}
	return ((uint8_t)value_double);	
}


t_rgb	convert_value_to_rgb(const char *value, bool *result)
{
	char	**value_rgb;
	t_rgb	rgb;

	value_rgb = ft_split(value, DELMITER_CHAR);
	if (value_rgb == NULL)
	{
		*result = false;
		rgb.red = ERROR;
		return (rgb);
	}
	rgb.red = convert_string_to_unint8_in_range(value_rgb[0], MIN, MAX, result);
	rgb.green = convert_string_to_double_in_range(value_rgb[1], MIN, MAX, result);
	rgb.blue = convert_string_to_double_in_range(value_rgb[2], MIN, MAX, result);
	delete_value(value_rgb);
	return (rgb);
}
