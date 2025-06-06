/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_intersect_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:00:12 by syl               #+#    #+#             */
/*   Updated: 2025/06/02 13:38:31 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//	A REFAIRE AVEC TOUS LES OBJETS
void	main_intersections(t_obj ***obj, t_mem *memory_shuttle)
{
	int a;
	int b;
	
	a = 1;
	//BOUCLE OBJ
	while (a < NB_OBJ)// A CHANGER AVEC NOUVEAU OBJETS. 
	{
		b = 0;
		while (obj[a] && b < obj[a][0]->number) //obj[a][b] != NULL) //PF ici bien s assurer que ca fonctionne avec le bon nombre d objets
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

