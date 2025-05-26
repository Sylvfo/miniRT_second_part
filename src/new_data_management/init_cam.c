/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 09:17:48 by syl               #+#    #+#             */
/*   Updated: 2025/05/26 11:59:34 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool init_cam_cph(t_scene *scene)
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

void cam_value_null(t_camera *cam)
{
	cam->p_coord = NULL;
	cam->v_axe = NULL;
	cam->p_zero = NULL;
	cam->v_up = NULL;
	cam->v_left = NULL;
	cam->v_true_up = NULL;
	cam->m_orient = NULL;
	cam->m_transl = NULL;
	cam->m_transf = NULL;
	cam->m_inverse = NULL;
	cam->pixel_size = 0.0;
}

bool init_cam_coord(t_camera *cam)
{
	if (!cam)
		return (false);
	cam->p_coord = create_point(0, 0, 0);
	if (!cam->p_coord)
		return (false);
	cam->v_axe = create_vector(0, 0, 0);
	if (!cam->v_axe)
		return (false);
	cam->p_zero = create_point(0, 0, 0);
	if (!cam->p_zero)
		return (false);
	cam->v_up =  create_vector(0, 1, 0);
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

bool init_cam_matrix(t_camera *cam)
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

void free_cam_cph(t_scene *scene)
{
	if (!scene->cam)
		return ;
	free_cam_coord(scene->cam);
	free_cam_matrix(scene->cam);
	free(scene->cam);
	scene->cam = NULL;
}

void free_cam_coord(t_camera *cam)
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
	if (cam->p_zero)
	{
		free(cam->p_zero);
		cam->p_zero = NULL;
	}
	if (cam->v_up)
	{
		free(cam->v_up);
		cam->v_up = NULL;
	}
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

void free_cam_matrix(t_camera *cam)
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