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

int	ft_size(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	check_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && !ft_isdigit(str[i + 1]))
		return (0);
	if (str[i] == '-')
		i = 1;
	while (str[i] && str[i] != '.')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (!str[i])
		return (1);
	i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_isvector(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!check_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
