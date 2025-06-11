/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:13:39 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/25 19:28:48 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	save_cylinder(char *str, t_obj **obj)
{
	char	**params;
	int		i;

	i = 0;
	params = ft_split(str, ' ');
	if (!params)
		return (error_system());
	while (obj[i]->type == CYLINDER)
	{
		i++;
	}
	obj[i]->type = CYLINDER;
	if (!save_coordonnee(params[1], obj[i]->p_coord) ||	\
		!save_coordonnee(params[2], obj[i]->v_axe) || \
		!save_color(params[5], obj[i]->color))
	{
		free_arg(params);
		return (0);
	}
	obj[i]->p_coord->t = 1;
	obj[i]->v_axe->t = 0;
	obj[i]->diam = number(params[3]);
	obj[i]->radius = obj[i]->diam/2;
	obj[i]->height = number(params[4]);
	free_arg(params);
	return (1);
}