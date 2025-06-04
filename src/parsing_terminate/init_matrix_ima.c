/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix_ima.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:21:31 by sforster          #+#    #+#             */
/*   Updated: 2025/06/04 23:15:52 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_image	*create_image(void)
{
	t_image	*ima;

	ima = NULL;
	ima = malloc(sizeof(t_image));
	if (!ima)
		return (NULL);
	
	ima->addr = NULL;
	ima->img = NULL;
	ima->ima_cmd = NULL;
	ima->addr_ima_cmd = NULL;
	ima->mlx_ptr = NULL;
	ima->mlx_win = NULL;
	ima->mlx_ptr = mlx_init();
	if (!ima->mlx_ptr)
	{
		free(ima);
		return (NULL);
	}
	ima->mlx_win = mlx_new_window(ima->mlx_ptr, (WND_WIDTH + 300), WND_HEIGHT, "Fen");
	ima->img = mlx_new_image(ima->mlx_ptr, WND_WIDTH, WND_HEIGHT);
	ima->addr = mlx_get_data_addr(ima->img, &ima->bits_per_pixel,
			&ima->line_length, &ima->endian);
	mlx_put_image_to_window(ima->mlx_ptr, ima->mlx_win, ima->img, 0, 0);
	return (ima);
}

bool create_image_cmd(t_image *ima)
{
	printf("enter in create img command\n");
	ima->ima_cmd = mlx_xpm_file_to_image(ima->mlx_ptr, "testimage.xpm",
                                     &ima->line_length, &ima->endian);
	if (!ima->ima_cmd)
	{
    	printf("Erreur : impossible de charger testimage.xpm\n");
    	return (false);
	}

	ima->addr_ima_cmd = mlx_get_data_addr(ima->ima_cmd,
                                      &ima->bits_per_pixel,
                                      &ima->line_length,
                                      &ima->endian);
	printf("youkeli\n");
	mlx_put_image_to_window(ima->mlx_ptr, ima->mlx_win, ima->ima_cmd, 1250, 100);
	return (true);
//	ima->ima_cmd = mlx_new_image(ima->mlx_ptr, 300, WND_HEIGHT);// hauteur == wnd height - hauteur du truc /2
//	mlx_xpm_file_to_image(ima->mlx_ptr, "testimage.xpm",&ima->line_length, &ima->endian);
//	ima->addr_ima_cmd = mlx_get_data_addr(ima->ima_cmd, &ima->bits_per_pixel,
//			&ima->line_length, &ima->endian);
	
//	mlx_put_image_to_window(ima->mlx_ptr, ima->mlx_win, ima->ima_cmd, WND_WIDTH, 0);
//	return (true);
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
