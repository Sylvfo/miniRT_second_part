/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_intersect_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:00:12 by syl               #+#    #+#             */
/*   Updated: 2025/05/28 11:39:12 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//	A REFAIRE AVEC TOUS LES OBJETS
void	main_intersections(t_pix *pix,t_obj ***obj, t_mem *memory_shuttle)
{
	int a;
	int b;
	
	a = 1;
	while (a < 2)// A CHANGER AVEC NOUVEAU OBJETS. 
	{
		b = 0;
		while (b < 2)// (obj[a][b] != NULL) //tous les objets...
		{
			apply_transformation(pix, obj[1][b], memory_shuttle);
			if (a == 1)
				intersect_sphere(pix, b, memory_shuttle);
//			if (a == 2)
//				intersect_plan(memory_shuttle, b);
//			if (a == 3)
//				intersect_cylinder(memory_shuttle, b);
			b++;
		}
		a++;
	}
}

