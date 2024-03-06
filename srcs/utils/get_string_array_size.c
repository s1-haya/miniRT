/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_array_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:13:16 by hsawamur          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/05 20:01:33 by erin             ###   ########.fr       */
=======
/*   Updated: 2024/03/06 14:02:36 by erin             ###   ########.fr       */
>>>>>>> 84d2404
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

size_t	get_string_array_size(char **array)
{
	size_t	size;

	size = 0;
	while (array[size] != NULL)
		size++;
	return (size);
}
