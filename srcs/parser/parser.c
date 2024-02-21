/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:45:34 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/21 19:27:43 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "scene.h"
#include "parser.h"

t_minirt_list	*read_rt_file(const char *file_name, bool *result);
bool			validate(t_minirt_list *list);
void			delete_minirt_list(t_minirt_list *list);

void	check_input_scene(t_scene *scene)
{
	t_shape			**shape;
	t_light			*light;
	shape = (t_shape **)malloc(sizeof(t_shape *) * SIZE);
	if (shape == NULL)
		return ;
	// shape[0] = new_shape(new_sphere(new_vector(3, 0, 25), 3), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.00,0.69,0.00), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), SPHERE, 0);
	// shape[1] = new_shape(new_sphere(new_vector(2, 0, 20), 1), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69,0.00,0.00), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), SPHERE, 1);
	// shape[2] = new_shape(new_sphere(new_vector(1, 0, 15), 1), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.00,0.00,0.69), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), SPHERE, 2);
	// shape[3] = new_shape(new_sphere(new_vector(0, 0, 10), 1), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.00,0.69,0.69), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), SPHERE, 3);
	// shape[4] = new_shape(new_sphere(new_vector(-1, 0, 5), 1), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69,0.69,0.00), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), SPHERE, 4);
	// shape[5] = new_shape(new_plane(new_vector(0, 1, 0), new_vector(0, -1, 0)),new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69,0.69,1), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), PLANE, 5);
	
	shape[0] = new_shape(new_cylinder(new_vector(3, 0, 25), 1, 2), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.00,0.69,0.00), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), CYLINDER);
	shape[1] = new_shape(new_cylinder(new_vector(2, 0, 20), 1, 2), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69,0.00,0.00), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), CYLINDER);
	shape[2] = new_shape(new_cylinder(new_vector(1, 0, 15), 1, 2), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.00,0.00,0.69), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), CYLINDER);
	shape[3] = new_shape(new_cylinder(new_vector(0, 0, 10), 1, 2), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.00,0.69,0.69), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), CYLINDER);
	shape[4] = new_shape(new_cylinder(new_vector(-1, 0, 5), 1, 2), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69,0.69,0.00), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), CYLINDER);
	// shape[5] = new_shape(new_plane(new_vector(0, 1, 0), new_vector(0, -1, 0)),new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69,0.69,1), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), PLANE, 5);

	// shape[0] = new_shape(new_cylinder(new_vector(0, 0, 5), 1, 2), new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69,0.00,0.69), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), CYLINDER, 2);
	// shape[1] = new_shape(new_plane(new_vector(0, 1, 0), new_vector(0, -1, 0)),new_material(AMBIENT_LIGNT_REFLECTION_COEFFICIENT, new_color(0.69,0.69,1), SPECULAR_REFLECTION_COEFFICIENT, GLOSS_FACTOR), PLANE, 5);

	light = (t_light *)malloc(sizeof(t_light) * LIGHT_SIZE);
	if (light == NULL)
		return ;
	light[0] = new_light(new_vector(5, 1, -5), new_color(1,1,1));
	light[1] = new_light(new_vector(5, 0, -5), new_color(0.5,0.5,0.5));
	light[2] = new_light(new_vector(5, 20, -5), new_color(0.5,0.5,0.5));
	// scene = new_scene(shape, light, new_camera(VIEWPOINT, LOOKATPOINT, 70), new_mlx_data());
	scene->shape = shape;
	scene->light = light;
	// scene->mlx = new_mlx_data();
}

void	parser(t_scene *scene, const char *file_name, bool *result)
{
	// t_minirt_list	*list;

	(void)scene;
	(void)file_name;
	(void)result;
	// check_input_scene(scene);
	// list = read_rt_file(file_name, result);
	// if (*result == false)
	// {
	// 	//error_fail_to_read
	// 	return ;
	// }
	// while (list != NULL)
	// {
	// 	*result = validate(list);
	// 	if (*result == false)
	// 	{
	// 		//error_fail_to_validate
	// 		delete_minirt_list(list);
	// 		return ;
	// 	}
	// 	list = list->next;
	// }
}
