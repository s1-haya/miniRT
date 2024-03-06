/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erin <erin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:34:21 by hsawamur          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/05 19:46:57 by erin             ###   ########.fr       */
=======
/*   Updated: 2024/03/06 14:32:17 by erin             ###   ########.fr       */
>>>>>>> 84d2404
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

<<<<<<< HEAD
# include "libft.h"
# include "camera.h"
# include "color.h"
# include "light.h"
# include "material.h"
# include "mlx_data.h"
# include "parser.h"
# include "ray.h"
# include "render_scene.h"
# include "scene.h"
# include "shape.h"
# include "utils.h"
# include "validate.h"
# include "vector.h"
# include <math.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
=======
# include <stdio.h>
# include "vector.h"
# include "light.h"
>>>>>>> 84d2404

double	max(double n1, double n2);

# define MLX_TITLE "MINIRT"
# define WINDOW_ORIGIN_X 0
# define WINDOW_ORIGIN_Y 0
# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 1000
# define SUCCESS 0
# define FAILURE 1

# define DIFFUSE_REFLECTION_COEFFICIENT 0.69
# define SPECULAR_REFLECTION_COEFFICIENT 0.30
# define GLOSS_FACTOR 50

#endif