/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_memory_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:50:25 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 10:33:27 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_pix ***init_memory_main(void)
{
	t_pix	***pix;

	pix = NULL;
	pix = malloc_pix_array(WND_HEIGHT,WND_WIDTH);
	if (!pix)
	{
		printf("Failing at allocating pix memory \n");
		exit(EXIT_FAILURE);
	}
	malloc_pix_struct(pix, WND_WIDTH, WND_HEIGHT);
	return (pix);
}