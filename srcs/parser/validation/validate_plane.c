/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:39:33 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/24 11:13:58 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

void	validate_plane(char **value, bool *result)
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
	convert_value_to_vector_in_range(value[1], MIN_DIRECTION,
										MAX_DIRECTION, result);
	convert_value_to_rgb(value[2], result);
}
