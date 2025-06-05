/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transf_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:02:02 by syl               #+#    #+#             */
/*   Updated: 2025/06/05 14:34:58 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void re_identity_matrix(float *m_identity)
{
	matrix_fill(m_identity, 0, 0, 1);
	matrix_fill(m_identity, 1, 1, 1);
	matrix_fill(m_identity, 2, 2, 1);
	matrix_fill(m_identity, 3, 3, 1);
}

//on peut faire un bool si jamais....
void move_object(t_scene *scene, t_pix ***pix, t_obj ***obj)
{
	// enter size
	float moving_dist;

	moving_dist = 2;

	printf("enter in move object \n");
	printf("scene x %i y %i \n",scene->x, scene->y);

	printf("object selected %i -%i\n", pix[scene->x][scene->y]->obj_a, pix[scene->x][scene->y]->obj_b);

	obj[pix[scene->x][scene->y]->obj_a][pix[scene->x][scene->y]->obj_b]->p_coord->y = obj[pix[scene->x][scene->y]->obj_a][pix[scene->x][scene->y]->obj_b]->p_coord->y + 1;
	//pix[scene->x][scene->y]->obj_a 
//	scene->obj[]
	//scene->obj[scene->pix[scene->x][scene->y]->obj_a][scene->pix[scene->x][scene->y]->obj_b]->p_coord->x += moving_dist;
//	if ()
//	or in data base....
	re_identity_matrix(obj[pix[scene->x][scene->y]->obj_a][pix[scene->x][scene->y]->obj_b]->m_transf);
	re_identity_matrix(obj[pix[scene->x][scene->y]->obj_a][pix[scene->x][scene->y]->obj_b]->m_transl);
	re_identity_matrix(obj[pix[scene->x][scene->y]->obj_a][pix[scene->x][scene->y]->obj_b]->m_rot);
	re_identity_matrix(obj[pix[scene->x][scene->y]->obj_a][pix[scene->x][scene->y]->obj_b]->m_inv);
	re_identity_matrix(obj[pix[scene->x][scene->y]->obj_a][pix[scene->x][scene->y]->obj_b]->m_scale);
	set_transformation_obj(obj[pix[scene->x][scene->y]->obj_a][pix[scene->x][scene->y]->obj_b]);
//	put tranformation in matrix...
//	translation matrix...
//	set_transformation_obj(scene->obj[scene->pix[scene->x][scene->y]->obj_a][scene->pix[scene->x][scene->y]->obj_b]);
}

