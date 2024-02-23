/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:36:35 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/23 17:53:28 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H
#include "color.h"
#include "vector.h"
#include <stdbool.h>
#include <stdlib.h>

double		convert_string_to_double_in_range(const char *string,
										 double min,
										 double max,
										 bool *result);
uint8_t		convert_string_to_unint8_in_range(const char *value,
												uint8_t min,
												uint8_t max,
												bool *result);
t_rgb		convert_value_to_rgb(const char *value, bool *result);
t_vector	convert_value_to_vector_in_range(const char *value,
												double min,
												double max,
												bool *result);
size_t		get_string_array_size(char **array);

#endif
