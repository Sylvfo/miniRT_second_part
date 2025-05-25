/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_raytracing_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:27:13 by syl               #+#    #+#             */
/*   Updated: 2025/05/25 17:15:58 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	raytracing(t_pix ***pix, t_scene *scene, t_mem *memory_shuttle)
{
	int	x;
	int	y;
	//
	constructing_camera(pix, scene);
	init_viewport(pix);
	matrix_transformations(scene);
	return ;

//	pix[0][0]->lux[1][0]->p_coord->t = 1;
	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			pix[x][y]->color = raytracer(pix[x][y], scene, memory_shuttle);
			y++;
		}
		x++;
	}
	return ;
}

t_color background_color(t_obj *obj_zero, t_light *lux_zero)
{
	t_color	background_color;

	background_color.r = obj_zero->color->r * lux_zero->ratio;
	background_color.g = obj_zero->color->g * lux_zero->ratio;
	background_color.b = obj_zero->color->b * lux_zero->ratio;
	return (background_color);
}

//CELUI CI POUR LA PARTIE PAS BONUS....
//t_pix pour les rays...
t_color	raytracer(t_pix *pix, t_scene *scene, t_mem **memory_shuttle)
{
	t_color	color;

	main_intersections2(pix, scene->obj, memory_shuttle);
	// deja faire sans les lumieres...
	color.r = scene->obj[pix->obj_a][pix->obj_b]->color->r;
	color.g = scene->obj[pix->obj_a][pix->obj_b]->color->g;
	color.b = scene->obj[pix->obj_a][pix->obj_b]->color->b;
	return (color);
	// a voir les lumieres apres...
/*	if (pix->obj_a == 0)
	{
		color = background_color(scene->obj[0][0], scene->lux[0][0]);
		return (color);
	}
	prepare_computation(pix);
	color = new_light(pix);
	return (color);*/
}


/*
	BONUS
	// pour reflexion
	// pour chaque calcule on a besoin de:
	// ray dir
	// ray origin
	// p_touch?? Non je crois pas...
	// scene
	// memory
	// donc on va envoyer tout ca a une fonction qui va nous retourner une couleur...
	// et cette couleur il faudra la multiplier etc...
// pour recursivite... et reflexion
t_color reflexion_color_rec(int a, t_scene *scene, t_mem *memory_shuttle)
{
	t_color color;
	t_color new_color;

	//set_transf..
	// intersections
	//find closest obj

	prepare_computation(memory_shuttle);
	new_color = new_light(scene, memory_shuttle);

	if (closest obj relf == 0.0 || a > 5 ) // ou s il croise pas d objet....
	// autre chose pour la couleur??
		return (new_color);
	find new ray + clear shuttle
    printf("before rec %d - %d\n", a, b);

	new_color = reflexion_color(a + 1,scene, meme shuttle)
   
	// how to add colors. 
	clear mem shuttle + avaible. 
	 printf("after rec %d - %d\n", a, b);
    return (color);
}*/
