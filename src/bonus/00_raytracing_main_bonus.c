/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_raytracing_main_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:34:56 by syl               #+#    #+#             */
/*   Updated: 2025/10/08 11:42:07 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	raytracing_main_bonus(t_glob **datas)
{
	struct timeval	chrono;

	gettimeofday(&chrono, NULL);
	constructing_camera(datas[0]->scene);
	matrix_transformations(datas[0]->scene->obj);// pas dans threads....
	raytracer_threads(datas);
	get_timestamp(chrono);
}

void	raytracer_threads(t_glob **datas)
{
	int			i;
	pthread_t	threads[NB_THREADS];

	reset_recursivity_level(datas);
	i = 0;
	while (i < NB_THREADS)
	{
		if (pthread_create(&threads[i], NULL, &routine, datas[i]) != 0)
			return ;
		i++;
	}
	i = 0;
	while (i < NB_THREADS)
	{
		if (pthread_join(threads[i], NULL) != 0)
			return ;
		i++;
	}
}

void	*routine(void *arg)
{
	int		x;
	int		y;
	t_glob	*datas;

	datas = (t_glob *)arg;
	x = datas->mem_shuttle->pix_x;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			clean_memory_shuttle(datas->mem_shuttle);
			datas->mem_shuttle->recursivity_level = 0;
			init_viewport_x_y(datas->mem_shuttle, datas->scene->cam, x, y);
			init_camera_pix_ray(datas->mem_shuttle, datas->scene->cam);
			*datas->pix[x][y]->color = raytracer_bonus(datas->pix[x][y],
					datas->scene, datas->mem_shuttle);
			y++;
		}
		x += NB_THREADS;
	}
	return (0);
}

////////////////////////////// RAYTRACER
//fonction très importante =)
t_color	raytracer_bonus(t_pix *pix, t_scene *scene, t_mem *mem_shtle)
{
	t_color	color_light;
	t_color	color;

	main_intersections(scene->obj, mem_shtle);
	copy_matrix_44(mem_shtle->obj_inv,
		scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->m_inv);
	if (mem_shtle->recursivity_level != 0)
		mem_shtle->prev_refraction
			= scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->indice_refract;
	if (mem_shtle->recursivity_level == 0)
		closest_obj_in_pix(pix, mem_shtle);
	if (mem_shtle->obj_a == 0)
	{
		color_light = background_color(scene->obj[0][0], scene->lux[0][0]);
		return (color_light);
	}
	if (scene->preview == true)
		return (*(scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->color));
	prepare_computation(mem_shtle, scene->obj);
	color = pattern(mem_shtle, scene);
	//color_light = lighting(scene, mem_shtle, color);
	color_light =	lighting_bonus(scene, mem_shtle, color);
	mem_shtle->recursivity_level++;
	if (mem_shtle->recursivity_level < MAX_RECURSIVITY)
		color_light = next_ray(scene, mem_shtle, color_light);
	return (color_light);
}

t_color	next_ray(t_scene *scene, t_mem *mem_shtle, t_color prev_color)
{
	t_color	next_color;
	float	transp;

	if (scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->mirror > 0.0)
		prev_color = reflexion(scene, mem_shtle, prev_color);
	transp = scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->transparence;
	if (scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->transparence > 0.0)
	{
		if (transp == 1.0)
			return (prev_color);
		if (scene->obj[mem_shtle->obj_a]
			[mem_shtle->obj_b]->indice_refract != 1.0)
			next_color = refraction(scene, mem_shtle);
		else
			next_color = transparence(scene, mem_shtle);
		next_color = scalar_mult_color2(next_color, (1.0f - transp));
		prev_color = scalar_mult_color2(prev_color, transp);
		prev_color = add_color(prev_color, next_color);
	}
	return (prev_color);
}
/*
//methode avec mutex. fonctionne. A voir si plus efficace avec transparence etc...
void* routine(void *arg)
{
	int x;
	int y;

	x = ((t_glob *)arg)->mem_shuttle->pix_x;
	y = ((t_glob *)arg)->mem_shuttle->pix_y;
	while(y < WND_HEIGHT)
	{
		clean_memory_shuttle(((t_glob *)arg)->mem_shuttle);
		init_viewport_x_y(((t_glob *)arg)->mem_shuttle, ((t_glob *)arg)->scene->cam, x, y);
		init_camera_pix_ray(((t_glob *)arg)->mem_shuttle, ((t_glob *)arg)->scene->cam);
		*(((t_glob *)arg)->pix[x][y]->color) = raytracer_bonus(((t_glob *)arg)->pix[x][y],
			((t_glob *)arg)->scene, ((t_glob *)arg)->mem_shuttle);
		pthread_mutex_lock(&((t_glob *)arg)->scene->mutex_x);
		((t_glob *)arg)->scene->x_thread += 1;
		if (((t_glob *)arg)->scene->x_thread >= WND_WIDTH)
		{
			((t_glob *)arg)->scene->x_thread = 0;
			((t_glob *)arg)->scene->y_thread += 1;
		}
		((t_glob *)arg)->mem_shuttle->pix_x = ((t_glob *)arg)->scene->x_thread;
		((t_glob *)arg)->mem_shuttle->pix_y = ((t_glob *)arg)->scene->y_thread;
		pthread_mutex_unlock(&((t_glob *)arg)->scene->mutex_x);
		x = ((t_glob *)arg)->mem_shuttle->pix_x;
		y = ((t_glob *)arg)->mem_shuttle->pix_y;
	}
	return (0);
}*/