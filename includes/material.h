/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:55:12 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/06 14:19:19 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "color.h"

typedef struct s_material
{
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	t_color	gloss_factor;
}	t_material;

#endif
