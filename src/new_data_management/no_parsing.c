/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:12:48 by syl               #+#    #+#             */
/*   Updated: 2025/06/07 16:30:15 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//A EFFACER un fois qu on aura les donnees des fichiers .rt
//POUR TESTS SYLVIE
void	no_parsing(t_scene *scene)
{
	scene->cam->p_coord->x = 0;
	scene->cam->p_coord->y = 0;
	scene->cam->p_coord->z = 20;
	scene->cam->v_axe->x = 0;
	scene->cam->v_axe->y = 0;
	scene->cam->v_axe->z = -1;
	scene->cam->fov = 90;

	scene->obj[1][0]->p_coord->x = 0.0;
	scene->obj[1][0]->p_coord->y = 0.0;
	scene->obj[1][0]->p_coord->z = 0.0;
	scene->obj[1][0]->diam = 4.0;
	scene->obj[1][0]->color->r = 0.0;
	scene->obj[1][0]->color->g = 0.0;
	scene->obj[1][0]->color->b = 0.8;
	scene->obj[1][0]->type = SPHERE; /// A reprendre

/*	scene->obj[1][1]->p_coord->x = 2;
	scene->obj[1][1]->p_coord->y = 1;
	scene->obj[1][1]->p_coord->z = 3;
	scene->obj[1][1]->diam = 1.2;
	scene->obj[1][1]->color->r = 0.7;
	scene->obj[1][1]->color->g = 0.9;
	scene->obj[1][1]->color->b = 0.8;
	scene->obj[1][1]->type = SPHERE; /// A reprendre*/

/*	scene->obj[1][1]->p_coord->x = 2;
	scene->obj[1][1]->p_coord->y = 1;
	scene->obj[1][1]->p_coord->z = 3;
	scene->obj[1][1]->diam = 1.2;
	scene->obj[1][1]->color->r = 0.7;
	scene->obj[1][1]->color->g = 0.9;
	scene->obj[1][1]->color->b = 0.8;
	scene->obj[1][1]->type = SPHERE; /// A reprendre*/

	scene->lux[0][0]->ratio = 0.3;
	scene->lux[0][0]->color->r = 0.2;// 0.2;
	scene->lux[0][0]->color->g = 0.2;//0.2;
	scene->lux[0][0]->color->b = 0.2;

	scene->lux[1][0]->ratio = 0.9;
	scene->lux[1][0]->p_coord->x = 4;
	scene->lux[1][0]->p_coord->y = 4;
	scene->lux[1][0]->p_coord->z = 4;
	scene->lux[1][0]->color->r = 0.9;// 0.2;
	scene->lux[1][0]->color->g = 0.1;//0.2;
	scene->lux[1][0]->color->b = 0.9;
	
	scene->obj[2][0]->p_coord->x = 0;
	scene->obj[2][0]->p_coord->y = -2;
	scene->obj[2][0]->p_coord->z = 0;
	scene->obj[2][0]->v_axe->x = 0;
	scene->obj[2][0]->v_axe->y = 1;
	scene->obj[2][0]->v_axe->z = 0;
	scene->obj[2][0]->color->r = 0.8;
	scene->obj[2][0]->color->g = 0.1;
	scene->obj[2][0]->color->b = 0.3;
	scene->obj[2][0]->type = PLAN;// A reprendre


	scene->obj[3][0]->p_coord->x = -4.5;
	scene->obj[3][0]->p_coord->y = 0;
	scene->obj[3][0]->p_coord->z = 0;
	/*
		scene->obj[3][0]->v_axe->x = -0.2;
	scene->obj[3][0]->v_axe->y = -0.3;
	scene->obj[3][0]->v_axe->z = -1;
	*/
/*
	scene->obj[3][0]->v_axe->x = 0.5;
	scene->obj[3][0]->v_axe->y = 0.8660;
	scene->obj[3][0]->v_axe->z = 0;*/
/*	scene->obj[3][0]->v_axe->x = -0.2;
	scene->obj[3][0]->v_axe->y = -0.3;
	scene->obj[3][0]->v_axe->z = -1;*/
	
	scene->obj[3][0]->v_axe->x = 0;
	scene->obj[3][0]->v_axe->y = 1;
	scene->obj[3][0]->v_axe->z = 0;
	scene->obj[3][0]->height = 2;
	scene->obj[3][0]->diam = 3;
	scene->obj[3][0]->color->r = 0.78;
	scene->obj[3][0]->color->g = 0.28;
	scene->obj[3][0]->color->b = 0.56;
	scene->obj[3][0]->type = CYLINDER; /// A reprendre
}
