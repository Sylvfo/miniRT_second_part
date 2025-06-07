/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:29:55 by syl               #+#    #+#             */
/*   Updated: 2025/06/07 16:26:25 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void print_selected_object(t_scene *scene)
{
	if (scene->pix[scene->x][scene->y]->obj_a == 0)
		printf("You are trying to touch the sky. No object selected \n");
	else if (scene->pix[scene->x][scene->y]->obj_a == SPHERE)
		printf("Sphere n %i selected \n", 1 + scene->pix[scene->x][scene->y]->obj_b);
	else if (scene->pix[scene->x][scene->y]->obj_a == PLAN)
		printf("Plan n %i selected \n", 1 + scene->pix[scene->x][scene->y]->obj_b);
	else if (scene->pix[scene->x][scene->y]->obj_a == CYLINDER)
		printf("Cylinder n %i selected \n", 1 + scene->pix[scene->x][scene->y]->obj_b);
}

//XX
//1 select action
//2 select object
//3 select axe
//4 select dimension/ angle
//XX5 enter and lanch command no need...

int mouse_click(int button, int x, int y, t_scene *scene)
{
	if (button == 1 && x >= WND_WIDTH)
	{
		if (y < 130 && scene->draw_mode == 0) //preview
		{
			scene->preview = true;
			scene->draw_mode = 1;
			raytracing_main_bonus(scene->pix, scene, scene->mem_shuttle);
			pix_to_window(scene->pix, scene);
			printf("preview and drawing mode one \n");
			printf("select action \n");
		}
		if (y > 650 && y < 720 && scene->draw_mode == 1)// || scene->draw_mode == 1) //render
		{
			scene->draw_mode = 0;
			scene->preview = false;
			raytracing_main_bonus(scene->pix, scene, scene->mem_shuttle);
			pix_to_window(scene->pix, scene);
			printf("render mode one \n");
		}
		if (scene->draw_mode == 1)// select movement type
		{
			if (y > 220 && y < 320) //move
			{
				scene->draw_type = 1; //move
				scene->draw_mode = 2;
				printf("move selected \n");
			}
		}
	}
	if (scene->draw_mode == 2 && button == 1 && x < WND_WIDTH)// select obj
	{
		scene->x = x;
		scene->y = y;
		print_selected_object(scene);
		printf(" \nselect axe x y z\n");
		scene->draw_mode = 3;
	}
    return (0);
}

int	ft_keys_bonus(int keycode, t_scene *scene)
{
//	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		printf("ESC pressed.\nWindow closed\n");
		scene->end_programm = true;
		mlx_loop_end(scene->ima->mlx_ptr);
		return (0);
	}
	if (scene->draw_mode == 3)
	{
		take_axe(keycode, scene);
		scene->draw_mode = 4;
		printf("enter distance  \n");
	}
	if (scene->draw_mode == 4)
	{
		if (scene->draw_type == 1)// move
			take_distance_move(keycode, scene);
	}
	return (0);
}

//voir avec negatifs et points
void take_distance_move(int keycode, t_scene *scene)
{
	if (keycode == 65293)
	{
		if (scene->size_modif != 0.0)
		{
			apply_drawing_changes(scene);
			clear_modif(scene);
			printf("new image lauching\n");
			raytracing_main_bonus(scene->pix, scene, scene->mem_shuttle);
			pix_to_window(scene->pix, scene);
		}
		clear_modif(scene);
	}
	/// effacer...
	if (keycode >= 48 && keycode <=  57) //chiffres horiz clavier
	{
//		if (keycode == 48)//0
		scene->size_modif = (scene->size_modif * 10) + (keycode - 48);
		printf("distance is %.2f \n",  scene->size_modif );
	}
}

void take_axe(int keycode, t_scene *scene)
{
	if (keycode == 120)//x
		scene->axe_draw = 1;
	else if (keycode == 121)//y
		scene->axe_draw = 2;
	else if (keycode == 122)//z
		scene->axe_draw = 3;
	else if (keycode == 117)//u
		scene->axe_draw = 4;
	printf("keycode selected %i\n", keycode);
}

void apply_drawing_changes(t_scene *scene)
{
	int obj_type;
	int obj_num;

	obj_type = scene->pix[scene->x][scene->y]->obj_a;
	obj_num = scene->pix[scene->x][scene->y]->obj_b;
	if (scene->draw_type == 1) // move
	{
		if (scene->axe_draw == 1)
			scene->obj[obj_type][obj_num]->p_coord->x += scene->size_modif;
		else if (scene->axe_draw == 2)
			scene->obj[obj_type][obj_num]->p_coord->y += scene->size_modif;
		else if (scene->axe_draw == 3)
			scene->obj[obj_type][obj_num]->p_coord->z += scene->size_modif;	
	}
	move_object(scene->obj[obj_type][obj_num]);
}

void	clear_modif(t_scene *scene)
{
	scene->axe_draw = 0;
	scene->draw_mode = 1;
	scene->draw_type = 0;
	scene->x = 0;
	scene->y = 0;
	scene->size_modif = 0.0;
	printf("select action\n");
}

/*
old working

int mouse_click(int button, int x, int y, t_scene *scene)
{
  //  printf("Clic détecté : bouton = %d, x = %d, y = %d\n", button, x, y);
	if (button == 1 && x < WND_WIDTH)
	{
		scene->preview = true;
		scene->x = x;
		scene->y = y;
		print_selected_object(scene);
	}
	else if (button == 1 && x >= WND_WIDTH)
	{
		if (y < 130)
		{
			scene->preview = true;
			raytracing_main_bonus(scene->pix, scene, scene->mem_shuttle);
			pix_to_window(scene->pix, scene);
			printf("preview mode one \n");
		}
		if (y > 220 && y < 320)
		{
			scene->preview = true;
			move_object(scene, scene->pix, scene->obj);
			raytracing_main_bonus(scene->pix, scene, scene->mem_shuttle);
			pix_to_window(scene->pix, scene);
			printf("preview mode one + object move \n");
		}
		
		if (y > 650 && y < 720)
		{
			scene->preview = false;
			raytracing_main_bonus(scene->pix, scene, scene->mem_shuttle);
			pix_to_window(scene->pix, scene);
			printf("render mode one \n");
		}
	}
    return (0);
}
*/