/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_reflection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:25:21 by syl               #+#    #+#             */
/*   Updated: 2025/06/02 14:25:29 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_color	reflexion(t_scene *scene, t_mem *mem_shtle, t_color prev_color)
{
	t_color	next_color;
	float	mirror;

	mirror = scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->mirror;
	next_ray_reflection(mem_shtle);
	next_color = raytracer_bonus(NULL, scene, mem_shtle);
	if (mem_shtle->recursivity_level < MAX_RECURSIVITY)
		next_color = next_ray(scene, mem_shtle, next_color);
	if (mirror == 1.0)
		return (next_color);
	next_color = scalar_mult_color2(next_color, mirror);
	prev_color = scalar_mult_color2(prev_color, (1.0f - mirror));
	prev_color = add_color(prev_color, next_color);
	return (prev_color);
}

void	next_ray_reflection(t_mem *mem_shuttle)
{
	t_coord	offset;

	offset = scalar_mult_ret(mem_shuttle->v_norm_parral, 0.001f);
	addition_na(mem_shuttle->r_base_origin, mem_shuttle->p_touch, &offset);
	vect_reflexion(mem_shuttle->r_base_dir, mem_shuttle->v_norm_parral);
	clean_memory_shuttle_refl(mem_shuttle);
}

void	vect_reflexion(t_coord *r_base_dir, t_coord *v_normal)
{
	float	inner_product;
	t_coord	v_scal;
	t_coord	result;

	v_scal.t = 0;
	inner_product = dot_product(r_base_dir, v_normal);
	v_scal = scalar_mult_ret(v_normal, (-2.0f * inner_product));
	addition_vect(&result, r_base_dir, &v_scal);
	result.t = 0;
	normalize_vector_na(&result);
	copy_coord(r_base_dir, &result);
}
