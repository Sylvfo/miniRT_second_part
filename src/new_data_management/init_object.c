/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 23:01:38 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 23:02:31 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool	init_sphere(t_scene *scene)
{
	int	i;

	scene->obj[1] = NULL;
	if (scene->nb_sphere == 0)
		return (true);
	i = 0;
	scene->obj[1] = malloc(sizeof(t_obj *) * (scene->nb_sphere));
	if (!scene->obj[1])
		return (false);
	while (i < scene->nb_sphere)
	{
		scene->obj[1][i] = malloc(sizeof(t_obj));
		if (!scene->obj[1][i])
			return (false);
		if (init_each_obj(scene->obj[1][i]) == false)
			return (false);
		scene->obj[1][i]->number = scene->nb_sphere;
		i++;
	}
	return (true);
}

bool	init_plan(t_scene *scene)
{
	int	i;

	i = 0;
	scene->obj[2] = NULL;
	if (scene->nb_plan == 0)
		return (true);
	scene->obj[2] = malloc(sizeof(t_obj *) * (scene->nb_plan));
	while (i < scene->nb_plan)
	{
		scene->obj[2][i] = malloc(sizeof(t_obj));
		if (!scene->obj[2][i])
			return (false);
		if (init_each_obj(scene->obj[2][i]) == false)
			return (false);
		scene->obj[2][i]->number = scene->nb_plan;
		i++;
	}
	return (true);
}

bool	init_cylinder(t_scene *scene)
{
	int	i;

	scene->obj[3] = NULL;
	if (scene->nb_cylinder == 0)
		return (true);
	i = 0;
	scene->obj[3] = malloc(sizeof(t_obj *) * (scene->nb_cylinder));
	while (i < scene->nb_cylinder)
	{
		scene->obj[3][i] = malloc(sizeof(t_obj));
		if (!scene->obj[3][i])
			return (false);
		if (init_each_obj(scene->obj[3][i]) == false)
			return (false);
		scene->obj[3][i]->number = scene->nb_cylinder;
		i++;
	}
	return (true);
}

bool	init_obj_cph(t_scene *scene)
{
	scene->obj = NULL;
	scene->obj = malloc(sizeof(t_obj **) * NB_OBJ);
	if (!scene->obj)
		return (false);
	scene->obj[0] = malloc(sizeof(t_obj *) * 2);
	scene->obj[0][0] = malloc(sizeof(t_obj));
	if (!scene->obj[0][0])
		return (false);
	if (init_each_obj(scene->obj[0][0]) == false)
		return (false);
	scene->obj[0][1] = NULL;
	if (!init_sphere(scene))
		return (false);
	if (!init_plan(scene))
		return (false);
	if (!init_cylinder(scene))
		return (false);
	return (true);
}
