/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_one_line_to_minirt_list.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:01:42 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/20 20:19:42 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <stdlib.h>

#include <stdio.h>

void			*set_error_and_return_null(bool *result);
t_minirt_list	*init_minirt_list();
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_strdup(const char *src);
char			**ft_split(char const *str, char c);
char			*ft_strndup(const char *s1, size_t n);
void			delete_minirt_list(t_minirt_list *list);


// static char *trim_spaces(const char *str) {
//     if (str == NULL) return NULL;

//     // 先頭の空白をスキップ
//     while (*str == ' ') str++;

//     // 文字列の長さを取得
//     size_t len = ft_strlen(str);
//     if (len == 0) return ft_strdup(""); // 空文字列の場合

//     // 末尾の空白を見つける
//     const char *end = str + len - 1;
//     while (end > str && ((unsigned char)*end) == ' ') end--;
//     len = end - str + 1;

//     // 結果を格納するための新しい文字列を確保
//     char *result = (char *)malloc(len + 1);
//     if (result == NULL) return NULL; // メモリ確保に失敗

//     // 文字列をコピーし、ヌル終端文字を追加
//     ft_memcpy(result, str, len);
//     result[len] = '\0';

//     return result;
// }

t_minirt_list	*convert_one_line_to_minirt_list(char *line, bool *result)
{
	t_minirt_list	*list;
	// char			*tmp;
	char			*first_space;

	list = init_minirt_list();
	if (list == NULL)
		return (set_error_and_return_null(result));
	// tmp = trim_spaces(line);
	// printf("tmp  %sd", tmp);
	// printf("line %sd", line);
	first_space = ft_strchr(line, ' ');
	if (first_space == NULL)
	{
		// free(tmp);
		delete_minirt_list(list);
		return (set_error_and_return_null(result));
	}
	list->identifier = ft_strndup(line, first_space - line);
	list->value = ft_split(first_space + 1, ' ');
	if (list == NULL || list->value[0] == NULL)
	{
		// free(tmp);
		delete_minirt_list(list);
		return (set_error_and_return_null(result));
	}
	// free(tmp);
	// printf("identifier %s\n", list->identifier);
	// printf("fist_space %s\n", list->value[0]);
	// printf("value[0]%sd\n", list->value[0]);
	return (list);
}
