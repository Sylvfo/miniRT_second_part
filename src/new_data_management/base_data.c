/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:58:41 by syl               #+#    #+#             */
/*   Updated: 2025/05/26 14:53:03 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// modifications a faire avec les donnes de base...
void	base_data2(t_scene *scene)
{
	scene->cam->fov = scene->cam->fov * 0.0174533;
	color_int_to_rgb(BAKGROUND_COLOR, scene->obj[0][0]->color);
	scene->obj[0][0]->color->r = int_to_float(scene->obj[0][0]->color->r);
	scene->obj[0][0]->color->g = int_to_float(scene->obj[0][0]->color->g);
	scene->obj[0][0]->color->b = int_to_float(scene->obj[0][0]->color->b);
	
 	//DIAM ETC...
}
