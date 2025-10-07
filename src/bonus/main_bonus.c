/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:30:46 by cmegret           #+#    #+#             */
/*   Updated: 2025/10/07 20:11:51 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static int	check_args(int argc, char **argv)
{
	if (NB_THREADS > WND_HEIGHT)
		return (1);
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

void	link_scene_pix(t_scene *scene, t_pix ***pix)
{
	scene->pix = pix;
}


int	main(int argc, char **argv)
{
	t_scene		*scene;
	t_pix		***pix;
	t_mem		**multi_memory_shuttle;
	t_glob		**datas;
	//pthread_t	threads[NB_THREADS];

	scene = init_first_scene_memory(true);
	if (!scene)
		return (1);
	if (!check_args(argc, argv) || !verification(argv[1], scene))
	{
		free(scene);
		return (1);
	}
	pix = init_memory_main();
	multi_memory_shuttle = init_multi_memory_shuttle();
	if (!init_bonus(scene, pix, multi_memory_shuttle, argv[1]))
		return (1);
	link_scene_pix(scene, pix);
	base_data(scene);
	datas = init_data(pix, scene, multi_memory_shuttle);
	if (!datas)
	{
		free_main_bonus(pix, scene, multi_memory_shuttle);
		return (1);
	}
	raytracing_main_bonus(datas);
	pix_to_window(pix, scene);
	printf("Image calculated \n");
	image_hooks_bonus(datas);
	free_main_bonus(pix, scene, multi_memory_shuttle);
	free_data(datas);
	return (EXIT_SUCCESS);
}
