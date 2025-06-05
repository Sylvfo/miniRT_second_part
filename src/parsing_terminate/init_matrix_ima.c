/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix_ima.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:21:31 by sforster          #+#    #+#             */
/*   Updated: 2025/06/05 13:02:25 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
// QU EST CE QUI EST VRAIMENT UTILISE?
typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*ima_cmd;
	char	*addr_ima_cmd;
	int		bits_per_pixel_cmd;
	int		line_length_cmd;
	int		endian_cmd;
	void	*mlx_ptr;
	void	*mlx_win;
}	t_image;*/

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
	ima->mlx_win = mlx_new_window(ima->mlx_ptr, (WND_WIDTH + 302), WND_HEIGHT, "Fen");
	ima->img = mlx_new_image(ima->mlx_ptr, WND_WIDTH, WND_HEIGHT);
	ima->addr = mlx_get_data_addr(ima->img, &ima->bits_per_pixel,
			&ima->line_length, &ima->endian);
	mlx_put_image_to_window(ima->mlx_ptr, ima->mlx_win, ima->img, 0, 0);
	return (ima);
}

bool create_image_cmd(t_image *ima)
{
	printf("enter in create img command\n");
	ima->ima_cmd = mlx_xpm_file_to_image(ima->mlx_ptr, "test1.xpm",
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
	printf("youkeli\n");
	return (true);
}

/*
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
	mlx_put_image_to_window(scene->ima->mlx_ptr,
		scene->ima->mlx_win, scene->ima->ima_cmd, WND_WIDTH + 2, 0);
}*/