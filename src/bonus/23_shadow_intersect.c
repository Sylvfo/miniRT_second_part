/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_shadow_intersect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:02:36 by syl               #+#    #+#             */
/*   Updated: 2026/01/20 16:17:53 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	intersect_plan_shadow_bonus(t_mem *memory_shuttle, t_obj *obj)
{
	t_intertt	result;

	return ;
	if (fabs(memory_shuttle->r_dir_m->y) < EPSILON)
		return ;
	result.t1 = -(memory_shuttle->r_origin_m->y / memory_shuttle->r_dir_m->y);
	result.t2 = INT_MAX;
	result.t_count = 1;
	take_shadow_color(memory_shuttle, result, obj);
}

void	intersect_sphere_shadow_bonus(t_mem *memory_shuttle, t_obj *obj)
{
	float		discriminant;
	float		a;
	float		b;
	float		c;
	t_intertt	result;

	substraction_p_to_v_na(memory_shuttle->v_sph_camera,
		memory_shuttle->r_origin_m, memory_shuttle->origin_zero);
	a = dot_product(memory_shuttle->r_dir_m, memory_shuttle->r_dir_m);
	b = 2 * dot_product(memory_shuttle->r_dir_m,
			memory_shuttle->v_sph_camera);
	c = dot_product(memory_shuttle->v_sph_camera,
			memory_shuttle->v_sph_camera) - 1;
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 1e-6)
		return ;
	result.t1 = (-b - simple_sqrt(discriminant)) / (2 * a);
	result.t2 = (-b + simple_sqrt(discriminant)) / (2 * a);
	result.t_count = 2;
	take_shadow_color(memory_shuttle, result, obj);
	return ;
}

void	intersect_cylinder_bonus(t_mem *memory_shuttle, t_obj *obj)
{
	float		a;
	float		b;
	float		c;
	float		discriminant;
	t_intertt	result;

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
	take_shadow_color(memory_shuttle, result, obj);
}

void	intersect_cone_bonus(t_mem *memory_shuttle, t_obj *obj)
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
	take_shadow_color(memory_shuttle, result, obj);
}
