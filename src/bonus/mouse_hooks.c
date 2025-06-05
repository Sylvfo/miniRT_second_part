/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:29:55 by syl               #+#    #+#             */
/*   Updated: 2025/06/05 14:26:35 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

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

int mouse_click(int button, int x, int y, t_scene *scene)
{
  //  printf("Clic détecté : bouton = %d, x = %d, y = %d\n", button, x, y);
	if (button == 1 && x < WND_WIDTH)
	{
		scene->preview = true;
		scene->x = x;
		scene->y = y;
		print_selected_object(scene);
	}
	else if (button == 1 && x >= WND_WIDTH)
	{
		if (y < 130)
		{
			scene->preview = true;
			raytracing_main_bonus(scene->pix, scene, scene->mem_shuttle);
			pix_to_window(scene->pix, scene);
			printf("preview mode one \n");
		}
		if (y > 220 && y < 320)
		{
			scene->preview = true;
			move_object(scene, scene->pix, scene->obj);
			raytracing_main_bonus(scene->pix, scene, scene->mem_shuttle);
			pix_to_window(scene->pix, scene);
			printf("preview mode one + object move \n");
		}
		
		if (y > 650 && y < 720)
		{
			scene->preview = false;
			raytracing_main_bonus(scene->pix, scene, scene->mem_shuttle);
			pix_to_window(scene->pix, scene);
			printf("render mode one \n");
		}
	}
    return (0);
}

