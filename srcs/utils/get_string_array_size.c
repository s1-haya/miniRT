/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_array_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:13:16 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/06 14:02:36 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	get_string_array_size(char **array)
{
	size_t	size;

	size = 0;
	while (array[size] != NULL)
		size++;
	return (size);
}
