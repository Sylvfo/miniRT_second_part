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

void	write_color(FILE *f, t_color *c, t_color *c2)
{
	fprintf(f, "%i,%i,%i", float_to_byte(c->r), \
float_to_byte(c->g), float_to_byte(c->b));
	if (c2->r != 0 || c2->b != 1 || c2->g != 1)
	{
		fprintf(f, ";%i,%i,%i", float_to_byte(c2->r), \
float_to_byte(c2->g), float_to_byte(c2->b));
	}
	fprintf(f, " ");
}

void	write_vec3(FILE *f, t_coord *p)
{
	fprintf(f, "%.3f,%.3f,%.3f ", p->x, p->y, p->z);
}

void	write_visual_effect(FILE *f, t_obj *obj)
{
	if (obj->transparence < 1.0)
		fprintf(f, "tran:%.1f ", obj->transparence);
	if (obj->indice_refract < 1.0)
		fprintf(f, "ref:%.1f ", obj->indice_refract);
	if (obj->mirror != 0.0)
		fprintf(f, " mir:%.1f ", obj->mirror);
	if (obj->pattern.type != -1)
		fprintf(f, " pat:%d|%.0f ", obj->pattern.type, obj->pattern.scale);
}

void	write_ambient(FILE *f, t_light *lux)
{
	t_color	color;
	t_color	color2;

	color2 = (t_color){0, 1, 1, 0};
	fprintf(f, "A %.3f ", lux->ratio);
	color = scalar_mult_color2(*lux->color, (1 / lux->ratio));
	write_color(f, &color, &color2);
	fprintf(f, "\n\n");
}

void	write_light(FILE *f, t_light *l)
{
	t_color	color2;

	color2 = (t_color){0, 1, 1, 0};
	fprintf(f, "L ");
	write_vec3(f, l->p_coord);
	fprintf(f, " %.3f ", l->ratio);
	write_color(f, l->color, &color2);
	fprintf(f, "\n\n");
}
