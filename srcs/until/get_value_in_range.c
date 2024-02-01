/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_in_range.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:10:49 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/01 18:15:54 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	get_value_in_range(double v, double v_min, double v_max)
{
	if (v < v_min)
		return (v_min);
	else if (v_max < v)
		return (v_max);
	return (v);
}
