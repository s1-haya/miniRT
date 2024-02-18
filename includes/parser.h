/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:43:37 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/18 15:51:29 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_hashmap {
	const char			*key;
	const char			**value;
	struct s_hashmap	*next;
}	t_hashmap;

bool	is_target_file_extension(const char *filename, const char *extension);

#endif
