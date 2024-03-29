/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 07:58:40 by hsawamur          #+#    #+#             */
/*   Updated: 2024/03/11 11:56:30 by erin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include <stdlib.h>
# include "vector.h"

typedef struct s_camera
{
	t_vector	view_point;
	t_vector	look_at_point;
	double		distance;
	size_t		horizontal_viewing_angle;
	double		screen_width;
	double		screen_height;
}	t_camera;

t_camera	new_camera(t_vector view_point, t_vector look_at_point, \
						double horizontal_value);

#endif
