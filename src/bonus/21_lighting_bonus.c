/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_lighting_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 21:18:04 by syl               #+#    #+#             */
/*   Updated: 2026/01/20 16:12:57 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_color	lighting_bonus(t_scene *scene, t_mem *memory_shuttle, t_color obj_color)
{
	int		i;
	t_color	light_color;

	light_color = init_color();
	memory_shuttle->percent_shadow = 0.0;
	i = 0;
	while (i < scene->nb_lights)
	{
		raytracer_shadow_bonus(scene, memory_shuttle, i);
		if (memory_shuttle->percent_shadow < 1.0)
		{
			light_color = color_light(i, light_color, scene, memory_shuttle);
		}
		i++;
	}
	light_color = add_color(light_color, *(scene->lux[0][0]->color));
	obj_color = multipling_color(obj_color, light_color);
	return (obj_color);
}

t_color	color_light(int i, t_color light_color, t_scene *scene, t_mem *mem_shtl)
{
	t_color	this_light_color;
	t_color	specular_color;

	this_light_color = compute_pointlight(mem_shtl,
			scene->lux[1][i]);
	specular_color = compute_specular(mem_shtl, scene->lux[1][i],
			scene->cam->p_coord);
	this_light_color = add_color(this_light_color, specular_color);
	if (mem_shtl->percent_shadow > 0.0 && mem_shtl->percent_shadow < 1.0)
		this_light_color = multipling_color(this_light_color,
				*mem_shtl->color_shadow);
	light_color = add_color(light_color, this_light_color);
	return (light_color);
}

void	light_intersections_shadow(t_obj ***obj, t_mem *memory_shuttle)
{
	int	a;
	int	b;

	a = 1;
	while (a < NB_OBJ)
	{
		b = 0;
		while (obj[a] && b < obj[a][0]->number)
		{
			obj_intersect(obj, memory_shuttle, a, b);
			if (memory_shuttle->percent_shadow >= 1.0)
				return ;
			b++;
		}
		a++;
	}
}

void	obj_intersect(t_obj ***obj, t_mem *memory_shuttle, int a, int b)
{
	apply_transformation_bonus(obj[a][b], memory_shuttle);
	if (a == 1)
		intersect_sphere_shadow_bonus(memory_shuttle, obj[a][b]);
	if (a == 2)
		intersect_plan_shadow_bonus(memory_shuttle, obj[a][b]);
	if (a == 3)
		intersect_cylinder_bonus(memory_shuttle, obj[a][b]);
	if (a == 4)
		intersect_cone_bonus(memory_shuttle, obj[a][b]);
	if (a == 5)
		intersect_triangle_bonus(memory_shuttle, obj, b);
}

void	apply_transformation_bonus(t_obj *obj, t_mem *memory_shuttle)
{
	matrix_point_multiplication_new(memory_shuttle->r_origin_m,
		obj->m_inv, memory_shuttle->p_light_to_point);
	matrix_point_multiplication_new(memory_shuttle->r_dir_m,
		obj->m_inv, memory_shuttle->v_light_to_point);
}
