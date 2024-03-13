/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_null_error_message.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:05:16 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/13 12:13:08 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

void	error_message(char *error_message, bool *result);

void	*get_null_error_message(char *message, bool *result)
{
	error_message(message, result);
	return (NULL);
}
