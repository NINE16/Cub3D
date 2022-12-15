#include "../inc/cub3d.h"

int	ft_charinstr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_map(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (ft_charinstr(str, '1') == 1)
	{
		while (str[i] != '\0')
		{
			if (str[i] != ' ' && str[i] != '0' && str[i] != '1' \
				&& str[i] != 'N' && str[i] != 'S' \
				&& str[i] != 'E' && str[i] != 'W' && str[i] != '\n'
				&& str[i] != '\t')
				// printf("%s\n", "Map missing elements");
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	ft_copy_map(char **map, t_recup *recup)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!(recup->minimap = malloc(sizeof(char *) * recup->sizeline + 1)))
		return(0);
	while (map[i])
	{
		if (!(recup->minimap[j] = malloc(sizeof(char) * recup->sizeline + 1)))
			return(0);
		recup->minimap[j] = map[i];
		j++;
		i++;
	}
	check_minimap(recup);
	return (0);
}

int	ft_set(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}