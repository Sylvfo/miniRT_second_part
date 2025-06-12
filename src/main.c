/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:30:46 by cmegret           #+#    #+#             */
/*   Updated: 2025/06/12 10:09:28 by syl              ###   ########.fr       */
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
	printf("\ncamera: fov %.2f| coord %.2f %.2f %.2f",scene->cam->fov, scene->cam->p_coord->x,scene->cam->p_coord->y,scene->cam->p_coord->z);

	/*printf("\nratio %.2f %.2f", scene->lux[0][0]->ratio, scene->lux[1][0]->ratio);
	printf("\ncamera: fov %.2f| coord %.2f %.2f %.2f",scene->cam->fov, scene->cam->p_coord->x,scene->cam->p_coord->y,scene->cam->p_coord->z);
	printf("\n\nsphere: nb : %d | coord %.2f %.2f %.2f | diam %.2f | couleur %.0f %.0f %.0f",scene->nb_sphere,scene->obj[1][0]->p_coord->x,scene->obj[1][0]->p_coord->y,scene->obj[1][0]->p_coord->z,scene->obj[1][0]->diam ,scene->obj[1][0]->color->r,scene->obj[1][0]->color->g,scene->obj[1][0]->color->b);
	printf("\nsphere: coord %.2f %.2f %.2f | diam %.2f | couleur %.0f %.0f %.0f",scene->obj[1][1]->p_coord->x,scene->obj[1][1]->p_coord->y,scene->obj[1][1]->p_coord->z,scene->obj[1][1]->diam ,scene->obj[1][1]->color->r,scene->obj[1][1]->color->g,scene->obj[1][1]->color->b);
	printf("\n\nplan: nb : %d | coord %.2f %.2f %.2f | axe %.2f %.2f %2.f| couleur %.0f %.0f %.0f",scene->nb_plan,scene->obj[2][0]->p_coord->x,scene->obj[2][0]->p_coord->y,scene->obj[2][0]->p_coord->z,scene->obj[2][0]->v_axe->x,scene->obj[2][0]->v_axe->y,scene->obj[2][0]->v_axe->z ,scene->obj[2][0]->color->r,scene->obj[2][0]->color->g,scene->obj[2][0]->color->b);
	printf("\nplan: coord %.2f %.2f %.2f | axe %.2f %.2f %2.f| couleur %.0f %.0f %.0f",scene->obj[2][1]->p_coord->x,scene->obj[2][1]->p_coord->y,scene->obj[2][1]->p_coord->z,scene->obj[2][1]->v_axe->x,scene->obj[2][1]->v_axe->y,scene->obj[2][1]->v_axe->z,scene->obj[2][1]->color->r,scene->obj[2][1]->color->g,scene->obj[2][1]->color->b);
	printf("\n\ncyl: nb : %d | coord %.2f %.2f %.2f | diam %.2f | couleur %.0f %.0f %.0f",scene->nb_cylinder,scene->obj[3][0]->p_coord->x,scene->obj[3][0]->p_coord->y,scene->obj[3][0]->p_coord->z,scene->obj[3][0]->diam ,scene->obj[3][0]->color->r,scene->obj[3][0]->color->g,scene->obj[3][0]->color->b);
	printf("\ncyl: coord %.2f %.2f %.2f | diam %.2f | couleur %.0f %.0f %.0f",scene->obj[3][1]->p_coord->x,scene->obj[3][1]->p_coord->y,scene->obj[3][1]->p_coord->z,scene->obj[3][1]->diam ,scene->obj[3][1]->color->r,scene->obj[3][1]->color->g,scene->obj[3][1]->color->b);
	printf("\n\nlight: nb : %d | coord %.2f %.2f %.2f | ratio %.2f | couleur %.0f %.0f %.0f",scene->nb_lights,scene->lux[1][0]->p_coord->x,scene->lux[1][0]->p_coord->y,scene->lux[1][0]->p_coord->z,scene->lux[1][0]->ratio ,scene->lux[1][0]->color->r,scene->lux[1][0]->color->g,scene->lux[1][0]->color->b);
	printf("\nlight: coord %.2f %.2f %.2f | ratio %.2f | couleur %.0f %.0f %.0f\n",scene->lux[1][1]->p_coord->x,scene->lux[1][1]->p_coord->y,scene->lux[1][1]->p_coord->z,scene->lux[1][1]->ratio ,scene->lux[1][1]->color->r,scene->lux[1][1]->color->g,scene->lux[1][1]->color->b);
	*/
	base_data2(scene, pix);
	raytracing(pix, scene, memory_shuttle);
	pix_to_window(pix, scene);
	if (scene->bonus_mode == false)
		image_hooks(scene);
	if (scene->bonus_mode == true)
		image_hooks_bonus(scene);
	printf("end programme\n");
	scene->pix = NULL;
	scene->mem_shuttle = NULL;
	free_main(pix, scene, memory_shuttle);
	return (EXIT_SUCCESS);
}
