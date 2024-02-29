/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:25:15 by hsawamur          #+#    #+#             */
/*   Updated: 2023/01/20 13:57:55 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

// int main()
// {
//   char str[8] = "ABC";
//   char strDest[10] = "HHHHHH";
//   char str2[8] = "ABC";
//   char strDest2[10] = "HHHHHH";
//   printf("%s\n", str2);
//   printf("%s\n", strDest2);
//   int rh2 = strlcpy(strDest2, str2, 8);
//   printf("%s\n", str);
//   printf("%s\n", strDest);
//   int r2 = ft_strlcpy(strDest2, str2, 8);
// }