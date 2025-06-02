/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:13:35 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/25 19:29:26 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	save_color(char *str, t_color *p)
{
	char	**coord;
	int		i;

	i = 0;
	coord = ft_split(str, ',');
	if (!coord)
		return (0);
	if (ft_size(coord) != NB_EL_AXE || !check_isvector(coord))
		return (free_arg(coord));
	p->r = number(coord[0]);
	p->g = number(coord[1]);
	p->b = number(coord[2]);
	free_arg(coord);
	return (1);
}

int	save_sphere(char *str, t_obj **obj)
{
	char	**params;
	int		i;

	i = 0;
	params = ft_split(str, ' ');
	if (!params)
		return (error_system());
	while (obj[i]->type == SPHERE)
	{
		i++;
	}
	obj[i]->type = SPHERE;
	if (!save_coordonnee(params[1], obj[i]->p_coord) || \
		!save_color(params[3], obj[i]->color))
	{
		free_arg(params);
		return (0);
	}
	obj[i]->diam = number(params[2]);
	free_arg(params);
	return (1);
}