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

// Intersection rayon-plan pour la base

t_intertt	cut_cone(t_mem *memory_shuttle, float t1, float t2)
{
	float		y1;
	float		y2;
	float		tmp;
	t_intertt	result;

	result = init_intertt();
	if (t1 > t2)
	{
		tmp = t1;
		t1 = t2;
		t2 = tmp;
	}
	y1 = memory_shuttle->r_origin_m->y + t1 * memory_shuttle->r_dir_m->y;
	if (-1 < y1 && y1 < 1)
	{
		result.t1 = t1;
		result.t_count = 1;
	}
	y2 = memory_shuttle->r_origin_m->y + t2 * memory_shuttle->r_dir_m->y;
	if (-1 < y2 && y2 < 1)
	{
		result.t2 = t2;
		result.t_count++;
	}
	return (result);
}

void	intersect_cone(t_mem *memory_shuttle, int cone_n)
{
	float		a;
	float		b;
	float		c;
	float		discriminant;
	t_intertt	result;

	a = pow(memory_shuttle->r_dir_m->x, 2) - \
pow(memory_shuttle->r_dir_m->y, 2) + pow(memory_shuttle->r_dir_m->z, 2);
	if (fabs(a) < 1.17549435e-38f)
		return ;
	b = 2 *(memory_shuttle->r_origin_m->x * memory_shuttle->r_dir_m->x - \
memory_shuttle->r_origin_m->y * memory_shuttle->r_dir_m->y + \
memory_shuttle->r_origin_m->z * memory_shuttle->r_dir_m->z);
	c = pow(memory_shuttle->r_origin_m->x, 2) - \
pow(memory_shuttle->r_origin_m->y, 2) + pow(memory_shuttle->r_origin_m->z, 2);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return ;
	if (a == 0)
		result = cut_cone(memory_shuttle, -c / (2 * b), -c / (2 * b));
	else
		result = cut_cone(memory_shuttle, (-b - sqrt(discriminant)) / (2 * a), \
(-b + sqrt(discriminant)) / (2 * a));
	result = intersect_caps(memory_shuttle, result);
	closestt(memory_shuttle, result, CONE, cone_n);
}
