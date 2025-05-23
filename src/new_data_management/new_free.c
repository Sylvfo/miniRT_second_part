/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:41:40 by syl               #+#    #+#             */
/*   Updated: 2025/05/23 10:25:47 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void free_main(t_pix ***pix)
{
	free_hits_cph(pix, WND_HEIGHT + 5, WND_WIDTH);
	printf("after free hits\n");
	free_pix_struct(pix, WND_HEIGHT, WND_WIDTH);
	free_pix_array(pix, WND_HEIGHT, WND_WIDTH);
}