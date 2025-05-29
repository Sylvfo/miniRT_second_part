/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_m_transformations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:01:13 by syl               #+#    #+#             */
/*   Updated: 2025/05/29 16:44:06 by syl              ###   ########.fr       */
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

//ok =)
void	set_transformation_obj(t_obj *obj)
{
	translation_matrix_coord(obj);
	matrix_mult_2(obj->m_transf, obj->m_transl);
	printf("m_transf 1");
		print_matrix_44(obj->m_transf);
	if (obj->type == PLAN || obj->type == CYLINDER)
	{
		rotation_from_vector(obj);
		matrix_mult_2(obj->m_transf, obj->m_rot);
		printf("m_rot");
		print_matrix_44(obj->m_rot);
	}
	if (obj->type == SPHERE || obj->type == CYLINDER)
	{
		scaling_matrix_coord(obj);
		matrix_mult_2(obj->m_transf, obj->m_scale);
	}
	inverse_matrix_44(obj->m_inv, obj->m_transf);
	printf("obj->m_inv");
	print_matrix_44(obj->m_inv);
}

//PF ici ok avec les boucles d objets??? A verifier
void	matrix_transformations(t_obj ***obj)
{
	int	a;
	int	b;
	printf("obj height %.3f \n", obj[3][0]->height);
	a = 0;
	while (a < 4) //(obj[a] != NULL)
	{
		b = 0;
		while (b < 1)//(obj[a][b] != NULL)
		{
			printf("obj num %i, type %i \n", a, obj[a][b]->type);
			set_transformation_obj(obj[a][b]);
			b++;
		}
		a++;
	}
}
