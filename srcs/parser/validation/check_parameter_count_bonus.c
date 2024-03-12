/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameter_count_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:57:04 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/11 13:48:06 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <unistd.h>
#include <stdio.h>

#define MAX_PRAMTER_COUNT (1)
#define ERROR_EXCEEDS_MAX_LIMIT "Error:\n\
parameter exceeds the maximum limit of 1. \
Please do so in just one line, \
If you are setting an identifier with uppercase characters\n"
#define ERROR_NOT_SET_UPEER_CHARACTER "Error:\nPrameter don't set. \
parameter of upeer character must be set, please.\n"

void	error_message(char *error_message, bool *result);

t_param_count	init_parameter_count(void)
{
	t_param_count	parameter_count;

	parameter_count.ambient = 0;
	parameter_count.camera = 0;
	parameter_count.light = 0;
	return (parameter_count);
}

void	check_parameter_count(t_param_count parameter_count, bool *result)
{
	if (*result && (parameter_count.ambient > MAX_PRAMTER_COUNT
			|| parameter_count.camera > MAX_PRAMTER_COUNT))
		error_message(ERROR_EXCEEDS_MAX_LIMIT, result);
}

void	check_set_parameter(t_param_count parameter_count, bool *result)
{
	if (*result && (parameter_count.ambient == 0
			|| parameter_count.camera == 0
			|| parameter_count.light == 0))
		error_message(ERROR_NOT_SET_UPEER_CHARACTER, result);
}
