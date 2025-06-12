/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:30:46 by cmegret           #+#    #+#             */
/*   Updated: 2025/06/12 18:25:01 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minirt.h"

/*
void	error_exit(const char *msg, t_program_context *context)
{
	(void) context;
	printf("%s\n", msg);
	//free_all(context);
	exit(EXIT_FAILURE);
}*/

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

void link_scene_pix(t_scene *scene, t_pix ***pix)
{
	scene->pix = pix;
}

void link_scene_mem(t_scene *scene, t_mem *memory_shuttle)
{
	scene->mem_shuttle = memory_shuttle;
}

int	main(int argc, char **argv)
{
	t_scene *scene;
	t_pix ***pix;
	t_mem *memory_shuttle;

	scene = init_first_scene_memory();
	if (!scene)
		return (1);
	if (!check_args(argc, argv))
		return (EXIT_FAILURE);
	if (!verification(argv[1], scene))
	{
		free(scene);
		return (1);
	}
	if (!init_scene_memory(scene))
	{
		free_scene(scene);
		return (1);
	}
	pix = init_memory_main();
	memory_shuttle = init_memory_shuttle();
	if (!save_data(argv[1], scene))
	{
		free_main(pix, scene, memory_shuttle);
		return (1);
	}
	base_data(scene);
	raytracing(pix, scene, memory_shuttle);
	pix_to_window(pix, scene);
	if (scene->bonus_mode == false)
		image_hooks(scene);
	if (scene->bonus_mode == true)
		image_hooks_bonus(scene);
	free_main(pix, scene, memory_shuttle);
	return (EXIT_SUCCESS);
}
