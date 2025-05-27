/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_prepare_comps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:00:25 by syl               #+#    #+#             */
/*   Updated: 2025/05/27 16:30:42 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//
void	prepare_computation(t_pix *pix, t_obj ***obj, t_mem *mem_shuttle)
{
	t_coord	term_for_p_local;
	t_coord	p_local_on_surface;

	term_for_p_local.t = 1;
	term_for_p_local.x = 0;
	term_for_p_local.y = 0;
	term_for_p_local.z = 0;

	p_local_on_surface.t = 1;
	p_local_on_surface.x = 0;
	p_local_on_surface.y = 0;
	p_local_on_surface.z = 0;

	scalar_mult_na(&term_for_p_local, mem_shuttle->r_dir_m, mem_shuttle->closestt);
	printf("closestt %.4f \n", mem_shuttle->closestt);
//	print_vector(mem_shuttle->r_dir_m);
//	print_point(&term_for_p_local);
	addition_na(&p_local_on_surface, mem_shuttle->r_origin_m, &term_for_p_local);
	p_local_on_surface.t = 1;
	matrix_point_multiplication_new(mem_shuttle->p_touch,
		obj[1][pix->obj_b]->m_transf, &p_local_on_surface);
	print_point(&p_local_on_surface);
	print_point(mem_shuttle->p_touch);
/*	if (pix->obj_b == 0)// 	MATRIX PAREIL OK
		print_matrix_44(obj[1][pix->obj_b]->m_transf);*/
	negat_na(mem_shuttle->v_eye, pix->r_dir); // PIX_R_DIR!!! A REVOIR POUR RECURSIVITE
	if (pix->obj_a == SPHERE)
	{
		//PF il y a peut des des problemes la dedans. J ai pas encore trop bien verifie. 
		normal_at_na(mem_shuttle);
		// PF ca c est quand on est dedans une sphere je crois
		if (dot_product(mem_shuttle->v_norm_parral, mem_shuttle->v_eye) < 0)
			negat_na(mem_shuttle->v_norm_parral, mem_shuttle->v_norm_parral);
	}
	//PF On fera les autres formes apres
//	print_point(mem_shuttle->p_touch);
/*	if (pix->comps->type == CYLINDER)
	{
		normal_at_cyl(pix->comps);
		if (dot_product(pix->comps->v_norm_parral, pix->comps->v_eye) < 0)
			negat_na(pix->comps->v_norm_parral, pix->comps->v_norm_parral);
	}*/
//	else if (pix->comps->type == PLAN)
//		prepare_comps_plan(pix);
}

/* A VOIR APRES
void	normal_at_cyl(t_comps *comps)
{
	t_coord	local_normal_vec;

	matrix_point_multiplication_new(comps->p_space, comps->obj_inv,
		comps->p_touch);
	if (comps->t_count == 8)
		vector_fill(&local_normal_vec, 0, -1, 0);
	else if (comps->t_count == 9)
		vector_fill(&local_normal_vec, 0, 1, 0);
	else
	{
		local_normal_vec.x = comps->p_space->x;
		local_normal_vec.y = 0;
		local_normal_vec.z = comps->p_space->z;
	}
	local_normal_vec.t = 0;
	normalize_vector_na(&local_normal_vec);
	transpose_matrix(comps->transp_inv, comps->obj_inv);
	matrix_point_multiplication_new_2(comps->v_norm_parral,
		comps->transp_inv, &local_normal_vec);
	normalize_vector_na(comps->v_norm_parral);
}
//A VOIR APRES
void	normal_caps(t_comps *comps)
{
	float	dist;

	dist = (comps->p_space->x * comps->p_space->x)
		+ (comps->p_space->z * comps->p_space->z);
	if (dist <= 1 && fabs(comps->p_space->y - comps->height) < EPSILON)
	{
		comps->v_norm_parral->x = 0;
		comps->v_norm_parral->y = 1;
		comps->v_norm_parral->z = 0;
		return ;
	}
	if (dist <= 1 && fabs(comps->p_space->y + comps->height) < EPSILON)
	{
		comps->v_norm_parral->x = 0;
		comps->v_norm_parral->y = -1;
		comps->v_norm_parral->z = 0;
		return ;
	}
	comps->v_norm_parral->x = comps->p_space->x;
	comps->v_norm_parral->y = 0;
	comps->v_norm_parral->z = comps->p_space->z;
}
*/

//RENOMMER NORMAL SPHERE?
void	normal_at_na(t_mem *mem_shuttle)
{
	printf("enter in normal at\n");
	matrix_point_multiplication_new(mem_shuttle->p_space,
		mem_shuttle->obj_inv, mem_shuttle->p_touch);
	print_point(mem_shuttle->p_touch);
	print_point(mem_shuttle->p_space);
	substraction_p_to_v_na(mem_shuttle->object_normal,
		mem_shuttle->p_space, mem_shuttle->origin_zero);
	normalize_vector_na(mem_shuttle->object_normal);
	transpose_matrix(mem_shuttle->transp_inv, mem_shuttle->obj_inv);
	matrix_point_multiplication_new_2(mem_shuttle->v_norm_parral,
		mem_shuttle->transp_inv, mem_shuttle->object_normal);
	normalize_vector_na(mem_shuttle->v_norm_parral);
	printf("hehre\n");
}

/* // NORMALEMENT PLUS BESOIN
void	prepare_computation(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			if (pix[x][y]->comps->type != NONE)
				prepare_computation_pix(pix[x][y]);
			y++;
		}
		x++;
	}
}*/

//ANCIENNE QUI FONCTIONNE
/*
void	normal_at_cyl(t_comps *comps)
{
	t_coord	local_normal_vec;

	matrix_point_multiplication_new(comps->p_space, comps->obj_inv,
		comps->p_touch);
	if (comps->t_count == 8)
		vector_fill(&local_normal_vec, 0, -1, 0);
	else if (comps->t_count == 9)
		vector_fill(&local_normal_vec, 0, 1, 0);
	else
	{
		local_normal_vec.x = comps->p_space->x;
		local_normal_vec.y = 0;
		local_normal_vec.z = comps->p_space->z;
	}
	local_normal_vec.t = 0;
	normalize_vector_na(&local_normal_vec);
	transpose_matrix(comps->transp_inv, comps->obj_inv);
	matrix_point_multiplication_new_2(comps->v_norm_parral,
		comps->transp_inv, &local_normal_vec);
	normalize_vector_na(comps->v_norm_parral);
}

void	prepare_computation_pix(t_pix *pix)
{
	t_coord	term_for_p_local;
	t_coord	p_local_on_surface;

	scalar_mult_na(&term_for_p_local, pix->comps->r_dir, pix->comps->closestt);
	addition_na(&p_local_on_surface, pix->comps->r_origin, &term_for_p_local);
	matrix_point_multiplication_new(pix->comps->p_touch,
		pix->comps->obj->m_transf, &p_local_on_surface);
	negat_na(pix->comps->v_eye, pix->r_dir);
	if (pix->comps->type == SPHERE)
	{
		normal_at_na(pix->comps);
		if (dot_product(pix->comps->v_norm_parral, pix->comps->v_eye) < 0)
			negat_na(pix->comps->v_norm_parral, pix->comps->v_norm_parral);
	}
	if (pix->comps->type == CYLINDER)
	{
		normal_at_cyl(pix->comps);
		if (dot_product(pix->comps->v_norm_parral, pix->comps->v_eye) < 0)
			negat_na(pix->comps->v_norm_parral, pix->comps->v_norm_parral);
	}
	else if (pix->comps->type == PLAN)
		prepare_comps_plan(pix);
}

void	normal_caps(t_comps *comps)
{
	float	dist;

	dist = (comps->p_space->x * comps->p_space->x)
		+ (comps->p_space->z * comps->p_space->z);
	if (dist <= 1 && fabs(comps->p_space->y - comps->height) < EPSILON)
	{
		comps->v_norm_parral->x = 0;
		comps->v_norm_parral->y = 1;
		comps->v_norm_parral->z = 0;
		return ;
	}
	if (dist <= 1 && fabs(comps->p_space->y + comps->height) < EPSILON)
	{
		comps->v_norm_parral->x = 0;
		comps->v_norm_parral->y = -1;
		comps->v_norm_parral->z = 0;
		return ;
	}
	comps->v_norm_parral->x = comps->p_space->x;
	comps->v_norm_parral->y = 0;
	comps->v_norm_parral->z = comps->p_space->z;
}

void	normal_at_na(t_comps *comps)
{
	matrix_point_multiplication_new(comps->p_space,
		comps->obj_inv, comps->p_touch);
	substraction_p_to_v_na(comps->object_normal,
		comps->p_space, comps->origin_zero);
	normalize_vector_na(comps->object_normal);
	transpose_matrix(comps->transp_inv, comps->obj_inv);
	matrix_point_multiplication_new_2(comps->v_norm_parral,
		comps->transp_inv, comps->object_normal);
	normalize_vector_na(comps->v_norm_parral);
}

void	prepare_computation(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			if (pix[x][y]->comps->type != NONE)
				prepare_computation_pix(pix[x][y]);
			y++;
		}
		x++;
	}
}*/