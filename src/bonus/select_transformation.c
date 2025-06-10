/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_transformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:17:00 by syl               #+#    #+#             */
/*   Updated: 2025/06/10 17:01:59 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void select_transformation(t_scene *scene, int x, int y)
{
	if (y > 142 && y < 183) //move
		select_translation(scene);

}

void select_translation(t_scene *scene)
{
	scene->draw_type = MOVE; //move
	scene->draw_mode = CHOOSE_OBJ;
	mlx_put_image_to_window(scene->ima->mlx_ptr,
		scene->ima->mlx_win, scene->ima->ima_blk, WND_WIDTH + 2, 850);
	mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win, (WND_WIDTH + 30), 900, 255, "Translation selected");
	mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win, (WND_WIDTH + 30), 920, 255, "Select object");
	printf("move selected \nSelect obj\n");
}

void select_rotation(t_scene *scene)
{
	scene->draw_type = ROTATE; //move
	scene->draw_mode = CHOOSE_OBJ;
	mlx_put_image_to_window(scene->ima->mlx_ptr,
		scene->ima->mlx_win, scene->ima->ima_blk, WND_WIDTH + 2, 850);
	mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win, (WND_WIDTH + 30), 900, 255, "Rotation selected");
	mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win, (WND_WIDTH + 30), 920, 255, "Select object");
	printf("move selected \nSelect obj\n");
}

void select_scale(t_scene *scene)
{
	scene->draw_type = SCALE; //move
	scene->draw_mode = CHOOSE_OBJ;
	mlx_put_image_to_window(scene->ima->mlx_ptr,
		scene->ima->mlx_win, scene->ima->ima_blk, WND_WIDTH + 2, 850);
	mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win, (WND_WIDTH + 30), 900, 255, "Scaling selected");
	mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win, (WND_WIDTH + 30), 920, 255, "Select object");
	printf("move selected \nSelect obj\n");	
}

void select_copy(t_scene *scene)
{
	scene->draw_type = COPY; //move
	scene->draw_mode = CHOOSE_OBJ;
	mlx_put_image_to_window(scene->ima->mlx_ptr,
		scene->ima->mlx_win, scene->ima->ima_blk, WND_WIDTH + 2, 850);
	mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win, (WND_WIDTH + 30), 900, 255, "Copy selected");
	mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win, (WND_WIDTH + 30), 920, 255, "Select object");
	printf("move selected \nSelect obj\n");		
}