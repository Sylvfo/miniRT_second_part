/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:04:41 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/25 19:29:17 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static int	type_shape(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == 's' && str[i + 1] == 'p')
		return (SPHERE);
	else if (str[i] == 'p' && str[i + 1] == 'l')
		return (PLAN);
	else if (str[i] == 'c' && str[i + 1] == 'y')
		return (CYLINDER);
	else if (str[i] == 'c' && str[i + 1] == 'o')
		return (CONE);
	else if (str[i] == 't' && str[i + 1] == 'r')
		return (TRIANGLE);
	return (0);
}

static void	save_parameter2(char *str, t_scene *scene, t_obj *obj)
{
	if (!ft_strncmp(str, "mir:", 4))
		obj->mirror = number(str + 4);
	else if (!ft_strncmp(str, "tran:", 5))
		obj->transparence = number(str + 5);
	else if (!ft_strncmp(str, "ref:", 4))
		obj->indice_refract = number(str + 4);
	else if (!ft_strncmp(str, "pat:", 4))
	{
		obj->pattern.type = number(str + 4);
		obj->pattern.scale = number(str + 6);
	}
	else if (!ft_strncmp(str, "txt:", 4))
	{
		handle_img(scene, obj, str + 4);
		obj->hastexture = true;
		obj->bump.mlx_ptr = scene->ima->mlx_ptr;
		obj->bump.mlx_win = scene->ima->mlx_win;
	}
}

int	save_parameter(char *str, t_scene *scene, int *pos)
{
	int		i;
	int		type;
	char	**params;

	i = 0;
	type = type_shape(str);
	if (!type)
		return (1);
	params = ft_split(str, ' ');
	if (!params)
		return (error_system());
	while (params[i])
	{
		save_parameter2(params[i], scene, scene->obj[type][*pos]);
		i++;
	}
	free_arg(params);
	return (1);
}
