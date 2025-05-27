/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_intersect_sphere_plan.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:04:59 by syl               #+#    #+#             */
/*   Updated: 2025/05/27 14:59:24 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
	A REFAIRE
void	intersect_plan(t_pix *pix, int plan_num)
{
	if (fabs(pix->hits[2][plan_num]->r_dir->y) < EPSILON)
	{
		pix->hits[2][plan_num]->t_count = 0;
		pix->hits[2][plan_num]->t1 = INT_MAX;
		pix->hits[2][plan_num]->t2 = INT_MAX;
		pix->hits[2][plan_num]->type = PLAN;
		return ;
	}
	pix->hits[2][plan_num]->t1 = -(pix->hits[2][plan_num]->r_origin->y
			/ pix->hits[2][plan_num]->r_dir->y);
	pix->hits[2][plan_num]->t2 = INT_MAX;
	pix->hits[2][plan_num]->t_count = 1;
	pix->hits[2][plan_num]->type = PLAN;
}*/

/*
	ORIGINALE A EFFACER
void	intersect_sphere(t_pix *pix, int sph_num)
{
	float	discriminant;
	float	a;
	float	b;
	float	c;

	substraction_p_to_v_na(pix->obj[1][sph_num]->v_sph_camera,
		pix->hits[1][sph_num]->r_origin, pix->cam->p_zero);
	a = dot_product(pix->hits[1][sph_num]->r_dir, pix->hits[1][sph_num]->r_dir);
	b = 2 * dot_product(pix->hits[1][sph_num]->r_dir,
			pix->obj[1][sph_num]->v_sph_camera);
	c = dot_product(pix->obj[1][sph_num]->v_sph_camera,
			pix->obj[1][sph_num]->v_sph_camera) - 1;
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 1e-6)
	{
		pix->hits[1][sph_num]->t_count = 0;
		pix->hits[1][sph_num]->t1 = INT_MAX;
		pix->hits[1][sph_num]->t2 = INT_MAX;
		return ;
	}
	pix->hits[1][sph_num]->t_count = 2;
	pix->hits[1][sph_num]->t1 = (-b - sqrt(discriminant)) / (2 * a);
	pix->hits[1][sph_num]->t2 = (-b + sqrt(discriminant)) / (2 * a);
	pix->hits[1][sph_num]->type = SPHERE;
	return ;
}*/


void	intersect_sphere(t_pix *pix, int sph_num, t_mem *memory_shuttle)
{
	float	discriminant;
	float	a;
	float	b;
	float	c;
	t_intertt result;

	substraction_p_to_v_na(memory_shuttle->v_sph_camera,
		memory_shuttle->r_origin_m, memory_shuttle->origin_zero);
	a = dot_product(memory_shuttle->r_dir_m, memory_shuttle->r_dir_m);
	b = 2 * dot_product(memory_shuttle->r_dir_m,
			memory_shuttle->v_sph_camera);
	c = dot_product(memory_shuttle->v_sph_camera,
			memory_shuttle->v_sph_camera) - 1;
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 1e-6)
	{
		return ;
	}	
	
	//SIMPLE SQRT!!!!!!!!!!!!
	result.t1 = (-b - sqrt(discriminant)) / (2 * a);
	result.t2 = (-b + sqrt(discriminant)) / (2 * a);
	result.t_count = 2;
	result.closestt = 0.0;
	closestt(memory_shuttle, result, sph_num);
	return ;
}

void	closestt(t_mem *memory_shuttle, t_intertt result, int sph_num)
{
//	printf("l");
	if (result.t1 < memory_shuttle->closestt)
	{
	//	printf("-");
		memory_shuttle->closestt = result.t1;
		memory_shuttle->obj_a = 1;
		memory_shuttle->obj_b = sph_num;
	//	memory_shuttle->closestt = result.closestt;
	}
	if (result.t2 < memory_shuttle->closestt)
	{
	//	printf(".");
		memory_shuttle->closestt = result.t2;
		memory_shuttle->obj_a = 1;
		memory_shuttle->obj_b = sph_num;
	}
}