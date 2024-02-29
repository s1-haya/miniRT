/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:15:04 by hsawamur          #+#    #+#             */
/*   Updated: 2023/01/15 19:35:55 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char) c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *) s);
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
// 	//argv[1] 文字列
// 	if ((p = strchr(argv[1], c)) != NULL) {
// printf("strchr():  '%c' is found in \"%s\".\n", c, argv[1]);
// printf("strchr():  s = %p, p = %p, pos = %ld\n", argv[1], p, p - argv[1]);
// 	} else {
// printf("strchr():  '%c' is not found in \"%s\".\n", c, argv[1]);
// 	}
// 	if ((p = ft_strchr(argv[1], c)) != NULL) {
// printf("ft_strchr():  '%c' is found in \"%s\".\n", c, argv[1]);
// printf("ft_strchr():  s = %p, p = %p, pos = %ld\n", argv[1], p, p - argv[1]);
// 	} else {
// printf("ft_strchr():  '%c' is not found in \"%s\".\n", c, argv[1]);
// 	}
// 	if ((p = strrchr(argv[1], c)) != NULL) {
// printf("strrchr(): '%c' is found in \"%s\".\n", c, argv[1]);
// printf("strrchr(): s = %p, p = %p, pos = %ld\n", argv[1], p, p - argv[1]);
// 	} else {
// printf("strrchr(): '%c' is not found in \"%s\".\n", c, argv[1]);
// 	}
// 	return 0;
// }