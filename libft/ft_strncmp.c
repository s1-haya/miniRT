/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:26:51 by hsawamur          #+#    #+#             */
/*   Updated: 2023/01/21 13:28:12 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c_s1;
	unsigned char	*c_s2;

	i = 0;
	if (!n)
		return (0);
	c_s1 = (unsigned char *)s1;
	c_s2 = (unsigned char *)s2;
	while (c_s1[i] == c_s2[i] && c_s1[i] != '\0')
	{
		i++;
		if (n == i)
			return (0);
	}
	return (c_s1[i] - c_s2[i]);
}

// int main (void) {
//     char str[] = "ffaga";
//     char str2[] = "libft-test-tokyo";
//     // char str[] = "abcdeff";
//     printf("strncmp()   %d\n",strncmp(str,"abcdef",16));
//     printf("ft_strncmp()   %d\n",ft_strncmp(str,"abcdef",16));
//     printf("strncmp()   %d\n",strncmp(str2,"li",2));
//     printf("ft_strncmp()   %d\n",ft_strncmp(str2,"li",2));
//     return 0;
// }