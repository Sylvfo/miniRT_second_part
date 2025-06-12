/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 09:17:48 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 22:37:42 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool	init_cam_cph(t_scene *scene)
{
	scene->cam = NULL;
	scene->cam = malloc(sizeof(t_camera));
	if (!scene->cam)
		return (false);
	cam_value_null(scene->cam);
	if (init_cam_coord(scene->cam) == false)
		return (false);
	if (init_cam_matrix(scene->cam) == false)
		return (false);
	return (true);
}

void	cam_value_null(t_camera *cam)
{
	cam->p_coord = NULL;
	cam->v_axe = NULL;
	cam->v_up = NULL;
	cam->v_left = NULL;
	cam->v_true_up = NULL;
	cam->m_orient = NULL;
	cam->m_transl = NULL;
	cam->m_transf = NULL;
	cam->m_inverse = NULL;
	cam->pixel_size = 0.0;
}

bool	init_cam_coord(t_camera *cam)
{
	if (!cam)
		return (false);
	cam->p_coord = create_point(0, 0, 0);
	if (!cam->p_coord)
		return (false);
	cam->v_axe = create_vector(0, 0, 0);
	if (!cam->v_axe)
		return (false);
	cam->v_up = create_vector(0, 1, 0);
	if (!cam->v_up)
		return (false);
	cam->v_left = create_vector(0, 0, 0);
	if (!cam->v_left)
		return (false);
	cam->v_true_up = create_vector(0, 0, 0);
	if (!cam->v_true_up)
		return (false);
	return (true);
}

bool	init_cam_matrix(t_camera *cam)
{
	if (!cam)
		return (false);
	cam->m_orient = create_indentity_matrix_44();
	if (!cam->m_orient)
		return (false);
	cam->m_transl = create_indentity_matrix_44();
	if (!cam->m_transl)
		return (false);
	cam->m_transf = create_indentity_matrix_44();
	if (!cam->m_transf)
		return (false);
	cam->m_inverse = create_indentity_matrix_44();
	if (!cam->m_inverse)
		return (false);
	return (true);
}
