/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   map_check.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: fatsaa-m <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/06/12 21:12:52 by fatsaa-m       #+#    #+#                */
/*   Updated: 2025/06/12 21:12:56 by fatsaa-m       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	map_color(char *str)
{
	char	**color;
	int		i;

	i = 0;
	color = ft_split(str, ',');
	if (!color)
		return (error_system());
	if (ft_size(color) != NB_EL_COLOR || !check_isvector(color))
		return (free_arg(color));
	while (color[i])
	{
		if (number(color[i]) < RGB_MIN || number(color[i]) > RGB_MAX)
			return (free_arg(color));
		i++;
	}
	free_arg(color);
	return (1);
}

int	map_coordonnee(char *str)
{
	char	**coord;
	int		i;

	i = 0;
	coord = ft_split(str, ',');
	if (!coord)
		return (error_system());
	if (ft_size(coord) != NB_EL_AXE || !check_isvector(coord))
		return (free_arg(coord));
	while (coord[i])
	{
		number(coord[i]);
		i++;
	}
	free_arg(coord);
	return (1);
}

int	map_vector(char *str)
{
	char	**vector;
	int		i;

	i = 0;
	vector = ft_split(str, ',');
	if (!vector)
		return (error_system());
	if (ft_size(vector) != NB_EL_VECTOR || !check_isvector(vector))
		return (free_arg(vector));
	while (vector[i])
	{
		if (number(vector[i]) < VECT_MIN || number(vector[i]) > VECT_MAX)
			return (free_arg(vector));
		i++;
	}
	free_arg(vector);
	return (1);
}
