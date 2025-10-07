/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_base_recursion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:21:29 by syl               #+#    #+#             */
/*   Updated: 2025/10/07 20:00:15 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_color next_ray(t_scene *scene, t_mem *mem_shtle, t_color color_light)//prev_color
{
	t_color next_color;
	float	transp;

	if (scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->mirror > 0.0)
		color_light = reflexion(scene, mem_shtle, color_light);
	if (scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->transparence > 0.0)
	{
		if (scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->transparence == 1.0)
			return (color_light);
		transp = scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->transparence;
		if (scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->indice_refract != 1.0)
			next_color = refraction(scene, mem_shtle);
		else
			next_color = transparence(scene, mem_shtle);
		next_color = scalar_mult_color2(next_color, (1.0f - transp));
		color_light = scalar_mult_color2(color_light, transp);
		color_light = add_color(color_light, next_color);
	}
	return color_light;
}


/*
t_color next_ray(t_scene *scene, t_mem *mem_shtle, t_color color_light)//prev_color
{
	t_color next_color;
	float	mirror;
	float	transp;

	if (mirror = scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->mirror > 0.0)
	;
	if (mirror > 0.0)
	{
		next_color = reflexion(scene, mem_shtle);
		if (mirror == 1.0)
			return (next_color);
		next_color = scalar_mult_color2(next_color, mirror);
		color_light = scalar_mult_color2(color_light, (1.0f - mirror));
		color_light = add_color(color_light, next_color);
	}

	transp = scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->transparence ;
	if ( transp > 0.0)
	{
		if (scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->transparence == 1.0)
			return (color_light);
		transp = scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->transparence;
		if (scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->indice_refract != 1.0)
			next_color = refraction(scene, mem_shtle);
		else
			next_color = transparence(scene, mem_shtle);
		next_color = scalar_mult_color2(next_color, (1.0f - transp));
		color_light = scalar_mult_color2(color_light, transp);
		color_light = add_color(color_light, next_color);
	}
	return color_light;
}

*/

/* fonctionne sans refraction
t_color next_ray(t_scene *scene, t_mem *mem_shtle, t_color color_light)
{
	t_color next_color;
	float	mirror;
	float	transp;
	float	refraction;

	//miroir
	mirror = scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->mirror;
	if (mirror > 0.0)
	{
		next_color = reflexion(scene, mem_shtle);
		if (mirror == 1.0)
			return (next_color);
		next_color = scalar_mult_color2(next_color, mirror);
		color_light = scalar_mult_color2(color_light, (1.0f - mirror));
		color_light = add_color(color_light, next_color);
	}
	//transparence
	if (scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->transparence > 0.0)
	{
		if (scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->transparence == 1.0)
			return (color_light);
		transp = scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->transparence;
		next_color = transparence(scene, mem_shtle);
		next_color = scalar_mult_color2(next_color, (1.0f - transp));
		color_light = scalar_mult_color2(color_light, transp);
		color_light = add_color(color_light, next_color);
	}
	return color_light;
}

*/