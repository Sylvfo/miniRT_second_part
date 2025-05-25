/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_intersect_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:00:12 by syl               #+#    #+#             */
/*   Updated: 2025/05/25 16:46:30 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
// a modifier.... deja double donc a effacer
void	intersect_pix_obj(t_pix *pix)
{
	int	a;
	int	b;

	a = 1;
	while (pix->obj[a] != NULL)
	{
		b = 0;
		while (pix->obj[a][b] != NULL)
		{
			if (a == 1)
				intersect_sphere(pix, b);
			if (a == 2)
				intersect_plan(pix, b);
			if (a == 3)
				intersect_cylinder(pix, b);
			b++;
		}
		a++;
	}
}*/

/*
// A effecer...
void	main_intersections(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			intersect_pix_obj(pix[x][y]);
			y++;
		}
		x++;
	}
}*/


void	main_intersections(t_pix *pix,t_obj ***obj, t_mem *memory_shuttle)
{
	int a;
	int b;

	a = 1;
	while (a < 4)
	{
		while (obj[a][b] != NULL) //tous les objets...
		{
			apply_transformation(pix, obj[a][b], memory_shuttle);
			if (a == 1)
				intersect_sphere(memory_shuttle, b);
/*			if (a == 2)
				intersect_plan(memory_shuttle, b);
			if (a == 3)
				intersect_cylinder(memory_shuttle, b);*/
			
	//		closest obj in pix...
		}
	}
}


void	intersect_pix_obj2(t_pix *pix)
{
	int	a;
	int	b;

	a = 1;
	while (pix->obj[a] != NULL)
	{
		b = 0;
		while (pix->obj[a][b] != NULL)
		{
			if (a == 1)
				intersect_sphere(pix, b);
			if (a == 2)
				intersect_plan(pix, b);
			if (a == 3)
				intersect_cylinder(pix, b);
			b++;
		}
		a++;
	}
}*/