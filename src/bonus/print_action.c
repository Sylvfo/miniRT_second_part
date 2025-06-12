/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:19:38 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 16:17:12 by syl              ###   ########.fr       */
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

void	print_action(t_scene *scene)
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

void	print_object(t_scene *scene)
{
	if (scene->pix[scene->x][scene->y]->obj_a == SPHERE)
		printf("sphere n° %i ",
			1 + scene->pix[scene->x][scene->y]->obj_b);
	else if (scene->pix[scene->x][scene->y]->obj_a == PLAN)
		printf("plan n° %i ",
			1 + scene->pix[scene->x][scene->y]->obj_b);
	else if (scene->pix[scene->x][scene->y]->obj_a == CYLINDER)
		printf("cylinder n° %i ",
			1 + scene->pix[scene->x][scene->y]->obj_b);
}

void	print_value(t_scene *scene)
{
	if (scene->draw_type == ROTATE)
		printf("%.3f degrees ", scene->size_modif);
	else
		printf("%.3f units ", scene->size_modif);
}

void	print_axe(t_scene *scene)
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
