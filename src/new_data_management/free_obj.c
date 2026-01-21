/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 23:08:57 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 23:10:45 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_each_obj(t_obj *obj)
{
	if (!obj)
		return ;
	free_each_obj_coord(obj);
	free_each_obj_matrix(obj);
	if (obj->color)
	{
		free(obj->color);
		obj->color = NULL;
	}
}

void	free_each_obj_suite(t_obj *obj)
{
	if (obj->tr_p2)
	{
		free(obj->tr_p2);
		obj->tr_p2 = NULL;
	}
	if (obj->tr_p3)
	{
		free(obj->tr_p3);
		obj->tr_p3 = NULL;
	}
	if (obj->v_axe)
	{
		free(obj->v_axe);
		obj->v_axe = NULL;
	}
	if (obj->v_axe_r)
	{
		free(obj->v_axe_r);
		obj->v_axe_r = NULL;
	}
}

void	free_each_obj_suite2(t_obj *obj)
{
	if (obj->tr_e2)
	{
		free(obj->tr_e2);
		obj->tr_e2 = NULL;
	}
	if (obj->tr_p1)
	{
		free(obj->tr_p1);
		obj->tr_p1 = NULL;
	}
	if (obj->v_sph_camera)
	{
		free(obj->v_sph_camera);
		obj->v_sph_camera = NULL;
	}
	if (obj->from)
	{
		free(obj->from);
		obj->from = NULL;
	}
}

void	free_each_obj_coord(t_obj *obj)
{
	if (obj->p_coord)
	{
		free(obj->p_coord);
		obj->p_coord = NULL;
	}
	if (obj->normal)
	{
		free(obj->normal);
		obj->normal = NULL;
	}
	if (obj->tr_e1)
	{
		free(obj->tr_e1);
		obj->tr_e1 = NULL;
	}
	free_each_obj_suite(obj);
	free_each_obj_suite2(obj);
}

void	free_obj(t_obj ***obj, int a, int nb)
{
	int	b;

	b = 0;
	while (b < nb)
	{
		free_each_obj(obj[a][b]);
		if (obj[a][b]->bump.img)
		{
			mlx_destroy_image(obj[a][b]->bump.mlx_ptr, obj[a][b]->bump.img);
		}
		free(obj[a][b]);
		obj[a][b] = NULL;
		b++;
	}
	free(obj[a]);
	obj[a] = NULL;
}
