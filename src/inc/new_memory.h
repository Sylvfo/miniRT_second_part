/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_memory.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:27:05 by syl               #+#    #+#             */
/*   Updated: 2025/05/27 08:56:33 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_MEMORY_H
# define NEW_MEMORY_H

# include "minirt_data_struct.h"

//memory init

//no_parsing.c
void	no_parsing(t_scene *scene);

//base_data.c
void	base_data2(t_scene *scene);

//init_pix.c
t_pix	***malloc_pix_array(int height, int width);
void	malloc_pix_struct(t_pix ***pix, int height, int width);
void	pix_values_null(t_pix *pix);

//init_hits.c
//void	malloc_hits_main(t_pix ***pix, int height, int width, int types, int objs);
//t_hits	***malloc_hits(int types, int objs);

//init_memory_main.c
t_pix ***init_memory_main(void);

// new_free.c
void free_main(t_pix ***pix, t_scene *scene, t_mem *memory_shuttle);
//void	free_hits_cph(t_pix ***pix, int height, int width);
//void	free_hits_new(t_hits ***hits, int types, int objs);
//void	*free_partial_hits(t_hits ***hits, int i_max, int j_max);

//free_pix.c
void	*free_partial_pix(t_pix ***pix, int height, int width);
void	free_pix_array(t_pix ***pix, int height, int width);
void	free_pix_struct(t_pix ***pix, int height, int width);

//check_main.c
bool	check_file(t_scene *scene,int argc, char *filename);

//init_scene.c
t_scene *init_first_scene_memory(void);
bool	init_scene_memory(t_scene *scene);
bool init_obj_cph(t_scene *scene);
void free_obj_cph(t_scene *scene);
bool init_each_obj(t_obj *obj);
void	init_each_obj_null(t_obj *obj);
bool init_each_obj_coord(t_obj *obj);
void free_each_obj(t_obj *obj);
void free_each_obj_coord(t_obj *obj);
bool	init_each_obj_matrix(t_obj *obj);
void	free_each_obj_matrix(t_obj *obj);

t_image	*create_image(void);

//init_cam.c
bool init_cam_cph(t_scene *scene);
void cam_value_null(t_camera *cam);
bool init_cam_coord(t_camera *cam);
bool init_cam_matrix(t_camera *cam);
void free_cam_cph(t_scene *scene);
void free_cam_coord(t_camera *cam);
void free_cam_matrix(t_camera *cam);

//init_memory_shuttle.c
t_mem	*init_memory_shuttle(void);
void	memory_shuttle_values_null(t_mem *memory_shuttle);
bool init_shuttle_values(t_mem *memory_shuttle);
void	free_memory_shuttle(t_mem *memory_shuttle);
//free_scene.c
void	free_scene(t_scene *scene);
void	free_ima(t_scene *scene);

//init_lux.c
bool init_lux_cph(t_scene *scene);
void free_each_lux(t_light *lux);
bool init_each_lux(t_light *lux);
void	init_each_lux_null(t_light *lux);
void free_lux_cph(t_scene *scene);

#endif