/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:37:51 by hsawamur          #+#    #+#             */
/*   Updated: 2023/01/14 14:20:28 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
	{
		*p++ = '\0';
	}
}

// int main(void)
// {
// 	char str[] = "0123456789";
// 	// printf("%s\n",str+2);
// 	// printf("%c\n", *str+1);
// 	// printf("%s\n",str+5);
// 	// printf("%c\n", *str+2);
// 	printf("%s\n", str);
// 	ft_bzero(str+2, 3);
// 	int i;

// 	i = 0;
// 	while (str[i] != '\0'){
// 		i++;
// 	}
// 	printf("%d\n", i);
// 	printf("%s\n", str);
// 	// ft_memset(str+2, '-', 5);
// 	// printf("%s\n",str);

// 	return 0;
// }