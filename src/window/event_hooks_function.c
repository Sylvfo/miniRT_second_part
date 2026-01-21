/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks_function.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:33:55 by cmegret           #+#    #+#             */
/*   Updated: 2025/06/12 15:34:51 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	ft_exit(t_scene *scene)
{
	mlx_loop_end(scene->ima->mlx_ptr);
	return (0);
}

int	ft_keys(int keycode, t_scene *scene)
{
	if (keycode == 65307)
	{
		printf("ESC pressed.\nWindow closed\n");
		mlx_loop_end(scene->ima->mlx_ptr);
		return (0);
	}
	return (0);
}
