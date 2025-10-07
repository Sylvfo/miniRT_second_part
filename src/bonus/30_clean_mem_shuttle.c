/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   30_clean_mem_shuttle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:54:54 by syl               #+#    #+#             */
/*   Updated: 2025/10/07 21:15:12 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	reset_recursivity_level(t_glob **datas)
{
	int	i;

	i = 0;
	while (i < NB_THREADS)
	{
		datas[i]->mem_shuttle->recursivity_level = 0;
		datas[i]->mem_shuttle->prev_refraction = 1;
		i++;
	}
}

t_mem	**init_multi_memory_shuttle(void)
{
	t_mem	**multi_mem_shuttle;
	int		i;

	multi_mem_shuttle = NULL;
	multi_mem_shuttle = malloc(NB_THREADS * sizeof(t_mem));
	if (!multi_mem_shuttle)
		return (NULL);
	i = 0;
	while (i < NB_THREADS)
	{
		multi_mem_shuttle[i] = init_memory_shuttle();
		if (!multi_mem_shuttle[i])
		{
			clear_multi_mem_shuttle(multi_mem_shuttle, i);
			free(multi_mem_shuttle);
			return (NULL);
		}
		multi_mem_shuttle[i]->pix_x = i;
		multi_mem_shuttle[i]->pix_y = 0;
		i++;
	}
	return (multi_mem_shuttle);
}

void	clear_multi_mem_shuttle(t_mem **multi_mem_shuttle, int i)
{
	i--;
	while (i > 0)
	{
		printf("problem with memory shuttle \n");
		free_memory_shuttle(multi_mem_shuttle[i]);
		multi_mem_shuttle[i] = NULL;
		i--;
	}
}

void	memory_shuttle_bonus_values_null(t_mem *mem_shuttle)
{
	mem_shuttle->pix_x = 0;
	mem_shuttle->pix_y = 0;
	mem_shuttle->recursivity_level = 0;
	mem_shuttle->prev_refraction = 0;
}

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
	mem_shuttle->p_touch->x = 0.0;
	mem_shuttle->p_touch->y = 0.0;
	mem_shuttle->p_touch->z = 0.0;
}
