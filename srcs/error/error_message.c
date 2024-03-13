/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:40:18 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/13 10:21:02 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

size_t	ft_strlen(const char *str);

void	error_message(char *error_message, bool *result)
{
	write(STDERR_FILENO, error_message, \
			ft_strlen(error_message) + 1);
	*result = false;
}
