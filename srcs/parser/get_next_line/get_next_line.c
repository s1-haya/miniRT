/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:54:21 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/17 12:32:31 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_a_new_line(char **saved, size_t index)
{
	char	*res;
	char	*temp;
	size_t	saved_len;

	res = ft_strndup(*saved, index);
	saved_len = ft_strlen(*saved + index);
	temp = ft_strndup(*saved + index, saved_len);
	free(*saved);
	*saved = temp;
	return (res);
}

static ssize_t	get_read_size(int fd, char **buf)
{
	char	*new_buf;
	ssize_t	read_size;

	if (BUFFER_SIZE < 1 || BUFFER_SIZE >= SIZE_MAX)
		return (-1);
	new_buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (new_buf == NULL)
		return (-1);
	read_size = read(fd, new_buf, BUFFER_SIZE);
	if (read_size == -1 || read_size == 0)
	{
		free(new_buf);
		return (read_size);
	}
	new_buf[read_size] = '\0';
	*buf = new_buf;
	return (read_size);
}

static char	*get_a_last_line(char **saved, ssize_t read_size)
{
	char	*temp;

	if (*saved == NULL || read_size == -1)
	{
		free(*saved);
		*saved = NULL;
		return (NULL);
	}
	if (*saved[0] == '\0')
	{
		free(*saved);
		*saved = NULL;
		return (NULL);
	}
	temp = ft_strndup(*saved, ft_strlen(*saved));
	free(*saved);
	*saved = NULL;
	return (temp);
}

static char	*set_a_new_line(int fd, char **saved)
{
	char	*buf;
	char	*temp;
	ssize_t	read_size;
	size_t	index;

	read_size = get_read_size(fd, &buf);
	if (read_size == 0 || read_size == -1)
		return (get_a_last_line(saved, read_size));
	temp = ft_strjoin(*saved, buf);
	free(buf);
	buf = NULL;
	if (temp == NULL)
	{
		free(*saved);
		*saved = NULL;
		return (NULL);
	}
	free(*saved);
	*saved = temp;
	index = get_next_line_index(*saved, '\n');
	if (index != 0)
		return (get_a_new_line(saved, index));
	return (set_a_new_line(fd, saved));
}

char	*get_next_line(int fd)
{
	static char	*saved;
	size_t		index;

	if (fd < 0 || fd > 1024)
		return (NULL);
	index = get_next_line_index(saved, '\n');
	if (saved != NULL)
	{
		if (index != 0)
			return (get_a_new_line(&saved, index));
		return (set_a_new_line(fd, &saved));
	}
	return (set_a_new_line(fd, &saved));
}

//coment is not japanese
//改行なし　
//1　buf_sizeがあるかどうかだな
// ない場合　savedを出力
//2　改行があるかどうか
// ない場合　1に戻る。
//3  return get_a_new__line();
// saved 改行ありorなし確認関数
// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }
// #include <fcntl.h>
// #include <stdio.h>
// int main()
// {
//     int        fd;
//     char    *line;
//     fd = open("./file", O_RDONLY);
//     while (1)
// 	{
//         line = get_next_line(fd);
//         if (line == NULL)
//             break;
//         printf("line %s", line);
// 		free(line);
// 	}
// 	close (fd);
//     return (0);
// }

// // #include <fcntl.h>
// // #include <stdio.h>
// // int main()
// // {
// // 	// -fsanitize=address -g
// // 	// mac error
// // 	// 0x0001032006ef is located 1 bytes to the left of 2-byte region 
//[0x0001032006f0,0x0001032006f2)	
// //     int        fd;
// //     char    *line;
// //     fd = open("./42_with_nl", O_RDONLY);
// //     while (1)
// //     {
// //         line = get_next_line(fd);
// //         if (line == NULL)
// //             break;
// //         printf("%s", line);
// //         free(line);
// //     }
// // 	line = get_next_line(fd);
// // 	printf("%s", line);
// // 	free(line);
// //     // system("leaks a.out");
// // 	close (fd);
// //     return (0);
// // }
