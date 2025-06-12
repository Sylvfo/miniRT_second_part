/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:03:29 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 23:24:11 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_scene	*init_first_scene_memory(bool bonus_mode)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene_value_null(scene);
	scene->bonus_mode = bonus_mode;
	return (scene);
}

void	scene_value_null(t_scene *scene)
{
	if (!scene)
		return ;
	scene->cam = NULL;
	scene->ima = NULL;
	scene->obj = NULL;
	scene->lux = NULL;
	scene->nb_sphere = 0;
	scene->nb_plan = 0;
	scene->nb_cylinder = 0;
	scene->nb_lights = 0;
	scene->wnd_height = (float)WND_HEIGHT;
	scene->wnd_width = (float)WND_WIDTH;
	scene->axe_draw = 0;
	scene->draw_mode = 0;
	scene->draw_type = 0;
	scene->x = 0;
	scene->y = 0;
	scene->size_modif = 0.0;
	scene->after_virgule = 0.0;
	scene->size_modif_neg = 1.0;
	scene->preview = false;
}

bool	init_scene_memory(t_scene *scene)
{
	if (!scene)
		return (false);
	if (init_cam_cph(scene) == false)
		return (false);
	scene->ima = NULL;
	scene->ima = create_image(scene);
	if (!scene->ima)
		return (false);
	if (scene->bonus_mode == true)
	{
		if (create_image_cmd(scene->ima) == false)
			return (false);
		if (create_image_blk(scene->ima) == false)
			return (false);
	}
	if (init_obj_cph(scene) == false)
		return (false);
	if (init_lux_cph(scene) == false)
		return (false);
	return (true);
}
