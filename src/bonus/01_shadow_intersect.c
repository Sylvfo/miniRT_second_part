/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_shadow_intersect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:02:36 by syl               #+#    #+#             */
/*   Updated: 2025/10/08 17:49:57 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	intersect_plan_shadow_bonus(t_mem *memory_shuttle, t_obj *obj)
{
	return;
	t_intertt	result;

	printf("la");
	if (fabs(memory_shuttle->r_dir_m->y) < EPSILON)
		return ;
	result.t1 = -(memory_shuttle->r_origin_m->y / memory_shuttle->r_dir_m->y);
	result.t2 = INT_MAX;
	result.t_count = 1;
	
	take_shadow_color(memory_shuttle, result, obj);
}

//void	intersect_sphere_shadow_bonus(t_mem *memory_shuttle)
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
//	closestt(memory_shuttle, result, SPHERE, sph_num);
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

//	t_coord		*v_light_to_point;
//	t_coord		*p_light_to_point;// a init et free
void	apply_transformation_bonus(t_obj *obj, t_mem *memory_shuttle)
{
	matrix_point_multiplication_new(memory_shuttle->r_origin_m,
		obj->m_inv, memory_shuttle->p_light_to_point);
	matrix_point_multiplication_new(memory_shuttle->r_dir_m,
		obj->m_inv, memory_shuttle->v_light_to_point);
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
/*
//inutlie?
void	clean_memory_shuttle_light(t_mem *mem_shuttle)
{
	//vector_fill(mem_shuttle->r_base_dir, 0, 0, 0);
	//vector_fill(mem_shuttle->r_dir_m, 0, 0, 0);
	point_fill(mem_shuttle->r_base_origin, 0, 0, 0);
	point_fill(mem_shuttle->r_origin_m, 0, 0, 0);
	mem_shuttle->closestt = INT_MAX;
	mem_shuttle->obj_a = 0;
	mem_shuttle->obj_b = 0;
	mem_shuttle->t_count = 0;
	mem_shuttle->distance_light_p_touch = 0.0;
	mem_shuttle->p_space->x = 0.0;
	mem_shuttle->p_space->y = 0.0;
	mem_shuttle->p_space->z = 0.0;
	mem_shuttle->p_touch->x = 0.0;
	mem_shuttle->p_touch->y = 0.0;
	mem_shuttle->p_touch->z = 0.0;
	vector_fill(mem_shuttle->v_light_to_point, 0, 0, 0);
	vector_fill(mem_shuttle->v_point_to_light, 0, 0, 0);
	vector_fill(mem_shuttle->reflect_dir, 0, 0, 0);
	vector_fill(mem_shuttle->scalar, 0, 0, 0);
	vector_fill(mem_shuttle->view_dir, 0, 0, 0);
	init_matrix_zero(mem_shuttle->obj_inv);
	init_matrix_zero(mem_shuttle->transp_inv);
}*/