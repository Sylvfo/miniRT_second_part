/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:13:00 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/25 19:28:38 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	save_coordonnee(char *str, t_coord *p)
{
	char	**coord;

	coord = ft_split(str, ',');
	if (!coord)
		return (0);
	if (ft_size(coord) != NB_EL_AXE || !check_isvector(coord))
		return (free_arg(coord));
	p->x = number(coord[0]);
	p->y = number(coord[1]);
	p->z = number(coord[2]);
	free_arg(coord);
	return (1);
}

int	save_camera(char *str, t_camera *camera)
{
//	t_coord		position;
//	t_coord		orientation;
//	t_camera	*cam;
//	float		fov;

	char	**params;

	params = ft_split(str, ' ');
	if (!params)
		return (error_system());
	if (!save_coordonnee(params[1], camera->p_coord) ||	\
		!save_coordonnee(params[2], camera->v_axe))
	{
		free_arg(params);
		return (0);
	}
	camera->fov = number(params[3]);
	normalize_vector_na(camera->v_axe);
	free_arg(params);
	return (1);
}
