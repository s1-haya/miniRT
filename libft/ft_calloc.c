/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:10:31 by hsawamur          #+#    #+#             */
/*   Updated: 2023/01/20 14:05:33 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	if (count == 0 || size == 0)
		return (ft_calloc(1, 1));
	if ((size_t)SIZE_MAX / count < size)
		return (NULL);
	res = (void *)malloc(size * count);
	if (res == NULL)
		return (NULL);
	ft_memset(res, 0, size * count);
	return (res);
}

// #include <stdio.h>
// int main(void) {
// 	int i;
// 	long * pMMem;	//	malloc用
// 	long * pCMem;	//	calloc用man 
// 	long * pft_CMem;	//	calloc用
// 	pMMem = (long *)malloc(0);
// 	pCMem = (long *)calloc(0, 1);
// 	pft_CMem = (long *)ft_calloc(0, 1);
// 	//	確保領域の初期値表示
// 	printf("malloc       [0]:0x%08lx\n", pMMem[0]);
// 	printf("malloc       [1]:0x%08lx\n", pMMem[1]);
// 	printf("malloc       [2]:0x%08lx\n", pMMem[2]);
// 	printf("calloc       [0]:0x%08lx\n", pCMem[0]);
// 	printf("ft_calloc    [0]:0x%08lx\n", pft_CMem[0]);
// 	printf("calloc       [1]:0x%08lx\n", pCMem[1]);
// 	printf("ft_calloc    [1]:0x%08lx\n", pft_CMem[1]);
// 	printf("calloc       [2]:0x%08lx\n",  pCMem[2]);
// 	printf("ft_calloc    [2]:0x%08lx\n", pft_CMem[2]);
// 	free(pMMem);
// 	free(pCMem);
// 	free(pft_CMem);
// 	return 0;
// }
//ft_bzero()→ ft_memset()
//理由　廃止予定の関数だかf
