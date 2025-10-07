/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory_shuttle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:47:48 by syl               #+#    #+#             */
/*   Updated: 2025/10/07 16:40:01 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_memory_shuttle(t_mem *memory_shuttle)
{
	free_mem_shuttle_part_1(memory_shuttle);
	free_mem_shuttle_part_2(memory_shuttle);
	free_mem_shuttle_part_3(memory_shuttle);
	free_mem_shuttle_part_4(memory_shuttle);
}

void	free_mem_shuttle_part_1(t_mem *memory_shuttle)
{
	if (memory_shuttle->r_origin_m)
	{
		free(memory_shuttle->r_origin_m);
		memory_shuttle->r_origin_m = NULL;
	}
	if (memory_shuttle->r_dir_m)
	{
		free(memory_shuttle->r_dir_m);
		memory_shuttle->r_dir_m = NULL;
	}
	if (memory_shuttle->r_dir_closest_obj)
	{
		free(memory_shuttle->r_dir_closest_obj);
		memory_shuttle->r_dir_closest_obj = NULL;
	}
	if (memory_shuttle->r_origin_closest_obj)
	{
		free(memory_shuttle->r_origin_closest_obj);
		memory_shuttle->r_origin_closest_obj = NULL;
	}
	if (memory_shuttle->v_sph_camera)
	{
		free(memory_shuttle->v_sph_camera);
		memory_shuttle->v_sph_camera = NULL;
	}
}

void	free_mem_shuttle_part_2(t_mem *memory_shuttle)
{
	if (memory_shuttle->origin_zero)
	{
		free(memory_shuttle->origin_zero);
		memory_shuttle->origin_zero = NULL;
	}
	if (memory_shuttle->p_viewport)
	{
		free(memory_shuttle->p_viewport);
		memory_shuttle->p_viewport = NULL;
	}
	if (memory_shuttle->p_viewport_world)
	{
		free(memory_shuttle->p_viewport_world);
		memory_shuttle->p_viewport_world = NULL;
	}
	if (memory_shuttle->r_base_origin)
	{
		free(memory_shuttle->r_base_origin);
		memory_shuttle->r_base_origin = NULL;
	}
	if (memory_shuttle->r_base_dir)
	{
		free(memory_shuttle->r_base_dir);
		memory_shuttle->r_base_dir = NULL;
	}
}

void	free_mem_shuttle_part_3(t_mem *memory_shuttle)
{
	if (memory_shuttle->p_space)
	{
		free(memory_shuttle->p_space);
		memory_shuttle->p_space = NULL;
	}
	if (memory_shuttle->p_touch)
	{
		free(memory_shuttle->p_touch);
		memory_shuttle->p_touch = NULL;
	}
	if (memory_shuttle->v_norm_parral)
	{
		free(memory_shuttle->v_norm_parral);
		memory_shuttle->v_norm_parral = NULL;
	}
	if (memory_shuttle->v_light_to_point)
	{
		free(memory_shuttle->v_light_to_point);
		memory_shuttle->v_light_to_point = NULL;
	}
	if (memory_shuttle->v_point_to_light)
	{
		free(memory_shuttle->v_point_to_light);
		memory_shuttle->v_point_to_light = NULL;
	}
}

void	free_mem_shuttle_part_4(t_mem *memory_shuttle)
{
	if (memory_shuttle->reflect_dir)
	{
		free(memory_shuttle->reflect_dir);
		memory_shuttle->reflect_dir = NULL;
	}
	if (memory_shuttle->scalar)
	{
		free(memory_shuttle->scalar);
		memory_shuttle->scalar = NULL;
	}
	if (memory_shuttle->view_dir)
	{
		free(memory_shuttle->view_dir);
		memory_shuttle->view_dir = NULL;
	}
	if (memory_shuttle->obj_inv)
	{
		free(memory_shuttle->obj_inv);
		memory_shuttle->obj_inv = NULL;
	}
	if (memory_shuttle->transp_inv)
	{
		free(memory_shuttle->transp_inv);
		memory_shuttle->transp_inv = NULL;
	}
}
