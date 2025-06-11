/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:32:24 by syl               #+#    #+#             */
/*   Updated: 2025/06/11 10:59:44 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	rotation_x_matrix(t_scene *scene,t_obj *obj)
{
	float	sinr;
	float	cosr;

	scene->size_modif = degree_to_radian(scene->size_modif);
	sinr = sin(scene->size_modif);
	cosr = cos(scene->size_modif);
	matrix_fill(obj->m_rot, 0, 0, 1);
	matrix_fill(obj->m_rot, 1, 1, cosr);
	matrix_fill(obj->m_rot, 1, 2, -sinr);
	matrix_fill(obj->m_rot, 2, 1, sinr);
	matrix_fill(obj->m_rot, 2, 2, cosr);
	matrix_fill(obj->m_rot, 3, 3, 1);
}

void	rotation_y_matrix(t_scene *scene,t_obj *obj)
{
	float	sinr;
	float	cosr;

	scene->size_modif = degree_to_radian(scene->size_modif);
	sinr = sin(scene->size_modif);
	cosr = cos(scene->size_modif);
	matrix_fill(obj->m_rot, 0, 0, cosr);
	matrix_fill(obj->m_rot, 0, 2, sinr);
	matrix_fill(obj->m_rot, 1, 1, 1);
	matrix_fill(obj->m_rot, 2, 0, -sinr);
	matrix_fill(obj->m_rot, 2, 2, cosr);
	matrix_fill(obj->m_rot, 3, 3, 1);
}

void	rotation_z_matrix(t_scene *scene,t_obj *obj)
{
	float	sinr;
	float	cosr;

	scene->size_modif = degree_to_radian(scene->size_modif);
	sinr = sin(scene->size_modif);
	cosr = cos(scene->size_modif);
	matrix_fill(obj->m_rot, 0, 0, cosr);
	matrix_fill(obj->m_rot, 0, 1, -sinr);
	matrix_fill(obj->m_rot, 1, 0, sinr);
	matrix_fill(obj->m_rot, 1, 1, cosr);
	matrix_fill(obj->m_rot, 2, 2, 1);
	matrix_fill(obj->m_rot, 3, 3, 1);
}