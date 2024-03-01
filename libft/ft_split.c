/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:57:35 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/21 09:13:22 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_all_free(char **res, size_t i)
{
	size_t	n;

	n = 0;
	while (n < i)
	{
		free(res[n]);
		res[n] = NULL;
		n++;
	}
	free(res);
	res = NULL;
	return (res);
}

static char	*ft_sepa_str(const char *str, char c)
{
	size_t		i;
	size_t		j;
	char		*res;

	j = 0;
	while (str[j] != '\0' && (c != str[j]))
		j++;
	res = malloc(sizeof(char) * (j + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < j)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static size_t	ft_arr_index(const char *str, char c)
{
	size_t	index;
	size_t	i;

	index = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == c))
			i++;
		if (str[i] == '\0')
			break ;
		while (str[i] != '\0' && (str[i] != c))
			i++;
		index++;
	}
	return (index);
}

static char	**ft_str_concat(char **res, const char *str, size_t index, char c)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		while (*str != '\0' && (c == *str))
			str++;
		if (*str == '\0')
			break ;
		else
		{
			res[i] = ft_sepa_str(str, c);
			if (res[i] == NULL)
				return (ft_all_free(res, i));
		}
		while (*str != '\0' && (c != *str))
			str++;
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *str, char c)
{
	char		**res;
	const char	*temp_str;
	size_t		index;

	if (str == NULL)
		return (NULL);
	temp_str = str;
	index = ft_arr_index(temp_str, c);
	res = malloc(sizeof(char *) * (index + 1));
	if (res == NULL)
		return (NULL);
	return (ft_str_concat(res, temp_str, index, c));
}

// #include <stdio.h>
// int main(int argc, char **argv)
// {
// 	int        i;
// 	char    **split;

// 	if (argc != 3)
// 		return (0);
// 	split = ft_split(argv[1], *argv[2]);
// 	i = 0;
// 	while (split[i] != NULL)
// 	{
// 		printf("split[%d]: %s\n", i, split[i]);
// 		i ++;
// 	}
// 	i = 0;
// 	// while (split[i] != NULL)
// 	// {
// 	// 	free(split[i]);
// 	// 	i ++;
// 	// }
// 	// "KsQz   C1ur3Qe5gPYyzML9QFcOzKSe2ug" "zL39wb"
// 	// "          " "  "
// 	// "QOvWt     VVtyInMPhSF","EInr8"
// 	return (0);
// }

// // int main(void)
// // {
// // 	printf("index   %d\n", ft_arr_index("fafafBbafagagBaabbcc", 'b'));
// // 	printf("index   %d\n", ft_arr_index("aabbcc", 'b'));
// // 	return (0);
// // }