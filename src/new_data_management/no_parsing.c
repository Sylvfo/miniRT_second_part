/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:12:48 by syl               #+#    #+#             */
/*   Updated: 2025/05/29 09:06:23 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//A EFFACER
//POUR TESTS SYLVIE
void	no_parsing(t_scene *scene)
{
	scene->cam->p_coord->x = 0;
	scene->cam->p_coord->y = 0;
	scene->cam->p_coord->z = 15;
	scene->cam->v_axe->x = 0;
	scene->cam->v_axe->y = 0;
	scene->cam->v_axe->z = -1;
	scene->cam->fov = 90;

	scene->obj[1][0]->p_coord->x = 0.0;
	scene->obj[1][0]->p_coord->y = 0.0;
	scene->obj[1][0]->p_coord->z = 0.0;
	scene->obj[1][0]->diam = 5.0;
	scene->obj[1][0]->color->r = 0.2;
	scene->obj[1][0]->color->g = 0.2;
	scene->obj[1][0]->color->b = 0.8;
	scene->obj[1][0]->type = SPHERE; /// A reprendre

	scene->obj[1][1]->p_coord->x = 2;
	scene->obj[1][1]->p_coord->y = 1;
	scene->obj[1][1]->p_coord->z = 3;
	scene->obj[1][1]->diam = 1.2;
	scene->obj[1][1]->color->r = 0.7;
	scene->obj[1][1]->color->g = 0.9;
	scene->obj[1][1]->color->b = 0.8;
	scene->obj[1][1]->type = SPHERE; /// A reprendre

/*	scene->obj[1][1]->p_coord->x = 2;
	scene->obj[1][1]->p_coord->y = 1;
	scene->obj[1][1]->p_coord->z = 3;
	scene->obj[1][1]->diam = 1.2;
	scene->obj[1][1]->color->r = 0.7;
	scene->obj[1][1]->color->g = 0.9;
	scene->obj[1][1]->color->b = 0.8;
	scene->obj[1][1]->type = SPHERE; /// A reprendre*/

	scene->lux[0][0]->ratio = 0.4;
	scene->lux[0][0]->color->r = 1.0;
	scene->lux[0][0]->color->g = 1.0;
	scene->lux[0][0]->color->b = 1.0;

	scene->lux[1][0]->ratio = 0.7;
	scene->lux[1][0]->p_coord->x = 6;
	scene->lux[1][0]->p_coord->y = 6;
	scene->lux[1][0]->p_coord->z = 4;
}
