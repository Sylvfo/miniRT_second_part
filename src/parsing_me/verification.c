#include "../inc/minirt.h"

static int check_line(char *str, int ligne, t_scene *scene, t_doublons *db)
{
	int i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == 'A')
		return (map_ambient(str, ligne, &db->ambient));
	else if (str[i] == 'L')
		return (map_light(str, ligne, &scene->nb_lights));
	else if (str[i] == 'C')
		return (map_camera(str, ligne, &db->camera));
	else if (str[i] == 's' && str[i + 1] == 'p')
		return (map_sphere(str, ligne, &scene->nb_sphere));
	else if (str[i] == 'p' && str[i + 1] == 'l')
		return (map_plan(str, ligne, &scene->nb_plan));	
	else if (str[i] == 'c' && str[i + 1] == 'y')
		return (map_cylinder(str, ligne, &scene->nb_cylinder));	
	return (1);
}

static bool file_error(int fd, t_scene *scene)
{
	char	*str;
	int		i;
	bool	error;
	t_doublons db;

	i = 1;
	db = (t_doublons){0,0};
	error = false;
	str = get_next_line(fd);
	while (str)
	{
		if (!error)
		{
			replace_by_space(str);
			if (!check_line(str, i, scene, &db))
				error = true;
		}
		free(str);
		str = get_next_line(fd);
		i++;
	}
	if (!error && error_missing(db, scene->nb_lights))
		return (true);
	return (error);
}

int verification(char *str, t_scene *scene)
{
	int fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		perror(str);
		exit(2);
	}
	if (file_error(fd, scene))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}