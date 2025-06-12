#include "../inc/minirt.h"

void message_error()
{
	ft_putendl_fd("Error: Not a <<.rt>> file", 2);
}

int	error_line(char **params, int line, int col)
{
	free_arg(params);
	printf("Error: line %d parameter %d\n",line, col);
	return (0);
}

int number_param_error(char **params, int ligne)
{
	free_arg(params);
	printf("Error line %d, number of parameter is wrong", ligne);
	return (0);
}

int error_system(void)
{
	perror("Error");
	return (0);
}

bool	error_missing(t_doublons num, int nb_light)
{
	if (num.camera != 1)
	{
		if (num.camera < 1)
			printf("Error: Missing camera params");
		else
			printf("Error: Too many camera params");
		return (true);
	}
	if (num.ambient != 1)
	{
		if (num.ambient < 1)
			printf("Error: Missing ambient params");
		else
			printf("Error: Too many ambient params");
		return (true);
	}
	if (nb_light < 1 )
	{
		printf("Error: Missing Light params");
		return (true);
	}
	return (false);
}