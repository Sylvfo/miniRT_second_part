/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:21:31 by sforster          #+#    #+#             */
/*   Updated: 2025/06/12 09:57:39 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_image	*create_image(t_scene *scene)
{
	t_image	*ima;

	ima = NULL;
	ima = malloc(sizeof(t_image));
	if (!ima)
		return (NULL);
	ima->addr = NULL;
	ima->img = NULL;
	ima->mlx_ptr = NULL;
	ima->mlx_win = NULL;
	ima->mlx_ptr = mlx_init();
	if (!ima->mlx_ptr)
	{
		free(ima);
		return (NULL);
	}
	if (scene->bonus_mode == false)
		ima->mlx_win = mlx_new_window(ima->mlx_ptr, WND_WIDTH, WND_HEIGHT, "MiniRT");
	if (scene->bonus_mode == true)
		ima->mlx_win = mlx_new_window(ima->mlx_ptr, WND_WIDTH + 300, WND_HEIGHT, "MiniRT_bonus");	
	ima->img = mlx_new_image(ima->mlx_ptr, WND_WIDTH, WND_HEIGHT);
	ima->addr = mlx_get_data_addr(ima->img, &ima->bits_per_pixel,
			&ima->line_length, &ima->endian);
	mlx_put_image_to_window(ima->mlx_ptr, ima->mlx_win, ima->img, 0, 0);
	return (ima);
}


bool create_image_cmd(t_image *ima)
{
	ima->ima_cmd = mlx_xpm_file_to_image(ima->mlx_ptr, "dessin_commandes/Title3.xpm",
                                     &ima->line_length_cmd, &ima->endian_cmd);
	if (!ima->ima_cmd)
	{
    	printf("Erreur : impossible de charger testimage.xpm\n");
    	return (false);
	}
	ima->addr_ima_cmd = mlx_get_data_addr(ima->ima_cmd,
                                      &ima->bits_per_pixel_cmd,
                                      &ima->line_length_cmd,
                                      &ima->endian_cmd);
	return (true);
}

bool create_image_blk(t_image *ima)
{
	ima->ima_blk = mlx_xpm_file_to_image(ima->mlx_ptr, "dessin_commandes/blackboard.xpm",
                                     &ima->line_length_blk, &ima->endian_blk);
	if (!ima->ima_blk)
	{
    	printf("Erreur : impossible de charger blackboard.xpm\n");
    	return (false);
	}
	ima->addr_ima_cmd = mlx_get_data_addr(ima->ima_blk,
                                      &ima->bits_per_pixel_blk,
                                      &ima->line_length_blk,
                                      &ima->endian_blk);
	return (true);
}



/*
bool	init_ima(t_program_context *context)
{
	t_image	*ima;

	ima = create_image();
	if (!ima)
		return (false);
	context->ima = ima;
	context->mlx_ptr = ima->mlx_ptr;
	context->mlx_win = ima->mlx_win;
	return (true);
}*/
