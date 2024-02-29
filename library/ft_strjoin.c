/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:55:13 by hsawamur          #+#    #+#             */
/*   Updated: 2023/02/08 22:37:42 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat_len(char *dst, const char *src, size_t d_len)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_res;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	else
	{
		len_res = ft_strlen(s1) + ft_strlen(s2);
		res = (char *)ft_calloc(sizeof(char), len_res + 1);
		if (res == NULL)
			return (NULL);
		while (*s1)
			*res++ = *s1++;
		while (*s2)
			*res++ = *s2++;
		// res = ft_strcat_len(res, s1, 0);
		// res = ft_strcat_len(res, s2, ft_strlen(s1));
	}
	return (res);
}

// #include "stdio.h"
// int main()
// {
// 	char str[] = "";
// 	char str2[] = "fghijk";
// 	printf("ft_strjoin()   %s\n", ft_strjoin(str, str2));
// 	printf("ft_strjoin()   %s\n", ft_strjoin(str, NULL));
// 	printf("ft_strjoin()   %s\n", ft_strjoin(NULL, str2));
// 	printf("ft_strjoin()   %s\n", ft_strjoin(NULL, NULL));
// }

//ft_bzero()
//ft_calloc()