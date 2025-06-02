/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_memory_shuttle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:38:27 by syl               #+#    #+#             */
/*   Updated: 2025/06/02 13:26:19 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_mem	*init_memory_shuttle(void)
{
	t_mem *mem_shuttle;

	mem_shuttle = NULL;
	mem_shuttle = malloc(sizeof(t_mem));
	if (!mem_shuttle)
		return (NULL);
	memory_shuttle_values_null(mem_shuttle);
	if (init_shuttle_values(mem_shuttle) == false)
	{
		printf("problem with memory shuttle \n");
		free_memory_shuttle(mem_shuttle);
		mem_shuttle = NULL;
		return (NULL);
	}
	return (mem_shuttle);
}

void	memory_shuttle_values_null(t_mem *memory_shuttle)
{
	memory_shuttle->r_base_origin = NULL;
	memory_shuttle->r_base_dir = NULL;

	memory_shuttle->p_viewport = NULL;
	memory_shuttle->p_viewport_world = NULL;
	memory_shuttle->r_origin_m = NULL;
	memory_shuttle->r_dir_m = NULL;
	memory_shuttle->v_sph_camera = NULL;
	memory_shuttle->t_count = 0.0;
	memory_shuttle->closestt = INT_MAX;
	memory_shuttle->obj_a = NONE;
	memory_shuttle->obj_b = 0;
	memory_shuttle->origin_zero = NULL;
	memory_shuttle->p_space = NULL;
	memory_shuttle->p_touch = NULL;
	memory_shuttle->p_space = NULL;
	memory_shuttle->v_norm_parral = NULL;
	memory_shuttle->v_light_to_point = NULL;
	memory_shuttle->v_point_to_light = NULL; 
	memory_shuttle->reflect_dir = NULL;
	memory_shuttle->scalar = NULL;
	memory_shuttle->view_dir = NULL;
	memory_shuttle->obj_inv = NULL;
	memory_shuttle->transp_inv = NULL;
}

bool init_shuttle_values(t_mem *memory_shuttle)
{
	memory_shuttle->r_origin_m = create_point(0, 0, 0);
	if (!memory_shuttle->r_origin_m)
		return (false);
	memory_shuttle->r_dir_m = create_vector(0, 0, 0);
	if (!memory_shuttle->r_dir_m)
		return (false);
	memory_shuttle->r_dir_closest_obj = create_vector(0, 0, 0);
	if (!memory_shuttle->r_dir_closest_obj)
		return (false);
	memory_shuttle->r_origin_closest_obj = create_point(0, 0, 0);
	if (!memory_shuttle->r_origin_closest_obj)
		return (false);
	memory_shuttle->v_sph_camera = create_vector(0, 0, 0);
	if (!memory_shuttle->v_sph_camera)
		return (false);
	memory_shuttle->origin_zero = create_point(0, 0, 0);
	if (!memory_shuttle->origin_zero)
		return (false);
	memory_shuttle->p_viewport = create_point(0, 0, -1);
	if (!memory_shuttle->p_viewport)
		return (false);
	memory_shuttle->p_viewport_world = create_point(0, 0, 0);
	if (!memory_shuttle->p_viewport_world)
		return (false);

	memory_shuttle->r_base_origin = create_point(0, 0, 0);
	if (!memory_shuttle->r_base_origin)
		return (false);
	memory_shuttle->r_base_dir = create_point(0, 0, 0);
	if (!memory_shuttle->r_base_dir)
		return (false);
//	memory_shuttle->object_normal = create_vector(0, 0, 0);
//	if (!memory_shuttle->object_normal)
//		return (false);
	memory_shuttle->p_space = create_point(0, 0, 0);
	if (!memory_shuttle->p_space)
		return (false);
	memory_shuttle->p_touch = create_point(0, 0, 0);
	if (!memory_shuttle->p_touch)
		return (false);
//	memory_shuttle->v_eye = create_vector(0, 0, 0);
//	if (!memory_shuttle->v_eye)
//		return (false);
	memory_shuttle->v_norm_parral = create_vector(0, 0, 0);
	if (!memory_shuttle->v_norm_parral)
		return (false);
	memory_shuttle->v_light_to_point = create_vector(0, 0, 0);
	if (!memory_shuttle->v_light_to_point)
		return (false);
//	memory_shuttle->v_sphere_to_point = create_vector(0, 0, 0);
//	if (!memory_shuttle->v_sphere_to_point)
//		return (false);
	memory_shuttle->v_point_to_light = create_vector(0, 0, 0);
	if (!memory_shuttle->v_point_to_light)
		return (false);
	memory_shuttle->reflect_dir = create_vector(0, 0, 0);
	if (!memory_shuttle->reflect_dir)
		return (false);
	memory_shuttle->scalar = create_vector(0, 0, 0);
	if (!memory_shuttle->scalar)
		return (false);
	memory_shuttle->view_dir = create_vector(0, 0, 0);
	if (!memory_shuttle->view_dir)
		return (false);
	memory_shuttle->obj_inv = create_indentity_matrix_44();
	if (!memory_shuttle->obj_inv)
		return (false);
	memory_shuttle->transp_inv = create_indentity_matrix_44();
	if (!memory_shuttle->transp_inv)
		return (false);
	return (true);
}

void	free_memory_shuttle(t_mem *memory_shuttle)
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
	if (memory_shuttle->origin_zero)
	{
		free(memory_shuttle->origin_zero);
		memory_shuttle->origin_zero = NULL;
	}
	//
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
//	if (memory_shuttle->object_normal)
//	{
//		free(memory_shuttle->object_normal);
//		memory_shuttle->object_normal = NULL;
//	}
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
	//if (memory_shuttle->v_eye)
	//{
//		free(memory_shuttle->v_eye);
//		memory_shuttle->v_eye = NULL;
//	}
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
//	if (memory_shuttle->v_sphere_to_point)
//	{
//		free(memory_shuttle->v_sphere_to_point);
//		memory_shuttle->v_sphere_to_point = NULL;
//	}
	if (memory_shuttle->v_point_to_light)
	{
		free(memory_shuttle->v_point_to_light);
		memory_shuttle->v_point_to_light = NULL;
	}
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
