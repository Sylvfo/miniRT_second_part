/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:24:48 by syl               #+#    #+#             */
/*   Updated: 2025/06/04 22:15:33 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	image_hooks(t_scene *scene)
{
	mlx_hook(scene->ima->mlx_win, 2, 1L << 0, ft_keys, scene);
	mlx_hook(scene->ima->mlx_win, 17, 0, ft_exit, scene);
	// mouse hooks for bonus...
	mlx_mouse_hook(scene->ima->mlx_win, mouse_click, scene);
	mlx_loop(scene->ima->mlx_ptr);
}

/*
void	image_hooks(t_program_context *context)
{
	mlx_hook(context->mlx_win, 2, 1L << 0, ft_keys, context);
	mlx_hook(context->mlx_win, 17, 0, ft_exit, context);
	mlx_loop(context->mlx_ptr);
}*/