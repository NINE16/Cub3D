#include "../inc/cub3d.h"

int	ft_path_texture(char *str, char **texture, t_recup *recup, int j)
{
	int	i;

	i = 0;
	if(!(*texture = (char *)malloc(sizeof(char) *  ft_strlen(str) + 1)))
		ft_error(recup, "Malloc texture parsing impossible\n");
	// *texture[i] = str[j];
	(void)recup;
	j += 1;
	while (str[j] != '\0')
	{
		(*texture)[i] = str[j];
		i++;
		j++;
	}
	(*texture)[i] = '\0';
	return (0);
}

void	ft_texture(char *str, t_recup *recup)
{
	int			i;
	static int	j = 0;

	i = 0;
	if (ft_strncmp(str, "NO", 2) == 0)
		ft_path_texture(str, &recup->no, recup, 2);
	else if (ft_strncmp(str, "SO", 3) == 0)
		ft_path_texture(str, &recup->so, recup, 2);
	else if (ft_strncmp(str, "WE", 3) == 0)
		ft_path_texture(str, &recup->we, recup, 2);
	else if (ft_strncmp(str, "EA", 3) == 0)
		ft_path_texture(str, &recup->ea, recup, 2);
	else if (str[i] == 'S' && str[i + 1] != 'O')
		ft_path_texture(str, &recup->sp, recup, 1);
	else if (str[0] != 'N' && str[0] != 'S' && str[0] != 'W' && str[0] != 'E'
		&& str[0] != 'R' && str[0] != 'F' && str[0] != 'C'
		&& str[0] > 65 && str[0] < 122)
		printf("Premier caractere d'un element n'est pas un identifiant\n");
	j++;
}

void	ft_color_resolution(char **str, t_recup *recup)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == 'F')
			recup->f = ft_atoi3(&str[i][j], recup);
		else if (str[i][j] == 'C')
			recup->c = ft_atoi3(&str[i][j], recup);
		i++;
	}
}

int	ft_atoi3(const char *str, t_recup *recup)
{
	int		sum;
	int		i;

	sum = 0;
	i = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == ','
		|| str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f')
	{
		i++;
		if (str[i] >= '0' && str[i] <= '9')
			recup->indicateur2++;
		while ((str[i] >= '0' && str[i] <= '9'))
		{
			sum = (sum * 10) + (str[i] - 48);
			i++;
		}
		if (sum > 2147483646 || sum < -2147483647)
			printf("Chiffre superieur a 255 dans F ou C\n");
	}
	return (sum);
}
