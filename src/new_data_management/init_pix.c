/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:27:35 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 23:03:22 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_pix	***malloc_pix_array(int width2, int height)
{
	t_pix	***pix;
	int		i;
	int		j;

	pix = malloc(sizeof(t_pix **) * (width2));
	if (!pix)
		return (NULL);
	i = 0;
	while (i < (width2))
	{
		pix[i] = malloc(sizeof(t_pix *) * (height));
		if (!pix[i])
			return (free_partial_pix(pix, i, height));
		j = 0;
		while (j < (height))
		{
			pix[i][j] = malloc(sizeof(t_pix));
			if (!pix[i][j])
				return (free_partial_pix(pix, i + 1, j));
			pix_values_null(pix[i][j]);
			j++;
		}
		i++;
	}
	return (pix);
}

void	pix_values_null(t_pix *pix)
{
	pix->color = NULL;
	pix->obj_a = 0;
	pix->obj_b = 0;
}

void	malloc_pix_struct(t_pix ***pix, int width2, int height)
{
	int	i;
	int	j;

	if (!pix)
		return ;
	i = 0;
	while (i < (width2))
	{
		j = 0;
		while (j < (height))
		{
			if (pix[i][j] != NULL)
			{
				pix[i][j]->color = create_color(0.0, 0.0, 0.0);
				pix[i][j]->color->rgb = 0;
			}
			j++;
		}
		i++;
	}
}
