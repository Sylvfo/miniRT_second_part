/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:30:46 by cmegret           #+#    #+#             */
/*   Updated: 2026/01/21 11:21:31 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minirt.h"

static int	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <scene_file.rt>\n", argv[0]);
		return (0);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 3) != 0)
	{
		printf("Error: Invalid file extension. Expected .rt\n");
		return (0);
	}
	return (1);
}

void	link_scene_mem(t_scene *scene, t_mem *memory_shuttle)
{
	scene->mem_shuttle = memory_shuttle;
}

int	init(t_scene *scene, t_pix ***pix, t_mem *memory_shuttle, char *str)
{
	if (!init_scene_memory(scene))
	{
		free_scene(scene);
		return (0);
	}
	if (!save_data(str, scene))
	{
		free_main(pix, scene, memory_shuttle);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_scene	*scene;
	t_pix	***pix;
	t_mem	*memory_shuttle;

	scene = init_first_scene_memory(false);
	if (!scene)
		return (1);
	if (!check_args(argc, argv) || !verification(argv[1], scene))
	{
		free(scene);
		return (1);
	}
	pix = init_memory_main();
	memory_shuttle = init_memory_shuttle();
	if (!init(scene, pix, memory_shuttle, argv[1]))
		return (1);
	base_data(scene);
	raytracing(pix, scene, memory_shuttle);
	pix_to_window(pix, scene);
	image_hooks(scene);
	free_main(pix, scene, memory_shuttle);
	return (EXIT_SUCCESS);
}
