/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_lighting_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 21:18:04 by syl               #+#    #+#             */
/*   Updated: 2025/10/09 14:41:16 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//main syl
t_color	lighting_bonus(t_scene *scene, t_mem *memory_shuttle, t_color obj_color)
{
	int		i;
	t_color	light_color;
	t_color	specular_color;
	t_color	this_light_color;
	
	light_color = init_color();
	memory_shuttle->percent_shadow = 0.0;
	i = 0;
	while (i < scene->nb_lights)
	{
		raytracer_shadow_bonus(scene, memory_shuttle, i);
		if (memory_shuttle->percent_shadow < 1.0)
		{
			this_light_color = compute_pointlight(memory_shuttle,
					scene->lux[1][i]);
			specular_color = compute_specular(memory_shuttle, scene->lux[1][i],
					scene->cam->p_coord);
			this_light_color = add_color(this_light_color, specular_color);
			if (memory_shuttle->percent_shadow > 0.0 && memory_shuttle->percent_shadow < 1.0)
				this_light_color = multipling_color(this_light_color, *memory_shuttle->color_shadow);
			light_color = add_color(light_color, this_light_color);
		}
		i++;
	}
	light_color = add_color(light_color, *(scene->lux[0][0]->color));
	obj_color = multipling_color(obj_color, light_color);
	return (obj_color);
}

void	take_shadow_color(t_mem *mem_shuttle, t_intertt result, t_obj *obj)// amcien closestt
{
	t_color	new_color_shadow;

	new_color_shadow = init_color();
	if ((result.t1 < INT_MAX && result.t1 > 0.0) || (result.t2 < INT_MAX && result.t2 > 0))
	{
 		if (obj->transparence == 1.0)
		{
			mem_shuttle->percent_shadow = 1.0;
			return;
		}
		if (mem_shuttle->percent_shadow == 0.0)
		{
			mem_shuttle->percent_shadow = (1.0 - obj->transparence);
			*mem_shuttle->color_shadow = scalar_mult_color2(*obj->color, mem_shuttle->percent_shadow);
			return;
		}
		mem_shuttle->percent_shadow = 0.5;
		new_color_shadow = scalar_mult_color2(*obj->color, obj->transparence);
		*mem_shuttle->color_shadow = scalar_mult_color2(*mem_shuttle->color_shadow, (1.0 - obj->transparence));
		*mem_shuttle->color_shadow = multipling_color(*mem_shuttle->color_shadow, new_color_shadow);
		return;
	}
}

void light_intersections_shadow(t_obj ***obj, t_mem *memory_shuttle)
{
	int	a;
	int	b;

	a = 1;
	while (a < NB_OBJ)
	{
		b = 0;
		while (obj[a] && b < obj[a][0]->number)
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
			if (memory_shuttle->percent_shadow >= 1.0)
				return ;
			b++;
		}
		a++;
	}
}

////////////////////////////// RAYTRACER
void raytracer_shadow_bonus(t_scene *scene, t_mem *mem_shtle, int num_light)
{
	clean_color(mem_shtle->color_shadow);
	mem_shtle->percent_shadow = 0.0;
	mem_shtle->percent_new_shadow = 0.0;
	next_ray_light(mem_shtle, scene->lux[1][num_light]->p_coord); //ancien prepare v light
	light_intersections_shadow(scene->obj, mem_shtle); // ancien main intersection
	return ;
}

void	next_ray_light(t_mem *mem_shuttle, t_coord *lux_p_coord)
{
	t_coord	offset;
	t_coord	tmp;

	offset = scalar_mult_ret(mem_shuttle->v_norm_parral, 0.01f);
	addition_na(mem_shuttle->p_light_to_point, mem_shuttle->p_touch, &offset);
	offset.x = 0.0;
	offset.y = 0.0;
	offset.z = 0.0;
	offset.t = 1;
	tmp.x = 0.0;
	tmp.y = 0.0;
	tmp.z = 0.0;
	tmp.t = 0;
	scalar_mult_na(&tmp, mem_shuttle->v_norm_parral, 0.0001 * 10.0f);
	addition_na(&offset, mem_shuttle->p_touch, &tmp);
	substraction_p_to_v_na(mem_shuttle->v_light_to_point,
		lux_p_coord, &offset);
	//besoin?
	mem_shuttle->distance_light_p_touch
		= length_vector(mem_shuttle->v_light_to_point);
	normalize_vector_na(mem_shuttle->v_light_to_point);
}
