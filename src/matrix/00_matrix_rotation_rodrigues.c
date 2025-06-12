/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_matrix_rotation_rodrigues.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:01:11 by syl               #+#    #+#             */
/*   Updated: 2025/05/31 10:21:39 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	rotation_from_vector(t_obj *obj)
{
	float	dot;
	float	angle;
	float	c;
	float	s;
	if (!obj || !obj->from || !obj->v_axe || !obj->v_axe_r || !obj->m_rot)
	{
		fprintf(stderr, "Error: Null pointer in rotation_from_vector\n");
		return ;
	}
	cross_product_na(obj->v_axe_r, obj->from, obj->v_axe);//ok
	dot = dot_product(obj->from, obj->v_axe);//to???
	dot = fmaxf(-1.0f, fminf(1.0f, dot));// c est quoi ca?
	angle = acos(dot); //acosf(dot);
	if (fabs(angle) < EPSILON)
		return ;
	normalize_vector_na(obj->v_axe_r);
	c = cos(angle);//ok
	s = sin(angle);//ok
	matrix_rotation_rodrigues(obj, c, s);
}

void	matrix_rotation_rodrigues(t_obj *obj, float c, float s)
{
	float	t;
	float	axe_x;
	float	axe_y;
	float	axe_z;

	axe_x = obj->v_axe_r->x;
	axe_y = obj->v_axe_r->y;
	axe_z = obj->v_axe_r->z;
	t = 1 - c;
	matrix_fill(obj->m_rot, 0, 0, (t * axe_x * axe_x + c));
	matrix_fill(obj->m_rot, 0, 1, t * axe_x * axe_y - s * axe_z);
	matrix_fill(obj->m_rot, 0, 2, t * axe_x * axe_z + s * axe_y);
	matrix_fill(obj->m_rot, 0, 3, 0);
	matrix_fill(obj->m_rot, 1, 0, t * axe_x * axe_y + s * axe_z);
	matrix_fill(obj->m_rot, 1, 1, t * axe_y * axe_y + c);
	matrix_fill(obj->m_rot, 1, 2, t * axe_y * axe_z - s * axe_x);
	matrix_fill(obj->m_rot, 1, 3, 0);
	matrix_fill(obj->m_rot, 2, 0, t * axe_x * axe_z - s * axe_y);
	matrix_fill(obj->m_rot, 2, 1, t * axe_y * axe_z + s * axe_x);
	matrix_fill(obj->m_rot, 2, 2, t * axe_z * axe_z + c);
	matrix_fill(obj->m_rot, 2, 3, 0);
	matrix_fill(obj->m_rot, 3, 0, 0);
	matrix_fill(obj->m_rot, 3, 1, 0);
	matrix_fill(obj->m_rot, 3, 2, 0);
	matrix_fill(obj->m_rot, 3, 3, 1);
}

/*
//TRES ANCIEN
void matrix_rotation_rodrigues(t_coord *axis, float angle, float *m_rot)
{
	float c;
	float s;
	float t;

	c = cos(angle);
    s = sin(angle);
    t = 1 - c;
    // Matrice 3x3 de rotation de Rodrigues + extension en 4x4
	matrix_fill(m_rot, 0, 0, t*axis->x*axis->x + c);
    matrix_fill(m_rot, 0, 1, t*axis->x*axis->y - s*axis->z);
    matrix_fill(m_rot, 0, 2, t*axis->x*axis->z + s*axis->y);
    matrix_fill(m_rot, 0, 3, 0);
    matrix_fill(m_rot, 1, 0, t*axis->x*axis->y + s*axis->z);
    matrix_fill(m_rot, 1, 1, t*axis->y*axis->y + c);
    matrix_fill(m_rot, 1, 2, t*axis->y*axis->z - s*axis->x);
    matrix_fill(m_rot, 1, 3, 0);
    matrix_fill(m_rot, 2, 0, t*axis->x*axis->z - s*axis->y);
    matrix_fill(m_rot, 2, 1, t*axis->y*axis->z + s*axis->x);
    matrix_fill(m_rot, 2, 2, t*axis->z*axis->z + c);
    matrix_fill(m_rot, 2, 3, 0);
    matrix_fill(m_rot, 3, 0, 0);
    matrix_fill(m_rot, 3, 1, 0);
    matrix_fill(m_rot, 3, 2, 0);
    matrix_fill(m_rot, 3, 3, 1);
}

//TRES ANCIEN
void rotation_from_vector(float *m_rot, t_coord *to)
{
    t_coord *axis;
    float 	angle;
	t_coord *from;
	float 	dot;

//	from = create_vector(0, 1, 0);
	axis = malloc(sizeof(t_coord));
    // Produit vectoriel pour obtenir l'axe de rotation
	axis = cross_product(from, to);
	dot = dot_product(from, to);// Produit scalaire pour obtenir l'angle
    angle = acos(dot); // angle en radians
    if (fabs(angle) < EPSILON)
		return; // Pas besoin de rotation. ce sera identity matrix...
	axis = normalize_vector(axis);
	matrix_rotation_rodrigues(axis, angle, m_rot);
	free(axis);
	free(from);
}*/