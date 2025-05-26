/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:27:35 by syl               #+#    #+#             */
/*   Updated: 2025/05/26 12:39:44 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_pix	***malloc_pix_array(int height, int width)
{
	t_pix	***pix;
	int		i;
	int		j;

	pix = malloc(sizeof(t_pix **) * (height));
	if (!pix)
		return (NULL);
	i = 0;
	while (i < (height))
	{
		pix[i] = malloc(sizeof(t_pix *) * (width));
		if (!pix[i])
			return (free_partial_pix(pix, i, width));
		j = 0;
		while (j < (width))
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
//	pix->hits = NULL;
	pix->p_viewport = NULL;
	pix->p_viewport_world = NULL;
	pix->r_dir = NULL;
	pix->r_origin = NULL;
	pix->color = NULL;
	pix->obj_a = 0;// a deplacer
	pix->obj_b = 0;// a deplacer
}

//REFAIRE COMME IL FAUT!!!
void	malloc_pix_struct(t_pix ***pix, int height, int width)
{
	int	i;
	int	j;

	if (!pix)
		return ;
	i = 0;
	while (i < (height))
	{
		j = 0;
		while (j < (width))
		{
			if (pix[i][j] != NULL)
			{
				pix[i][j]->p_viewport = create_point(0, 0, 0);
				pix[i][j]->p_viewport_world = create_point(0, 0, 0);
				pix[i][j]->r_dir = create_vector(0, 0, 0);
				pix[i][j]->r_origin = create_vector(0, 0, 0);
				pix[i][j]->color = malloc(sizeof(t_color));
				pix[i][j]->color->r = 0.0;
				pix[i][j]->color->g = 0.0;
				pix[i][j]->color->b = 0.0;
				pix[i][j]->color->rgb = 0;
			}
			j++;
		}
		i++;
	}
}