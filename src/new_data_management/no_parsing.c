/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:12:48 by syl               #+#    #+#             */
/*   Updated: 2025/05/26 15:25:42 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//A EFFACER
//POUR TESTS SYLVIE
void	no_parsing(t_scene *scene)
{
	scene->cam->p_coord->x = 0;
	scene->cam->p_coord->y = 10;
	scene->cam->p_coord->z = 0;
	scene->cam->v_axe->x = 0;
	scene->cam->v_axe->y = -1;
	scene->cam->v_axe->z = 0;
	scene->cam->fov = 90;

	scene->obj[1][0]->p_coord->x = 0;
	scene->obj[1][0]->p_coord->y = 0;
	scene->obj[1][0]->p_coord->z = 0;
	scene->obj[1][0]->diam = 2;
	scene->obj[1][0]->color->r = 0.2;
	scene->obj[1][0]->color->r = 0.2;
	scene->obj[1][0]->color->r = 0.8;
	scene->obj[1][0]->type = SPHERE; /// A reprendre

	scene->obj[1][1]->p_coord->x = -3;
	scene->obj[1][1]->p_coord->y = -1;
	scene->obj[1][1]->p_coord->z = 0;
	scene->obj[1][1]->diam = 0.78;
	scene->obj[1][1]->color->r = 0.2;
	scene->obj[1][1]->color->r = 0.2;
	scene->obj[1][1]->color->r = 0.8;
	scene->obj[1][1]->type = SPHERE; /// A reprendre

	scene->lux[0][0]->ratio = 1.8;
	scene->lux[0][0]->color->r = 0.5;
	scene->lux[0][0]->color->g = 0.2;
	scene->lux[0][0]->color->b = 0.8;

	scene->lux[1][0]->ratio = 1.8;
	scene->lux[1][0]->p_coord->x = 2;
	scene->lux[1][0]->p_coord->y = 5;
	scene->lux[1][0]->p_coord->z = 2;
}

/*
void no_parsing_cam(t_camera *cam)
{
	if (!cam)
		return;
	//A RETIRER APRES RETOUR ENREGISTREMENT DONNEES
	cam->p_coord->x = 0;
	cam->p_coord->y = 20;
	cam->p_coord->z = 0;
	cam->v_axe->x = 0;
	cam->v_axe->y = -1;
	cam->v_axe->x = 0;
	cam->fov = 80;
}*/