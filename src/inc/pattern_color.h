/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_color.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:06:16 by cmegret           #+#    #+#             */
/*   Updated: 2025/08/22 14:59:25 by fatsaa-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERN_COLOR_H
# define PATTERN_COLOR_H

# include "minirt.h"

t_color	pattern(t_mem *mem, t_scene *scene);
t_color	pattern_checkboard(int x, int y, t_scene *scene, t_mem *mem);
t_color	pattern_gradient(float u, t_scene *scene, t_mem *mem);
t_color	pattern_stripes(float u, t_scene *scene, t_mem *mem);
t_color	pattern_rings(float distance, t_scene *scene, t_mem *mem);

t_color	pattern_plan(float scale, t_coord hitpoint, t_scene *scene, \
t_mem *mem);
t_color	pattern_sphere(float scale, t_coord p_local, t_scene *scene, \
t_mem *mem);
t_color	pattern_cylcon(float scale, t_coord p_local, t_scene *scene, \
t_mem *mem);
t_color	pattern_shape(float scale, t_coord hitpoint, t_scene *scene, \
t_mem *mem);

//bruit de perlin
t_color	pattern_bruit_perlin(float u, float v, t_scene *scene, t_mem *mem);
#endif
