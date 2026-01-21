/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20_mouse_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:29:55 by syl               #+#    #+#             */
/*   Updated: 2025/10/08 16:27:24 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	mouse_click(int button, int x, int y, t_glob **data)
{
	if (x > 2016 && x < 2132)
	{
		if (y > 407 && y < 464)
			export_bmp(data[0]->pix, "file2");
	}
	if (x > 2160 && x < 2277)
	{
		if (y > 407 && y < 464)
			save_scene_to_file(data[0]->scene, "testesave.rt");
	}
	if (button == 1 && x >= WND_WIDTH)
	{
		if (y > 50 && y < 100 && data[0]->scene->draw_mode == RENDER)
			drawing_mode(data);
		if (y <= 50 && data[0]->scene->draw_mode == PREVIEW)
			render_mode(data);
		if (data[0]->scene->draw_mode == PREVIEW)
			select_transformation(data[0]->scene, y);
	}
	if (data[0]->scene->draw_mode == CHOOSE_OBJ && button == 1 && x < WND_WIDTH)
		select_object(data[0]->scene, x, y);
	return (0);
}

int	ft_keys_bonus(int keycode, t_glob **datas)
{
	char	msg[120];
	float	*size;

	size = &datas[0]->scene->size_modif;
	if (keycode == 65307)
	{
		printf("ESC pressed.\nWindow closed\n");
		mlx_loop_end(datas[0]->scene->ima->mlx_ptr);
		return (0);
	}
	if (datas[0]->scene->draw_mode == CHOOSE_AXE)
	{
		take_axe(keycode, datas[0]->scene);
		if (*size != 0 && gcvt(*size, 6, msg))
			print_on_screen(datas[0]->scene, msg, 3, 255);
	}
	if (datas[0]->scene->draw_mode == CHOOSE_DIM)
	{
		take_dimensions(keycode, datas);
		if (*size != 0 && gcvt(*size, 6, msg))
			print_on_screen(datas[0]->scene, msg, 3, 255);
	}
	return (0);
}

void	clear_modif(t_scene *scene)
{
	scene->axe_draw = NO_AXE;
	scene->draw_mode = PREVIEW;
	scene->draw_type = NO_MOVE;
	scene->y = 0;
	scene->x = 0;
	scene->size_modif = 0.0;
	scene->after_virgule = 0.0;
	scene->size_modif_neg = 1.0;
	printf("select action\n");
}
