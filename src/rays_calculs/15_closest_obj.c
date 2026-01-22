/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_closest_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:48:36 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 14:35:15 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	closestt(t_mem *mem_shuttle, t_intertt result, int obj_type, int obj_nu)
{
	if (result.t1 < mem_shuttle->closestt && result.t1 > 0)
	{
		mem_shuttle->closestt = result.t1;
		mem_shuttle->obj_a = obj_type;
		mem_shuttle->obj_b = obj_nu;
		mem_shuttle->t_count = result.t_count;
		copy_coord(mem_shuttle->r_dir_closest_obj, mem_shuttle->r_dir_m);
		copy_coord(mem_shuttle->r_origin_closest_obj, mem_shuttle->r_origin_m);
	}
	if (result.t2 < mem_shuttle->closestt && result.t2 > 0)
	{
		mem_shuttle->closestt = result.t2;
		mem_shuttle->obj_a = obj_type;
		mem_shuttle->obj_b = obj_nu;
		mem_shuttle->t_count = result.t_count;
		copy_coord(mem_shuttle->r_dir_closest_obj, mem_shuttle->r_dir_m);
		copy_coord(mem_shuttle->r_origin_closest_obj, mem_shuttle->r_origin_m);
	}
}

void	closest_obj_in_pix(t_pix *pix, t_mem *mem_shuttle)
{
	pix->obj_a = mem_shuttle->obj_a;
	pix->obj_b = mem_shuttle->obj_b;
}
