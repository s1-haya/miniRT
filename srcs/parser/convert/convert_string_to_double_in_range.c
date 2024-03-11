/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string_to_double_in_range.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:01:33 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/11 13:48:06 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR (0.0)
#define ERROR_NOT_RANGE "Error:\nThe value is not within the allowed range.\n"
#define ERROR_NULL_STRING "Error:\nThe string is NULL.\n"

void	error_message(char *error_message, bool *result);
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
		error_message(ERROR_NULL_STRING, result);
		return (ERROR);
	}
	value = ft_strtod(string, &endptr);
	if (value == HUGE_VAL || value == -HUGE_VAL)
	{
		perror("Error:\n");
		*result = false;
		return (ERROR);
	}
	if (*result && ((*endptr != '\0' && *endptr != '\n') \
		|| value < min || max < value))
	{
		error_message(ERROR_NOT_RANGE, result);
		return (ERROR);
	}
	return (value);
}
