/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21_render_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:07:46 by syl               #+#    #+#             */
/*   Updated: 2025/06/13 11:23:59 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	drawing_mode(t_scene *scene)
{
	scene->preview = true;
	scene->draw_mode = 1;
	raytracing_main_bonus(scene->pix, scene, scene->mem_shuttle);
	pix_to_window(scene->pix, scene);
	print_on_screen(scene, "DRAWING MODE ON", 0, 7050681);
	print_on_screen(scene, "SELECT ACTION", 1, 0x5c66df);
}

void	render_mode(t_scene *scene)
{
	scene->draw_mode = 0;
	scene->preview = false;
	print_on_screen(scene, "RENDER MODE ON. WAIT FOR CALCULATION", 0, 7050681);
	raytracing_main_bonus(scene->pix, scene, scene->mem_shuttle);
	pix_to_window(scene->pix, scene);
	print_on_screen(scene, "RENDER MODE ON", 0, 7050681);
}

void	is_transformation_possible(t_scene *scene)
{
	if (scene->pix[scene->x][scene->y]->obj_a == PLAN
		&& scene->draw_type == SCALE)
	{
		print_on_screen(scene, "IMPOSSIBLE TO SCALE A PLAN", 0, 7050681);
		clear_modif(scene);
	}
}
