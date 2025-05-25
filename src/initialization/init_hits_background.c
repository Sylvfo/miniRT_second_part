/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hits_background.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:47:15 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/25 19:49:17 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
static int	allocate_background_hit_coords(t_hits *hit)
{
	hit->r_dir = malloc(sizeof(t_coord));
	if (!hit->r_dir)
		return (0);
	hit->r_origin = malloc(sizeof(t_coord));
	if (!hit->r_origin)
	{
		free(hit->r_dir);
		hit->r_dir = NULL;
		return (0);
	}
	return (1);
}

static t_hits	*create_and_initialize_background_hit(void)
{
	t_hits	*hit;

	hit = malloc(sizeof(t_hits));
	if (!hit)
		return (NULL);
	if (!allocate_background_hit_coords(hit))
	{
		free(hit);
		return (NULL);
	}
	hit->type = NONE;
	hit->t1 = INT_MAX;
	hit->t2 = INT_MAX;
	hit->t_count = 0;
	return (hit);
}

void	init_hits_background(t_hits ***hits)
{
	if (!hits || !hits[0])
		return ;
	hits[0][0] = create_and_initialize_background_hit();
	if (!hits[0][0])
	{
		free(hits[0]);
		hits[0] = NULL;
		return ;
	}
	hits[0][1] = NULL;
}*/
