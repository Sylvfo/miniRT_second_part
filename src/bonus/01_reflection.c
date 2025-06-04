/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_reflection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:25:21 by syl               #+#    #+#             */
/*   Updated: 2025/06/02 14:25:29 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// a deplacer
void	addition_vect(t_coord *result, t_coord *p_v_1, t_coord *p_v_2)
{
	result->x = p_v_1->x + p_v_2->x;
	result->y = p_v_1->y + p_v_2->y;
	result->z = p_v_1->z + p_v_2->z;
	result->t = 0;
}

void next_ray_reflection(t_mem *memory_shuttle)
{
//	t_coord tmp;
//	t_coord tmp2;

	t_coord offset = scalar_mult_ret(memory_shuttle->v_norm_parral, 0.001f);
	addition_na(memory_shuttle->r_base_origin, memory_shuttle->p_touch, &offset);

//	copy_coord(memory_shuttle->r_base_origin, memory_shuttle->p_touch);//p touch est dans espace world
	vect_reflexion(memory_shuttle->r_base_dir, memory_shuttle->v_norm_parral);
// mettre un peu de distance
//	scalar_mult_na(&tmp, memory_shuttle->r_base_dir, 0.0001f);
//	addition_na(&tmp2, memory_shuttle->p_touch, &tmp);
//	copy_coord(memory_shuttle->r_base_dir, &tmp2);

	memory_shuttle->closestt = INT_MAX;
	clean_memory_shuttle_refl(memory_shuttle);
}

void vect_reflexion(t_coord *r_base_dir, t_coord *v_normal)
{
	float inner_product; //dot is the same
	t_coord v_scal;
	t_coord add;
	t_coord result;

	v_scal.t = 0;
	inner_product = dot_product(r_base_dir, v_normal);//=)
	v_scal = scalar_mult_ret(v_normal, (-2.0f * inner_product));
	addition_vect(&result, r_base_dir, &v_scal);
	result.t = 0;
	normalize_vector_na(&result);
	copy_coord(r_base_dir, &result);
}

void clean_memory_shuttle_refl(t_mem *memory_shuttle)
{
	vector_fill(memory_shuttle->r_dir_m, 0, 0, 0);
	point_fill(memory_shuttle->r_origin_m, 0, 0, 0);
	vector_fill(memory_shuttle->r_dir_closest_obj, 0, 0, 0);
	point_fill(memory_shuttle->r_origin_closest_obj, 0, 0, 0);

	vector_fill(memory_shuttle->v_sph_camera, 0, 0, 0);
	point_fill(memory_shuttle->p_touch, 0, 0, 0);
	vector_fill(memory_shuttle->v_norm_parral, 0, 0, 0);
	point_fill(memory_shuttle->p_space, 0, 0, 0);
	vector_fill(memory_shuttle->v_light_to_point, 0, 0, 0);
	vector_fill(memory_shuttle->v_point_to_light, 0, 0, 0);
	vector_fill(memory_shuttle->reflect_dir, 0, 0, 0);
	vector_fill(memory_shuttle->scalar, 0, 0, 0);
	vector_fill(memory_shuttle->view_dir, 0, 0, 0);
	memory_shuttle->t_count = 0;
	memory_shuttle->closestt = INT_MAX;
	memory_shuttle->obj_a = 0;
	memory_shuttle->obj_b = 0;
	init_matrix_zero(memory_shuttle->obj_inv);
	init_matrix_zero(memory_shuttle->transp_inv);
}

//a effacer.. truc chat gpt
t_color blend_reflection(t_color local, t_color reflected, float refl_intensity)
{
    t_color result;

    result.r = (1 - refl_intensity) * local.r + refl_intensity * reflected.r;
    result.g = (1 - refl_intensity) * local.g + refl_intensity * reflected.g;
    result.b = (1 - refl_intensity) * local.b + refl_intensity * reflected.b;
    result.rgb = 0; // à recalculer si nécessaire

    return result;
}

/*
avant modif hamburg
void vect_reflexion(t_coord *result, t_coord *v_previous, t_coord *v_normal)
{
	float inner_product; //dot is the same
	t_coord v_scal;
	t_coord add;

	v_scal.t = 0;
	inner_product = dot_product(v_previous, v_normal);//=)
	v_scal = scalar_mult_ret(v_normal, (-2 * inner_product));
	addition_vect(result, v_previous, &v_scal);
//	addition_na(&add, v_previous, result);
//	inner_product = dot_product(&add, v_normal);
//	printf("is zero  %.3f \n", inner_product);
}
*/


/*
//gpt
void vect_reflexion(t_coord *result, t_coord *v_previous, t_coord *v_normal)
{
	float dot;
	t_coord v_scal;
	t_coord add;

	printf("v normal lenght %.3f \n", length_vector(v_normal));
	printf("v previous lenght %.3f \n", length_vector(v_previous));
	dot = dot_product(v_previous, v_normal);
	v_scal = scalar_mult_ret(v_previous, (2 * dot));
	substraction_p_to_v_na(result, v_normal, &v_scal);
	printf("ray lenght result %.3f \n", length_vector(result));
//	addition_na(&add, v_previous, result);
//	dot = dot_product(&add, v_normal);
//	printf("is zero  %.3f \n", dot);
}*/

