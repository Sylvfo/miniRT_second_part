/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:25:14 by syl               #+#    #+#             */
/*   Updated: 2025/10/07 21:14:40 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	get_timestamp(struct timeval start)
{
	struct timeval	current;
	size_t			milliseconds;
	size_t			seconds;

	gettimeofday(&current, NULL);
	seconds = (current.tv_sec - start.tv_sec);
	milliseconds = (current.tv_usec / 1000 - start.tv_usec / 1000);
	printf("Time to calculate: %li sec %li millisec \n", seconds, milliseconds);
	return ;
}

void	paint_it_black(t_color *color)
{
	color->r = 0.0;
	color->g = 0.0;
	color->b = 0.0;
}