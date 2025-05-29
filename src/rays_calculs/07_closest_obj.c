/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_closest_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:48:36 by syl               #+#    #+#             */
/*   Updated: 2025/05/29 15:58:34 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	closestt(t_mem *memory_shuttle, t_intertt result, int obj_type, int obj_num)// sph num changer en obj num
{
	if (result.t1 < memory_shuttle->closestt && result.t1 > 0)
	{
		//RAJOUTER DES TRUCS POUR AUTRES OBJETS?
		memory_shuttle->closestt = result.t1;
		memory_shuttle->obj_a = obj_type;
		memory_shuttle->obj_b = obj_num;
		memory_shuttle->t_count = 2;//??
		copy_coord(memory_shuttle->r_dir_closest_obj, memory_shuttle->r_dir_m);
		copy_coord(memory_shuttle->r_origin_closest_obj, memory_shuttle->r_origin_m);
	}
	if (result.t2 < memory_shuttle->closestt && result.t2 > 0)
	{
		memory_shuttle->closestt = result.t2;
		memory_shuttle->obj_a = obj_type;
		memory_shuttle->obj_b = obj_num;
		memory_shuttle->t_count = 2;//??
		copy_coord(memory_shuttle->r_dir_closest_obj, memory_shuttle->r_dir_m);
		copy_coord(memory_shuttle->r_origin_closest_obj, memory_shuttle->r_origin_m);
	}
}

void closest_obj_in_pix(t_pix *pix, t_mem *memory_shuttle)
{
	pix->obj_a = memory_shuttle->obj_a;
	pix->obj_b = memory_shuttle->obj_b;
}

//NORMALEMENT PLUS BESOIN....
/*
void	save_in_comps(t_pix *pix, int a, int b)
{
	pix->comps->t_count = pix->hits[a][b]->t_count;
	pix->comps->obj = pix->obj[a][b];
	if (pix->obj[a][b] && pix->obj[a][b]->color && pix->comps->obj_color)
		copy_color(pix->comps->obj_color, pix->obj[a][b]->color);
	copy_coord(pix->comps->r_dir, pix->hits[a][b]->r_dir);
	copy_coord(pix->comps->r_origin, pix->hits[a][b]->r_origin);
	pix->comps->type = pix->hits[a][b]->type;
	copy_matrix_44(pix->comps->obj_inv, pix->obj[a][b]->m_inv);
	if (pix->hits[a][b]->type == CYLINDER)
		pix->comps->height = pix->obj[a][b]->height;
	if (pix->hits[a][b]->type == PLAN || pix->hits[a][b]->type == CYLINDER)
		copy_coord(pix->comps->object_normal, pix->obj[a][b]->v_axe);
}

void	closest_obj(t_pix *pix)
{
	int	a;
	int	b;

	a = 1;
	while (pix->hits[a] != NULL)
	{
		b = 0;
		while (pix->hits[a][b] != NULL)
		{
			if (pix->hits[a][b]->t1 < pix->comps->closestt
					&& pix->hits[a][b]->t1 > 0)
			{
				pix->comps->closestt = pix->hits[a][b]->t1;
				save_in_comps(pix, a, b);
			}
			else if (pix->hits[a][b]->t2 < pix->comps->closestt
					&& pix->hits[a][b]->t2 > 0)
			{
				pix->comps->closestt = pix->hits[a][b]->t2;
				save_in_comps(pix, a, b);
			}
			b++;
		}
		a++;
	}
}

void	find_closest_obj(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			closest_obj(pix[x][y]);
			y++;
		}
		x++;
	}
}

void	prepare_comps_plan(t_pix *pix)
{
	copy_coord(pix->comps->v_norm_parral, pix->comps->obj->v_axe);
	normalize_vector_na(pix->comps->v_norm_parral);
	if (dot_product(pix->comps->v_norm_parral, pix->comps->v_eye) < 0)
		negat_na(pix->comps->v_norm_parral, pix->comps->v_norm_parral);
}*/
