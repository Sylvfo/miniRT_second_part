/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:13:30 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/25 19:28:59 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	save_ambient(char *str, t_light *lux)
{
	char	**params;

	params = ft_split(str, ' ');
	if (!params)
		return (error_system());
	lux->ratio = number(params[1]);
	if (!save_color(params[2], lux->color, lux->color))
	{
		free_arg(params);
		return (0);
	}
	free_arg(params);
	return (1);
}

int	save_light(char *str, t_light **lux)
{
	char	**params;
	int		i;

	i = 0;
	params = ft_split(str, ' ');
	if (!params)
		return (error_system());
	while (lux[i]->ratio >= 0)
		i++;
	if (!save_coordonnee(params[1], lux[i]->p_coord))
	{
		free_arg(params);
		return (0);
	}
	if (ft_size(params) == NB_EL_LIGHT && !save_color(params[3], lux[i]->color, \
lux[i]->color))
	{
		free_arg(params);
		return (0);
	}
	lux[i]->ratio = number(params[2]);
	free_arg(params);
	return (1);
}
