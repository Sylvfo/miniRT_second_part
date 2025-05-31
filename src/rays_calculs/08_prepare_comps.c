/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_prepare_comps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:00:25 by syl               #+#    #+#             */
/*   Updated: 2025/05/31 21:14:36 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	prepare_computation(t_pix *pix, t_obj ***obj, t_mem *mem_shuttle)
{
	t_coord	term_for_p_local;//RENOMMER
	t_coord	p_local_on_surface;//RENOMMER
	t_coord v_eye;

	scalar_mult_na(&term_for_p_local, mem_shuttle->r_dir_closest_obj, mem_shuttle->closestt);
	term_for_p_local.t = 1;
	addition_na(&p_local_on_surface, mem_shuttle->r_origin_closest_obj, &term_for_p_local);
	matrix_point_multiplication_new(mem_shuttle->p_touch,
		obj[pix->obj_a][pix->obj_b]->m_transf, &p_local_on_surface);
	negat_na(&v_eye, pix->r_dir); // PIX_R_DIR!!! A REVOIR POUR RECURSIVITE
	if (pix->obj_a == SPHERE)
		normal_sphere(mem_shuttle);
	if (pix->obj_a == CYLINDER)
	{
		normal_cylinder(mem_shuttle, obj);
	}
	else if (pix->obj_a == PLAN)
		copy_coord(mem_shuttle->v_norm_parral, obj[2][mem_shuttle->obj_b]->v_axe);
	if (dot_product(mem_shuttle->v_norm_parral, &v_eye) < 0)
			negat_na(mem_shuttle->v_norm_parral, mem_shuttle->v_norm_parral);
}

void	normal_cylinder(t_mem *mem_shuttle, t_obj ***obj)
{
	t_coord	local_normal_vec;

	init_matrix_zero(mem_shuttle->transp_inv);
	matrix_point_multiplication_new(mem_shuttle->p_space, obj[3][mem_shuttle->obj_b]->m_inv,
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
	transpose_matrix(mem_shuttle->transp_inv, obj[3][mem_shuttle->obj_b]->m_inv);
	matrix_point_multiplication_new_2(mem_shuttle->v_norm_parral,
		mem_shuttle->transp_inv, &local_normal_vec);
	normalize_vector_na(mem_shuttle->v_norm_parral);
}

void	normal_sphere(t_mem *mem_shuttle)
{
	t_coord object_normal;

	object_normal.t = 0;
	matrix_point_multiplication_new(mem_shuttle->p_space,
		mem_shuttle->obj_inv, mem_shuttle->p_touch);
	substraction_p_to_v_na(&object_normal,
		mem_shuttle->p_space, mem_shuttle->origin_zero);
	normalize_vector_na(&object_normal);
	transpose_matrix(mem_shuttle->transp_inv, mem_shuttle->obj_inv);
	matrix_point_multiplication_new_2(mem_shuttle->v_norm_parral,
		mem_shuttle->transp_inv, &object_normal);
	normalize_vector_na(mem_shuttle->v_norm_parral);
}

/*PLUS BESOIN
void	prepare_comps_plan(t_mem *mem_shuttle,t_obj ***obj)
{
	copy_coord(mem_shuttle->v_norm_parral, obj[2][mem_shuttle->obj_b]->v_axe);
//	if (dot_product(mem_shuttle->v_norm_parral, mem_shuttle->v_eye) < 0)
//		negat_na(mem_shuttle->v_norm_parral, mem_shuttle->v_norm_parral);
}*/

/*
AVANT NETTOYAGE
void	prepare_computation(t_pix *pix, t_obj ***obj, t_mem *mem_shuttle)
{
	t_coord	term_for_p_local;
	t_coord	p_local_on_surface;

	scalar_mult_na(&term_for_p_local, mem_shuttle->r_dir_closest_obj, mem_shuttle->closestt);
	term_for_p_local.t = 1;
	addition_na(&p_local_on_surface, mem_shuttle->r_origin_closest_obj, &term_for_p_local);
	matrix_point_multiplication_new(mem_shuttle->p_touch,
		obj[pix->obj_a][pix->obj_b]->m_transf, &p_local_on_surface);
	negat_na(mem_shuttle->v_eye, pix->r_dir); // PIX_R_DIR!!! A REVOIR POUR RECURSIVITE
	if (pix->obj_a == SPHERE)
	{
		normal_at_na(mem_shuttle);
		if (dot_product(mem_shuttle->v_norm_parral, mem_shuttle->v_eye) < 0)
			negat_na(mem_shuttle->v_norm_parral, mem_shuttle->v_norm_parral);
	}
	if (pix->obj_a == CYLINDER)
	{
		normal_at_cyl(mem_shuttle, obj);
		if (dot_product(mem_shuttle->v_norm_parral, mem_shuttle->v_eye) < 0)
			negat_na(mem_shuttle->v_norm_parral, mem_shuttle->v_norm_parral);
	}
	else if (pix->obj_a == PLAN)
		prepare_comps_plan(mem_shuttle, obj);
}

void	prepare_comps_plan(t_mem *mem_shuttle,t_obj ***obj)
{
	copy_coord(mem_shuttle->v_norm_parral, obj[2][mem_shuttle->obj_b]->v_axe);
	if (dot_product(mem_shuttle->v_norm_parral, mem_shuttle->v_eye) < 0)
		negat_na(mem_shuttle->v_norm_parral, mem_shuttle->v_norm_parral);
}

void	normal_at_cyl(t_mem *mem_shuttle, t_obj ***obj)
{
	t_coord	local_normal_vec;

	matrix_point_multiplication_new(mem_shuttle->p_space, obj[3][mem_shuttle->obj_b]->m_inv,
		mem_shuttle->p_touch);
	if (mem_shuttle->t_count == 8)
	{
		vector_fill(&local_normal_vec, 0, -1, 0);
	}
	else if (mem_shuttle->t_count == 9)
	{
		vector_fill(&local_normal_vec, 0, 1, 0);
	}	
	else
	{
		local_normal_vec.x = mem_shuttle->p_space->x;
		local_normal_vec.y = 0;
		local_normal_vec.z = mem_shuttle->p_space->z;
	}
	local_normal_vec.t = 0;
	normalize_vector_na(&local_normal_vec);
	transpose_matrix(mem_shuttle->transp_inv, obj[3][mem_shuttle->obj_b]->m_inv);
	matrix_point_multiplication_new_2(mem_shuttle->v_norm_parral,
		mem_shuttle->transp_inv, &local_normal_vec);
	normalize_vector_na(mem_shuttle->v_norm_parral);
}

void	normal_at_na(t_mem *mem_shuttle)
{
	t_coord object_normal;

	object_normal.t = 0;
	matrix_point_multiplication_new(mem_shuttle->p_space,
		mem_shuttle->obj_inv, mem_shuttle->p_touch);
	substraction_p_to_v_na(&object_normal,
		mem_shuttle->p_space, mem_shuttle->origin_zero);
	normalize_vector_na(&object_normal);
	transpose_matrix(mem_shuttle->transp_inv, mem_shuttle->obj_inv);
	matrix_point_multiplication_new_2(mem_shuttle->v_norm_parral,
		mem_shuttle->transp_inv, &object_normal);
	normalize_vector_na(mem_shuttle->v_norm_parral);
}


*/