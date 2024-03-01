/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:21:48 by hsawamur          #+#    #+#             */
/*   Updated: 2023/01/16 16:12:24 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*c_s1;
	unsigned char	*c_s2;

	i = 0;
	if (!n)
		return (0);
	c_s1 = (unsigned char *)s1;
	c_s2 = (unsigned char *)s2;
	while (c_s1[i] == c_s2[i])
	{
		i++;
		if (n == i)
			return (0);
	}
	return (c_s1[i] - c_s2[i]);
}

// int main(void)
// {
// 	char str[] = "ffaga";
//     char str2[] = "libft-test-tokyo";
//     // char str[] = "abcdeff";
//     printf("memcmp()      %d\n",memcmp(str,"abcdef",16));
//     printf("ft_memcmp()   %d\n",ft_memcmp(str,"abcdef",16));
//     printf("memcmp()      %d\n",memcmp(str2,"libft-test-tokyo",30));
//     printf("ft_memcmp()   %d\n",ft_memcmp(str2,"libft-test-tokyo",30));
//     return 0;
// }