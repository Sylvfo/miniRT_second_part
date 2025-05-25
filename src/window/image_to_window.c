/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:21:36 by syl               #+#    #+#             */
/*   Updated: 2025/05/25 21:06:27 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	pix_to_window(t_pix ***pix, t_scene *scene)
{
	int		x;
	int		y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			color_float_to_int(pix[x][y]->color);
			my_mlx_pixel_put(scene->ima, x, y, pix[x][y]->color->rgb);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(scene->ima->mlx_ptr,
		scene->ima->mlx_win, scene->ima->img, 0, 0);
}

/*
void	pix_to_window(t_pix ***pix, t_program_context *context)
{
	int		x;
	int		y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			color_float_to_int(pix[x][y]->color);
			my_mlx_pixel_put(context->ima, x, y, pix[x][y]->color->rgb);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(context->mlx_ptr,
		context->mlx_win, context->ima->img, 0, 0);
}*/
