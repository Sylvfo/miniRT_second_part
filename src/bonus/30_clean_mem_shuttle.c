/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   30_clean_mem_shuttle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:54:54 by syl               #+#    #+#             */
/*   Updated: 2025/10/07 15:28:04 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_mem	**init_multi_memory_shuttle(void)
{
	t_mem	**multi_mem_shuttle;
	int i;

	multi_mem_shuttle = NULL;
	multi_mem_shuttle = malloc(NB_THREADS * sizeof(t_mem));
	if (!multi_mem_shuttle)
		return (NULL);
	i = 0;
	while(i < NB_THREADS)
	{
		multi_mem_shuttle[i] = init_memory_shuttle();
		if (!multi_mem_shuttle[i])
		{
			//a revoir...
			i--;
			while(i > 0)
			{
				printf("problem with memory shuttle \n");
				free_memory_shuttle(multi_mem_shuttle[i]);
				multi_mem_shuttle[i] = NULL;
				i--;
			}
			free(multi_mem_shuttle);
			return NULL;
		}
		multi_mem_shuttle[i]->pix_x = i;
		multi_mem_shuttle[i]->pix_y = 0;
		// !! taille minimum image??
		i++;
	}
	return (multi_mem_shuttle);
}

void memory_shuttle_bonus_values_null(t_mem *mem_shuttle)
{
	mem_shuttle->pix_x = 0;
	mem_shuttle->pix_y = 0;
	mem_shuttle->recursivity_level = 0;
	mem_shuttle->prev_refraction = 0;
}
//ça clean pas 
//mem_shuttle->r_base_origin
//mem_shuttle->r_base_dir
//
//mais ça clean
//mem_shuttle->r_dir_closest_obj
//mem_shuttle->r_origin_closest_obj
//mem_shuttle->v_sph_camera
//mem_shuttle->v_norm_parral
void	clean_memory_shuttle_refl(t_mem *mem_shuttle)
{
	vector_fill(mem_shuttle->r_dir_m, 0, 0, 0);
	point_fill(mem_shuttle->r_origin_m, 0, 0, 0);
	vector_fill(mem_shuttle->r_dir_closest_obj, 0, 0, 0);
	point_fill(mem_shuttle->r_origin_closest_obj, 0, 0, 0);
	vector_fill(mem_shuttle->v_sph_camera, 0, 0, 0);
	point_fill(mem_shuttle->p_touch, 0, 0, 0);
	vector_fill(mem_shuttle->v_norm_parral, 0, 0, 0);
	point_fill(mem_shuttle->p_space, 0, 0, 0);
	vector_fill(mem_shuttle->v_light_to_point, 0, 0, 0);
	vector_fill(mem_shuttle->v_point_to_light, 0, 0, 0);
	vector_fill(mem_shuttle->reflect_dir, 0, 0, 0);
	vector_fill(mem_shuttle->scalar, 0, 0, 0);
	vector_fill(mem_shuttle->view_dir, 0, 0, 0);
	mem_shuttle->t_count = 0;
	mem_shuttle->closestt = INT_MAX;
	mem_shuttle->obj_a = 0;
	mem_shuttle->obj_b = 0;
	init_matrix_zero(mem_shuttle->obj_inv);
	init_matrix_zero(mem_shuttle->transp_inv);

	//
	mem_shuttle->p_touch->x = 0.0;
	mem_shuttle->p_touch->y = 0.0;
	mem_shuttle->p_touch->z = 0.0;
}

void	paint_it_black(t_color *color)
{
	color->r = 0.0;
	color->g = 0.0;
	color->b = 0.0;
}

/*
//memory_shuttle
typedef struct s_mem
{
	t_coord		*r_base_origin;
	t_coord		*r_base_dir;
	t_coord		*r_origin_m;
	t_coord		*r_dir_m;
	int			t_count;
	float		closestt;
	int			obj_a;
	int			obj_b;
	t_coord		*r_dir_closest_obj;
	t_coord		*r_origin_closest_obj;
	t_coord		*p_viewport;
	t_coord		*p_viewport_world;
	t_coord		*v_sph_camera;
	t_coord		*origin_zero;
	t_coord		*p_touch;
	t_coord		*v_norm_parral;
	float		*transp_inv;
	t_coord		*p_space;
	float		*obj_inv;
	t_coord		*v_light_to_point;
	float		distance_light_p_touch;
	t_coord		*v_point_to_light;
	t_coord		*reflect_dir;
	t_coord		*scalar;
	t_coord		*view_dir;
	bool		is_avaible;
}	t_mem;

*/