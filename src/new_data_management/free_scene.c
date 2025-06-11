/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:35:27 by syl               #+#    #+#             */
/*   Updated: 2025/05/31 17:12:12 by syl              ###   ########.fr       */
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
	if (scene->ima)
	{
		free_ima(scene);
		free(scene->ima);
		scene->ima = NULL;
	}
	if (scene->lux)
	{
		free_lux_cph(scene);
		free(scene->lux);
		scene->lux = NULL;		
	}
	free_cam_cph(scene);
	free(scene);
}

void	free_ima(t_scene *scene)
{
	if (!scene->ima)
		return ;
	if (scene->ima->img)
	{
		mlx_destroy_image(scene->ima->mlx_ptr, scene->ima->img);
		scene->ima->img = NULL;
	}
	if (scene->ima->mlx_win)
	{
		mlx_destroy_window(scene->ima->mlx_ptr, scene->ima->mlx_win);
		scene->ima->mlx_win = NULL;
	}
	if (scene->ima->mlx_ptr)
	{
		mlx_destroy_display(scene->ima->mlx_ptr);
		free(scene->ima->mlx_ptr);
		scene->ima->mlx_ptr = NULL;
	}
	free(scene->ima);
	scene->ima = NULL;
}