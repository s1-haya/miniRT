/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string_double_in_range.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:01:33 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/22 18:34:25 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define ERROR (0.0)
#define ERROR_NOT_IN_RANGE "Error: The value is not within the allowed range."

double convert_string_to_double_in_range(char *string,
										 double min,
										 double max,
										 bool *result)
{
	double value;
	char *endptr;

	value = strtod(string, &endptr);
	if (value == HUGE_VAL || value == -HUGE_VAL)
	{
		perror("Error: ");
		*result = false;
		return (ERROR);
	}
	if (value < min || max < value)
	{
		write(STDERR_FILENO, ERROR_NOT_IN_RANGE, sizeof(ERROR_NOT_IN_RANGE) - 1)
		*result = false;
		return (ERROR);
	}
	return (value);
}
