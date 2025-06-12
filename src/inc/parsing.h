/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by sforster          #+#    #+#             */
/*   Updated: 2025/06/12 14:56:30 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minirt.h"

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
