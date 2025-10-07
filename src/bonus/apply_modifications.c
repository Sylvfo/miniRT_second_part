/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_modifications.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:19:21 by syl               #+#    #+#             */
/*   Updated: 2025/10/07 20:35:51 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	apply_transformations(t_glob **datas)
{
	if (datas[0]->scene->draw_type == MOVE)
		apply_move_changes(datas[0]->scene);
	else if (datas[0]->scene->draw_type == ROTATE)
		apply_rotate_changes(datas[0]->scene);
	else if (datas[0]->scene->draw_type == SCALE)
		apply_scale_changes(datas[0]->scene);
	print_modif(datas[0]->scene);
	raytracer_threads(datas);
	pix_to_window(datas[0]->scene->pix, datas[0]->scene);
}

void	apply_move_changes(t_scene *scene)
{
	int	obj_type;
	int	obj_num;

	obj_type = scene->pix[scene->x][scene->y]->obj_a;
	obj_num = scene->pix[scene->x][scene->y]->obj_b;
	moving_matrix(scene, scene->obj[obj_type][obj_num]);
	matrix_mult_2(scene->obj[obj_type][obj_num]->m_transf,
		scene->obj[obj_type][obj_num]->m_transl);
	re_identity_matrix(scene->obj[obj_type][obj_num]->m_inv);
	inverse_matrix_44(scene->obj[obj_type][obj_num]->m_inv,
		scene->obj[obj_type][obj_num]->m_transf);
}

void	apply_rotate_changes(t_scene *scene)
{
	int	obj_type;
	int	obj_num;

	obj_type = scene->pix[scene->x][scene->y]->obj_a;
	obj_num = scene->pix[scene->x][scene->y]->obj_b;
	rotating_matrix(scene, scene->obj[obj_type][obj_num]);
	matrix_mult_2(scene->obj[obj_type][obj_num]->m_transf,
		scene->obj[obj_type][obj_num]->m_rot);
	re_identity_matrix(scene->obj[obj_type][obj_num]->m_inv);
	inverse_matrix_44(scene->obj[obj_type][obj_num]->m_inv,
		scene->obj[obj_type][obj_num]->m_transf);
}

void	apply_scale_changes(t_scene *scene)
{
	int	obj_type;
	int	obj_num;

	obj_type = scene->pix[scene->x][scene->y]->obj_a;
	obj_num = scene->pix[scene->x][scene->y]->obj_b;
	scaling_matrix(scene, scene->obj[obj_type][obj_num]);
	matrix_mult_2(scene->obj[obj_type][obj_num]->m_transf,
		scene->obj[obj_type][obj_num]->m_scale);
	re_identity_matrix(scene->obj[obj_type][obj_num]->m_inv);
	inverse_matrix_44(scene->obj[obj_type][obj_num]->m_inv,
		scene->obj[obj_type][obj_num]->m_transf);
}
