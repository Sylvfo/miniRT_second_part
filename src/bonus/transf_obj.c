/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transf_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:02:02 by syl               #+#    #+#             */
/*   Updated: 2025/06/11 11:00:45 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void re_identity_matrix(float *m_identity)
{
	init_matrix_zero(m_identity);
	matrix_fill(m_identity, 0, 0, 1);
	matrix_fill(m_identity, 1, 1, 1);
	matrix_fill(m_identity, 2, 2, 1);
	matrix_fill(m_identity, 3, 3, 1);
}

void scaling_matrix(t_scene *scene, t_obj *obj)
{
	re_identity_matrix(obj->m_scale);
	if (scene->axe_draw == X_AXE || scene->axe_draw == U_UNITY)
		matrix_fill(obj->m_scale, 0, 0, scene->size_modif);
	if (scene->axe_draw == Y_AXE || scene->axe_draw == U_UNITY)
		matrix_fill(obj->m_scale, 1, 1, scene->size_modif);
	if (scene->axe_draw == Z_AXE || scene->axe_draw == U_UNITY)
		matrix_fill(obj->m_scale, 2, 2, scene->size_modif);
	matrix_fill(obj->m_scale, 3, 3, 1);//inutile?
}

void moving_matrix(t_scene *scene, t_obj *obj)
{
	re_identity_matrix(obj->m_transl);
	if (scene->axe_draw == X_AXE)
		matrix_fill(obj->m_transl, 0, 3, scene->size_modif);
	else if (scene->axe_draw == Y_AXE)
		matrix_fill(obj->m_transl, 1, 3, scene->size_modif);
	else if (scene->axe_draw == Z_AXE)
		matrix_fill(obj->m_transl, 2, 3, scene->size_modif);
	matrix_fill(obj->m_transl, 3, 3, 1);//inutile?
}

void rotating_matrix(t_scene *scene, t_obj *obj)
{
	re_identity_matrix(obj->m_rot);
	if (scene->axe_draw == X_AXE)
		rotation_x_matrix(scene,obj);
	else if (scene->axe_draw == Y_AXE)
		rotation_y_matrix(scene,obj);
	else if (scene->axe_draw == Z_AXE)
		rotation_z_matrix(scene,obj);
}