/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 07:58:40 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/01 19:28:03 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include <stdlib.h>
# include "vector.h"

typedef struct s_camera
{
	t_vector	view_point;
	t_vector	look_at;
	double		distance;
	size_t		horizontal_viewing_angle;
}	t_camera;

#endif
