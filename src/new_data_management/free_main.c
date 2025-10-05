/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:41:40 by syl               #+#    #+#             */
/*   Updated: 2025/10/05 18:05:32 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_main(t_pix ***pix, t_scene *scene, t_mem *memory_shuttle)
{
	if (scene)
	{
		scene->pix = NULL;
		scene->mem_shuttle = NULL;
		free_scene(scene);
	}
	scene = NULL;
	free_pix_struct(pix, WND_WIDTH, WND_HEIGHT);
	free_pix_array(pix, WND_WIDTH, WND_HEIGHT);
	if (memory_shuttle)
		free_memory_shuttle(memory_shuttle);
	free(memory_shuttle);
	memory_shuttle = NULL;
}

int	free_arg(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}
