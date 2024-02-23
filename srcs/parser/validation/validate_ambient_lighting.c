/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ambient_lighting.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:38:29 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/23 16:27:33 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <stdbool.h>
#include <stdlib.h>

// 環境光の適用範囲 [0.0,1.0] 浮動小数点の型を統一するためdouble型
// R,G,Bの色の適用範囲 [0-255] unsigned char型
#define MIN (0.0)
#define MAX (1.0)

double convert_string_to_double_in_range(const char *string,
										double min,
										double max,
										bool *result);
t_rgb	convert_value_to_rgb(const char *value, bool *result);

void	validate_ambient_lighting(char **value, bool *result)
{
	if (value[2] != NULL)
	{
		*result = false;
		return ;
	}
	convert_string_to_double_in_range(value[0], MIN, MAX, result);
	convert_value_to_rgb(value[1], result);
}
