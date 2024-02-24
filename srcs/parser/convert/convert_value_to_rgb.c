/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_value_to_rgb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:27:15 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/24 11:43:14 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <stdbool.h>
#include <stdlib.h>

#define DELMITER_CHAR ','
#define MIN (0)
#define MAX (255)


char	**ft_split(char const *str, char c);
void	delete_value(char **value);
uint8_t	convert_string_to_unint8_in_range(const char *value,
												uint8_t min,
												uint8_t max,
												bool *result);

t_rgb	convert_value_to_rgb(const char *value, bool *result)
{
	char	**value_rgb;
	t_rgb	rgb;

	value_rgb = ft_split(value, DELMITER_CHAR);
	if (value_rgb == NULL)
	{
		*result = false;
		rgb.red = 0;
		delete_value(value_rgb);
		return (rgb);
	}
	rgb.red = convert_string_to_unint8_in_range(value_rgb[0], MIN, MAX, result);
	rgb.green = convert_string_to_unint8_in_range(value_rgb[1], MIN, MAX, result);
	rgb.blue = convert_string_to_unint8_in_range(value_rgb[2], MIN, MAX, result);
	delete_value(value_rgb);
	return (rgb);
}
