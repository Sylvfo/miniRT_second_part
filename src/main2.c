



int	main(int argc, char **argv)
{
	char *c;
	c = ft_itoa(getpid());
	write(1, c, 7);
	write(1, "\n", 1);
	free(c);

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
	//save datas(scene, argv[1]);
	//PF no_parsing a effacer une fois que le programme prendra le fichier.rt
	no_parsing(scene);//pour les testes de Sylvie
	//PF important! Il y a des donnees a modifier avant de lancer le programme
	// Je pense il faut pas y toucher pour l instant...
	base_data2(scene);
	raytracing(pix, scene, memory_shuttle);
	pix_to_window(pix, scene);
	image_hooks(scene);
	free_main(pix, scene, memory_shuttle);
	return (EXIT_SUCCESS);
}
