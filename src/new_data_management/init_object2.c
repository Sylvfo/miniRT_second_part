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

//	rajoute cone
bool	init_cone(t_scene *scene)
{
	int	i;

	scene->obj[4] = NULL;
	if (scene->nb_cone == 0)
		return (true);
	i = 0;
	scene->obj[4] = malloc(sizeof(t_obj *) * (scene->nb_cone));
	while (i < scene->nb_cone)
	{
		scene->obj[4][i] = malloc(sizeof(t_obj));
		if (!scene->obj[4][i])
			return (false);
		if (init_each_obj(scene->obj[4][i]) == false)
			return (false);
		scene->obj[4][i]->number = scene->nb_cone;
		i++;
	}
	return (true);
}

//rajoute triangle
bool	init_triangle(t_scene *scene)
{
	int	i;

	scene->obj[5] = NULL;
	if (scene->nb_triangle == 0)
		return (true);
	i = 0;
	scene->obj[5] = malloc(sizeof(t_obj *) * (scene->nb_triangle));
	while (i < scene->nb_triangle)
	{
		scene->obj[5][i] = malloc(sizeof(t_obj));
		if (!scene->obj[5][i])
			return (false);
		if (init_each_obj(scene->obj[5][i]) == false)
			return (false);
		scene->obj[5][i]->number = scene->nb_triangle;
		i++;
	}
	return (true);
}
