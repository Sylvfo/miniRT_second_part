/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_refraction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:14:49 by syl               #+#    #+#             */
/*   Updated: 2025/10/07 19:04:24 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
//radian
float angle_between_vectors(t_coord *v1, t_coord *v2)
{
	float dot;
	float len;
	float cos_angle;

	dot = dot_product(v1, v2);
	len = length_vector(v1) * length_vector(v2);
	if (len == 0)
		return 1.0;// vecteurs nuls => angle nul arbitrairement
	cos_angle = dot / len;
	if (cos_angle > 1.0)
		cos_angle = 1.0;
	else if (cos_angle < -1.0)
		cos_angle = -1.0;
	return (cos_angle);
}*/

t_color	refraction(t_scene *scene, t_mem *mem_shtle)
{
	t_color	color;

	/////////////////////////
	next_ray_refraction(scene, mem_shtle);
	////////////////////////////// RAYTRACER
	main_intersections(scene->obj, mem_shtle);
	copy_matrix_44(mem_shtle->obj_inv,
		scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->m_inv);
	mem_shtle->prev_refraction = scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->indice_refract;
	if (mem_shtle->obj_a == 0)
	{
		color = background_color(scene->obj[0][0], scene->lux[0][0]);
		return (color);
	}
	prepare_computation(mem_shtle, scene->obj);
	color = pattern(mem_shtle, scene);///???
	color = lighting(scene, mem_shtle,
			*(scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->color));
	//////////////////////////////
	mem_shtle->recursivity_level++;
	//recursion reflexion//
	if (mem_shtle->recursivity_level < MAX_RECURSIVITY)
		color = next_ray(scene, mem_shtle,  color);
	return (color);
}

//calcul next_ray_reflection il faut trouver
//mem_shuttle->r_base_origin
//mem_shuttle->r_base_dir
void	next_ray_refraction(t_scene *scene, t_mem *mem_shuttle)
{
	t_coord	offset;

	//pour déplacer l origine du vecteur sur p touch
	offset = scalar_mult_ret(mem_shuttle->r_base_dir, 0.02f);
	addition_na(mem_shuttle->r_base_origin, mem_shuttle->p_touch, &offset);

	// modifier le ray
	vect_refraction(mem_shuttle->r_base_dir, mem_shuttle->v_norm_parral, mem_shuttle->prev_refraction / scene->obj[mem_shuttle->obj_a][mem_shuttle->obj_b]->indice_refract);
	//clean
	clean_memory_shuttle_refl(mem_shuttle);
}

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