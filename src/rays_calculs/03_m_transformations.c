/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_m_transformations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:01:13 by syl               #+#    #+#             */
/*   Updated: 2025/10/09 15:13:29 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	apply_transformation(t_obj *obj, t_mem *memory_shuttle)
{
	matrix_point_multiplication_new(memory_shuttle->r_origin_m,
		obj->m_inv, memory_shuttle->r_base_origin);
	matrix_point_multiplication_new(memory_shuttle->r_dir_m,
		obj->m_inv, memory_shuttle->r_base_dir);
}

void	set_transformation_obj(t_obj *obj)
{
	translation_matrix_coord(obj);
	matrix_mult_2(obj->m_transf, obj->m_transl);
	if (obj->type == PLAN || obj->type == CYLINDER || obj->type == CONE)
	{
		rotation_from_vector(obj);
		matrix_mult_2(obj->m_transf, obj->m_rot);
	}
	if (obj->type == SPHERE || obj->type == CYLINDER || obj->type == CONE)
	{
		scaling_matrix_coord(obj);
		matrix_mult_2(obj->m_transf, obj->m_scale);
	}
	inverse_matrix_44(obj->m_inv, obj->m_transf);
}

void	handle_img(t_scene *scene, t_obj *obj, char *path)
{
	obj->bump.img = mlx_xpm_file_to_image(scene->ima->mlx_ptr, path, \
&obj->bump.w, &obj->bump.h);
	if (!obj->bump.img)
	{
		exit(1);
	}
	obj->bump.addr = mlx_get_data_addr(obj->bump.img, \
&obj->bump.bits_per_pixel, &obj->bump.line_length, \
&obj->bump.endian);
}

void	matrix_transformations(t_obj ***obj)
{
	int	a;
	int	b;

	a = 1;
	while (a < NB_OBJ)
	{
		b = 0;
		while (obj[a] && b < obj[a][0]->number)
		{
			set_transformation_obj(obj[a][b]);
			b++;
		}
		a++;
	}
}
