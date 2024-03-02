/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameter_count.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:39:37 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/02 08:50:33 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <unistd.h>
#include <stdio.h>

#define MAX_PRAMTER_COUNT (1)
#define ERROR_EXCEEDS_MAX_LIMIT "Error: \
parameter exceeds the maximum limit of 1.\
Please do so in just one line, \
If you are setting an identifier with uppercase characters\n"
#define ERROR_NOT_SET_UPEER_CHARACTER "Error: Prameter don't set. \
parameter of upeer character must be set, please."

t_param_count	init_parameter_count()
{
	t_param_count	parameter_count;

	parameter_count.ambient = 0;
	parameter_count.camera = 0;
	parameter_count.light = 0;
	return (parameter_count);
}

void	printf_param_count(t_param_count parameter_count)
{
	printf("ambient: %zu, ", parameter_count.ambient);
	printf("camera:  %zu, ", parameter_count.camera);
	printf("light:   %zu\n", parameter_count.light);
}

void	check_parameter_count(t_param_count parameter_count, bool *result)
{
	if (*result && (parameter_count.ambient > MAX_PRAMTER_COUNT
		|| parameter_count.camera > MAX_PRAMTER_COUNT
		|| parameter_count.light > MAX_PRAMTER_COUNT))
	{
		write(STDERR_FILENO, ERROR_EXCEEDS_MAX_LIMIT, sizeof(ERROR_EXCEEDS_MAX_LIMIT) - 1);
		*result = false;
	}
}

void	check_set_parameter(t_param_count parameter_count, bool *result)
{
	if (parameter_count.ambient == 0
		|| parameter_count.camera == 0
		|| parameter_count.light == 0)
	{
		write(STDERR_FILENO, ERROR_NOT_SET_UPEER_CHARACTER,
			sizeof(ERROR_NOT_SET_UPEER_CHARACTER) - 1);
		*result = false;
	}
}

