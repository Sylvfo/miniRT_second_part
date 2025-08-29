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

int	map_ratio(char *str)
{
	float	test;

	if (!check_isdigit(str))
		return (0);
	test = number(str);
	if (test < RATIO_MIN || test > RATIO_MAX)
		return (0);
	return (1);
}

int	value_ref(char *str, float min, float max)
{
	float	test;

	if (!check_isdigit(str))
		return (0);
	test = number(str);
	if (test < min || test > max)
		return (0);
	return (1);
}

int	map_diameter(char *str)
{
	if (!check_isdigit(str))
		return (0);
	return (1);
}

int	map_height(char *str)
{
	return (map_diameter(str));
}

int	map_degre(char *str)
{
	float	test;

	if (!check_isdigit(str))
		return (0);
	test = number(str);
	if (test < DEG_MIN || test > DEG_MAX)
		return (0);
	return (1);
}
