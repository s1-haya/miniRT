/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:40:24 by hsawamur          #+#    #+#             */
/*   Updated: 2023/01/15 20:04:14 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*p == (unsigned char)c)
			return (p);
		i++;
		p++;
	}
	return (NULL);
}

// int main(void)
// {
// 	char data[] = "Learning Lad Rocks";
// 	unsigned char *pos = memchr(data, 'a', 4);
// 	printf("%s\n", pos);
// 	unsigned char *pos2 = ft_memchr(data, 'a', 4);
// 	printf("%s\n", pos2);
// }
