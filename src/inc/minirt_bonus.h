/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:31:12 by syl               #+#    #+#             */
/*   Updated: 2025/10/06 18:14:55 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# include <pthread.h>
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

# define NB_THREADS 12
# define MAX_RECURSIVITY 5

//00_main_bonus.c
void	raytracing_main_bonus(t_pix ***pix, t_scene *scene, t_mem **m_mem_shuttle);
void	raytracing_main_bonus_before(t_pix ***pix, t_scene *scene, t_mem *m_mem_shuttle);
t_color	raytracer_bonus(t_pix *pix, t_scene *scene, t_mem *memory_shuttle);
void	raytracing_recalculate_bonus(t_pix ***pix, t_scene *scene, t_mem *mem_shuttle);

//00_init_bonus.c
int	init_bonus(t_scene *scene, t_pix ***pix, t_mem **memory_shuttle, char *str);

//00_time.c
void	get_timestamp(struct timeval start);

//01_reflection.c
void	next_ray_reflection(t_mem *memory_shuttle);
t_color	reflexion(t_scene *scene, t_mem *memory_shuttle);
t_color	base_reflection(t_scene *scene, t_mem *mem_shtle, t_color color_light);
void	vect_reflexion(t_coord *r_base_dir, t_coord *v_normal);
//01_transparence.c 
t_color	transparence(t_scene *scene, t_mem *mem_shtle);
void	next_ray_transp(t_mem *mem_shuttle);

//00_base_recursion.c
t_color next_ray(t_scene *scene, t_mem *mem_shtle, t_color color_light);

//30_clean_mem_shuttle.c
t_mem	**init_multi_memory_shuttle(void);
void	clean_memory_shuttle_refl(t_mem *memory_shuttle);
void	paint_it_black(t_color *color);
//mouse_hooks.c
int		mouse_click(int button, int x, int y, t_scene *scene);
int		ft_keys_bonus(int keycode, t_scene *scene);
void	take_axe(int keycode, t_scene *scene);
void	clear_modif(t_scene *scene);

//00_base_recursion.c

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
