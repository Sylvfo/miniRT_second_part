/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_light_shadow_main.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:44:59 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 14:44:37 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_color	lighting(t_scene *scene, t_mem *memory_shuttle, t_color obj_color)
{
	int		i;
	t_color	light_color;
	t_color	specular_color;
	t_color	this_light_color;

	i = 0;
	light_color = init_color();
	while (i < scene->nb_lights)
	{
		prepare_v_light(memory_shuttle, scene->lux[1][i]->p_coord);
		if (intersect_objects_shadow(scene, memory_shuttle) == false)
		{
			this_light_color = compute_pointlight(memory_shuttle,
					scene->lux[1][i]);
			specular_color = compute_specular(memory_shuttle, scene->lux[1][i],
					scene->cam->p_coord);
			this_light_color = add_color(this_light_color, specular_color);
			light_color = add_color(light_color, this_light_color);
		}
		i++;
	}
	light_color = add_color(light_color, *(scene->lux[0][0]->color));
	obj_color = multipling_color(obj_color, light_color);
	return (obj_color);
}
