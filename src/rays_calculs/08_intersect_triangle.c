/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_intersect_cylinder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:29:35 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 14:33:02 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	cal_intersect(t_mem *mem, t_obj ***obj, int n, t_intertt result)
{
	t_coord	cross_e;
	float	det;
	float	f;
	float	u[2];
	t_coord	p1_to_origin;

	substraction_p_to_v_na(&p1_to_origin, mem->r_origin_m, obj[5][n]->tr_p1);
	cross_product_na(&cross_e, mem->r_dir_m, obj[TRIANGLE][n]->tr_e2);
	det = dot_product(obj[TRIANGLE][n]->tr_e1, &cross_e);
	if (fabs(det) < EPSILON)
		return ;
	f = 1.0 / det;
	u[0] = f * dot_product(&p1_to_origin, &cross_e);
	if (u[0] < 0.0 || u[0] > 1.0)
		return ;
	cross_product_na(&cross_e, &p1_to_origin, obj[TRIANGLE][n]->tr_e1);
	u[1] = f * dot_product(mem->r_dir_m, &cross_e);
	if (u[1] < 0.0 || (u[0] + u[1]) > 1.0)
		return ;
	result.t1 = f * dot_product(obj[TRIANGLE][n]->tr_e2, &cross_e);
	result.t2 = (float)INT_MAX;
	result.t_count = 1;
	if (result.t1 < EPSILON)
		return ;
	closestt(mem, result, TRIANGLE, n);
}

void	intersect_triangle(t_mem *memory_shuttle, t_obj ***obj, int n)
{
	t_intertt	result;

	result.t_count = 0;
	cal_intersect(memory_shuttle, obj, n, result);
}
