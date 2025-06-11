/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:19:38 by syl               #+#    #+#             */
/*   Updated: 2025/06/11 12:04:56 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	print_modif(t_scene *scene)
{
	print_action(scene);
	print_object(scene);
	print_value(scene);
	print_axe(scene);
}

void print_action(t_scene *scene)
{
	if (scene->draw_type == MOVE)
		printf("Move ");
	else if (scene->draw_type == ROTATE)
		printf("Rotate ");
	else if (scene->draw_type == SCALE)
		printf("Scale ");
	else if (scene->draw_type == COPY)
		printf("Copy ");
}

void print_object(t_scene *scene)
{
	if (scene->pix[scene->x][scene->y]->obj_a == SPHERE)
		printf("sphere n° %i ", 1 + scene->pix[scene->x][scene->y]->obj_b);
	else if (scene->pix[scene->x][scene->y]->obj_a == PLAN)
		printf("plan n° %i ", 1 + scene->pix[scene->x][scene->y]->obj_b);
	else if (scene->pix[scene->x][scene->y]->obj_a == CYLINDER)
		printf("cylinder n° %i ", 1 + scene->pix[scene->x][scene->y]->obj_b);
}

void print_value(t_scene *scene)
{
	if (scene->draw_type == ROTATE)
		printf("%.3f degrees ", scene->size_modif);
	else 
		printf("%.3f units ", scene->size_modif);
}

void print_axe(t_scene *scene)
{
	if (scene->axe_draw == X_AXE)
		printf("on x axis\n");
	else if (scene->axe_draw == Y_AXE)
		printf("on y axis\n");
	else if (scene->axe_draw == Z_AXE)
		printf("on z axis\n");
	else if (scene->axe_draw == U_UNITY)
		printf("on all axes\n");
}

void print_selected_object(t_scene *scene)
{
	if (scene->pix[scene->x][scene->y]->obj_a == 0)
		printf("You are trying to touch the sky. No object selected \n");
	else if (scene->pix[scene->x][scene->y]->obj_a == SPHERE)
		printf("Sphere n %i selected \n", 1 + scene->pix[scene->x][scene->y]->obj_b);
	else if (scene->pix[scene->x][scene->y]->obj_a == PLAN)
		printf("Plan n %i selected \n", 1 + scene->pix[scene->x][scene->y]->obj_b);
	else if (scene->pix[scene->x][scene->y]->obj_a == CYLINDER)
		printf("Cylinder n %i selected \n", 1 + scene->pix[scene->x][scene->y]->obj_b);
}

void print_on_screen(t_scene *scene, char *msg, int place, int color)
{
	if (place == 0)
	{
		mlx_put_image_to_window(scene->ima->mlx_ptr,
		scene->ima->mlx_win, scene->ima->ima_blk, WND_WIDTH + 2, 850);
		mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win,
			(WND_WIDTH + 30), 900, color, msg);
	}
	if (place == 1)
		mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win,
			(WND_WIDTH + 30), 920, color, msg);
	if (place == 3)
		mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win,
			(WND_WIDTH + 30), 940, color, msg);
}