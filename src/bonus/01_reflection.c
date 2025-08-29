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

t_color	base_reflection(t_scene *scene, t_mem *mem_shtle, t_color color_light)
{
	t_color	color_reflexion;
	float	mirror;

	mirror = scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->mirror;
	color_reflexion = reflexion(scene, mem_shtle);
	if (mirror == 1.0)
		return (color_reflexion);
	color_reflexion = scalar_mult_color2(color_reflexion, mirror);
	color_light = scalar_mult_color2(color_light, (1.0f - mirror));
	color_light = add_color(color_light, color_reflexion);
	return (color_light);
}

t_color	reflexion(t_scene *scene, t_mem *mem_shtle)
{
	t_color	color;

	next_ray_reflection(mem_shtle);
	main_intersections(scene->obj, mem_shtle);
	copy_matrix_44(mem_shtle->obj_inv,
		scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->m_inv);
	if (mem_shtle->obj_a == 0)
	{
		color = background_color(scene->obj[0][0], scene->lux[0][0]);
		return (color);
	}
	prepare_computation(mem_shtle, scene->obj);
	color = lighting(scene, mem_shtle,
			*(scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->color));
	//recursion reflexion//
	return (color);
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
