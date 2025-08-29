/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saving.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:06:16 by cmegret           #+#    #+#             */
/*   Updated: 2025/06/12 14:59:25 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVING_H
# define SAVING_H

# include "minirt.h"

int		save_color(char *str, t_color *p, t_color *p2);
int		save_coordonnee(char *str, t_coord *p);
int		save_camera(char *str, t_camera *camera);
int		save_sphere(char *str, t_obj **obj, int *pos);
int		save_cylinder(char *str, t_obj **obj, int *pos);
int		save_plan(char *str, t_obj **obj, int *pos);
int		save_light(char *str, t_light **lux);
int		save_ambient(char *str, t_light *lux);
int		save_data(char *str, t_scene *scene);
int		save_cone(char *str, t_obj **obj, int *pos);	//rajouter cone
int		save_triangle(char *str, t_obj **obj, int *pos); //rajoute triangle
int		save_parameter(char *str, t_scene *scene, int *pos);

int		error_line(char **params, int line, int col);
int		number_param_error(char **params, int ligne);
int		error_system(void);
bool	error_missing(t_doublons num, int nb_light);

#endif
