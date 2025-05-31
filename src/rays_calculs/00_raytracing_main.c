/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_raytracing_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:27:13 by syl               #+#    #+#             */
/*   Updated: 2025/05/31 16:48:30 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	raytracing(t_pix ***pix, t_scene *scene, t_mem *memory_shuttle)
{
	int	x;
	int	y;
	
	// PF Construit tout ce qui est commun. 
	constructing_camera(scene);
	init_viewport(pix, scene->cam);
	matrix_transformations(scene->obj);
	// PF ensuite fait les calculs pour chaque pixel 
	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			clean_memory_shuttle(memory_shuttle);
			*(pix[x][y]->color) = raytracer(pix[x][y], scene, memory_shuttle);
			y++;
		}
		x++;
	}
	return ;
}

t_color	raytracer(t_pix *pix, t_scene *scene, t_mem *memory_shuttle)
{
	t_color	color;
	float	intensity;

	// PF je pense que ca marche
	intensity = 1.0;
	main_intersections(pix, scene->obj, memory_shuttle);
	copy_matrix_44(memory_shuttle->obj_inv, scene->obj[memory_shuttle->obj_a][memory_shuttle->obj_b]->m_inv);
	// PF pour garder en memoire l objet le plus proche de chaque pixel
	closest_obj_in_pix(pix, memory_shuttle);
	// PF dans le cas ou il crois aucun objet. 
	if (pix->obj_a == 0)
	{
		color = background_color(scene->obj[0][0], scene->lux[0][0]);
		return (color);
	}
	color.r = scene->obj[pix->obj_a][pix->obj_b]->color->r;
	color.g = scene->obj[pix->obj_a][pix->obj_b]->color->g;
	color.b = scene->obj[pix->obj_a][pix->obj_b]->color->b;
	prepare_computation(pix, scene->obj, memory_shuttle);
//	// PF le but serait que la fonction de lumiere retourne une couleur. Comme ca on pourra l utiliser dans 
	// la recursivite pour les reflexion et eventuellement la transparence. 
	// mais on avait fait une fonction de lumiere qui retourne juste un float d intensite. 
	intensity = light_intensity_cph(scene, memory_shuttle);
	//color = new_light(scene, memory_shuttle, color);
	scalar_mult_color(&color, intensity);
	return (color);
}

void	clean_memory_shuttle(t_mem *memory_shuttle)
{
	//ICI CHANGER LES RAYONS POUR LE NEXT SI RECURSIVITE. 
	memory_shuttle->closestt = INT_MAX;
	memory_shuttle->obj_a = 0;
	memory_shuttle->obj_b = 0;
	memory_shuttle->t_count = 0;
	memory_shuttle->distance_light_p_touch = 0.0;
	vector_fill(memory_shuttle->object_normal, 0, 0, 0);
	vector_fill(memory_shuttle->v_eye, 0, 0, 0);
	memory_shuttle->p_space->x = 0.0;
	memory_shuttle->p_space->y = 0.0;
	memory_shuttle->p_space->z = 0.0;
	memory_shuttle->p_touch->x = 0.0;
	memory_shuttle->p_touch->y = 0.0;
	memory_shuttle->p_touch->z = 0.0;
	vector_fill(memory_shuttle->v_light_to_point, 0, 0, 0);
	vector_fill(memory_shuttle->v_point_to_light, 0, 0, 0);
	vector_fill(memory_shuttle->reflect_dir, 0, 0, 0);
	vector_fill(memory_shuttle->scalar, 0, 0, 0);
	vector_fill(memory_shuttle->view_dir, 0, 0, 0);
	init_matrix_zero(memory_shuttle->obj_inv);
	init_matrix_zero(memory_shuttle->transp_inv);
}

t_color background_color(t_obj *obj_zero, t_light *lux_zero)
{
	t_color	background_color;

	background_color.r = obj_zero->color->r * lux_zero->ratio;
	background_color.g = obj_zero->color->g * lux_zero->ratio;
	background_color.b = obj_zero->color->b * lux_zero->ratio;
	return (background_color);
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
