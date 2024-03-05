/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_single_argument.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:14:23 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/05 19:44:51 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	verify_single_argument(int argc)
{
	if (argc == 1 || argc > 2)
	{
		write(STDERR_FILENO,
			ERROR_INCORRCT_NUMBER_OF_ARGUMENTS,
			sizeof(ERROR_INCORRCT_NUMBER_OF_ARGUMENTS) - 1);
		return (false);
	}
	return (true);
}
