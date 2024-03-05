/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_value_to_vector_in_range.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:20:31 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/05 12:06:34 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdbool.h>
#include <unistd.h>

#define DELMITER_CHAR ','
#define MIN_NORMAL (-1.0)
#define MAX_NORMAL (1.0)
#define ERROR_NOT_MEMORY_ALLOCATED "Error: Memory allocation failed.\
Please close other applications and try again.\n"
#define ERROR_NOT_CORRECT_SIZE "Error: Incorrect number of parameters.\n"
#define ERROR_NOT_UNIT_VECTOR "Error: The vector is not a unit vector.\n"

void	error_message(char *error_message, bool *result);
char	**ft_split(char const *str, char c);
void	delete_value(char **value);
double	convert_string_to_double_in_range(const char *string,
			double min, double max, bool *result);
size_t	get_string_array_size(char **array);

t_vector	convert_value_to_vector_in_range_until(char **value_vector,
												double min,
												double max,
												bool *result)
{
	t_vector	vector;

	vector.x = convert_string_to_double_in_range(value_vector[0],
			min, max, result);
	vector.y = convert_string_to_double_in_range(value_vector[1],
			min, max, result);
	vector.z = convert_string_to_double_in_range(value_vector[2],
			min, max, result);
	return (vector);
}

t_vector	convert_value_to_vector_in_range(const char *value,
				double min, double max, bool *result)
{
	char		**value_vector;
	t_vector	vector;

	vector.x = 0;
	if (*result == false)
		return (vector);
	value_vector = ft_split(value, DELMITER_CHAR);
	if (value_vector == NULL)
	{
		error_message(ERROR_NOT_MEMORY_ALLOCATED, result);
		return (vector);
	}
	if (get_string_array_size(value_vector) != 3)
	{
		error_message(ERROR_NOT_CORRECT_SIZE, result);
		delete_value(value_vector);
		return (vector);
	}
	vector = convert_value_to_vector_in_range_until(value_vector,
			min, max, result);
	delete_value(value_vector);
	return (vector);
}

static void	convert_value_to_normal_vector_until(t_vector *vector, bool *result)
{
	if (vector_length(*vector) != 1.0)
	{
		error_message(ERROR_NOT_UNIT_VECTOR, result);
		*result = false;
	}
	normalize_vector(vector);
}

t_vector	convert_value_to_normal_vector(const char *value, bool *result)
{
	char		**value_vector;
	t_vector	vector;

	vector.x = 0;
	if (*result == false)
		return (vector);
	value_vector = ft_split(value, DELMITER_CHAR);
	if (value_vector == NULL)
	{
		error_message(ERROR_NOT_MEMORY_ALLOCATED, result);
		return (vector);
	}
	if (get_string_array_size(value_vector) != 3)
	{
		error_message(ERROR_NOT_CORRECT_SIZE, result);
		delete_value(value_vector);
		return (vector);
	}
	vector = convert_value_to_vector_in_range_until(value_vector,
			MIN_NORMAL, MAX_NORMAL, result);
	delete_value(value_vector);
	convert_value_to_normal_vector_until(&vector, result);
	return (vector);
}
