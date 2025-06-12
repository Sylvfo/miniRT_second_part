/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_viewport_construction.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:57:11 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 11:43:26 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	init_camera_pix_ray(t_mem *memory_shuttle, t_camera *cam)
{
	t_coord p_zero;

	p_zero.x = 0.0;
	p_zero.y = 0.0;
	p_zero.z = 0.0;
	p_zero.t = 1;
	matrix_point_multiplication_new(memory_shuttle->r_base_origin,  cam->m_inverse, &p_zero);
	matrix_point_multiplication_new(memory_shuttle->p_viewport_world,
		cam->m_inverse, memory_shuttle->p_viewport);
	substraction_p_to_v_na(memory_shuttle->r_base_dir, memory_shuttle->p_viewport_world, memory_shuttle->r_base_origin);
	normalize_vector_na(memory_shuttle->r_base_dir);
}

void	init_viewport_x_y(t_mem *memory_shuttle, t_camera *cam, int x, int y)
{
    memory_shuttle->p_viewport->x = cam->half_width
        - ((x + 0.5) * cam->pixel_size);
    memory_shuttle->p_viewport->y = -cam->half_height
        + ((y + 0.5) * cam->pixel_size); // <-- inversion correcte de l'axe Y
    memory_shuttle->p_viewport->z = -1.0;
}

/*
void	init_viewport_x_y(t_mem *memory_shuttle, t_camera *cam, int x, int y)
{
	memory_shuttle->p_viewport->x = cam->half_width
		- ((x + 0.5) * cam->pixel_size);
	memory_shuttle->p_viewport->y = cam->half_height
		- ((y + 0.5) * cam->pixel_size);
	memory_shuttle->p_viewport->z = -1.0;
}*/
