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

int	map_cylinder(char *str, int ligne, int *num)
{
	char	**params;

	params = ft_split(str, ' ');
	if (!params)
		return (error_system());
	if (ft_size(params) < NB_EL_CYLINDER)
		return (number_param_error(params, ligne));
	if (!map_coordonnee(params[1]))
		return (error_line(params, ligne, 2));
	if (!map_vector(params[2]))
		return (error_line(params, ligne, 3));
	if (!map_diameter(params[3]))
		return (error_line(params, ligne, 4));
	if (!map_height(params[4]))
		return (error_line(params, ligne, 5));
	if (!map_color(params[5]))
		return (error_line(params, ligne, 6));
	free_arg(params);
	(*num)++;
	return (1);
}

//	cone
int	map_cone(char *str, int ligne, int *num)
{
	char	**params;

	params = ft_split(str, ' ');
	if (!params)
		return (error_system());
	if (ft_size(params) < NB_EL_CYLINDER)
		return (number_param_error(params, ligne));
	if (!map_coordonnee(params[1]))
		return (error_line(params, ligne, 2));
	if (!map_vector(params[2]))
		return (error_line(params, ligne, 3));
	if (!map_diameter(params[3]))
		return (error_line(params, ligne, 4));
	if (!map_height(params[4]))
		return (error_line(params, ligne, 5));
	if (!map_color(params[5]))
		return (error_line(params, ligne, 6));
	free_arg(params);
	(*num)++;
	return (1);
}

//	triangle
int	map_triangle(char *str, int ligne, int *num)
{
	char	**params;

	params = ft_split(str, ' ');
	if (!params)
		return (error_system());
	if (ft_size(params) < NB_EL_TRIANGLE)
		return (number_param_error(params, ligne));
	if (!map_coordonnee(params[1]))
		return (error_line(params, ligne, 2));
	if (!map_coordonnee(params[2]))
		return (error_line(params, ligne, 3));
	if (!map_coordonnee(params[3]))
		return (error_line(params, ligne, 4));
	if (!map_color(params[4]))
		return (error_line(params, ligne, 6));
	free_arg(params);
	(*num)++;
	return (1);
}
