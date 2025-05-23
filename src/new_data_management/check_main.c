/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:12:44 by syl               #+#    #+#             */
/*   Updated: 2025/05/23 14:13:03 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool	check_file(t_scene *scene,int argc, char *filename)
{
	if (argc != 2)
	{
		printf("Usage: Please enter filename.rt\n");
		return (false);
	}
	(void) filename;
	// a changer pc il faut prendre depuis check arg. 
	scene->nb_sphere = 3;
	scene->nb_plan = 2;
	scene->nb_cylinder = 4;
	scene->nb_lights = 2;
//	if (check_rt(argv, scene) == true)
//		return (true);
	return (true);
}