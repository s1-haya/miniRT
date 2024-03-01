/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:59:36 by hsawamur          #+#    #+#             */
/*   Updated: 2023/01/23 12:41:58 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	max;

	src_len = ft_strlen(src);
	if (!dstsize)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	i = 0;
	max = dstsize - dst_len - 1;
	while (i < max && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}

// int main(void)
// {
// 	const char src1[10]	= "ab";
// 	char dest1[10]   = "123";

// 	char src[10]	= "ab";
// 	char dest[10]	= "123";

// 	size_t 			nb = 2;
// 	unsigned int 	nb2 = 2;
// 	//strcat(src, dest);
// 	printf("Str: %ld \n", strlcat(dest1, src1, nb));
// 	printf("Str: %zu", ft_strlcat(dest, src, nb2));
// 	return (0);
// }