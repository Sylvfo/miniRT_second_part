/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_raytracing_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:27:13 by syl               #+#    #+#             */
/*   Updated: 2026/01/20 15:52:20 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	raytracing(t_pix ***pix, t_scene *scene, t_mem *mem_shuttle)
{
	int	x;
	int	y;

	constructing_camera(scene);
	matrix_transformations(scene->obj);
	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			clean_memory_shuttle(mem_shuttle);
			init_viewport_x_y(mem_shuttle, scene->cam, x, y);
			init_camera_pix_ray(mem_shuttle, scene->cam);
			*(pix[x][y]->color) = raytracer(pix[x][y],
					scene, mem_shuttle);
			y++;
		}
		x++;
	}
}

t_color	raytracer(t_pix *pix, t_scene *scene, t_mem *mem_shuttle)
{
	t_color	color;

	main_intersections(scene->obj, mem_shuttle);
	copy_matrix_44(mem_shuttle->obj_inv,
		scene->obj[mem_shuttle->obj_a][mem_shuttle->obj_b]->m_inv);
	closest_obj_in_pix(pix, mem_shuttle);
	if (mem_shuttle->obj_a == 0)
	{
		color = background_color(scene->obj[0][0], scene->lux[0][0]);
		return (color);
	}
	prepare_computation(mem_shuttle, scene->obj);
	color = lighting(scene, mem_shuttle, \
*(scene->obj[pix->obj_a][pix->obj_b]->color));
	return (color);
}

void	clean_memory_shuttle(t_mem *mem_shuttle)
{
	vector_fill(mem_shuttle->r_base_dir, 0, 0, 0);
	vector_fill(mem_shuttle->r_dir_m, 0, 0, 0);
	point_fill(mem_shuttle->r_base_origin, 0, 0, 0);
	point_fill(mem_shuttle->r_origin_m, 0, 0, 0);
	mem_shuttle->closestt = (float)INT_MAX;
	mem_shuttle->obj_a = 0;
	mem_shuttle->obj_b = 0;
	mem_shuttle->t_count = 0;
	mem_shuttle->distance_light_p_touch = 0.0;
	point_fill(mem_shuttle->p_space, 0, 0, 0);
	point_fill(mem_shuttle->p_touch, 0, 0, 0);
	vector_fill(mem_shuttle->v_light_to_point, 0, 0, 0);
	vector_fill(mem_shuttle->v_point_to_light, 0, 0, 0);
	vector_fill(mem_shuttle->reflect_dir, 0, 0, 0);
	vector_fill(mem_shuttle->scalar, 0, 0, 0);
	vector_fill(mem_shuttle->view_dir, 0, 0, 0);
	init_matrix_zero(mem_shuttle->obj_inv);
	init_matrix_zero(mem_shuttle->transp_inv);
}

t_color	background_color(t_obj *obj_zero, t_light *lux_zero)
{
	t_color	background_color;

	background_color.r = obj_zero->color->r * lux_zero->ratio;
	background_color.g = obj_zero->color->g * lux_zero->ratio;
	background_color.b = obj_zero->color->b * lux_zero->ratio;
	background_color = multipling_color(background_color, *(lux_zero->color));
	return (background_color);
}
