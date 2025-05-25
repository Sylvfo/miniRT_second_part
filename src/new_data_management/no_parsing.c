/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:12:48 by syl               #+#    #+#             */
/*   Updated: 2025/05/25 19:25:58 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//A EFFACER
//POUR TESTS SYLVIE
void	no_parsing(t_scene *scene)
{
	scene->nb_sphere = 2;
	scene->nb_plan = 1;
	scene->nb_cylinder = 1;
	scene->nb_lights = 1;
	scene->wnd_height = 800;
	scene->wnd_width = 1200;

	scene->cam->p_coord->x = 0;
	scene->cam->p_coord->y = 0;
	scene->cam->p_coord->z = 20;
	scene->cam->fov = 70;

	scene->cam->v_axe->x = 0;
	scene->cam->v_axe->y = 0;
	scene->cam->v_axe->z = -1;
	scene->cam->fov = 70;

	scene->obj[1][0]->p_coord->x = 2;
	scene->obj[1][0]->p_coord->y = 2;
	scene->obj[1][0]->p_coord->z = 0;
	scene->obj[1][0]->diam = 2;
	scene->obj[1][0]->color->r = 0.2;
	scene->obj[1][0]->color->r = 0.2;
	scene->obj[1][0]->color->r = 0.8;

	scene->lux[0][0]->ratio = 1.8;
	scene->lux[0][0]->color->r = 0.5;
	scene->lux[0][0]->color->g = 0.2;
	scene->lux[0][0]->color->b = 0.8;

	scene->lux[1][0]->ratio = 1.8;
	scene->lux[1][0]->p_coord->x = 2;
	scene->lux[1][0]->p_coord->y = 5;
	scene->lux[1][0]->p_coord->z = 2;
}