/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_intersect_cylinder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:29:35 by syl               #+#    #+#             */
/*   Updated: 2025/05/31 20:45:21 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool	check_cap(t_mem *memory_shuttle, float t)
{
	float	x;
	float	z;

	x = memory_shuttle->r_origin_m->x + t * memory_shuttle->r_dir_m->x;
	z = memory_shuttle->r_origin_m->z + t * memory_shuttle->r_dir_m->z;
	if (x * x + z * z <= 1)
		return (true);
	return (false);
}

t_intertt	handle_cap(t_mem *memory_shuttle, t_intertt result, float y_pos)
{
	float	t;

	t = (y_pos - memory_shuttle->r_origin_m->y)
		/ memory_shuttle->r_dir_m->y;
	if (check_cap(memory_shuttle, t) == true && t < result.t1 && t < result.t2)// && t > 0)
	{
		if (y_pos == -1)
		{
			result.t2 = t;
			result.t_count = 8;
		}
		if (y_pos == 1)
		{
			result.t1 = t;
			result.t_count = 9;
		}
	}
	return (result);
}

t_intertt	intersect_caps(t_mem *memory_shuttle, t_intertt result)
{
	if (fabs(memory_shuttle->r_dir_m->y) < 1.17549435e-38f)
		return (result);
	// ici voir si les cylindres sont fermes dans les bonus....
	result = handle_cap(memory_shuttle, result, -1);
	result = handle_cap(memory_shuttle, result, 1);
	return (result);
}

void	intersect_cylinder(t_mem *memory_shuttle, int cyl_n)
{
	float	a;
	float	b;
	float	c;
	float	discriminant;
	t_intertt result;

	a = memory_shuttle->r_dir_m->x * memory_shuttle->r_dir_m->x
		+ memory_shuttle->r_dir_m->z * memory_shuttle->r_dir_m->z;
	if (fabs(a) < 1.17549435e-38f)
		return ;
	b = 2 * memory_shuttle->r_origin_m->x * memory_shuttle->r_dir_m->x
		+ 2 * memory_shuttle->r_origin_m->z * memory_shuttle->r_dir_m->z;
	c = memory_shuttle->r_origin_m->x * memory_shuttle->r_origin_m->x
		+ memory_shuttle->r_origin_m->z * memory_shuttle->r_origin_m->z
		- 1;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
	{
		return ;
	}
	result = cut_cylinder(memory_shuttle, (-b - sqrt(discriminant)) / (2 * a),
		(-b + sqrt(discriminant)) / (2 * a));
	result = intersect_caps(memory_shuttle, result);
	closestt(memory_shuttle, result, 3, cyl_n);
}

t_intertt	cut_cylinder(t_mem *memory_shuttle, float t1, float t2)
{
	float	y1;
	float	y2;
	float	tmp;
	t_intertt result;

	result.t1 = INT_MAX;
	result.t2 = INT_MAX;
	result.t_count = 0;
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


