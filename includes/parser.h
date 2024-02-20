/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:43:37 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/20 17:44:32 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include <stdbool.h>

typedef struct s_minirt_list {
	char					*identifier;
	char					**value;
	struct s_minirt_list	*next;
}	t_minirt_list;

bool	is_target_file_extension(const char *filename, const char *extension);

#endif
