/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:43:19 by erin              #+#    #+#             */
/*   Updated: 2024/03/05 19:41:05 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include <libc.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_camera			t_camera;
typedef struct s_rgb			t_rgb;
typedef struct s_color			t_color;
typedef struct s_light			t_light;
typedef struct s_ambient_light	t_ambient_light;
typedef struct s_material		t_material;
typedef struct s_mlx_data		t_mlx_data;
typedef struct s_minirt_list	t_minirt_list;
typedef struct s_param_count	t_param_count;
typedef struct s_ray			t_ray;
typedef struct s_intersection	t_intersection;
typedef struct s_scene			t_scene;
typedef struct s_img			t_img;
typedef enum e_object			t_object;
typedef struct s_plane			t_plane;
typedef struct s_sphere			t_sphere;
typedef struct s_cylinder		t_cylinder;
typedef struct s_shape			t_shape;
typedef struct s_vector			t_vector;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_camera
{
	t_vector	view_point;
	t_vector	look_at_point;
	double		distance;
	size_t		horizontal_viewing_angle;
}	t_camera;

typedef struct s_rgb
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
}	t_rgb;

typedef struct s_color
{
	double	red;
	double	green;
	double	blue;
}	t_color;

typedef struct s_light
{
	double			distance;
	t_vector		point;
	double			intensity;
	t_rgb			rgb;
	struct s_light	*next;
}	t_light;

typedef struct s_ambient_light
{
	double	intensity;
	t_rgb	rgb;
}	t_ambient_light;

typedef struct s_material
{
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	t_color	gloss_factor;
}	t_material;

typedef struct s_img
{
	void	*data;
	char	*address;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_mlx_data
{
	void	*data;
	void	*window;
	void	*mlx;
	t_img	img;
}	t_mlx_data;

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

typedef struct s_ray
{
	t_vector	point;
	t_vector	direction;
}	t_ray;

typedef struct s_intersection
{
	double		distance;
	t_vector	point;
	t_vector	normal;
	bool		is_success;
}	t_intersection;

typedef struct s_scene {
	t_list			*shape;
	t_light			*light;
	t_camera		camera;
	t_mlx_data		mlx;
	t_ambient_light	ambient;
}	t_scene;

typedef enum e_object
{
	PLANE,
	SPHERE, 
	CYLINDER
}	t_object;

typedef struct s_plane
{
	t_vector	point;
	t_vector	normal;
	t_rgb		rgb;
}	t_plane;

typedef struct s_sphere
{
	t_vector	origin;
	double		radius;
	t_rgb		rgb;
}	t_sphere;

typedef struct s_cylinder
{
	t_vector	origin;
	t_vector	axis;
	double		radius;
	double		height;
	t_rgb		rgb;
}	t_cylinder;

typedef struct s_shape
{
	enum e_object	object;
	void			*substance;
	t_intersection	intersection;
}	t_shape;

#endif