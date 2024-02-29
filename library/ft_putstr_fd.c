/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:25:24 by hsawamur          #+#    #+#             */
/*   Updated: 2023/01/25 00:18:13 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *c, int fd)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(c);
	if (c == NULL)
		return ;
	while (len > SIZE_MAX)
	{
		write(fd, c, SIZE_MAX);
		len -= SIZE_MAX;
	}	
	write(fd, c, len);
}

int main(void)
{
	ft_putstr_fd("jdaljfdjfidjlajzljoiflkajdflkjaofjlajfdioa;fdjajdf:kjdlk;fjiafjkajfiaol;fjiaoflkajfoi:jaojfla;jfijajdfijadfjkljfajo:f;k;akf;lakflka;fk;akf;akfj;fjalfjad", 1);
	return (0);
}