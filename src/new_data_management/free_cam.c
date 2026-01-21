/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:36:55 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 22:38:52 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_cam_cph(t_scene *scene)
{
	if (!scene->cam)
		return ;
	free_cam_coord(scene->cam);
	free_cam_coord2(scene->cam);
	free_cam_matrix(scene->cam);
	free(scene->cam);
	scene->cam = NULL;
}

void	free_cam_coord(t_camera *cam)
{
	if (!cam)
		return ;
	if (cam->p_coord)
	{
		free(cam->p_coord);
		cam->p_coord = NULL;
	}
	if (cam->v_axe)
	{
		free(cam->v_axe);
		cam->v_axe = NULL;
	}
	if (cam->v_up)
	{
		free(cam->v_up);
		cam->v_up = NULL;
	}
}

void	free_cam_coord2(t_camera *cam)
{
	if (!cam)
		return ;
	if (cam->v_left)
	{
		free(cam->v_left);
		cam->v_left = NULL;
	}
	if (cam->v_true_up)
	{
		free(cam->v_true_up);
		cam->v_true_up = NULL;
	}
}

void	free_cam_matrix(t_camera *cam)
{
	if (!cam)
		return ;
	if (cam->m_orient)
	{
		free(cam->m_orient);
		cam->m_orient = NULL;
	}
	if (cam->m_transl)
	{
		free(cam->m_transl);
		cam->m_transl = NULL;
	}
	if (cam->m_transf)
	{
		free(cam->m_transf);
		cam->m_transf = NULL;
	}
	if (cam->m_inverse)
	{
		free(cam->m_inverse);
		cam->m_inverse = NULL;
	}
}
