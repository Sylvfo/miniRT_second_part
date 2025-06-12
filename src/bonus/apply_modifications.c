/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_modifications.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:19:21 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 16:12:30 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	apply_transformations(t_scene *scene)
{
	if (scene->draw_type == MOVE)
		apply_move_changes(scene);
	else if (scene->draw_type == ROTATE)
		apply_rotate_changes(scene);
	else if (scene->draw_type == SCALE)
		apply_scale_changes(scene);
	print_modif(scene);
	raytracing_main_bonus(scene->pix, scene, scene->mem_shuttle);
	pix_to_window(scene->pix, scene);
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
