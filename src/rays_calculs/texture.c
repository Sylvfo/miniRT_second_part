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

t_color	ft_endian(t_image *img, unsigned char *index)
{
	t_color	color;

	if (img->endian == 0)
	{
		color.b = (float)index[0] / 255.0;
		color.g = (float)index[1] / 255.0;
		color.r = (float)index[2] / 255.0;
	}
	else
	{
		color.r = (float)index[0] / 255.0;
		color.g = (float)index[1] / 255.0;
		color.b = (float)index[2] / 255.0;
	}
	color.rgb = 1;
	return (color);
}

t_color	texture(t_image *img, float u, float v)
{
	int				x;
	int				y;
	t_color			color;
	unsigned char	*index;

	color = (t_color){0, 0, 0, 1};
	u = fmod(fabs(u), 1.0);
	v = fmod(fabs(v), 1.0);
	x = (int)(u * img->w);
	y = (int)(v * img->h);
	if (0 <= x && x < img->w && 0 <= y && y < img->h)
	{
		index = (unsigned char *)img->addr + y * img->line_length + \
x * (img->bits_per_pixel / 8);
		color = ft_endian(img, index);
	}
	return (color);
}

t_color	texture_cylcone(t_coord p_local, t_scene *scene, t_mem *mem)
{
	t_color	color;
	float	size[2];
	float	u;
	float	v;

	size[0] = -scene->obj[mem->obj_a][mem->obj_b]->height / 2;
	size[1] = size[0] *(-1);
	u = atan2(p_local.z, p_local.x) / (2 * PI);
	v = (p_local.y - size[0]) / (size[1] - size[0]);
	color = texture (&scene->obj[mem->obj_a][mem->obj_b]->bump, u, v);
	return (color);
}

t_color	texture_sphere(t_coord p_local, t_scene *scene, t_mem *mem)
{
	t_color	color;
	float	r;
	float	u;
	float	v;

	r = length_vector(&p_local);
	u = atan2(p_local.z, p_local.x) / (2 * PI);
	if (u < 0.0)
	{
		u += 1.0;
	}
	v = acos(p_local.y) / ((r + 1e-6) * PI);
	color = texture (&scene->obj[mem->obj_a][mem->obj_b]->bump, u, v);
	return (color);
}

t_color	texture_shape(t_scene *scene, t_mem *mem, t_coord hitpoint)
{
	t_coord	p_local;
	t_obj	*obj;

	obj = scene->obj[mem->obj_a][mem->obj_b];
	substraction_p_to_v_na(&hitpoint, &hitpoint, obj->p_coord);
	matrix_point_multiplication_new(&p_local, obj->m_inv, &hitpoint);
	if (mem->obj_a == SPHERE)
	{
		return (texture_sphere(p_local, scene, mem));
	}
	else if (mem->obj_a == CYLINDER || mem->obj_a == CONE)
	{
		return (texture_cylcone(p_local, scene, mem));
	}
	return ((t_color){1, 1, 1, 1});
}
