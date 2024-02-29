/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:04:05 by hsawamur          #+#    #+#             */
/*   Updated: 2023/01/16 16:06:08 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	if (!*needle)
		return ((char *)haystack);
	k = 0;
	while (k < len && haystack[k])
	{
		i = 0;
		while (k < len && needle[i] && haystack[k] && needle[i] == haystack[k])
		{
			++i;
			++k;
		}
		k = k - i;
		if (needle[i] == '\0')
			return ((char *)&haystack[k]);
		k += 1;
	}
	return (NULL);
}

// int main()
// {
//     char a[] = "aiueo";
// 	const char haystack[] = "abcdefg";
// 	const char needle[] = "";
// 	char *ret;
// 	printf("[%s]\n", strnstr("", "", 0));
// 	printf("[%p]\n", strnstr(NULL, "is", 0));
// 	printf("[%p]\n", strnstr("abbbcdefg", "bbc", 20) );
// 	printf("[%s]\n", ft_strnstr("", "", 0));
// 	printf("[%p]\n", ft_strnstr(NULL, "is", 0));
// 	printf("[%p]\n", ft_strnstr("abbbcdefg", "bbc", 20) );
// 	// printf("[%p]\n", strnstr(NULL, "1", 1));
// 	ret = strnstr(haystack, needle, 5);
// 	printf("strnstr %s\n",ret);
// 	printf("strnstr %s\n",needle);
//     printf("%s : %s\n", strnstr(a, "u", 3), ft_strnstr(a, "u", 3));
//     printf("%s : %s\n", strnstr(a, "a", 6), ft_strnstr(a, "a", 6));
//     printf("%s : %s\n", strnstr(a, "u", 6), ft_strnstr(a, "u", 6));
//     printf("%s : %s\n", strnstr(a, "eui", 6), ft_strnstr(a, "eui", 6));
//     printf("%s : %s\n", strnstr(a, "ie", 6), ft_strnstr(a, "ie", 6));
//     printf("%s : %s\n", strnstr(a, "uo", 6), ft_strnstr(a, "uo", 6));
//     return (0);
// }