/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string_to_double_in_range.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:01:33 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/01 17:53:09 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR (0.0)
#define ERROR_NOT_RANGE "Error: The value is not within the allowed range.\n"
#define ERROR_NULL_STRING "Error: The string is NULL.\n"

double	ft_strtod(const char *str, char **endptr);

double	convert_string_to_double_in_range(const char *string,
							double min, double max, bool *result)
{
	double	value;
	char	*endptr;

	if (*result == false)
		return (ERROR);
	if (string == NULL)
	{
		write(STDERR_FILENO, ERROR_NULL_STRING, sizeof(ERROR_NULL_STRING) - 1);
		*result = false;
		return (ERROR);
	}
	value = ft_strtod(string, &endptr);
	if (value == HUGE_VAL || value == -HUGE_VAL)
	{
		perror("Error: ");
		*result = false;
		return (ERROR);
	}
	if ((*endptr != '\0' && *endptr != '\n') || value < min || max < value)
	{
		write(STDERR_FILENO, ERROR_NOT_RANGE, sizeof(ERROR_NOT_RANGE) - 1);
		*result = false;
		return (ERROR);
	}
	return (value);
}
