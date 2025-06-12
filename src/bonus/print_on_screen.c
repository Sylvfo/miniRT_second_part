/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_on_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:14:48 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 16:17:39 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	print_on_screen(t_scene *scene, char *msg, int place, int color)
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

void	print_selected_object(t_scene *scene)
{
	if (scene->pix[scene->x][scene->y]->obj_a == 0)
		printf("You are trying to touch the sky. No object selected \n");
	else if (scene->pix[scene->x][scene->y]->obj_a == SPHERE)
		printf("Sphere n %i selected \n",
			1 + scene->pix[scene->x][scene->y]->obj_b);
	else if (scene->pix[scene->x][scene->y]->obj_a == PLAN)
		printf("Plan n %i selected \n",
			1 + scene->pix[scene->x][scene->y]->obj_b);
	else if (scene->pix[scene->x][scene->y]->obj_a == CYLINDER)
		printf("Cylinder n %i selected \n",
			1 + scene->pix[scene->x][scene->y]->obj_b);
}
