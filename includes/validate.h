/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:36:35 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/05 11:53:53 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

#include "scene.h"
#include "parser.h"
#include "color.h"
#include "vector.h"
#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define MIN_DIRECTION (-1.0)
#define MAX_DIRECTION (1.0)

#define ERROR_NOT_CORRECT_SIZE "Error: Incorrect number of parameters.\n"
#define ERROR_NOT_MEMORY_ALLOCATED "Error: Memory allocation failed.\
Please close other applications and try again.\n"

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
t_vector	convert_value_to_normal_vector(const char *value, bool *result);
void		error_message(char *error_message, bool *result);

#endif
