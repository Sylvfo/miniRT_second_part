/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:15:29 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/25 19:26:57 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
int	validate_plane(char *line, t_num_obj *num_obj)
{
	t_coord	point;
	t_coord	normal;
	t_color	color;

	if (!line || !num_obj || line[0] != 'p' || line[1] != 'l')
		return (1);
	line += 2;
	skip_whitespace((const char **)&line);
	if (!*line || parse_coordinates(&line, &point.x, &point.y, &point.z))
		return (1);
	if (!*line || parse_coordinates(&line, &normal.x, &normal.y, &normal.z))
		return (1);
	if (validate_orientation_vector(normal.x, normal.y, normal.z))
		return (1);
	if (!*line || parse_color(&line, &color.r, &color.g, &color.b)
		|| check_only_spaces(line))
		return (1);
	num_obj->plan++;
	return (0);
}*/
