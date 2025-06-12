/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_intersect_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:00:12 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 14:26:25 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	main_intersections(t_obj ***obj, t_mem *memory_shuttle)
{
	int	a;
	int	b;

	a = 1;
	while (a < NB_OBJ)
	{
		b = 0;
		while (obj[a] && b < obj[a][0]->number)
		{
			apply_transformation(obj[a][b], memory_shuttle);
			if (a == 1)
				intersect_sphere(memory_shuttle, b);
			if (a == 2)
				intersect_plan(memory_shuttle, b);
			if (a == 3)
				intersect_cylinder(memory_shuttle, b);
			b++;
		}
		a++;
	}
}
