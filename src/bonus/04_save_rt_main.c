/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_save_rt_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:07:43 by syl               #+#    #+#             */
/*   Updated: 2025/10/09 16:54:25 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	write_camera(FILE *f, t_camera *c)
{
	fprintf(f, "C ");
	write_vec3(f, c->p_coord);
	fprintf(f, " ");
	write_vec3(f, c->v_axe);
	fprintf(f, " %.4f\n\n", c->fov / ANGLE_FOV);
}

void	write_objects(FILE *f, t_obj ***obj)
{
	int	a;
	int	b;

	a = 1;
	while (a < NB_OBJ)
	{
		b = 0;
		while (obj[a] && b < obj[a][0]->number)
		{
			if (a == 1)
				write_sphere(f, obj[a][b]);
			if (a == 2)
				write_plan(f, obj[a][b]);
			if (a == 3)
				write_cylinder(f, obj[a][b]);
			if (a == 4)
				write_cone(f, obj[a][b]);
			if (a == 5)
				write_triangle(f, obj[a][b]);
			b++;
		}
		a++;
	}
}

int	save_scene_to_file(t_scene *scene, const char *filename)
{
	FILE	*f;
	int		i;

	f = fopen(filename, "w");
	if (!f)
		return (perror("fopen"), 1);
	write_ambient(f, scene->lux[0][0]);
	write_camera(f, scene->cam);
	i = 0;
	while (scene->lux[1][i] != NULL)
	{
		write_light(f, scene->lux[1][i]);
		i++;
	}
	write_objects(f, scene->obj);
	fclose(f);
	return (0);
}
