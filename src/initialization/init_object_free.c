/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:34:22 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/25 19:51:11 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
static void	free_obj_background(t_obj ***obj)
{
	if (obj && obj[0] && obj[0][0])
	{
		clear_obj_members(obj[0][0]);
		free_and_null((void **)&obj[0][0]);
	}
	if (obj)
		free_and_null((void **)&obj[0]);
}

static void	free_obj_spheres(t_obj ***obj, int count)
{
	if (obj && obj[1])
	{
		free_obj_array_items(obj[1], count);
		obj[1] = NULL;
	}
}

static void	free_obj_plans(t_obj ***obj, int count)
{
	if (obj && obj[2])
	{
		free_obj_array_items(obj[2], count);
		obj[2] = NULL;
	}
}

static void	free_obj_cylinders(t_obj ***obj, int count)
{
	if (obj && obj[3])
	{
		free_obj_array_items(obj[3], count);
		obj[3] = NULL;
	}
}

void	free_object(t_obj ***obj, t_num_obj *num_obj)
{
	if (!obj)
		return ;
	if (!num_obj)
	{
		free(obj);
		return ;
	}
	free_obj_background(obj);
	free_obj_spheres(obj, num_obj->sphere);
	free_obj_plans(obj, num_obj->plan);
	free_obj_cylinders(obj, num_obj->cylinder);
	free(obj);
}
*/