#include "../inc/cub3d.h"

void	check_map(t_recup *recup, char *ficher)
{
	int		fd;
	char	*chars;
	char	*map;

	map = 0;
	fd = open(ficher, O_RDONLY);
	if (fd == -1)
		ft_error(recup, "Cannot read file\n");
	chars = ft_strdup("");
	while (1)
	{
		map = get_next_line(fd);
		if (map == NULL)
			break ;
		chars = ft_strjoin(chars, map);
	}
	recup->map = ft_split(chars, '\n');
	free(chars);
	free(map);
	close (fd);
}

t_recup	*ft_init_struct(void)
{
	t_recup	*recup;

	if(!(recup = malloc (sizeof(t_recup) + 1)))
		return(0);	recup->rx = 1000;
	recup->ry = 1000;
	recup->i = 0;
	recup->f = 0;
	recup->f = 0;
	recup->no = NULL;
	recup->so = NULL;
	recup->we = NULL;
	recup->ea = NULL;
	recup->sp = NULL;
	recup->nblines = 0;
	recup->sizeline = 0;
	recup->map = NULL;
	recup->minimap = NULL;
	recup->depart = 0;
	recup->dx = 0;
	recup->dy = 0;
	recup->texture[0].img = NULL;
	recup->texture[1].img = NULL;
	recup->texture[2].img = NULL;
	recup->texture[3].img = NULL;
	recup->elements = 0;
	recup->indicateur = 0;
	recup->indicateur2 = 0;
	recup->data.mlx_win = NULL;
	recup->data.img = NULL;
	return (recup);
}

int	check_args(char *file)
{
	if (ft_strchr(file, '.') == 0)
	{
		printf("%s\n", "Invalid file");
		exit(0);
	}
	else if (ft_strncmp(ft_strrchr(file, '.'), ".cub", 5))
	{
		printf("%s\n", "Invalid extension");
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_recup	*recup;

	recup = NULL;
	if (argc == 2)
	{
		recup = ft_init_struct();
		check_args(argv[1]);
		check_map(recup, argv[1]);
		mapcheck(recup);
		//free(recup->map);
		find_player(recup);
		ft_mlx(recup);
		mlx_loop(recup->data.mlx_ptr);
	}
	else
		printf("Missing map, game cannot be started\n");
	return (0);
}
