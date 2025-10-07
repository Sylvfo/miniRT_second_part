/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:24:48 by syl               #+#    #+#             */
/*   Updated: 2025/10/07 20:34:43 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	image_hooks(t_scene *scene)
{
	mlx_hook(scene->ima->mlx_win, 2, 1L << 0, ft_keys, scene);
	mlx_hook(scene->ima->mlx_win, 17, 0, ft_exit, scene);
	mlx_loop(scene->ima->mlx_ptr);
}

void	image_hooks_bonus(t_glob **data)
{
	mlx_hook(data[0]->scene->ima->mlx_win, 17, 0, ft_exit, data[0]->scene);
	mlx_hook(data[0]->scene->ima->mlx_win, 2, 1L << 0, ft_keys_bonus, data);
	mlx_mouse_hook(data[0]->scene->ima->mlx_win, mouse_click, data);
	mlx_loop(data[0]->scene->ima->mlx_ptr);
}
