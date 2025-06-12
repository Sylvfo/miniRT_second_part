/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:09:12 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 14:42:52 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	copy_coord(t_coord *new, t_coord *origin)
{
	new->x = origin->x;
	new->y = origin->y;
	new->z = origin->z;
	new->t = origin->t;
}

void	vector_fill(t_coord *vect, float x, float y, float z)
{
	vect->x = x;
	vect->y = y;
	vect->z = z;
	vect->t = 0;
}

void	point_fill(t_coord *point, float x, float y, float z)
{
	point->x = x;
	point->y = y;
	point->z = z;
	point->t = 1;
}

t_intertt	init_intertt(void)
{
	t_intertt	result;

	result.t1 = INT_MAX;
	result.t2 = INT_MAX;
	result.t_count = 0;
	return (result);
}

t_color	init_color(void)
{
	t_color	color;

	color.r = 0.0;
	color.g = 0.0;
	color.b = 0.0;
	return (color);
}