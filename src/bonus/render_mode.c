/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:07:46 by syl               #+#    #+#             */
/*   Updated: 2025/06/10 17:18:46 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void drawing_mode(t_scene *scene)
{
	scene->preview = true;
	scene->draw_mode = 1;
	raytracing_main_bonus(scene->pix, scene, scene->mem_shuttle);
	pix_to_window(scene->pix, scene);
	mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win, (WND_WIDTH + 30), 900, 255, "DRAWING MODE ON");
	mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win, (WND_WIDTH + 30), 920, 255, "SELECT ACTION");
}

void	render_mode(t_scene *scene)
{
	scene->draw_mode = 0;
	scene->preview = false;
	mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win, (WND_WIDTH + 30), 114, 255, "RENDER MODE ON. WAIT FOR CALCULATION");
	raytracing_main_bonus(scene->pix, scene, scene->mem_shuttle);
	pix_to_window(scene->pix, scene);
	mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win, (WND_WIDTH + 30), 114, 255, "RENDER MODE ON");
//	printf("render mode one \n");
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


void is_transformation_possible(t_scene *scene, int x, int y)
{
	if (scene->pix[scene->x][scene->y]->obj_a == PLAN && scene->draw_type == SCALE)
	{
		scene->draw_type = NO_MOVE;
		scene->draw_mode = PREVIEW;
		mlx_put_image_to_window(scene->ima->mlx_ptr,
		scene->ima->mlx_win, scene->ima->ima_blk, WND_WIDTH + 2, 850);
		mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win, (WND_WIDTH + 30), 900, 255, "IMPOSSIBLE TO SCALE A PLAN");
		mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win, (WND_WIDTH + 30), 920, 255, "SELECT ACTION");
	}
}