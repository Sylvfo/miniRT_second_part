/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_closest_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:48:36 by syl               #+#    #+#             */
/*   Updated: 2025/05/31 16:42:53 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	closestt(t_mem *memory_shuttle, t_intertt result, int obj_type, int obj_num)
{
	if (result.t1 < memory_shuttle->closestt && result.t1 > 0)
	{
		memory_shuttle->closestt = result.t1;
		memory_shuttle->obj_a = obj_type;
		memory_shuttle->obj_b = obj_num;
		memory_shuttle->t_count = result.t_count;
		copy_coord(memory_shuttle->r_dir_closest_obj, memory_shuttle->r_dir_m);
		copy_coord(memory_shuttle->r_origin_closest_obj, memory_shuttle->r_origin_m);
	}
	if (result.t2 < memory_shuttle->closestt && result.t2 > 0)
	{
		memory_shuttle->closestt = result.t2;
		memory_shuttle->obj_a = obj_type;
		memory_shuttle->obj_b = obj_num;
		memory_shuttle->t_count = result.t_count;
		copy_coord(memory_shuttle->r_dir_closest_obj, memory_shuttle->r_dir_m);
		copy_coord(memory_shuttle->r_origin_closest_obj, memory_shuttle->r_origin_m);
	}
}

void closest_obj_in_pix(t_pix *pix, t_mem *memory_shuttle)
{
	pix->obj_a = memory_shuttle->obj_a;
	pix->obj_b = memory_shuttle->obj_b;
}
