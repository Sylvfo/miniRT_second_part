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
	free_obj(scene->obj, SPHERE, scene->nb_sphere);
	free_obj(scene->obj, PLAN, scene->nb_plan);
	free_obj(scene->obj, CYLINDER, scene->nb_cylinder);
	free_obj(scene->obj, CONE, scene->nb_cone);
	free_obj(scene->obj, TRIANGLE, scene->nb_triangle);
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
