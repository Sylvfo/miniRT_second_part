/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_shadows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:20:52 by syl               #+#    #+#             */
/*   Updated: 2025/05/31 17:56:59 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//OK NEW DATA STRUCT
void	prepare_v_light(t_mem *memory_shuttle, t_coord *lux_p_coord)
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

	scalar_mult_na(&tmp, memory_shuttle->v_norm_parral, 0.00001 * 10.0f);
	addition_na(&offset_point, memory_shuttle->p_touch, &tmp);
	substraction_p_to_v_na(memory_shuttle->v_light_to_point,
		lux_p_coord, &offset_point);
	memory_shuttle->distance_light_p_touch
		= length_vector(memory_shuttle->v_light_to_point);
	normalize_vector_na(memory_shuttle->v_light_to_point);
}

//A REVOIR AVEC NOUVELLE DATA STRUCTURE
bool	intersect_objects_shadow(t_scene *scene, t_mem *memory_shuttle, int lux_num)
{
	int		a;
	int		b;
	bool	in_shadow;

	in_shadow = false;
	a = 1;
	//BOUCLE OBJ
	while (a < NB_OBJ)//  (scene->obj[a] != NULL)
	{
		b = 0;
		while (scene->obj[a] && b < scene->obj[a][0]->number)//(scene->obj[a][b] != NULL)
		{
			if (a == SPHERE)
				in_shadow = intersect_sphere_shadow(scene->obj[a][b], memory_shuttle);
			else if (a == PLAN)
				in_shadow = intersect_plan_shadow(memory_shuttle, scene->obj[a][b]);
			else if (a == CYLINDER)
				in_shadow = intersect_cylinder_shadow(memory_shuttle, scene->obj[a][b]);
			if (in_shadow)
				return (true);
			b++;
		}
		a++;
	}
	return (false);
}
