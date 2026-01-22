/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:14:58 by syl               #+#    #+#             */
/*   Updated: 2025/05/11 21:00:00 by you             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_color	compute_pointlight(t_mem *mem_shuttle, t_light *lux)
{
	float	n_dot_l;
	float	intensity;
	t_color	color_intensity;

	intensity = 0.0f;
	substraction_p_to_v_na(mem_shuttle->v_point_to_light, lux->p_coord,
		mem_shuttle->p_touch);
	normalize_vector_na(mem_shuttle->v_point_to_light);
	n_dot_l = dot_product(mem_shuttle->v_norm_parral,
			mem_shuttle->v_point_to_light);
	if (n_dot_l > 0.0f)
		intensity = lux->ratio * n_dot_l;
	color_intensity = scalar_mult_color2(*(lux->color), intensity);
	return (color_intensity);
}

t_color	compute_specular(t_mem *mem_shtl, t_light *lux, t_coord *cam_coord)
{
	float	specular_intensity;
	float	reflect_dot_view;
	float	dot_p;
	float	power_term;
	t_color	color_intensity;

	specular_intensity = 0.0f;
	dot_p = dot_product(mem_shtl->v_norm_parral,
			mem_shtl->v_light_to_point);
	scalar_mult_na(mem_shtl->scalar, mem_shtl->v_norm_parral, 2.0f * dot_p);
	substraction_p_to_v_na(mem_shtl->reflect_dir, mem_shtl->scalar,
		mem_shtl->v_light_to_point);
	normalize_vector_na(mem_shtl->reflect_dir);
	substraction_p_to_v_na(mem_shtl->view_dir, cam_coord,
		mem_shtl->p_touch);
	normalize_vector_na(mem_shtl->view_dir);
	reflect_dot_view = dot_product(mem_shtl->reflect_dir,
			mem_shtl->view_dir);
	if (reflect_dot_view > 0.0f)
	{
		power_term = powf(reflect_dot_view, SHININESS);
		specular_intensity = lux->ratio * power_term * 0.5f;
	}
	color_intensity = scalar_mult_color2(*(lux->color), specular_intensity);
	return (color_intensity);
}
