/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:30:46 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/29 16:49:36 by syl              ###   ########.fr       */
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
	// PF ici je fais deja une alloc afin de pouvoir enregistrer
	// combien il y a de spheres, plans et cylindre lors de 
	// la premiere lecture
	scene = init_first_scene_memory();
	if (!scene)
		return (1);
	// PF A faire cette fonction est pour checker si le fichier .rt
	// est conforme. Pense juste au fait que pour la partie
	// obligatoire on est sense pouvoir entrer des lumieres sans
	// couleurs
/*	if (check_file(scene, argc, argv[1]) == false)
	{
		free(scene);
		printf("problem with file in cph \n");
		scene = NULL;
		return (1);
	}*/

	printf("ok check file \n");
	//PF ici normalement ca devrait marcher...
	// c est tous les mallocs pour les objets. 
	// Mais pas tout a ete bien fait. 
	// Si tu as le temps tu peux mettre de lordre
	// le seul probleme c est les boucles while sur tous les objets
	if (init_scene_memory(scene) == false)
	{
		free(scene);
		scene = NULL;
		printf("problem with scene memory allocation \n");
		return (1);
	}
	printf("scene allocated \n");
	//PF ici normalement ca devrait marcher...
	// c est tous les mallocs pour pixels. 
	// Pareil c est un peu le chaos. Mais je pourrais voir moi plus tard
	pix = init_memory_main();
	memory_shuttle = init_memory_shuttle();
	//PF ici il faut recreer une fonction qui relit le fichier
	// et qui enregistre dans la structure scene
	// prevoit deja qu on va surement ajouter d autres objets dans les bonus
	// et eventuellement d autres petites choses comme la taille de la fenetre
	// un mode preview, etcc... on verra plus tard. Mais il y aura des petits trucs 
	// a rajouter
	pix = init_memory_main();
	//save datas(scene, argv[1]);
	//PF no_parsing a effacer une fois que le programme prendra le fichier.rt
	no_parsing(scene);//pour les testes de Sylvie
	//PF important! Il y a des donnees a modifier avant de lancer le programme
	// Je pense il faut pas y toucher pour l instant...
	base_data2(scene);
	printf("memory allocated \n");
	raytracing(pix, scene, memory_shuttle);
	printf("after raytracing \n");
	pix_to_window(pix, scene);
	image_hooks(scene);
	free_main(pix, scene, memory_shuttle);
	return (EXIT_SUCCESS);
}

