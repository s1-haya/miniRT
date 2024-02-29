/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:25:10 by hsawamur          #+#    #+#             */
/*   Updated: 2023/01/24 21:40:15 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		n = -(n);
	return (n);
}

static void	ft_recursion_n_fd(int n, int fd)
{
	int	n_mod;
	int	n_div;

	n_div = n / 10;
	n_mod = ft_abs(n % 10);
	if (n_div != 0)
		ft_recursion_n_fd(n_div, fd);
	ft_putchar_fd(n_mod + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_recursion_n_fd(n, fd);
}

// #include "stdio.h"
// int main(void)
// {
// 	ft_putnbr_fd(1000, 1);
// 	printf("\n");
// 	ft_putnbr_fd(2147483647, 1);
// 	printf("\n");
// 	ft_putnbr_fd(-47483647, 1);
// 	printf("\n");
// 	ft_putnbr_fd(-21647, 1);
// 	printf("\n");
// 	ft_putnbr_fd(-2147483647, 1);
// 	printf("\n");
// 	ft_putnbr_fd(-2147483648, 1);
// 	printf("\n");
// 	return (0);
// }