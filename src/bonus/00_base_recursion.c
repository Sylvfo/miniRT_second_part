/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_base_recursion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:21:29 by syl               #+#    #+#             */
/*   Updated: 2025/10/06 18:01:21 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_color next_ray(t_scene *scene, t_mem *mem_shtle, t_color color_light)
{
	t_color next_color;
	float	mirror;
	float	transp;

//	if (mem_shtle->recursivity_level == MAX_RECURSIVITY)
//		return (color_light);
	//miroir
	mirror = scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->mirror;
	if (mirror > 0.0)
	{
	//	if (mirror > 0.0)
	//		printf("- %f ", mirror);
		next_color = reflexion(scene, mem_shtle);
		if (mirror == 1.0)
			return (next_color);
		next_color = scalar_mult_color2(next_color, mirror);
		color_light = scalar_mult_color2(color_light, (1.0f - mirror));
		color_light = add_color(color_light, next_color);
	}
	//transparence
/*	if (scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->transparence > 0.0)
	{
		next_color = transparence(scene, mem_shtle);
		transp = scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->transparence;
		if (transp == 1.0)
			return (next_color);
		next_color = scalar_mult_color2(next_color, transp);
		color_light = scalar_mult_color2(color_light, (1.0f - transp));
		color_light = add_color(color_light, next_color);
	}*/
	//refraction

	return color_light;
}