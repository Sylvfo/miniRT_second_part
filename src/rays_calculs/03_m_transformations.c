/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_m_transformations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:01:13 by syl               #+#    #+#             */
/*   Updated: 2025/05/25 16:47:55 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//normalement ok
void	apply_transformation(t_pix *pix,t_obj *obj, t_mem *memory_shuttle)
{
	matrix_point_multiplication_new(memory_shuttle->r_origin_m,
		obj->m_inv, pix->r_origin);
	matrix_point_multiplication_new(memory_shuttle->r_dir_m,
				obj->m_inv, pix->r_dir);
}

/*
Normalement plus besoin
void	apply_transformation(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			apply_transformation_obj(pix[x][y]);
			y++;
		}
		x++;
	}
}*/

//ok =)
void	set_transformation_obj(t_obj *obj)
{
	translation_matrix_coord(obj);
	matrix_mult_2(obj->m_transf, obj->m_transl);
	if (obj->type == PLAN || obj->type == CYLINDER)
	{
		rotation_from_vector(obj);
		matrix_mult_2(obj->m_transf, obj->m_rot);
	}
	if (obj->type == SPHERE || obj->type == CYLINDER)
	{
		scaling_matrix_coord(obj);
		matrix_mult_2(obj->m_transf, obj->m_scale);
	}
	inverse_matrix_44(obj->m_inv, obj->m_transf);
}

// ok =)
void	set_transformation(t_obj ***obj)
{
	int	a;
	int	b;

	a = 1;
	while (obj[a] != NULL)
	{
		b = 0;
		while (obj[a][b] != NULL)
		{
			set_transformation_obj(obj[a][b]);
			b++;
		}
		a++;
	}
}

// ok =) enventuellement retirer
void	matrix_transformations(t_pix ***pix)
{
	set_transformation(pix[0][0]->obj);
//	apply_transformation(pix);
}
