/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_shadows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:20:52 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 18:49:55 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	prepare_v_light(t_mem *mem_shuttle, t_coord *lux_p_coord)
{
	t_coord	offset_point;
	t_coord	tmp;

	offset_point.x = 0.0;
	offset_point.y = 0.0;
	offset_point.z = 0.0;
	offset_point.t = 1;
	tmp.x = 0.0;
	tmp.y = 0.0;
	tmp.z = 0.0;
	tmp.t = 0;
	scalar_mult_na(&tmp, mem_shuttle->v_norm_parral, 0.01 * 10.0f);
	addition_na(&offset_point, mem_shuttle->p_touch, &tmp);
	substraction_p_to_v_na(mem_shuttle->v_light_to_point,
		lux_p_coord, &offset_point);
	mem_shuttle->distance_light_p_touch
		= length_vector(mem_shuttle->v_light_to_point);
	normalize_vector_na(mem_shuttle->v_light_to_point);
}

bool	intersect_objects_shadow(t_scene *scene, t_mem *mem_shuttle)
{
	int		a;
	int		b;
	bool	in_shadow;

	in_shadow = false;
	a = 1;
	while (a < NB_OBJ)
	{
		b = 0;
		while (scene->obj[a] && b < scene->obj[a][0]->number)
		{
			if (a == SPHERE)
				in_shadow = sphere_shadow(scene->obj[a][b], mem_shuttle);
			else if (a == PLAN)
				in_shadow = plan_shadow(mem_shuttle, scene->obj[a][b]);
			else if (a == CYLINDER)
				in_shadow = cylinder_shadow(mem_shuttle, scene->obj[a][b]);
			if (in_shadow)
				return (true);
			b++;
		}
		a++;
	}
	return (false);
}
