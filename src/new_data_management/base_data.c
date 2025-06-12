/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:58:41 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 12:11:35 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// modifications a faire avec les donnes de base...
// a faire apres que les donnees ont ete enregistrees. 
void	base_data2(t_scene *scene, t_pix ***pix)
{
	scene->wnd_height = (float)WND_HEIGHT;
	scene->wnd_width = (float)WND_WIDTH;
	scene->cam->fov = scene->cam->fov * 0.0174533;
	color_int_to_rgb(BAKGROUND_COLOR, scene->obj[0][0]->color);
	scene->obj[0][0]->color->r = int_to_float(scene->obj[0][0]->color->r);
	scene->obj[0][0]->color->g = int_to_float(scene->obj[0][0]->color->g);
	scene->obj[0][0]->color->b = int_to_float(scene->obj[0][0]->color->b);
	scalar_mult_color(scene->lux[0][0]->color, scene->lux[0][0]->ratio);
	scene->preview = false;
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
	int b;

	b = 0;
	// SPHERES
	while(b < scene->nb_sphere)
	{
		scene->obj[1][b]->diam = scene->obj[1][b]->diam / 2;
		scene->obj[1][b]->radius = scene->obj[1][b]->diam;
		scene->obj[1][b]->difuse = 0.7;// a deplacer...
		scene->obj[1][b]->specular = 0.8;// a deplacer...
		scene->obj[1][b]->mirror = 0.0;// a deplacer...
		b++;
	}
	b = 0;
	while(b < scene->nb_plan)
	{
		scene->obj[2][b]->difuse = 0.9;// a deplacer...
		scene->obj[2][b]->specular = 0.9;// a deplacer...
		scene->obj[2][b]->mirror = 0.0;// a deplacer...
		b++;
	}
	// CYL
	b = 0;
	while(b < scene->nb_cylinder)
	{
		scene->obj[3][b]->diam = scene->obj[3][b]->diam / 2;
		scene->obj[3][b]->radius = scene->obj[3][b]->diam;
		scene->obj[3][b]->height = scene->obj[3][b]->height / 2;
		scene->obj[3][b]->difuse = 0.9;
		scene->obj[3][b]->specular = 0.9;
		scene->obj[3][b]->mirror = 0.0;// a deplacer...
		b++;
	}

	int x = 0;
	int y = 0;
	//FOR BONUS
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			pix[x][y]->bonus =  true;
			pix[x][y]->preview = false;
			y++;
		}
		x++;
	}
	scene->axe_draw = 0;
	scene->draw_mode = 0;
	scene->draw_type = 0;
	scene->x = 0;
	scene->y = 0;
	scene->size_modif = 0.0;
	scene->after_virgule = 0.0;
	scene->size_modif_neg = 1.0;
}

