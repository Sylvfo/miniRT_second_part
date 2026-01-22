/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows_plan.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:45:34 by cmegret           #+#    #+#             */
/*   Updated: 2025/06/12 14:47:59 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool	plan_shadow(t_mem *memory_shuttle, t_obj *plan)
{
	t_coord	p0_minus_p;
	float	denom;
	float	t;

	denom = dot_product(plan->v_axe, memory_shuttle->v_light_to_point);
	if (fabs(denom) < 0.0001)
		return (false);
	p0_minus_p.x = plan->p_coord->x - memory_shuttle->p_touch->x;
	p0_minus_p.y = plan->p_coord->y - memory_shuttle->p_touch->y;
	p0_minus_p.z = plan->p_coord->z - memory_shuttle->p_touch->z;
	t = dot_product(plan->v_axe, &p0_minus_p) / denom;
	if (t > EPSILON && t < memory_shuttle->distance_light_p_touch)
		return (true);
	return (false);
}
