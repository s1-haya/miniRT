/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:33:48 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/12 13:29:27 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "scene.h"
#include "libft.h"

#define AMBIENT_LIGHTING "A"
#define CAMERA "C"
#define LIGHT "L"
#define PLANE "pl"
#define SPHERE "sp"
#define CYLINDER "cy"
#define ERROR_INVALID_CHARACTERS "Error:\nthis file you enter contains \
invalid characters.\n"

void	validate_ambient_lighting(t_scene *scene, char **value,
			t_param_count *count, bool *result);
void	validate_camera(t_scene *scene, char **value,
			t_param_count *count, bool *result);
void	validate_light(t_scene *scene, char **value,
			t_param_count *count, bool *result);
void	validate_plane(t_scene *scene, char **value, \
						bool *result, t_param_count *count);
void	validate_sphere(t_scene *scene, char **value, \
						bool *result, t_param_count *count);
void	validate_cylinder(t_scene *scene, char **value, \
						bool *result, t_param_count *count);
void	check_parameter_count(t_param_count parameter_count, bool *result);
void	error_message(char *error_message, bool *result);

void	validate(t_scene *scene, t_minirt_list *list,
				t_param_count *count, bool *result)
{
	if (!ft_strcmp(AMBIENT_LIGHTING, list->identifier))
		validate_ambient_lighting(scene, list->value, count, result);
	else if (!ft_strcmp(CAMERA, list->identifier))
		validate_camera(scene, list->value, count, result);
	else if (!ft_strcmp(LIGHT, list->identifier))
		validate_light(scene, list->value, count, result);
	else if (!ft_strcmp(PLANE, list->identifier))
		validate_plane(scene, list->value, result, count);
	else if (!ft_strcmp(SPHERE, list->identifier))
		validate_sphere(scene, list->value, result, count);
	else if (!ft_strcmp(CYLINDER, list->identifier))
		validate_cylinder(scene, list->value, result, count);
	else
		error_message(ERROR_INVALID_CHARACTERS, result);
	check_parameter_count(*count, result);
}
