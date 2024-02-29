/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:02:28 by hsawamur          #+#    #+#             */
/*   Updated: 2023/01/17 19:44:43 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*reverse;

	reverse = NULL;
	while (1)
	{
		if (*s == (char) c)
			reverse = (char *)s;
		if (*s == '\0')
			return ((char *)reverse);
		s++;
	}
	return (0);
}

// int main(int argc, char *argv[]){
// 	int c;
// 	char *p;
// 	if (argc != 3) {
// 		fprintf(stderr, "Usage: %s [str] [char]\n", argv[0]);
// 		exit(1);
// 	}
// 	//特定の文字
// 	c = argv[2][0];
// 	printf("strchr()      %s\n", strchr(argv[1], c));
// 	printf("strrchr()     %s\n", strrchr(argv[1], c));
// 	printf("ft_strrchr()  %s\n", ft_strrchr(argv[1], c));
// 	return 0;
// }
