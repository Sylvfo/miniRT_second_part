/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_raytracing_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:27:13 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 23:45:21 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_color	pattern_plan(float scale, t_coord hitpoint, t_scene *scene, t_mem *mem)
{
	float	dist;
	int		x;
	int		y;

	scale = 1 / scale;
	x = (int)floor(hitpoint.x / scale);
	y = (int)floor(hitpoint.y / scale);
	if (scene->obj[mem->obj_a][mem->obj_b]->pattern.type == CHECKBOARD)
		return (pattern_checkboard(x, y, scene, mem));
	else if (scene->obj[mem->obj_a][mem->obj_b]->pattern.type == STRIPES)
		return (pattern_stripes(hitpoint.x / scale, scene, mem));
	else if (scene->obj[mem->obj_a][mem->obj_b]->pattern.type == GRADIENT)
		return (pattern_gradient(hitpoint.x / scale, scene, mem));
	else if (scene->obj[mem->obj_a][mem->obj_b]->pattern.type == RINGS)
	{
		dist = sqrt(pow(hitpoint.x / scale, 2) + pow(hitpoint.y / scale, 2));
		return (pattern_rings(dist, scene, mem));
	}
	else if (scene->obj[mem->obj_a][mem->obj_b]->pattern.type == PERLIN)
		return (pattern_bruit_perlin(hitpoint.x / scale, hitpoint.y / scale, \
scene, mem));
	return (*scene->obj[mem->obj_a][mem->obj_b]->color);
}

t_color	pattern_sphere(float scale, t_coord p_local, t_scene *scene, t_mem *mem)
{
	float	v;
	float	u;
	float	distance;

	normalize_vector_na(&p_local);
	u = atan2(p_local.z, p_local.x) / (2 * PI);
	v = acos(p_local.y) / PI;
	if (scene->obj[mem->obj_a][mem->obj_b]->pattern.type == CHECKBOARD)
		return (pattern_checkboard((int)floor(u * scale), \
(int)floor(v * scale), scene, mem));
	else if (scene->obj[mem->obj_a][mem->obj_b]->pattern.type == STRIPES)
		return (pattern_stripes(u * scale, scene, mem));
	else if (scene->obj[mem->obj_a][mem->obj_b]->pattern.type == GRADIENT)
		return (pattern_gradient(u, scene, mem));
	else if (scene->obj[mem->obj_a][mem->obj_b]->pattern.type == RINGS)
	{
		distance = v * scale;
		return (pattern_rings(distance, scene, mem));
	}
	else if (scene->obj[mem->obj_a][mem->obj_b]->pattern.type == PERLIN)
		return (pattern_bruit_perlin(u * scale, v * scale, scene, mem));
	return (*scene->obj[mem->obj_a][mem->obj_b]->color);
}

t_color	pattern_cylcon(float scale, t_coord p_local, t_scene *scene, t_mem *mem)
{
	float	size[2];
	float	v;
	float	u;
	float	distance;

	size[0] = -scene->obj[mem->obj_a][mem->obj_b]->height / 2;
	size[1] = size[0] * (-1);
	u = atan2(p_local.z, p_local.x) / (2 * PI);
	v = (p_local.y - size[0]) / (size[1] - size[0]);
	if (scene->obj[mem->obj_a][mem->obj_b]->pattern.type == CHECKBOARD)
		return (pattern_checkboard((int)floor(u * scale), \
(int)floor(v * scale), scene, mem));
	else if (scene->obj[mem->obj_a][mem->obj_b]->pattern.type == STRIPES)
		return (pattern_stripes(u * scale, scene, mem));
	else if (scene->obj[mem->obj_a][mem->obj_b]->pattern.type == GRADIENT)
		return (pattern_gradient(u, scene, mem));
	else if (scene->obj[mem->obj_a][mem->obj_b]->pattern.type == RINGS)
	{
		distance = sqrt(pow(p_local.x, 2) + pow(p_local.z, 2)) * scale;
		return (pattern_rings(distance, scene, mem));
	}
	else if (scene->obj[mem->obj_a][mem->obj_b]->pattern.type == PERLIN)
		return (pattern_bruit_perlin(u * scale, v * scale, scene, mem));
	return (*scene->obj[mem->obj_a][mem->obj_b]->color);
}

t_color	pattern_shape(float scale, t_coord hitpoint, t_scene *scene, t_mem *mem)
{
	t_coord	p_local;
	t_obj	*obj;

	obj = scene->obj[mem->obj_a][mem->obj_b];
	matrix_point_multiplication_new(&p_local, obj->m_inv, &hitpoint);
	scale = obj->pattern.scale;
	if (mem->obj_a == PLAN || mem->obj_a == TRIANGLE)
		return (pattern_plan(scale, hitpoint, scene, mem));
	substraction_p_to_v_na(&hitpoint, &hitpoint, obj->p_coord);
	matrix_point_multiplication_new(&p_local, obj->m_inv, &hitpoint);
	if (mem->obj_a == CYLINDER || mem->obj_a == CONE)
		return (pattern_cylcon(scale, p_local, scene, mem));
	else if (mem->obj_a == SPHERE)
		return (pattern_sphere(scale, p_local, scene, mem));
	return (*obj->color);
}

t_color	pattern(t_mem *mem, t_scene *scene)
{
	t_coord	hitpoint;
	t_coord	c;
	float	scale;
	t_color	color;

	scale = 1;
	c = scalar_mult_ret(mem->r_base_dir, mem->closestt);
	addition_vect(&hitpoint, mem->r_base_origin, &c);
	if (scene->obj[mem->obj_a][mem->obj_b]->hastexture)
		return (texture_shape(scene, mem, hitpoint));
	if (scene->obj[mem->obj_a][mem->obj_b]->pattern.scale == 0)
		return (*scene->obj[mem->obj_a][mem->obj_b]->color);
	color = pattern_shape(scale, hitpoint, scene, mem);
	return (color);
}
