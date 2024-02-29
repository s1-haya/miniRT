/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:01:19 by hsawamur          #+#    #+#             */
/*   Updated: 2023/01/24 19:21:27 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*copy_dst;
	const unsigned char	*copy_src;

	if (!dst && !src)
		return (NULL);
	copy_dst = (unsigned char *)dst;
	copy_src = (const unsigned char *)src;
	if (dst <= src)
	{
		while (0 < n--)
			*copy_dst++ = *copy_src++;
	}
	else
	{
		copy_dst += n;
		copy_src += n;
		while (0 < n--)
			*--copy_dst = *--copy_src;
	}
	return (copy_dst);
}

// #include <string.h>
// int main(void)
// {
// 	char str1[50];
// 	// char str3[50];
// 	char str2[50] = "mahmudul hasan";
// 	char *ret;
// 	// char *ret2;

// 	ret = memmove(NULL, NULL, 11);
// 	// ret2 = ft_memmove(str3, str2, 11);
// 	printf("%s\n", ret);
// 	// printf("%s\n", ret2);
// 	return (0);
// }