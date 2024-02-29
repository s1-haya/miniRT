/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:57:17 by hsawamur          #+#    #+#             */
/*   Updated: 2023/01/21 13:42:22 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)buf;
	i = 0;
	while (i < n)
	{
		*p++ = (unsigned char)ch;
		i++;
	}
	return (buf);
}

// int main(void)
// {
// 	char str[] = "0123456789";
// 	// printf("%s\n",str+2);
// 	// printf("%c\n", *str+1);
// 	// printf("%s\n",str+5);
// 	// printf("%c\n", *str+2);
// 	printf("%s\n", str);
// 	printf("%s\n", bzero(str+2, 3));
// 	printf("%s\n", str);
// 	ft_memset(str+2, '-', 5);
// 	// printf("%s\n",str);

// 	return 0;
// }