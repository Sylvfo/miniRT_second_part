/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:14:23 by syl               #+#    #+#             */
/*   Updated: 2025/05/26 10:19:42 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool init_lux_cph(t_scene *scene)
{
	int		a;
	int		b;

	scene->lux = NULL;
	scene->lux = malloc(sizeof(t_light **) * 3); // 3 pour nombre lum
	if (!scene->lux)
		return (false);
	scene->lux[0] = malloc(sizeof(t_light *) * 2);
	scene->lux[0][0] = malloc(sizeof(t_light));
	if (!scene->lux[0][0])
		return (false);
	scene->lux[0][0]->color = create_color(0.0, 0.0, 0.0);
	if (!scene->lux[0][0]->color)
		return (false);
	scene->lux[0][1] = NULL;
	// light point
	b = 0;
	scene->lux[1] = NULL;
	scene->lux[1] = malloc(sizeof(t_light *) * (scene->nb_lights));
	if (!scene->lux[1])
		return (false);
	while (b < scene->nb_lights)
	{
		scene->lux[1][b] = malloc(sizeof(t_light));
		if (!scene->lux[1][b])
			return (false);
		if (init_each_lux(scene->lux[1][b]) == false)
			return (false);
		b++;
	}
	// autres luxets... 
	//	scene->lux[5] = NULL;
	return (true);
}

//ok
void free_each_lux(t_light *lux)
{
	if (!lux)
		return ;
	if (lux->color)
	{
		free(lux->color);
		lux->color = NULL;
	}
	if (lux->p_coord)
	{
		free(lux->p_coord);
		lux->p_coord = NULL;
	}
}

bool init_each_lux(t_light *lux)
{
	if (!lux)
		return (lux);
	init_each_lux_null(lux);
	lux->ratio = -1;
	lux->p_coord = create_point(0, 0, 0);
	if (!lux->p_coord)
		return (false);
	lux->color = create_color(1.0, 1.0, 1.0);
	if (!lux->color)
		return (false);
	return (true);
}

void	init_each_lux_null(t_light *lux)
{
	lux->p_coord = NULL;
	lux->color = NULL;
}

void free_lux_cph(t_scene *scene)
{
	int b;

	if (!scene->lux)
		return ;
	if (scene->lux[0][0])
	{
		if (scene->lux[0][0]->color)
		{
			free(scene->lux[0][0]->color);
			scene->lux[0][0]->color = NULL;
		}
		free(scene->lux[0][0]);
		scene->lux[0][0] = NULL;
	}
	free(scene->lux[0]);//???
	scene->lux[0] = NULL;
	b = 0;
	while (b < scene->nb_lights)
	{
		if (scene->lux[1][b])
		{
			free_each_lux(scene->lux[1][b]);
		//free les coord...
			free(scene->lux[1][b]);
			scene->lux[1][b] = NULL;
		}	
		b++;
	}
	free(scene->lux[1]);
	scene->lux[1] = NULL;
}
