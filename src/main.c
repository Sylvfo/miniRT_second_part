/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:30:46 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/26 09:55:59 by syl              ###   ########.fr       */
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
}

static int	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <scene_file.rt>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 3) != 0)
	{
		printf("Error: Invalid file extension. Expected .rt\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static t_program_context	*init_context(void)
{
	t_program_context	*context;

	context = malloc(sizeof(t_program_context));
	if (!context)
	{
		perror("Failed to allocate memory for program context");
		return (NULL);
	}
	ft_bzero(context, sizeof(t_program_context));
	context->num_obj = malloc(sizeof(t_num_obj));
	if (!context->num_obj)
	{
		perror("Failed to allocate memory for num_obj");
		free(context);
		return (NULL);
	}
	ft_bzero(context->num_obj, sizeof(t_num_obj));
	context->num_obj->sphere = 0;
	context->num_obj->plan = 0;
	context->num_obj->cylinder = 0;
	context->num_obj->light = 0;
	return (context);
}

static void	setup_window_context(t_program_context *context)
{
	context->width = WND_WIDTH;
	context->height = WND_HEIGHT;
	if (!init_ima(context))
	{
		perror("Failed to initialize image");
		error_exit(NULL, context);
	}
}*/

int	main(int argc, char **argv)
{
	t_pix ***pix;//ok
	t_scene *scene;
	t_mem *memory_shuttle;//ok

	pix = NULL;
	scene = NULL;
	memory_shuttle = NULL;
	scene = init_first_scene_memory();
	if (!scene)
		return (1);
	if (check_file(scene, argc, argv[1]) == false)
	{
		free(scene);
		printf("problem with file in cph \n");
		scene = NULL;
		return (1);
	}
	printf("ok check file \n");
	if (init_scene_memory(scene) == false)
	{
		free(scene);
		scene = NULL;
		printf("problem with scene memory allocation \n");
		return (1);
	}
	printf("scene allocated \n");
	pix = init_memory_main();
	memory_shuttle = init_memory_shuttle();
	//save datas(scene, argv[1]);
//	no_parsing(scene);//pour les testes de Sylvie

	printf("memory allocated \n");
//	raytracing(pix, scene, memory_shuttle);
//	pix_to_window(pix, scene);
//	image_hooks(scene);
	free_main(pix, scene, memory_shuttle);
	return (EXIT_SUCCESS);
}

