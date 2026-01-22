/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_raytracing_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:27:13 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 23:45:21 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_color	pattern_checkboard(int x, int y, t_scene *scene, t_mem *mem)
{
	t_color	col[2];

	col[0] = *scene->obj[mem->obj_a][mem->obj_b]->color;
	col[1] = scene->obj[mem->obj_a][mem->obj_b]->color2;
	if ((x + y) % 2 == 0)
		return (col[0]);
	else
		return (col[1]);
}

t_color	pattern_stripes(float u, t_scene *scene, t_mem *mem)
{
	t_color	col[2];
	int		stripe;

	col[0] = *scene->obj[mem->obj_a][mem->obj_b]->color;
	col[1] = scene->obj[mem->obj_a][mem->obj_b]->color2;
	stripe = (int)(floor)(u);
	if ((stripe) % 2 == 0)
		return (col[0]);
	else
		return (col[1]);
}

t_color	pattern_gradient(float u, t_scene *scene, t_mem *mem)
{
	t_color	col[2];
	t_color	color;
	float	t;

	col[0] = *scene->obj[mem->obj_a][mem->obj_b]->color;
	col[1] = scene->obj[mem->obj_a][mem->obj_b]->color2;
	t = fmod(fabs(u), 1.0);
	color = (t_color){
		col[0].r * (1.0 - t) +col[1].r * t,
		col[0].g * (1.0 - t) +col[1].g * t,
		col[0].b * (1.0 - t) +col[1].b * t,
		0
	};
	return (color);
}

t_color	pattern_rings(float distance, t_scene *scene, t_mem *mem)
{
	t_color	col[2];
	int		ring;

	col[0] = *scene->obj[mem->obj_a][mem->obj_b]->color;
	col[1] = scene->obj[mem->obj_a][mem->obj_b]->color2;
	ring = (int)floor(distance);
	if ((ring) % 2 == 0)
		return (col[0]);
	else
		return (col[1]);
}
