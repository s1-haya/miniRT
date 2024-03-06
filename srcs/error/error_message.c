/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:40:18 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/06 15:02:08 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

size_t	ft_strlen(const char *str);

void	error_message(char *error_message, bool *result)
{
	write(STDERR_FILENO, error_message, \
			ft_strlen(error_message));
	*result = false;
}
