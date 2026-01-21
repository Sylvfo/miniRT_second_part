/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 09:45:48 by syl               #+#    #+#             */
/*   Updated: 2026/01/21 16:02:15 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	init_bonus(t_scene *scene, t_pix ***pix, t_mem **memory_shuttle, char *str)
{
	if (!init_scene_memory(scene))
	{
		free_scene(scene);
		return (0);
	}
	if (!save_data(str, scene))
	{
		free_bonus(pix, scene, memory_shuttle, NULL);
		return (0);
	}
	pthread_mutex_init(&scene->mutex_x, NULL);
	pthread_mutex_init(&scene->mutex_y, NULL);
	link_scene_pix(scene, pix);
	base_data(scene);
	return (1);
}

t_glob	**init_data(t_pix ***pix, t_scene *scene, t_mem **m_mem_shuttle)
{
	t_glob	**data;
	int		i;

	data = NULL;
	data = malloc(NB_THREADS * sizeof(t_glob *));
	if (!data)
		return (NULL);
	i = 0;
	while (i < NB_THREADS)
	{
		data[i] = malloc(NB_THREADS * sizeof(t_glob));
		if (!data[i])
		{
			clear_data(data, i);
			return (NULL);
		}
		data[i]->mem_shuttle = m_mem_shuttle[i];
		data[i]->scene = scene;
		data[i]->pix = pix;
		i++;
	}
	return (data);
}

void	clear_data(t_glob	**data, int i)
{
	i--;
	while (i > 0)
	{
		free(data[i]);
		data[i] = NULL;
		i--;
	}
}
