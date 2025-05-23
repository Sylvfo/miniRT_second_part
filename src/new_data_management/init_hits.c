/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:04:27 by syl               #+#    #+#             */
/*   Updated: 2025/05/23 09:37:35 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	malloc_hits_main(t_pix ***pix, int height, int width, int types, int objs)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (pix[i][j])
				pix[i][j]->hits = malloc_hits(types, objs);
			j++;
		}
		i++;
	}
}

t_hits	***malloc_hits(int types, int objs)
{
	t_hits	***hits;
	int		i;
	int		j;

	hits = malloc(sizeof(t_hits **) * types);
	if (!hits)
		return (NULL);
	i = 0;
	while (i < types)
	{
		hits[i] = malloc(sizeof(t_hits *) * objs);
		if (!hits[i])
			return (free_partial_hits(hits, i, objs));
		j = 0;
		while (j < objs)
		{
			hits[i][j] = malloc(sizeof(t_hits));
			if (!hits[i][j])
				return (free_partial_hits(hits, i + 1, j));
			j++;
		}
		i++;
	}
	return (hits);
}

void	*free_partial_hits(t_hits ***hits, int i_max, int j_max)
{
	int	i;
	int	j;

	i = 0;
	while (i < i_max)
	{
		j = 0;
		while (hits[i] && j < j_max)
		{
			if (hits[i][j])
			{
				free(hits[i][j]);
			}
			j++;
		}
		free(hits[i]);
		i++;
	}
	free(hits);
	return (NULL);
}

void	free_hits_new(t_hits ***hits, int types, int objs)
{
	int	i;
	int	j;

	if (!hits)
		return ;
	i = 0;
	while (i < types)
	{
		j = 0;
		while (j < objs)
		{
			free(hits[i][j]);
			hits[i][j] = NULL;
			j++;
		}
		free(hits[i]);
		hits[i] = NULL;
		i++;
	}
	free(hits);
}


void	free_hits_cph(t_pix ***pix, int height, int width)
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
			free_hits_new(pix[i][j]->hits, 4, 4);
			pix[i][j]->hits = NULL;
		/*	if (pix[i][j]->hits)
			{
				free_hits_new(pix[i][j]->hits, 4, 4);
				pix[i][j]->hits = NULL;
			}*/
			j++;
		}
		i++;
	}
}