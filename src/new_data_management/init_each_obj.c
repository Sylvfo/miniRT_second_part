/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_each_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 23:18:53 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 23:21:41 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool	init_each_obj(t_obj *obj)
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
	obj->difuse = 0.9;
	obj->specular = 0.8;
	obj->mirror = 0.0;
	obj->pattern.scale = 0;
	obj->pattern.type = -1;
	obj->color2 = (t_color){0, 1, 1, 0};
	obj->hastexture = false;
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

bool	init_each_obj_suite(t_obj *obj)
{
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

bool	init_each_obj_coord(t_obj *obj)
{
	obj->p_coord = create_point(0, 0, 0);
	if (!obj->p_coord)
		return (false);
	obj->normal = create_vector(0, 0, 0);
	if (!obj->normal)
		return (false);
	obj->tr_e1 = create_vector(0, 0, 0);
	if (!obj->tr_e1)
		return (false);
	obj->tr_e2 = create_vector(0, 0, 0);
	if (!obj->tr_e2)
		return (false);
	obj->tr_p1 = create_point(0, 0, 0);
	if (!obj->tr_p1)
		return (false);
	obj->tr_p2 = create_point(0, 0, 0);
	if (!obj->tr_p2)
		return (false);
	obj->tr_p3 = create_point(0, 0, 0);
	if (!obj->tr_p3)
		return (false);
	obj->v_axe = create_vector(0, 0, 0);
	if (!obj->v_axe)
		return (false);
	return (init_each_obj_suite(obj));
}

void	init_each_obj_null(t_obj *obj)
{
	obj->p_coord = NULL;
	obj->normal = NULL;
	obj->tr_p1 = NULL;
	obj->tr_p2 = NULL;
	obj->tr_p3 = NULL;
	obj->tr_e1 = NULL;
	obj->tr_e2 = NULL;
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
	obj->bump.img = NULL;
}
