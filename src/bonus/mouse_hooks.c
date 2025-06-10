/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:29:55 by syl               #+#    #+#             */
/*   Updated: 2025/06/10 18:39:46 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
printf
type transformation, objet, axe, dimension....
*/

int mouse_click(int button, int x, int y, t_scene *scene)
{
	if (button == 1 && x >= WND_WIDTH)
	{
		if (y > 67 && y < 112 && scene->draw_mode == RENDER)
			drawing_mode(scene);
		if (y <= 67 && scene->draw_mode == PREVIEW)
			render_mode(scene);
		if (scene->draw_mode == PREVIEW)
			select_transformation(scene, x, y);
	}
	if (scene->draw_mode == CHOOSE_OBJ && button == 1 && x < WND_WIDTH)
		select_object(scene, x, y);
    return (0);
}

int	ft_keys_bonus(int keycode, t_scene *scene)
{
	printf("keycode %i \n", keycode);
	if (keycode == 65307)
	{
		printf("ESC pressed.\nWindow closed\n");
		mlx_loop_end(scene->ima->mlx_ptr);
		return (0);
	}
	if (scene->draw_mode == CHOOSE_AXE)
		take_axe(keycode, scene);
	if (scene->draw_mode == CHOOSE_DIM)
		take_dimensions(keycode, scene);
	return (0);
}



void	clear_modif(t_scene *scene)
{
	scene->axe_draw = 0;
	scene->draw_mode = PREVIEW;
	scene->draw_type = 0;
	scene->y = 0;
	scene->size_modif = 0.0;
	scene->after_virgule = 0.0;
	scene->size_modif_neg = 1.0;
	printf("select action\n");
}
