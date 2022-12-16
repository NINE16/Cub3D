#include "../inc/cub3d.h"

void	ft_map(char *str, t_recup *recup)
{
	int			i;
	static int	snblines = 0;
	static int	ssizeline = 0;

	i = ft_strlen(str);
	if (ft_is_map(str) == 1)
	{
		if (i > ssizeline)
			ssizeline = i;
		snblines = snblines + 1;
	}
	recup->nblines = snblines;
	recup->sizeline = ssizeline;
}

char	*mapcheck(t_recup *recup)
{
	int	i;

	i = 0;
	check_elements(recup);
	while (recup->map[i])
	{
		if (ft_is_map(recup->map[i]) == 0)
		{
			ft_color_resolution(recup->map, recup);
			ft_texture(recup->map[i], recup);
			recup->elements++;
		}
		i++;
	}
	i = -1;
	while (recup->map[++i])
		ft_map(recup->map[i], recup);
	if (recup->nblines == 0 || recup->sizeline == 0)
		ft_error(recup, "Map is empty");
	ft_create_minimap(recup);
	return (0);
}

void	ft_create_minimap(t_recup *recup)
{
	int	i;

	i = 0;
	while (recup->map[i])
	{
		if (ft_is_map(recup->map[i]) == 1)
		{
			if (ft_copy_map(&recup->map[i], recup) == 0)
			{
				break ;
			}
			else
				ft_error(recup, "Missing elements");
		}
		free(recup->map[i]);
		i++;
	}
	ft_verify_errors(recup);
}
