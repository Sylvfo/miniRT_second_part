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

void	write_sphere(FILE *f, t_obj *obj)
{
	fprintf(f, "sp ");
	write_vec3(f, obj->p_coord);
	fprintf(f, " %g ", obj->radius * 2);
	write_color(f, obj->color, &obj->color2);
	write_visual_effect(f, obj);
	fprintf(f, "\n");
}

void	write_plan(FILE *f, t_obj *obj)
{
	fprintf(f, "pl ");
	write_vec3(f, obj->p_coord);
	write_vec3(f, obj->v_axe);
	write_color(f, obj->color, &obj->color2);
	write_visual_effect(f, obj);
	fprintf(f, "\n");
}

void	write_cylinder(FILE *f, t_obj *obj)
{
	fprintf(f, "cy ");
	write_vec3(f, obj->p_coord);
	write_vec3(f, obj->v_axe);
	fprintf(f, " %g ", obj->radius * 2);
	fprintf(f, " %g ", obj->height * 2);
	write_color(f, obj->color, &obj->color2);
	write_visual_effect(f, obj);
	fprintf(f, "\n");
}

void	write_cone(FILE *f, t_obj *obj)
{
	fprintf(f, "co ");
	write_vec3(f, obj->p_coord);
	write_vec3(f, obj->v_axe);
	fprintf(f, " %g ", obj->radius * 2);
	fprintf(f, " %g ", obj->height * 2);
	write_color(f, obj->color, &obj->color2);
	write_visual_effect(f, obj);
	fprintf(f, "\n");
}

void	write_triangle(FILE *f, t_obj *obj)
{
	fprintf(f, "tr ");
	write_vec3(f, obj->tr_p1);
	write_vec3(f, obj->tr_p2);
	write_vec3(f, obj->tr_p3);
	write_color(f, obj->color, &obj->color2);
	write_visual_effect(f, obj);
	fprintf(f, "\n");
}
