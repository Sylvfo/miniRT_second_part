/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:31:12 by syl               #+#    #+#             */
/*   Updated: 2025/06/07 15:59:45 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# include "minirt_data_struct.h"

//00_main_bonus.c
t_color	raytracer_bonus(t_pix *pix, t_scene *scene, t_mem *memory_shuttle);
t_color	reflexion(t_scene *scene, t_mem *memory_shuttle, int recurs_count);
void	raytracing_main_bonus(t_pix ***pix, t_scene *scene, t_mem *memory_shuttle);
//01_reflection.c
void next_ray_reflection(t_mem *memory_shuttle);
void clean_memory_shuttle_refl(t_mem *memory_shuttle);
void vect_reflexion(t_coord *r_base_dir, t_coord *v_normal);
//void vect_reflexion(t_coord *result, t_coord *v_previous, t_coord *v_normal);
t_color blend_reflection(t_color local, t_color reflected, float refl_intensity);

//mouse_hooks.c
int mouse_click(int button, int x, int y, t_scene *scene);
int	ft_keys_bonus(int keycode, t_scene *scene);
void take_distance_move(int keycode, t_scene *scene);
void take_axe(int keycode, t_scene *scene);
void apply_drawing_changes(t_scene *scene);
void	clear_modif(t_scene *scene);
//transf_obj.c
void move_object(t_obj *obj);
#endif
