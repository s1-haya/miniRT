/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_error_and_return_null.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:05:16 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/05 19:41:32 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*set_error_and_return_null(bool *result)
{
	*result = false;
	return (NULL);
}
