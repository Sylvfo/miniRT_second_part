/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:03:29 by syl               #+#    #+#             */
/*   Updated: 2025/06/04 23:15:00 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_scene *init_first_scene_memory(void)
{
	t_scene *scene;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->cam = NULL;
	scene->ima = NULL;
	scene->obj = NULL;
	scene->lux = NULL;
	// PF A ENLEVER APRES ENREGISTREMENT DES DONNEES
	scene->nb_sphere = 2;
	scene->nb_plan = 1;
	scene->nb_cylinder = 1;
	scene->nb_lights = 1;
	scene->wnd_height = WND_HEIGHT;
	scene->wnd_width = WND_WIDTH;
	return (scene);
}

bool	init_scene_memory(t_scene *scene)
{
	if (!scene)
		return (false);
	if (init_cam_cph(scene) == false)
		return (false);
	scene->ima = NULL;
	scene->ima = create_image();
	if (!scene->ima)
		return (false);
//	if (scene->bonus_mode == true)
//	{
	if (create_image_cmd(scene->ima) == false)
			return (false);
//	}	
	if (init_obj_cph(scene) == false)
		return (false);
	if (init_lux_cph(scene) == false)
		return (false);
	return (true);
}

bool init_obj_cph(t_scene *scene)
{
	int		a;
	int		b;

	scene->obj = NULL;
	scene->obj = malloc(sizeof(t_obj **) * 5); // 5 pour nombre objet
	if (!scene->obj)
		return (false);
	scene->obj[0] = malloc(sizeof(t_obj *) * 2);
	scene->obj[0][0] = malloc(sizeof(t_obj));
	if (!scene->obj[0][0])
		return (false);
	if (init_each_obj(scene->obj[0][0]) == false)
			return (false);
	scene->obj[0][1] = NULL;
	// SPHERES
	b = 0;
	scene->obj[1] = NULL;
	scene->obj[1] = malloc(sizeof(t_obj *) * (scene->nb_sphere));
	if (!scene->obj[1])
		return (false);
	while (b < scene->nb_sphere)
	{
		scene->obj[1][b] = malloc(sizeof(t_obj));
		if (!scene->obj[1][b])
			return (false);
		if (init_each_obj(scene->obj[1][b]) == false)
			return (false);
		scene->obj[1][b]->type = SPHERE;
		b++;
	}
	// PLANS
	b = 0;
	scene->obj[2] = NULL;
	scene->obj[2] = malloc(sizeof(t_obj *) * (scene->nb_plan));
	while (b < scene->nb_plan)
	{
		scene->obj[2][b] = malloc(sizeof(t_obj));
		if (!scene->obj[2][b])
			return (false);
		if (init_each_obj(scene->obj[2][b]) == false)
			return (false);
		scene->obj[2][b]->type = PLAN;
		b++;
	}
	// CYLINDERS
	b = 0;
	scene->obj[3] = NULL;
	scene->obj[3] = malloc(sizeof(t_obj *) * (scene->nb_cylinder));
	while (b < scene->nb_cylinder)
	{
		scene->obj[3][b] = malloc(sizeof(t_obj));
		if (!scene->obj[3][b])
			return (false);
		if (init_each_obj(scene->obj[3][b]) == false)
			return (false);
		b++;
	}
	// autres objets... 
	//	scene->obj[5] = NULL;
	return (true);
}


void free_each_obj(t_obj *obj)
{
	if (!obj)
		return ;
	free_each_obj_coord(obj);
	free_each_obj_matrix(obj);

	if (obj->color)
	{
		free(obj->color);
		obj->color = NULL;
	}
}

bool init_each_obj(t_obj *obj)
{
	if (!obj)
		return (obj);
	init_each_obj_null(obj);
	if (init_each_obj_coord(obj) == false)
		return (false);
	if (init_each_obj_matrix(obj) == false)
		return (false);
	obj->color = create_color(0.0, 0.0, 0.0);
	if (!obj->color)
		return (false);
	obj->color->r = 0.0;
	obj->color->g = 0.0;
	obj->color->b = 0.0;
	obj->color->rgb = 0;
	obj->type = NONE;
	//obj->difuse = 
	return (true);
}

bool	init_each_obj_matrix(t_obj *obj)
{
	obj->m_transl = create_indentity_matrix_44();
	if (!obj->m_transl)
		return (false);
	obj->m_rot = create_indentity_matrix_44();
	if (!obj->m_rot)
		return (false);
	obj->m_scale = create_indentity_matrix_44();
	if (!obj->m_scale)
		return (false);
	obj->m_transf = create_indentity_matrix_44();
	if (!obj->m_transf)
		return (false);
	obj->m_inv = create_indentity_matrix_44();
	if (!obj->m_inv)
		return (false);
	return (true);
}



void	free_each_obj_matrix(t_obj *obj)
{
	if (obj->m_transl)
	{
		free(obj->m_transl);
		obj->m_transl = NULL;
	}
	if (obj->m_rot)
	{
		free(obj->m_rot);
		obj->m_rot = NULL;
	}
	if (obj->m_scale)
	{
		free(obj->m_scale);
		obj->m_scale = NULL;
	}
	if (obj->m_transf)
	{
		free(obj->m_transf);
		obj->m_transf = NULL;
	}
	if (obj->m_inv)
	{
		free(obj->m_inv);
		obj->m_inv = NULL;
	}
}

bool init_each_obj_coord(t_obj *obj)
{
	obj->p_coord = create_point(0, 0, 0);
	if (!obj->p_coord)
		return (false);
	obj->v_axe = create_vector(0, 0, 0);
	if (!obj->v_axe)
		return (false);
	obj->v_axe_r = create_vector(0, 0, 0);
	if (!obj->v_axe_r)
		return (false);
	obj->from = create_vector(0, 1, 0);
	if (!obj->from)
		return (false);
	obj->v_sph_camera = create_vector(0, 0, 0);
	if (!obj->v_sph_camera)
		return (false);
	return (true);
}


void free_each_obj_coord(t_obj *obj)
{
	if (obj->p_coord)
	{
		free(obj->p_coord);
		obj->p_coord = NULL;
	}
	if (obj->v_axe)
	{
		free(obj->v_axe);
		obj->v_axe = NULL;
	}
	if (obj->v_axe_r)
	{
		free(obj->v_axe_r);
		obj->v_axe_r= NULL;
	}
	if (obj->from)
	{
		free(obj->from);
		obj->from= NULL;
	}
	if (obj->v_sph_camera)
	{
		free(obj->v_sph_camera);
		obj->v_sph_camera= NULL;
	}
}

void	init_each_obj_null(t_obj *obj)
{
	obj->p_coord = NULL;
	obj->color = NULL;
	obj->v_axe = NULL; 
	obj->m_transl = NULL; 
	obj->m_rot = NULL; 
	obj->m_scale = NULL;
	obj->m_transf = NULL;
	obj->m_inv = NULL; 
	obj->v_axe_r = NULL;
	obj->from = NULL;
	obj->v_sph_camera = NULL;
}

void free_obj_cph(t_scene *scene)
{
	int b;

	if (!scene->obj)
		return ;
	if (scene->obj[0][0])
	{
		free_each_obj(scene->obj[0][0]);
		free(scene->obj[0][0]);
		scene->obj[0][0] = NULL;
	}
	free(scene->obj[0]);
	scene->obj[0] = NULL;
	b = 0;
	while (b < scene->nb_sphere)
	{
		free_each_obj(scene->obj[1][b]);
		free(scene->obj[1][b]);
		scene->obj[1][b] = NULL;
		b++;
	}
	free(scene->obj[1]);
	scene->obj[1] = NULL;
	b = 0;
	while (b < scene->nb_plan)
	{
		free_each_obj(scene->obj[2][b]);
		free(scene->obj[2][b]);
		scene->obj[2][b] = NULL;
		b++;
	}
	free(scene->obj[2]);
	scene->obj[2] = NULL;
	b = 0;
	while (b < scene->nb_cylinder)
	{
		free_each_obj(scene->obj[3][b]);
		free(scene->obj[3][b]);
		scene->obj[3][b] = NULL;
		b++;
	}
	free(scene->obj[3]);
	scene->obj[3] = NULL;
}
