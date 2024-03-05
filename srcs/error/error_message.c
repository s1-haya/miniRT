/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:40:18 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/05 19:55:19 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	error_message(char *error_message, bool *result)
{
	write(STDERR_FILENO, error_message, \
			ft_strlen(error_message) - 1);
	*result = false;
}
