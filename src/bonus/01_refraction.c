/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_refraction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:14:49 by syl               #+#    #+#             */
/*   Updated: 2026/01/20 16:13:05 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_color	refraction(t_scene *scene, t_mem *mem_shtle)
{
	t_color	color;

	next_ray_refraction(scene, mem_shtle);
	color = raytracer_bonus(NULL, scene, mem_shtle);
	return (color);
}

void	next_ray_refraction(t_scene *scene, t_mem *mem_shuttle)
{
	t_coord	offset;

	offset = scalar_mult_ret(mem_shuttle->r_base_dir, 0.02f);
	addition_na(mem_shuttle->r_base_origin, mem_shuttle->p_touch, &offset);
	vect_refraction(mem_shuttle->r_base_dir, mem_shuttle->v_norm_parral,
		mem_shuttle->prev_refraction
		/ scene->obj[mem_shuttle->obj_a][mem_shuttle->obj_b]->indice_refract);
	clean_memory_shuttle_refl(mem_shuttle);
}

void	vect_refraction(t_coord *r_base_dir, t_coord *v_normal, float ind_refr)
{
	double	snell_condition;
	double	cosi;
	double	dp;

	cosi = -fmax(-1.0, fmin(1.0, dot_product(r_base_dir, v_normal)));
	if (cosi < 0.0)
	{
		cosi = -cosi;
		negat_na(v_normal, v_normal);
		ind_refr = 1.0 / ind_refr;
	}
	snell_condition = 1.0 - ind_refr * ind_refr * (1.0 - cosi * cosi);
	if (snell_condition < 0.0)
	{
		dp = dot_product(r_base_dir, v_normal);
		r_base_dir->x = r_base_dir->x - 2.0 * dp * v_normal->x;
		r_base_dir->y = r_base_dir->y - 2.0 * dp * v_normal->y;
		r_base_dir->z = r_base_dir->z - 2.0 * dp * v_normal->z;
		r_base_dir->t = 0;
		return ;
	}
	snell_condition = sqrt(snell_condition);
	scalar_mult_na(r_base_dir, r_base_dir, ind_refr);
	scalar_mult_na(v_normal, v_normal, (ind_refr * cosi - snell_condition));
	addition_vect(r_base_dir, r_base_dir, v_normal);
}

void	cal_intersect_bonus(t_mem *mem, t_obj ***obj, int n, t_intertt result)
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
	take_shadow_color(mem, result, obj[TRIANGLE][n]);
}
