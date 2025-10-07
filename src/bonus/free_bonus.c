/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:13:09 by syl               #+#    #+#             */
/*   Updated: 2025/10/07 16:37:58 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_main_bonus(t_pix ***pix, t_scene *scene, t_mem **multi_mem_shuttle)
{	
	pthread_mutex_destroy(&scene->mutex_x);
	pthread_mutex_destroy(&scene->mutex_y);
	if (scene)
	{
		scene->pix = NULL;
		scene->mem_shuttle = NULL;
		free_scene(scene);
	}
	scene = NULL;
	free_pix_struct(pix, WND_WIDTH, WND_HEIGHT);
	free_pix_array(pix, WND_WIDTH, WND_HEIGHT);
	if (multi_mem_shuttle != NULL)
	{
		free_multi_memory_shuttle(multi_mem_shuttle);
		free(multi_mem_shuttle);
		multi_mem_shuttle = NULL;
	}
}

void free_multi_memory_shuttle(t_mem **multi_mem_shuttle)
{
	int i;

	i = 0;
	while(i < NB_THREADS)
	{
		free_memory_shuttle(multi_mem_shuttle[i]);
		free(multi_mem_shuttle[i]);
		multi_mem_shuttle[i] = NULL;
		i++;
	}
}

void free_data(t_glob **datas)
{
	int i;

	if (!datas)
		return;
	i = 0;
	while (i < NB_THREADS)
	{
		free(datas[i]);
		datas[i] = NULL;
		i++;
	}
	free(datas);
	datas = NULL;
}