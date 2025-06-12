/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 23:27:45 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 23:42:05 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_each_lux(t_light *lux)
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

void	free_lux_cph(t_scene *scene)
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
	free(scene->lux[0]);
	scene->lux[0] = NULL;
	b = 0;
	while (b < scene->nb_lights)
	{
		if (scene->lux[1][b])
		{
			free_each_lux(scene->lux[1][b]);
			free(scene->lux[1][b]);
			scene->lux[1][b] = NULL;
		}	
		b++;
	}
	free(scene->lux[1]);
	scene->lux[1] = NULL;
}
