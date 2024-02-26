/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_value_to_vector_in_range.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:20:31 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/26 17:45:29 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdbool.h>
#include <unistd.h>

#define DELMITER_CHAR ','
#define ERROR_NOT_MEMORY_ALLOCATED "Error: Memory allocation failed.\
						Please close other applications and try again.\n"

char	**ft_split(char const *str, char c);
void	delete_value(char **value);
double	convert_string_to_double_in_range(const char *string,
			double min, double max, bool *result);
size_t	get_string_array_size(char **array);

t_vector	convert_value_to_vector_in_range(const char *value,
			double min, double max, bool *result)
{
	char		**value_vector;
	t_vector	vector;

	value_vector = ft_split(value, DELMITER_CHAR);
	if (*result == false || value_vector == NULL 
		|| get_string_array_size(value_vector) != 3)
	{
		if (value_vector == NULL)
			write(STDERR_FILENO, ERROR_NOT_MEMORY_ALLOCATED,
				sizeof(ERROR_NOT_MEMORY_ALLOCATED) - 1);
		vector.x = 0;
		delete_value(value_vector);
		*result = false;
		return (vector);
	}
	vector.x = convert_string_to_double_in_range(value_vector[0],
			min, max, result);
	vector.y = convert_string_to_double_in_range(value_vector[1],
			min, max, result);
	vector.z = convert_string_to_double_in_range(value_vector[2],
			min, max, result);
	delete_value(value_vector);
	return (vector);
}
