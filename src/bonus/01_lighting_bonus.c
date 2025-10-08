/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_lighting_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 21:18:04 by syl               #+#    #+#             */
/*   Updated: 2025/10/08 19:49:30 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//main
t_color	lighting_bonus(t_scene *scene, t_mem *memory_shuttle, t_color obj_color)
{
	int		i;
	t_color	light_color;
	t_color	specular_color;
	t_color	this_light_color;
	
	light_color = init_color();
	memory_shuttle->color_shadow = create_color(0,0,0);
	memory_shuttle->new_color_shadow = create_color(0,0,0);
	memory_shuttle->p_light_to_point = create_point(0,0,0);
	memory_shuttle->percent_shadow = 0.0;
	i = 0;
	while (i < scene->nb_lights)
	{
		raytracer_shadow_bonus(scene, memory_shuttle, i);// ancien intersect_objects_shadow
		if (memory_shuttle->percent_shadow < 1.0)
		{
			this_light_color = compute_pointlight(memory_shuttle,
					scene->lux[1][i]);
			specular_color = compute_specular(memory_shuttle, scene->lux[1][i],
					scene->cam->p_coord);
			this_light_color = add_color(this_light_color, specular_color);
			light_color = add_color(light_color, this_light_color);
			//!!! pas plus foncé que ambiant lignht
			if (memory_shuttle->percent_shadow > 0.0)// && memory_shuttle->percent_shadow < 1.0)
			{
				//ici on ajoute l'ombre (transparence + couleur) à la lumière
			//	printf(".");
				light_color = scalar_mult_color2(light_color, (1.0f - memory_shuttle->percent_shadow));
				*memory_shuttle->color_shadow = scalar_mult_color2(*memory_shuttle->color_shadow, memory_shuttle->percent_shadow);
				light_color = multipling_color(light_color, *memory_shuttle->color_shadow);
				//light_color = add_color(light_color, *memory_shuttle->color_shadow);
				/*t_color transmitted = scalar_mult_color2(*memory_shuttle->color_shadow, memory_shuttle->percent_shadow);
				t_color visible = scalar_mult_color2(light_color, (1.0f - memory_shuttle->percent_shadow));
				light_color = add_color(visible, transmitted);*/
			}
		}
		i++;
	}
	//ambiant light
	light_color = add_color(light_color, *(scene->lux[0][0]->color));
	obj_color = multipling_color(obj_color, light_color);
	//obj_color = add_color(obj_color, light_color);
	free(memory_shuttle->color_shadow);
	free(memory_shuttle->new_color_shadow);
	return (obj_color);
}

void light_intersections_shadow(t_obj ***obj, t_mem *memory_shuttle)
{
	int	a;
	int	b;

	a = 1;
	while (a < NB_OBJ)
	{
		b = 0;
		while (obj[a] && b < obj[a][0]->number)
		{ 
			apply_transformation_bonus(obj[a][b], memory_shuttle);
			if (a == 1)
				intersect_sphere_shadow_bonus(memory_shuttle, obj[a][b]);
			if (a == 2)
				intersect_plan_shadow_bonus(memory_shuttle, obj[a][b]);
			if (a == 3)
				intersect_cylinder_bonus(memory_shuttle, obj[a][b]);
			if (a == 4)
				intersect_cone_bonus(memory_shuttle, obj[a][b]);
			if (a == 5)
				intersect_triangle_bonus(memory_shuttle, obj, b);
			if (memory_shuttle->percent_shadow >= 1.0)// || memory_shuttle->percent_new_shadow >= 1.0)
				return ;
			b++;
		}
		a++;
	}
}

/*///gpt
void	take_shadow_color(t_mem *mem_shuttle, t_intertt result, t_obj *obj)
{
	if ((result.t1 < INT_MAX && result.t1 > 0.0) || (result.t2 < INT_MAX && result.t2 > 0.0))
	{
		if (obj->transparence == 1.0)
			return;

		// Transparence courante
		double t = obj->transparence;

		// mise à jour du pourcentage d'ombre cumulée
		mem_shuttle->percent_shadow = 1.0 - (1.0 - mem_shuttle->percent_shadow) * (1.0 - (1.0 - t));

		// mélange de couleurs (substitution)
		t_color old = *mem_shuttle->color_shadow;
		t_color obj_col = *obj->color;

		t_color new_shadow;
		new_shadow.r = (1 - t) * obj_col.r + t * old.r;
		new_shadow.g = (1 - t) * obj_col.g + t * old.g;
		new_shadow.b = (1 - t) * obj_col.b + t * old.b;

		*mem_shuttle->color_shadow = new_shadow;
	}
}*/

/*
void	take_shadow_color(t_mem *mem_shuttle, t_intertt result, t_obj *obj)
{
	if ((result.t1 < INT_MAX && result.t1 > 0.0)
		|| (result.t2 < INT_MAX && result.t2 > 0.0))
	{
		double	t;

		t = obj->transparence; // 0 = opaque, 1 = transparent
		if (t == 1.0)
			return ;

		// ---- cumul de transparence ----
		mem_shuttle->percent_shadow = 1.0 - (1.0 - mem_shuttle->percent_shadow)
			* (1.0 - (1.0 - t));

		// ---- mélange progressif (substitution) ----
		// couleur de l'objet pondérée par son opacité
		t_color	obj_part = scalar_mult_color2(*obj->color, (1.0 - t));
		// couleur d'ombre précédente atténuée par la transparence
		t_color	old_part = scalar_mult_color2(*mem_shuttle->color_shadow, t);
		// on additionne les deux (équivaut à un mix : obj*(1-t) + old*t)
		*mem_shuttle->color_shadow = add_color(obj_part, old_part);
	}
}*/

// ici on additionne
void	take_shadow_color(t_mem *mem_shuttle, t_intertt result, t_obj *obj)// amcien closestt
{
	if ((result.t1 < INT_MAX && result.t1 > 0.0) || (result.t2 < INT_MAX && result.t2 > 0))
	{
 		if (obj->transparence == 1.0)
		{
			mem_shuttle->percent_shadow = 1.0;
			return;
		}
		//ici il faut mettre à jour le percent_shadow et la nouvelle couleur avec le nouvel objet. 
		//mem_shuttle->percent_new_shadow = obj->transparence;
		mem_shuttle->percent_shadow = 1.0 - (1.0 - mem_shuttle->percent_shadow) * (1.0 - obj->transparence);
		*mem_shuttle->new_color_shadow = scalar_mult_color2(*obj->color, obj->transparence);
		*mem_shuttle->color_shadow = scalar_mult_color2(*mem_shuttle->color_shadow, mem_shuttle->percent_new_shadow);
		*mem_shuttle->color_shadow = add_color(*mem_shuttle->color_shadow, *mem_shuttle->new_color_shadow);
		
		return;
	}
}

////////////////////////////// RAYTRACER
//fonction très importante =)
void raytracer_shadow_bonus(t_scene *scene, t_mem *mem_shtle, int num_light)
{
	clean_color(mem_shtle->color_shadow);
	clean_color(mem_shtle->new_color_shadow);
	mem_shtle->percent_shadow = 0.0;
	mem_shtle->percent_new_shadow = 0.0;
	//ici on remet les couleurs à zero
	next_ray_light(mem_shtle, scene->lux[1][num_light]->p_coord); //ancien prepare v light
	light_intersections_shadow(scene->obj, mem_shtle); // ancien main intersection
	return ;
}

void	next_ray_light(t_mem *mem_shuttle, t_coord *lux_p_coord)
{
	t_coord	offset;
	t_coord	tmp;

	//offset = scalar_mult_ret(mem_shuttle->r_base_dir, 0.02f);
	//addition_na(mem_shuttle->r_base_origin, mem_shuttle->p_touch, &offset);
	//scalar_mult_na(&tmp, mem_shuttle->v_norm_parral, 0.0001 * 10.0f);
//	addition_na(&offset, mem_shuttle->p_touch, &tmp);
//	offset = scalar_mult_ret(mem_shuttle->p_light_to_point, 0.01f);
	offset = scalar_mult_ret(mem_shuttle->v_norm_parral, 0.01f);
	addition_na(mem_shuttle->p_light_to_point, mem_shuttle->p_touch, &offset);
	offset.x = 0.0;
	offset.y = 0.0;
	offset.z = 0.0;
	offset.t = 1;
	tmp.x = 0.0;
	tmp.y = 0.0;
	tmp.z = 0.0;
	tmp.t = 0;
	scalar_mult_na(&tmp, mem_shuttle->v_norm_parral, 0.0001 * 10.0f);
	addition_na(&offset, mem_shuttle->p_touch, &tmp);
	substraction_p_to_v_na(mem_shuttle->v_light_to_point,
		lux_p_coord, &offset);
	//besoin?
	mem_shuttle->distance_light_p_touch
		= length_vector(mem_shuttle->v_light_to_point);
	normalize_vector_na(mem_shuttle->v_light_to_point);
	//clean_memory_shuttle_refl(mem_shuttle);
}

/*

void	take_shadow_color(t_mem *mem_shuttle, t_intertt result, t_obj *obj)// amcien closestt
{
//	printf("s");
	if ((result.t1 < INT_MAX && result.t1 > 0.0) || (result.t2 < INT_MAX && result.t2 > 0))
	{
 		if (obj->transparence == 1.0)
		{
			mem_shuttle->percent_shadow = 1.0;
			return;
		}
		mem_shuttle->percent_new_shadow = obj->transparence;
		mem_shuttle->percent_shadow = 1.0 - (1.0 - mem_shuttle->percent_shadow) * (1.0 - obj->transparence);
		*mem_shuttle->new_color_shadow = scalar_mult_color2(*obj->color, obj->transparence);
		return;
	}
	if (result.t2 < INT_MAX && result.t2 > 0)
	{
		if (obj->transparence == 1.0)
		{
	//		printf("iu");
			mem_shuttle->percent_shadow = 1.5;
			return;
		}
	//	printf("k");
		mem_shuttle->percent_new_shadow = obj->transparence;
		mem_shuttle->percent_shadow = 1.0 - (1.0 - mem_shuttle->percent_shadow) * (1.0 - obj->transparence);

		*mem_shuttle->new_color_shadow = scalar_mult_color2(*obj->color, obj->transparence);
		return;
	}
}
*/

/* dj utilisé
void	prepare_v_light(t_mem *mem_shuttle, t_coord *lux_p_coord)
{
	t_coord	offset_point;
	t_coord	tmp;

	offset_point.x = 0.0;
	offset_point.y = 0.0;
	offset_point.z = 0.0;
	offset_point.t = 1;
	tmp.x = 0.0;
	tmp.y = 0.0;
	tmp.z = 0.0;
	tmp.t = 0;
	scalar_mult_na(&tmp, mem_shuttle->v_norm_parral, 0.001 * 10.0f);
	addition_na(&offset_point, mem_shuttle->p_touch, &tmp);
	substraction_p_to_v_na(mem_shuttle->v_light_to_point,
		lux_p_coord, &offset_point);
	mem_shuttle->distance_light_p_touch
		= length_vector(mem_shuttle->v_light_to_point);
	normalize_vector_na(mem_shuttle->v_light_to_point);
}*/

//intersect_objects_shadow_bonus
/*
return color or transparency???
refaire le rayon entre objet et lampe. 
juste savoir si ça touche. 
raytracer...
*/

/*

t_color	lighting_bonus(t_scene *scene, t_mem *memory_shuttle, t_color obj_color)
{
	int		i;
	t_color	light_color;
	t_color	specular_color;
	t_color	this_light_color;

	i = 0;
	light_color = init_color();
	while (i < scene->nb_lights)
	{
		prepare_v_light(memory_shuttle, scene->lux[1][i]->p_coord);
		if (intersect_objects_shadow_bonus(scene, memory_shuttle) == false)
		{
			this_light_color = compute_pointlight(memory_shuttle,
					scene->lux[1][i]);
			specular_color = compute_specular(memory_shuttle, scene->lux[1][i],
					scene->cam->p_coord);
			this_light_color = add_color(this_light_color, specular_color);
			light_color = add_color(light_color, this_light_color);
		}
		i++;
	}
	light_color = add_color(light_color, *(scene->lux[0][0]->color));
	obj_color = multipling_color(obj_color, light_color);
	return (obj_color);
}
*/

/*
//A REVOIR AVEC NOUVELLE DATA STRUCTURE
bool	intersect_objects_shadow(t_scene *scene, t_mem *mem_shuttle)
{
	int		a;
	int		b;
	bool	in_shadow;
	float percent_shadow_object;
	t_color light_color;

	light_color = blanc. 
	

	mem_shuttle->percent_shadow = 0.0;
	percent_shadow_object = 0.0;
	

	in_shadow = false;
	a = 1;
	while (a < NB_OBJ)
	{
		b = 0;
		while (scene->obj[a] && b < scene->obj[a][0]->number)
		{
			if (a == SPHERE)
				in_shadow = sphere_shadow(scene->obj[a][b], mem_shuttle);
			else if (a == PLAN)
				in_shadow = plan_shadow(mem_shuttle, scene->obj[a][b]);
			else if (a == CYLINDER)
				in_shadow = cylinder_shadow(mem_shuttle, scene->obj[a][b]);
			if (mem_shuttle->percent_shadow >= 1.0);
				return (false);// black
			b++;
		}
		a++;
	}
	return (false);
}

*/