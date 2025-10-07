/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_refraction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:14:49 by syl               #+#    #+#             */
/*   Updated: 2025/10/07 21:07:23 by syl              ###   ########.fr       */
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
		mem_shuttle->prev_refraction / scene->obj[mem_shuttle->obj_a][mem_shuttle->obj_b]->indice_refract);
	clean_memory_shuttle_refl(mem_shuttle);
}

void vect_refraction(t_coord *r_base_dir, t_coord *v_normal, float indice_refraction)
{
	double snell_condition;
	double cosi;
	
	cosi = -fmax(-1.0, fmin(1.0, dot_product(r_base_dir, v_normal)));
	if (cosi < 0.0)
	{
		cosi = -cosi;
		negat_na(v_normal, v_normal);
		indice_refraction = 1.0 / indice_refraction;
	}
	snell_condition = 1.0 - indice_refraction * indice_refraction * (1.0 - cosi * cosi);
	if (snell_condition < 0.0)
	{
		double dp = dot_product(r_base_dir, v_normal);
		r_base_dir->x = r_base_dir->x - 2.0 * dp * v_normal->x;
		r_base_dir->y = r_base_dir->y - 2.0 * dp * v_normal->y;
		r_base_dir->z = r_base_dir->z - 2.0 * dp * v_normal->z;
		r_base_dir->t = 0;
		return;
	}
	snell_condition = sqrt(snell_condition);
	scalar_mult_na(r_base_dir, r_base_dir, indice_refraction);
	scalar_mult_na(v_normal, v_normal, (indice_refraction * cosi - snell_condition));
	addition_vect(r_base_dir, r_base_dir, v_normal);
}
/* notes
void vect_refraction(t_coord *r_base_dir, t_coord *v_normal, float indice_refraction)
{
	double snell_condition;
	double cosi;
	
	cosi = -fmax(-1.0, fmin(1.0, dot_product(r_base_dir, v_normal)));
	if (cosi < 0.0) // on est à l'intérieur sortant : inverse la normale et l'eta
	{
		cosi = -cosi;
		negat_na(v_normal, v_normal);
		indice_refraction = 1.0 / indice_refraction;
	}
	snell_condition = 1.0 - indice_refraction * indice_refraction * (1.0 - cosi * cosi);
	if (snell_condition < 0.0)// gérer les petites erreurs numériques
	{
		double dp = dot_product(r_base_dir, v_normal);// Réflexion totale interne -> retourner le vecteur réfléchi
		r_base_dir->x = r_base_dir->x - 2.0 * dp * v_normal->x;
		r_base_dir->y = r_base_dir->y - 2.0 * dp * v_normal->y;
		r_base_dir->z = r_base_dir->z - 2.0 * dp * v_normal->z;
		r_base_dir->t = 0;
		return;
	}
	snell_condition = sqrt(snell_condition);
	scalar_mult_na(r_base_dir, r_base_dir, indice_refraction);
	scalar_mult_na(v_normal, v_normal, (indice_refraction * cosi - snell_condition));
	addition_vect(r_base_dir, r_base_dir, v_normal);
}
*/