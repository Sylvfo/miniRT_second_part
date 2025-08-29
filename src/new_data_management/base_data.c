/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:58:41 by syl               #+#    #+#             */
/*   Updated: 2025/06/13 11:30:33 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void	base_cylcone(t_scene *scene, int a, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		scene->obj[a][i]->diam = scene->obj[a][i]->diam / 2;
		scene->obj[a][i]->radius = scene->obj[a][i]->diam;
		scene->obj[a][i]->height = scene->obj[a][i]->height / 2;
		i++;
	}
}

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
	base_cylcone(scene, CYLINDER, scene->nb_cylinder);
	base_cylcone(scene, CONE, scene->nb_cone);
}

void	background_base_color(t_scene *scene)
{
	color_int_to_rgb(BAKGROUND_COLOR, scene->obj[0][0]->color);
	scene->obj[0][0]->color->r = int_to_float(scene->obj[0][0]->color->r);
	scene->obj[0][0]->color->g = int_to_float(scene->obj[0][0]->color->g);
	scene->obj[0][0]->color->b = int_to_float(scene->obj[0][0]->color->b);
	scalar_mult_color(scene->lux[0][0]->color, scene->lux[0][0]->ratio);
}
