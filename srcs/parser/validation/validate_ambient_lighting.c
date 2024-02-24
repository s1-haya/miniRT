/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ambient_lighting.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:38:29 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/24 11:15:31 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

#define MIN_AMBIENT_LIGHT (0.0)
#define MAX_AMBIENT_LIGHT (1.0)

void validate_ambient_lighting(char **value, bool *result)
{
	if (get_string_array_size(value) != 2)
	{
		*result = false;
		return;
	}
	convert_string_to_double_in_range(value[0], MIN_AMBIENT_LIGHT,
										MAX_AMBIENT_LIGHT, result);
	convert_value_to_rgb(value[1], result);
}
