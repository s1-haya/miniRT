/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:39:11 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/24 11:14:26 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

void	validate_cylinder(char **value, bool *result)
{
	size_t	size;

	size = get_string_array_size(value);
	if (size != 5)
	{
		*result = false;
		return ;
	}
	convert_value_to_vector_in_range(value[0], INT_MIN,
										INT_MAX, result);
	convert_value_to_vector_in_range(value[1], MIN_DIRECTION,
										MAX_DIRECTION, result);
	convert_string_to_double_in_range(value[2], INT_MIN,
										INT_MAX, result);
	convert_string_to_double_in_range(value[3], INT_MIN,
										INT_MAX, result);
	convert_value_to_rgb(value[4], result);
}
