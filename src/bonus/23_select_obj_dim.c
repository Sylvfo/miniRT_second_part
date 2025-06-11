/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23_select_obj_dim.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:37:18 by syl               #+#    #+#             */
/*   Updated: 2025/06/11 12:05:24 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void select_object(t_scene *scene, int x, int y)
{
	scene->x = x;
	scene->y = y;
	print_selected_object(scene);
	print_on_screen(scene,"OBJECT SELECTED", 0, 255);
//	mlx_put_image_to_window(scene->ima->mlx_ptr,
//	scene->ima->mlx_win, scene->ima->ima_blk, WND_WIDTH + 2, 850);
//	mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win, (WND_WIDTH + 30), 900, 255, "OBJECT SELECTED");
	is_transformation_possible(scene, x, y);
	if (scene->draw_type == SCALE)
	{
		mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win, (WND_WIDTH + 30), 920, 255, "CHOOSE AXE x y z or U (unity)");
	}
	else
	{
		mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win, (WND_WIDTH + 30), 920, 255, "CHOOSE AXE x y z");
	}
	scene->draw_mode = CHOOSE_AXE;
}


void take_dimensions(int keycode, t_scene *scene)
{
	int digit;

	if (scene->size_modif == 0.0 && keycode == 45 && scene->size_modif_neg == 1.0)
		scene->size_modif_neg *= -1.0;
	if (keycode == 65293)// enter
	{
		scene->size_modif *= scene->size_modif_neg;
		if (scene->size_modif != 0.0)
			apply_transformations(scene);
		clear_modif(scene);
	}
	if (keycode >= 48 && keycode <= 57) //chiffres claviers
	{
		digit = keycode - 48;
		if (scene->after_virgule == 0.0) // partie entière
			scene->size_modif = (scene->size_modif * 10.0) + digit;
		else if (scene->after_virgule < 1000.0) // max 3 chiffres après la virgule
		{
			scene->after_virgule *= 10.0;
			scene->size_modif += digit / scene->after_virgule;
		}
	}
	if (keycode == 46 && scene->after_virgule == 0.0)
		scene->after_virgule = 1.0;
}

/*
void take_dimensions(int keycode, t_scene *scene)
{
	if (scene->draw_type == MOVE)// move
		take_distance_move(keycode, scene);
}*/

/*
//voir avec negatifs et points
//valeurs max... et min
// autres chiffres
// max 360 min 0.001
void  take_dimensions(int keycode, t_scene *scene)
{
	if (scene->size_modif == 0.0 && keycode == 45 && scene->size_modif_neg == 1.0)
		scene->size_modif_neg *= -1.0;
	if (keycode == 65293)
	{
		scene->size_modif *= scene->size_modif_neg;
		printf("distance finale is %.5f \n",  scene->size_modif );
	
		//avant virgule
		// apres virgule
		// negatif??
		if (scene->size_modif != 0.0)
			apply_transformations(scene);
		printf("out of transfo....\n");
		clear_modif(scene);
	}
	/// effacer...
	if (keycode >= 48 && keycode <=  57) //chiffres horiz clavier
	{
		if (scene->after_virgule == 0.0)
			scene->size_modif = (scene->size_modif * 10) + (keycode - 48);
		if (scene->after_virgule > 0)
		{
			printf("bo\n");
			scene->after_virgule *= 10;
			scene->size_modif = scene->size_modif + ((keycode - 48)/scene->after_virgule);
		}	
		printf("distance is %.5f \n",  scene->size_modif );
	}
	if (keycode == 46 && scene->after_virgule == 0.0)
	{
		printf("yo\n");
		scene->after_virgule = 1.0;
	}

}*/

/*
//avant gpt
void  take_dimensions(int keycode, t_scene *scene)
{
	if (scene->size_modif == 0.0 && keycode == 45 && scene->size_modif_neg == 1.0)
		scene->size_modif_neg *= -1.0;
	if (keycode == 65293)
	{
		scene->size_modif *= scene->size_modif_neg;
		printf("distance finale is %.5f \n",  scene->size_modif );
	
		//avant virgule
		// apres virgule
		// negatif??
		if (scene->size_modif != 0.0)
			apply_transformations(scene);
		print_modif(scene);
		clear_modif(scene);
		printf("out of transfo....\n");
	}
	/// effacer...
	if (keycode >= 48 && keycode <=  57) //chiffres horiz clavier
	{
		if (scene->after_virgule == 0.0)
			scene->size_modif = (scene->size_modif * 10) + (keycode - 48);
		if (scene->after_virgule > 0)
		{
			printf("bo\n");
			scene->after_virgule *= 10;
			scene->size_modif = scene->size_modif + ((keycode - 48)/scene->after_virgule);
		}	
		printf("distance is %.5f \n",  scene->size_modif );
	}
	if (keycode == 46 && scene->after_virgule == 0.0)
	{
		printf("yo\n");
		scene->after_virgule = 1.0;
	}

}*/




/*

. 46
- 45

autre clavier
1 65436
2 50
3 65435
4 65430
5 53
6 54
7 65429
8 65431
9 65434
0 65438



2 50
5 53
6 54

7 65429
4 65430
8 65431
9 65434
3 65435
1 65436
0 65438

. 65439
- 65453
*/


//void relaunch_preview()

void take_axe(int keycode, t_scene *scene)
{
	if (keycode == 120)//x
		scene->axe_draw = X_AXE;
	else if (keycode == 121)//y
		scene->axe_draw = Y_AXE;
	else if (keycode == 122)//z
		scene->axe_draw = Z_AXE;
	else if (keycode == 117 && scene->draw_type == SCALE)
		scene->axe_draw = U_UNITY;
//	printf("keycode selected %i\n", keycode);
//	printf("axe draw %i \n", scene->axe_draw);
//	printf("axe draw mode %i \n", scene->draw_mode);
	if (scene->axe_draw != 0)
	{
		scene->draw_mode = CHOOSE_DIM;
		mlx_put_image_to_window(scene->ima->mlx_ptr,
		scene->ima->mlx_win, scene->ima->ima_blk, WND_WIDTH + 2, 850);
		mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win, (WND_WIDTH + 30), 900, 255, "AXE SELECTED");
		if (scene->draw_type == MOVE || scene->draw_type == COPY)
			mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win, (WND_WIDTH + 30), 920, 255, "CHOOSE DIMENSION");
		else if (scene->draw_type == SCALE)
			mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win, (WND_WIDTH + 30), 920, 255, "CHOOSE DIMENSION SCALAR");
		else if (scene->draw_type == ROTATE)
			mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win, (WND_WIDTH + 30), 920, 255, "ROTATION ANGLE");
		mlx_string_put(scene->ima->mlx_ptr, scene->ima->mlx_win, (WND_WIDTH + 30), 940, 255, "MAX 360, MIN 0.001");
	}	
}

