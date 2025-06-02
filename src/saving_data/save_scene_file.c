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

static int check_line(char *str, t_scene *scene)
{
	int i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == 'A')
		return (save_ambient(str, scene->lux[0][0]));
	else if (str[i] == 'L')
		return (save_light(str, scene->lux[1]));
	if (str[i] == 'C')
		return (save_camera(str, scene->cam));
	else if (str[i] == 's' && str[i + 1] == 'p')
		return (save_sphere(str, scene->obj[1]));
	else if (str[i] == 'p' && str[i + 1] == 'l')
		return (save_plan(str, scene->obj[2]));	
	else if (str[i] == 'c' && str[i + 1] == 'y')
		return (save_cylinder(str, scene->obj[3]));	
	return (1);
}

static bool file_parcour(int fd, t_scene *scene)
{
	char	*str;
	bool	error;

	error = false;
	str = get_next_line(fd);
	while (str)
	{
		if (!error)
		{
			replace_by_space(str);
			if (!check_line(str, scene))
				error = true;
		}
		free(str);
		str = get_next_line(fd);
	}
	return (error);
}

int	save_data(char *str, t_scene *scene)
{
	int fd;

	fd = open(str, O_RDONLY);
	if (fd == -1 )
	{
		perror(str);
		return(0);
	}
	if (file_parcour(fd, scene))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}