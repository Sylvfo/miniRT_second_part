/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_modifications.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:19:21 by fatsaa-m          #+#    #+#             */
/*   Updated: 2025/11/17 20:35:51 by fatsaa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minirt.h"

//recupere le vecteur directeur
static void	axe_modified(t_coord *axe, float *m)
{
	int	i;

	i = 2;
	axe->x = m[3];
	axe->y = m[7];
	axe->z = m[11];
	print_vector(axe);
	normalize_vector_na(axe);
}

//recuper les coordonnees modifier
//avec obj->m_transf
void	recupcoord(t_coord *p, float *m)
{
	p->x = m[5];
	p->y = m[9];
	p->z = m[13];
}

void	change_axe_modified(t_obj *obj, int type)
{
	if (type == CYLINDER || type == CONE)
	{
		axe_modified(obj->v_axe, obj->m_transf);
	}
}

void	change_coord_modified(t_obj *obj, int type)
{
	if (type == PLAN || type == TRIANGLE)
	{
		return ;
	}
	recupcoord(obj->p_coord, obj->m_transf);
}
