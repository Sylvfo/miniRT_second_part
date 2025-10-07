/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_raytracing_main_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:34:56 by syl               #+#    #+#             */
/*   Updated: 2025/10/07 19:29:09 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"



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

//raytracer....
void* routine(void *arg)
{
	int x;
	int y;
	t_glob *datas;

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
			*datas->pix[x][y]->color = raytracer_bonus(datas->pix[x][y], datas->scene, datas->mem_shuttle);
			y++;
		}
		x += NB_THREADS;
	}
	return (0);
}

//raytracing_main_bonus
void	raytracing_main_bonus(t_glob **datas)
{
//	struct timeval chrono;
//	gettimeofday(&chrono, NULL);
	constructing_camera(datas[0]->scene);
	matrix_transformations(datas[0]->scene->obj);
	raytracer_threads(datas);
//	get_timestamp(chrono);
}

void raytracer_threads(t_glob **datas)
{
	int i;
	pthread_t	threads[NB_THREADS];

	reset_recursivity_level(datas);
	
	i = 0;
	while (i < NB_THREADS)
	{
		if (pthread_create(&threads[i], NULL, &routine, datas[i]) != 0)
			return;
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

//fonction très importante =)
//t_color	raytracer_bonus(t_pix *pix, t_scene *scene, t_mem *mem_shtle)
t_color	raytracer_bonus(t_pix *pix, t_scene *scene, t_mem *mem_shtle)
{
	t_color	color_light;
	t_color	color;

	////////////////////////////// RAYTRACER
	main_intersections(scene->obj, mem_shtle);
	copy_matrix_44(mem_shtle->obj_inv,
		scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->m_inv);
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
	color_light = lighting(scene, mem_shtle, color);
	//////////////////////////////
	//ici voir pour récursion, réfléxion, réfraction, transparence...
	mem_shtle->recursivity_level++;
	if (mem_shtle->recursivity_level < MAX_RECURSIVITY)
		color_light = next_ray(scene, mem_shtle, color_light);
	return (color_light);
}

//a remplacer par raytracer_threads
void	raytracing_recalculate_bonus(t_pix ***pix, t_scene *scene, t_mem *mem_shuttle)
{
	int	x;
	int	y;

	x = 0;
	//ici multi threadings
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			clean_memory_shuttle(mem_shuttle);
		//	mem_shuttle->recursivity_level = 0;
			init_viewport_x_y(mem_shuttle, scene->cam, x, y);
			init_camera_pix_ray(mem_shuttle, scene->cam);
			//ici?
			*(pix[x][y]->color) = raytracer_bonus(pix[x][y],
					scene, mem_shuttle);
			y++;
		}
		x++;
	}
	return ;
}

void reset_recursivity_level(t_glob **datas)
{
	int i;

	i = 0;
	while (i < NB_THREADS)
	{
		datas[i]->mem_shuttle->recursivity_level = 0;
		datas[i]->mem_shuttle->prev_refraction = 1;
		i++;
	}
}

/*
void	raytracing_main_bonus_before(t_pix ***pix, t_scene *scene, t_mem *m_mem_shuttle)
{
	int	x;
	int	y;
	struct timeval chrono;
	gettimeofday(&chrono, NULL);

	//mettre un truc recalculate??
	constructing_camera(scene);
	matrix_transformations(scene->obj);
	x = 0;
	//ici multi threadings

	//même chose que recalculate
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			clean_memory_shuttle(m_mem_shuttle);
			init_viewport_x_y(m_mem_shuttle, scene->cam, x, y);
			init_camera_pix_ray(m_mem_shuttle, scene->cam);
			*(pix[x][y]->color) = raytracer_bonus(pix[x][y],
						scene, m_mem_shuttle);
			
			y++;
		}
		x++;
	}
	get_timestamp(chrono);
}

*/
/*
void	raytracing_main_bonus(t_pix ***pix, t_scene *scene, t_mem **m_mem_shuttle)
{
	int	x;
	int	y;

	//mettre un truc recalculate??
	constructing_camera(scene);
	matrix_transformations(scene->obj);
	x = 0;
	//ici multi threadings

	//même chose que recalculate
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			//choose mem_shuttle
			clean_memory_shuttle(m_mem_shuttle[a]);
			init_viewport_x_y(m_mem_shuttle[a], scene->cam, x, y);
			init_camera_pix_ray(m_mem_shuttle[a], scene->cam);
			*(pix[x][y]->color) = raytracer_bonus(pix[x][y],
						scene, m_mem_shuttle[a]);
			
			y++;
		}
		x++;
	}
}
*/

/*
mutex sur chaque pixel trop long
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
}

*/