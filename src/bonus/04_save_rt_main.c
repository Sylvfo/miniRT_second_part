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
#include <stdio.h>
#include <unistd.h>

void	write_color(FILE *f, t_color *c)
{
	fprintf(f, "%i,%i,%i", float_to_byte(c->r), float_to_byte(c->g), float_to_byte(c->b));
}

void	write_vec3(FILE *f, t_coord *p)
{
	fprintf(f, "%.3f,%.3f,%.3f", p->x, p->y, p->z);
}

void	write_ambient(FILE *f, t_light *lux)
{
	fprintf(f, "A %.3f ", lux->ratio);
	write_color(f, lux->color);
	fprintf(f, "\n\n");
}


void	write_camera(FILE *f, t_camera *c)
{
	fprintf(f, "C ");
	write_vec3(f, c->p_coord);
	fprintf(f, " ");
	write_vec3(f, c->v_axe);
	fprintf(f, " %.4f\n\n", c->fov);
}

void	write_light(FILE *f, t_light *l)
{
	fprintf(f, "L ");
	write_vec3(f, l->p_coord);
	fprintf(f, " %.3f ", l->ratio);
	write_color(f, l->color);
	fprintf(f, "\n\n");
}
/*
void	write_objects(FILE *f, t_scene *scene)
{
	int i;
	t_obj *obj;

	i = 0;
	while (i < scene->nb_objs)
	{
		obj = scene->objs[i];
		if (obj->type == SPHERE)
		{
			fprintf(f, "sp ");
			write_vec3(f, &obj->t_coord);
			fprintf(f, " %g ", obj->diam);
			write_color(f, obj->color);
			fprintf(f, "\n");
		}
		else if (obj->type == PLANE)
		{
			fprintf(f, "pl ");
			write_vec3(f, &obj->pos);
			fprintf(f, " ");
			write_vec3(f, &obj->norm);
			fprintf(f, " ");
			write_color(f, obj->color);
			fprintf(f, "\n");
		}
		else if (obj->type == CYLINDER)
		{
			fprintf(f, "cy ");
			write_vec3(f, &obj->pos);
			fprintf(f, " ");
			write_vec3(f, &obj->norm);
			fprintf(f, " %g %g ", obj->diam, obj->height);
			write_color(f, obj->color);
			fprintf(f, "\n");
		}
		i++;
	}
}*/

void write_sphere(FILE *f, t_obj *obj)
{
	fprintf(f, "sp ");
	write_vec3(f, obj->p_coord);//ca peut changer
	fprintf(f, " %g ", obj->diam);//ça peut changer
	write_color(f, obj->color);
	if (obj->transparence < 1.0)
		fprintf(f, "tran:%.1f ", obj->transparence);
	if (obj->indice_refract < 1.0)
		fprintf(f, "ref:%.1f ", obj->indice_refract);
	if (obj->mirror < 1.0)
		fprintf(f, "mir:%.1f ", obj->mirror);
	fprintf(f, "\n");
}

void write_plan(FILE *f, t_obj *obj)
{
	fprintf(f, "pl ");
	write_vec3(f, obj->p_coord);//ca peut changer
	write_vec3(f, obj->v_axe);//ca peut changer
	write_color(f, obj->color);
	if (obj->transparence < 1.0)
		fprintf(f, "tran:%.1f ", obj->transparence);
	if (obj->indice_refract < 1.0)
		fprintf(f, "ref:%.1f ", obj->indice_refract);
	if (obj->mirror < 1.0)
		fprintf(f, "mir:%.1f ", obj->mirror);
	fprintf(f, "\n");
}

void write_objects(FILE *f, t_obj ***obj)
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
				write_plan(f, obj[a][b]);;
		/*	if (a == 3)
				intersect_cylinder_bonus(obj[a][b]);
			if (a == 4)
				intersect_cone_bonus(obj[a][b]);
			if (a == 5)
				intersect_triangle_bonus(obj[a][b]);*/
			b++;
		}
		a++;
	}
}




int	save_scene_to_file(t_scene *scene, const char *filename)
{
	FILE *f;
	int i;

	f = fopen(filename, "w");
	if (!f)
		return (perror("fopen"), 1);
	write_ambient(f, scene->lux[0][0]);
	
	write_camera(f, scene->cam);
	i = 0;
	while(scene->lux[1][i] != NULL)
	{
		write_light(f, scene->lux[1][i]); // si tu as plusieurs lumières, boucle dessus
		i++;
	}
	
	
	write_objects(f, scene->obj);
	fclose(f);
	return (0);
}