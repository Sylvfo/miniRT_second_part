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

void next_ray_reflection(t_mem *memory_shuttle)
{
	// si vecteur reflexion vers camera???
	copy_coord(memory_shuttle->r_base_origin, memory_shuttle->p_touch);
	vect_reflexion(memory_shuttle->r_base_dir, memory_shuttle->r_base_dir, memory_shuttle->v_norm_parral);
	clean_memory_shuttle_refl(memory_shuttle);
}

void clean_memory_shuttle_refl(t_mem *memory_shuttle)
{
	vector_fill(memory_shuttle->r_origin_m, 0, 0, 0);
	vector_fill(memory_shuttle->r_dir_closest_obj, 0, 0, 0);
	vector_fill(memory_shuttle->r_origin_closest_obj, 0, 0, 0);
	vector_fill(memory_shuttle->v_sph_camera, 0, 0, 0);
	vector_fill(memory_shuttle->p_touch, 0, 0, 0);
	vector_fill(memory_shuttle->v_norm_parral, 0, 0, 0);
	vector_fill(memory_shuttle->p_space, 0, 0, 0);
	vector_fill(memory_shuttle->v_light_to_point, 0, 0, 0);
	vector_fill(memory_shuttle->v_point_to_light, 0, 0, 0);
	vector_fill(memory_shuttle->reflect_dir, 0, 0, 0);
	vector_fill(memory_shuttle->scalar, 0, 0, 0);
	vector_fill(memory_shuttle->view_dir, 0, 0, 0);

	memory_shuttle->t_count = 0;
	memory_shuttle->closestt = 0;
	memory_shuttle->obj_a = 0;
	memory_shuttle->obj_b = 0;
	memory_shuttle->closestt = 0;
	memory_shuttle->closestt = 0;
	memory_shuttle->closestt = 0;
	memory_shuttle->closestt = 0;
	memory_shuttle->closestt = 0;
	init_matrix_zero(memory_shuttle->obj_inv);
	init_matrix_zero(memory_shuttle->transp_inv);
}

void vect_reflexion(t_coord *result, t_coord *v_previous, t_coord *v_normal)
{
	float dot;
	t_coord v_scal;

	dot = dot_product(v_previous, v_normal);
	v_scal = scalar_mult_ret(v_previous, (2 * dot));
	substraction_p_to_v_na(result, v_normal, &v_scal);
}

t_color blend_reflection(t_color local, t_color reflected, float refl_intensity)
{
    t_color result;

    result.r = (1 - refl_intensity) * local.r + refl_intensity * reflected.r;
    result.g = (1 - refl_intensity) * local.g + refl_intensity * reflected.g;
    result.b = (1 - refl_intensity) * local.b + refl_intensity * reflected.b;
    result.rgb = 0; // à recalculer si nécessaire

    return result;
}