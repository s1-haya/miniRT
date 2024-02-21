/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:33:48 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/21 19:40:10 by hsawamur         ###   ########.fr       */
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

bool	validate_ambient_lighting(char **value);
bool	validate_camera(char **value);
bool	validate_light(char **value);
bool	validate_plane(char **value);
bool	validate_sphere(char **value);
bool	validate_cylinder(char **value);

bool	validate(t_minirt_list *list)
{
	if (!ft_strncmp(AMBIENT_LIGHTING, list->identifier, 
			ft_strlen(AMBIENT_LIGHTING)))
		return (validate_ambient_lighting(list->value));
	else if (!ft_strncmp(CAMERA, list->identifier, 
			ft_strlen(CAMERA)))
		return (validate_camera(list->value));
	else if (!ft_strncmp(LIGHT, list->identifier, 
			ft_strlen(LIGHT)))
		return (validate_light(list->value));
	else if (!ft_strncmp(PLANE, list->identifier, 
			ft_strlen(PLANE)))
		return (validate_plane(list->value));
	else if (!ft_strncmp(SPHERE, list->identifier, 
			ft_strlen(SPHERE)))
		return (validate_sphere(list->value));
	else if (!ft_strncmp(CYLINDER, list->identifier, 
			ft_strlen(CYLINDER)))
		return (validate_cylinder(list->value));
	return (false);
}
