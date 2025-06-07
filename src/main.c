/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:30:46 by cmegret           #+#    #+#             */
/*   Updated: 2025/06/05 15:13:49 by syl              ###   ########.fr       */
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
	t_pix ***pix;
	t_scene *scene;
	t_mem *memory_shuttle;
	
	scene = init_first_scene_memory();
	if (!scene)
		return (1);
/*	if (check_file(scene, argc, argv[1]) == false)
	{
		free(scene);
		printf("problem with file in cph \n");
		scene = NULL;
		return (1);
	}*/
	if (init_scene_memory(scene) == false)
	{
		free(scene);
		scene = NULL;
		printf("problem with scene memory allocation \n");
		return (1);
	}
	pix = init_memory_main();
	memory_shuttle = init_memory_shuttle();
//	save datas(scene, argv[1]);
	no_parsing(scene);//pour les testes de Sylvie
	base_data2(scene, pix);
	link_scene_pix(scene, pix);
	link_scene_mem(scene, memory_shuttle);
	raytracing(pix, scene, memory_shuttle);
	pix_to_window(pix, scene);
	image_hooks(scene);
	printf("back in main. objet selected is %i//%i \n", pix[scene->x][scene->y]->obj_a, pix[scene->x][scene->y]->obj_b);

	printf("end programme\n");
	scene->pix = NULL;
	scene->mem_shuttle = NULL;
	free_main(pix, scene, memory_shuttle);
	return (EXIT_SUCCESS);
}

