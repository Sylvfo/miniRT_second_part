/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_intersect_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:00:12 by syl               #+#    #+#             */
/*   Updated: 2025/05/29 16:42:42 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//	A REFAIRE AVEC TOUS LES OBJETS
void	main_intersections(t_pix *pix,t_obj ***obj, t_mem *memory_shuttle)
{
	int a;
	int b;
	
	a = 1;
//	apply_transformation(pix, obj[1][0], memory_shuttle);
//	intersect_sphere(pix, b, memory_shuttle);

//	apply_transformation(pix, obj[2][0], memory_shuttle);
//	intersect_plan(memory_shuttle, b);

//	apply_transformation(pix, obj[3][0], memory_shuttle);
//	intersect_sphere(pix, b, memory_shuttle);

	while (a < 4)// A CHANGER AVEC NOUVEAU OBJETS. 
	{
		b = 0;
		while (obj[a][b] != NULL) //PF ici bien s assurer que ca fonctionne avec le bon nombre d objets
		{
			apply_transformation(pix, obj[a][b], memory_shuttle);
			if (a == 1)
				intersect_sphere(pix, b, memory_shuttle);
			if (a == 2 && b == 0)
				intersect_plan(memory_shuttle, b);
			if (a == 3)
				intersect_cylinder(memory_shuttle, b);
			b++;
		}
		a++;
	}
}

