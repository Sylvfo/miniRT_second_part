/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transf_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:02:02 by syl               #+#    #+#             */
/*   Updated: 2025/06/07 15:53:50 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void re_identity_matrix(float *m_identity)
{
	init_matrix_zero(m_identity);
	matrix_fill(m_identity, 0, 0, 1);
	matrix_fill(m_identity, 1, 1, 1);
	matrix_fill(m_identity, 2, 2, 1);
	matrix_fill(m_identity, 3, 3, 1);
}

void move_object(t_obj *obj)
{
	re_identity_matrix(obj->m_transf);
	re_identity_matrix(obj->m_transl);
	re_identity_matrix(obj->m_rot);
	re_identity_matrix(obj->m_inv);
	re_identity_matrix(obj->m_scale);
	set_transformation_obj(obj);
}

