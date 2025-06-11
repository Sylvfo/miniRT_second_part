/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_light_shadow_main.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:44:59 by syl               #+#    #+#             */
/*   Updated: 2025/06/02 11:32:58 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
t_color lighting(t_scene *scene, t_mem *memory_shuttle, t_color obj_color)
{
	int		i = 0;
//	t_color light_color = {0.0, 0.0, 0.0};
	t_color ambient_color;
	t_color this_light_color, specular_color;

	// Ambient
	obj_color = scalar_mult_color2(obj_color, scene->lux[0][0]->ratio);
//	obj_color = add_color(obj_color)
//	ambient_color = scalar_mult_color2(*(scene->lux[0][0]->color), scene->lux[0][0]->ratio);
//	obj_color = add_color(obj_color, ambient_color);
//	obj_color = multipling_color(obj_color, ambient_color);
	// Point lights
	while (i < 1)// scene->lux[1][i] != NULL)
	{
		prepare_v_light(memory_shuttle, scene->lux[1][i]->p_coord); 
		if (!intersect_objects_shadow(scene, memory_shuttle, i))
		{
			this_light_color = compute_pointlight(memory_shuttle, scene->lux[1][i]);
			specular_color = compute_specular(memory_shuttle, scene->lux[1][i], scene->cam->p_coord);
			this_light_color = add_color(this_light_color, specular_color);
			//this_light_color = multipling_color(this_light_color, specular_color);
			obj_color = add_color(obj_color, this_light_color);
			//obj_color = multipling_color(obj_color, this_light_color);
		}
		i++;
	}
	return (obj_color);
}*/

//ICI YA DU BONUS. VOIR SI C EST OK...
t_color	lighting(t_scene *scene, t_mem *memory_shuttle, t_color obj_color)
{
	int		i;
	t_color light_color;
	t_color specular_color;
	t_color this_light_color;

	i = 0;
	light_color.r = 0.0;
	light_color.g = 0.0;
	light_color.b = 0.0;
	while (i < 1)// (scene->lux[1][i] != NULL)
	{
		prepare_v_light(memory_shuttle, scene->lux[1][i]->p_coord); 
		if (intersect_objects_shadow(scene, memory_shuttle, i) == false)
		{
			this_light_color = compute_pointlight(memory_shuttle, scene->lux[1][i]);
			// if obj shiny
			specular_color = compute_specular(memory_shuttle, scene->lux[1][i], scene->cam->p_coord);
			this_light_color = add_color(this_light_color, specular_color);// function add three color??
			light_color = add_color(light_color, this_light_color);
		}
		i++;
	}
	light_color = add_color(light_color, *(scene->lux[0][0]->color));//ambiant
	obj_color = multipling_color(obj_color, light_color);
	return (obj_color); 
}

/*
AVANT RETOUR COULEUR
float	light_intensity_cph(t_scene *scene, t_mem *memory_shuttle)
{
	float	intensity;
	int		i;

	intensity = 0.0;
	intensity += scene->lux[0][0]->ratio;
	i = 0;
	//BOUCLE LUX
	while (i < 1)// (scene->lux[1][i] != NULL)
	{
		prepare_v_light(memory_shuttle, scene->lux[1][i]->p_coord); 
		if (intersect_objects_shadow(scene, memory_shuttle, i) == false)
		{
			intensity = intensity + compute_pointlight_old(memory_shuttle, scene->lux[1][i]);
			// PF il faudrait remettre la nouvelle data structure dans cette fonction  il faudrait aussi reflechir a comment 
			// if obj shiny
			intensity = intensity + compute_specular(memory_shuttle, scene->lux[1][i], scene->cam->p_coord);
		}
		i++;
	}
	printf("intensity %.4f \n", intensity);
	return (intensity); //return color??
}
*/


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

