/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks_function.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:33:55 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/25 21:19:30 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	ft_exit(t_scene *scene)
{
	///!!!!!!!!!!!! EXISTE QUE VERSION LINUX....
	mlx_loop_end(scene->ima->mlx_ptr);
//	free_main(pix, scene, memory_shuttle);
//	exit(0);
	return (0);
}

int	ft_keys(int keycode, t_scene *scene)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		printf("ESC pressed.\nWindow closed\n");
		mlx_loop_end(scene->ima->mlx_ptr);
//		free_main(pix, scene, memory_shuttle);
//		exit(0);
		return (0);
	}
	return (0);
}

/*
int	ft_exit(t_pix ***pix, t_scene *scene, t_mem *memory_shuttle)
{
	free_main(pix, scene, memory_shuttle);
	exit(0);
	return (0);
}

int	ft_keys(int keycode, t_pix ***pix, t_scene *scene, t_mem *memory_shuttle)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		printf("ESC pressed.\nWindow closed\n");
		free_main(pix, scene, memory_shuttle);
		exit(0);
		return (0);
	}
	return (0);
}
*/