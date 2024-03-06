/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:36:35 by hsawamur          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/05 19:51:02 by erin             ###   ########.fr       */
=======
/*   Updated: 2024/03/06 14:18:04 by erin             ###   ########.fr       */
>>>>>>> 84d2404
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

# include "define.h"
# include <stdbool.h>

# define MIN_DIRECTION (-1.0)
# define MAX_DIRECTION (1.0)

# define ERROR_NOT_CORRECT_SIZE "Error: Incorrect number of parameters.\n"
# define ERROR_NOT_MEMORY_ALLOCATED "Error: Memory allocation failed.\
Please close other applications and try again.\n"

double		convert_string_to_double_in_range(const char *string, \
											double min, \
											double max, \
											bool *result);
uint8_t		convert_string_to_unint8_in_range(const char *value, \
												uint8_t min, \
												uint8_t max, \
												bool *result);
t_rgb		convert_value_to_rgb(const char *value, bool *result);
t_vector	convert_value_to_vector_in_range(const char *value, \
												double min, \
												double max, \
												bool *result);
size_t		get_string_array_size(char **array);
t_vector	convert_value_to_normal_vector(const char *value, bool *result);
void		error_message(char *error_message, bool *result);

#endif
