/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_raytracing_main_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:34:56 by syl               #+#    #+#             */
/*   Updated: 2025/10/05 18:15:33 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"


		
// arg = mem shut?
void* routine(void *arg)
{
	while(((t_glob *)arg)->pix_y < WND_HEIGHT)
	{
		//choose mem_shuttle
		clean_memory_shuttle(((t_glob *)arg));
		init_viewport_x_y(((t_glob *)arg), ((t_glob *)arg)->scene->cam, ((t_glob *)arg)->pix_x, ((t_glob *)arg)->pix_y);
		init_camera_pix_ray(((t_glob *)arg), ((t_glob *)arg)->scene->cam);
		*((t_glob *)arg)->pix[((t_glob *)arg)->pix_x][((t_glob *)arg)->pix_y]->color = raytracer_bonus(((t_glob *)arg)->pix[((t_glob *)arg)->pix_x][((t_glob *)arg)->pix_y],
			((t_glob *)arg)->scene, ((t_glob *)arg));
		pthread_mutex_lock(&((t_glob *)arg)->scene->mutex_x);
		pthread_mutex_lock(&((t_glob *)arg)->scene->mutex_y);
		((t_glob *)arg)->scene->x_thread += 1;
		if (((t_glob *)arg)->scene->x_thread >= WND_WIDTH)
		{
			((t_glob *)arg)->scene->x_thread = 0;
			((t_glob *)arg)->scene->y_thread += 1;
		}
		((t_glob *)arg)->pix_x = ((t_glob *)arg)->scene->x_thread;
		((t_glob *)arg)->pix_y = ((t_glob *)arg)->scene->y_thread;
		pthread_mutex_unlock(&((t_glob *)arg)->scene->mutex_x);
		pthread_mutex_unlock(&((t_glob *)arg)->scene->mutex_y);
	}
}

//raytracing_main_bonus
void	raytracing_main_bonus(t_pix ***pix, t_scene *scene, t_mem **m_mem_shuttle)
{
	int	x;
	int	y;
	int i;
	pthread_t	th[24];
	t_glob	*args_multithreading;

	args_multithreading = malloc(24 * sizeof(t_glob));
	i = 0;
	while (i < 24)
	{
		args_multithreading[i].mem_shuttle = m_mem_shuttle[i];
		i++;
	}

	//mettre un truc recalculate??
	constructing_camera(scene);
	matrix_transformations(scene->obj);

	//init scene for threads
	scene->x_thread = 23;
	scene->y_thread = 0;
	
	pthread_mutex_init(&scene->mutex_x, NULL);
	pthread_mutex_init(&scene->mutex_y, NULL);

	
	for (i = 0; i < 24; i++)
	{
		if (pthread_create(&th[i], NULL, &routine, args_multithreading[i]) != 0)
		{
			perror("Failed to create thread\n");
			return;
		}
		printf("Thread %d has started \n", i);
	}

	//pthread join
	for (i = 0; i < 24; i++)
	{
		// it is in the order we tell them to appear, not in the order they finish execution...
		if (pthread_join(th[i], NULL) != 0)
			return (3);
		printf("Thread %d has finished execution \n", i);
	}
	pthread_mutex_destroy(&scene->mutex_x);
	pthread_mutex_destroy(&scene->mutex_y);
}

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
			init_viewport_x_y(mem_shuttle, scene->cam, x, y);
			init_camera_pix_ray(mem_shuttle, scene->cam);
			*(pix[x][y]->color) = raytracer_bonus(pix[x][y],
					scene, mem_shuttle);
			y++;
		}
		x++;
	}
	return ;
}

t_color	raytracer_bonus(t_pix *pix, t_scene *scene, t_mem *mem_shtle)
{
	t_color	color_light;
	t_color	color;

	main_intersections(scene->obj, mem_shtle);
	copy_matrix_44(mem_shtle->obj_inv,
		scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->m_inv);
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
	//ici voir pour récursion, réfléxion, réfraction, transparence...
	if (scene->obj[mem_shtle->obj_a][mem_shtle->obj_b]->mirror > 0.0)
	{
		color_light = base_reflection(scene, mem_shtle, color_light);
	}
	return (color_light);
}



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
/*	while (x < WND_WIDTH)
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