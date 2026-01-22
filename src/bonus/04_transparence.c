/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_transparence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 21:08:54 by syl               #+#    #+#             */
/*   Updated: 2025/10/07 21:08:57 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	next_ray_transp(t_mem *mem_shuttle)
{
	t_coord	offset;

	offset = scalar_mult_ret(mem_shuttle->r_base_dir, 0.001f);
	addition_na(mem_shuttle->r_base_origin, mem_shuttle->p_touch, &offset);
	clean_memory_shuttle_refl(mem_shuttle);
}

t_color	transparence(t_scene *scene, t_mem *mem_shtle)
{
	t_color	color;

	next_ray_transp(mem_shtle);
	color = raytracer_bonus(NULL, scene, mem_shtle);
	return (color);
}
