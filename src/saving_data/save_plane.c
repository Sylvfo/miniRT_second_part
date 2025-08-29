/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:13:43 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/25 19:29:08 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	save_plan(char *str, t_obj **obj, int *pos)
{
	char	**params;
	int		i;

	i = 0;
	params = ft_split(str, ' ');
	if (!params)
		return (error_system());
	while (obj[i]->type == PLAN)
	{
		i++;
	}
	obj[i]->type = PLAN;
	if (!save_coordonnee(params[1], obj[i]->p_coord) || \
!save_coordonnee(params[2], obj[i]->v_axe) || \
!save_color(params[3], obj[i]->color, &obj[i]->color2))
	{
		free_arg(params);
		return (0);
	}
	normalize_vector_na(obj[i]->v_axe);
	free_arg(params);
	*pos = i;
	return (1);
}
