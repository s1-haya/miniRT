/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:27:36 by hsawamur          #+#    #+#             */
/*   Updated: 2023/01/20 10:49:29 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_str_index(long n)
{
	size_t	index;

	index = 1;
	if (n == 0)
		return (index);
	if (n < 0)
	{
		index += 1;
		n *= -1;
	}
	while (n > 9)
	{
		n = n / 10;
		index++;
	}
	return (index);
}

static char	*ft_str_n(long n, char *res, size_t index)
{
	size_t	mod;
	size_t	i;

	mod = n % 10;
	i = index - 1;
	while (n > 9)
	{
		res[i] = mod + '0';
		n = n / 10;
		mod = n % 10;
		i--;
	}
	res[i] = mod + '0';
	res[index] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	size_t			index;
	char			*res;
	long			temp_n;

	index = ft_str_index((long)n);
	res = (char *)malloc(sizeof(char) * (index + 1));
	temp_n = (long)n;
	if (res == NULL)
		return (NULL);
	if (temp_n < 0)
	{
		temp_n *= -1;
		res[0] = '-';
	}
	return (ft_str_n(temp_n, res, index));
}

// #include "string.h"
// #include "stdio.h"
// int main(void)
// {
// 	// printf("ft_index()   %d\n", ft_str_index(-152525));
// 	// printf("ft_index()   %d\n", ft_str_index(-2147483647));
// 	// printf("ft_index()   %d\n", ft_str_index(-2147483648));
// 	// printf("ft_index()   %d\n", ft_str_index(-15));
// 	// printf("ft_index()   %d\n", ft_str_index(15));
// 	// printf("ft_index()   %d\n", ft_str_index(-1));
// 	// printf("ft_index()   %d\n", ft_str_index(1));
// 	// printf("ft_index()   %d\n", ft_str_index(0));
// 	printf("ft_itoa()   %s\n", ft_itoa(-2147483647));
// 	printf("ft_itoa()   %s\n", ft_itoa(-2147483648));
// 	// printf("ft_itoa()   %s\n", ft_itoa(-152525));
// 	// printf("ft_itoa()   %s\n", ft_itoa(152525));
// 	// printf("ft_itoa()   %s\n", ft_itoa(-15));
// 	// printf("ft_itoa()   %s\n", ft_itoa(1525));
// 	// printf("ft_itoa()   %s\n", ft_itoa(1));
// 	// printf("ft_itoa()   %s\n", ft_itoa(0));
// 	return (0);
// }