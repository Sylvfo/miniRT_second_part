/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:31:12 by syl               #+#    #+#             */
/*   Updated: 2026/01/21 11:16:45 by sforster         ###   ########.fr       */
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

//00_raytracing_main_bonus.c
void	raytracing_main_bonus(t_glob **datas);
t_color	raytracer_bonus(t_pix *pix, t_scene *scene, t_mem *memory_shuttle);
void	*routine(void *arg);
void	reset_recursivity_level(t_glob **datas);
t_color	next_ray(t_scene *scene, t_mem *mem_shtle, t_color color_light);

//00_init_bonus.c
int		init_bonus(t_scene *scene, t_pix ***pix, t_mem **memory_shuttle,\
	char *str);
t_glob	**init_data(t_pix ***pix, t_scene *scene, t_mem **m_mem_shuttle);
void	clear_data(t_glob	**data, int i);

//00_time.c
void	get_timestamp(struct timeval start);
void	paint_it_black(t_color *color);

//01_reflection.c
void	next_ray_reflection(t_mem *memory_shuttle);
t_color	reflexion(t_scene *scene, t_mem *mem_shtle, t_color prev_color);
void	vect_reflexion(t_coord *r_base_dir, t_coord *v_normal);

//01_transparence.c 
t_color	transparence(t_scene *scene, t_mem *mem_shtle);
void	next_ray_transp(t_mem *mem_shuttle);

//01_refraction.c
t_color	refraction(t_scene *scene, t_mem *mem_shtle);
void	next_ray_refraction(t_scene *scene, t_mem *mem_shuttle);
void	vect_refraction(t_coord *r_base_dir, t_coord *v_normal,\
	float indice_refraction);
void	cal_intersect_bonus(t_mem *mem, t_obj ***obj, int n, t_intertt result);

//free_bonus.c 
void	free_main_bonus(t_pix ***pix, t_scene *scene,\
	t_mem **multi_mem_shuttle, t_glob **datas);
void	free_multi_memory_shuttle(t_mem **multi_mem_shuttle);
void	free_data(t_glob **datas);

//30_clean_mem_shuttle.c
t_mem	**init_multi_memory_shuttle(void);
void	memory_shuttle_bonus_values_null(t_mem *mem_shuttle);
void	clean_memory_shuttle_refl(t_mem *memory_shuttle);
void	raytracer_threads(t_glob **datas);
void	clear_multi_mem_shuttle(t_mem **multi_mem_shuttle, int i);

//mouse_hooks.c
int		mouse_click(int button, int x, int y, t_glob **data);
int		ft_keys_bonus(int keycode, t_glob **datas);
void	take_axe(int keycode, t_scene *scene);
void	clear_modif(t_scene *scene);

//01_lighting_bonus.c
t_color	lighting_bonus(t_scene *scene, t_mem *memory_shuttle,\
	t_color obj_color);
void	light_intersections_shadow(t_obj ***obj, t_mem *memory_shuttle);
t_color	color_light(int i, t_color light_color, t_scene *scene,\
	t_mem *memory_shuttle);
void	obj_intersect(t_obj ***obj, t_mem *memory_shuttle, int a, int b);
void	apply_transformation_bonus(t_obj *obj, t_mem *memory_shuttle);

//01_raytracer_shadow.c
void	raytracer_shadow_bonus(t_scene *scene, t_mem *mem_shtle, int num_light);
void	next_ray_light(t_mem *mem_shuttle, t_coord *lux_p_coord);

//01_take_shadow_color.c
void	take_shadow_color(t_mem *mem_shuttle, t_intertt result, t_obj *obj);
void	new_shadow_color(t_mem *mem_shuttle, t_obj *obj);

//01_shadow_intersect.c
void	intersect_plan_shadow_bonus(t_mem *memory_shuttle, t_obj *obj);
void	intersect_sphere_shadow_bonus(t_mem *memory_shuttle, t_obj *obj);
void	intersect_cylinder_bonus(t_mem *memory_shuttle, t_obj *obj);
void	intersect_triangle_bonus(t_mem *memory_shuttle, t_obj ***obj, int n);
void	intersect_cone_bonus(t_mem *memory_shuttle, t_obj *obj);

//00_base_recursion.c
void	clean_memory_shuttle_light(t_mem *mem_shuttle);
//transf_obj.c
//void move_object(t_obj *obj);
void	re_identity_matrix(float *m_identity);

//render_mode.c
//oid	drawing_mode(t_scene *scene);
void	drawing_mode(t_glob **datas);
//void	render_mode(t_scene *scene);
void	render_mode(t_glob **datas);
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
void	take_dimensions(int keycode, t_glob **datas);

//apply_modifications.c
void	apply_transformations(t_glob **datas);
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

//export_jpg.c
void	export_bmp(t_pix ***pix, const char *filename);

//04_save_rt_main.c
void	write_camera(FILE *f, t_camera *c);
int		save_scene_to_file(t_scene *scene, const char *filename);

//coord_modified
void	change_coord_modified(t_obj *obj, int type);
void	change_axe_modified(t_obj *obj, int type);

//04_save_file_rt.c
void	write_color(FILE *f, t_color *c, t_color *c2);
void	write_vec3(FILE *f, t_coord *p);
void	write_visual_effect(FILE *f, t_obj *obj);
void	write_ambient(FILE *f, t_light *lux);
void	write_light(FILE *f, t_light *l);

//04_save_suite_rt.c
void	write_sphere(FILE *f, t_obj *obj);
void	write_plan(FILE *f, t_obj *obj);
void	write_cylinder(FILE *f, t_obj *obj);
void	write_cone(FILE *f, t_obj *obj);
void	write_triangle(FILE *f, t_obj *obj);

#endif
