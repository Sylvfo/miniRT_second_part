/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_take_shadow_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:43:03 by sforster          #+#    #+#             */
/*   Updated: 2026/01/20 16:17:03 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	take_shadow_color(t_mem *mem_shuttle, t_intertt result, t_obj *obj)
{
	t_color	new_color_shadow;

	new_color_shadow = init_color();
	if ((result.t1 < (float)INT_MAX && result.t1 > 0.0)
		|| (result.t2 < (float)INT_MAX && result.t2 > 0))
	{
		if (obj->transparence == 1.0)
		{
			mem_shuttle->percent_shadow = 1.0;
			return ;
		}
		if (mem_shuttle->percent_shadow == 0.0)
		{
			mem_shuttle->percent_shadow = (1.0 - obj->transparence);
			*mem_shuttle->color_shadow = scalar_mult_color2(*obj->color,
					mem_shuttle->percent_shadow);
			return ;
		}
		new_shadow_color(mem_shuttle, obj);
		return ;
	}
}

void	new_shadow_color(t_mem *mem_shuttle, t_obj *obj)
{
	t_color	new_color_shadow;

	mem_shuttle->percent_shadow = 0.5;
	new_color_shadow = scalar_mult_color2(*obj->color, obj->transparence);
	*mem_shuttle->color_shadow = scalar_mult_color2(*mem_shuttle->color_shadow,
			(1.0 - obj->transparence));
	*mem_shuttle->color_shadow = multipling_color(*mem_shuttle->color_shadow,
			new_color_shadow);
}

void	intersect_triangle_bonus(t_mem *memory_shuttle, t_obj ***obj, int n)
{
	t_intertt	result;

	result.t_count = 0;
	cal_intersect_bonus(memory_shuttle, obj, n, result);
}
