/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:41:40 by syl               #+#    #+#             */
/*   Updated: 2025/05/25 09:59:20 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void free_main(t_pix ***pix, t_scene *scene)
{
	// delink
	if (scene)
		free_scene(scene);
	free(scene);
	scene = NULL;
	free_hits_cph(pix, WND_HEIGHT, WND_WIDTH);
	printf("after free hits\n");
	free_pix_struct(pix, WND_HEIGHT, WND_WIDTH);
	free_pix_array(pix, WND_HEIGHT, WND_WIDTH);
}