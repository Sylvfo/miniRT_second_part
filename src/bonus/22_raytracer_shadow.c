/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_raytracer_shadow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:39:34 by sforster          #+#    #+#             */
/*   Updated: 2026/01/20 15:40:02 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

////////////////////////////// RAYTRACER
void	raytracer_shadow_bonus(t_scene *scene, t_mem *mem_shtle, int num_light)
{
	clean_color(mem_shtle->color_shadow);
	mem_shtle->percent_shadow = 0.0;
	mem_shtle->percent_new_shadow = 0.0;
	next_ray_light(mem_shtle, scene->lux[1][num_light]->p_coord);
	light_intersections_shadow(scene->obj, mem_shtle);
	return ;
}

void	next_ray_light(t_mem *mem_shuttle, t_coord *lux_p_coord)
{
	t_coord	offset;
	t_coord	tmp;

	offset = scalar_mult_ret(mem_shuttle->v_norm_parral, 0.01f);
	addition_na(mem_shuttle->p_light_to_point, mem_shuttle->p_touch, &offset);
	offset.x = 0.0;
	offset.y = 0.0;
	offset.z = 0.0;
	offset.t = 1;
	tmp.x = 0.0;
	tmp.y = 0.0;
	tmp.z = 0.0;
	tmp.t = 0;
	scalar_mult_na(&tmp, mem_shuttle->v_norm_parral, 0.0001 * 10.0f);
	addition_na(&offset, mem_shuttle->p_touch, &tmp);
	substraction_p_to_v_na(mem_shuttle->v_light_to_point,
		lux_p_coord, &offset);
	mem_shuttle->distance_light_p_touch
		= length_vector(mem_shuttle->v_light_to_point);
	normalize_vector_na(mem_shuttle->v_light_to_point);
}
