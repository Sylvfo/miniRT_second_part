/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:34:56 by syl               #+#    #+#             */
/*   Updated: 2025/06/05 15:36:06 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
reflexion
faire recursivite
additionner avec la couleur de l objet pour mi-miroir
sparkle sur les objets miroirs... ou alors lumière qu on voit?
mettre le nombre de formes en plus max...
*/

void	raytracing_main_bonus(t_pix ***pix, t_scene *scene, t_mem *memory_shuttle)
{
	int	x;
	int	y;
	
	// PF ensuite fait les calculs pour chaque pixel 
	x = 0;
	//BOUCLE PIX
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			clean_memory_shuttle(memory_shuttle);
			//simplifier ces deux la... et enlever les viewport de la datastructure
			init_viewport_x_y(memory_shuttle, scene->cam, x, y);
			init_camera_pix_ray(memory_shuttle, scene->cam);
			pix[x][y]->preview = scene->preview;
		//	printf("pix preview is : %s\n", pix[x][y]->preview ? "true" : "false");
			*(pix[x][y]->color) = raytracer_bonus(pix[x][y], scene, memory_shuttle);
			y++;
		}
		x++;
	}
	return ;
}


t_color	raytracer_bonus(t_pix *pix, t_scene *scene, t_mem *memory_shuttle) 
{
	t_color	color;
//	t_color	color_refl;
	t_color	color_light;

	main_intersections(scene->obj, memory_shuttle);
	copy_matrix_44(memory_shuttle->obj_inv, scene->obj[memory_shuttle->obj_a][memory_shuttle->obj_b]->m_inv);
	closest_obj_in_pix(pix, memory_shuttle);
	if (memory_shuttle->obj_a == 0)
	{
		color = background_color(scene->obj[0][0], scene->lux[0][0]);
		return (color);
	}
	if (pix->preview == true)
	{
	//	printf("previewin raytracer bonus \n");
		return (*(scene->obj[memory_shuttle->obj_a][memory_shuttle->obj_b]->color));
	}
	
	prepare_computation(memory_shuttle, scene->obj);
	if (scene->obj[memory_shuttle->obj_a][memory_shuttle->obj_b]->mirror == 0.0)
		color_light = lighting(scene, memory_shuttle, *(scene->obj[pix->obj_a][pix->obj_b]->color));
	else if (scene->obj[memory_shuttle->obj_a][memory_shuttle->obj_b]->mirror > 0.0)
	{
		color_light = reflexion(scene, memory_shuttle, 4);
		//les ajouter...
	}
	//else
	
	return (color_light);
}

void paint_it_black(t_color *color)
{
	color->r = 0.0;
	color->g = 0.0;
	color->b = 0.0;
}

t_color	reflexion(t_scene *scene, t_mem *memory_shuttle, int recurs_count)
{
	t_color	color;

	(void) recurs_count;
	//printf("enter reflexion\n");
	next_ray_reflection(memory_shuttle);
	main_intersections(scene->obj, memory_shuttle);
	copy_matrix_44(memory_shuttle->obj_inv, scene->obj[memory_shuttle->obj_a][memory_shuttle->obj_b]->m_inv);
	if (memory_shuttle->obj_a == 0)
	{
		paint_it_black(&color);
	}
	prepare_computation(memory_shuttle, scene->obj);
	
	color = lighting(scene, memory_shuttle, *(scene->obj[memory_shuttle->obj_a][memory_shuttle->obj_b]->color));
	return (color);
}


/*
A retravailler

t_color	reflexion(t_scene *scene, t_mem *memory_shuttle, int recurs_count)
{
	t_color	color;

	//changer le ray + nettoyer le memory shuttle
//	next_ray_reflection(memory_shuttle);
//	main_intersections(scene->obj, memory_shuttle);
//	copy_matrix_44(memory_shuttle->obj_inv, scene->obj[memory_shuttle->obj_a][memory_shuttle->obj_b]->m_inv);
//	if (memory_shuttle->obj_a == 0)
//	{
//		color = background_color(scene->obj[0][0], scene->lux[0][0]);
//		return (color);
//	}
//	prepare_computation(memory_shuttle, scene->obj);
	if (scene->obj[memory_shuttle->obj_a][memory_shuttle->obj_b]->mirror != 1.0)
	{
		color = reflexion(scene, memory_shuttle, recurs_count - 1);
	}
//	color = lighting(scene, memory_shuttle, *(scene->obj[memory_shuttle->obj_a][memory_shuttle->obj_b]->color));
	//BONUS prendre obj shiness, transparence, texture,...
	//ICI RECURSIVITE
//	if (scene->obj[memory_shuttle->obj_a][memory_shuttle->obj_b]->mirror == 0.0 || recurs_count == 0)
//		return (color);
	if (recurs_count == 0)
	{
		color.r = 0.2;
		color.g = 0.8;
		color.b = 0.8;
		return (color);
	}
	color_light = reflexion(scene, memory_shuttle, 4);
	
//	multiplaction or additon??
//	color * scene->obj[pix->obj_a][pix->obj_b]->mirror 
	return (color);
}
*/