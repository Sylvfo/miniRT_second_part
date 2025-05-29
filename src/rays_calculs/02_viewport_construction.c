/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_viewport_construction.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:57:11 by syl               #+#    #+#             */
/*   Updated: 2025/05/29 11:18:15 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	init_camera_pix_ray(t_pix *pix, t_camera *cam)
{
	matrix_point_multiplication_new(pix->r_origin, cam->m_inverse,
		cam->p_zero);
	matrix_point_multiplication_new(pix->p_viewport_world,
		cam->m_inverse, pix->p_viewport);
	substraction_p_to_v_na(pix->r_dir, pix->p_viewport_world, pix->r_origin);
	normalize_vector_na(pix->r_dir);
}

void	init_viewport_x_y(t_pix *pix, t_camera *cam, int x, int y)
{
	pix->p_viewport->x = cam->half_width
		- ((x + 0.5) * cam->pixel_size);
	pix->p_viewport->y = cam->half_height
		- ((y + 0.5) * cam->pixel_size);
	//pix->p_viewport->z toujours -1 parce dans methode le viewport est toujorus a 1 de la camera
}

void	init_viewport(t_pix ***pix, t_camera *cam)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			init_viewport_x_y(pix[x][y], cam, x, y);
			init_camera_pix_ray(pix[x][y], cam);
			y++;
		}
		x++;
	}
}


