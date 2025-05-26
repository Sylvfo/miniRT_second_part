/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:14:23 by syl               #+#    #+#             */
/*   Updated: 2025/05/26 10:18:02 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
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
	scene->obj[0][1] = NULL;
	// spheres
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
	obj->color = malloc(sizeof(t_color));
	if (!obj->color)
		return (false);
	return (true);
}


bool	init_each_obj_matrix(t_obj *obj)
{
	obj->m_transl = create_matrix(4, 4);
	if (!obj->m_transl)
		return (false);
	obj->m_rot = create_matrix(4, 4);
	if (!obj->m_rot)
		return (false);
	obj->m_scale = create_matrix(4, 4);
	if (!obj->m_scale)
		return (false);
	obj->m_transf = create_matrix(4, 4);
	if (!obj->m_transf)
		return (false);
	obj->m_inv = create_matrix(4, 4);
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
	obj->p_coord = malloc(sizeof(t_coord));
	if (!obj->p_coord)
		return (false);
	obj->v_axe = malloc(sizeof(t_coord));
	if (!obj->v_axe)
		return (false);
	obj->v_axe_r = malloc(sizeof(t_coord));
	if (!obj->v_axe_r)
		return (false);
	obj->from = malloc(sizeof(t_coord));
	if (!obj->from)
		return (false);
	obj->v_sph_camera = malloc(sizeof(t_coord));
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
		free(scene->obj[0][0]);
		scene->obj[0][0] = NULL;
	}
	free(scene->obj[0]);
	scene->obj[0] = NULL;
	b = 0;
	while (b < scene->nb_sphere)
	{
		free_each_obj(scene->obj[1][b]);
		//free les coord...
		free(scene->obj[1][b]);
		scene->obj[1][b] = NULL;
		b++;
	}
	free(scene->obj[1]);
	scene->obj[1] = NULL;
}*/
