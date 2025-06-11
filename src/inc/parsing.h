/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by sforster          #+#    #+#             */
/*   Updated: 2025/05/26 10:09:21 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minirt.h"

/* Parse Utils */

/*
void	skip_whitespace(const char **str);
int		parse_float(char **line, float *value);
int		parse_coordinates(char **line, float *x, float *y, float *z);
int		parse_color(char **line, float *r, float *g, float *b);
int		parse_dimension(char **line, float *dimension);
int		check_only_spaces(char *str);
int		validate_orientation_vector(float ox, float oy, float oz);
int		validate_fov(float fov);*/

/* Parsing */
/*void	parse_scene_file(const char *filename, t_program_context *context);
void	process_buffer(char *buf, t_program_context *context);
int		validate_ambient(char *line);
int		validate_light(char *line, t_num_obj *num_obj);
int		validate_camera(char *line);
int		validate_plane(char *line, t_num_obj *num_obj);
int		validate_cylinder(char *line, t_num_obj *num_obj);
int		validate_sphere(char *line, t_num_obj *num_obj);*/


/*			my parsing Franck			*/
int		map_ratio(char *str);
int		map_diameter(char *str);
int		map_height(char *str);
int		map_color(char *str);
int		map_coordonnee(char *str);
int		map_vector(char *str);
int		map_degre(char *str);
int		map_ambient(char *str, int ligne, int *num);
int		map_camera(char *str, int ligne, int *num);
int		map_sphere(char *str, int ligne, int *num);
int		map_light(char *str, int ligne, int *num);
int		map_plan(char *str, int ligne, int *num);
int		map_cylinder(char *str, int ligne, int *num);
int		verification(char *str, t_scene *num);
void	replace_by_space(char *str);
float	number(char *str);
int		check_isvector(char **str);
int		check_isdigit(char *str);
int		ft_size(char **argv);
#endif
