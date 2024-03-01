/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 07:58:40 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/29 11:54:17 by hsawamur         ###   ########.fr       */
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
}	t_camera;

t_camera	new_camera(t_vector view_point, t_vector look_at_point,
						double horizontal_value);

#endif
