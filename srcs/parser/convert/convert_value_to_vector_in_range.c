/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_value_to_vector_in_range.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:20:31 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/13 13:53:21 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "render_scene.h"
#include <stdbool.h>
#include <unistd.h>

#define DELMITER_CHAR ','
#define MIN_NORMAL (-1.0)
#define MAX_NORMAL (1.0)
#define ERROR_NOT_MEMORY_ALLOCATED "Error:\nMemory allocation failed.\
Please close other applications and try again.\n"
#define ERROR_NOT_CORRECT_SIZE "Error: Incorrect number of parameters.\n"
#define ERROR_NOT_UNIT_VECTOR "Error:\nThe vector is not a unit vector.\n"

void	error_message(char *error_message, bool *result);
void	*get_null_error_message(char *message, bool *result);
char	**ft_split(char const *str, char c);
void	delete_value(char **value);
double	convert_string_to_double_in_range(const char *string,
			double min, double max, bool *result);
size_t	get_string_array_size(char **array);
char	**check_delimiter_value(const char *value,
			char delimiter_char, bool *result);

static t_vector	convert_value_to_vector_in_range_until(char **value_vector,
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
	value_vector = check_delimiter_value(value, DELMITER_CHAR, result);
	if (value_vector == NULL)
		return (vector);
	vector = convert_value_to_vector_in_range_until(value_vector,
			min, max, result);
	delete_value(value_vector);
	return (vector);
}

static void	convert_value_to_normal_vector_until(t_vector *vector, bool *result)
{
	if (vector_length(*vector) < 1.0 - C_EPSILON || \
		1.0 + C_EPSILON < vector_length(*vector))
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
	value_vector = check_delimiter_value(value, DELMITER_CHAR, result);
	if (value_vector == NULL)
		return (vector);
	vector = convert_value_to_vector_in_range_until(value_vector,
			MIN_NORMAL, MAX_NORMAL, result);
	delete_value(value_vector);
	convert_value_to_normal_vector_until(&vector, result);
	return (vector);
}
