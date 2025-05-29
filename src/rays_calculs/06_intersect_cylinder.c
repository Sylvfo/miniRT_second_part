/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_intersect_cylinder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:29:35 by syl               #+#    #+#             */
/*   Updated: 2025/05/29 16:28:36 by syl              ###   ########.fr       */
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

void	handle_cap(t_mem *memory_shuttle, int cyl_n, float y_pos, int cap_type)
{
	float	t;

	t = (y_pos - memory_shuttle->r_origin_m->y)
		/ memory_shuttle->r_dir_m->y;
	if (check_cap(memory_shuttle, t) == true
		&& t < memory_shuttle->closestt)//&& t < pix->hits[3][cyl_n]->t2)
	{
		memory_shuttle->t_count = cap_type;
		memory_shuttle->closestt = t;
		memory_shuttle->obj_a = 3;
		memory_shuttle->obj_b = cyl_n;
	}
}

void	intersect_caps(t_mem *memory_shuttle, int cyl_n)
{
	if (fabs(memory_shuttle->r_dir_m->y) < 0.0001)
		return ;
	handle_cap(memory_shuttle, cyl_n, -1, 8);//up
	handle_cap(memory_shuttle, cyl_n, 1, 9);//down
}

void	intersect_cylinder(t_mem *memory_shuttle, int cyl_n)
{
	float	a;
	float	b;
	float	c;
	float	discriminant;

	a = memory_shuttle->r_dir_m->x * memory_shuttle->r_dir_m->x
		+ memory_shuttle->r_dir_m->z * memory_shuttle->r_dir_m->z;
	if (fabs(a) < EPSILON)
		return ;
	b = 2 * memory_shuttle->r_origin_m->x * memory_shuttle->r_dir_m->x
		+ 2 * memory_shuttle->r_origin_m->z * memory_shuttle->r_dir_m->z;
	c = memory_shuttle->r_origin_m->x * memory_shuttle->r_origin_m->x
		+ memory_shuttle->r_origin_m->z * memory_shuttle->r_origin_m->z
		- 1;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return ;
	
	memory_shuttle->t_count = 2;
	cut_cylinder(memory_shuttle, cyl_n, (-b - simple_sqrt(discriminant)) / (2 * a),
		(-b + simple_sqrt(discriminant)) / (2 * a));
	intersect_caps(memory_shuttle, cyl_n);
}

//void	cut_cylinder(t_pix *pix, int cyl_n, float t1, float t2)
void	cut_cylinder(t_mem *memory_shuttle, int cyl_n, float t1, float t2)
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
		result.t1 = t1;
		result.t_count++;
	}
	closestt(memory_shuttle, result, 3, cyl_n);
}

// ANCIENNES
/*
void	cut_cylinder(t_pix *pix, int cyl_n, float t1, float t2)
{
	float	y1;
	float	y2;
	float	tmp;

	if (t1 > t2)
	{
		tmp = t1;
		t1 = t2;
		t2 = tmp;
	}
	y1 = pix->hits[3][cyl_n]->r_origin->y + t1 * pix->hits[3][cyl_n]->r_dir->y;
	if (-1 < y1 && y1 < 1)
	{
		pix->hits[3][cyl_n]->t1 = t1;
		pix->hits[3][cyl_n]->t_count = 1;
	}
	y2 = pix->hits[3][cyl_n]->r_origin->y + t2 * pix->hits[3][cyl_n]->r_dir->y;
	if (-1 < y2 && y2 < 1)
	{
		pix->hits[3][cyl_n]->t2 = t2;
		pix->hits[3][cyl_n]->t_count++;
	}
}

bool	check_cap(t_pix *pix, float t, int cyl_n)
{
	float	x;
	float	z;

	x = pix->hits[3][cyl_n]->r_origin->x + t * pix->hits[3][cyl_n]->r_dir->x;
	z = pix->hits[3][cyl_n]->r_origin->z + t * pix->hits[3][cyl_n]->r_dir->z;
	if (x * x + z * z <= 1)
		return (true);
	return (false);
}

bool	handle_cap(t_pix *pix, int cyl_n, float y_pos, int cap_type)
{
	float	t;

	t = (y_pos - pix->hits[3][cyl_n]->r_origin->y)
		/ pix->hits[3][cyl_n]->r_dir->y;
	if (check_cap(pix, t, cyl_n) == true
		&& t < pix->hits[3][cyl_n]->t1 && t < pix->hits[3][cyl_n]->t2)
	{
		pix->hits[3][cyl_n]->t_count = cap_type;
		if (cap_type == 8)
			pix->hits[3][cyl_n]->t2 = t;
		else
			pix->hits[3][cyl_n]->t1 = t;
		return (true);
	}
	return (false);
}

void	intersect_caps(t_pix *pix, int cyl_n)
{
	if (fabs(pix->hits[3][cyl_n]->r_dir->y) < 0.0001)
		return ;
	if (pix->obj[3][cyl_n]->closed_down == true)
		handle_cap(pix, cyl_n, -1, 8);
	pix->obj[3][cyl_n]->closed_up = true;
	if (pix->obj[3][cyl_n]->closed_up == true)
		handle_cap(pix, cyl_n, 1, 9);
}

void	intersect_cylinder(t_pix *pix, int cyl_n)
{
	float	a;
	float	b;
	float	c;
	float	discriminant;

	a = pix->hits[3][cyl_n]->r_dir->x * pix->hits[3][cyl_n]->r_dir->x
		+ pix->hits[3][cyl_n]->r_dir->z * pix->hits[3][cyl_n]->r_dir->z;
	if (fabs(a) < EPSILON)
		return ;
	b = 2 * pix->hits[3][cyl_n]->r_origin->x * pix->hits[3][cyl_n]->r_dir->x
		+ 2 * pix->hits[3][cyl_n]->r_origin->z * pix->hits[3][cyl_n]->r_dir->z;
	c = pix->hits[3][cyl_n]->r_origin->x * pix->hits[3][cyl_n]->r_origin->x
		+ pix->hits[3][cyl_n]->r_origin->z * pix->hits[3][cyl_n]->r_origin->z
		- 1;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return ;
	pix->hits[3][cyl_n]->t_count = 2;
	cut_cylinder(pix, cyl_n, (-b - simple_sqrt(discriminant)) / (2 * a),
		(-b + simple_sqrt(discriminant)) / (2 * a));
	intersect_caps(pix, cyl_n);
}*/