/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:39:42 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/24 11:13:49 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

void	validate_sphere(char **value, bool *result)
{
	size_t	size;

	size = get_string_array_size(value);
	if (size != 3)
	{
		*result = false;
		return ;
	}
	convert_value_to_vector_in_range(value[0], INT_MIN,
										INT_MAX, result);
	convert_string_to_double_in_range(value[1], INT_MIN,
										INT_MAX, result);
	convert_value_to_rgb(value[2], result);
}