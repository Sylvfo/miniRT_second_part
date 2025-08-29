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

static int	check_pattern(char *str)
{
	char	**params;
	int		a;

	params = ft_split(str, '|');
	if (!params)
		return (error_system());
	if (ft_size(params) != 2)
	{
		free_arg(params);
		return (0);
	}
	if (!check_isdigit(params[0]) || !check_isdigit(params[1]))
	{
		free_arg(params);
		return (0);
	}
	a = ft_atoi(params[0]);
	free_arg(params);
	if (a > NUM_PATTERN)
		return (0);
	return (1);
}

static int	check_texture(char *str)
{
	int	fd;

	if (ft_strncmp(str + ft_strlen(str) - 4, ".xpm", 4) != 0)
	{
		printf("Error: Invalid file extension. Expected .xpm\n");
		return (0);
	}
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		perror(str);
		return (0);
	}
	close (fd);
	return (1);
}

static int	check_parameter2(char *str)
{
	int	a;

	a = 1;
	if (!ft_strncmp(str, "mir:", 4))
	{
		a = map_ratio(str + 4);
	}
	else if (!ft_strncmp(str, "pat:", 4))
	{
		a = check_pattern(str + 4);
	}
	else if (!ft_strncmp(str, "txt:", 4))
	{
		a = check_texture(str + 4);
	}
	else if (!ft_strncmp(str, "tran:", 5))
	{
		a = map_ratio(str + 5);
	}
	else if (!ft_strncmp(str, "ref:", 4))
	{
		a = value_ref(str + 4, 1, 3);
	}
	return (a);
}

int	check_parameter(char *str, int ligne)
{
	int		i;
	char	**params;
	int		type;

	i = 0;
	type = type_shape(str);
	if (!type)
		return (1);
	params = ft_split(str, ' ');
	if (!params)
		return (error_system());
	while (params[i])
	{
		if (!check_parameter2(params[i]))
			return (error_line(params, ligne, i + 1));
		i++;
	}
	free_arg(params);
	return (1);
}
