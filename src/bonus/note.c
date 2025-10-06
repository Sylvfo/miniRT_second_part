#include "../inc/minirt.h"

// arg = mem shut?
void* routine(void *arg)
{
	int x;
	int y;
	printf("enter routine\n");

	x = ((t_glob *)arg)->mem_shuttle->pix_x;
	y = ((t_glob *)arg)->mem_shuttle->pix_y;

		printf("enter loop\n");

		pthread_mutex_lock(&((t_glob *)arg)->scene->mutex_x);
		printf("mutex locked\n");
		pthread_mutex_unlock(&((t_glob *)arg)->scene->mutex_x);
		printf("x = %d \n", x);
		x = ((t_glob *)arg)->mem_shuttle->pix_x;
		y = ((t_glob *)arg)->mem_shuttle->pix_y;

	return (0);
}

//raytracing_main_bonus
void	raytracing_main_bonus(t_pix ***pix, t_scene *scene, t_mem **m_mem_shuttle)
{
	//int	x;
//	int	y;
	int i;
	pthread_t	th[24];
	t_glob	**args_multithreading;

	(void) pix;
	(void) scene;
	printf("first hiere A \n");
	args_multithreading = malloc(24 * sizeof(t_glob*));
	i = 0;
	while (i < 24)
	{
		args_multithreading[i] = malloc(24 * sizeof(t_glob));
		args_multithreading[i]->mem_shuttle = m_mem_shuttle[i];

		i++;
	}
	printf("first hiere \n");

	//mettre un truc recalculate??
	constructing_camera(scene);
	matrix_transformations(scene->obj);
	printf("first hiere B\n");
	//init scene for threads
	scene->x_thread = 23;
	scene->y_thread = 0;
	printf("first hiere C\n");
	
	pthread_mutex_init(&scene->mutex_x, NULL);
	pthread_mutex_init(&scene->mutex_y, NULL);
	printf("first hiere D\n");
	for (i = 0; i < 24; i++)
	{
		if (pthread_create(&th[i], NULL, &routine, args_multithreading[i]) != 0)
		{
			perror("Failed to create thread\n");
			return;
		}
		printf("Thread %d has started \n", i);
	}
	printf("first hiere E\n");
	//pthread join
	for (i = 0; i < 24; i++)
	{
		// it is in the order we tell them to appear, not in the order they finish execution...
		if (pthread_join(th[i], NULL) != 0)
			return ;
		printf("Thread %d has finished execution \n", i);
	}
	pthread_mutex_destroy(&scene->mutex_x);
	pthread_mutex_destroy(&scene->mutex_y);
}

typedef struct s_scene
{
	int			x_thread;
	int			y_thread;
	pthread_mutex_t mutex_x;
	pthread_mutex_t mutex_y;
}	t_scene;