/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:13:09 by syl               #+#    #+#             */
/*   Updated: 2026/01/21 16:01:31 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_bonus(t_pix ***pix, t_scene *scn, t_mem **m_mshtl, t_glob **datas)
{
	pthread_mutex_destroy(&scn->mutex_x);
	pthread_mutex_destroy(&scn->mutex_y);
	if (scn)
	{
		scn->pix = NULL;
		scn->mem_shuttle = NULL;
		free_scene(scn);
	}
	scn = NULL;
	free_pix_struct(pix, WND_WIDTH, WND_HEIGHT);
	free_pix_array(pix, WND_WIDTH, WND_HEIGHT);
	if (m_mshtl != NULL)
	{
		free_multi_memory_shuttle(m_mshtl);
		free(m_mshtl);
		m_mshtl = NULL;
	}
	free_data(datas);
}

void	free_multi_memory_shuttle(t_mem **multi_mem_shuttle)
{
	int	i;

	i = 0;
	while (i < NB_THREADS)
	{
		free_memory_shuttle(multi_mem_shuttle[i]);
		free(multi_mem_shuttle[i]);
		multi_mem_shuttle[i] = NULL;
		i++;
	}
}

void	free_data(t_glob **datas)
{
	int	i;

	if (!datas)
		return ;
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
