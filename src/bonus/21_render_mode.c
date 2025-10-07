/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21_render_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:07:46 by syl               #+#    #+#             */
/*   Updated: 2025/10/07 20:35:48 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	drawing_mode(t_glob **datas)
{
	datas[0]->scene->preview = true;
	datas[0]->scene->draw_mode = 1;
	raytracer_threads(datas);
	pix_to_window(datas[0]->pix, datas[0]->scene);
	print_on_screen(datas[0]->scene, "DRAWING MODE ON", 0, 7050681);
	print_on_screen(datas[0]->scene, "SELECT ACTION", 1, 0x5c66df);
}

void	render_mode(t_glob **datas)
{
	datas[0]->scene->draw_mode = 0;
	datas[0]->scene->preview = false;
	print_on_screen(datas[0]->scene, "RENDER MODE ON. WAIT FOR CALCULATION", 0, 7050681);
	raytracer_threads(datas);
	pix_to_window(datas[0]->pix, datas[0]->scene);
	print_on_screen(datas[0]->scene, "RENDER MODE ON", 0, 7050681);
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
