/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray_calculs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:12:16 by syl               #+#    #+#             */
/*   Updated: 2025/10/08 19:42:55 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_RAY_CALCULS_H
# define MINIRT_RAY_CALCULS_H

# include "minirt_data_struct.h"

// 00_raytracing_main.c
void		raytracing(t_pix ***pix, t_scene *scene, t_mem *memory_shuttle);
t_color		raytracer(t_pix *pix, t_scene *scene, t_mem *memory_shuttle);
t_color		background_color(t_obj *obj_zero, t_light *lux_zero);
void		clean_memory_shuttle(t_mem *memory_shuttle);

//01_camera_construction.c
void		view_camera(t_camera *cam);
void		pixel_size(t_scene *scene);
void		constructing_camera(t_scene *scene);

//02_viewport_construction.c
void		init_camera_pix_ray(t_mem *memory_shuttle, t_camera *cam);
void		init_viewport_x_y(t_mem *mem_shuttle, t_camera *cam, int x, int y);
//void		init_viewport(t_pix ***pix, t_mem *memory_shuttle, t_camera *cam);

//03_m_transformations.c
void		apply_transformation(t_obj *obj, t_mem *memory_shuttle);
void		set_transformation_obj(t_obj *obj);
void		matrix_transformations(t_obj ***obj);

//04_intersect_main.c
void		main_intersections(t_obj ***obj, t_mem *memory_shuttle);
void		closest_obj_in_pix(t_pix *pix, t_mem *memory_shuttle);// A DEPL

//05_intersect_sphere_plan.c
void		intersect_plan(t_mem *memory_shuttle, int plan_num);
void		intersect_sphere(t_mem *memory_shuttle, int sph_num);

//06_intersect_cylinder.c
void		intersect_cylinder(t_mem *memory_shuttle, int cyl_n);
t_intertt	cut_cylinder(t_mem *memory_shuttle, float t1, float t2);
t_intertt	intersect_caps(t_mem *memory_shuttle, t_intertt result);
bool		check_cap(t_mem *memory_shuttle, float t);
t_intertt	handle_cap(t_mem *mem_shuttle, t_intertt result, float y_pos);
void		closestt(t_mem *mem_sh, t_intertt res, int obj_ty, int obj_nu);

//07_intersect_cone.c
void		intersect_cone(t_mem *memory_shuttle, int cone_n);
t_intertt	cut_cone(t_mem *memory_shuttle, float t1, float t2);
//08_intersect_triangle.c
void		intersect_triangle(t_mem *memory_shuttle, t_obj ***obj, \
int triangle_n);

//08_prepare_comps.c
void		prepare_computation(t_mem *mem_shuttle, t_obj ***obj);
void		normal_sphere(t_mem *mem_shuttle);
void		normal_cylinder(t_mem *mem_shuttle, t_obj ***obj);

void		normal_cone(t_mem *mem_shuttle, t_obj ***obj); // normal cone

//09_light_shadow_main.c
t_color		lighting(t_scene *scene, t_mem *memory_shuttle, t_color color);

//10_shadows.c
void		prepare_v_light(t_mem *memory_shuttle, t_coord *lux_p_coord);
bool		intersect_objects_shadow(t_scene *scene, t_mem *memory_shuttle);

//shadows_sphere.c
bool		sphere_shadow(t_obj *sphere, t_mem *memory_shuttle);
bool		plan_shadow(t_mem *memory_shuttle, t_obj *plan);
bool		cylinder_shadow(t_mem *memory_shuttle, t_obj *cylinder);

//11_light.c
t_color		compute_specular(t_mem *mem_sht, t_light *lux, t_coord *cam_coord);
t_color		compute_pointlight(t_mem *memory_shuttle, t_light *lux);
t_intertt	init_intertt(void);

//texture.c
t_color		texture_shape(t_scene *scene, t_mem *mem, t_coord hitpoint);

#endif