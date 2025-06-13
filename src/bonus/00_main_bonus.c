/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:34:56 by syl               #+#    #+#             */
/*   Updated: 2025/06/13 11:31:36 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	raytracing_main_bonus(t_pix ***pix, t_scene *scene, t_mem *mem_shuttle)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			clean_memory_shuttle(mem_shuttle);
			init_viewport_x_y(mem_shuttle, scene->cam, x, y);
			init_camera_pix_ray(mem_shuttle, scene->cam);
			*(pix[x][y]->color) = raytracer_bonus(pix[x][y],
					scene, mem_shuttle);
			y++;
		}
		x++;
	}
	return ;
}

t_color	raytracer_bonus(t_pix *pix, t_scene *scene, t_mem *mem_shtle)
{
	t_color	color_light;

	main_intersections(scene->obj, mem_shtle);
	copy_matrix_44(mem_shtle->obj_inv,
		scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->m_inv);
	closest_obj_in_pix(pix, mem_shtle);
	if (mem_shtle->obj_a == 0)
	{
		color_light = background_color(scene->obj[0][0], scene->lux[0][0]);
		return (color_light);
	}
	if (scene->preview == true)
		return (*(scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->color));
	prepare_computation(mem_shtle, scene->obj);
	color_light = lighting(scene, mem_shtle,
			*(scene->obj[pix->obj_a][pix->obj_b]->color));
	if (scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->mirror > 0.0)
	{
		color_light = base_reflection(scene, mem_shtle, color_light);
	}
	return (color_light);
}

void	paint_it_black(t_color *color)
{
	color->r = 0.0;
	color->g = 0.0;
	color->b = 0.0;
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
}
