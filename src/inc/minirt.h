/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by sforster          #+#    #+#             */
/*   Updated: 2025/10/06 17:09:35 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../../lib/libft/libft.h"
//# include "../../lib/minilibx-linux/mlx_int.h"
# include "../../lib/minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <sys/time.h>

# include "minirt_data_struct.h"
# include "minirt_matrix.h"
# include "parsing.h"
# include "saving.h"
# include "minirt_vect_point_color.h"
# include "minirt_ray_calculs.h"
# include "minirt_vect_point_color.h"
# include "minirt_window.h"
# include "pattern_color.h"
# include "new_memory.h"
# include "macro.h"
# include "minirt_bonus.h"
# define WND_WIDTH 2000
# define WND_HEIGHT 1200


# define BAKGROUND_COLOR 711850
# define EPSILON 0.0001
# define PI 3.1415926535
# define PIRAD 0.017453
# define SHININESS 100.0

enum e_obj_type
{
	NONE,
	SPHERE,
	PLAN,
	CYLINDER,
	CONE,
	TRIANGLE,
};

enum e_type_pattern
{
	ZERO,
	CHECKBOARD,
	STRIPES,
	GRADIENT,
	RINGS,
	PERLIN,
};
int		main(int argc, char **argv);

#endif