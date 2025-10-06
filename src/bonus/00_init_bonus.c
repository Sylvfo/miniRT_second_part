/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 09:45:48 by syl               #+#    #+#             */
/*   Updated: 2025/10/06 18:02:09 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	init_bonus(t_scene *scene, t_pix ***pix, t_mem **memory_shuttle, char *str)
{
	(void) pix;
	(void) memory_shuttle;
	if (!init_scene_memory(scene))
	{
		free_scene(scene);
		return (0);
	}
	if (!save_data(str, scene))
	{
		//a modifier
	//	free_main(pix, scene, memory_shuttle);
		return (0);
	}
	return (1);
}