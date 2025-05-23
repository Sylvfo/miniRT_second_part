/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:27:35 by syl               #+#    #+#             */
/*   Updated: 2025/05/23 13:56:39 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_pix	***malloc_pix_array(int height, int width)
{
	t_pix	***pix;
	int		i;
	int		j;

	pix = malloc(sizeof(t_pix **) * height);
	if (!pix)
		return (NULL);
	i = 0;
	while (i < height)
	{
		pix[i] = malloc(sizeof(t_pix *) * width);
		if (!pix[i])
			return (free_partial_pix(pix, i, width));
		j = 0;
		while (j < width)
		{
			pix[i][j] = malloc(sizeof(t_pix));
			if (!pix[i][j])
				return (free_partial_pix(pix, i + 1, j));
			pix[i][j]->hits = NULL;
			pix[i][j]->p_viewport = NULL;
			pix[i][j]->p_viewport_world = NULL;
			j++;
		}
		i++;
	}
	return (pix);
}

void	malloc_pix_struct(t_pix ***pix, int height, int width)
{
	int	i;
	int	j;

	if (!pix)
		return ;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (pix[i][j] != NULL)
			{
				pix[i][j]->p_viewport = malloc(sizeof(t_coord));
				pix[i][j]->p_viewport_world = malloc(sizeof(t_coord));
			}
			j++;
		}
		i++;
	}
}