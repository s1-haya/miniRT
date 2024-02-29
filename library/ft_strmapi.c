/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:25:15 by hsawamur          #+#    #+#             */
/*   Updated: 2023/01/23 16:29:34 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	i;

	if (!s || !f)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	i = 0;
	if (res == NULL)
		return (NULL);
	while (s[i])
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

// char	ft_toupper(unsigned int n, char c)
// {
// 	if (('a' <= c && c <= 'z') && (n % 3 == 0))
// 	{
// 		c -= 'a' - 'A';
// 	}
// 	return (c);
// }

// #include "string.h"
// #include "stdio.h"
// int main (void)
// {
// 	printf("ft_strmapi()   %s\n", ft_strmapi("abcdefghi", ft_toupper));
// 	return (0);
// }