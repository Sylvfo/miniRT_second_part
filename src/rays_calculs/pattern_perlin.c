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

float	fade(float t)
{
	return (t * t * t * (t * (t * 6 - 15) + 10));
}

float	grad(int hash, float x, float y)
{
	int		h;
	float	u;
	float	v;
	float	result;

	h = hash & 7;
	u = y;
	v = x;
	if (h < 4)
		u = x;
	else
		u = y;
	if (h < 2)
		v = y;
	else
		u = x;
	if ((h & 1) != 0)
		u = -u;
	if ((h & 2) != 0)
		v = -v;
	result = u + v;
	return (result);
}

void	perlin_tab(int *perm)
{
	perm[0] = 0;
	perm[1] = 7;
	perm[2] = 14;
	perm[3] = 5;
	perm[4] = 12;
	perm[5] = 3;
	perm[6] = 10;
	perm[7] = 1;
	perm[8] = 8;
	perm[9] = 15;
	perm[10] = 6;
	perm[11] = 13;
	perm[12] = 4;
	perm[13] = 11;
	perm[14] = 2;
	perm[15] = 9;
}

float	perlin_noise(float x, float y)
{
	int		perm[16];
	int		xi[2];
	float	_grad[4];
	float	lerp[2];
	float	xf[2];

	perlin_tab(perm);
	xi[0] = (int)floor(x) & 15;
	xi[1] = (int)floor(x) & 15;
	xf[0] = x - floor(x);
	xf[1] = y - floor(y);
	_grad[0] = grad(perm[(perm[xi[0]] + xi[1]) & 15], xf[0], xf[1]);
	_grad[1] = grad(perm[(perm[xi[0]] + xi[1] + 1) & 15], xf[0] - 1, xf[1]);
	_grad[2] = grad(perm[(perm[(xi[0] + 1) % 16] + xi[1]) & 15], \
xf[0], xf[1] - 1);
	_grad[3] = grad(perm[(perm[(xi[0] + 1) % 16] + xi[1] + 1) & 15], \
xf[0] - 1, xf[1] - 1);
	lerp[0] = _grad[0] + fade(xf[0]) * (_grad[2] - _grad[0]);
	lerp[1] = _grad[1] + fade(xf[0]) * (_grad[3] - _grad[1]);
	return (lerp[0] + fade(xf[1]) * (lerp[1] - lerp[0]));
}

t_color	pattern_bruit_perlin(float u, float v, t_scene *scene, t_mem *mem)
{
	float	noise;
	t_color	color;
	t_color	col[2];
	float	scale;

	scale = scene->obj[mem->obj_a][mem->obj_b]->pattern.scale;
	col[0] = *scene->obj[mem->obj_a][mem->obj_b]->color;
	col[1] = scene->obj[mem->obj_a][mem->obj_b]->color2;
	noise = perlin_noise(u * scale, v * scale);
	noise = (noise + 1.0) / 2.0;
	color = (t_color){
		col[0].r * (1.0 - noise) +col[1].r * noise,
		col[0].g * (1.0 - noise) +col[1].g * noise,
		col[0].b * (1.0 - noise) +col[1].b * noise,
		0
	};
	return (color);
}
