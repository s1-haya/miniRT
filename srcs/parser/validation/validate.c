/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:33:48 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/26 11:40:53 by hsawamur         ###   ########.fr       */
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
	if (!ft_strcmp(AMBIENT_LIGHTING, list->identifier))
		validate_ambient_lighting(list->value, result);
	else if (!ft_strcmp(CAMERA, list->identifier))
		validate_camera(list->value, result);
	else if (!ft_strcmp(LIGHT, list->identifier))
		validate_light(list->value, result);
	else if (!ft_strcmp(PLANE, list->identifier))
		validate_plane(list->value, result);
	else if (!ft_strcmp(SPHERE, list->identifier))
		validate_sphere(list->value, result);
	else if (!ft_strcmp(CYLINDER, list->identifier))
		validate_cylinder(list->value, result);
	else
		*result = false;
}
