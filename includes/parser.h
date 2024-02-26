/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:43:37 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/26 13:13:53 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct s_minirt_list {
	char					*identifier;
	char					**value;
	struct s_minirt_list	*next;
}	t_minirt_list;

typedef struct s_param_count {
	size_t	ambient;
	size_t	camera;
	size_t	light;
}	t_param_count;

bool	is_target_file_extension(const char *filename, const char *extension);

#endif
