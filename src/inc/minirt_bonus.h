/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:31:12 by syl               #+#    #+#             */
/*   Updated: 2025/06/12 15:05:53 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# include "minirt_data_struct.h"

enum e_transf_type
{
	NO_MOVE,
	MOVE,
	ROTATE,
	SCALE,
	COPY,
};

enum e_transf_mode
{
	RENDER,
	PREVIEW,
	CHOOSE_OBJ,
	CHOOSE_AXE,
	CHOOSE_DIM,
};

enum e_transf_axe
{
	NO_AXE,
	X_AXE,
	Y_AXE,
	Z_AXE,
	U_UNITY,
};

//00_main_bonus.c
t_color	raytracer_bonus(t_pix *pix, t_scene *scene, t_mem *memory_shuttle);
t_color	reflexion(t_scene *scene, t_mem *memory_shuttle, int recurs_count);
void	raytracing_main_bonus(t_pix ***pix, t_scene *scene, t_mem *mem_shuttle);

//01_reflection.c
void	next_ray_reflection(t_mem *memory_shuttle);
void	clean_memory_shuttle_refl(t_mem *memory_shuttle);
void	vect_reflexion(t_coord *r_base_dir, t_coord *v_normal);
//t_color	blend_reflection(t_color local, t_color reflected, float refl_int);

//mouse_hooks.c
int		mouse_click(int button, int x, int y, t_scene *scene);
int		ft_keys_bonus(int keycode, t_scene *scene);
//void	take_distance_move(int keycode, t_scene *scene);
void	take_axe(int keycode, t_scene *scene);
//void apply_drawing_changes(t_scene *scene);
void	clear_modif(t_scene *scene);

//transf_obj.c
//void move_object(t_obj *obj);
void	re_identity_matrix(float *m_identity);

//render_mode.c
void	drawing_mode(t_scene *scene);
void	render_mode(t_scene *scene);
void	is_transformation_possible(t_scene *scene);

//select_transformation.c
void	select_transformation(t_scene *scene, int y);
void	select_translation(t_scene *scene);
void	select_rotation(t_scene *scene);
void	select_scale(t_scene *scene);
void	select_copy(t_scene *scene);

//select_obj_dim.c 
void	select_object(t_scene *scene, int x, int y);
//void take_distance_move(int keycode, t_scene *scene);
void	take_axe(int keycode, t_scene *scene);
void	take_dimensions(int keycode, t_scene *scene);

//apply_modifications.c
void	apply_transformations(t_scene *scene);
void	apply_move_changes(t_scene *scene);
void	apply_rotate_changes(t_scene *scene);
void	apply_scale_changes(t_scene *scene);
void	apply_copy_changes(t_scene *scene);

//transf_obj.c
void	scaling_matrix(t_scene *scene, t_obj *obj);
void	moving_matrix(t_scene *scene, t_obj *obj);
void	rotating_matrix(t_scene *scene, t_obj *obj);

//matrix_rotation.c
void	rotation_x_matrix(t_scene *scene, t_obj *obj);
void	rotation_y_matrix(t_scene *scene, t_obj *obj);
void	rotation_z_matrix(t_scene *scene, t_obj *obj);

//print_action.c
void	print_modif(t_scene *scene);
void	print_action(t_scene *scene);
void	print_object(t_scene *scene);
void	print_value(t_scene *scene);
void	print_axe(t_scene *scene);
void	print_selected_object(t_scene *scene);
void	print_on_screen(t_scene *scene, char *msg, int place, int color);

#endif
