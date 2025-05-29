/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:58:41 by syl               #+#    #+#             */
/*   Updated: 2025/05/29 16:49:42 by syl              ###   ########.fr       */
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

	i = 0;
	if (scene->bonus_mode == false)
	{
		while (i < scene->nb_lights)
		{
			scene->lux[1][i]->color->r = 1.0;
			scene->lux[1][i]->color->g = 1.0;
			scene->lux[1][i]->color->b = 1.0;
			scene->lux[1][i]->color->rgb = 0; //??
			i++;
		}
	}
	if (scene->bonus_mode == true)
	{
		while (i < scene->nb_lights)
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
	}
	int a;
	int b;

	a = 1;
	b = 0;
	while(b < 2)
	{
		scene->obj[1][b]->diam = scene->obj[1][b]->diam / 2;
		scene->obj[1][b]->radius = scene->obj[1][b]->diam;// / 2;
//		scene->obj[1][b]->radius /= 2;
		//scene->obj[1][b]->radius = scene->obj[1][b]->diam;
		b++;
	}
	b = 0;
	while(b < 1)
	{
		scene->obj[3][b]->diam = scene->obj[1][b]->diam / 2;
		scene->obj[3][b]->radius = scene->obj[1][b]->diam;// / 2;
		b++;
	}

/*	while (b < )// a modifier
	{
		while(b < scene->nb_sphere)
		{
			scene->obj[a][b]->diam = scene->obj[a][b]->diam / 2;
			scene->obj[a][b]->radius = scene->obj[a][b]->diam ;
			b++;
		}
		a++;
	}*/
	
	
 	//DIAM ETC...
}
