/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:59:24 by hsawamur          #+#    #+#             */
/*   Updated: 2023/01/23 15:43:25 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*copy_dst;
	const unsigned char	*copy_src;
	size_t				i;

	if (!dst && !src)
		return (dst);
	copy_dst = (unsigned char *)dst;
	copy_src = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		copy_dst[i] = copy_src[i];
		i++;
	}
	return (dst);
}

// int main(void)
// {
// 	short num1[3] = { 0x1234, 0x5678, 0x9abc };
// 	short num2[3] = { 0 };
// 	short num3[3] = { 0x1234, 0x5678, 0x9abc };
// 	short num4[3] = { 0 };

// 	//	short型×3個のバイト数をコピーする
// 	memcpy(num2, num1, sizeof(short) * 3);
// 	printf("%hx %hx %hx", num2[0], num2[1], num2[2]);

// 	//	コピー後のnum2配列を表示
// 	ft_memcpy(num4, num3, sizeof(short) * 3);
// 	printf("%hx %hx %hx", num4[0], num4[1], num4[2]);

// 	return 0;
// }