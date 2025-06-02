#include "../inc/minirt.h"

void	replace_by_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) || ft_isspace(str[i] == '\n'))
		{
			str[i] = ' ';
		}
		i++;
	}
}

float	number(char *str)
{
	int	i;
	int point;
	int	num;
	float number;

	i = 0;
	point = 0;
	if (str[i] == '-')
		i = 1;
	while (str[i] && str[i] != '.')
		i++;
	num = ft_atoi(str);
	if (str[i] == '.' && str[i + 1])
	{
		point = ft_atoi(str + i + 1);
		i = ft_strlen(str + i + 1);
	}
	if (str[0] == '-')
		point = point * -1;
	number = (num * pow(10, (double)i) + point)/pow(10, (double)i);
	return (number);
}
