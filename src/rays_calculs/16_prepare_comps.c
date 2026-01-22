/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_prepare_comps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:00:25 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 17:59:16 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	prepare_computation(t_mem *mem_shtl, t_obj ***obj)
{
	t_coord	p_local;
	t_coord	p_local_surface;
	t_coord	v_eye;

	scalar_mult_na(&p_local, mem_shtl->r_dir_closest_obj,
		mem_shtl->closestt);
	p_local.t = 1;
	addition_na(&p_local_surface, mem_shtl->r_origin_closest_obj,
		&p_local);
	matrix_point_multiplication_new(mem_shtl->p_touch,
		obj[mem_shtl->obj_a][mem_shtl->obj_b]->m_transf, &p_local_surface);
	negat_na(&v_eye, mem_shtl->r_base_dir);
	if (mem_shtl->obj_a == SPHERE)
		normal_sphere(mem_shtl);
	if (mem_shtl->obj_a == CYLINDER)
		normal_cylinder(mem_shtl, obj);
	if (mem_shtl->obj_a == CONE)
		normal_cone(mem_shtl, obj);
	else if (mem_shtl->obj_a == TRIANGLE)
		copy_coord(mem_shtl->v_norm_parral, obj[5][mem_shtl->obj_b]->normal);
	else if (mem_shtl->obj_a == PLAN)
		copy_coord(mem_shtl->v_norm_parral, obj[2][mem_shtl->obj_b]->v_axe);
	if (dot_product(mem_shtl->v_norm_parral, &v_eye) < 0)
		negat_na(mem_shtl->v_norm_parral, mem_shtl->v_norm_parral);
}

void	normal_cylinder(t_mem *mem_shuttle, t_obj ***obj)
{
	t_coord	local_normal_vec;

	init_matrix_zero(mem_shuttle->transp_inv);
	matrix_point_multiplication_new(mem_shuttle->p_space,
		obj[3][mem_shuttle->obj_b]->m_inv,
		mem_shuttle->p_touch);
	if (mem_shuttle->t_count == 8)
		vector_fill(&local_normal_vec, 0, -1, 0);
	else if (mem_shuttle->t_count == 9)
		vector_fill(&local_normal_vec, 0, 1, 0);
	else
	{
		local_normal_vec.x = mem_shuttle->p_space->x;
		local_normal_vec.y = 0;
		local_normal_vec.z = mem_shuttle->p_space->z;
	}
	local_normal_vec.t = 0;
	normalize_vector_na(&local_normal_vec);
	transpose_matrix(mem_shuttle->transp_inv,
		obj[3][mem_shuttle->obj_b]->m_inv);
	matrix_point_multiplication_2(mem_shuttle->v_norm_parral,
		mem_shuttle->transp_inv, &local_normal_vec);
	normalize_vector_na(mem_shuttle->v_norm_parral);
}

// je dois modifier la normal de cone
void	normal_cone(t_mem *mem_shuttle, t_obj ***obj)
{
	t_coord	local_normal_vec;

	init_matrix_zero(mem_shuttle->transp_inv);
	matrix_point_multiplication_new(mem_shuttle->p_space,
		obj[4][mem_shuttle->obj_b]->m_inv,
		mem_shuttle->p_touch);
	if (mem_shuttle->t_count == 8)
		vector_fill(&local_normal_vec, 0, -1, 0);
	else if (mem_shuttle->t_count == 9)
		vector_fill(&local_normal_vec, 0, 1, 0);
	else
	{
		local_normal_vec.x = mem_shuttle->p_space->x;
		local_normal_vec.y = 0;
		local_normal_vec.z = mem_shuttle->p_space->z;
	}
	local_normal_vec.t = 0;
	normalize_vector_na(&local_normal_vec);
	transpose_matrix(mem_shuttle->transp_inv,
		obj[4][mem_shuttle->obj_b]->m_inv);
	matrix_point_multiplication_2(mem_shuttle->v_norm_parral,
		mem_shuttle->transp_inv, &local_normal_vec);
	normalize_vector_na(mem_shuttle->v_norm_parral);
}

void	normal_sphere(t_mem *mem_shuttle)
{
	t_coord	object_normal;

	object_normal.t = 0;
	matrix_point_multiplication_new(mem_shuttle->p_space,
		mem_shuttle->obj_inv, mem_shuttle->p_touch);
	substraction_p_to_v_na(&object_normal,
		mem_shuttle->p_space, mem_shuttle->origin_zero);
	normalize_vector_na(&object_normal);
	transpose_matrix(mem_shuttle->transp_inv, mem_shuttle->obj_inv);
	matrix_point_multiplication_2(mem_shuttle->v_norm_parral,
		mem_shuttle->transp_inv, &object_normal);
	normalize_vector_na(mem_shuttle->v_norm_parral);
}

/*
void	normal_cylinder(t_mem *mem_shuttle, t_obj ***obj)
{
	t_coord	local_normal_vec;

	init_matrix_zero(mem_shuttle->transp_inv);
	matrix_point_multiplication_new(mem_shuttle->p_space,
		obj[3][mem_shuttle->obj_b]->m_inv,
		mem_shuttle->p_touch);
	if (mem_shuttle->t_count == 8)
		vector_fill(&local_normal_vec, 0, -1, 0);
	else if (mem_shuttle->t_count == 9)
		vector_fill(&local_normal_vec, 0, 1, 0);
	else
	{
		local_normal_vec.x = mem_shuttle->p_space->x;
		local_normal_vec.y = 0;
		local_normal_vec.z = mem_shuttle->p_space->z;
	}
	local_normal_vec.t = 0;
	normalize_vector_na(&local_normal_vec);
	transpose_matrix(mem_shuttle->transp_inv,
		obj[3][mem_shuttle->obj_b]->m_inv);
	matrix_point_multiplication_2(mem_shuttle->v_norm_parral,
		mem_shuttle->transp_inv, &local_normal_vec);
	normalize_vector_na(mem_shuttle->v_norm_parral);
}
*/