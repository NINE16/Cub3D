#include "../inc/cub3d.h"

void	check_elements(t_recup *recup)
{
	int	i;

	i = 0;
	while (recup->map[i])
	{
		if (ft_is_map(recup->map[i]) == 0)
			recup->elements++;
		if (ft_is_map(recup->map[i]) == 1)
			break ;
		i++;
	}
	if (recup->elements != 7)
		ft_error(recup, "Your map is not the last element");
}

void	replace_empty(t_recup *recup, int len, char *curr_line)
{
	int	i;

	i = 0;
	if (len < recup->sizeline)
	{
		len = recup->sizeline;
		while (curr_line[len])
		{
			if (ft_isspace(curr_line[len]) == 1)
				curr_line[len] = '1';
 			len++;
		}
	}
}

int	check_wall(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && ft_isspace(str[i]) != 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isspace(unsigned char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

void	check_minimap(t_recup *recup)
{
	int	i;
	int	j;
	int	diff;

	i = 0;
	j = 0;
	diff = 0;
	while (i < recup->nblines)
	{
		j = 0;
		while ((size_t)j < ft_strlen(recup->minimap[i]))
		{
			if (ft_isspace(recup->minimap[i][j]) == 1)
			{
				recup->minimap[i][j] = '1';
			}
			j++;
		}
		i++;
	}
}
