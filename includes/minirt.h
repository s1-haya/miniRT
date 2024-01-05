/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:34:21 by hsawamur          #+#    #+#             */
/*   Updated: 2024/01/05 23:02:10 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

typedef enum e_object
{
	PLANE,
	SPHERE, 
	SYLINDER
}	t_object

typedef struct s_data
{
	void *img;
	char *address;
	int bits_per_pixel;
	int size_line;
	int endian;
} t_data;

#endif