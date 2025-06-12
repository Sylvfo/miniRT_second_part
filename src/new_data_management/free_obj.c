/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 23:08:57 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 23:10:45 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_each_obj(t_obj *obj)
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

void	free_each_obj_coord(t_obj *obj)
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
		obj->v_axe_r = NULL;
	}
	if (obj->from)
	{
		free(obj->from);
		obj->from = NULL;
	}
	if (obj->v_sph_camera)
	{
		free(obj->v_sph_camera);
		obj->v_sph_camera = NULL;
	}
}

void	free_obj(t_obj ***obj, int a, int nb)
{
	int	b;

	b = 0;
	while (b < nb)
	{
		free_each_obj(obj[a][b]);
		free(obj[a][b]);
		obj[a][b] = NULL;
		b++;
	}
	free(obj[a]);
	obj[a] = NULL;
}

void	free_obj_cph(t_scene *scene)
{
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
	free_obj(scene->obj, 1, scene->nb_sphere);
	free_obj(scene->obj, 2, scene->nb_plan);
	free_obj(scene->obj, 3, scene->nb_cylinder);
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
