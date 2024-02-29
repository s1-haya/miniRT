/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:55:12 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/29 16:38:06 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

#include "color.h"

typedef struct s_material
{
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	t_color	gloss_factor;
}	t_material;

#endif
