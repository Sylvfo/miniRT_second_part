/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:30:45 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 22:33:10 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	*free_partial_pix(t_pix ***pix, int height, int width)
{
	int	i;
	int	j;

	if (!pix)
		return (NULL);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (pix[i] && j < width)
		{
			if (pix[i][j])
				free(pix[i][j]);
			j++;
		}
		free(pix[i]);
		i++;
	}
	free(pix);
	return (NULL);
}

void	free_pix_array(t_pix ***pix, int height, int width)
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
				free(pix[i][j]);
				pix[i][j] = NULL;
			}
			j++;
		}
		free(pix[i]);
		i++;
	}
	free(pix);
}

void	free_pix_struct(t_pix ***pix, int height, int width)
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
				if (pix[i][j]->color != NULL)
				{
					free(pix[i][j]->color);
					pix[i][j]->color = NULL;
				}
			}
			j++;
		}
		i++;
	}
}
