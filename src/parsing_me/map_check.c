#include "../inc/minirt.h"

int map_ratio(char *str)
{
	float test;

	if (!check_isdigit(str))
		return (0);
	test = 	number(str);
	if (test < RATIO_MIN || test > RATIO_MAX)
		return (0);
	return (1);
}

int map_diameter(char *str)
{
	float test;

	if (!check_isdigit(str))
		return (0);
	test = 	number(str);
	return (1);
}

int map_height(char *str)
{
	return map_diameter(str);
}

int map_degre(char *str)
{
	float test;

	if (!check_isdigit(str))
		return (0);
	test = 	number(str);
	if (test < DEG_MIN || test > DEG_MAX)
		return (0);
	return (1);
}
