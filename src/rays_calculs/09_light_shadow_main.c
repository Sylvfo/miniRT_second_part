/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_light_shadow_main.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:44:59 by syl               #+#    #+#             */
/*   Updated: 2025/05/27 15:43:13 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//A REVOIR AVEC NOUVELLE DATA STRUCTURE


/*
// return color. 
// white intensity is 200,200,200
//t_color	light_intensity(t_scene *scene, t_mem *memory_shuttle)
float	light_intensity_old(t_scene *scene, t_mem *memory_shuttle) // besoin scene??
{
	t_color	intensity;
	t_color	intensity2;
	int		i;
	float oldintensity;

	oldintensity = scene->lux[0][0]->ratio;


	intensity.r = scene->lux[0][0]->ratio;
	intensity.g = scene->lux[0][0]->ratio;
	intensity.b = scene->lux[0][0]->ratio;
	intensity.rgb = 0.0;
	i = 0;
	//toutes les lumieres
//	prepare_v_light(memory_shuttle, scene->lux[1][0]->p_coord);
	oldintensity = oldintensity + compute_pointlight_old(memory_shuttle, scene->lux[1][0]);
//	intensity2 = compute_pointlight(memory_shuttle, scene->lux[1][0], intensity);
//	intensity.r = intensity.r + intensity2.r;
//	intensity.g = intensity.g + intensity2.g;
//	intensity.b = intensity.b + intensity2.b;
	while (scene->lux[1][i] != NULL)
	{
		prepare_v_light(memory_shuttle, scene->lux[1][i]->p_coord);
	//	if (intersect_objects_shadow(scene, memory_shuttle, i) == false)
	//	{
		//	printf("in shad\n");
		//	intensity = compute_pointlight(memory_shuttle, scene->lux[1][i], intensity);
			// ok	intensity = intensity + compute_pointlight(pix, pix->lux[1][i]);
		//		intensity = intensity + compute_specular(pix, pix->lux[1][i]);
	//	}

		intensity = compute_pointlight(memory_shuttle, scene->lux[1][i], intensity);
		i++;
	}
//	scalar_mult_color()
	return (oldintensity);
//	return (intensity);
}*/

/*
t_color	new_light(t_scene *scene, t_mem *memory_shuttle, t_color color)
{
	t_color intensity;
	float old_int;

	old_int = light_intensity_old(scene, memory_shuttle);

	scalar_mult_color(&color, old_int);
	//INIT INTENSITIY?
//	intensity = light_intensity(scene, memory_shuttle);
	//
//	multipling_color(&color, &intensity);
	return (color);
}*/

float	light_intensity_cph(t_scene *scene, t_mem *memory_shuttle)
{
	float	intensity;
	int		i;

	intensity = 0.0;
//	intensity += scene->lux[0][0]->ratio;
	i = 0;
	while (scene->lux[1][i] != NULL)
	{
		intensity = intensity + compute_pointlight_old(memory_shuttle, scene->lux[1][i]);
	//	prepare_v_light(memory_shuttle, scene->lux[1][i]->p_coord);
	//	if (intersect_objects_shadow(scene, memory_shuttle, i) == false)
	//	{
	//		intensity = intensity + compute_pointlight_old(memory_shuttle, scene->lux[1][i]);

		//	intensity = intensity + compute_specular(pix, pix->lux[1][i]);
	//	}
	//	else
	//		return (0.0);
		i++;
	}
	return (intensity);
}
//PAS BESOIN??
/*
void	new_light(t_pix ***pix)
{
	int		x;
	int		y;
	float	intensity;

	intensity = 1;
	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			intensity = light_intensity(pix[x][y]);
			pix[x][y]->color->r = pix[x][y]->comps->obj_color->r;
			pix[x][y]->color->g = pix[x][y]->comps->obj_color->g;
			pix[x][y]->color->b = pix[x][y]->comps->obj_color->b;
			if (pix[x][y]->comps->type == SPHERE ||
				pix[x][y]->comps->type == PLAN ||
				pix[x][y]->comps->type == CYLINDER)
				scalar_mult_color(pix[x][y]->color, intensity);
			y++;
		}
		x++;
	}
}*/


/*
ANCIENNE

//A REVOIR AVEC NOUVELLE DATA STRUCTURE
/*
float	light_intensity(t_pix *pix)
{
	float	intensity;
	int		i;

	intensity = 0.0;
	intensity += pix->lux[0][0]->ratio;
	pix->comps->obj_color->r *= pix->lux[0][0]->color->r / 255.0;
	pix->comps->obj_color->g *= pix->lux[0][0]->color->g / 255.0;
	pix->comps->obj_color->b *= pix->lux[0][0]->color->b / 255.0;
	i = 0;
	while (pix->lux[1][i] != NULL)
	{
		if (pix->comps->type == SPHERE || pix->comps->type == PLAN
			|| pix->comps->type == CYLINDER)
		{
			prepare_v_light(pix, i);
			if (intersect_objects_shadow(pix, i) == false)
			{
				intensity = intensity + compute_pointlight(pix, pix->lux[1][i]);
				intensity = intensity + compute_specular(pix, pix->lux[1][i]);
			}
		}
		i++;
	}
	return (intensity);
}

void	new_light(t_pix ***pix)
{
	int		x;
	int		y;
	float	intensity;

	intensity = 1;
	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			intensity = light_intensity(pix[x][y]);
			pix[x][y]->color->r = pix[x][y]->comps->obj_color->r;
			pix[x][y]->color->g = pix[x][y]->comps->obj_color->g;
			pix[x][y]->color->b = pix[x][y]->comps->obj_color->b;
			if (pix[x][y]->comps->type == SPHERE ||
				pix[x][y]->comps->type == PLAN ||
				pix[x][y]->comps->type == CYLINDER)
				scalar_mult_color(pix[x][y]->color, intensity);
			y++;
		}
		x++;
	}
}*/