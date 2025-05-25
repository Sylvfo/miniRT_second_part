/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:30:45 by syl               #+#    #+#             */
/*   Updated: 2025/05/25 20:44:20 by syl              ###   ########.fr       */
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

//fonctionne :)
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
				if (pix[i][j]->p_viewport != NULL)
				{
					free(pix[i][j]->p_viewport);
					pix[i][j]->p_viewport = NULL;
				}
				if (pix[i][j]->p_viewport_world != NULL)
				{
					free(pix[i][j]->p_viewport_world);
					pix[i][j]->p_viewport_world = NULL;
				}
				if (pix[i][j]->r_dir != NULL)
				{
					free(pix[i][j]->r_dir);
					pix[i][j]->r_dir = NULL;
				}
				if (pix[i][j]->r_origin != NULL)
				{
					free(pix[i][j]->r_origin);
					pix[i][j]->r_origin = NULL;
				}
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