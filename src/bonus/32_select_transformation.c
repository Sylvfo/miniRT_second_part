/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   22_select_transformation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:17:00 by syl               #+#    #+#             */
/*   Updated: 2025/06/13 11:27:46 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	select_transformation(t_scene *scene, int y)
{
	if (y >= 188 && y < 232)
		select_translation(scene);
	if (y >= 232 && y < 262)
		select_rotation(scene);
	if (y >= 262 && y < 299)
		select_scale(scene);
}

void	select_translation(t_scene *scene)
{
	scene->draw_type = MOVE;
	scene->draw_mode = CHOOSE_OBJ;
	print_on_screen(scene, "Translation selected", 0, 230);
	print_on_screen(scene, "Select object", 1, 210);
}

void	select_rotation(t_scene *scene)
{
	scene->draw_type = ROTATE;
	scene->draw_mode = CHOOSE_OBJ;
	print_on_screen(scene, "Rotation selected", 0, 230);
	print_on_screen(scene, "Select object", 1, 210);
}

void	select_scale(t_scene *scene)
{
	scene->draw_type = SCALE;
	scene->draw_mode = CHOOSE_OBJ;
	print_on_screen(scene, "Scaling selected", 0, 230);
	print_on_screen(scene, "Select object", 1, 210);
}

void	select_copy(t_scene *scene)
{
	scene->draw_type = COPY;
	scene->draw_mode = CHOOSE_OBJ;
	mlx_put_image_to_window(scene->ima->mlx_ptr,
		scene->ima->mlx_win, scene->ima->ima_blk, WND_WIDTH + 2, 850);
	mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win,
		(WND_WIDTH + 30), 900, 255, "Copy selected");
	mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win,
		(WND_WIDTH + 30), 920, 255, "Select object");
}
