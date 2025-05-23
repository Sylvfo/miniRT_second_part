/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:35:27 by syl               #+#    #+#             */
/*   Updated: 2025/05/23 14:52:25 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_scene(t_scene *scene)
{
	if (!scene)
		return;
	if (scene->obj)
	{
		free_obj_cph(scene);
		free(scene->obj);
		scene->obj = NULL;
	}
	
//	free_cam(scene)
}

/*
void	free_cam(t_scene *scene)
{
	if (scene->cam == NULL)
		return ;
	
}*/