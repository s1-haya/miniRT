/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:33:48 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/23 16:30:10 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

#define AMBIENT_LIGHTING "A"
#define CAMERA "C"
#define LIGHT "L"
#define PLANE "pl"
#define SPHERE "sp"
#define CYLINDER "cy"

void	validate_ambient_lighting(char **value, bool *result);
void	validate_camera(char **value, bool *result);
void	validate_light(char **value, bool *result);
void	validate_plane(char **value, bool *result);
void	validate_sphere(char **value, bool *result);
void	validate_cylinder(char **value, bool *result);

void	validate(t_minirt_list *list, bool *result)
{
	if (!ft_strncmp(AMBIENT_LIGHTING, list->identifier, 
			ft_strlen(AMBIENT_LIGHTING)))
		validate_ambient_lighting(list->value, result);
	else if (!ft_strncmp(CAMERA, list->identifier, 
			ft_strlen(CAMERA)))
		validate_camera(list->value, result);
	else if (!ft_strncmp(LIGHT, list->identifier, 
			ft_strlen(LIGHT)))
		validate_light(list->value, result);
	else if (!ft_strncmp(PLANE, list->identifier, 
			ft_strlen(PLANE)))
		validate_plane(list->value, result);
	else if (!ft_strncmp(SPHERE, list->identifier, 
			ft_strlen(SPHERE)))
		validate_sphere(list->value, result);
	else if (!ft_strncmp(CYLINDER, list->identifier, 
			ft_strlen(CYLINDER)))
		validate_cylinder(list->value, result);
	else
		*result = false;
}
