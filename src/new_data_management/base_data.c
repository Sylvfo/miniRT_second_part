/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:58:41 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 22:23:15 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	base_data(t_scene *scene)
{
	int	i;

	i = 0;
	background_base_color(scene);
	scene->cam->fov = scene->cam->fov * 0.0174533;
	while (i < scene->nb_sphere)
	{
		scene->obj[1][i]->diam = scene->obj[1][i]->diam / 2;
		scene->obj[1][i]->radius = scene->obj[1][i]->diam;
		i++;
	}
	i = 0;
	while (i < scene->nb_cylinder)
	{
		scene->obj[3][i]->diam = scene->obj[3][i]->diam / 2;
		scene->obj[3][i]->radius = scene->obj[3][i]->diam;
		scene->obj[3][i]->height = scene->obj[3][i]->height / 2;
		i++;
	}
}

void	background_base_color(t_scene *scene)
{
	color_int_to_rgb(BAKGROUND_COLOR, scene->obj[0][0]->color);
	scene->obj[0][0]->color->r = int_to_float(scene->obj[0][0]->color->r);
	scene->obj[0][0]->color->g = int_to_float(scene->obj[0][0]->color->g);
	scene->obj[0][0]->color->b = int_to_float(scene->obj[0][0]->color->b);
	scalar_mult_color(scene->lux[0][0]->color, scene->lux[0][0]->ratio);
}
