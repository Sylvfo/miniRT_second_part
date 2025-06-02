/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_intersect_sphere_plan.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:04:59 by syl               #+#    #+#             */
/*   Updated: 2025/06/02 13:37:55 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	intersect_plan(t_mem *memory_shuttle, int plan_num)
{
	t_intertt result;

	if (fabs(memory_shuttle->r_dir_m->y) < EPSILON)
		return ;
	result.t1 = -(memory_shuttle->r_origin_m->y / memory_shuttle->r_dir_m->y);
	result.t2 = INT_MAX;
	result.t_count = 1;
	closestt(memory_shuttle, result, PLAN, plan_num);
}

void	intersect_sphere(t_mem *memory_shuttle, int sph_num)
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
	closestt(memory_shuttle, result, SPHERE, sph_num);
	return ;
}
