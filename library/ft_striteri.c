/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:25:20 by hsawamur          #+#    #+#             */
/*   Updated: 2023/01/23 14:33:15 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}	
}

// int	ft_tolower(int c)
// {
// 	if ('a' <= c && c <= 'z')
// 	{
// 		c += 'a' + 'A';
// 	}
// 	return (c);
// }

// void	ft_i(unsigned int n, char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	if (n % 3 == 0 && !s[i])
// 	{
// 		s[i] = ft_tolower(s[i]);
// 		i++;
// 	}
// }