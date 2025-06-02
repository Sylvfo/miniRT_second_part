/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:58:41 by syl               #+#    #+#             */
/*   Updated: 2025/06/02 11:20:54 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// modifications a faire avec les donnes de base...
// a faire apres que les donnees ont ete enregistrees. 
void	base_data2(t_scene *scene)
{
	int i;

	scene->bonus_mode = false; // A VOIR POUR CHANGER APRES
	scene->cam->fov = scene->cam->fov * 0.0174533;
	color_int_to_rgb(BAKGROUND_COLOR, scene->obj[0][0]->color);
	scene->obj[0][0]->color->r = int_to_float(scene->obj[0][0]->color->r);
	scene->obj[0][0]->color->g = int_to_float(scene->obj[0][0]->color->g);
	scene->obj[0][0]->color->b = int_to_float(scene->obj[0][0]->color->b);
	scalar_mult_color(scene->lux[0][0]->color, scene->lux[0][0]->ratio);
	
	i = 0;
/*	if (scene->bonus_mode == false)
	{
		while (i < scene->nb_lights)
		{
			scene->lux[1][i]->color->r = 1.0;
			scene->lux[1][i]->color->g = 1.0;
			scene->lux[1][i]->color->b = 1.0;
			scene->lux[1][i]->color->rgb = 0; //??
			i++;
		}
	}*/
/*	if (scene->bonus_mode == true)
	{
		while (i < scene->nb_lights)// mettres les lum a 1
		{
			if (scene->lux[1][i]->color->r != 0.0)
				scene->lux[1][i]->color->r /= 255.0;
			if (scene->lux[1][i]->color->g != 0.0)
				scene->lux[1][i]->color->g /= 255.0;
			if (scene->lux[1][i]->color->b != 0.0)	
				scene->lux[1][i]->color->b /= 255.0;
			scene->lux[1][i]->color->rgb = 0; //??
			i++;
		}
	}*/
	int a;
	int b;

	a = 1;
	b = 0;
	// SPHERES
	while(b < 2)
	{
		scene->obj[1][b]->diam = scene->obj[1][b]->diam / 2;
		scene->obj[1][b]->radius = scene->obj[1][b]->diam / 2;
		scene->obj[1][b]->difuse = 0.7;
		scene->obj[1][b]->specular = 0.8;
//		scene->obj[1][b]->radius /= 2;
		//scene->obj[1][b]->radius = scene->obj[1][b]->diam;
		b++;
	}
	while(b < 2)
	{
		scene->obj[2][b]->difuse = 0.9;
		scene->obj[2][b]->specular = 0.9;
//		scene->obj[1][b]->radius /= 2;
		//scene->obj[1][b]->radius = scene->obj[1][b]->diam;
		b++;
	}
	// CYL
	b = 0;
	while(b < 1)
	{
		scene->obj[3][b]->diam = scene->obj[3][b]->diam / 2;
		scene->obj[3][b]->radius = scene->obj[3][b]->diam / 2;
		scene->obj[3][b]->height = scene->obj[3][b]->height / 2;
		scene->obj[3][b]->difuse = 0.9;
		scene->obj[3][b]->specular = 0.9;
		b++;
	}
}
