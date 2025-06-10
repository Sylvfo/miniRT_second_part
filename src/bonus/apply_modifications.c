/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_modifications.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:19:21 by syl               #+#    #+#             */
/*   Updated: 2025/06/10 17:42:59 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void apply_transformations(t_scene *scene)
{
	if (scene->draw_type == MOVE)
		apply_move_changes(scene);
/*	else if (scene->draw_type == ROTATE)
		apply_rotate_changes(scene);
	else if (scene->draw_type == SCALE)
		apply_scale_changes(scene);
	else if (scene->draw_type == COPY)
		apply_copy_changes(scene);*/
	clear_modif(scene);
	printf("new image lauching\n");
	raytracing_main_bonus(scene->pix, scene, scene->mem_shuttle);
	pix_to_window(scene->pix, scene);
}

void apply_move_changes(t_scene *scene)
{
	int obj_type;
	int obj_num;

	obj_type = scene->pix[scene->x][scene->y]->obj_a;
	obj_num = scene->pix[scene->x][scene->y]->obj_b;
	if (scene->axe_draw == X_AXE)
		scene->obj[obj_type][obj_num]->p_coord->x += scene->size_modif;
	else if (scene->axe_draw == Y_AXE)
		scene->obj[obj_type][obj_num]->p_coord->y += scene->size_modif;
	else if (scene->axe_draw == Z_AXE)
		scene->obj[obj_type][obj_num]->p_coord->z += scene->size_modif;	
	///!!!!
	move_object(scene->obj[obj_type][obj_num]);
}

void apply_rotate_changes(t_scene *scene)
{
	int obj_type;
	int obj_num;

	obj_type = scene->pix[scene->x][scene->y]->obj_a;
	obj_num = scene->pix[scene->x][scene->y]->obj_b;
	//....
}

void apply_scale_changes(t_scene *scene)
{
	int obj_type;
	int obj_num;

	obj_type = scene->pix[scene->x][scene->y]->obj_a;
	obj_num = scene->pix[scene->x][scene->y]->obj_b;
	//....
}

void apply_copy_changes(t_scene *scene)
{
	int obj_type;
	int obj_num;

	obj_type = scene->pix[scene->x][scene->y]->obj_a;
	obj_num = scene->pix[scene->x][scene->y]->obj_b;
	//....
}