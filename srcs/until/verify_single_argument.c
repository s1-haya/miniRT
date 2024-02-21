/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_single_argument.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:14:23 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/21 18:32:00 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#define ERROR_INCORRCT_NUMBER_OF_ARGUMENTS "Error: \
Incorrect number of arguments. Usage: ./miniRT <filename>"

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
