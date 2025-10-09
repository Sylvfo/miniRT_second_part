/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23_select_obj_dim.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:37:18 by syl               #+#    #+#             */
/*   Updated: 2025/10/09 17:22:09 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include <stdlib.h>

void	select_object(t_scene *scene, int x, int y)
{
	scene->x = x;
	scene->y = y;
	print_selected_object(scene);
	print_on_screen(scene, "OBJECT SELECTED", 0, 255);
	is_transformation_possible(scene);
	if (scene->draw_type == SCALE)
		print_on_screen(scene, "CHOOSE AXE x y z or U (unity)", 1, 255);
	else
		print_on_screen(scene, "CHOOSE AXE x y z", 1, 255);
	scene->draw_mode = CHOOSE_AXE;
}

void	take_dimensions(int keycode, t_glob **datas)
{
	
/*	float	digit;
	(void) keycode;

	if (scanf("%f", &digit))
		datas[0]->scene->size_modif = digit;
	printf("digit %f", digit);
	if (keycode == 65293)
	{
		datas[0]->scene->size_modif *= datas[0]->scene->size_modif_neg;
		if (datas[0]->scene->size_modif != 0.0)
			apply_transformations(datas);
		clear_modif(datas[0]->scene);
	}*/


	int digit;
	if (datas[0]->scene->size_modif == 0.0 && keycode == 45
		&& datas[0]->scene->size_modif_neg == 1.0)
		datas[0]->scene->size_modif_neg *= -1.0;*/
	if (keycode == 65293)
	{
		datas[0]->scene->size_modif *= datas[0]->scene->size_modif_neg;
		if (datas[0]->scene->size_modif != 0.0)
			apply_transformations(datas);
		clear_modif(datas[0]->scene);
	}
	if (keycode >= 48 && keycode <= 57)
	{
		digit = keycode - 48;
		if (datas[0]->scene->after_virgule == 0.0)
			datas[0]->scene->size_modif = (datas[0]->scene->size_modif * 10.0) + digit;
		else if (datas[0]->scene->after_virgule < 1000.0)
		{
			datas[0]->scene->after_virgule *= 10.0;
			datas[0]->scene->size_modif += digit / datas[0]->scene->after_virgule;
		}
	}
	if (keycode == 46 && datas[0]->scene->after_virgule == 0.0)//point?
		datas[0]->scene->after_virgule = 1.0;
}

void	take_axe(int keycode, t_scene *scene)
{
	printf("laaa");
	if (keycode == 120)
		scene->axe_draw = X_AXE;
	else if (keycode == 121)
		scene->axe_draw = Y_AXE;
	else if (keycode == 122)
		scene->axe_draw = Z_AXE;
	else if (keycode == 117 && scene->draw_type == SCALE)
		scene->axe_draw = U_UNITY;
	if (scene->axe_draw != 0)
	{
		scene->draw_mode = CHOOSE_DIM;
		print_on_screen(scene, "AXE SELECTED", 0, 255);
		if (scene->draw_type == MOVE || scene->draw_type == COPY)
			print_on_screen(scene, "CHOOSE DIMENSION", 1, 255);
		else if (scene->draw_type == SCALE)
			print_on_screen(scene, "CHOOSE DIMENSION SCALAR", 1, 255);
		else if (scene->draw_type == ROTATE)
			print_on_screen(scene, "ROTATION ANGLE", 1, 255);
		print_on_screen(scene, "MAX 360, MIN 0.001", 2, 255);
	}
	printf("laaa2");
}
