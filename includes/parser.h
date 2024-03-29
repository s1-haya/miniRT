/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:43:37 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/13 13:54:07 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>
# include <stdbool.h>

# define DELMITER_CHAR ','

typedef struct s_minirt_list {
	char					*identifier;
	char					**value;
	struct s_minirt_list	*next;
}	t_minirt_list;

typedef struct s_param_count {
	size_t	ambient;
	size_t	camera;
	size_t	light;
	size_t	objs;
}	t_param_count;

bool	is_target_file_extension(const char *filename, const char *extension);

#endif
