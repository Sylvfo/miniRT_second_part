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

int	map_ambient(char *str, int ligne, int *num)
{
	char	**params;

	params = ft_split(str, ' ');
	if (!params)
		return (error_system());
	if (ft_size(params) != NB_EL_AMBIENT)
		return (number_param_error(params, ligne));
	if (!map_ratio(params[1]))
		return (error_line(params, ligne, 2));
	if (!map_color(params[2]))
		return (error_line(params, ligne, 3));
	free_arg(params);
	(*num)++;
	return (1);
}

int	map_light(char *str, int ligne, int *num)
{
	char	**params;

	params = ft_split(str, ' ');
	if (!params)
		return (error_system());
	if (ft_size(params) != NB_EL_LIGHT && ft_size(params) != (NB_EL_LIGHT - 1))
		return (number_param_error(params, ligne));
	if (!map_coordonnee(params[1]))
		return (error_line(params, ligne, 2));
	if (!map_ratio(params[2]))
		return (error_line(params, ligne, 3));
	if (ft_size(params) == NB_EL_LIGHT)
	{
		if (!map_color(params[3]))
			return (error_line(params, ligne, 4));
	}
	free_arg(params);
	(*num)++;
	return (1);
}

int	map_camera(char *str, int ligne, int *num)
{
	char	**params;

	params = ft_split(str, ' ');
	if (!params)
		return (error_system());
	if (ft_size(params) != NB_EL_CAMERA)
		return (number_param_error(params, ligne));
	if (!map_coordonnee(params[1]))
		return (error_line(params, ligne, 2));
	if (!map_vector(params[2]))
		return (error_line(params, ligne, 3));
	if (!map_degre(params[3]))
		return (error_line(params, ligne, 4));
	free_arg(params);
	(*num)++;
	return (1);
}

int	map_sphere(char *str, int ligne, int *num)
{
	char	**params;

	params = ft_split(str, ' ');
	if (!params)
		return (error_system());
	if (ft_size(params) < NB_EL_SPHERE)
		return (number_param_error(params, ligne));
	if (!map_coordonnee(params[1]))
		return (error_line(params, ligne, 2));
	if (!map_diameter(params[2]))
		return (error_line(params, ligne, 3));
	if (!map_color(params[3]))
		return (error_line(params, ligne, 4));
	free_arg(params);
	(*num)++;
	return (1);
}

int	map_plan(char *str, int ligne, int *num)
{
	char	**params;

	params = ft_split(str, ' ');
	if (!params)
		return (error_system());
	if (ft_size(params) < NB_EL_PLAN)
		return (number_param_error(params, ligne));
	if (!map_coordonnee(params[1]))
		return (error_line(params, ligne, 2));
	if (!map_vector(params[2]))
		return (error_line(params, ligne, 3));
	if (!map_color(params[3]))
		return (error_line(params, ligne, 4));
	free_arg(params);
	(*num)++;
	return (1);
}
